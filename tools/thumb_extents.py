#!/usr/bin/env python3
"""Recover Thumb function extents by control-flow traversal and audit the inventory.

This is a reporting tool, not a CI check. It reconstructs each accepted function's
extent from the ROM by following every reachable basic block, and compares the
result with config/BSBE78/function_extents.csv. It also flags accepted starts that
cannot be function entries: those that sit inside a basic block, and those whose
body pops a frame it never pushed.

Both classes arise from the same cause. GCC's Thumb-1 output reaches intra-function
labels beyond the +/-2 KiB `B` range by emitting `BL` instead, which is safe wherever
`lr` is already dead, so a decoded `BL` does not by itself prove a function entry.

Usage: thumb_extents.py CONFIG ROM [--range START END]
"""

from __future__ import annotations

import csv
import sys
from pathlib import Path

import yaml


ROM_BASE = 0x08000000


def halfword(data: bytes, address: int) -> int:
    offset = address - ROM_BASE
    return int.from_bytes(data[offset : offset + 2], "little")


def is_return(instruction: int) -> bool:
    """`bx rN` / `blx rN`, or `pop` with pc in the register list."""
    return instruction & 0xFF87 == 0x4700 or instruction & 0xFF00 == 0xBD00


def is_frame_push(instruction: int) -> bool:
    """`push {...}` or `sub sp, #imm`."""
    return instruction & 0xFF00 in (0xB400, 0xB500) or instruction & 0xFF80 == 0xB080


def is_frame_pop(instruction: int) -> bool:
    """`pop {...}` or `add sp, #imm`."""
    return instruction & 0xFF00 in (0xBC00, 0xBD00) or instruction & 0xFF80 == 0xB000


def walk(data: bytes, start: int, limit: int, entries: set[int]) -> dict[str, object]:
    """Follow every reachable block from `start`, avoiding proven literal pools.

    Control flow that reaches an independently confirmed entry is a tail call or a
    long jump, not a continuation, so the walk stops there. Two passes are run so
    that pool words discovered late are not decoded as instructions.
    """
    pool: set[int] = set()
    for _ in range(8):
        seen: set[int] = set()
        found: set[int] = set()
        pending = [start]
        end, returns, clean = start, False, True
        while pending:
            address = pending.pop()
            while True:
                if address in seen:
                    break
                if address & 1 or not start <= address < limit or address in pool:
                    clean = False
                    break
                if address != start and address in entries:
                    break
                seen.add(address)
                instruction = halfword(data, address)
                size, stop = 2, False
                if instruction & 0xF800 == 0xF000:
                    following = halfword(data, address + 2)
                    if following & 0xF800 in (0xE800, 0xF800):
                        size = 4
                        seen.add(address + 2)
                    else:
                        clean = False
                elif instruction & 0xF800 in (0x4800, 0xA000):
                    slot = ((address + 4) & ~3) + (instruction & 0xFF) * 4
                    found.update((slot, slot + 2))
                elif instruction & 0xF000 == 0xD000 and (instruction >> 8) & 0xF < 0xE:
                    displacement = instruction & 0xFF
                    if displacement & 0x80:
                        displacement -= 0x100
                    pending.append(address + 4 + displacement * 2)
                elif instruction & 0xF800 == 0xE000:
                    displacement = instruction & 0x7FF
                    if displacement & 0x400:
                        displacement -= 0x800
                    pending.append(address + 4 + displacement * 2)
                    stop = True
                elif is_return(instruction):
                    returns, stop = True, True
                end = max(end, address + size)
                if stop:
                    break
                address += size
        if found <= pool:
            break
        pool |= found
    return {"end": end, "returns": returns, "clean": clean, "instructions": len(seen)}


def opens_frame_before_closing(data: bytes, start: int, end: int) -> bool:
    """True unless the body pops or unwinds a frame it never established."""
    address, opened = start, False
    while address < end:
        instruction = halfword(data, address)
        if is_frame_push(instruction):
            opened = True
        if is_frame_pop(instruction):
            return opened
        if instruction & 0xF800 == 0xF000 and halfword(data, address + 2) & 0xF800 in (
            0xE800,
            0xF800,
        ):
            address += 4
            continue
        address += 2
    return True


def preceded_by_terminator(data: bytes, address: int, previous_end: int) -> bool:
    """True if a function may begin here: after a return, a `b`, or pool/alignment."""
    if previous_end < address:
        return True
    instruction = halfword(data, address - 2)
    return instruction == 0 or is_return(instruction) or instruction & 0xF800 == 0xE000


def main() -> None:
    arguments = sys.argv[1:]
    bounds: tuple[int, int] | None = None
    if len(arguments) == 5 and arguments[2] == "--range":
        bounds = (int(arguments[3], 0), int(arguments[4], 0))
        arguments = arguments[:2]
    if len(arguments) != 2:
        raise SystemExit("usage: thumb_extents.py CONFIG ROM [--range START END]")

    config_path, rom_path = Path(arguments[0]), Path(arguments[1])
    root = config_path.parents[2]
    config = yaml.safe_load(config_path.read_text(encoding="utf-8"))
    data = rom_path.read_bytes()

    with (root / config["function_size_map"]).open(newline="", encoding="utf-8") as stream:
        extents = {int(row["address"], 0): int(row["end"], 0) for row in csv.DictReader(stream)}
    with (root / "config/BSBE78/functions.csv").open(newline="", encoding="utf-8") as stream:
        confidence = {int(row["address"], 0): row["confidence"] for row in csv.DictReader(stream)}

    entries = {
        address
        for address, evidence in confidence.items()
        if "direct-call" in evidence or "rom-pointer" in evidence
    }
    low, high = bounds if bounds else (min(extents), max(extents.values()))
    starts = sorted(address for address in extents if low <= address < high)
    if not starts:
        raise SystemExit("no accepted function starts in the requested range")

    disagreements: list[tuple[int, int, int]] = []
    mid_block: list[int] = []
    unbalanced: list[int] = []
    for index, start in enumerate(starts):
        accepted_end = extents[start]
        result = walk(data, start, min(high, start + 0x4000), entries)
        if result["clean"] and result["returns"] and result["end"] != accepted_end:
            disagreements.append((start, accepted_end, int(result["end"])))
        # Use the real preceding extent, not the range floor, so a start on the
        # requested boundary is not judged against unrelated bytes before it.
        preceding = [end for begin, end in extents.items() if begin < start]
        previous_end = max(preceding) if preceding else start
        if not preceded_by_terminator(data, start, previous_end):
            mid_block.append(start)
        elif not opens_frame_before_closing(data, start, accepted_end):
            unbalanced.append(start)

    print(f"{len(starts)} accepted starts in 0x{low:08X}-0x{high:08X}")
    print(f"{len(disagreements)} extents disagree with the control-flow walk")
    for start, accepted_end, recovered in disagreements:
        print(f"  0x{start:08X}: accepted 0x{accepted_end:08X}, walk 0x{recovered:08X}")
    print(f"{len(mid_block)} starts sit inside a basic block")
    for start in mid_block:
        print(f"  0x{start:08X}  {confidence.get(start, 'unknown')}")
    print(f"{len(unbalanced)} starts unwind a frame they never establish")
    for start in unbalanced:
        print(f"  0x{start:08X}  {confidence.get(start, 'unknown')}")


if __name__ == "__main__":
    main()
