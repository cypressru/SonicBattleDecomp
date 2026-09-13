// Inferred complete list-editor TU: 0x08033D10..0x08034F28.
// C++ fallback; original language, names and declarations are unknown.
// See docs/list-editor-tu-cpp.md for ownership and verification evidence.
#include "types.h"
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
struct DrawData {
    const void *parts;
    u32 field4;
    u16 tile;
    u8 rest[10];
    s16 x, y;
};
extern "C" {
extern u32 gUnknown_03005254, gUnknown_03005258;
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern s16 gUnknown_030016f0[][8];
extern void (*gUnknown_03002030)(void);
extern Node gUnknown_03003e20[];
extern const u16 gUnknown_0814d910[], gUnknown_0814d2bc[];
extern const void *const gUnknown_08edc8a8[];
extern const u8 gUnknown_08edb93c[];
extern const Position gUnknown_08edc888, gUnknown_08edc898;
extern const u16 *gUnknown_03005324;
void FUN_0803d1a0(void), FUN_08033f68(void);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void);
void FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void FUN_0801f89c(void), FUN_0801fda0(void);
u8 FUN_0801fab0(u16), FUN_0802067c(void *, u16), FUN_08020500(void *, const u16 *, u16);
void FUN_0802036c(void *, const void *, u32), FUN_08020408(void *, const void *);
void FUN_080281c8(Node *), FUN_08028200(Node *), FUN_0801f9d8(Node *);
void FUN_080345cc(Node *), FUN_0803465c(Node *), FUN_08034f10(Node *);
void FUN_08021180(const void *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
struct Save {
    u8 prefix[0x77], language, field78, flags, rest[0x3f8], mode, count, entries[13];
};
extern Save gUnknown_03002110;
extern u8 gUnknown_03005320, gUnknown_0300531c, gUnknown_03005318;
extern s16 gUnknown_03001b10[];
extern const u16 gUnknown_0814ce1c[], gUnknown_0814d0bc[], gUnknown_08132714[], gUnknown_081327d4[];
extern const u8 gUnknown_0814d31c[], gUnknown_0814d6ac[], gUnknown_08132544[], gUnknown_08154aa0[];
extern const u8 gUnknown_0814d7f4[], gUnknown_0814d77c[], gUnknown_08071b7c[], gUnknown_0807173c[];
extern const Position gUnknown_08edc828[];
void FUN_0801fbfc(const u16 *, u8), FUN_0801fba0(u16, u16), FUN_0801f618(u16);
void *FUN_08021128(u32);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void FUN_08021000(void *, const u16 *, u32, u32, u16);
void FUN_08030d20(Node *), FUN_08034514(Node *), FUN_08034430(void), FUN_08033e60(void);
void FUN_08033d10(u8, u8, u8);

extern u8 gUnknown_03005328;
extern u16 gUnknown_030048e0[];
extern const Position gUnknown_08edc878;
extern const u32 gUnknown_0814ce5c[];
extern const u8 gUnknown_0814ce74[];
extern const u16 gUnknown_0814d044[];
extern const u16 *const gUnknown_08edc930[], *const gUnknown_08edc8d8[], *const gUnknown_08edc904[];
extern u8 gUnknown_03001620[];
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020b74(u32, u32, const u16 *, u32, u32);
void CpuSet(const void *, void *, u32);
void FUN_08027eb8(Node *), FUN_08027f38(Node *), FUN_0801f8c0(Node *);
void FUN_08034ef4(Node *), FUN_080349ac(Node *), FUN_08034d54(Node *), FUN_08034dd0(Node *);
void FUN_08034e50(Node *), FUN_08034ebc(Node *);
void FUN_0801f718(u16, u16), FUN_08029250(void), FUN_0802fdf8(void);
void FUN_0801f978(Node *, s16), FUN_0801fed8(u8, u8);
void FUN_08033d10(u8 row, u8 entry, u8 position) {
    u32 *destination = (u32 *)0x06002018 + gUnknown_0814ce5c[row];
    register u32 zero asm("r2") = 0;
    u32 y = 0;
    register u32 nextRow asm("r8") = row + 1;
    do {
        u32 x = 0;
        ++y;
        for (; x < 16; ++x)
            *destination++ = zero;
        destination += 96;
    } while (y < 18);
    if (row != 5) {
        const u16 *label = gUnknown_08edc930[position + 1];
        register u32 halfWidth asm("r2") = FUN_08020ad0(label) >> 1;
        FUN_08020b74(6 - halfWidth, gUnknown_0814ce5c[row] + 6, label, 13, 14);
    }
    if (entry) {
        switch (gUnknown_03002110.language) {
        case 0:
            FUN_08020b74(24, gUnknown_0814ce5c[row] + 6, gUnknown_08edc8d8[entry - 1], 13, 14);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            FUN_08020b74(24, gUnknown_0814ce5c[row] + 6, gUnknown_08edc904[entry - 1], 13, 14);
            break;
        }
    }
    if (gUnknown_03005324)
        CpuSet(gUnknown_0814d044 + gUnknown_0814ce74[entry] * 5,
               (u8 *)gUnknown_03005324 + (nextRow * 32 + 2), 5);
    else
        CpuSet(gUnknown_0814d044 + gUnknown_0814ce74[entry] * 5, (u8 *)0x05000002 + nextRow * 32,
               5);
}

void FUN_08033e60(void) {
    gUnknown_03001b10[4] =
        gUnknown_03002110.count | ((gUnknown_03005320 & 15) << 8) | (gUnknown_03005318 << 12);
    gUnknown_03001b10[5] =
        (gUnknown_03002110.entries[0] & 15) | ((gUnknown_03002110.entries[1] & 15) << 4) |
        ((gUnknown_03002110.entries[2] & 15) << 8) | ((gUnknown_03002110.entries[3] & 15) << 12);
    gUnknown_03001b10[6] =
        (gUnknown_03002110.entries[4] & 15) | ((gUnknown_03002110.entries[5] & 15) << 4) |
        ((gUnknown_03002110.entries[6] & 15) << 8) | ((gUnknown_03002110.entries[7] & 15) << 12);
    gUnknown_03001b10[7] =
        (gUnknown_03002110.entries[8] & 15) | ((gUnknown_03002110.entries[9] & 15) << 4) |
        ((gUnknown_03002110.entries[10] & 15) << 8) | ((gUnknown_03002110.entries[11] & 15) << 12);
}

void FUN_08033f68(void) {
    u8 entries[12];
    if (gUnknown_030016f0[0][4] != gUnknown_03001b10[4] ||
        gUnknown_030016f0[0][5] != gUnknown_03001b10[5] ||
        gUnknown_030016f0[0][6] != gUnknown_03001b10[6] ||
        gUnknown_030016f0[0][7] != gUnknown_03001b10[7]) {
        u8 position = (gUnknown_030016f0[0][4] & 0xf000) >> 12;
        u8 selection = (gUnknown_030016f0[0][4] & 0x0f00) >> 8;
        entries[0] = gUnknown_030016f0[0][5] & 15;
        entries[1] = (gUnknown_030016f0[0][5] & 0xf0) >> 4;
        entries[2] = (gUnknown_030016f0[0][5] & 0xf00) >> 8;
        entries[3] = (gUnknown_030016f0[0][5] & 0xf000) >> 12;
        entries[4] = gUnknown_030016f0[0][6] & 15;
        entries[5] = (gUnknown_030016f0[0][6] & 0xf0) >> 4;
        entries[6] = (gUnknown_030016f0[0][6] & 0xf00) >> 8;
        entries[7] = (gUnknown_030016f0[0][6] & 0xf000) >> 12;
        entries[8] = gUnknown_030016f0[0][7] & 15;
        entries[9] = (gUnknown_030016f0[0][7] & 0xf0) >> 4;
        entries[10] = (gUnknown_030016f0[0][7] & 0xf00) >> 8;
        entries[11] = (gUnknown_030016f0[0][7] & 0xf000) >> 12;
        for (u8 row = 0; row <= 4; ++row, ++position) {
            u8 *table = entries;
            FUN_08033d10(row, table[position], position);
        }
        FUN_08033d10(5, selection + 1, 0);
        const u16 *colors = gUnknown_0814d910 + selection * 64;

        FUN_0802036c((void *)0x05000300, colors, 128);
        const void *graphics = gUnknown_08edc8a8[selection];

        FUN_08020408((void *)0x06014000, graphics);
        gUnknown_03001b10[4] = gUnknown_030016f0[0][4];
        gUnknown_03001b10[5] = gUnknown_030016f0[0][5];
        gUnknown_03001b10[6] = gUnknown_030016f0[0][6];
        gUnknown_03001b10[7] = gUnknown_030016f0[0][7];
    }
}

void FUN_080340b8(void) {
    gUnknown_03005320 = 0;
    gUnknown_03002110.mode = 0;
    if (gUnknown_03002110.flags & 1)
        gUnknown_0300531c = 11;
    else
        gUnknown_0300531c = 10;
    FUN_0801fbfc(gUnknown_0814ce1c, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000000, 0x01000100);
    gUnknown_03005324 = (const u16 *)FUN_08021128(512);
    CpuFastSet(gUnknown_0814d0bc, (void *)gUnknown_03005324, 128);
    CpuFastSet(gUnknown_08132714, (void *)(gUnknown_03005324 + 240), 1);
    LZ77UnCompVram(gUnknown_0814d31c, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_0814d6ac, (void *)0x06004000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600c000);
    LZ77UnCompVram(gUnknown_08154aa0, (void *)0x06010000);
    u32 zero1 = 0;
    CpuFastSet(&zero1, (void *)0x0600f800, 0x01000200);
    u16 *tiles = (u16 *)0x0600f916;
    u16 tile = 256;
    register u32 column asm("r5") = 0;
    do {
        u16 *destination = tiles++;
        register u32 row asm("r4") = 0;
        do {
            *destination = tile;
            ++tile;
            destination += 32;
            ++row;
        } while (row < 14);
        ++column;
    } while (column < 18);
    u32 zero2 = 0;
    CpuFastSet(&zero2, (void *)0x06002000, 0x01000800);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06002000, 18, 14, 0);
    if (!gUnknown_03005254 || !gUnknown_03005260) {
        u32 position;
        if (gUnknown_03002110.count >= gUnknown_0300531c)
            position = gUnknown_0300531c - 5;
        else if (gUnknown_03002110.count > 4)
            position = gUnknown_03002110.count - 4;
        else
            position = 0;
        gUnknown_03005318 = position;
        for (u32 row = 0; row < 5; ++row, ++position)
            FUN_08033d10(row, gUnknown_03002110.entries[position], position);
        FUN_08033d10(5, (u8)(gUnknown_03005320 + 1), 0);
        u32 selection = gUnknown_03005320;
        const u16 *colors = gUnknown_0814d910 + selection * 64;

        FUN_0802036c((void *)0x05000300, colors, 128);
        const void *graphics = gUnknown_08edc8a8[selection];

        FUN_08020408((void *)0x06014000, graphics);
    }
    u32 zero3 = 0;
    CpuFastSet(&zero3, (void *)0x0600f000, 0x01000200);
    LZ77UnCompVram(gUnknown_0814d7f4, (void *)0x0600f100);
    u32 zero4 = 0;
    CpuFastSet(&zero4, (void *)0x0600e800, 0x01000200);
    LZ77UnCompVram(gUnknown_0814d77c, (void *)0x0600e800);
    u16 *background = (u16 *)0x0600e000;
    register u32 row asm("r5") = 0;
    do {
        u32 column = 0;
        ++row;
        for (; column < 4; ++column) {
            FUN_08021000(background, gUnknown_081327d4, 8, 8, 0xf200);
            background += 8;
        }
        background += 224;
    } while (row < 4);
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08034514, 8, gUnknown_03003e20, 0);
    Node *child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *child->position = gUnknown_08edc828[0];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *child->position = gUnknown_08edc828[1];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *child->position = gUnknown_08edc828[2];
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08034430;
    FUN_0801f618(4);
    gUnknown_03005258 = 0;
    gUnknown_03001b10[0] = gUnknown_03001b10[1] = gUnknown_03001b10[2] = gUnknown_03001b10[3] =
        gUnknown_03001b10[4] = gUnknown_03001b10[5] = gUnknown_03001b10[6] = gUnknown_03001b10[7] =
            0;
    if (gUnknown_03005254) {
        if (!gUnknown_03005260)
            FUN_08033e60();
        else
            gUnknown_03001b10[4] = 0xffff;
    }
}

