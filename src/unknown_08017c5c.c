#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03003140;
/* 156-byte participant records. Offsets 93..146 hold two 27-byte palette
   selections; the byte at 150 chooses between them. */
struct UnknownRecord030013b0 {
    u8 first[93];
    u8 palettes[2][27];
    u8 padding147[3];
    u8 slot;
    u8 padding151[5];
};
extern struct UnknownRecord030013b0 gUnknown_030013b0[];
extern u32 gUnknown_03001380;
extern u8 gUnknown_03002684;
extern u8 gUnknown_030028c0[];
extern u16 gUnknown_030030f8[];
extern u16 gUnknown_03003108[];
extern u16 gUnknown_03003110[];
extern u8 gUnknown_03003120[];
extern u16 gUnknown_03003100[];
extern s16 gUnknown_03003118[];
extern volatile u16 gUnknown_03003178[];

#define REG_BG0CNT (*(volatile u16 *)0x04000008)
#define REG_BG1CNT (*(volatile u16 *)0x0400000a)
#define REG_BG2CNT (*(volatile u16 *)0x0400000c)
#define REG_BG3CNT (*(volatile u16 *)0x0400000e)
#define REG_SIOCNT (*(volatile u32 *)0x04000128)
#define REG_IME (*(volatile u16 *)0x04000208)
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

union UnknownQueueEntry08017f34 {
    struct {
        u32 first;
        u32 second;
    } words;
    u16 halves[4];
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

/* The 0x030033E0 queue is written field-wise by FUN_08015F6C and read back a
   word at a time by FUN_08017690, so both views of the record are needed. */
union UnknownQueueRecord030033e0 {
    u32 words[4];
    struct {
        u16 first;
        u16 second;
        s16 zero;
        /* FUN_080175D4 sorts on this field with `ldrsh`, so it is signed. */
        s16 constant;
        u16 fourth;
        u8 third;
        u8 sixth;
        u8 fifth;
        u8 seventh;
        u8 eighth;
        u8 ninth;
    } fields;
};

struct UnknownRecord030017d0 {
    u8 slots[4];
    u8 first;
    u8 second;
    u8 third;
    u8 padding7;
    u16 fourth[4];
    u8 fifth;
    u8 sixth;
    u16 seventh[3];
    u8 eighth;
    u8 padding25;
    u16 ninth;
    s16 tenth[3];
    u16 eleventh[4];
    u16 twelfth[4];
    u8 thirteenth;
    u8 fourteenth;
    u8 fifteenth;
    u8 sixteenth;
    u8 padding54[2];
    u16 seventeenth;
    u16 eighteenth[3];
    u8 nineteenth;
    u8 twentieth;
    u8 twentyfirst;
    u8 padding67;
};

struct UnknownState030030d0 {
    u8 first;
    u8 second;
    u8 padding2[2];
    u16 counter;
    u8 padding6[30];
    u8 flag;
};

struct UnknownEntry03002cd0 {
    u16 first;
    u16 second;
    u16 unused;
    u16 third;
    u16 fourth;
    u8 padding10[2];
    u8 fifth;
    u8 sixth;
    u8 padding14[2];
};

struct UnknownState080180d4 {
    u16 first;
    u16 unused;
    u16 second;
    u16 third;
};

struct UnknownState080180f0 {
    u16 first[10];
    u16 flags[10];
    u16 third[10];
    u8 position;
    u8 padding61[3];
};

struct UnknownRecord03001c40 {
    u8 padding0[20];
    u16 first;
    u8 padding22[128];
    u8 second;
    u8 padding151[8];
    u8 style;
    u8 padding160[36];
    u8 third;
    u8 padding197[3];
    u16 value;
    u8 padding202[50];
};

extern union UnknownQueueEntry08017f34 gUnknown_03003190[];
extern union UnknownQueueRecord030033e0 gUnknown_030033e0[];
extern struct UnknownEntry03002cd0 gUnknown_03002cd0[];
extern struct UnknownState030030d0 gUnknown_030030d0;
extern struct UnknownState080180d4 gUnknown_030048e0;
extern struct UnknownState080180f0 gUnknown_03001b30[];
extern struct UnknownRecord03001c40 gUnknown_03001c40[];
extern struct UnknownRecord030017d0 gUnknown_030017d0[];
extern const s16 gUnknown_0804df7c[];
extern const u8 gUnknown_0806b2d4[][10];
extern const u16 gUnknown_0847aa18[];

/* The link send slot and the four receive slots. Each receive slot is a
   16-byte record whose first halfword carries the handshake marker. */
struct UnknownState03001b10 {
    s16 first;
    s16 second;
    s16 padding4[5];
    s16 check;
};
extern struct UnknownState03001b10 gUnknown_03001b10;
extern s16 gUnknown_030016f0[][8];
extern u32 gUnknown_030013a4;
extern u32 gUnknown_03001730;
extern u8 gUnknown_030017c4;
extern u32 FUN_08018730(s16 *slots);
extern void FUN_08018c20(void);

extern u8 gUnknown_0300138c;
extern u16 gUnknown_03001378;
extern volatile u16 gUnknown_03007ff8;
extern unsigned long long gUnknown_03002610;
extern void MultiSioSyncVSync(void);
extern void FUN_0801f60c(void);
extern void FUN_0801694c(void);
extern void FUN_0801ffa4(u32 first);
extern void FUN_0801fbd8(void);

extern u16 gUnknown_030016b8;
extern u16 gUnknown_03001d0c[][126];
extern void CpuFastSet(const void *source, void *destination, u32 mode);
extern void CpuSet(const void *source, void *destination, u32 mode);
extern s32 DivArm(s32 denominator, s32 numerator);
extern s32 __divsi3(s32 numerator, s32 denominator);
extern void FUN_0800baac(u8 index);
extern void FUN_08016b30(u32 first, u32 second, u32 third, u32 fourth);
extern void FUN_08017690(void);
extern void FUN_08017eec(void);
extern void FUN_08017fb0(void);
extern void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth);
extern void FUN_0801f618(u32 index);
extern void FUN_0801ff30(void);

