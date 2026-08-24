import struct
import unittest

from compose_archive_target import replace_elf_sections


class ReplaceElfSectionsTests(unittest.TestCase):
    def test_replaces_equal_sized_named_section(self):
        names = b"\0.text\0.shstrtab\0"
        header = bytearray(52)
        header[:7] = b"\x7fELF\x01\x01\x01"
        struct.pack_into("<I", header, 0x20, 76)
        struct.pack_into("<HHH", header, 0x2E, 40, 3, 2)
        sections = b"\0" * 40
        sections += struct.pack("<IIIIIIIIII", 1, 1, 0, 0, 52, 4, 0, 0, 1, 0)
        sections += struct.pack("<IIIIIIIIII", 7, 3, 0, 0, 56, len(names), 0, 0, 1, 0)
        elf = bytes(header) + b"old!" + names + b"\0" * (76 - 56 - len(names)) + sections
        self.assertEqual(replace_elf_sections(elf, {".text": b"new!"})[52:56], b"new!")

    def test_rejects_size_mismatch(self):
        with self.assertRaisesRegex(ValueError, "32-bit little-endian"):
            replace_elf_sections(b"not ELF", {".text": b"x"})

    def test_preserves_words_covered_by_relocations(self):
        names = b"\0.text\0.rel.text\0.shstrtab\0"
        header = bytearray(52)
        header[:7] = b"\x7fELF\x01\x01\x01"
        section_offset = 52 + 4 + 8 + len(names)
        struct.pack_into("<I", header, 0x20, section_offset)
        struct.pack_into("<HHH", header, 0x2E, 40, 4, 3)
        text = b"base"
        relocation = struct.pack("<II", 0, 2)
        sections = b"\0" * 40
        sections += struct.pack("<IIIIIIIIII", 1, 1, 0, 0, 52, 4, 0, 0, 1, 0)
        sections += struct.pack("<IIIIIIIIII", 7, 9, 0, 0, 56, 8, 0, 1, 4, 8)
        sections += struct.pack(
            "<IIIIIIIIII", 17, 3, 0, 0, 64, len(names), 0, 0, 1, 0
        )
        elf = bytes(header) + text + relocation + names + sections
        result = replace_elf_sections(
            elf, {".text": b"ROM!"}, preserve_relocated_bytes=True
        )
        self.assertEqual(result[52:56], text)
