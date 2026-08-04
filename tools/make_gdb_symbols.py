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
DEFAULT_OUTPUT = ROOT / "build/debug/sonic_battle_symbols.o"
IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, default=DEFAULT_INPUT)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    args = parser.parse_args()

    rows = list(csv.DictReader(args.input.open(newline="", encoding="utf-8")))
    lines = [".syntax unified", ".thumb"]
    seen: set[str] = set()
    for row in rows:
        name = row["name"]
        if not IDENTIFIER.fullmatch(name):
            raise SystemExit(f"invalid debugger symbol name: {name!r}")
        if name in seen:
            raise SystemExit(f"duplicate debugger symbol name: {name}")
        seen.add(name)
        address = int(row["address"], 0)
        lines.extend((f".global {name}", f".thumb_set {name}, 0x{address:X}", f".type {name}, %function"))

    args.output.parent.mkdir(parents=True, exist_ok=True)
    assembler = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-as"
    subprocess.run(
        [str(assembler), "-mthumb-interwork", "-o", str(args.output), "-"],
        input="\n".join(lines) + "\n",
        text=True,
        check=True,
    )
    print(f"wrote {args.output.relative_to(ROOT)} with {len(rows)} reviewed function symbols")


if __name__ == "__main__":
    main()
