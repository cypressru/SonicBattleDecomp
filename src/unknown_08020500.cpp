#include "types.h"
// C++ fallback with synthetic linkage; original language is unknown.
// Complete TU and storage evidence: docs/palette-tu-cpp.md.
extern "C" {
static u16 gUnknown_03004b00;
// Preserve unclassified bytes between the observed state fields.
static u16 unclassified_03004b02;
static u8 gUnknown_03004b04;
static u8 unclassified_03004b05;
static u8 unclassified_03004b06;
static u8 unclassified_03004b07;
static u16 gUnknown_03004b08;
void FUN_0801fba0(u16, u16);
s32 __divsi3(s32, s32);
u8 FUN_08020500(u16 *destination, const u16 *source, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*destination & 0x7FFF) != (*source & 0x7FFF)) {
            if ((*destination & 0x1F) > (*source & 0x1F)) {
                (*destination)--;
            }
            if ((*destination & 0x1F) < (*source & 0x1F)) {
                (*destination)++;
            }
            if ((*destination & 0x3E0) > (*source & 0x3E0)) {
                *destination -= 0x20;
            }
            if ((*destination & 0x3E0) < (*source & 0x3E0)) {
                *destination += 0x20;
            }
            if ((*destination & 0x7C00) > (*source & 0x7C00)) {
                *destination -= 0x400;
            }
            if ((*destination & 0x7C00) < (*source & 0x7C00)) {
                *destination += 0x400;
            }
            result = 0;
        }
        destination++;
        source++;
        i++;
    }
    return result;
}

u32 FUN_080205d0(void) {
    switch (gUnknown_03004b04) {
    case 0:
        return 1;
    case 1:
        if (gUnknown_03004b00 & 0x8000) {
            return 1;
        }
        gUnknown_03004b00 += gUnknown_03004b08;
        if (gUnknown_03004b00 > 0x8000) {
            gUnknown_03004b00 = 0x8000;
            FUN_0801fba0(0x54, 0x10);
        } else {
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    case 2:
        if (gUnknown_03004b00 == 0) {
            return 1;
        }
        if (gUnknown_03004b00 < gUnknown_03004b08) {
            gUnknown_03004b00 = 0;
            FUN_0801fba0(0x54, 0);
        } else {
            gUnknown_03004b00 -= gUnknown_03004b08;
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    }
    return 0;
}

u32 FUN_0802067c(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if (*colors & 0x7FFF) {
            if (*colors & 0x1F) {
                (*colors)--;
            }
            if (*colors & 0x3E0) {
                *colors -= 0x20;
            }
            if (*colors & 0x7C00) {
                *colors -= 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

u32 FUN_080206ec(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*colors & 0x7FFF) != 0x7FFF) {
            if ((*colors & 0x1F) <= 0x1E) {
                (*colors)++;
            }
            if ((*colors & 0x3E0) <= 0x3DF) {
                *colors += 0x20;
            }
            if ((*colors & 0x7C00) <= 0x7BFF) {
                *colors += 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

void FUN_08020774(u16 *destination, const u16 *source, u16 count, u16 factor) {
    u16 i = 0;

    while (i < count) {
        u16 result;

        result = (((0x1FU & *source) * factor) >> 4) & 0x1F;
        result |= (((0x3E0U & *source) * factor) >> 4) & 0x3E0;
        result |= (((0x7C00U & *source) * factor) >> 4) & 0x7C00;
        *destination = result;
        destination++;
        source++;
        i++;
    }
}

void FUN_080207ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = __divsi3(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020840(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = __divsi3(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020898(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = __divsi3(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_080208ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = __divsi3(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020944(void) {
    FUN_0801fba0(0x50, 0);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 0;
    gUnknown_03004b00 = 0;
    gUnknown_03004b08 = 0;
}
}
