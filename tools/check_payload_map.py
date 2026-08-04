#!/usr/bin/env python3
"""Validate the embedded GBA test-program and its compressed-stream map."""

from __future__ import annotations

import sys
from pathlib import Path


PAYLOAD_START = 0xEEB690
STREAMS = [
    (0x1D8, 0x4330, 0x49F8),
    (0x4330, 0x2A9C8, 0x2D1B8),
    (0x2A9C8, 0x49BC7, 0x3315C),
    (0x49BC8, 0x739BC, 0x38AF0),
    (0x739BC, 0x96680, 0x342DC),
    (0x96680, 0xB3787, 0x29C0C),
]


def lz77_end(data: bytes, start: int) -> tuple[int, int]:
    if data[start] != 0x10:
        raise ValueError(f"missing LZ77 header at payload offset 0x{start:X}")
    raw_size = int.from_bytes(data[start + 1 : start + 4], "little")
    cursor, produced = start + 4, 0
    while produced < raw_size:
        flags = data[cursor]
        cursor += 1
        for bit in range(7, -1, -1):
            if produced >= raw_size:
                break
            if flags & (1 << bit):
                produced += (data[cursor] >> 4) + 3
                cursor += 2
            else:
                produced += 1
                cursor += 1
    return cursor, raw_size


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_payload_map.py ROM")
    payload = Path(sys.argv[1]).read_bytes()[PAYLOAD_START:]
    if payload[0xA0:0xAC] != b"AGB TEST PRG":
        raise SystemExit("embedded GBA header was not found")
    for start, expected_end, expected_raw_size in STREAMS:
        actual = lz77_end(payload, start)
        if actual != (expected_end, expected_raw_size):
            raise SystemExit(f"unexpected stream at 0x{start:X}: {actual!r}")
    if any(payload[0xB3788:]):
        raise SystemExit("embedded payload padding is not entirely zero")
    print("Embedded payload map verified")


if __name__ == "__main__":
    main()
