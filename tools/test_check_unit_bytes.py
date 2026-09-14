import unittest

from check_unit_bytes import resolve_symbol


class LinkerSymbolTests(unittest.TestCase):
    def test_sdk_names_use_reviewed_addresses(self):
        self.assertEqual(resolve_symbol("CpuSet", {"CpuSet": 0x0804A599}, {}), 0x0804A599)

    def test_generic_function_alias_preserves_instruction_set(self):
        functions = {0x08000104: "arm", 0x08018678: "thumb"}
        self.assertEqual(resolve_symbol("FUN_08000104", {}, functions), 0x08000104)
        self.assertEqual(resolve_symbol("FUN_08018678", {}, functions), 0x08018679)

    def test_data_addresses_do_not_receive_thumb_bit(self):
        self.assertEqual(resolve_symbol("gUnknown_0300019c", {}, {}), 0x0300019C)

    def test_unreviewed_function_and_unknown_name_are_rejected(self):
        for name in ["FUN_08000106", "UnknownFunction", "gUnknown_0300019c_suffix"]:
            with self.subTest(name=name), self.assertRaises(ValueError):
                resolve_symbol(name, {}, {0x08000104: "arm"})


if __name__ == "__main__":
    unittest.main()
