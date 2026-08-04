#!/usr/bin/env python3
"""Compile one C translation unit with the pinned legacy agbcc toolchain."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
AGBCC = ROOT / "tools/agbcc/agbcc"
AS = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-as"


def main() -> None:
    if len(sys.argv) < 3:
        raise SystemExit("usage: compile_agbcc.py INPUT OUTPUT [CC1 FLAGS...]")
    source, output = Path(sys.argv[1]), Path(sys.argv[2])
    if not AGBCC.is_file():
        raise SystemExit("missing pinned agbcc; run tools/setup_agbcc.sh")
    if not AS.is_file():
        raise SystemExit("missing ARM binutils assembler")
    cpp = subprocess.run(
        [
            "cpp",
            "-I",
            str(ROOT / "include"),
            "-I",
            str(ROOT / "tools/agbcc/include"),
            "-nostdinc",
            "-undef",
            "-std=gnu89",
            str(source),
        ],
        check=True,
        stdout=subprocess.PIPE,
    )
    cc1_flags = sys.argv[3:] or ["-O2"]
    assembly = subprocess.run(
        [str(AGBCC), *cc1_flags, "-o", "-", "-"],
        input=cpp.stdout,
        check=True,
        stdout=subprocess.PIPE,
    )
    output.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(
        [str(AS), "-mcpu=arm7tdmi", "-o", str(output), "-"],
        input=assembly.stdout,
        check=True,
    )


if __name__ == "__main__":
    main()
