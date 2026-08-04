#!/usr/bin/env python3
"""Extract one object produced by the pinned compiler build."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


def main() -> None:
    if len(sys.argv) != 4:
        raise SystemExit("usage: extract_archive_member.py ARCHIVE MEMBER OUTPUT")
    archive, member, output = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3])
    if not archive.is_file():
        raise SystemExit(f"missing compiler archive: {archive}")
    result = subprocess.run(
        ["ar", "p", str(archive), member],
        check=True,
        stdout=subprocess.PIPE,
    )
    if not result.stdout.startswith(b"\x7fELF"):
        raise SystemExit(f"archive member is not an ELF object: {member}")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(result.stdout)


if __name__ == "__main__":
    main()
