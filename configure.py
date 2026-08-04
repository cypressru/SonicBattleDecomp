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
    ]
    for unit, target in zip(configured_units, ninja_targets):
        symbol_specs = []
        for symbol in [*unit.get("symbols", []), *symbol_maps.get(unit["name"], [])]:
            spec = f"{symbol['name']}:{int(symbol['address'])}:{symbol.get('mode', 'thumb')}"
            if "size" in symbol:
                spec += f":{int(symbol['size'])}"
            symbol_specs.append(spec)
        for relocation in unit.get("relocations", []):
            symbol_specs.append(
                f"@rel:{int(relocation['offset'])}:{relocation['type']}:{relocation['symbol']}"
            )
        for mapping in unit.get("mappings", []):
            symbol_specs.append(f"@map:{int(mapping['offset'])}:{mapping['mode']}")
        if not unit.get("auto_generated", False) and not symbol_specs:
            symbol_name = unit["name"].rsplit("/", 1)[-1]
            symbol_specs.append(f"{symbol_name}:{int(unit['start'])}:thumb")
        if unit.get("target_sections"):
            sections = " ".join(
                f"{section['name']}:{int(section['start'])}:{int(section['end'])}"
                for section in unit["target_sections"]
            )
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
            symbol_sizes = " ".join(
                f"@symbol-size:{name}:{int(size)}"
                for name, size in unit.get("base_symbol_size_overrides", {}).items()
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
