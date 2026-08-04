#!/usr/bin/env python3
"""Wrap a ROM range and its symbols in an ELF relocatable object for objdiff."""

from __future__ import annotations

import struct
import sys
from pathlib import Path


def align(value: int, alignment: int) -> int:
    return (value + alignment - 1) & -alignment


def main() -> None:
    source, output = Path(sys.argv[1]), Path(sys.argv[2])
    start, end = int(sys.argv[3]), int(sys.argv[4])
    kind = sys.argv[5]
    symbol_specs = sys.argv[6:]
    if kind not in {"code", "data", "rodata"}:
        raise ValueError(f"unsupported slice kind: {kind}")
    payload = bytearray(source.read_bytes()[start:end])
    symbols = []
    relocation_specs = [spec for spec in symbol_specs if spec.startswith("@rel:")]
    mapping_specs = [spec for spec in symbol_specs if spec.startswith("@map:")]
    section_specs = [spec for spec in symbol_specs if spec.startswith("@section:")]
    local_specs = [spec for spec in symbol_specs if spec.startswith("@local:")]
    for spec in (
        spec
        for spec in symbol_specs
        if not spec.startswith(("@rel:", "@map:", "@section:", "@local:"))
    ):
        parts = spec.rsplit(":", 3)
        if len(parts) == 4:
            name, address, mode, size_text = parts
            explicit_size = int(size_text, 0)
        else:
            name, address, mode = parts
            explicit_size = None
        relative = int(address, 0) - start
        if not 0 <= relative < len(payload):
            raise ValueError(f"symbol {name} is outside slice")
        symbols.append((relative, name, mode, explicit_size))
    symbols.sort()
    local_symbols = {spec.split(":", 1)[1] for spec in local_specs}
    missing_local_symbols = local_symbols - {name for _relative, name, _mode, _size in symbols}
    if missing_local_symbols:
        raise ValueError(
            f"local symbol is not defined: {', '.join(sorted(missing_local_symbols))}"
        )

    synthetic_sections = {}
    for spec in section_specs:
        _tag, name, size_text = spec.split(":", 2)
        if name != ".bss":
            raise ValueError(f"unsupported synthetic section: {name}")
        synthetic_sections[name] = int(size_text, 0)
    has_bss = ".bss" in synthetic_sections

    relocations: list[tuple[int, int, str, int | None]] = []
    relocation_types = {"abs32": 2, "thumb_call": 10}
    for spec in relocation_specs:
        parts = spec.split(":", 4)
        if len(parts) == 5:
            _tag, offset_text, relocation_type, name, addend_text = parts
            addend = int(addend_text, 0)
        else:
            _tag, offset_text, relocation_type, name = parts
            addend = None
        offset = int(offset_text, 0)
        if relocation_type not in relocation_types:
            raise ValueError(f"unsupported relocation type: {relocation_type}")
        width = 4
        if not 0 <= offset <= len(payload) - width:
            raise ValueError(f"relocation for {name} is outside slice")
        if relocation_type == "abs32":
            payload[offset : offset + 4] = struct.pack("<I", addend or 0)
        else:
            if addend is not None:
                raise ValueError("explicit addends are only supported for abs32 relocations")
            payload[offset : offset + 4] = b"\xff\xf7\xfe\xff"
        relocations.append((offset, relocation_types[relocation_type], name, addend))

    strtab = bytearray(b"\0")
    symbol_table = bytearray(b"\0" * 16)
    local_symbol_count = 0
    section_symbol_indices = {}
    if any(name == ".text" for _offset, _type, name, _addend in relocations):
        if kind != "code":
            raise ValueError(".text relocations require a code slice")
        section_symbol_indices[".text"] = len(symbol_table) // 16
        symbol_table.extend(struct.pack("<IIIBBH", 0, 0, 0, 3, 0, 1))
        local_symbol_count += 1
    if any(name == ".bss" for _offset, _type, name, _addend in relocations):
        if not has_bss:
            raise ValueError(".bss relocations require a synthetic .bss section")
        section_symbol_indices[".bss"] = len(symbol_table) // 16
        symbol_table.extend(struct.pack("<IIIBBH", 0, 0, 0, 3, 0, 3))
        local_symbol_count += 1
    if kind == "code":
        mappings: set[tuple[int, str]] = set()
        for spec in mapping_specs:
            _tag, offset_text, mode = spec.split(":", 2)
            offset = int(offset_text, 0)
            if mode not in {"arm", "thumb", "data"}:
                raise ValueError(f"unsupported mapping mode: {mode}")
            if not 0 <= offset < len(payload):
                raise ValueError(f"mapping at {offset_text} is outside slice")
            mappings.add((offset, {"arm": "$a", "thumb": "$t", "data": "$d"}[mode]))
        for index, (relative, _name, mode, explicit_size) in enumerate(symbols):
            if mode in {"arm", "thumb"}:
                mappings.add((relative, "$a" if mode == "arm" else "$t"))
            elif mode == "data":
                mappings.add((relative, "$d"))
            next_relative = symbols[index + 1][0] if index + 1 < len(symbols) else len(payload)
            if explicit_size is not None and relative + explicit_size < next_relative:
                mappings.add((relative + explicit_size, "$d"))
        for relative, mapping_name in sorted(mappings):
            name_offset = len(strtab)
            strtab.extend(mapping_name.encode("ascii") + b"\0")
            symbol_table.extend(struct.pack("<IIIBBH", name_offset, relative, 0, 0, 0, 1))
            local_symbol_count += 1
    defined_symbol_indices = {}
    indexed_symbols = list(enumerate(symbols))
    ordered_symbols = [
        *[(index, symbol) for index, symbol in indexed_symbols if symbol[1] in local_symbols],
        *[(index, symbol) for index, symbol in indexed_symbols if symbol[1] not in local_symbols],
    ]
    for index, (relative, name, mode, explicit_size) in ordered_symbols:
        name_offset = len(strtab)
        strtab.extend(name.encode("utf-8") + b"\0")
        next_relative = symbols[index + 1][0] if index + 1 < len(symbols) else len(payload)
        size = explicit_size if explicit_size is not None else next_relative - relative
        if size < 0 or relative + size > len(payload):
            raise ValueError(f"symbol {name} size is outside slice")
        value = relative | (1 if kind == "code" and mode == "thumb" else 0)
        symbol_type = 1 if mode == "data" or kind != "code" else 2
        defined_symbol_indices[name] = len(symbol_table) // 16
        binding = 0 if name in local_symbols else 1
        symbol_table.extend(
            struct.pack("<IIIBBH", name_offset, value, size, symbol_type | (binding << 4), 0, 1)
        )
        if binding == 0:
            local_symbol_count += 1

    external_symbol_indices: dict[str, int] = {}
    for _offset, _relocation_type, name, _addend in relocations:
        if name in section_symbol_indices or name in defined_symbol_indices:
            continue
        if name in external_symbol_indices:
            continue
        name_offset = len(strtab)
        strtab.extend(name.encode("utf-8") + b"\0")
        external_symbol_indices[name] = len(symbol_table) // 16
        symbol_table.extend(struct.pack("<IIIBBH", name_offset, 0, 0, 0x10, 0, 0))

    relocation_table = bytearray()
    for offset, relocation_type, name, _addend in relocations:
        symbol_index = section_symbol_indices.get(
            name, defined_symbol_indices.get(name, external_symbol_indices.get(name))
        )
        assert symbol_index is not None
        info = symbol_index << 8 | relocation_type
        relocation_table.extend(struct.pack("<II", offset, info))

    section_name = {"code": b".text", "data": b".data", "rodata": b".rodata"}[kind]
    shstr = b"\0" + section_name + b"\0.rel.text\0"
    reltab_name = 1 + len(section_name) + 1
    bss_name = len(shstr) if has_bss else None
    if has_bss:
        shstr += b".bss\0"
    symtab_name = len(shstr)
    shstr += b".symtab\0"
    strtab_name = symtab_name + len(b".symtab") + 1
    shstrtab_name = strtab_name + len(b".strtab") + 1
    shstr += b".strtab\0.shstrtab\0"
    text_offset = 52
    reltab_offset = align(text_offset + len(payload), 4)
    symtab_offset = reltab_offset + len(relocation_table)
    strtab_offset = symtab_offset + len(symbol_table)
    shstr_offset = strtab_offset + len(strtab)
    shoff = align(shstr_offset + len(shstr), 4)
    section_count = 7 if has_bss else 6
    shstr_index = 6 if has_bss else 5
    symtab_index = 4 if has_bss else 3
    strtab_index = 5 if has_bss else 4
    header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01" + b"\0" * 9,
        1, 40, 1, 0, 0, shoff, 0x05000000, 52, 0, 0, 40, section_count, shstr_index,
    )
    null_section = b"\0" * 40
    section_flags = 0x6 if kind == "code" else (0x2 if kind == "rodata" else 0x3)
    text_section = struct.pack("<IIIIIIIIII", 1, 1, section_flags, 0, text_offset, len(payload), 0, 0, 4, 0)
    reltab_section = struct.pack(
        "<IIIIIIIIII",
        reltab_name,
        9,
        0,
        0,
        reltab_offset,
        len(relocation_table),
        symtab_index,
        1,
        4,
        8,
    )
    bss_section = struct.pack(
        "<IIIIIIIIII",
        bss_name or 0,
        8,
        3,
        0,
        0,
        synthetic_sections.get(".bss", 0),
        0,
        0,
        2,
        0,
    )
    symtab_section = struct.pack(
        "<IIIIIIIIII",
        symtab_name,
        2,
        0,
        0,
        symtab_offset,
        len(symbol_table),
        strtab_index,
        1 + local_symbol_count,
        4,
        16,
    )
    strtab_section = struct.pack(
        "<IIIIIIIIII", strtab_name, 3, 0, 0, strtab_offset, len(strtab), 0, 0, 1, 0
    )
    shstr_section = struct.pack(
        "<IIIIIIIIII", shstrtab_name, 3, 0, 0, shstr_offset, len(shstr), 0, 0, 1, 0
    )
    result = header + payload
    result += b"\0" * (reltab_offset - len(result)) + relocation_table + symbol_table + strtab + shstr
    result += b"\0" * (shoff - len(result))
    result += null_section + text_section + reltab_section
    if has_bss:
        result += bss_section
    result += symtab_section + strtab_section + shstr_section
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result)


if __name__ == "__main__":
    main()
