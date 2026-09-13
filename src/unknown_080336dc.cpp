// Inferred complete score-screen TU: 0x080336DC..0x08033D10.
// C++ reconstruction fallback; original source language and names are unknown.
// Layout views and compiler constraints are not recovered declarations.
// See docs/score-screen-tu-cpp.md for ownership and independent verification.
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
extern Node gUnknown_03003e20[];
extern u16 gUnknown_030048e0[];
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_08132734[], gUnknown_0814be64[];
extern const Position gUnknown_08edc738[];
u8 FUN_08020500(void *, const u16 *, u16), FUN_0802067c(void *, u16);
void FUN_08033bb4(Node *), FUN_08033bc4(Node *), FUN_08033cc8(Node *), FUN_08033cdc(Node *);
void FUN_08033c74(Node *), FUN_08033bf8(void), FUN_08000210(void), FUN_0801f718(u16, u16);
void FUN_0801f9d8(Node *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
extern const Position gUnknown_08edc648[];
void FUN_08033b60(Node *);
void FUN_0801f89c(void), FUN_0801fda0(void);
extern void (*gUnknown_03003150[])(void);
struct SceneState {
    u8 prefix[120];
    u32 score;
    u8 rank;
};
extern SceneState gUnknown_03001620;
extern const u16 gUnknown_0814be24[], gUnknown_081327d4[];
extern const u8 gUnknown_081323d4[], gUnknown_0814bea4[];
extern const Position gUnknown_08edc6c8[], gUnknown_08edc6d8[];
void FUN_080185d8(void), FUN_0801fbfc(const u16 *, u8), FUN_0801fb60(void);
void FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void), FUN_080210d8(void),
    FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(void *, const u16 *, u32, u32, u16), FUN_08030d3c(Node *);
