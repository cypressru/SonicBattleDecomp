import unittest

from check_debug_metadata import find_debug_metadata


class DebugMetadataAuditTests(unittest.TestCase):
    def test_accepts_unrelated_library_identifier(self):
        self.assertEqual(find_debug_metadata(b"MultiSioSync4Sio32Load020820\0"), [])

    def test_finds_dwarf_marker(self):
        self.assertEqual(find_debug_metadata(b"x.debug_info\0"), [".debug_info"])

    def test_finds_source_path(self):
        self.assertEqual(find_debug_metadata(b"\0build/src/player.c\0"), ["build/src/player.c"])
