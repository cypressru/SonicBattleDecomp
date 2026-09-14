#!/usr/bin/env python3
"""Independently link and compare a single-text-section unit to its ROM extent."""

import argparse
import hashlib
import subprocess
import tempfile
from pathlib import Path

import yaml


ROOT = Path(__file__).resolve().parents[1]
BINUTILS = ROOT / "tools/binutils/root/usr/bin"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("unit", help="unit name in config/BSBE78/config.yml")
    args = parser.parse_args()
    config = yaml.safe_load((ROOT / "config/BSBE78/config.yml").read_text())
    unit = next(unit for unit in config["units"] if unit["name"] == args.unit)
    if unit.get("target_sections"):
        raise SystemExit("this checker requires a single ROM .text extent")
    rom = (ROOT / config["rom"]).read_bytes()
    if hashlib.sha1(rom).hexdigest() != config["sha1"]:
        raise SystemExit("unexpected base ROM SHA-1")
    start, end = int(unit["start"]), int(unit["end"])
    base = ROOT / "build" / config["version"] / "base" / f"{args.unit}.o"
    with tempfile.TemporaryDirectory() as directory:
        linked = Path(directory) / "unit.elf"
        binary = Path(directory) / "unit.bin"
        command = [
            str(BINUTILS / "arm-none-eabi-ld"),
            "--fatal-warnings", "-e", "0",
            f"-Ttext={start + 0x08000000:#x}",
        ]
        if "bss_address" in unit:
            command.append(f"-Tbss={int(unit['bss_address']):#x}")
        subprocess.run([*command, "-o", str(linked), str(base)], check=True)
        subprocess.run(
            [str(BINUTILS / "arm-none-eabi-objcopy"), "-O", "binary",
             "--only-section=.text", str(linked), str(binary)],
            check=True,
        )
        actual = binary.read_bytes()
    expected = rom[start:end]
    if actual != expected:
        raise SystemExit(f"{args.unit}: linked .text does not match the complete ROM extent")
    print(f"{args.unit}: {len(actual)}/{len(expected)} linked ROM bytes identical")


if __name__ == "__main__":
    main()
