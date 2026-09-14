#include "types.h"
// C++ reconstruction fallback; original source language is unknown.
// Synthetic address labels and observed field views are not retail names/types.
// Boundaries, shared storage and constraint evidence: docs/scene-39dd8-tu-cpp.md.
struct Position {
    const void *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, timer;
};
struct Animation {
    u16 *destination;
    u16 tile, timer;
};
struct Node {
    void (*callback)(Node *);
    u8 field4, previous, index, next;
    Position *position;
    void *allocation;
};
struct Controller {
    // Accessed prefix of a 20-byte allocation; its final two bytes are unobserved here.
    u8 prefix[16];
    u8 left, right;
};
struct Child {
    // Accessed prefix of a 28-byte allocation; its final four bytes are unobserved here.
    const void *parts;
    u32 field4;
    u16 tile, field10;
    u8 attr0, padding[7];
    u16 x, y;
};
extern "C" {
extern const u16 gUnknown_0815e69c[];
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
void FUN_08039dd8(Node *node) {
    Animation *animation = (Animation *)node->allocation;
    ++animation->timer;
    if (animation->timer > 23)
        animation->timer = 0;
    FUN_08021000(animation->destination, gUnknown_0815e69c + ((animation->timer >> 2) & 7) * 204,
                 12, 17, animation->tile);
}
}
extern "C" {
extern u8 gUnknown_030052e0, gUnknown_03002110[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_0815f02c[], gUnknown_0816eaec[], gUnknown_081327d4[];
extern const u8 gUnknown_0815f06c[], gUnknown_0815c4b4[], gUnknown_08132544[], gUnknown_0815f818[];
extern const u8 *const gUnknown_08edd314[];
extern const Position gUnknown_08edd304;
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d20(Node *), FUN_08039dd8(Node *), FUN_0801f9d8(Node *), FUN_08039fe0(Node *);
void FUN_0801fba0(u16, u16), FUN_0801f618(u32);
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_08039fd0(void);
void FUN_08039e20(void) {
    gUnknown_030052e0 = 0;
    FUN_0801fbfc(gUnknown_0815f02c, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_0815f06c, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_0815c4b4, (void *)0x06008000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600d240);
    LZ77UnCompVram(gUnknown_08edd314[gUnknown_03002110[119]], (void *)0x06010000);
    u32 mapZero = 0;
    CpuFastSet(&mapZero, (void *)0x0600f800, 0x01000200);
    FUN_08021000((u16 *)0x0600fa06, gUnknown_0816eaec, 16, 8, 0xd380);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    LZ77UnCompVram(gUnknown_0815f818, (void *)0x0600e800);
    u16 *destination = (u16 *)0x0600e000;
    for (u32 y = 0; y <= 3; ++y) {
        for (u32 x = 0; x <= 3; ++x) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf292);
            destination += 8;
        }
        destination += 224;
    }
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_08039dd8, 8, gUnknown_03003e20, 0);
    Animation *animation = (Animation *)node->allocation;
    animation->destination = (u16 *)0x0600f0a6;
    animation->tile = 0xe000;
    animation->timer = 0;
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd304;
    FUN_0801f7d0(FUN_08039fe0, 20, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08039fd0;
    FUN_0801f618(1);
}
void FUN_08039fd0(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
}
extern "C" {
u8 FUN_08020500(u16 *, const u16 *, u16);
extern const u16 gUnknown_0815f7f8[], gUnknown_0815e67c[], gUnknown_081326f4[], gUnknown_081609c4[];
extern const u8 gUnknown_0816eac4[];
extern Node gUnknown_03003e20[];
extern u8 gUnknown_030052e0;
extern u32 gUnknown_03005264;
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08028238(Node *), FUN_08028270(Node *), FUN_0803a3b8(Node *);
void FUN_08039fe0(Node *node) {
    register Node *owner = node;
    Controller *controller = (Controller *)node->allocation;
    register u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_0815f7f8, 16) == 0;

    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001c0, gUnknown_0815e67c, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_081326f4, 16) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    pending = result;
    u32 final;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_081609c4, 16) == 0)
        final = pending | 1;
    else
        final = (u8)pending;
    if (!final) {
        register void (*initialize)(Node *) = FUN_08028238;

        register Node *listInitial = gUnknown_03003e20;
        register Node *list = listInitial;
        register Node *child = FUN_0801f7d0(initialize, 28, list, 0);
        controller->left = child->index;
        Child *allocation = (Child *)child->allocation;
        allocation->parts = gUnknown_0816eac4;
        allocation->tile = final;
        allocation->attr0 = 4;
        allocation->x = 64;
        allocation->y = 146;
        child = FUN_0801f7d0(FUN_08028270, 28, list, 0);
        controller->right = child->index;
        allocation = (Child *)child->allocation;
        allocation->parts = gUnknown_0816eac4;
        allocation->tile = 64;
        allocation->attr0 = 4;
        allocation->x = 176;
        allocation->y = 118;
        gUnknown_030052e0 = gUnknown_03005264;
        register void (*next)(Node *) = FUN_0803a3b8;

        owner->callback = next;
    }
}
}
extern "C" {
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_030052e0;
extern u32 gUnknown_03005264;
extern Node gUnknown_03003e20[];
void FUN_0803a260(Node *), FUN_0803a478(Node *);
void FUN_08027fb8(Node *), FUN_08028038(Node *);
void FUN_0801f718(u32, u32), FUN_0801f618(u32);
void FUN_0803a0f8(Node *input) {
    register Node *node = input;
    Controller *controller = (Controller *)node->allocation;
    register u16 pressed asm("r1") = gUnknown_030048e0[2];
    if (pressed & 1) {
        switch (gUnknown_030052e0) {
        case 0:
            gUnknown_03005264 = 0;
            break;
        case 1:
            gUnknown_03005264 = 1;
            break;
        case 2:
            gUnknown_03005264 = 2;
            break;
        case 3:
            gUnknown_03005264 = 3;
            break;
        case 4:
            gUnknown_03005264 = 4;
            break;
        case 5:
            gUnknown_03005264 = 5;
            break;
        case 6:
            gUnknown_03005264 = 6;
            break;
        }
        node->callback = FUN_0803a260;
        FUN_0801f718(1, 120);
        FUN_0801f618(404);
    } else if (pressed & 32) {
        if (gUnknown_030052e0)
            --gUnknown_030052e0;
        else
            gUnknown_030052e0 = 6;
        node->callback = FUN_0803a478;
        gUnknown_03003e20[controller->left].callback = FUN_08027fb8;
        gUnknown_03003e20[controller->left].position->state = 0;
        FUN_0801f618(401);
    } else if (pressed & 16) {
        if (++gUnknown_030052e0 > 6)
            gUnknown_030052e0 = 0;
        node->callback = FUN_0803a478;
        gUnknown_03003e20[controller->right].callback = FUN_08028038;
        gUnknown_03003e20[controller->right].position->state = 0;
        FUN_0801f618(401);
    }
}
}
extern "C" {
extern u8 gUnknown_030052e0, gUnknown_03002110[], gUnknown_03001620[];
extern u8 gUnknown_030053f8, gUnknown_030053e8, gUnknown_030053f0, gUnknown_030053e0;
extern void (*gUnknown_03002030)(void);
u32 FUN_0802067c(u16 *, u16);
void FUN_08029cfc(u32);
void *memset(void *, int, u32);
void FUN_0803cb64(void), FUN_0802cc78(void), FUN_080284b4(void), FUN_0803ae04(void);
void FUN_080315bc(void), FUN_0803984c(void), FUN_08037d44(void);
void FUN_0803a260(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        switch (gUnknown_030052e0) {
        case 0: {
            register u8 *save = gUnknown_03002110;
            register u32 offset = 145;

            offset <<= 3;
            if (save[offset] == 0)
                gUnknown_03002030 = FUN_0802cc78;
            else
                gUnknown_03002030 = FUN_0803cb64;
            break;
        }
        case 1:
            FUN_08029cfc(0);
            FUN_08029cfc(1);
            FUN_08029cfc(2);
            FUN_08029cfc(3);
            memset(gUnknown_03001620, 0, 152);
            gUnknown_03002030 = FUN_080284b4;
            break;
        case 2:
            FUN_08029cfc(0);
            FUN_08029cfc(1);
            FUN_08029cfc(2);
            FUN_08029cfc(3);
            gUnknown_03002030 = FUN_0802cc78;
            break;
        case 3:
            gUnknown_030053f8 = 0;
            gUnknown_030053e8 = 0;
            gUnknown_030053f0 = 0;
            gUnknown_030053e0 = 0;
            FUN_08029cfc(0);
            FUN_08029cfc(1);
            FUN_08029cfc(2);
            FUN_08029cfc(3);
            gUnknown_03002030 = FUN_0803ae04;
            break;
        case 4:
            gUnknown_03002030 = FUN_080315bc;
            break;
        case 5:
            gUnknown_03002030 = FUN_0803984c;
            break;
        case 6:
            gUnknown_03002030 = FUN_08037d44;
            break;
        }
    }
}
}
extern "C" {
extern const u8 *const gUnknown_08edd32c[];
extern const u8 gUnknown_0816e9e4[];
extern u8 gUnknown_03002110[], gUnknown_030052e0;
void FUN_0802036c(u32, u32, u32);
void FUN_0801fba0(u16, u16);
void FUN_0803a0f8(Node *), FUN_0803a428(Node *);
void FUN_0803a3b8(Node *node) {
    register const u8 *const *table = gUnknown_08edd32c;
    register u32 index = gUnknown_03002110[119];
    index <<= 2;
    index += (u32)table;
    register const u8 *source = *(const u8 **)index;

    FUN_0802036c(0x06007000, (u32)(source + (gUnknown_030052e0 << 12)), 4096);
    FUN_0802036c(0x050001a0, (u32)(gUnknown_0816e9e4 + (gUnknown_030052e0 << 5)), 32);
    FUN_0801fba0(80, 0x3f41);
    FUN_0801fba0(82, 4096);
    node->callback = FUN_0803a428;
}
void FUN_0803a428(Node *node) {
    if (++node->position->state <= 15) {
        register u32 state = node->position->state;
        register u32 shifted = state << 8;
        register u32 scale asm("r3") = 0x1000;
        asm("" : "+r"(scale));
        register u32 remainder asm("r0") = scale;
        asm("" : "+r"(remainder));
        remainder -= shifted;
        FUN_0801fba0(82, remainder | state);
    } else {
        node->position->state = 16;
        FUN_0801fba0(82, 16);
        node->callback = FUN_0803a0f8;
    }
    FUN_0803a0f8(node);
}
void FUN_0803a478(Node *node) {
    if (node->position->state) {
        --node->position->state;
        register u32 state = node->position->state;
        register u32 shifted = state << 8;
        register u32 scale asm("r3") = 0x1000;
        asm("" : "+r"(scale));
        register u32 remainder asm("r0") = scale;
        asm("" : "+r"(remainder));
        remainder -= shifted;
        FUN_0801fba0(82, remainder | state);
    } else {
        FUN_0801fba0(82, 4096);
        node->callback = FUN_0803a3b8;
    }
}
}

