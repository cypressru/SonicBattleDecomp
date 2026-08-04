#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03003140;
extern u8 gUnknown_030013b0[];
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
    u8 padding0[159];
    u8 style;
    u8 padding160[40];
    u16 value;
    u8 padding202[50];
};

extern struct UnknownQueueEntry08017f34 gUnknown_03003190[];
extern union UnknownQueueRecord030033e0 gUnknown_030033e0[];
extern struct UnknownEntry03002cd0 gUnknown_03002cd0[];
extern struct UnknownState030030d0 gUnknown_030030d0;
extern struct UnknownState080180d4 gUnknown_030048e0;
extern struct UnknownState080180f0 gUnknown_03001b30[];
extern struct UnknownRecord03001c40 gUnknown_03001c40[];
extern struct UnknownRecord030017d0 gUnknown_030017d0[];
extern const s16 gUnknown_0804df7c[];
extern const u8 gUnknown_0806b2d4[][10];
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

/* The buttons currently held by participant `index`, taken from the newest
   slot of that participant's input ring. */
#define HELD_BUTTONS (gUnknown_03001b30[index].first[gUnknown_03001b30[index].position])

/* Selects one of the ten columns of the 0x0806B2D4 move table for the
   participant's fighting style, according to the buttons held. */
u8 FUN_080034f0(u8 index) {
    u8 result;

    if ((HELD_BUTTONS & 0x20) && (HELD_BUTTONS & 0x80)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][1];
    } else if ((HELD_BUTTONS & 0x10) && (HELD_BUTTONS & 0x80)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][3];
    } else if ((HELD_BUTTONS & 0x20) && (HELD_BUTTONS & 0x40)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][7];
    } else if ((HELD_BUTTONS & 0x10) && (HELD_BUTTONS & 0x40)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][9];
    } else if (HELD_BUTTONS & 0x80) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][2];
    } else if (HELD_BUTTONS & 0x20) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][4];
    } else if (HELD_BUTTONS & 0x10) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][6];
    } else if (HELD_BUTTONS & 0x40) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][8];
    } else {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][0];
    }
    return result;
}

void FUN_08007e24(void) {
    volatile u32 *dma;

    dma = (volatile u32 *)0x040000d4;
    dma[0] = 0x0847ab98;
    dma[1] = 0x05000280;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = 0x0847abb8;
    dma[1] = 0x06011200;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847acb8;
    dma[1] = 0x06011300;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847adb8;
    dma[1] = 0x06011400;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847aeb8;
    dma[1] = 0x06011500;
    dma[2] = 0x80000080;
    dma[2];
}

void FUN_08007e9c(u8 index) {
    u8 i;

    for (i = 0; i <= 68; i++) {
        gUnknown_030013b0[i + index * 156] = 9;
    }
}

void FUN_0800baac(u8 index) {
    struct UnknownRecord030017d0 *record;
    struct UnknownRecord030017d0 *table;

    table = gUnknown_030017d0;
    record = table + index;
    if (record->slots[0] != 255) {
        gUnknown_030028c0[record->slots[0]] = 0;
    }
    if (record->slots[1] != 255) {
        gUnknown_030028c0[record->slots[1]] = 0;
    }
    if (record->slots[2] != 255) {
        gUnknown_030028c0[record->slots[2]] = 0;
    }
    if (record->slots[3] != 255) {
        gUnknown_030028c0[record->slots[3]] = 0;
    }
    record->fifteenth = 255;
    record->slots[0] = -1;
    record->slots[1] = -1;
    record->slots[2] = -1;
    record->slots[3] = -1;
    record->first = 0;
    record->nineteenth = 0;
    record->second = 0;
    record->third = 0;
    record->fourth[0] = 0;
    record->fourth[1] = 0;
    record->fourth[2] = 0;
    record->fourth[3] = 0;
    record->eighteenth[0] = 0;
    record->eighteenth[1] = 0;
    record->eighteenth[2] = 0;
    record->fifth = 0;
    record->sixth = 0;
    record->seventh[0] = 0;
    record->seventh[1] = 0;
    record->seventh[2] = 0;
    record->eighth = 0;
    record->ninth = 0xffff;
    record->tenth[0] = -1;
    record->tenth[1] = -1;
    record->tenth[2] = -1;
    record->eleventh[0] = 0;
    record->twelfth[0] = 0;
    record->eleventh[1] = 0;
    record->twelfth[1] = 0;
    record->eleventh[2] = 0;
    record->twelfth[2] = 0;
    record->eleventh[3] = 0;
    record->twelfth[3] = 0;
    record->seventeenth = 0;
    record->sixteenth = 8;
    record->fourteenth = 0;
    record->thirteenth = 1;
    record->twentieth = 0;
    record->twentyfirst = 0;
}

