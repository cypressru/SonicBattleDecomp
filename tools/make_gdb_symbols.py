#!/usr/bin/env python3
"""Build a symbol-only ARM object from the reviewed Sonic Battle function map."""

from __future__ import annotations

import argparse
import csv
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_INPUT = ROOT / "config/BSBE78/functions.csv"
DEFAULT_OUTPUT = ROOT / "build/debug/sonic_battle_symbols.elf"
IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
ROM_BASE = 0x08000000


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, default=DEFAULT_INPUT)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    args = parser.parse_args()

    rows = list(csv.DictReader(args.input.open(newline="", encoding="utf-8")))
    lines = [".syntax unified", ".thumb", '.section .text, "ax", %progbits']
    seen: set[str] = set()
    previous_address = ROM_BASE
    for row in rows:
        name = row["name"]
        if not IDENTIFIER.fullmatch(name):
            raise SystemExit(f"invalid debugger symbol name: {name!r}")
        if name in seen:
            raise SystemExit(f"duplicate debugger symbol name: {name}")
        seen.add(name)
        address = int(row["address"], 0)
        if address < previous_address:
            raise SystemExit("debugger function map is not sorted by address")
        previous_address = address
        lines.extend(
            (
                f".org 0x{address - ROM_BASE:X}",
                f".global {name}",
                f".type {name}, %function",
                ".thumb_func",
                f"{name}:",
            )
        )

    args.output.parent.mkdir(parents=True, exist_ok=True)
    assembler = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-as"
    linker = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-ld"
    object_path = args.output.with_suffix(".o")
    subprocess.run(
        [str(assembler), "-mthumb-interwork", "-o", str(object_path), "-"],
        input="\n".join(lines) + "\n",
        text=True,
        check=True,
    )
    try:
        subprocess.run(
            [
                str(linker),
                "-Ttext=0x08000000",
                "-e",
                "0x080000C0",
                "-o",
                str(args.output),
                str(object_path),
            ],
            check=True,
        )
    finally:
        object_path.unlink(missing_ok=True)
    print(f"wrote {args.output.relative_to(ROOT)} with {len(rows)} reviewed function symbols")


if __name__ == "__main__":
    main()
