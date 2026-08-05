import unittest

from check_function_map import ROM_BASE, owning_extent, thumb_bl_destination


class ThumbCallDecoderTests(unittest.TestCase):
    def test_decodes_forward_bl(self):
        # Thumb-1 BL from 0x08000000 to 0x08000008.
        self.assertEqual(thumb_bl_destination(bytes.fromhex("00 f0 02 f8"), ROM_BASE), ROM_BASE + 8)

    def test_rejects_non_call(self):
        self.assertIsNone(thumb_bl_destination(bytes.fromhex("00 20 70 47"), ROM_BASE))


class OwningExtentTests(unittest.TestCase):
    """A declared long-branch target is only valid strictly inside a function body."""

    EXTENTS = {ROM_BASE: ROM_BASE + 0x40, ROM_BASE + 0x40: ROM_BASE + 0x80}

    def test_interior_address_is_owned(self):
        self.assertEqual(owning_extent(self.EXTENTS, ROM_BASE + 0x10), ROM_BASE)
        self.assertEqual(owning_extent(self.EXTENTS, ROM_BASE + 0x50), ROM_BASE + 0x40)

    def test_function_start_is_not_interior(self):
        # A start is a real entry, so it must be recorded as a function rather
        # than declared as a long-branch target.
        self.assertIsNone(owning_extent(self.EXTENTS, ROM_BASE))
        self.assertIsNone(owning_extent(self.EXTENTS, ROM_BASE + 0x40))

    def test_extent_end_is_not_interior(self):
        self.assertIsNone(owning_extent(self.EXTENTS, ROM_BASE + 0x80))

    def test_address_outside_every_extent_is_unowned(self):
        self.assertIsNone(owning_extent(self.EXTENTS, ROM_BASE + 0x100))


if __name__ == "__main__":
    unittest.main()
