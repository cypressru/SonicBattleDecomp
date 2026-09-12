#!/usr/bin/env python3
"""Independently link and compare a unit's complete ROM sections."""

import argparse
import csv
import hashlib
import re
import struct
import subprocess
import tempfile
from pathlib import Path

import yaml


ROOT = Path(__file__).resolve().parents[1]
BINUTILS = ROOT / "tools/binutils/root/usr/bin"


def known_symbols(config):
    symbols = {}
    functions = {}
    maps = set()
    for unit in config["units"]:
        if unit.get("function_map"):
            maps.add(unit["function_map"])
        for symbol in unit.get("symbols", []):
            address = int(symbol["address"]) + 0x08000000
            mode = symbol.get("mode", "thumb")
            symbols[symbol["name"]] = address | (mode == "thumb")
            if mode in {"arm", "thumb"}:
                functions[address] = mode
    for path in sorted(maps):
        with (ROOT / path).open(newline="") as stream:
            for row in csv.DictReader(stream):
                address = int(row["address"], 0)
                symbols[row["name"]] = address | (row["mode"] == "thumb")
                if row["mode"] in {"arm", "thumb"}:
                    functions[address] = row["mode"]
    return symbols, functions


def resolve_symbol(name, symbols, functions):
    if name in symbols:
        return symbols[name]
    match = re.fullmatch(r"gUnknown_([0-9a-fA-F]{8})", name)
    if match:
        return int(match[1], 16)
    match = re.fullmatch(r"FUN_([0-9a-fA-F]{8})", name)
    if match:
        address = int(match[1], 16)
        if address in functions:
            return address | (functions[address] == "thumb")
    raise ValueError(f"no reviewed address for undefined symbol {name}")


