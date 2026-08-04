#!/usr/bin/env python3
"""Reject game binaries and generated reverse-engineering output from Git."""

import subprocess
import sys

FORBIDDEN_PREFIXES = ("rom/", "asm/", "assets/", "build/", "expected/")
FORBIDDEN_SUFFIXES = (".gba", ".bin", ".elf", ".o", ".a")

tracked = subprocess.check_output(["git", "ls-files"], text=True).splitlines()
bad = [p for p in tracked if p.startswith(FORBIDDEN_PREFIXES) and p != "rom/.gitkeep"]
bad += [p for p in tracked if p.lower().endswith(FORBIDDEN_SUFFIXES)]
if bad:
    print("forbidden proprietary/generated files are tracked:", file=sys.stderr)
    print("\n".join(sorted(set(bad))), file=sys.stderr)
    raise SystemExit(1)
