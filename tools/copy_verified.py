#!/usr/bin/env python3
"""Bootstrap linker placeholder until the ROM has real object boundaries."""

import shutil
import sys
from pathlib import Path

source, output = Path(sys.argv[1]), Path(sys.argv[2])
output.parent.mkdir(parents=True, exist_ok=True)
shutil.copyfile(source, output)
