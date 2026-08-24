#!/usr/bin/env python3
"""Compose a multi-section target object from ROM bytes and library metadata."""

from __future__ import annotations

import struct
import subprocess
import sys
from pathlib import Path


def replace_elf_sections(
    elf: bytes, replacements: dict[str, bytes], *, preserve_relocated_bytes: bool = False
) -> bytes:
    if elf[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("archive member is not a 32-bit little-endian ELF object")
    section_offset = struct.unpack_from("<I", elf, 0x20)[0]
    section_size, section_count, names_index = struct.unpack_from("<HHH", elf, 0x2E)
    if section_size != 40 or names_index >= section_count:
        raise ValueError("unsupported ELF section table")

    def section(index: int) -> tuple[int, ...]:
        return struct.unpack_from("<IIIIIIIIII", elf, section_offset + index * section_size)

    names_header = section(names_index)
    names = elf[names_header[4] : names_header[4] + names_header[5]]
    output = bytearray(elf)
    replacement_indices: dict[int, str] = {}
    found: set[str] = set()
    for index in range(section_count):
        header = section(index)
        name_end = names.find(b"\0", header[0])
        name = names[header[0] : name_end].decode("ascii")
        if name not in replacements:
            continue
        payload = replacements[name]
        if len(payload) != header[5]:
            raise ValueError(
                f"section {name} has size 0x{header[5]:X}, replacement has 0x{len(payload):X}"
            )
        output[header[4] : header[4] + header[5]] = payload
        found.add(name)
        replacement_indices[index] = name
    missing = replacements.keys() - found
    if missing:
        raise ValueError(f"ELF has no requested section: {', '.join(sorted(missing))}")
    if preserve_relocated_bytes:
        for index in range(section_count):
            header = section(index)
            if header[1] != 9 or header[7] not in replacement_indices:
                continue
            target = section(header[7])
            entry_size = header[9] or 8
            if entry_size != 8 or header[5] % entry_size:
                raise ValueError("unsupported ELF relocation section")
            for offset in range(header[4], header[4] + header[5], entry_size):
                relocation_offset = struct.unpack_from("<I", elf, offset)[0]
                if relocation_offset + 4 > target[5]:
                    raise ValueError("relocation extends beyond its target section")
                target_offset = target[4] + relocation_offset
                output[target_offset : target_offset + 4] = elf[target_offset : target_offset + 4]
    return bytes(output)


def main() -> None:
    if len(sys.argv) < 6:
        raise SystemExit(
            "usage: compose_archive_target.py ARCHIVE MEMBER ROM OUTPUT SECTION:START:END [...]"
        )
    archive, member, rom_path, output = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3]), Path(sys.argv[4])
    rom = rom_path.read_bytes()
    replacements: dict[str, bytes] = {}
    for spec in sys.argv[5:]:
        name, start_text, end_text = spec.rsplit(":", 2)
        start, end = int(start_text, 0), int(end_text, 0)
        if not 0 <= start < end <= len(rom):
            raise ValueError(f"invalid ROM range for {name}: 0x{start:X}-0x{end:X}")
        replacements[name] = rom[start:end]
    member_data = subprocess.run(
        ["ar", "p", str(archive), member], check=True, stdout=subprocess.PIPE
    ).stdout
    result = replace_elf_sections(member_data, replacements)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result)


if __name__ == "__main__":
    main()
