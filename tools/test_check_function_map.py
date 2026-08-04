import unittest

from check_function_map import ROM_BASE, thumb_bl_destination


class ThumbCallDecoderTests(unittest.TestCase):
    def test_decodes_forward_bl(self):
        # Thumb-1 BL from 0x08000000 to 0x08000008.
        self.assertEqual(thumb_bl_destination(bytes.fromhex("00 f0 02 f8"), ROM_BASE), ROM_BASE + 8)

    def test_rejects_non_call(self):
        self.assertIsNone(thumb_bl_destination(bytes.fromhex("00 20 70 47"), ROM_BASE))