extern "C" {
extern const u8 gUnknown_0816eacc[];
extern const u8 gUnknown_0815fafc[], gUnknown_08160244[];
extern const u8 gUnknown_081609e4[], gUnknown_081679e4[];
extern const Position gUnknown_08edd304 = {gUnknown_0816eacc, 64, 32, 128, 0, 0, 0, 0, 0, 0};
extern const u8 *const gUnknown_08edd314[6] = {gUnknown_0815fafc, gUnknown_08160244,
                                               gUnknown_08160244, gUnknown_08160244,
                                               gUnknown_08160244, gUnknown_08160244};
extern const u8 *const gUnknown_08edd32c[6] = {gUnknown_081609e4, gUnknown_081679e4,
                                               gUnknown_081679e4, gUnknown_081679e4,
                                               gUnknown_081679e4, gUnknown_081679e4};
extern const u16 gUnknown_0815f02c[32] __attribute__((section(".rodata.registers"))) = {
    0x00,   0x0000, 0x08,   0x1f00, 0x10,   0x0000, 0x12,   0x0000, 0x0a,   0x1e0b, 0x14,
    0x0000, 0x16,   0x0000, 0x0c,   0x1d03, 0x18,   0x0000, 0x1a,   0x0000, 0x0e,   0x1c0b,
    0x1c,   0x0000, 0x1e,   0x0000, 0x50,   0x3f41, 0x52,   0x1000, 0x54,   0x0000};
}
