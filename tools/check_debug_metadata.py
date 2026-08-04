#!/usr/bin/env python3
"""Audit a retail ROM for common surviving compiler/debug metadata strings."""

from __future__ import annotations

import re
import sys
from pathlib import Path


DEBUG_MARKERS = (
    b".debug_info",
    b".debug_line",
    b".debug_abbrev",
    b".stabstr",
    b".symtab",
    b".strtab",
    b"GCC: (GNU)",
)
SOURCE_PATH = re.compile(
    rb"(?:[A-Za-z]:[\\/]|(?:^|[\x00\s])[./]*[A-Za-z0-9_.-]+[\\/])"
    rb"[A-Za-z0-9_./\\-]+\.(?:c|cc|cpp|cxx|h|hpp|s|asm)(?:\x00|\s)",
    re.IGNORECASE,
)


def find_debug_metadata(data: bytes) -> list[str]:
    findings = [marker.decode("ascii") for marker in DEBUG_MARKERS if marker in data]
    findings.extend(match.group(0).decode("ascii", "replace").strip("\0 \t\r\n") for match in SOURCE_PATH.finditer(data))
    return findings


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_debug_metadata.py ROM")
    findings = find_debug_metadata(Path(sys.argv[1]).read_bytes())
    if findings:
        raise SystemExit("possible compiler/debug metadata found: " + ", ".join(findings))
    print("No common compiler, debug-section, symbol-table, or source-path strings detected")


if __name__ == "__main__":
    main()
