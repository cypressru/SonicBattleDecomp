#include "types.h"

// C++ is the reconstruction default; the retail source language is undetermined.
// C linkage preserves the project's address-based symbols, not recovered names.
extern "C" {
static u32 gUnknown_0300019c;

void FUN_08020134(u32 value) { gUnknown_0300019c = value | 1; }

u32 FUN_08020144(void) { return gUnknown_0300019c = gUnknown_0300019c * 0x0014fa05 + 0x0000c0af; }

u32 FUN_08020160(u32 threshold) {
    u32 random = gUnknown_0300019c * 0x0014fa05 + 0x0000c0af;
    u32 percent;
    u32 result;

    gUnknown_0300019c = random;
    percent = ((random & 0xFFFF) * 100) >> 16;
    result = 0;
    if (percent <= threshold) {
        result = 1;
    }
    return result;
}
}
