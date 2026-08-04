#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03003140;
extern volatile u16 gUnknown_03003178[];

#define REG_BG0CNT (*(volatile u16 *)0x04000008)
#define REG_BG1CNT (*(volatile u16 *)0x0400000a)
#define REG_BG2CNT (*(volatile u16 *)0x0400000c)
#define REG_BG3CNT (*(volatile u16 *)0x0400000e)
extern u8 gUnknown_030016d0;
extern u8 gUnknown_030017c0;
extern u8 gUnknown_030017c8;
extern u8 gUnknown_030017cc;
extern s16 gUnknown_030016c8;
extern u8 gUnknown_030016c4;
extern s16 gUnknown_03001b04;
extern s16 gUnknown_03001b08;
extern u8 gUnknown_03001390;
extern u8 gUnknown_03001370;
extern s16 gUnknown_030016bc;
extern s16 gUnknown_030016c0;
extern s16 gUnknown_03001b2c;
extern s16 gUnknown_03001384;
extern u16 gUnknown_03003170;
extern u16 gUnknown_030033cc;

struct UnknownQueueEntry08017f00 {
    u32 words[4];
};

struct UnknownQueueEntry08017f34 {
    void *first;
    void *second;
};

struct UnknownQueueEntry08018004 {
    u16 first;
    u16 second;
    u16 zero;
    u16 constant;
    u16 fourth;
    u8 third;
    u8 sixth;
    u8 fifth;
    u8 seventh;
    u8 eighth;
    u8 ninth;
};

struct UnknownState080180d4 {
    u16 first;
    u16 unused;
    u16 second;
    u16 third;
};

struct UnknownState080180f0 {
    u8 padding0[20];
    u16 flags[11];
    u8 padding42[18];
    u8 position;
    u8 padding61[3];
};

extern struct UnknownQueueEntry08017f34 gUnknown_03003190[];
extern struct UnknownQueueEntry08017f00 gUnknown_030033e0[];
extern struct UnknownState080180d4 gUnknown_030048e0;
extern struct UnknownState080180f0 gUnknown_03001b30[];
extern const s16 gUnknown_0804df7c[];
extern void CpuFastSet(const void *source, void *destination, u32 mode);
extern void CpuSet(const void *source, void *destination, u32 mode);
extern s32 DivArm(s32 denominator, s32 numerator);
extern s32 __divsi3(s32 numerator, s32 denominator);
extern void FUN_08017690(void);
extern void FUN_08017eec(void);
extern void FUN_08017fb0(void);
extern void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth);
extern void FUN_0801ff30(void);

void FUN_08017c5c(void) {
    gUnknown_03003140 ^= 1;
    gUnknown_030013a0 = 1;
}

void FUN_08017c74(void) {
    volatile u32 zero;
    volatile u32 *dma;

    zero = 0;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&zero;
    dma[1] = 0x02000000;
    dma[2] = 0x85010000;
    dma[2];
    zero = 0;
    dma[0] = (u32)&zero;
    dma[1] = 0x03000000;
    dma[2] = 0x85001f80;
    dma[2];
}

void FUN_08017cb0(void) {
    volatile u16 zero;
    volatile u32 *dma;

    zero = 0;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&zero;
    dma[1] = 0x06000000;
    dma[2] = 0x8100c000;
    dma[2];
}

void FUN_08017cd8(void) { CpuSet((void *)0x05000000, (void *)0x05000002, 0x1ff); }

void FUN_08017d58(void) {
    FUN_08017eec();
    FUN_0801ff30();
    FUN_08017690();
    FUN_08017fb0();
    gUnknown_030013a0 = 1;
}

