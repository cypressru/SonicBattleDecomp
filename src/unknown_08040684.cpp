// Inferred numeric helpers; C++ fallback, original source language unknown.
// Synthetic linkage and ownership/ABI evidence: docs/numeric-40684-tu-cpp.md.
#include "types.h"
// GNU integer-complex is an ABI carrier for BIOS quotient r0 / remainder r1.
// It is not evidence for a retail source type.
typedef __complex__ int DivResult;
extern "C" {
// Shared seed is written by the separate reward initializer; no BSS claimed.
extern u32 gUnknown_03005430;
extern const s16 gUnknown_081731d6[256];
DivResult FUN_0804a59c(s32 numerator, s32 denominator);

s16 FUN_08040684(u8 index) { return gUnknown_081731d6[index]; }
s16 FUN_08040698(u8 index) {
    u32 adjusted = index;
    const s16 *table = gUnknown_081731d6;
    adjusted += 64;
    u32 mask = 0xff;
    return table[adjusted & mask];
}
u32 FUN_080406b4(void) {
    gUnknown_03005430 = gUnknown_03005430 * 0x41c64e6dU + 0x3039U;
    return (gUnknown_03005430 << 1) >> 17;
}
// Width truncates to signed eight bits; output is digits 0..9 with FF padding.
// The original negative-value and zero-width paths are preserved.
s32 FUN_080406d4(s32 value, s8 *destination, s32 width) {
    s32 current = value;
    s32 adjustedWidth;
    register s8 *cursor asm("r4") = destination;
    u8 remaining;

    asm volatile("" : "+r"(cursor));
    adjustedWidth = (s8)width;

    cursor += adjustedWidth;
    adjustedWidth--;
    adjustedWidth = (s32)((u32)adjustedWidth << 24);

    remaining = (u32)adjustedWidth >> 24;
    adjustedWidth >>= 24;
    if (adjustedWidth == -1) {
        goto digits_done;
    }
    goto check_current;

digit_loop: {
    DivResult pair = FUN_0804a59c(current, 10);
    s32 quotient = __real__ pair;
    s32 remainder = __imag__ pair;
    u32 shifted;
    register u32 decrement asm("r1");

    current = quotient;
    *--cursor = remainder;
    shifted = (u32)remaining << 24;
    decrement = 0xFFu << 24;

    shifted += decrement;
    remaining = shifted >> 24;
    if ((s8)remaining == -1) {
        goto digits_done;
    }
}

check_current:
    if (current > 9) {
        goto digit_loop;
    }
    *--cursor = current;

digits_done: {
    register u32 originalShift asm("r2") = (u32)remaining << 24;
    register s32 signedRemaining asm("r0");

    signedRemaining = (s32)originalShift >> 24;
    if (signedRemaining > 0) {
        s32 minusOne;

        originalShift >>= 24;
        signedRemaining--;
        signedRemaining = (s32)((u32)signedRemaining << 24);
        remaining = (u32)signedRemaining >> 24;
        signedRemaining >>= 24;
        minusOne = -1;

        if (signedRemaining != minusOne) {
            s32 padding = minusOne;

            do {
                u32 shifted;
                register u32 decrement asm("r5");

                *--cursor = padding;
                shifted = (u32)remaining << 24;
                decrement = 0xFFu << 24;

                shifted += decrement;
                remaining = shifted >> 24;
                signedRemaining = (s32)shifted >> 24;
            } while (signedRemaining != minusOne);
        }
        signedRemaining = (s8)originalShift;
    }
    return signedRemaining;
}
}
// Q14 sine samples generated as round(16384*sin(2*pi*i/256)).
extern const s16 gUnknown_081731d6[256] = {
    0,      402,    804,    1205,   1606,   2006,   2404,   2801,   3196,   3590,   3981,   4370,
    4756,   5139,   5520,   5897,   6270,   6639,   7005,   7366,   7723,   8076,   8423,   8765,
    9102,   9434,   9760,   10080,  10394,  10702,  11003,  11297,  11585,  11866,  12140,  12406,
    12665,  12916,  13160,  13395,  13623,  13842,  14053,  14256,  14449,  14635,  14811,  14978,
    15137,  15286,  15426,  15557,  15679,  15791,  15893,  15986,  16069,  16143,  16207,  16261,
    16305,  16340,  16364,  16379,  16384,  16379,  16364,  16340,  16305,  16261,  16207,  16143,
    16069,  15986,  15893,  15791,  15679,  15557,  15426,  15286,  15137,  14978,  14811,  14635,
    14449,  14256,  14053,  13842,  13623,  13395,  13160,  12916,  12665,  12406,  12140,  11866,
    11585,  11297,  11003,  10702,  10394,  10080,  9760,   9434,   9102,   8765,   8423,   8076,
    7723,   7366,   7005,   6639,   6270,   5897,   5520,   5139,   4756,   4370,   3981,   3590,
    3196,   2801,   2404,   2006,   1606,   1205,   804,    402,    0,      -402,   -804,   -1205,
    -1606,  -2006,  -2404,  -2801,  -3196,  -3590,  -3981,  -4370,  -4756,  -5139,  -5520,  -5897,
    -6270,  -6639,  -7005,  -7366,  -7723,  -8076,  -8423,  -8765,  -9102,  -9434,  -9760,  -10080,
    -10394, -10702, -11003, -11297, -11585, -11866, -12140, -12406, -12665, -12916, -13160, -13395,
    -13623, -13842, -14053, -14256, -14449, -14635, -14811, -14978, -15137, -15286, -15426, -15557,
    -15679, -15791, -15893, -15986, -16069, -16143, -16207, -16261, -16305, -16340, -16364, -16379,
    -16384, -16379, -16364, -16340, -16305, -16261, -16207, -16143, -16069, -15986, -15893, -15791,
    -15679, -15557, -15426, -15286, -15137, -14978, -14811, -14635, -14449, -14256, -14053, -13842,
    -13623, -13395, -13160, -12916, -12665, -12406, -12140, -11866, -11585, -11297, -11003, -10702,
    -10394, -10080, -9760,  -9434,  -9102,  -8765,  -8423,  -8076,  -7723,  -7366,  -7005,  -6639,
    -6270,  -5897,  -5520,  -5139,  -4756,  -4370,  -3981,  -3590,  -3196,  -2801,  -2404,  -2006,
    -1606,  -1205,  -804,   -402,
};
// Observed trailing zero before the next scene's register metadata. It may be
// alignment or an unused closed-cycle endpoint; no retail layout is inferred.
extern const u16 gUnknown_081733d6 = 0;
}
