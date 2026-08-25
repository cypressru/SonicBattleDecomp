#!/usr/bin/env python3
"""Validate the base ROM and generate Ninja and objdiff configuration."""

from __future__ import annotations

import hashlib
import csv
import json
import sys
from pathlib import Path

import yaml

from tools.m4a_map import derive_m4a_ranges
from tools.raw_asset_map import derive_raw_asset_ranges

ROOT = Path(__file__).resolve().parent
CONFIG_PATH = ROOT / "config/BSBE78/config.yml"


def fail(message: str) -> None:
    raise SystemExit(f"error: {message}")


def main() -> None:
    config = yaml.safe_load(CONFIG_PATH.read_text(encoding="utf-8"))
    configured_entries = {unit["name"]: unit for unit in config["units"]}
    rom = ROOT / config["rom"]
    if not rom.is_file():
        fail(f"place the verified ROM at {rom.relative_to(ROOT)}")

    data = rom.read_bytes()
    actual_sha1 = hashlib.sha1(data).hexdigest()
    if actual_sha1 != config["sha1"]:
        fail(f"unexpected ROM SHA-1: {actual_sha1} (expected {config['sha1']})")
    if len(data) != int(config["rom_size"]):
        fail(f"unexpected ROM size: 0x{len(data):X}")
    clz_table_start = 0xED66A8
    expected_clz_table = bytes(value.bit_length() for value in range(256))
    if data[clz_table_start : clz_table_start + 0x100] != expected_clz_table:
        fail("unexpected libgcc __clz_tab contents")

    function_ends: dict[int, int] = {}
    function_size_map = config.get("function_size_map")
    if function_size_map:
        with (ROOT / function_size_map).open(newline="", encoding="utf-8") as stream:
            for row in csv.DictReader(stream):
                start = int(row["address"], 0) - 0x08000000
                end = int(row["end"], 0) - 0x08000000
                if end <= start:
                    fail(f"invalid function extent at 0x{start + 0x08000000:08X}")
                function_ends[start] = end

    configured_units = []
    for unit in config["units"]:
        range_map = unit.get("range_map")
        if not range_map:
            configured_units.append(unit)
            continue
        with (ROOT / range_map).open(newline="", encoding="utf-8") as stream:
            rows = list(csv.DictReader(stream))
        if unit.get("derive_m4a_ranges"):
            existing = {int(row["address"], 0) for row in rows}
            rows.extend(row for row in derive_m4a_ranges(data) if int(row["address"], 0) not in existing)
        if unit.get("derive_raw_asset_ranges"):
            existing = {int(row["address"], 0) for row in rows}
            rows.extend(
                row
                for row in derive_raw_asset_ranges(data, function_ends)
                if int(row["address"], 0) not in existing
            )
        if unit.get("derive_m4a_ranges") or unit.get("derive_raw_asset_ranges"):
            rows.sort(key=lambda row: int(row["address"], 0))
            addresses = [int(row["address"], 0) for row in rows]
            if len(addresses) != len(set(addresses)):
                fail(f"range map for {unit['name']} has duplicate derived addresses")
        starts = [int(row["address"], 0) - 0x08000000 for row in rows]
        if not starts or starts[0] != int(unit["start"]):
            fail(f"range map for {unit['name']} does not begin at its configured start")
        palette_indices = [
            index for index, row in enumerate(rows) if row["name"].startswith("palette_")
        ]
        if unit.get("derive_raw_asset_ranges") and len(palette_indices) != 20:
            fail(f"expected 20 independently identified character palettes, found {len(palette_indices)}")
        for index in palette_indices:
            next_start = starts[index + 1] if index + 1 < len(starts) else int(unit["end"])
            if next_start - starts[index] != 32:
                fail(f"palette {rows[index]['name']} is not an isolated 32-byte record")
        for index, (row, start) in enumerate(zip(rows, starts)):
            end = starts[index + 1] if index + 1 < len(starts) else int(unit["end"])
            is_asset = row["name"].startswith(("lz77_asset_", "raw_asset_", "palette_"))
            derived_unit = {
                "name": f"{'assets' if is_asset else 'rodata'}/{row['name']}",
                "start": start,
                "end": end,
                "category": "assets" if is_asset else "rodata",
                "kind": "rodata",
                "symbols": [{"name": row["name"], "address": start, "mode": "data"}],
            }
            derived_unit.update(config.get("range_overrides", {}).get(row["name"], {}))
            configured_units.append(derived_unit)
    build_dir = ROOT / "build" / config["version"]
    build_dir.mkdir(parents=True, exist_ok=True)
    units = []
    ninja_targets = []
    symbol_maps: dict[str, list[dict[str, object]]] = {}
    for unit in configured_units:
        map_path = unit.get("symbol_map", unit.get("function_map"))
        if not map_path:
            continue
        rows: list[dict[str, object]] = []
        with (ROOT / map_path).open(newline="", encoding="utf-8") as stream:
            for row in csv.DictReader(stream):
                address = int(row["address"], 0) - 0x08000000
                if int(unit["start"]) <= address < int(unit["end"]):
                    rows.append({"name": row["name"], "address": address, "mode": row["mode"]})
        if not rows:
            fail(f"function map for {unit['name']} contains no symbols")
        for index, row in enumerate(rows):
            address = int(row["address"])
            if address not in function_ends:
                fail(f"function size map has no extent for {row['name']}")
            next_address = int(rows[index + 1]["address"]) if index + 1 < len(rows) else int(unit["end"])
            size = min(function_ends[address], next_address, int(unit["end"])) - address
            if size <= 0:
                fail(f"invalid accepted function size for {row['name']}")
            row["size"] = size
        symbol_maps[unit["name"]] = rows
        pointer_table = unit.get("owned_pointer_table")
        if pointer_table:
            addresses_by_name = {str(row["name"]): int(row["address"]) for row in rows}
            table_start = int(pointer_table["start"])
            expected = bytearray()
            for name in pointer_table["symbols"]:
                if name not in addresses_by_name:
                    fail(f"owned pointer table for {unit['name']} references unknown symbol {name}")
                expected.extend((addresses_by_name[name] + 0x08000001).to_bytes(4, "little"))
            actual = data[table_start : table_start + len(expected)]
            if actual != expected:
                fail(f"owned pointer table for {unit['name']} does not match the reviewed symbol order")
    for unit in configured_units:
        target_path = build_dir / "target" / f"{unit['name']}.o"
        has_base = bool(unit.get("source") or unit.get("source_asm") or unit.get("archive_member"))
        base_path = build_dir / "base" / f"{unit['name']}.o" if has_base else None
        target_path.parent.mkdir(parents=True, exist_ok=True)
        if not unit.get("exclude_from_objdiff", False):
            units.append({
                "name": unit["name"],
                "target_path": str(target_path.relative_to(ROOT)),
                "base_path": str(base_path.relative_to(ROOT)) if base_path else None,
                "metadata": {
                    "progress_categories": [unit["category"]],
                    "auto_generated": unit.get("auto_generated", False),
                    "has_base": base_path is not None,
                    "complete": unit.get("complete", False),
                },
            })
        ninja_targets.append(str(target_path.relative_to(ROOT)))

    objdiff = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "min_version": "3.0.0",
        "custom_make": "ninja",
        "build_target": True,
        "build_base": True,
        "watch_patterns": ["*.c", "*.h", "*.s", "*.inc", "*.py", "*.yml"],
        "units": units,
        "progress_categories": [
            {"id": "game", "name": "Game"},
            {"id": "sdk", "name": "SDK"},
            {"id": "runtime", "name": "Runtime"},
            {"id": "assets", "name": "Data and assets"},
            {"id": "rodata", "name": "Read-only data"},
            {"id": "payload", "name": "Embedded payload"},
        ],
    }
    (ROOT / "objdiff.json").write_text(json.dumps(objdiff, indent=2) + "\n", encoding="utf-8")

    ninja = [
        "# Generated by configure.py; do not edit.",
        "ninja_required_version = 1.10",
        "builddir = build/BSBE78",
        "",
        "rule slice_object",
        "  command = python3 tools/slice_object.py $in $out $start $end $kind $symbols",
        "  description = SLICE $out",
        "",
        "rule copy_rom",
        "  command = python3 tools/copy_verified.py $in $out",
        "  description = LINK $out",
        "",
        "rule compile_agbcc",
        "  command = python3 tools/compile_agbcc.py $in $out $cflags",
        "  description = CC $out",
        "",
        "rule extract_archive_member",
        "  command = python3 tools/extract_archive_member.py $in $member $out",
        "  description = AR $out",
        "",
        "rule assemble_arm",
        "  command = tools/binutils/root/usr/bin/arm-none-eabi-as -mcpu=arm7tdmi --defsym L_$symbol=1 -o $out $in",
        "  description = AS $out",
        "",
        "rule compose_archive_target",
        "  command = python3 tools/compose_archive_target.py $archive $member $in $out $sections",
        "  description = COMPOSE $out",
        "",
        "rule compose_source_target",
        "  command = python3 tools/compose_source_target.py $base $in $out $sections",
        "  description = COMPOSE $out",
        "",
    ]
    for unit, target in zip(configured_units, ninja_targets):
        entries = configured_entries.get(unit.get("config_entries_from"), unit)
        offset_origin = int(unit.get("offset_origin", entries["start"]))
        offset_adjustment = int(unit["start"]) - offset_origin
        unit_size = int(unit["end"]) - int(unit["start"])
        symbol_specs = []
        for symbol in [*unit.get("symbols", []), *symbol_maps.get(unit["name"], [])]:
            spec = f"{symbol['name']}:{int(symbol['address'])}:{symbol.get('mode', 'thumb')}"
            if "size" in symbol:
                spec += f":{int(symbol['size'])}"
            symbol_specs.append(spec)
        relocations = list(entries.get("relocations", []))
        for table in entries.get("relocation_tables", []):
            table_start = int(table["start"])
            table_end = int(table["end"])
            stride = int(table.get("stride", 4))
            if stride <= 0 or table_end <= table_start or (table_end - table_start) % stride:
                fail(f"invalid relocation table in {unit['name']} at 0x{table_start:X}")
            pointer_base = int(table["pointer_base"])
            entries_start = int(entries["start"])
            for relocation_offset in range(table_start, table_end, stride):
                rom_offset = entries_start + relocation_offset
                raw_pointer = int.from_bytes(data[rom_offset : rom_offset + 4], "little")
                addend = raw_pointer - pointer_base
                if not 0 <= addend < int(entries["end"]) - entries_start:
                    fail(
                        f"relocation-table pointer 0x{raw_pointer:08X} in {unit['name']} "
                        "is outside its target section"
                    )
                relocations.append(
                    {
                        "offset": relocation_offset,
                        "type": table.get("type", "abs32"),
                        "symbol": table["symbol"],
                        "addend": addend,
                    }
                )
        for relocation in relocations:
            relocation_offset = int(relocation["offset"]) - offset_adjustment
            if not 0 <= relocation_offset < unit_size:
                continue
            spec = (
                f"@rel:{relocation_offset}:{relocation['type']}:"
                f"{relocation['symbol']}"
            )
            if "addend" in relocation:
                spec += f":{int(relocation['addend'])}"
            symbol_specs.append(spec)
        for mapping in entries.get("mappings", []):
            mapping_offset = int(mapping["offset"]) - offset_adjustment
            if not 0 <= mapping_offset < unit_size:
                continue
            symbol_specs.append(f"@map:{mapping_offset}:{mapping['mode']}")
        for section in unit.get("synthetic_sections", []):
            symbol_specs.append(f"@section:{section['name']}:{int(section['size'])}")
        for symbol_name in unit.get("local_symbols", []):
            symbol_specs.append(f"@local:{symbol_name}")
        if not unit.get("auto_generated", False) and not symbol_specs:
            symbol_name = unit["name"].rsplit("/", 1)[-1]
            symbol_specs.append(f"{symbol_name}:{int(unit['start'])}:thumb")
        if unit.get("target_sections"):
            sections = " ".join(
                f"{section['name']}:{int(section['start'])}:{int(section['end'])}"
                for section in unit["target_sections"]
            )
            if unit.get("source"):
                base = build_dir / "base" / f"{unit['name']}.o"
                ninja.extend([
                    f"build {target}: compose_source_target {config['rom']} | {base.relative_to(ROOT)} tools/compose_source_target.py tools/compose_archive_target.py",
                    f"  base = {base.relative_to(ROOT)}",
                    f"  sections = {sections}",
                    "",
                ])
            else:
                archive = unit.get("archive", "tools/agbcc/libgcc.a")
                ninja.extend([
                    f"build {target}: compose_archive_target {config['rom']} | {archive} tools/compose_archive_target.py",
                    f"  archive = {archive}",
                    f"  member = {unit['archive_member']}",
                    f"  sections = {sections}",
                    "",
                ])
        else:
            ninja.extend([
                f"build {target}: slice_object {config['rom']} | tools/slice_object.py {function_size_map or ''}",
                f"  start = {int(unit['start'])}",
                f"  end = {int(unit['end'])}",
                f"  kind = {unit.get('kind', 'code')}",
                "  symbols =" + (f" {' '.join(symbol_specs)}" if symbol_specs else ""),
                "",
            ])
        if unit.get("source"):
            base = build_dir / "base" / f"{unit['name']}.o"
            accepted_names = {str(row["name"]) for row in symbol_maps.get(unit["name"], [])}
            symbol_sizes = " ".join(
                f"@symbol-size:{name}:{int(size)}"
                for name, size in entries.get("base_symbol_size_overrides", {}).items()
                if not accepted_names or name in accepted_names
            )
            ninja.extend(
                [
                    f"build {base.relative_to(ROOT)}: compile_agbcc {unit['source']} | include/types.h tools/compile_agbcc.py",
                    f"  cflags = {' '.join(unit.get('cflags', ['-O2']))} {symbol_sizes}".rstrip(),
                    "",
                ]
            )
            ninja_targets.append(str(base.relative_to(ROOT)))
        elif unit.get("source_asm"):
            base = build_dir / "base" / f"{unit['name']}.o"
            ninja.extend(
                [
                    f"build {base.relative_to(ROOT)}: assemble_arm {unit['source_asm']}",
                    f"  symbol = {unit['asm_symbol']}",
                    "",
                ]
            )
            ninja_targets.append(str(base.relative_to(ROOT)))
        elif unit.get("archive_member"):
            base = build_dir / "base" / f"{unit['name']}.o"
            archive = unit.get("archive", "tools/agbcc/libgcc.a")
            ninja.extend(
                [
                    f"build {base.relative_to(ROOT)}: extract_archive_member {archive} | tools/extract_archive_member.py",
                    f"  member = {unit['archive_member']}",
                    "",
                ]
            )
            ninja_targets.append(str(base.relative_to(ROOT)))
    output_rom = f"build/{config['version']}/sonic_battle.gba"
    ninja.extend(
        [
            f"build {output_rom}: copy_rom {config['rom']}",
            "",
            f"build objects: phony {' '.join(ninja_targets)}",
            f"build check: phony {output_rom}",
            f"default {output_rom} objects",
            "",
        ]
    )
    (ROOT / "build.ninja").write_text("\n".join(ninja), encoding="utf-8")
    print(f"Configured {config['name']} ({actual_sha1})")


if __name__ == "__main__":
    main()