void FUN_08017d78(u8 layer, u32 bits) {
    u8 index;
    volatile u16 value;

    index = layer;
    value = bits;
    gUnknown_03003178[index] |= value;
    switch (index) {
    case 0:
        REG_BG0CNT = gUnknown_03003178[0];
        break;
    case 1:
        REG_BG1CNT = gUnknown_03003178[1];
        break;
    case 2:
        REG_BG2CNT = gUnknown_03003178[2];
        break;
    case 3:
        REG_BG3CNT = gUnknown_03003178[3];
        break;
    }
}

void FUN_08017de8(u8 layer, u16 bits) {
    u8 index;
    volatile u16 value;

    index = layer;
    value = bits << 2;
    gUnknown_03003178[index] |= value;
    switch (index) {
    case 0:
        REG_BG0CNT = gUnknown_03003178[0];
        break;
    case 1:
        REG_BG1CNT = gUnknown_03003178[1];
        break;
    case 2:
        REG_BG2CNT = gUnknown_03003178[2];
        break;
    case 3:
        REG_BG3CNT = gUnknown_03003178[3];
        break;
    }
}

void FUN_08017e5c(u8 layer, u16 bits) {
    u8 index;
    volatile u16 value;

    index = layer;
    value = bits << 8;
    gUnknown_03003178[index] |= value;
    switch (index) {
    case 0:
        REG_BG0CNT = gUnknown_03003178[0];
        break;
    case 1:
        REG_BG1CNT = gUnknown_03003178[1];
        break;
    case 2:
        REG_BG2CNT = gUnknown_03003178[2];
        break;
    case 3:
        REG_BG3CNT = gUnknown_03003178[3];
        break;
    }
}

void FUN_08017ed0(void) {
    gUnknown_030017cc = 0;
    gUnknown_030017c8 = 0;
    gUnknown_03001388 = 0;
}

void FUN_08017eec(void) {
    gUnknown_030033cc = 0;
    gUnknown_03003170 = 0;
}

void FUN_08017f00(u32 first, u32 second, u32 third, u32 fourth) {
    struct UnknownQueueEntry08017f00 entry;

    entry.words[0] = first;
    entry.words[1] = second;
    entry.words[2] = third;
    entry.words[3] = fourth;
    CpuFastSet(&entry, &gUnknown_030033e0[gUnknown_030017cc], 4);
    gUnknown_030017cc++;
}

void FUN_08017f34(void *first, void *second) {
    struct UnknownQueueEntry08017f34 *entries = gUnknown_03003190;
    u8 *count = &gUnknown_03001388;
    struct UnknownQueueEntry08017f34 *entry = &entries[*count];

    entry->first = first;
    entry->second = second;
    (*count)++;
}

void FUN_08017f58(u8 first, u8 second) {
    gUnknown_030016d0 = first;
    gUnknown_030017c0 = second;
}

void FUN_08017f6c(void) { gUnknown_030017c8 = gUnknown_030017cc; }

void FUN_08018004(u16 first, u16 second, u8 third, u16 fourth, u8 fifth, u8 sixth, u8 seventh,
                  u8 eighth, u8 ninth) {
    struct UnknownQueueEntry08018004 entry;
    struct UnknownQueueEntry08018004 copy;

    entry.first = first;
    entry.second = second;
    entry.zero = 0;
    entry.third = third;
    entry.constant = 200;
    entry.sixth = sixth;
    entry.fourth = fourth;
    entry.fifth = fifth;
    entry.seventh = seventh;
    entry.eighth = eighth;
    entry.ninth = ninth;
    copy = entry;
    CpuFastSet(&copy, &gUnknown_030033e0[gUnknown_030017cc], 4);
    gUnknown_030017cc++;
}

void FUN_0801808c(u16 first, u16 second, u16 third, u16 fourth) {
    FUN_080200d8(gUnknown_03003170, first, second, third, fourth);
    gUnknown_03003170++;
}

void FUN_080180d4(u16 *first, u16 *second, u16 *third) {
    *first = gUnknown_030048e0.first;
    *second = gUnknown_030048e0.second;
    *third = gUnknown_030048e0.third;
}

