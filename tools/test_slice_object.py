import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


class SliceObjectRelocationTests(unittest.TestCase):
    def test_emits_thumb_call_and_abs32_relocations(self):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / "input.bin"
            output = directory / "output.o"
            source.write_bytes(bytes(range(16)))

            subprocess.run(
                [
                    sys.executable,
                    str(ROOT / "tools/slice_object.py"),
                    str(source),
                    str(output),
                    "0",
                    "16",
                    "code",
                    "Function:0:thumb:16",
                    "@rel:4:thumb_call:Callee",
                    "@rel:12:abs32:Global",
                    "@map:8:data",
                    "@map:10:thumb",
                ],
                check=True,
            )

            data = output.read_bytes()
            header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
            section_offset, section_size, section_count, string_index = (
                header[6],
                header[11],
                header[12],
                header[13],
            )
            self.assertEqual((section_size, section_count, string_index), (40, 6, 5))

            sections = [
                struct.unpack_from("<IIIIIIIIII", data, section_offset + index * section_size)
                for index in range(section_count)
            ]
            names_section = sections[string_index]
            names = data[names_section[4] : names_section[4] + names_section[5]]

            def section_name(section):
                end = names.index(b"\0", section[0])
                return names[section[0] : end].decode("ascii")

            sections_by_name = {section_name(section): section for section in sections}
            text = sections_by_name[".text"]
            payload = data[text[4] : text[4] + text[5]]
            self.assertEqual(payload[4:8], b"\xff\xf7\xfe\xff")
            self.assertEqual(payload[12:16], b"\0\0\0\0")

            relocations = sections_by_name[".rel.text"]
            entries = [
                struct.unpack_from("<II", data, offset)
                for offset in range(
                    relocations[4], relocations[4] + relocations[5], relocations[9]
                )
            ]
            self.assertEqual([(offset, info & 0xFF) for offset, info in entries], [(4, 10), (12, 2)])

            symbols = sections_by_name[".symtab"]
            strings = sections[ symbols[6] ]
            string_data = data[strings[4] : strings[4] + strings[5]]
            mapping_symbols = []
            for offset in range(symbols[4], symbols[4] + symbols[5], symbols[9]):
                name_offset, value = struct.unpack_from("<II", data, offset)
                end = string_data.index(b"\0", name_offset)
                name = string_data[name_offset:end].decode("ascii")
                if name in {"$a", "$t", "$d"}:
                    mapping_symbols.append((value, name))
            self.assertIn((8, "$d"), mapping_symbols)
            self.assertIn((10, "$t"), mapping_symbols)

    def test_rejects_relocation_outside_slice(self):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / "input.bin"
            source.write_bytes(b"\0" * 4)
            result = subprocess.run(
                [
                    sys.executable,
                    str(ROOT / "tools/slice_object.py"),
                    str(source),
                    str(directory / "output.o"),
                    "0",
                    "4",
                    "code",
                    "Function:0:thumb:4",
                    "@rel:2:thumb_call:Callee",
                ],
                capture_output=True,
                text=True,
            )
            self.assertNotEqual(result.returncode, 0)
            self.assertIn("outside slice", result.stderr)


if __name__ == "__main__":
    unittest.main()
