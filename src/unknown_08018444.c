#include "types.h"

typedef unsigned long long u64;

extern u8 gUnknown_030013a0;
extern u16 gUnknown_03001b10[8];
extern u16 gUnknown_030016f0[4][8];
extern u8 gUnknown_03003290;
extern u32 gUnknown_03001730;
extern u8 gUnknown_0300138c;
extern u32 gUnknown_03003150[];
extern u32 gUnknown_030032a0[];
extern u32 gUnknown_03007ffc;
extern u32 gUnknown_03001380;
extern u8 gUnknown_030017c4;
extern u16 gUnknown_03001378;
extern volatile u16 gUnknown_03007ff8;
extern u64 gUnknown_03002610;

extern void FUN_0801694c(void);
extern void FUN_08017eec(void);
extern void FUN_0801ff30(void);
extern void FUN_08017690(void);
extern void FUN_08017fb0(void);
extern void FUN_08018654(void);
extern void FUN_0801fc60(void);
extern void FUN_0801f600(void);
extern void FUN_0801886c(u16 *, u8);
extern void VBlankIntrWait(void);
extern void IntrWait(u32, u32);
extern void FUN_08018c3c(void);
extern void FUN_08018678(u32);
extern void FUN_08018a8c(void);
extern void FUN_0801f60c(void);
extern void FUN_0801fbd8(void);
extern void FUN_0801ffa4(u32);

void FUN_08018444(void) {
    u8 i;
    u8 j;

    gUnknown_0300138c = 1;
    gUnknown_03003290 = 0;
    FUN_08018678(0);
    for (i = 0; i <= 7; i++) {
        gUnknown_03001b10[i] = 0;
        for (j = 0; j <= 3; j++) {
            gUnknown_030016f0[j][i] = 0;
        }
    }
    gUnknown_03001730 = 0;
    gUnknown_030017c4 = 0;
    gUnknown_03001380 = 0xff;
}

void FUN_080184c8(void) {
    FUN_08018c3c();
    gUnknown_0300138c = 0;
    gUnknown_03003290 = 0;
    {
        volatile u32 *dma = (volatile u32 *)0x040000d4;
        dma[0] = 0x08071184;
        dma[1] = (u32)gUnknown_03003150;
        dma[2] = 0x8000000a;
        dma[2];
        dma[0] = 0x08000104;
        dma[1] = (u32)gUnknown_030032a0;
        dma[2] = 0x80000070;
        dma[2];
    }
    gUnknown_03007ffc = (u32)gUnknown_030032a0;
    gUnknown_03001380 = 0;
}

void FUN_08018530(void) {
    u8 i;
    u8 j;

    for (i = 0; i <= 7; i++) {
        gUnknown_03001b10[i] = 0;
        for (j = 0; j <= 3; j++) {
            gUnknown_030016f0[j][i] = 0;
        }
    }
}

void FUN_0801856c(void) {
    FUN_0801886c(gUnknown_03001b10, gUnknown_03003290);
    if ((gUnknown_03001730 & 0x180) != 0x100) {
        VBlankIntrWait();
    } else {
        IntrWait(1, 0x80);
    }
}

void FUN_080185a8(void) {
    FUN_0801694c();
    FUN_08017eec();
    FUN_0801ff30();
    FUN_08017690();
    FUN_08017fb0();
    gUnknown_030013a0 = 0;
}

void FUN_080185cc(void) { FUN_08018654(); }

void FUN_080185d8(void) {
    if (gUnknown_0300138c != 0) {
        FUN_08018a8c();
    }
    FUN_0801f60c();
    gUnknown_03001378++;
    gUnknown_03007ff8 |= 1;
    if (gUnknown_030013a0 != 0) {
        FUN_0801694c();
        FUN_08017eec();
        FUN_0801ff30();
        FUN_08017690();
        FUN_08017fb0();
        gUnknown_030013a0 = 0;
    }
    FUN_0801fbd8();
    FUN_0801ffa4(0);
    gUnknown_03002610++;
}

void FUN_08018654(void) {
    FUN_0801fc60();
    FUN_0801f600();
}

void FUN_08018664(void) {}

void FUN_08018668(void) { *(volatile u16 *)0x03007ff8 |= 1; }