u8 FUN_080180f0(u8 group, u8 start, u8 count, u16 mask) {
    u16 position;
    s16 index;
    u8 i;

    if (start > 9) {
        start = 9;
    }

    position = gUnknown_03001b30[group].position - start;
    index = position;
    if (index < 0) {
        position = index + 10;
    }

    for (i = 0; i < count; i++) {
        index = position;

        if (gUnknown_03001b30[group].flags[index] & mask) {
            return 1;
        }
        if (index <= 9) {
            position = index + 1;
        } else {
            position = 0;
        }
    }

    return 0;
}

void FUN_0801816c(s16 *outputX, s16 *outputY, s16 inputX, s16 inputY) {
    inputX -= gUnknown_03001b2c;
    inputY -= gUnknown_030016c0;
    *outputX = (gUnknown_0804df7c[gUnknown_03001b08 + 0x800] * inputX -
                gUnknown_0804df7c[gUnknown_03001b08] * inputY) >>
               13;
    *outputY = (gUnknown_0804df7c[gUnknown_03001b08] * inputX +
                gUnknown_0804df7c[gUnknown_03001b08 + 0x800] * inputY) >>
               13;
}

void FUN_08018204(s16 *outputX, s16 *outputY, u16 factorX, s16 factorY) {
    s32 signedFactorX = (s16)factorX;

    *outputX = ((gUnknown_03001b04 * signedFactorX) >> 13) + 120;
    *outputY = ((DivArm(gUnknown_030016c8, gUnknown_03001b04 << 8) * factorY) >> 13) + 80;
}

void FUN_0801824c(s16 *outputX, s16 *outputY, s16 inputX, s16 inputY) {
    *outputX = __divsi3((inputX - 120) << 13, gUnknown_03001b04);
    *outputY = __divsi3(((inputY - 80) << 13) * gUnknown_030016c8, gUnknown_03001b04 << 8);
}

void FUN_080182ac(void) {
    gUnknown_03001384 = (42 * gUnknown_03001b04) >> 9;
    gUnknown_03001384 -= DivArm(gUnknown_030016c8, gUnknown_03001384);
}

void FUN_080182e4(s16 target) { gUnknown_03001b04 -= (gUnknown_03001b04 - target) >> 3; }

void FUN_08018300(s16 target) { gUnknown_030016c8 = (gUnknown_030016c8 + target) >> 1; }

void FUN_08018318(s16 first, s16 second) {
    if ((u8)(gUnknown_03001370 - 2) <= 1) {
        first += gUnknown_030016bc;
    } else {
        second += gUnknown_030016bc;
    }

    gUnknown_03001b2c -= (gUnknown_03001b2c - first) >> 3;
    gUnknown_030016c0 -= (gUnknown_030016c0 - second) >> 3;
}

s16 FUN_08018390(void) { return gUnknown_03001b08; }

void FUN_0801839c(void) {
    u8 *current = &gUnknown_030016c4;
    u8 *target = &gUnknown_03001390;

    if (*current != *target) {
        u8 value = *current;

        *current = value - ((value - *target) >> 2);
    }
}

void FUN_080183c4(u8 value) { gUnknown_03001390 = value; }

void FUN_080183d0(u8 first, u8 second, u8 third, u8 fourth, u8 fifth, u8 sixth) {
    *(volatile u16 *)0x04000050 = second | (third << 8) | (first << 6);
    *(volatile u16 *)0x04000052 = fourth | (fifth << 8);
    *(volatile u16 *)0x04000054 = sixth;
}

void FUN_08018410(void) {
    volatile u32 *dma = (volatile u32 *)0x040000d4;

    dma[0] = 0x0847afb8;
    dma[1] = (u32)gUnknown_03001740;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = 0x084cadd8;
    dma[1] = (u32)(gUnknown_03001740 + 0x40);
    dma[2] = 0x80000010;
    dma[2];
}
