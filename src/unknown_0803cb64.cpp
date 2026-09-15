// C++ reconstruction fallback; original language and symbol names are unknown.
// Full-TU ownership and constraint evidence: docs/scene-3cb64-tu-cpp.md.
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
extern "C" {
extern u8 gUnknown_03002110[];
extern const u8 gUnknown_0811e230[], gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *const *gUnknown_03005420, *const *gUnknown_030053bc;
extern const u16 *const *const gUnknown_08edd2ec[];
extern const u16 *const gUnknown_08edd5b0[],
    *const gUnknown_08edd5d0[], *const gUnknown_08edd5f0[], *const gUnknown_08edd610[],
                                                                *const gUnknown_08edd630[],
                                                                    *const gUnknown_08edd650[];
extern const u16 *const gUnknown_08edd4f0[],
    *const gUnknown_08edd518[], *const gUnknown_08edd670[], *const gUnknown_08edd73c[];
extern const u16 gUnknown_08171164[], gUnknown_08171bd8[], gUnknown_08171b48[], gUnknown_081327d4[];
extern const u8 gUnknown_081711e4[], gUnknown_081323d4[], gUnknown_08171b04[], gUnknown_08171a34[],
    gUnknown_0817194c[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0802cc78(void), FUN_0803cf9c(void), FUN_08030d3c(Node *), FUN_0803d168(Node *);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void),
    FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020b74(u32, u32, const u16 *, u32, u32);
void FUN_08038c74(u32, u16, u16, u8, u32);
void FUN_08039bac(u8, u8, const u16 *, u8, u8);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_0801fba0(u16, u16), FUN_0801f618(u32);
void FUN_0803cb64(void) {
    if (!gUnknown_03002110[1160]) {
        gUnknown_03002030 = FUN_0802cc78;
        return;
    }
    switch (gUnknown_03002110[119]) {
    case 0:
        gUnknown_03005420 = gUnknown_08edd5b0;
        break;
    case 2:
        gUnknown_03005420 = gUnknown_08edd5f0;
        break;
    case 3:
        gUnknown_03005420 = gUnknown_08edd610;
        break;
    case 4:
        gUnknown_03005420 = gUnknown_08edd630;
        break;
    case 5:
        gUnknown_03005420 = gUnknown_08edd650;
        break;
    default:
        gUnknown_03005420 = gUnknown_08edd5d0;
        break;
    }
    gUnknown_030053bc = gUnknown_08edd2ec[gUnknown_03002110[119]];
    FUN_0801fbfc(gUnknown_08171164, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_081711e4, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_081323d4, (void *)0x0600c000);
    LZ77UnCompVram(gUnknown_08171b04, (void *)0x06010000);
    u32 firstZero = 0;
    CpuFastSet(&firstZero, (void *)0x0600f800, 0x01000200);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    LZ77UnCompVram(gUnknown_08171a34, (void *)0x0600f000);
    FUN_08021000((u16 *)0x0600f304, gUnknown_08171bd8, 26, 6, 0x111);
    u32 thirdZero = 0;
    CpuFastSet(&thirdZero, (void *)0x0600e800, 0x01000200);
    LZ77UnCompVram(gUnknown_0817194c, (void *)0x0600e800);
    FUN_08021000((u16 *)0x0600e8c4, gUnknown_08171b48, 18, 4, 45);
    FUN_08021000((u16 *)0x0600eb04, gUnknown_08171bd8, 26, 6, 117);
    u16 *destination = (u16 *)0x0600e000;
    for (u32 y = 0; y <= 3; ++y) {
        for (u32 x = 0; x <= 3; ++x) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf200);
            destination += 8;
        }
        destination += 224;
    }
    register const u8 *characterMap = gUnknown_0811e230;
    register u8 *save = gUnknown_03002110;
    register u8 *savedCharacter = save + 1161;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06000598, 18, 4, 0);
    FUN_08020b74(16, 0, gUnknown_03005420[0], 15, 0);
    FUN_08020b74(16, 16, gUnknown_03005420[1], 15, 0);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06000e98, 26, 6, 0);
    FUN_08020b74(8, 0, gUnknown_03005420[2], 15, 0);
    FUN_08020b74(8, 16, gUnknown_03005420[3], 15, 0);
    FUN_08038c74(*(u32 *)(save + 1164) / 60, 200, 16, 15, 1);
    register s32 language = save[119];

    if (language == 0) {
        register const u16 *const *nameTable = gUnknown_08edd518;

        register u8 *characterSlot = savedCharacter;

        FUN_08039bac(200, 0, nameTable[characterMap[*characterSlot]], 15, 1);
        register u8 *location = save + 1163;
        if (*location != 255) {
            FUN_08020b74(8, 32, gUnknown_03005420[4], 15, 0);
            FUN_08039bac(200, 32, gUnknown_08edd73c[*location], 15, 1);
        }
    } else {
        if (language < 0)
            goto detailsDone;

        if (language > 5)
            goto detailsDone;
        register const u16 *const *nameTable = gUnknown_08edd4f0;

        register u8 *characterSlot = savedCharacter;

        FUN_08039bac(200, 0, nameTable[characterMap[*characterSlot]], 15, 1);
        register u8 *location = save + 1163;
        if (*location != 255) {
            FUN_08020b74(8, 32, gUnknown_03005420[4], 15, 0);
            FUN_08039bac(200, 32, gUnknown_08edd670[*location], 15, 1);
        }
    }