void FUN_0800fd8c(void) {
    u8 i;

    for (i = 0; i <= 11; i++) {
        FUN_0800baac(i);
    }
    for (i = 0; i <= 26; i++) {
        gUnknown_030028c0[i] = 0;
    }
    gUnknown_03002684 = 0;
}

void FUN_08012b60(void) {
    u8 i;

    gUnknown_030030d0.flag = 0;
    for (i = 0; i <= 63; i++) {
        gUnknown_03002cd0[i].first = 0;
        gUnknown_03002cd0[i].second = 0;
        gUnknown_03002cd0[i].third = 0;
        gUnknown_03002cd0[i].fourth = 0;
        gUnknown_03002cd0[i].fifth = 0;
        gUnknown_03002cd0[i].sixth = 0;
    }
}

#define BUTTON_STATE                                                                               \
    gUnknown_03001b30[gUnknown_03001380].flags[gUnknown_03001b30[gUnknown_03001380].position]

u8 FUN_080153e0(void) {
    if (gUnknown_030030d0.counter <= 0x1fff) {
        gUnknown_030030d0.counter += 0x200;
    } else {
        gUnknown_030030d0.counter -= 0x2000;
    }
    if ((BUTTON_STATE & 0x40) || (BUTTON_STATE & 0x80)) {
        gUnknown_030030d0.second ^= 1;
        FUN_0801f618(600);
    }
    if (BUTTON_STATE & 1) {
        FUN_0801f618(601);
        return gUnknown_030030d0.second;
    }
    if (BUTTON_STATE & 8) {
        FUN_0801f618(601);
        return 0;
    }
    return 255;
}

