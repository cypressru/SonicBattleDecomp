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


def owning_extent(extents: dict[int, int], target: int) -> int | None:
    """The accepted function whose body strictly contains `target`, if any."""
    for start, end in extents.items():
        if start < target < end:
            return start
    return None


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: check_function_map.py CONFIG ROM")
    config_path, rom_path = Path(sys.argv[1]), Path(sys.argv[2])
    root = config_path.parents[2]
    config = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    data = rom_path.read_bytes()

    rejected_pointers = {
        (ROM_BASE + int(item["source"]), int(item["destination"]))
        for item in config.get("rejected_function_pointers", [])
    }
    for source, destination in rejected_pointers:
        actual = int.from_bytes(data[source - ROM_BASE : source - ROM_BASE + 4], "little")
        if actual != destination | 1:
            raise SystemExit(
                f"rejected function pointer changed at 0x{source:08X}: "
                f"expected 0x{destination | 1:08X}, found 0x{actual:08X}"
            )

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
    # GCC reaches an intra-function label beyond the +/-2 KiB `B` range by emitting
    # `BL` wherever `lr` is already dead, so a decoded `BL` does not by itself prove
    # a function entry. Each such destination is declared here rather than being
    # accepted as a function, and every declaration is validated: it must lie strictly
    # inside an accepted extent, must not also be an accepted start, and must actually
    # be reached by a `BL`. A stale or unreachable declaration is an error.
    long_branch_targets = {int(value) for value in config.get("long_branch_targets", [])}
    for target in sorted(long_branch_targets):
        if target in accepted:
            raise SystemExit(
                f"declared long-branch target 0x{target:08X} is also an accepted function start"
            )
        if owning_extent(extents, target) is None:
            raise SystemExit(
                f"declared long-branch target 0x{target:08X} is not interior to any accepted extent"
            )

    ordered_extents = sorted(extents.items())
    for (start, end), (next_start, _next_end) in zip(ordered_extents, ordered_extents[1:]):
        if end > next_start:
            raise SystemExit(
                f"function extent 0x{start:08X}-0x{end:08X} overlaps "
                f"the next entry at 0x{next_start:08X}"
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
    reached_long_branch_targets: set[int] = set()
    instruction_bytes = bytearray(len(data))
    for start, end in extents.items():
        instruction_bytes[start - ROM_BASE : end - ROM_BASE] = b"\1" * (end - start)
        for address in range(start & ~1, end - 3, 2):
            destination = thumb_bl_destination(data, address)
            if destination is None or not ROM_BASE <= destination < executable_end:
                continue
            if destination in long_branch_targets:
                reached_long_branch_targets.add(destination)
            elif destination not in accepted:
                missing_calls.setdefault(destination, []).append(address)
    unreached = long_branch_targets - reached_long_branch_targets
    if unreached:
        details = ", ".join(f"0x{target:08X}" for target in sorted(unreached))
        raise SystemExit(f"declared long-branch targets are never reached by a call: {details}")
    if missing_calls:
        details = ", ".join(
            f"0x{destination:08X} ({len(callers)} callers)"
            for destination, callers in sorted(missing_calls.items())
        )
        raise SystemExit(f"direct calls target unrecorded functions: {details}")

    missing_pointers: dict[int, list[int]] = {}
    for offset in range(0, min(len(data), executable_end - ROM_BASE) - 3, 2):
        if any(instruction_bytes[offset : offset + 4]):
            continue
        value = int.from_bytes(data[offset : offset + 4], "little")
        destination = value & ~1
        if (
            value & 1
            and ROM_BASE <= destination < executable_end
            and destination not in accepted
            and (ROM_BASE + offset, destination) not in rejected_pointers
        ):
            missing_pointers.setdefault(destination, []).append(ROM_BASE + offset)
    if missing_pointers:
        details = ", ".join(
            f"0x{destination:08X} ({len(sources)} pointers)"
            for destination, sources in sorted(missing_pointers.items())
        )
        raise SystemExit(f"Thumb pointers target unrecorded functions: {details}")
    print(
        f"Function map verified: {len(extents)} analyzed extents; "
        f"{len(long_branch_targets)} validated long-branch targets; "
        "every in-range Thumb BL and halfword-aligned function-pointer destination is symbolized "
        "or declared interior to an accepted extent"
    )


if __name__ == "__main__":
    main()
