import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

from compile_agbcc import patch_symbol_sizes


ROOT = Path(__file__).resolve().parents[1]


class SymbolSizeOverrideTests(unittest.TestCase):
    def test_patches_only_the_requested_elf_symbol_size(self):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / "input.bin"
            output = directory / "output.o"
            source.write_bytes(b"\0" * 8)
            subprocess.run(
                [
                    sys.executable,
                    str(ROOT / "tools/slice_object.py"),
                    str(source),
                    str(output),
                    "0",
                    "8",
                    "code",
                    "Function:0:thumb:8",
                ],
                check=True,
            )

            patch_symbol_sizes(output, {"Function": 6})

            data = output.read_bytes()
            self.assertIn(b"Function\0", data)
            header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
            sections = [
                struct.unpack_from("<IIIIIIIIII", data, header[6] + i * header[11])
                for i in range(header[12])
            ]
            symtab = next(section for section in sections if section[1] == 2)
            sizes = [
                struct.unpack_from("<I", data, offset + 8)[0]
                for offset in range(symtab[4], symtab[4] + symtab[5], symtab[9])
            ]
            self.assertEqual(sizes[-1], 6)

    def test_rejects_unknown_symbol(self):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / "input.bin"
            output = directory / "output.o"
            source.write_bytes(b"\0" * 4)
            subprocess.run(
                [
                    sys.executable,
                    str(ROOT / "tools/slice_object.py"),
                    str(source),
                    str(output),
                    "0",
                    "4",
                    "code",
                    "Function:0:thumb:4",
                ],
                check=True,
            )
            with self.assertRaisesRegex(ValueError, "Missing"):
                patch_symbol_sizes(output, {"Missing": 4})


if __name__ == "__main__":
    unittest.main()