void FUN_08033c20(Node *), FUN_08033a2c(Node *), FUN_08033a1c(void);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16);
void FUN_080336dc(void) {
    u8 digits[6];
    gUnknown_03003150[1] = FUN_080185d8;
    FUN_0801fbfc(gUnknown_0814be24, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000000, 0x01000100);
    u32 zero1 = 0;
    CpuFastSet(&zero1, (void *)0x06000000, 0x01000008);
    LZ77UnCompVram(gUnknown_081323d4, (void *)0x06000020);
    LZ77UnCompVram(gUnknown_0814bea4, (void *)0x06010000);
    u32 zero2 = 0;
    CpuFastSet(&zero2, (void *)0x0600d000, 0x01000200);
    u32 zero3 = 0;
    CpuFastSet(&zero3, (void *)0x0600c800, 0x01000200);
    u32 zero4 = 0;
    CpuFastSet(&zero4, (void *)0x0600c000, 0x01000200);
    u16 *destination = (u16 *)0x0600b800;
    register u32 row asm("r2") = 0;
    do {
        u32 column = 0;
        u32 nextRow = row + 1;
        for (; column < 4; ++column) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 1);
            destination += 8;
        }
        destination += 224;
        row = nextRow;
    } while (row < 4);
    FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    if (gUnknown_03001620.rank > 4)
        FUN_0801f7d0(FUN_08033c20, 28, gUnknown_03003e20, 0);
    else
        FUN_0801f7d0(FUN_08033a2c, 28, gUnknown_03003e20, 0);
    void (*draw)(Node *) = FUN_0801f9d8;
    Node *initialRoot = gUnknown_03003e20;
    Node *child = FUN_0801f7d0(draw, 16, initialRoot, 0);
    *child->position = gUnknown_08edc6c8[0];
    u32 score = gUnknown_03001620.score;
    register Node *root asm("r6");
    register void (*digitDraw)(Node *) asm("r5");
    if (score > 999998) {
        digits[0] = 164;
        digits[1] = 164;
        digits[2] = 164;
        digits[3] = 164;
        digits[4] = 164;
        digits[5] = 164;
        root = initialRoot;
        digitDraw = draw;
    } else {
        digits[0] = 128 + 4 * (score / 100000);
        digits[1] = 128 + 4 * ((score % 100000) / 10000);
        digits[2] = 128 + 4 * ((score % 10000) / 1000);
        digits[3] = 128 + 4 * ((score % 1000) / 100);
        digits[4] = 128 + 4 * ((score % 100) / 10);
        digits[5] = 128 + 4 * (score % 10);
        u32 i = 0;
        u32 first = digits[0];

        root = initialRoot;
        digitDraw = draw;
        if (first == 128) {
            digits[0] = 168;
            u32 blank = 168;

            do {
                ++i;
                if (i > 4)
                    break;
                u8 *digit = digits + i;
                if (*digit != 128)
                    break;
                *digit = blank;
            } while (1);
        }
    }
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[0];
    child->position->tile = digits[0];
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[1];
    child->position->tile = digits[1];
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[2];
    child->position->tile = digits[2];
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[3];
    child->position->tile = digits[3];
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[4];
    child->position->tile = digits[4];
    child = FUN_0801f7d0(digitDraw, 16, root, 0);
    *child->position = gUnknown_08edc6d8[5];
    child->position->tile = digits[5];
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08033a1c;
    FUN_0801f618(5);
}
void FUN_08033a1c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_08033a2c(Node *node) {
    u8 *data = (u8 *)node->allocation;
    Node *child;
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[12] = child->index;
    *child->position = gUnknown_08edc648[0];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[13] = child->index;
    *child->position = gUnknown_08edc648[1];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[14] = child->index;
    *child->position = gUnknown_08edc648[2];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[15] = child->index;
    *child->position = gUnknown_08edc648[3];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[16] = child->index;
    *child->position = gUnknown_08edc648[4];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[17] = child->index;
    *child->position = gUnknown_08edc648[5];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[18] = child->index;
    *child->position = gUnknown_08edc648[6];
    child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    data[19] = child->index;
    *child->position = gUnknown_08edc648[7];
    node->callback = FUN_08033b60;
}
void FUN_08033b60(Node *node) {
    u32 initial = !FUN_08020500((void *)0x05000000, gUnknown_08132734, 16);
    asm volatile("" : "+r"(initial));
    u32 pending = initial;
    u32 result;
    if (!FUN_08020500((void *)0x05000200, gUnknown_0814be64, 32)) {
        result = 1;
        asm volatile("" : : "r"(result));
    } else {
        result = (u8)pending;
        asm volatile("" : "+r"(result));
        if (!result)
            node->callback = FUN_08033bb4;
    }
}
void FUN_08033bb4(Node *node) {
    *(u32 *)node->allocation = 180;
    node->callback = FUN_08033bc4;
}
void FUN_08033bc4(Node *node) {
    s32 *counter = (s32 *)node->allocation;
    if (--*counter <= 0 || (gUnknown_030048e0[2] & 1)) {
        node->callback = (void (*)(Node *))FUN_08033bf8;
        FUN_0801f718(5, 120);
    }
}
void FUN_08033bf8(void) {
    if (FUN_0802067c((void *)0x05000000, 512))
        gUnknown_03002030 = FUN_08000210;
}
void FUN_08033c20(Node *node) {
    u8 *data = (u8 *)node->allocation;
    for (u8 i = 0; i < 15; ++i) {
        Node *child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        u8 *indices = data + 12;
        asm volatile("" : "+r"(indices));
        indices[i] = child->index;
        *child->position = gUnknown_08edc738[i];
    }
    node->callback = FUN_08033c74;
}
void FUN_08033c74(Node *node) {
    u32 initial = !FUN_08020500((void *)0x05000000, gUnknown_08132734, 16);
    asm volatile("" : "+r"(initial));
    u32 pending = initial;
    u32 result;
    if (!FUN_08020500((void *)0x05000200, gUnknown_0814be64, 32)) {
        result = 1;
        asm volatile("" : : "r"(result));
    } else {
        result = (u8)pending;
        asm volatile("" : "+r"(result));
        if (!result)
            node->callback = FUN_08033cc8;
    }
}
void FUN_08033cc8(Node *node) {
    *(u32 *)node->allocation = 300;
    node->callback = FUN_08033cdc;
}
void FUN_08033cdc(Node *node) {
    s32 *counter = (s32 *)node->allocation;
    if (--*counter <= 0 || (gUnknown_030048e0[2] & 1)) {
        node->callback = (void (*)(Node *))FUN_08033bf8;
        FUN_0801f718(5, 120);
    }
}
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
const Position gUnknown_08edc648[] = {{gUnknown_0814ce14, 42, 70, 0, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 59, 78, 16, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 80, 70, 32, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 101, 76, 48, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 135, 72, 64, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 157, 77, 80, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 174, 71, 48, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 195, 77, 96, 0, 0, 0, 0, 0, 0}};
extern const u8 gUnknown_08120134[];
const Position gUnknown_08edc6c8[] = {{gUnknown_08120134, 60, 98, 112, 0, 0, 16, 0, 0, 0}};
extern const u8 gUnknown_08120144[];
extern const u8 gUnknown_08120144[];
extern const u8 gUnknown_08120144[];
extern const u8 gUnknown_08120144[];
extern const u8 gUnknown_08120144[];
extern const u8 gUnknown_08120144[];
const Position gUnknown_08edc6d8[] = {{gUnknown_08120144, 110, 98, 128, 0, 0, 16, 0, 0, 0},
                                      {gUnknown_08120144, 122, 98, 128, 0, 0, 16, 0, 0, 0},
                                      {gUnknown_08120144, 134, 98, 128, 0, 0, 16, 0, 0, 0},
                                      {gUnknown_08120144, 146, 98, 128, 0, 0, 16, 0, 0, 0},
                                      {gUnknown_08120144, 158, 98, 128, 0, 0, 16, 0, 0, 0},
                                      {gUnknown_08120144, 170, 98, 128, 0, 0, 16, 0, 0, 0}};
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
extern const u8 gUnknown_0814ce14[];
const Position gUnknown_08edc738[] = {{gUnknown_0814ce14, 11, 76, 188, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 27, 76, 268, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 41, 76, 252, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 57, 76, 204, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 72, 76, 284, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 89, 76, 172, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 104, 76, 300, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 119, 76, 316, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 136, 76, 236, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 153, 76, 172, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 168, 76, 300, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 182, 76, 220, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 197, 76, 268, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 213, 76, 252, 0, 0, 0, 0, 0, 0},
                                      {gUnknown_0814ce14, 229, 76, 332, 0, 0, 0, 0, 0, 0}};
extern const u16 gUnknown_0814be24[] __attribute__((section(".rodata.registers")));
const u16 gUnknown_0814be24[] = {0,  0,  8,  6659, 16,   0,     18, 0,    10, 6403, 20,
                                 0,  22, 0,  12,   6147, 24,    0,  26,   0,  14,   5891,
                                 28, 0,  30, 0,    80,   16128, 82, 2056, 84, 0};
}
