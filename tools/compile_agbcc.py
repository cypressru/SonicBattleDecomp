#!/usr/bin/env python3
"""Compile one C translation unit with the pinned legacy agbcc toolchain."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
AGBCC = ROOT / "tools/agbcc/agbcc"
OLD_AGBCC = ROOT / "tools/agbcc/old_agbcc"
AS = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-as"


def main() -> None:
    if len(sys.argv) < 3:
        raise SystemExit("usage: compile_agbcc.py INPUT OUTPUT [CC1 FLAGS...]")
    source, output = Path(sys.argv[1]), Path(sys.argv[2])
    cc1_flags = sys.argv[3:]
    compiler = AGBCC
    old_libc_mode = "--old-agbcc" in cc1_flags
    if old_libc_mode:
        cc1_flags.remove("--old-agbcc")
        compiler = OLD_AGBCC
    if not compiler.is_file():
        raise SystemExit("missing pinned agbcc; run tools/setup_agbcc.sh")
    if not AS.is_file():
        raise SystemExit("missing ARM binutils assembler")
    cpp_args = [
            "cpp",
            "-I",
            str(ROOT / "include"),
            "-I",
            str(ROOT / "tools/agbcc/include"),
            "-I",
            str(ROOT / "tools/agbcc/libc/include"),
            "-I",
            str(ROOT / "tools/agbcc/gcc_arm/ginclude"),
            "-nostdinc",
            "-undef",
            "-std=gnu89",
        ]
    if old_libc_mode:
        cpp_args.extend(
            [
                "-DABORT_PROVIDED",
                "-DHAVE_GETTIMEOFDAY",
                "-D__thumb__",
                "-DARM_RDI_MONITOR",
                "-D__GNUC__",
                "-DINTERNAL_NEWLIB",
                "-D__USER_LABEL_PREFIX__=",
            ]
        )
    cpp_args.append(str(source))
    cpp = subprocess.run(
        cpp_args,
        check=True,
        stdout=subprocess.PIPE,
    )
    cc1_flags = cc1_flags or ["-O2"]
    assembly = subprocess.run(
        [str(compiler), *cc1_flags, "-o", "-", "-"],
        input=cpp.stdout,
        check=True,
        stdout=subprocess.PIPE,
    )
    output.parent.mkdir(parents=True, exist_ok=True)
    assembly_input = assembly.stdout + b"\n.text\n\t.align 2, 0\n"
    subprocess.run(
        [str(AS), "-mcpu=arm7tdmi", "-o", str(output), "-"],
        input=assembly_input,
        check=True,
    )


if __name__ == "__main__":
    main()