void FUN_080163c0(u8 layer) {
    u8 index;
    volatile u16 value;

    index = layer;
    gUnknown_03003178[index] = 0;
    value = 0;
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

u8 FUN_08015384(void) {
    u16 previous;

    previous = gUnknown_030030d0.counter;
    gUnknown_030030d0.counter = previous + 1;
    if (previous >= 60 && previous <= 0xed6) {
        if (gUnknown_030048e0.second & 8) {
            gUnknown_030030d0.counter = 0xed8;
        }
    }
    if (gUnknown_030030d0.counter > 0xf00) {
        return 2;
    }
    if (gUnknown_030030d0.counter > 0xed8) {
        return 1;
    }
    return 0;
}

u8 FUN_08015858(void) {
    const u8 *source;

    gUnknown_030030d0.counter++;
    if (gUnknown_030030d0.counter == 27) {
        FUN_0801f618(46);
    } else if (gUnknown_030030d0.counter == 88) {
        source = (const u8 *)0x0831ed34;
        CpuFastSet(source, (void *)0x06016800, 0x200);
        source += 0x800;
        CpuFastSet(source, (void *)0x06017000, 0x200);
    }
    if (gUnknown_030030d0.counter > 103) {
        return 1;
    }
    return 0;
}

u8 FUN_0801584c(void) { return gUnknown_030030d0.first; }

void FUN_080158e4(void) {
    gUnknown_03003108[0] = 0;
    gUnknown_03003108[1] = 0;
    gUnknown_03003108[2] = 0;
    gUnknown_03003108[3] = 0;
    gUnknown_03003110[0] = 0;
    gUnknown_03003110[1] = 0;
    gUnknown_03003110[2] = 0;
    gUnknown_03003110[3] = 0;
    gUnknown_030030f8[0] = 0;
    gUnknown_030030f8[1] = 0;
    gUnknown_030030f8[2] = 0;
    gUnknown_030030f8[3] = 0;
    gUnknown_03003120[0] = 0;
    gUnknown_03003120[1] = 0;
    gUnknown_03003120[2] = 0;
    gUnknown_03003120[3] = 0;
}

/* Bubble-sorts the live part of the 0x030033E0 queue into descending order of
   the halfword at offset 6, so FUN_08017690 submits records back to front. */
void FUN_080175d4(void) {
    union UnknownQueueRecord030033e0 temp;
    u8 i;
    u8 j;
    u8 pass;

    pass = 1;
    for (i = gUnknown_030017c8 + 1; i < gUnknown_030017cc; i++) {
        for (j = gUnknown_030017c8; j < gUnknown_030017cc - pass; j++) {
            if (gUnknown_030033e0[j].fields.constant < gUnknown_030033e0[j + 1].fields.constant) {
                temp = gUnknown_030033e0[j];
                gUnknown_030033e0[j] = gUnknown_030033e0[j + 1];
                gUnknown_030033e0[j + 1] = temp;
            }
        }
        pass++;
    }
}

void FUN_08017690(void) {
    u8 i;
    union UnknownQueueRecord030033e0 *record;

    for (i = 0; i < gUnknown_030017cc; i++) {
        if (i >= gUnknown_030017c8) {
            if (gUnknown_030033e0[i].fields.zero > 29) {
                gUnknown_030033e0[i].fields.third = 2;
            } else {
                gUnknown_030033e0[i].fields.third = 3;
            }
        }
        record = &gUnknown_030033e0[i];
        FUN_08016b30(record->words[0], record->words[1], record->words[2], record->words[3]);
    }
}

/* Eases 0x03001B08 towards a target angle on a 0x2000-unit circle, taking the
   short way round and renormalising both the argument and the result. */
void FUN_080176e4(s16 target) {
    while (target > 0x2000) {
        target -= 0x2000;
    }
    while (target < 0) {
        target += 0x2000;
    }
    if (gUnknown_03001b08 - target > 0x1000) {
        gUnknown_03001b08 -= 0x2000;
    } else if (gUnknown_03001b08 - target < -0x1000) {
        gUnknown_03001b08 += 0x2000;
    }
    gUnknown_03001b08 -= (gUnknown_03001b08 - target) >> 3;
    while (gUnknown_03001b08 > 0x1fff) {
        gUnknown_03001b08 -= 0x2000;
    }
    while (gUnknown_03001b08 < 0) {
        gUnknown_03001b08 += 0x2000;
    }
}

void FUN_08017964(u8 group) {
    u8 i;

    gUnknown_03001b30[group].position = 0;
    for (i = 0; i <= 9; i++) {
        gUnknown_03001b30[group].first[i] = 0;
        gUnknown_03001b30[group].flags[i] = 0;
        gUnknown_03001b30[group].third[i] = 0;
    }
    gUnknown_03001c40[0].value = 0;
    gUnknown_03001c40[1].value = 0;
    gUnknown_03001c40[2].value = 0;
    gUnknown_03001c40[3].value = 0;
}

u8 FUN_080158c0(void) {
    gUnknown_030030d0.counter++;
    if (gUnknown_030030d0.counter > 119) {
        return 1;
    }
    return 0;
}

s16 FUN_08015f40(u8 index) { return -gUnknown_03003100[index]; }

s16 FUN_08015f58(u8 index) { return gUnknown_03003118[index]; }

void FUN_08015f6c(void) {
    u8 i;

    for (i = 0; (s8)i >= 0; i++) {
        gUnknown_030033e0[i].fields.first = 0;
        gUnknown_030033e0[i].fields.second = 0;
        gUnknown_030033e0[i].fields.zero = 0;
        gUnknown_030033e0[i].fields.constant = 0;
        gUnknown_030033e0[i].fields.fourth = 0;
        gUnknown_030033e0[i].fields.third = 0;
        gUnknown_030033e0[i].fields.sixth = 0;
        gUnknown_030033e0[i].fields.fifth = 0;
        gUnknown_030033e0[i].fields.seventh = 0;
        gUnknown_030033e0[i].fields.eighth = 0;
        gUnknown_030033e0[i].fields.ninth = 0;
    }
}

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
