import unittest

from thumb_extents import (
    literal_islands,
    ROM_BASE,
    is_frame_pop,
    is_frame_push,
    is_return,
    opens_frame_before_closing,
    preceded_by_terminator,
    walk,
)


def assemble(*halfwords: int) -> bytes:
    return b"".join(value.to_bytes(2, "little") for value in halfwords)


PUSH_R4_LR = 0xB510
POP_R4 = 0xBC10
POP_R0 = 0xBC01
BX_R0 = 0x4700
BX_LR = 0x4770
MOVS_R0_0 = 0x2000
NOP = 0x0000


class InstructionClassifierTests(unittest.TestCase):
    def test_recognizes_returns(self):
        self.assertTrue(is_return(BX_LR))
        self.assertTrue(is_return(0xBD10))  # pop {r4, pc}
        self.assertFalse(is_return(MOVS_R0_0))

    def test_recognizes_frame_boundaries(self):
        self.assertTrue(is_frame_push(PUSH_R4_LR))
        self.assertTrue(is_frame_push(0xB082))  # sub sp, #8
        self.assertTrue(is_frame_pop(POP_R4))
        self.assertTrue(is_frame_pop(0xB002))  # add sp, #8
        self.assertFalse(is_frame_pop(MOVS_R0_0))


class WalkTests(unittest.TestCase):
    def test_leaf_ends_at_its_return(self):
        data = assemble(MOVS_R0_0, BX_LR, NOP, NOP)
        result = walk(data, ROM_BASE, ROM_BASE + len(data), set())
        self.assertEqual(result["end"], ROM_BASE + 4)
        self.assertTrue(result["returns"])
        self.assertTrue(result["clean"])

    def test_does_not_decode_a_literal_pool(self):
        # ldr r0, [pc, #0] loads the word at 0x08000004, which must not be walked.
        data = assemble(0x4800, BX_LR, 0x4770, 0x4770)
        result = walk(data, ROM_BASE, ROM_BASE + len(data), set())
        self.assertEqual(result["end"], ROM_BASE + 4)

    def test_stops_at_a_confirmed_entry(self):
        # A `b` forward into a confirmed entry is a tail call, not a continuation.
        data = assemble(0xE001, NOP, NOP, MOVS_R0_0, BX_LR)
        entries = {ROM_BASE + 6}
        result = walk(data, ROM_BASE, ROM_BASE + len(data), entries)
        self.assertEqual(result["end"], ROM_BASE + 2)
        self.assertFalse(result["returns"])

    def test_follows_a_conditional_branch(self):
        data = assemble(0xD001, MOVS_R0_0, BX_LR, MOVS_R0_0, BX_LR)
        result = walk(data, ROM_BASE, ROM_BASE + len(data), set())
        self.assertEqual(result["end"], ROM_BASE + 10)
        self.assertTrue(result["returns"])


class EntryPlausibilityTests(unittest.TestCase):
    def test_epilogue_fragment_is_unbalanced(self):
        data = assemble(POP_R4, POP_R0, BX_R0)
        self.assertFalse(opens_frame_before_closing(data, ROM_BASE, ROM_BASE + len(data)))

    def test_real_function_is_balanced(self):
        data = assemble(PUSH_R4_LR, MOVS_R0_0, POP_R4, POP_R0, BX_R0)
        self.assertTrue(opens_frame_before_closing(data, ROM_BASE, ROM_BASE + len(data)))

    def test_leaf_without_stack_traffic_is_balanced(self):
        data = assemble(MOVS_R0_0, BX_LR)
        self.assertTrue(opens_frame_before_closing(data, ROM_BASE, ROM_BASE + len(data)))

    def test_start_after_a_return_is_plausible(self):
        data = assemble(BX_LR, PUSH_R4_LR)
        self.assertTrue(preceded_by_terminator(data, ROM_BASE + 2, ROM_BASE + 2))

    def test_start_after_alignment_padding_is_plausible(self):
        data = assemble(NOP, PUSH_R4_LR)
        self.assertTrue(preceded_by_terminator(data, ROM_BASE + 2, ROM_BASE + 2))

    def test_start_after_a_gap_is_plausible(self):
        data = assemble(MOVS_R0_0, PUSH_R4_LR)
        self.assertTrue(preceded_by_terminator(data, ROM_BASE + 2, ROM_BASE))

    def test_start_inside_a_basic_block_is_rejected(self):
        data = assemble(MOVS_R0_0, PUSH_R4_LR)
        self.assertFalse(preceded_by_terminator(data, ROM_BASE + 2, ROM_BASE + 2))


if __name__ == "__main__":
    unittest.main()


class LiteralIslandTests(unittest.TestCase):
    """Islands are pool runs inside the body, including any alignment padding."""

    def test_finds_island_with_alignment_padding(self):
        # b +6 ; pad ; two pool words ; movs ; bx lr
        data = assemble(0xE002, NOP, 0, 0, 0, 0, MOVS_R0_0, BX_LR)
        result = walk(data, ROM_BASE, ROM_BASE + len(data), set())
        result["pool"] = {ROM_BASE + 4, ROM_BASE + 6}
        result["code"] = {ROM_BASE, ROM_BASE + 8, ROM_BASE + 10}
        self.assertEqual(
            literal_islands(result, ROM_BASE, ROM_BASE + len(data)),
            [(ROM_BASE + 2, ROM_BASE + 8)],
        )

    def test_island_without_padding_starts_at_the_pool(self):
        data = assemble(0xE001, 0, 0, MOVS_R0_0, BX_LR)
        result = {"pool": {ROM_BASE + 2, ROM_BASE + 4}, "code": {ROM_BASE, ROM_BASE + 6}}
        self.assertEqual(
            literal_islands(result, ROM_BASE, ROM_BASE + len(data)),
            [(ROM_BASE + 2, ROM_BASE + 6)],
        )

    def test_trailing_pool_is_not_an_island(self):
        # A pool run reaching the end of the body is the ordinary trailing pool.
        result = {"pool": {ROM_BASE + 4, ROM_BASE + 6}, "code": {ROM_BASE, ROM_BASE + 2}}
        self.assertEqual(literal_islands(result, ROM_BASE, ROM_BASE + 8), [])
