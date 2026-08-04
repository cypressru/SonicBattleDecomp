#!/usr/bin/env python3
"""Verify accepted function extents and all direct-call destinations."""

from __future__ import annotations

import csv
import sys
from pathlib import Path

import yaml


ROM_BASE = 0x08000000


def thumb_bl_destination(data: bytes, address: int) -> int | None:
    offset = address - ROM_BASE
    if offset < 0 or offset + 4 > len(data):
        return None
    first = int.from_bytes(data[offset : offset + 2], "little")
    second = int.from_bytes(data[offset + 2 : offset + 4], "little")
    if first & 0xF800 != 0xF000 or second & 0xF800 != 0xF800:
        return None
    displacement = ((first & 0x7FF) << 12) | ((second & 0x7FF) << 1)
    if displacement & (1 << 22):
        displacement -= 1 << 23
    return address + 4 + displacement


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        return list(csv.DictReader(stream))


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: check_function_map.py CONFIG ROM")
    config_path, rom_path = Path(sys.argv[1]), Path(sys.argv[2])
    root = config_path.parents[2]
    config = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    data = rom_path.read_bytes()

    function_rows = read_csv(root / "config/BSBE78/functions.csv")
    accepted = {int(row["address"], 0) for row in function_rows}
    if len(accepted) != len(function_rows):
        raise SystemExit("function map contains duplicate addresses")

    extents: dict[int, int] = {}
    for row in read_csv(root / config["function_size_map"]):
        start, end = int(row["address"], 0), int(row["end"], 0)
        if start in extents or end <= start:
            raise SystemExit(f"invalid or duplicate function extent at 0x{start:08X}")
        extents[start] = end
    if accepted != extents.keys():
        missing_sizes = accepted - extents.keys()
        orphan_sizes = extents.keys() - accepted
        raise SystemExit(
            f"function/extent inventory differs: {len(missing_sizes)} missing sizes, "
            f"{len(orphan_sizes)} orphan sizes"
        )

    executable_end = ROM_BASE
    for unit in config["units"]:
        if unit.get("kind", "code") != "code" or unit["category"] not in {
            "game",
            "sdk",
            "runtime",
        }:
            continue
        executable_end = max(executable_end, ROM_BASE + int(unit["end"]))
        accepted.add(ROM_BASE + int(unit["start"]))
        for symbol in unit.get("symbols", []):
            if symbol.get("mode", "thumb") in {"thumb", "arm"}:
                accepted.add(ROM_BASE + int(symbol["address"]))

    missing_calls: dict[int, list[int]] = {}
    for start, end in extents.items():
        for address in range(start & ~1, end - 3, 2):
            destination = thumb_bl_destination(data, address)
            if (
                destination is not None
                and ROM_BASE <= destination < executable_end
                and destination not in accepted
            ):
                missing_calls.setdefault(destination, []).append(address)
    if missing_calls:
        details = ", ".join(
            f"0x{destination:08X} ({len(callers)} callers)"
            for destination, callers in sorted(missing_calls.items())
        )
        raise SystemExit(f"direct calls target unrecorded functions: {details}")
    print(
        f"Function map verified: {len(extents)} analyzed extents; "
        "every in-range Thumb BL destination is symbolized"
    )


if __name__ == "__main__":
    main()
