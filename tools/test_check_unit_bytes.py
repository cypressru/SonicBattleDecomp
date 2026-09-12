import unittest
import struct

from check_unit_bytes import owned_bss_sections, resolve_symbol, section_script, verify_bss


class BssLayoutTests(unittest.TestCase):
    def test_explicit_sections_do_not_add_trailing_bss_padding(self):
        script = section_script([{"name": ".text", "start": 0x20500}], 0x03004B00)
        self.assertIn(".text 0x8020500 : { *(.text) }", script)
        self.assertIn(".bss 0x3004b00 (NOLOAD) : { *(.bss) *(COMMON) }", script)
        self.assertNotIn("ALIGN", script)

    def test_invalid_section_name_is_rejected(self):
        with self.assertRaises(ValueError):
            section_script([{"name": ".text; injected", "start": 0}], 0)

    def fixture(self, kind=8, address=0x03004B30, size=0x20C, name=".bss"):
        elf = bytearray(52 + 120)
        elf[:7] = b"\x7fELF\x01\x01\x01"
        struct.pack_into("<I", elf, 32, 52)
        struct.pack_into("<HHH", elf, 46, 40, 3, 1)
        names = b"\0.shstrtab\0" + name.encode() + b"\0"
        struct.pack_into("<10I", elf, 92, 1, 3, 0, 0, len(elf), len(names), 0, 0, 1, 0)
        struct.pack_into("<10I", elf, 132, 11, kind, 3, address, 0, size, 0, 0, 8, 0)
        return bytes(elf) + names

    def test_exact_nobits_layout(self):
        verify_bss(self.fixture(), 0x03004B30, 0x20C)

    def test_wrong_kind_address_or_size(self):
        for kwargs in ({"kind": 1}, {"address": 0x03004B34}, {"size": 0x208}):
            with self.subTest(kwargs=kwargs), self.assertRaises(ValueError):
                verify_bss(self.fixture(**kwargs), 0x03004B30, 0x20C)

    def test_invalid_or_truncated_elf(self):
        for elf in (b"", bytes(52), self.fixture()[:100], self.fixture()[:-1]):
            with self.subTest(length=len(elf)), self.assertRaises(ValueError):
                verify_bss(elf, 0x03004B30, 0x20C)

    def test_named_nobits_layout(self):
        elf = self.fixture(name=".bss.boot_source", address=0x03004D94, size=4)
        verify_bss(elf, 0x03004D94, 4, ".bss.boot_source")
        with self.assertRaises(ValueError):
            verify_bss(elf, 0x03004D94, 4, ".bss.boot_reset")
        with self.assertRaises(ValueError):
            verify_bss(self.fixture(name=".bss.boot_source", kind=1),
                       0x03004B30, 0x20C, ".bss.boot_source")

    def test_discontiguous_sections_do_not_claim_gaps(self):
        extra = [{"name": ".bss.boot_source", "address": 0x03004D94, "size": 4}]
        unit = {"bss_address": 0x03004D40,
                "synthetic_sections": [{"name": ".bss", "size": 76}],
                "bss_sections": extra}
        self.assertEqual(owned_bss_sections(unit), [
            {"name": ".bss", "address": 0x03004D40, "size": 76}, *extra])
        script = section_script([], unit["bss_address"], extra)
        self.assertIn(".bss.boot_source 0x3004d94 (NOLOAD) : { *(.bss.boot_source) }", script)
        self.assertNotIn(". +=", script)

    def test_invalid_discontiguous_sections(self):
        unit = {"bss_address": 0x03004D40,
                "synthetic_sections": [{"name": ".bss", "size": 76}]}
        for extra in (
            {"name": ".bss", "address": 0x03004D94, "size": 4},
            {"name": ".bss.bad;", "address": 0x03004D94, "size": 4},
            {"name": ".bss.overlap", "address": 0x03004D88, "size": 8},
            {"name": ".bss.empty", "address": 0x03004D94, "size": 0},
            {"name": ".bss.rom", "address": 0x08004D94, "size": 4},
            {"name": ".bss.end", "address": 0x03007FFC, "size": 8},
        ):
            with self.subTest(extra=extra), self.assertRaises(ValueError):
                owned_bss_sections({**unit, "bss_sections": [extra]})
        with self.assertRaises(ValueError):
            owned_bss_sections({"bss_sections": [{"name": ".bss.extra"}]})
        with self.assertRaises(ValueError):
            owned_bss_sections({**unit, "bss_sections": [
                {"name": ".bss.first", "address": 0x03004D90, "size": 8},
                {"name": ".bss.second", "address": 0x03004D94, "size": 4},
            ]})
        with self.assertRaises(ValueError):
            section_script([], 0x03004D40, [{"name": ".bss.bad;", "address": 0x03004D94}])


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