detailsDone:
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06002218, 26, 6, 0);
    FUN_08020b74(8, 0, gUnknown_03005420[5], 15, 0);
    FUN_08020b74(8, 16, gUnknown_03005420[6], 15, 0);
    FUN_08020b74(8, 32, gUnknown_03005420[7], 15, 0);
    FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0803d168, 20, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_0803cf9c;
    FUN_0801f618(4);
}
}

struct Controller {
    u8 prefix[16];
    u16 selection, blend;
};
extern "C" {
extern u16 gUnknown_030048e0[];
extern const u16 gUnknown_081711a4[], gUnknown_08132754[], gUnknown_081711c4[];
extern const u8 gUnknown_08171d10[];
extern void (*gUnknown_03002030)(void);
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_08039e20(void), FUN_0802cc78(void),
    FUN_0803fb2c(void);
void FUN_0801f718(u32, u32), FUN_0801f618(u32), FUN_0801fed8(u8, u32), FUN_0801fba0(u16, u16);
s32 FUN_0801f914(s32, s32);
u8 FUN_08020500(u16 *, const u16 *, u16);
u32 FUN_0802067c(u16 *, u16);
void FUN_0803d034(Node *), FUN_0803d100(Node *), FUN_0803d128(Node *);
void FUN_0803cf9c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0803cfac(Node *node) {
    Controller *controller = (Controller *)node->allocation;
    u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_081711a4, 16) == 0;
    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_08132754, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_081711c4, 16) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (!result) {
        controller->selection = result;
        controller->blend = result;
        node->callback = FUN_0803d034;
    }
    FUN_0801fed8(node->index, 0);
}
void FUN_0803d034(Node *node) {
    Controller *controller = (Controller *)node->allocation;
    register u16 pressed asm("r1") = gUnknown_030048e0[2];
    if (pressed & 1) {
        node->callback = FUN_0803d128;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    } else if (pressed & 2) {
        node->callback = FUN_0803d100;
        FUN_0801f718(4, 120);
        FUN_0801f618(403);
    } else if (pressed & 192) {
        controller->selection ^= 1;
        FUN_0801f618(401);
    }
    if (controller->selection) {
        if (++controller->blend > 15)
            controller->blend = 16;
        node->position->y = FUN_0801f914(40, node->position->y);
    } else {
        if (controller->blend)
            --controller->blend;
        node->position->y = FUN_0801f914(24, node->position->y);
    }
    u32 blend = controller->blend;
    FUN_0801fba0(82, ((16 - blend) << 8) | blend);
    FUN_0801fed8(node->index, 0);
}
void FUN_0803d100(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512))
        gUnknown_03002030 = FUN_08039e20;
}
void FUN_0803d128(Node *node) {
    Controller *controller = (Controller *)node->allocation;
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        if (controller->selection)
            gUnknown_03002030 = FUN_0802cc78;
        else
            gUnknown_03002030 = FUN_0803fb2c;
    }
}
void FUN_0803d168(Node *node) {
    node->position->parts = gUnknown_08171d10;
    node->position->x = 14;
    node->position->y = 24;
    node->position->tile = 0;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0803cfac;
}
}

