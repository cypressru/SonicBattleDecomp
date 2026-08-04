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
    payload = source.read_bytes()[start:end]
    symbols = []
    for spec in symbol_specs:
        name, address, mode = spec.rsplit(":", 2)
        relative = int(address, 0) - start
        if not 0 <= relative < len(payload):
            raise ValueError(f"symbol {name} is outside slice")
        symbols.append((relative, name, mode))
    symbols.sort()

    strtab = bytearray(b"\0")
    symbol_table = bytearray(b"\0" * 16)
    for index, (relative, name, mode) in enumerate(symbols):
        name_offset = len(strtab)
        strtab.extend(name.encode("utf-8") + b"\0")
        next_relative = symbols[index + 1][0] if index + 1 < len(symbols) else len(payload)
        value = relative | (1 if kind == "code" and mode == "thumb" else 0)
        symbol_type = 0x12 if kind == "code" else 0x11
        symbol_table.extend(struct.pack("<IIIBBH", name_offset, value, next_relative - relative, symbol_type, 0, 1))

    section_name = {"code": b".text", "data": b".data", "rodata": b".rodata"}[kind]
    shstr = b"\0" + section_name + b"\0.symtab\0.strtab\0.shstrtab\0"
    symtab_name = 1 + len(section_name) + 1
    strtab_name = symtab_name + len(b".symtab") + 1
    shstrtab_name = strtab_name + len(b".strtab") + 1
    text_offset = 52
    symtab_offset = align(text_offset + len(payload), 4)
    strtab_offset = symtab_offset + len(symbol_table)
    shstr_offset = strtab_offset + len(strtab)
    shoff = align(shstr_offset + len(shstr), 4)
    header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01" + b"\0" * 9,
        1, 40, 1, 0, 0, shoff, 0x05000000, 52, 0, 0, 40, 5, 4,
    )
    null_section = b"\0" * 40
    section_flags = 0x6 if kind == "code" else (0x2 if kind == "rodata" else 0x3)
    text_section = struct.pack("<IIIIIIIIII", 1, 1, section_flags, 0, text_offset, len(payload), 0, 0, 4, 0)
    symtab_section = struct.pack(
        "<IIIIIIIIII", symtab_name, 2, 0, 0, symtab_offset, len(symbol_table), 3, 1, 4, 16
    )
    strtab_section = struct.pack(
        "<IIIIIIIIII", strtab_name, 3, 0, 0, strtab_offset, len(strtab), 0, 0, 1, 0
    )
    shstr_section = struct.pack(
        "<IIIIIIIIII", shstrtab_name, 3, 0, 0, shstr_offset, len(shstr), 0, 0, 1, 0
    )
    result = header + payload
    result += b"\0" * (symtab_offset - len(result)) + symbol_table + strtab + shstr
    result += b"\0" * (shoff - len(result))
    result += null_section + text_section + symtab_section + strtab_section + shstr_section
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result)


if __name__ == "__main__":
    main()
