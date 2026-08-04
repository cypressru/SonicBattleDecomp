#!/usr/bin/env python3
"""Wrap a ROM range in an ELF relocatable object for objdiff target viewing."""

from __future__ import annotations

import struct
import sys
from pathlib import Path


def align(value: int, alignment: int) -> int:
    return (value + alignment - 1) & -alignment


def main() -> None:
    source, output, start, end = Path(sys.argv[1]), Path(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4])
    payload = source.read_bytes()[start:end]
    shstr = b"\0.text\0.shstrtab\0"
    text_offset = 52
    shstr_offset = text_offset + len(payload)
    shoff = align(shstr_offset + len(shstr), 4)
    header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01" + b"\0" * 9,
        1, 40, 1, 0, 0, shoff, 0x05000000, 52, 0, 0, 40, 3, 2,
    )
    null_section = b"\0" * 40
    text_section = struct.pack("<IIIIIIIIII", 1, 1, 0x6, 0x08000000 + start, text_offset, len(payload), 0, 0, 4, 0)
    shstr_section = struct.pack("<IIIIIIIIII", 7, 3, 0, 0, shstr_offset, len(shstr), 0, 0, 1, 0)
    result = header + payload + shstr
    result += b"\0" * (shoff - len(result)) + null_section + text_section + shstr_section
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result)


if __name__ == "__main__":
    main()