def verify_bss(elf, expected_address, expected_size):
    """Check linked ELF32 little-endian NOBITS ownership, not ROM contents."""
    if len(elf) < 52 or elf[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("expected ELF32 little-endian linked object")
    offset = struct.unpack_from("<I", elf, 32)[0]
    entry_size, count, names_index = struct.unpack_from("<HHH", elf, 46)
    if entry_size != 40 or names_index >= count or offset + count * 40 > len(elf):
        raise ValueError("invalid ELF section table")
    headers = [struct.unpack_from("<10I", elf, offset + i * 40) for i in range(count)]
    names_header = headers[names_index]
    names_start, names_size = names_header[4:6]
    if names_start + names_size > len(elf):
        raise ValueError("invalid ELF section names")
    names = elf[names_start:names_start + names_size]
    found = []
    for header in headers:
        start = header[0]
        end = names.find(b"\0", start)
        if start >= len(names) or end < 0:
            raise ValueError("invalid ELF section name")
        if names[start:end] == b".bss":
            found.append(header)
    if len(found) != 1:
        raise ValueError("expected exactly one linked .bss section")
    header = found[0]
    if header[1] != 8 or header[3] != expected_address or header[5] != expected_size:
        raise ValueError(
            f"linked .bss type/address/size mismatch: "
            f"{header[1]}/{header[3]:#x}/{header[5]:#x}"
        )


def section_script(sections, bss_address):
    """Place owned sections without the default script's trailing BSS rounding."""
    lines = ["SECTIONS {"]
    for section in sections:
        name = section["name"]
        if not re.fullmatch(r"\.[A-Za-z0-9_.]+", name):
            raise ValueError(f"invalid section name {name}")
        address = int(section["start"]) + 0x08000000
        lines.append(f"  {name} {address:#x} : {{ *({name}) }}")
    lines.append(f"  .bss {bss_address:#x} (NOLOAD) : {{ *(.bss) *(COMMON) }}")
    lines.append("}")
    return "\n".join(lines) + "\n"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("unit", help="unit name in config/BSBE78/config.yml")
    args = parser.parse_args()
    config = yaml.safe_load((ROOT / "config/BSBE78/config.yml").read_text())
    unit = next(unit for unit in config["units"] if unit["name"] == args.unit)
    sections = unit.get("target_sections", [
        {"name": ".text", "start": unit["start"], "end": unit["end"]},
    ])
    rom = (ROOT / config["rom"]).read_bytes()
    if hashlib.sha1(rom).hexdigest() != config["sha1"]:
        raise SystemExit("unexpected base ROM SHA-1")
    base = ROOT / "build" / config["version"] / "base" / f"{args.unit}.o"
    symbols, functions = known_symbols(config)
    undefined = subprocess.check_output(
        [str(BINUTILS / "arm-none-eabi-nm"), "--undefined-only", str(base)], text=True,
    )
    # Absolute --defsym values lose STT_FUNC/Thumb metadata and can cause GNU ld
    # to insert ARM interworking veneers. Supply typed symbolic definitions only;
    # this object contains no instructions or data and is not a target-code shim.
    definitions = []
    for line in undefined.splitlines():
        if not line.strip():
            continue
        name = line.split()[-1]
        address = resolve_symbol(name, symbols, functions)
        definitions.append(f".global {name}")
        mode = functions.get(address & ~1)
        if mode:
            definitions.append(f".type {name}, %function")
        directive = ".thumb_set" if mode == "thumb" else ".set"
        definitions.append(f"{directive} {name}, {address:#x}")
    total = 0
    with tempfile.TemporaryDirectory() as directory:
        linked = Path(directory) / "unit.elf"
        binary = Path(directory) / "unit.bin"
        symbol_object = Path(directory) / "symbols.o"
        subprocess.run(
            [str(BINUTILS / "arm-none-eabi-as"), "-mcpu=arm7tdmi", "-o", str(symbol_object), "-"],
            input=("\n".join(definitions) + "\n").encode(), check=True,
        )
        command = [
            str(BINUTILS / "arm-none-eabi-ld"),
            "--fatal-warnings", "-e", "0",
        ]
        for section in sections:
            start, end = int(section["start"]), int(section["end"])
            if not 0 <= start < end <= len(rom):
                raise ValueError(f"invalid ROM extent for {section['name']}")
            command.append(f"--section-start={section['name']}={start + 0x08000000:#x}")
        if "bss_address" in unit:
            # GNU ld's default script pads .bss to a word boundary. That padding
            # is not owned input storage (for example a ten-byte state span).
            # Use explicit output sections so the layout assertion stays exact.
            script = Path(directory) / "sections.ld"
            script.write_text(section_script(sections, int(unit["bss_address"])))
            command.extend(["-T", str(script)])
        subprocess.run([*command, "-o", str(linked), str(base), str(symbol_object)], check=True)
        if "bss_address" in unit:
            bss = next(section for section in unit["synthetic_sections"]
                       if section["name"] == ".bss")
            verify_bss(linked.read_bytes(), int(unit["bss_address"]), int(bss["size"]))
            print(f"{args.unit}: .bss NOBITS address/size verified "
                  f"({int(unit['bss_address']):#x}, {int(bss['size']):#x})")
        for section in sections:
            subprocess.run(
                [str(BINUTILS / "arm-none-eabi-objcopy"), "-O", "binary",
                 f"--only-section={section['name']}", str(linked), str(binary)],
                check=True,
            )
            actual = binary.read_bytes()
            expected = rom[int(section["start"]):int(section["end"])]
            if actual != expected:
                offset = next((i for i, (a, b) in enumerate(zip(actual, expected)) if a != b),
                              min(len(actual), len(expected)))
                raise SystemExit(
                    f"{args.unit}: linked {section['name']} differs at offset {offset:#x} "
                    f"(sizes {len(actual):#x}/{len(expected):#x})"
                )
            total += len(actual)
    print(f"{args.unit}: {total}/{total} linked ROM bytes identical ({len(sections)} sections)")


if __name__ == "__main__":
    main()
