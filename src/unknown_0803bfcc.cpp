// Inferred complete results-scene TU; original source language unknown.
// C++ reconstruction fallback and synthetic linkage; see docs/results-3bfcc-tu-cpp.md.
#include "types.h"
extern "C" {
// Retail libgcc helper also defines the observed zero-denominator return (zero).
u32 __udivsi3(u32, u32);
extern const u16 *const *gUnknown_030053bc;
extern u8 gUnknown_03001620[];
extern u32 gUnknown_03005418, gUnknown_03005404, gUnknown_0300541c, gUnknown_03005408,
    gUnknown_03005410;
extern volatile u32 gUnknown_0300540c;
void FUN_08039bac(u8, u8, const u16 *, u8, u8);
void FUN_08038a84(u32, u16, u16, u8, u32), FUN_08039374(u32, u16, u16, u8, u32),
    FUN_08038f30(u32, u16, u16, u8, u32), FUN_08038e04(u32, u16, u16, u8, u32),
    FUN_08039170(u32, u16, u16, u8, u32);
void FUN_0803bfcc(u8 selection) {
    u8 labelIndex = selection;
    u16 y = 6;
    for (u16 row = 0; row <= 4; ++row) {
        FUN_08039bac(4, y, gUnknown_030053bc[labelIndex + 24], 1, 0);
        y += 16;
        ++labelIndex;
    }
    y = 6;
    switch (selection) {
    case 0: {
        u8 *state = gUnknown_03001620;
        FUN_08038a84((u16)(*(u16 *)(state + 114) / 30), 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    }
    case 1:
        FUN_08039374(gUnknown_03005418, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 2:
        FUN_08038f30(gUnknown_03001620[43], 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 3:
        FUN_08039374(gUnknown_03005404, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 4:
        FUN_08038e04(gUnknown_03001620[51], 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 5:
        FUN_08039374(gUnknown_0300541c, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 6:
        FUN_08039170(gUnknown_03005408, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 7:
        FUN_08039374(gUnknown_0300540c, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 8:

        y += 16;
        if (y > 79)
            break;
    case 9:
        if (gUnknown_03005410 & 1)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 10:
        if (gUnknown_03005410 & 2)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 11:
        if (gUnknown_03005410 & 4)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 12:
        if (gUnknown_03005410 & 8)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 13:
        if (gUnknown_03005410 & 16)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 14:
        if (gUnknown_03005410 & 32)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
        y += 16;
        if (y > 79)
            break;
    case 15:
        if (gUnknown_03005410 & 64)
            FUN_08039374(10000, 204, y, 1, 1);
        else
            FUN_08039374(0, 204, y, 1, 1);
    case 16:
        break;
    }
}
}

struct Position {
    const void *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, timer;
};
struct Node {
    void (*callback)(Node *);
    u8 field4, previous, index, next;
    Position *position;
    void *allocation;
};
extern "C" {
extern u8 gUnknown_030052e0, gUnknown_03001620[], gUnknown_03002110[];
extern u32 gUnknown_03005418;
extern u32 gUnknown_03005404;
extern u32 gUnknown_0300541c;
extern volatile u32 gUnknown_0300540c;
extern u32 gUnknown_03005408;
extern u32 gUnknown_03005414;
extern u32 gUnknown_03005410;
extern const u32 gUnknown_0807163c[];
extern const u16 gUnknown_081703d8[], gUnknown_081327d4[];
extern const u8 gUnknown_08170418[], gUnknown_081323d4[], gUnknown_08170760[], gUnknown_08170b94[],
    gUnknown_08170e10[], gUnknown_081705d8[], gUnknown_08170638[];
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *const *gUnknown_030053bc;
extern const u16 *const *const gUnknown_08edd2ec[];
extern const Position gUnknown_08edd560[5];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void), FUN_080210d8(void),
    FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8), FUN_0803bfcc(u8);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d3c(Node *), FUN_0803caa4(Node *), FUN_0801f9d8(Node *), FUN_0803cb1c(Node *),
    FUN_0803cb38(Node *), FUN_0803c9c0(Node *);
void FUN_0801fba0(u16, u16), FUN_0803c844(void), FUN_0801f618(u16);
// Partial access-width view, not a recovered retail structure declaration.
struct StateScore {
    u8 pad[98];
    u16 field98;
    u8 rest[20];
    u32 total;
};
void FUN_0803c378(void) {
    gUnknown_030052e0 = 0;
    gUnknown_03005418 = 0;
    gUnknown_03005404 = 0;
    gUnknown_0300541c = 0;
    gUnknown_0300540c = 0;
    gUnknown_03005408 = 0;
    gUnknown_03005414 = 0;
    gUnknown_03005410 = 0;
    u8 *initialState = gUnknown_03001620;
    u16 *time = (u16 *)(initialState + 114);

    if (*time <= 1800)
        gUnknown_03005410 = 1;
    if (*time <= 5399)
        gUnknown_03005418 = (180 - (u16)(*time / 30)) * 100;
    if (gUnknown_03001620[43] == 0)
        gUnknown_03005410 |= 4;
    else if (gUnknown_03001620[39] == gUnknown_03001620[43])
        gUnknown_03005410 |= 2;
    gUnknown_03005404 = gUnknown_03001620[43] * 1000;
    if (gUnknown_03001620[51] <= 9)
        gUnknown_0300541c = (10 - gUnknown_03001620[51]) * 1000;
    if (*(u16 *)(gUnknown_03001620 + 66)) {
        u32 ratio;
        if (*(u16 *)(gUnknown_03001620 + 58) == *(u16 *)(gUnknown_03001620 + 74)) {
            gUnknown_03005410 |= 16;
            ratio =
                ((u32) * (u16 *)(gUnknown_03001620 + 66) << 12) / *(u16 *)(gUnknown_03001620 + 58);
        } else {
            ratio =
                ((u32) * (u16 *)(gUnknown_03001620 + 74) << 12) / *(u16 *)(gUnknown_03001620 + 58);
        }
        register u32 ratioScale asm("r1") = 10000;

        gUnknown_0300540c = (ratio * ratioScale) >> 12;
        if (gUnknown_0300540c > 999998)
            gUnknown_0300540c = 999999;
        u32 value = gUnknown_0300540c;
        gUnknown_03005408 = value / 100;
        if (value > 9999)
            gUnknown_0300540c = 10000;
    }
    if (gUnknown_03001620[39] &&
        gUnknown_03001620[39] >= gUnknown_03001620[51] + gUnknown_03001620[52] +
                                     gUnknown_03001620[53] + gUnknown_03001620[54])
        gUnknown_03005410 |= 64;
    if (((StateScore *)gUnknown_03001620)->field98 == 0)
        gUnknown_03005410 |= 32;
    if (gUnknown_03001620[51] == 0)
        gUnknown_03005410 |= 8;
    gUnknown_03005414 =
        gUnknown_03005418 + gUnknown_03005404 + gUnknown_0300541c + gUnknown_0300540c;
    register u32 i asm("r1") = 0;
    u32 j = 0;
    // Separate the termination counter from the naturally advanced table index.
    do {
        if (gUnknown_0807163c[j] & gUnknown_03005410)
            gUnknown_03005414 += 10000;
        ++j;
    } while (++i <= 7);
    ((struct StateScore *)gUnknown_03001620)->total += gUnknown_03005414;
    FUN_0801fbfc(gUnknown_081703d8, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_08170418, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_081323d4, (void *)0x06004000);
    LZ77UnCompVram(gUnknown_08170760, (void *)0x06010000);
    s32 language = gUnknown_03002110[119];
    switch (language) {
    case 0:
        LZ77UnCompVram(gUnknown_08170b94, (void *)0x06010a00);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LZ77UnCompVram(gUnknown_08170e10, (void *)0x06010a00);
        break;
    }
    gUnknown_030053bc = gUnknown_08edd2ec[gUnknown_03002110[119]];
    u32 firstZero = 0;
    CpuFastSet(&firstZero, (void *)0x0600f800, 0x01000200);
    LZ77UnCompVram(gUnknown_081705d8, (void *)0x0600f800);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    u32 thirdZero = 0;
    CpuFastSet(&thirdZero, (void *)0x06008000, 0x01000b68);
    u16 *column = (u16 *)0x0600f104;
    u16 tile = 0x2001;
    for (u32 x = 0; x <= 25; ++x) {
        u32 y = 0;
        u16 *nextColumn = column + 1;
        u16 *row = column;
        do {
            *row = tile++;
            row += 32;
        } while (++y <= 13);
        column = nextColumn;
    }
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 26, 14, 0);
    FUN_0803bfcc(0);
    u32 fourthZero = 0;
    CpuFastSet(&fourthZero, (void *)0x0600e800, 0x01000200);
    LZ77UnCompVram(gUnknown_08170638, (void *)0x0600e800);
    u16 *destination = (u16 *)0x0600e000;
    register u32 y asm("r1") = 0;
    do {
        u32 x = 0;
        u32 nextY = y + 1;
        do {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf200);
            destination += 8;
        } while (++x <= 3);
        destination += 224;
        y = nextY;
    } while (y <= 3);
    FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0803caa4, 0, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd560[0];
    node = FUN_0801f7d0(FUN_0803cb1c, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd560[1];
    node = FUN_0801f7d0(FUN_0803cb38, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd560[2];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd560[3];
    node = FUN_0801f7d0(FUN_0803c9c0, 80, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd560[4];
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_0803c844;
    FUN_0801f618(4);
}
}

extern "C" {
extern u8 gUnknown_030052e0, gUnknown_03002110[], gUnknown_03001620[];
extern u16 gUnknown_030048e0[];
extern u32 gUnknown_03005414;
extern const u8 gUnknown_0817112c[];
extern const u16 gUnknown_08170720[], gUnknown_08132734[], gUnknown_081710bc[];
extern void (*gUnknown_03002030)(void);
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_08039c3c(void);
void FUN_0801f718(u16, u16), FUN_0801f618(u16), FUN_0803bfcc(u8), FUN_080217d0(u32);
void FUN_080336dc(void), FUN_08030f38(void), FUN_0801fed8(u8, u32);
u32 FUN_0802067c(u16 *, u16);
u8 FUN_08020500(u16 *, const u16 *, u16);
void *memcpy(void *, const void *, unsigned long);
void FUN_0803c8e8(void), FUN_0803cb54(Node *);
void FUN_0803c844(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0803c854(Node *node) {
    if (gUnknown_030048e0[2] & 1) {
        node->callback = (void (*)(Node *))FUN_0803c8e8;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    } else if (gUnknown_030048e0[4] & 64) {
        if (gUnknown_030052e0) {
            --gUnknown_030052e0;
            FUN_08039c3c();
            FUN_0803bfcc(gUnknown_030052e0);
            FUN_0801f618(401);
        }
    } else if (gUnknown_030048e0[4] & 128) {
        if (gUnknown_030052e0 <= 10) {
            ++gUnknown_030052e0;
            FUN_08039c3c();
            FUN_0803bfcc(gUnknown_030052e0);
            FUN_0801f618(401);
        }
    }
}
void FUN_0803c8e8(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        u8 *initial = gUnknown_03001620;
        u8 *iterationPointer = initial + 124;
        u32 iteration = ++*iterationPointer;
        u8 *state = initial;
        if (iteration > 4) {
            u32 changed = 0;
            register u32 rank asm("r2") = 1;
            u32 score = *(u32 *)(state + 120);
            if (score > 299999)
                rank = 4;
            else if (score > 199999)
                rank = 3;
            else if (score > 99999)
                rank = 2;
            u8 *save = gUnknown_03002110;
            u8 *difficulty = save + 118;
            asm("" : "+h"(difficulty));
            u8 *character = save + 117;
            u32 rankIndex = *character * 4;

            rankIndex += *difficulty;
            u8 *rankBase = save + 248;
            u8 *rankSlot = (u8 *)(rankIndex + (u32)rankBase);
            if (*rankSlot < rank) {
                *rankSlot = rank;
                changed = 1;
            }
            u32 characterIndex = *character;
            u32 scoreOffset = characterIndex * 3;
            register u8 *difficultyAddress asm("r2") = difficulty;
            asm("" : "+r"(difficultyAddress));
            register u32 difficultyValue asm("r2") = *difficultyAddress;
            scoreOffset = (scoreOffset + difficultyValue) << 2;
            u8 *scoreBase = save + 128;
            u32 *scoreSlot = (u32 *)(scoreOffset + (u32)scoreBase);
            u32 storedScore = *scoreSlot;
            u32 currentScore = *(u32 *)(state + 120);
            if (storedScore < currentScore) {
                *scoreSlot = currentScore;
                changed = 1;
            }
            if (changed)
                FUN_080217d0(0);
            gUnknown_03002030 = FUN_080336dc;
        } else {
            gUnknown_03002030 = FUN_08030f38;
        }
    }
}
void FUN_0803c9c0(Node *node) {
    u8 *allocation = (u8 *)node->allocation;
    memcpy(allocation + 16, gUnknown_0817112c, 56);
    u32 value = gUnknown_03005414;
    *(u16 *)(allocation + 16) = value / 1000000 * 4;
    *(u16 *)(allocation + 24) = value % 1000000 / 100000 * 4;
    *(u16 *)(allocation + 32) = value % 100000 / 10000 * 4;
    *(u16 *)(allocation + 40) = value % 10000 / 1000 * 4;
    *(u16 *)(allocation + 48) = value % 1000 / 100 * 4;
    *(u16 *)(allocation + 56) = value % 100 / 10 * 4;
    u32 lastDigit = value % 10 * 4;
    *(u16 *)(allocation + 64) = lastDigit;
    u8 index = 0;
    if (*(u16 *)(allocation + 16) == 0) {
        u32 digitOffset;
        do {
            digitOffset = index * 8;
            *(u16 *)((u32)allocation + digitOffset + 16) = 40;
            index = (u8)(index + 1);
            if (index > 5)
                break;
            digitOffset = index * 8;
        } while (*(u16 *)((u32)allocation + digitOffset + 16) == 0);
    }
    node->position->parts = allocation + 16;
    node->callback = FUN_0803cb54;
}
void FUN_0803caa4(Node *node) {
    u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_08170720, 32) == 0;
    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_08132734, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_081710bc, 48) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (!result)
        node->callback = FUN_0803c854;
}
void FUN_0803cb1c(Node *node) {
    if (gUnknown_030052e0)
        FUN_0801fed8(node->index, 0);
}
void FUN_0803cb38(Node *node) {
    if (gUnknown_030052e0 <= 10)
        FUN_0801fed8(node->index, 0);
}
void FUN_0803cb54(Node *node) { FUN_0801fed8(node->index, 0); }
}

extern "C" {
extern const u8 gUnknown_0815ac28[], gUnknown_0815ac38[], gUnknown_0817111c[];
extern const Position gUnknown_08edd560[5] = {
    {gUnknown_0815ac28, 64, 16, 80, 0, 0, 0, 0, 0, 0},
    {gUnknown_0815ac38, 120, 34, 16, 0, 0, 0, 0, 0, 0},
    {gUnknown_0815ac38, 120, 128, 20, 0, 0, 0, 0, 0, 0},
    {gUnknown_0817111c, 16, 136, 0, 0, 0, 0, 0, 0},
    {0, 220, 136, 24, 0, 0, 0, 0, 0, 0},
};
extern const u16 gUnknown_081703d8[32] __attribute__((section(".rodata.display_regs"))) = {
    0x00,   0x0000, 0x08,   0x1f00, 0x10,   0x0000, 0x12,   0x0000, 0x0a,   0x1e09, 0x14,
    0x0000, 0x16,   0x0000, 0x0c,   0x1d01, 0x18,   0x0000, 0x1a,   0x0000, 0x0e,   0x1c03,
    0x1c,   0x0000, 0x1e,   0x0000, 0x50,   0x3f41, 0x52,   0x0808, 0x54,   0x0000,
};
u32 gUnknown_03005404 __attribute__((section(".bss"), aligned(4))) = 0;
u32 gUnknown_03005408 __attribute__((section(".bss.result_5408"), aligned(4))) = 0;
volatile u32 gUnknown_0300540c __attribute__((section(".bss.result_540c"), aligned(4))) = 0;
u32 gUnknown_03005410 __attribute__((section(".bss.result_5410"), aligned(4))) = 0;
u32 gUnknown_03005414 __attribute__((section(".bss.result_5414"), aligned(4))) = 0;
u32 gUnknown_03005418 __attribute__((section(".bss.result_5418"), aligned(4))) = 0;
u32 gUnknown_0300541c __attribute__((section(".bss.result_541c"), aligned(4))) = 0;
}