/* One byte of participant `index`'s selected palette record. */
#define PALETTE(part) (gUnknown_030013b0[index].palettes[gUnknown_030013b0[index].slot][part])

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

/* Hides all 128 objects and resets all 32 OAM affine matrices to identity.
   The four entries of each matrix share one pass of the loop body. */
void FUN_08017cf4(void) {
    volatile u16 *entry;
    s32 i;

    entry = (volatile u16 *)0x07000000;
    for (i = 0; i < 32; i++) {
        *entry++ = 0x200;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0x100;
        *entry++ = 0x200;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0x200;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0x200;
        *entry++ = 0;
        *entry++ = 0;
        *entry++ = 0x100;
    }
}

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
    union UnknownQueueEntry08017f34 *entries = gUnknown_03003190;
    u8 *count = &gUnknown_03001388;
    union UnknownQueueEntry08017f34 *entry = &entries[*count];

    entry->words.first = (u32)first;
    entry->words.second = (u32)second;
    (*count)++;
}

void FUN_08017f58(u8 first, u8 second) {
    gUnknown_030016d0 = first;
    gUnknown_030017c0 = second;
}

void FUN_08017f6c(void) { gUnknown_030017c8 = gUnknown_030017cc; }

static inline void UploadQueueEntry08017f80(union UnknownQueueEntry08017f34 entry) {
    u16 index = gUnknown_03003170;

    FUN_080200d8(index, entry.halves[0], entry.halves[1], entry.halves[2], entry.halves[3]);
    gUnknown_03003170++;
}

void FUN_08017f80(union UnknownQueueEntry08017f34 entry) { UploadQueueEntry08017f80(entry); }

void FUN_08017fb0(void) {
    u8 i;

    for (i = 0; i < gUnknown_03001388; i++) {
        UploadQueueEntry08017f80(gUnknown_03003190[i]);
    }
}

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
