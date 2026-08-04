#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
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

struct UnknownState080180d4 {
    u16 first;
    u16 unused;
    u16 second;
    u16 third;
};

extern struct UnknownQueueEntry08017f34 gUnknown_03003190[];
extern struct UnknownQueueEntry08017f00 gUnknown_030033e0[];
extern struct UnknownState080180d4 gUnknown_030048e0;
extern void CpuFastSet(const void *source, void *destination, u32 mode);
extern s32 DivArm(s32 denominator, s32 numerator);
extern s32 __divsi3(s32 numerator, s32 denominator);
extern void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth);

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

void FUN_0801808c(u16 first, u16 second, u16 third, u16 fourth) {
    FUN_080200d8(gUnknown_03003170, first, second, third, fourth);
    gUnknown_03003170++;
}

void FUN_080180d4(u16 *first, u16 *second, u16 *third) {
    *first = gUnknown_030048e0.first;
    *second = gUnknown_030048e0.second;
    *third = gUnknown_030048e0.third;
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