extern "C" {
extern const u16 gUnknown_08171d18[];
extern const u16 gUnknown_08171d2c[];
extern const u16 gUnknown_08171d48[];
extern const u16 gUnknown_08171d54[];
extern const u16 gUnknown_08171d60[];
extern const u16 gUnknown_08171d6c[];
extern const u16 gUnknown_08171d94[];
extern const u16 gUnknown_08171dbc[];
extern const u16 gUnknown_08171de4[];
extern const u16 gUnknown_08171e08[];
extern const u16 gUnknown_08171e38[];
extern const u16 gUnknown_08171e48[];
extern const u16 gUnknown_08171e64[];
extern const u16 gUnknown_08171e84[];
extern const u16 gUnknown_08171eb4[];
extern const u16 gUnknown_08171ee8[];
extern const u16 gUnknown_08171f18[];
extern const u16 gUnknown_08171f40[];
extern const u16 gUnknown_08171f74[];
extern const u16 gUnknown_08171f84[];
extern const u16 gUnknown_08171fa0[];
extern const u16 gUnknown_08171fc0[];
extern const u16 gUnknown_08171ff4[];
extern const u16 gUnknown_08172020[];
extern const u16 gUnknown_08172050[];
extern const u16 gUnknown_08172074[];
extern const u16 gUnknown_081720a4[];
extern const u16 gUnknown_081720b4[];
extern const u16 gUnknown_081720c8[];
extern const u16 gUnknown_081720e0[];
extern const u16 gUnknown_08172114[];
extern const u16 gUnknown_08172144[];
extern const u16 gUnknown_0817217c[];
extern const u16 gUnknown_081721a4[];
extern const u16 gUnknown_081721d0[];
extern const u16 gUnknown_081721e4[];
extern const u16 gUnknown_08172204[];
extern const u16 gUnknown_08172224[];
extern const u16 gUnknown_08172254[];
extern const u16 gUnknown_08172284[];
extern const u16 gUnknown_081722bc[];
extern const u16 gUnknown_081722e4[];
extern const u16 gUnknown_08172314[];
extern const u16 gUnknown_08172328[];
extern const u16 gUnknown_08172348[];
extern const u16 gUnknown_08172368[];
extern const u16 gUnknown_08172398[];
extern const u16 gUnknown_081723c4[];
extern const u16 gUnknown_081723f4[];
extern const u16 gUnknown_08172410[];
extern const u16 gUnknown_08172418[];
extern const u16 gUnknown_08172434[];
extern const u16 gUnknown_08172450[];
extern const u16 gUnknown_0817246c[];
extern const u16 gUnknown_08172480[];
extern const u16 gUnknown_08172494[];
extern const u16 gUnknown_081724a0[];
extern const u16 gUnknown_081724b4[];
extern const u16 gUnknown_081724c0[];
extern const u16 gUnknown_081724cc[];
extern const u16 gUnknown_081724d8[];
extern const u16 gUnknown_081724f4[];
extern const u16 gUnknown_08172514[];
extern const u16 gUnknown_0817251c[];
extern const u16 gUnknown_0817252c[];
extern const u16 gUnknown_08172538[];
extern const u16 gUnknown_08172544[];
extern const u16 gUnknown_08172554[];
extern const u16 gUnknown_08172564[];
extern const u16 gUnknown_0817256c[];
extern const u16 gUnknown_08172584[];
extern const u16 gUnknown_08172590[];
extern const u16 gUnknown_081725a0[];
extern const u16 gUnknown_081725a8[];
extern const u16 gUnknown_081725b8[];
extern const u16 gUnknown_081725cc[];
extern const u16 gUnknown_081725e0[];
extern const u16 gUnknown_081725f8[];
extern const u16 gUnknown_08172600[];
extern const u16 gUnknown_08172614[];
extern const u16 gUnknown_08172620[];
extern const u16 gUnknown_08172628[];
extern const u16 gUnknown_08172630[];
extern const u16 gUnknown_0817263c[];
extern const u16 gUnknown_08172650[];
extern const u16 gUnknown_08172668[];
extern const u16 gUnknown_08172680[];
extern const u16 gUnknown_08172688[];
extern const u16 gUnknown_08172690[];
extern const u16 gUnknown_081726a0[];
extern const u16 gUnknown_081726b4[];
extern const u16 gUnknown_081726c8[];
extern const u16 gUnknown_081726d8[];
extern const u16 gUnknown_081726e8[];
extern const u16 gUnknown_081726f0[];
extern const u16 gUnknown_081726f8[];
extern const u16 gUnknown_08172714[];
extern const u16 gUnknown_0817272c[];
extern const u16 gUnknown_08172748[];
extern const u16 gUnknown_0817275c[];
extern const u16 gUnknown_08172770[];
extern const u16 gUnknown_08172780[];
extern const u16 gUnknown_08172798[];
extern const u16 gUnknown_081727ac[];
extern const u16 gUnknown_081727c0[];
extern const u16 gUnknown_081727d0[];
extern const u16 gUnknown_081727e0[];
extern const u16 gUnknown_081727f0[];
extern const u16 gUnknown_081727fc[];
extern const u16 gUnknown_08172804[];
extern const u16 gUnknown_0817280c[];
extern const u16 gUnknown_08172814[];
extern const u16 gUnknown_08172828[];
extern const u16 gUnknown_0817283c[];
extern const u16 gUnknown_08172848[];
extern const u16 gUnknown_08172854[];
extern const u16 gUnknown_08172860[];
extern const u16 gUnknown_08172868[];
extern const u16 gUnknown_08172870[];
extern const u16 gUnknown_0817287c[];
extern const u16 gUnknown_08172884[];
extern const u16 gUnknown_08172894[];
extern const u16 gUnknown_0817289c[];
extern const u16 gUnknown_081728a8[];
extern const u16 gUnknown_081728b4[];
extern const u16 gUnknown_081728bc[];
extern const u16 gUnknown_081728c8[];
extern const u16 gUnknown_081728d8[];
extern const u16 gUnknown_081728e8[];
extern const u16 gUnknown_081728f8[];
extern const u16 gUnknown_08172910[];
extern const u16 gUnknown_08172918[];
extern const u16 gUnknown_08172924[];
extern const u16 gUnknown_08172930[];
extern const u16 gUnknown_08172938[];
extern const u16 gUnknown_08172948[];
extern const u16 gUnknown_08172958[];
extern const u16 gUnknown_08172968[];
extern const u16 gUnknown_08172980[];
extern const u16 gUnknown_0817298c[];
extern const u16 gUnknown_081729a4[];
extern const u16 gUnknown_081729b0[];
extern const u16 gUnknown_081729c0[];
extern const u16 gUnknown_081729cc[];
extern const u16 gUnknown_081729d8[];
extern const u16 gUnknown_081729e8[];
extern const u16 gUnknown_081729f8[];
extern const u16 gUnknown_08172a08[];
extern const u16 gUnknown_08172a18[];
extern const u16 gUnknown_08172a2c[];
extern const u16 *const gUnknown_08edd5b0[8] = {
    gUnknown_08171d18, gUnknown_08171d2c, gUnknown_08171d48, gUnknown_08171d54,
    gUnknown_08171d60, gUnknown_08171d6c, gUnknown_08171d94, gUnknown_08171dbc,
};
extern const u16 *const gUnknown_08edd5d0[8] = {
    gUnknown_08171de4, gUnknown_08171e08, gUnknown_08171e38, gUnknown_08171e48,
    gUnknown_08171e64, gUnknown_08171e84, gUnknown_08171eb4, gUnknown_08171ee8,
};
extern const u16 *const gUnknown_08edd5f0[8] = {
    gUnknown_08171f18, gUnknown_08171f40, gUnknown_08171f74, gUnknown_08171f84,
    gUnknown_08171fa0, gUnknown_08171fc0, gUnknown_08171ff4, gUnknown_08172020,
};
extern const u16 *const gUnknown_08edd610[8] = {
    gUnknown_08172050, gUnknown_08172074, gUnknown_081720a4, gUnknown_081720b4,
    gUnknown_081720c8, gUnknown_081720e0, gUnknown_08172114, gUnknown_08172144,
};
extern const u16 *const gUnknown_08edd630[8] = {
    gUnknown_0817217c, gUnknown_081721a4, gUnknown_081721d0, gUnknown_081721e4,
    gUnknown_08172204, gUnknown_08172224, gUnknown_08172254, gUnknown_08172284,
};
extern const u16 *const gUnknown_08edd650[8] = {
    gUnknown_081722bc, gUnknown_081722e4, gUnknown_08172314, gUnknown_08172328,
    gUnknown_08172348, gUnknown_08172368, gUnknown_08172398, gUnknown_081723c4,
};
extern const u16 *const gUnknown_08edd670[51] = {
    gUnknown_081723f4, gUnknown_08172410, gUnknown_08172418, gUnknown_08172434, gUnknown_08172450,
    gUnknown_0817246c, gUnknown_08172480, gUnknown_08172494, gUnknown_081724a0, gUnknown_081724b4,
    gUnknown_081724c0, gUnknown_081724cc, gUnknown_081724d8, gUnknown_081724f4, gUnknown_08172514,
    gUnknown_0817251c, gUnknown_0817252c, gUnknown_08172538, gUnknown_08172544, gUnknown_08172554,
    gUnknown_08172564, gUnknown_0817256c, gUnknown_08172584, gUnknown_08172590, gUnknown_081725a0,
    gUnknown_081725a8, gUnknown_081725b8, gUnknown_081725cc, gUnknown_081725e0, gUnknown_081725f8,
    gUnknown_08172600, gUnknown_08172614, gUnknown_08172620, gUnknown_08172628, gUnknown_08172630,
    gUnknown_0817263c, gUnknown_08172650, gUnknown_08172668, gUnknown_08172680, gUnknown_08172688,
    gUnknown_08172690, gUnknown_081726a0, gUnknown_081726b4, gUnknown_081726c8, gUnknown_081726d8,
    gUnknown_081726e8, gUnknown_081726f0, gUnknown_081726f8, gUnknown_08172714, gUnknown_0817272c,
    gUnknown_08172748,
};
extern const u16 *const gUnknown_08edd73c[51] = {
    gUnknown_0817275c, gUnknown_08172770, gUnknown_08172780, gUnknown_08172798, gUnknown_081727ac,
    gUnknown_081727c0, gUnknown_081727d0, gUnknown_081727e0, gUnknown_081727f0, gUnknown_081727fc,
    gUnknown_08172804, gUnknown_0817280c, gUnknown_08172814, gUnknown_08172828, gUnknown_0817283c,
    gUnknown_08172848, gUnknown_08172854, gUnknown_08172860, gUnknown_08172868, gUnknown_08172870,
    gUnknown_0817287c, gUnknown_08172884, gUnknown_08172894, gUnknown_0817289c, gUnknown_081728a8,
    gUnknown_081728b4, gUnknown_081728bc, gUnknown_081728c8, gUnknown_081728d8, gUnknown_081728e8,
    gUnknown_081728f8, gUnknown_08172910, gUnknown_08172918, gUnknown_08172924, gUnknown_08172930,
    gUnknown_08172938, gUnknown_08172948, gUnknown_08172958, gUnknown_08172968, gUnknown_08172980,
    gUnknown_0817298c, gUnknown_081729a4, gUnknown_081729b0, gUnknown_081729c0, gUnknown_081729cc,
    gUnknown_081729d8, gUnknown_081729e8, gUnknown_081729f8, gUnknown_08172a08, gUnknown_08172a18,
    gUnknown_08172a2c,
};
extern const u16 gUnknown_08171164[32] __attribute__((section(".rodata.display_regs"))) = {
    0x0000, 0x0000, 0x0008, 0x1f03, 0x0010, 0x0000, 0x0012, 0x0000, 0x000a, 0x1e03, 0x0014,
    0x0000, 0x0016, 0x0000, 0x000c, 0x1d03, 0x0018, 0x0000, 0x001a, 0x0000, 0x000e, 0x1c0b,
    0x001c, 0x0000, 0x001e, 0x0000, 0x0050, 0x3f42, 0x0052, 0x1000, 0x0054, 0x0000,
};
const u16 *const *gUnknown_03005420 __attribute__((section(".bss"))) = 0;
}