void FUN_08034430(void) {
    if (gUnknown_03005254) {
        if (gUnknown_03005258 > 59) {
            if (FUN_0802067c((void *)0x05000000, 512)) {
                gUnknown_03002030 = FUN_0803d1a0;
                FUN_0801fb60();
                FUN_0801fb94();
                FUN_0801ff30();
                FUN_0801f780();
                FUN_080210d8();
                FUN_0802110c();
            }
            return;
        }
        if (gUnknown_0300525c == FUN_0801fab0(0x4681))
            gUnknown_03005258 = 0;
        else
            ++gUnknown_03005258;
        if (gUnknown_03005260 && !gUnknown_030016f0[0][1])
            FUN_08033f68();
    }
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_080344d8(u8 selection) {
    FUN_0802036c((void *)0x05000300, gUnknown_0814d910 + selection * 64, 128);
    FUN_08020408((void *)0x06014000, gUnknown_08edc8a8[selection]);
}

void FUN_08034514(Node *node) {
    u8 *indices = (u8 *)node->allocation;
    Node *child = FUN_0801f7d0(FUN_080281c8, 28, gUnknown_03003e20, 0);
    u32 index = child->index;

    u16 zero = 0;

    indices[0] = index;
    DrawData *data = (DrawData *)child->allocation;
    data->parts = gUnknown_08edb93c;
    data->tile = zero;
    data->x = 38;
    data->y = 52;
    child->position->attr2 = 0;
    child = FUN_0801f7d0(FUN_08028200, 28, gUnknown_03003e20, 0);
    indices[1] = child->index;
    data = (DrawData *)child->allocation;
    data->parts = gUnknown_08edb93c;
    data->tile = 16;
    data->x = 38;
    data->y = 138;
    child->position->attr2 = 0;
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    indices[2] = child->index;
    *child->position = gUnknown_08edc888;
    node->callback = FUN_080345cc;
}

void FUN_080345cc(Node *node) {
    u8 *indices = (u8 *)node->allocation;
    void *destination = (void *)0x05000000;

    const u16 **palette = &gUnknown_03005324;
    asm volatile("" : "+r"(palette));
    const u16 *colors = *palette;

    u32 initial = !FUN_08020500(destination, colors, 256);
    asm volatile("" : "+r"(initial));
    register u32 pending asm("r4") = initial;
    register u32 result asm("r5");
    if (!FUN_08020500((void *)0x05000200, gUnknown_0814d2bc, 48)) {
        result = 1;
        asm volatile("" : : "r"(result));
    } else {
        result = pending;

        if (!result) {
            Node *child = FUN_0801f7d0(FUN_08034f10, 16, gUnknown_03003e20, 0);
            indices[3] = child->index;
            *child->position = gUnknown_08edc898;
            FUN_08021180(gUnknown_03005324);
            gUnknown_03005324 = (const u16 *)result;
            node->callback = FUN_0803465c;
        }
    }
}

void FUN_0803465c(Node *node) {
    u8 *indices = (u8 *)node->allocation;
    if (!gUnknown_03005260) {
        if ((u16)(gUnknown_030048e0[4] & 64)) {
            gUnknown_03003e20[indices[0]].callback = FUN_08027eb8;
            gUnknown_03003e20[indices[0]].position->state = 0;
            if (!gUnknown_03005320)
                gUnknown_03005320 = gUnknown_0300531c - 1;
            else
                --gUnknown_03005320;
            FUN_08033d10(5, (u8)(gUnknown_03005320 + 1), 0);
            FUN_080344d8(gUnknown_03005320);
            FUN_08033e60();
            FUN_0801f618(401);
        } else if (gUnknown_030048e0[4] & 128) {
            gUnknown_03003e20[indices[1]].callback = FUN_08027f38;
            gUnknown_03003e20[indices[1]].position->state = 0;
            if (++gUnknown_03005320 >= gUnknown_0300531c)
                gUnknown_03005320 = 0;
            FUN_08033d10(5, (u8)(gUnknown_03005320 + 1), 0);
            FUN_080344d8(gUnknown_03005320);
            FUN_08033e60();
            FUN_0801f618(401);
        } else if (gUnknown_030048e0[2] & 16) {
            FUN_0801f8c0(&gUnknown_03003e20[indices[0]]);
            FUN_0801f8c0(&gUnknown_03003e20[indices[1]]);
            *gUnknown_03003e20[indices[2]].position = gUnknown_08edc878;
            gUnknown_03003e20[indices[3]].callback = FUN_08034ef4;
            node->callback = FUN_080349ac;
            gUnknown_03005328 = gUnknown_03002110.count ? gUnknown_03002110.count - 1 : 0;
            gUnknown_03005318 = gUnknown_03005328 > 3 ? gUnknown_03005328 - 4 : 0;
            if (gUnknown_03005318 > 11)
                --gUnknown_03005318;
            gUnknown_03003e20[indices[2]].position->y =
                (gUnknown_03005328 - gUnknown_03005318) * 16 + 48;
            FUN_08033d10(5, 0, 0);
            FUN_0801f618(401);
        } else if (gUnknown_030048e0[2] & 1) {
            if (gUnknown_03002110.count < gUnknown_0300531c) {
                gUnknown_03002110.entries[gUnknown_03002110.count] = gUnknown_03005320 + 1;
                u8 position;
                ++gUnknown_03002110.count;
                if (gUnknown_03002110.count >= gUnknown_0300531c)
                    position = gUnknown_0300531c - 5;
                else if (gUnknown_03002110.count > 4)
                    position = gUnknown_03002110.count - 4;
                else
                    position = 0;
                gUnknown_03005318 = position;
                for (u8 row = 0; row < 5; ++row, ++position)
                    FUN_08033d10(row, gUnknown_03002110.entries[position], position);
                FUN_08033e60();
                FUN_0801f618(402);
            } else {
                FUN_0801f618(419);
            }
        } else if (gUnknown_030048e0[2] & 2) {
            if (gUnknown_03002110.count) {
                --gUnknown_03002110.count;
                gUnknown_03002110.entries[gUnknown_03002110.count] = 0;
                u8 position;
                if (gUnknown_03002110.count >= gUnknown_0300531c)
                    position = gUnknown_0300531c - 5;
                else if (gUnknown_03002110.count > 4)
                    position = gUnknown_03002110.count - 4;
                else
                    position = 0;
                gUnknown_03005318 = position;
                for (u8 row = 0; row < 5; ++row, ++position)
                    FUN_08033d10(row, gUnknown_03002110.entries[position], position);
                FUN_08033e60();
                FUN_0801f618(403);
            } else {
                FUN_0801f618(419);
            }
        } else if (gUnknown_030048e0[2] & 0x208) {
            node->callback = FUN_08034d54;
        } else if (gUnknown_030048e0[2] & 0x100) {
            node->callback = FUN_08034dd0;
        }
    } else {
        if (gUnknown_030016f0[0][1] == 0x6789)
            node->callback = FUN_08034d54;
        if (gUnknown_030016f0[0][1] == (s16)0x8901)
            node->callback = FUN_08034dd0;
    }
}

void FUN_080349ac(Node *node) {
    u8 *indices = (u8 *)node->allocation;
    if (gUnknown_030048e0[4] & 64) {
        if (gUnknown_03005328) {
            if (--gUnknown_03005328) {
                if (gUnknown_03005328 < gUnknown_03005318 + 1)
                    gUnknown_03005318 = gUnknown_03005328 - 1;
            } else {
                gUnknown_03005318 = 0;
            }

            gUnknown_03003e20[indices[2]].position->y =
                (gUnknown_03005328 - gUnknown_03005318) * 16 + 48;
            u8 position = gUnknown_03005318;
            for (u8 row = 0; row < 5; ++row, ++position)
                FUN_08033d10(row, gUnknown_03002110.entries[position], position);
            FUN_0801f618(401);
        }
    } else if ((u16)(gUnknown_030048e0[4] & 128)) {
        if (gUnknown_03005328 + 1 < gUnknown_03002110.count) {
            ++gUnknown_03005328;
            if (gUnknown_03005328 >= gUnknown_0300531c - 1)
                gUnknown_03005318 = gUnknown_0300531c - 5;
            else if (gUnknown_03005328 > gUnknown_03005318 + 3)
                gUnknown_03005318 = gUnknown_03005328 - 3;

            gUnknown_03003e20[indices[2]].position->y =
                (gUnknown_03005328 - gUnknown_03005318) * 16 + 48;
            u8 position = gUnknown_03005318;
            for (u8 row = 0; row < 5; ++row, ++position)
                FUN_08033d10(row, gUnknown_03002110.entries[position], position);
            FUN_0801f618(401);
        }
    } else if (gUnknown_030048e0[2] & 32) {
        Node *child = FUN_0801f7d0(FUN_080281c8, 28, gUnknown_03003e20, 0);
        indices[0] = child->index;
        DrawData *data = (DrawData *)child->allocation;
        data->parts = gUnknown_08edb93c;
        data->tile = 0;
        data->x = 38;
        data->y = 52;
        child->position->attr2 = 0;
        child = FUN_0801f7d0(FUN_08028200, 28, gUnknown_03003e20, 0);
        indices[1] = child->index;
        data = (DrawData *)child->allocation;
        data->parts = gUnknown_08edb93c;
        data->tile = 16;
        data->x = 38;
        data->y = 138;
        child->position->attr2 = 0;
        *gUnknown_03003e20[indices[2]].position = gUnknown_08edc888;
        gUnknown_03003e20[indices[3]].callback = FUN_08034f10;
        node->callback = FUN_0803465c;
        u8 position;
        if (gUnknown_03002110.count >= gUnknown_0300531c)
            position = gUnknown_0300531c - 5;
        else if (gUnknown_03002110.count > 4)
            position = gUnknown_03002110.count - 4;
        else
            position = 0;
        for (u8 row = 0; row < 5; ++row, ++position)
            FUN_08033d10(row, gUnknown_03002110.entries[position], position);
        FUN_08033d10(5, (u8)(gUnknown_03005320 + 1), 0);
        FUN_0801f618(401);
    } else if (gUnknown_030048e0[2] & 3) {
        if (gUnknown_03002110.count) {
            --gUnknown_03002110.count;
            register u32 initialIndex asm("r5") = gUnknown_03005328;
            asm volatile("" : : "r"(initialIndex));
            for (u8 i = initialIndex; i <= gUnknown_0300531c; ++i)
                gUnknown_03002110.entries[i] = gUnknown_03002110.entries[i + 1];
            if (!gUnknown_03002110.entries[gUnknown_03005328] && gUnknown_03005328)
                --gUnknown_03005328;
            if (gUnknown_03002110.count <= 4)
                gUnknown_03005318 = 0;
            else if (gUnknown_03002110.count <= gUnknown_03005318 + 4)
                gUnknown_03005318 = gUnknown_03002110.count - 4;

            gUnknown_03003e20[indices[2]].position->y =
                (gUnknown_03005328 - gUnknown_03005318) * 16 + 48;
            u8 position = gUnknown_03005318;
            for (u8 row = 0; row < 5; ++row, ++position)
                FUN_08033d10(row, gUnknown_03002110.entries[position], position);
            FUN_08033e60();
            FUN_0801f618(403);
        } else {
            FUN_0801f618(419);
        }
    } else if (gUnknown_030048e0[2] & 0x208) {
        node->callback = FUN_08034d54;
    } else if (gUnknown_030048e0[2] & 0x100) {
        node->callback = FUN_08034dd0;
    }
}

void FUN_08034d54(Node *node) {
    gUnknown_03001b10[1] = 0x6789;
    gUnknown_03001b10[2] = gUnknown_03001b10[3] = gUnknown_03001b10[4] = gUnknown_03001b10[5] =
        gUnknown_03001b10[6] = gUnknown_03001b10[7] = 0;
    u32 ready = 1;
    for (u32 i = 0; i < gUnknown_0300525c; ++i) {
        if (i != gUnknown_03005260 && gUnknown_030016f0[i][1] != 0x6789)
            ready = 0;
    }
    if (ready) {
        node->callback = FUN_08034e50;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    }
}

void FUN_08034dd0(Node *node) {
    gUnknown_03001b10[1] = 0x8901;
    gUnknown_03001b10[2] = gUnknown_03001b10[3] = gUnknown_03001b10[4] = gUnknown_03001b10[5] =
        gUnknown_03001b10[6] = gUnknown_03001b10[7] = 0;
    u32 ready = 1;
    for (u32 i = 0; i < gUnknown_0300525c; ++i) {
        if (i != gUnknown_03005260 && gUnknown_030016f0[i][1] != (s16)0x8901)
            ready = 0;
    }
    if (ready) {
        node->callback = FUN_08034ebc;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    }
}

void FUN_08034e50(Node *) {
    if (FUN_0802067c((void *)0x05000000, 512)) {
        gUnknown_03001620[1] = 0;
        gUnknown_03001620[2] = gUnknown_03002110.count;
        for (u8 i = 0; i < gUnknown_03002110.count; ++i)
            (gUnknown_03001620 + 3)[i] = gUnknown_03002110.entries[i] - 1;
        gUnknown_03002030 = FUN_08029250;
    }
}

void FUN_08034ebc(Node *) {
    if (FUN_0802067c((void *)0x05000000, 512)) {
        gUnknown_03002110.mode = 0;
        gUnknown_03002030 = FUN_0802fdf8;
    }
}

void FUN_08034ef4(Node *node) {
    FUN_0801f978(node, -48);
    FUN_0801fed8(node->index, 0);
}

void FUN_08034f10(Node *node) {
    FUN_0801f978(node, 48);
    FUN_0801fed8(node->index, 0);
}
extern const u8 gUnknown_0814df10[];
extern const u8 gUnknown_0814e9e0[];
extern const u8 gUnknown_0814f1f8[];
extern const u8 gUnknown_0814fca0[];
extern const u8 gUnknown_081506d0[];
extern const u8 gUnknown_0815106c[];
extern const u8 gUnknown_08151948[];
extern const u8 gUnknown_0815226c[];
extern const u8 gUnknown_08152bf0[];
extern const u8 gUnknown_08153638[];
extern const u8 gUnknown_08153ee4[];
extern const u8 gUnknown_081541c8[];
extern const u8 gUnknown_081550dc[];
extern const u8 gUnknown_081550e4[];
extern const u8 gUnknown_081550ec[];
extern const u8 gUnknown_081550f4[];
extern const u8 gUnknown_081550fc[];
extern const u16 gUnknown_08155114[];
extern const u16 gUnknown_08155128[];
extern const u16 gUnknown_08155138[];
extern const u16 gUnknown_08155148[];
extern const u16 gUnknown_0815515c[];
extern const u16 gUnknown_0815516c[];
extern const u16 gUnknown_0815517c[];
extern const u16 gUnknown_0815518c[];
extern const u16 gUnknown_08155198[];
extern const u16 gUnknown_081551ac[];
extern const u16 gUnknown_081551b8[];
extern const u16 gUnknown_081551c8[];
extern const u16 gUnknown_081551e4[];
extern const u16 gUnknown_081551fc[];
extern const u16 gUnknown_08155214[];
extern const u16 gUnknown_08155234[];
extern const u16 gUnknown_0815524c[];
extern const u16 gUnknown_08155264[];
extern const u16 gUnknown_08155274[];
extern const u16 gUnknown_0815528c[];
extern const u16 gUnknown_081552a4[];
extern const u16 gUnknown_081552b8[];
extern const u16 gUnknown_081552d0[];
extern const u16 gUnknown_081552d4[];
extern const u16 gUnknown_081552d8[];
extern const u16 gUnknown_081552dc[];
extern const u16 gUnknown_081552e0[];
extern const u16 gUnknown_081552e4[];
extern const u16 gUnknown_081552e8[];
extern const u16 gUnknown_081552ec[];
extern const u16 gUnknown_081552f0[];
extern const u16 gUnknown_081552f4[];
extern const u16 gUnknown_081552f8[];
extern const u16 gUnknown_08155300[];
extern const u16 gUnknown_08155308[];
extern const u16 gUnknown_08155310[];
extern const u16 gUnknown_08155318[];
extern const u16 gUnknown_08155320[];
extern const u16 gUnknown_08155328[];
extern const u16 gUnknown_08155330[];
extern const u16 gUnknown_08155338[];
extern const u16 gUnknown_08155340[];
extern const Position gUnknown_08edc828[] = {
    {gUnknown_081550e4, 120, 16, 32, 0, 0, 0, 0, 0, 0},
    {gUnknown_081550dc, 32, 16, 64, 0, 0, 16, 0, 0, 0},
    {gUnknown_081550dc, 208, 16, 96, 0, 0, 16, 0, 0, 0},
};
extern const Position gUnknown_08edc858[] = {
    {gUnknown_081550ec, 38, 52, 0, 0, 0, 0, 0, 0, 0},
    {gUnknown_081550ec, 38, 138, 16, 0, 0, 0, 0, 0, 0},
};
extern const Position gUnknown_08edc878 = {gUnknown_081550f4, 82, 80, 128, 0, 0, 0, 0, 0, 0};
extern const Position gUnknown_08edc888 = {gUnknown_081550f4, 160, 126, 132, 0, 0, 0, 0, 0, 0};
extern const Position gUnknown_08edc898 = {gUnknown_081550fc, -52, 95, 512, 32, 0, 0, 0, 0, 0};
extern const void *const gUnknown_08edc8a8[] = {
    gUnknown_0814df10, gUnknown_0814e9e0, gUnknown_0814f1f8, gUnknown_0814fca0,
    gUnknown_081506d0, gUnknown_0815106c, gUnknown_08151948, gUnknown_0815226c,
    gUnknown_08152bf0, gUnknown_08153638, gUnknown_081541c8, gUnknown_08153ee4,
};
extern const u16 *const gUnknown_08edc8d8[] = {
    gUnknown_08155114, gUnknown_08155128, gUnknown_08155138, gUnknown_08155148,
    gUnknown_0815515c, gUnknown_0815516c, gUnknown_0815517c, gUnknown_0815518c,
    gUnknown_08155198, gUnknown_081551ac, gUnknown_081551b8,
};
extern const u16 *const gUnknown_08edc904[] = {
    gUnknown_081551c8, gUnknown_081551e4, gUnknown_081551fc, gUnknown_08155214,
    gUnknown_08155234, gUnknown_0815524c, gUnknown_08155264, gUnknown_08155274,
    gUnknown_0815528c, gUnknown_081552a4, gUnknown_081552b8,
};
extern const u16 *const gUnknown_08edc930[] = {
    gUnknown_081552d0, gUnknown_081552d4, gUnknown_081552d8, gUnknown_081552dc, gUnknown_081552e0,
    gUnknown_081552e4, gUnknown_081552e8, gUnknown_081552ec, gUnknown_081552f0, gUnknown_081552f4,
    gUnknown_081552f8, gUnknown_08155300, gUnknown_08155308, gUnknown_08155310, gUnknown_08155318,
    gUnknown_08155320, gUnknown_08155328, gUnknown_08155330, gUnknown_08155338, gUnknown_08155340,
};
extern const u16 gUnknown_0814ce1c[] __attribute__((section(".rodata.registers"))) = {
    0x0,  0x0,  0x8,  0x1f00, 0x10,   0x0,    0x12, 0x0,   0xa,  0x1e80, 0x14,
    0x0,  0x16, 0x0,  0xc,    0x1d07, 0x18,   0x0,  0x1a,  0x0,  0xe,    0x1c0b,
    0x1c, 0x0,  0x1e, 0x0,    0x50,   0x3f44, 0x52, 0x808, 0x54, 0x0};
extern const u32 gUnknown_0814ce5c[]
    __attribute__((section(".rodata.registers"))) = {0x0, 0x10, 0x20, 0x30, 0x40, 0x58};
extern const u8 gUnknown_0814ce74[] __attribute__((section(".rodata.registers"))) = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb};
u8 gUnknown_03005318 __attribute__((section(".bss"))) = 0;
u8 gUnknown_0300531c __attribute__((section(".bss.limit"))) = 0;
u8 gUnknown_03005320 __attribute__((section(".bss.selection"))) = 0;
const u16 *gUnknown_03005324 __attribute__((section(".bss.palette"))) = 0;
u8 gUnknown_03005328 __attribute__((section(".bss.cursor"))) = 0;
}
