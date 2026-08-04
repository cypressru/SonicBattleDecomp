"""Derive referenced starts inside the uncompressed graphics region."""

from __future__ import annotations

import bisect


ROM_BASE = 0x08000000
CODE_END = 0x04B718
RAW_ASSET_START = 0x3F4418
RAW_ASSET_END = 0xBF2118
EXPECTED_STARTS = 151


def derive_raw_asset_ranges(data: bytes, function_ends: dict[int, int]) -> list[dict[str, str]]:
    """Return aligned targets referenced from known non-instruction code bytes.

    References are read only from literal pools and other owned data between
    accepted function extents. This avoids treating pixel words that merely
    resemble 0x08xxxxxx pointers as evidence.
    """

    extents = sorted(function_ends.items())
    starts = [start for start, _end in extents]
    targets: set[int] = set()
    for offset in range(0, CODE_END, 4):
        index = bisect.bisect_right(starts, offset) - 1
        if index >= 0 and offset < extents[index][1]:
            continue
        target = int.from_bytes(data[offset : offset + 4], "little") - ROM_BASE
        if RAW_ASSET_START < target < RAW_ASSET_END and target % 4 == 0:
            targets.add(target)
    if len(targets) != EXPECTED_STARTS:
        raise ValueError(
            f"expected {EXPECTED_STARTS} code-referenced raw-asset starts, found {len(targets)}"
        )
    return [
        {
            "address": hex(ROM_BASE + target),
            "name": f"raw_asset_referenced_{target:06x}",
            "mode": "data",
            "confidence": "aligned-pointer-from-code-owned-data",
        }
        for target in sorted(targets)
    ]
