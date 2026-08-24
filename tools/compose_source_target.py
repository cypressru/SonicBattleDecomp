#!/usr/bin/env python3
"""Compose a multi-section target object from a compiled base object and ROM bytes."""

from __future__ import annotations

import sys
from pathlib import Path

from compose_archive_target import replace_elf_sections


def main() -> None:
    if len(sys.argv) < 5:
        raise SystemExit(
            "usage: compose_source_target.py BASE ROM OUTPUT SECTION:START:END [...]"
        )

    base_path, rom_path, output = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
    rom = rom_path.read_bytes()
    replacements: dict[str, bytes] = {}
    for spec in sys.argv[4:]:
        name, start_text, end_text = spec.rsplit(":", 2)
        start, end = int(start_text, 0), int(end_text, 0)
        if not 0 <= start < end <= len(rom):
            raise ValueError(f"invalid ROM range for {name}: 0x{start:X}-0x{end:X}")
        replacements[name] = rom[start:end]

    result = replace_elf_sections(
        base_path.read_bytes(), replacements, preserve_relocated_bytes=True
    )
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result)


if __name__ == "__main__":
    main()
