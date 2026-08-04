#!/usr/bin/env python3
"""Compile one C translation unit with the pinned legacy agbcc toolchain."""

from __future__ import annotations

import subprocess
import struct
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
AGBCC = ROOT / "tools/agbcc/agbcc"
OLD_AGBCC = ROOT / "tools/agbcc/old_agbcc"
AS = ROOT / "tools/binutils/root/usr/bin/arm-none-eabi-as"


def patch_symbol_sizes(path: Path, overrides: dict[str, int]) -> None:
    if not overrides:
        return
    data = bytearray(path.read_bytes())
    header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
    section_offset, section_size, section_count = header[6], header[11], header[12]
    sections = [
        struct.unpack_from("<IIIIIIIIII", data, section_offset + index * section_size)
        for index in range(section_count)
    ]
    found: set[str] = set()
    for section in sections:
        if section[1] != 2:  # SHT_SYMTAB
            continue
        string_section = sections[section[6]]
        strings = data[string_section[4] : string_section[4] + string_section[5]]
        for offset in range(section[4], section[4] + section[5], section[9]):
            name_offset = struct.unpack_from("<I", data, offset)[0]
            name_end = strings.index(0, name_offset)
            name = strings[name_offset:name_end].decode("utf-8")
            if name in overrides:
                struct.pack_into("<I", data, offset + 8, overrides[name])
                found.add(name)
    missing = overrides.keys() - found
    if missing:
        raise ValueError(f"cannot override missing symbols: {', '.join(sorted(missing))}")
    path.write_bytes(data)


def main() -> None:
    if len(sys.argv) < 3:
        raise SystemExit("usage: compile_agbcc.py INPUT OUTPUT [CC1 FLAGS...]")
    source, output = Path(sys.argv[1]), Path(sys.argv[2])
    cc1_flags = sys.argv[3:]
    symbol_sizes = {}
    for flag in list(cc1_flags):
        if flag.startswith("@symbol-size:"):
            _tag, name, size = flag.split(":", 2)
            symbol_sizes[name] = int(size, 0)
            cc1_flags.remove(flag)
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
    patch_symbol_sizes(output, symbol_sizes)


if __name__ == "__main__":
    main()
