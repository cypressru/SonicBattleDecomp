#include "types.h"

// Inferred complete intro callback TU. See docs/intro-3d748-tu-cpp.md.
extern "C" {
extern u8 gUnknown_030017cc, gUnknown_030017c8, gUnknown_03001388;
extern s16 gUnknown_030016bc, gUnknown_03001b2c, gUnknown_030016c0, gUnknown_03001374,
    gUnknown_03001b08;
extern const s16 gUnknown_08172a3c[20], gUnknown_08172a64[10];
extern void (*gUnknown_03002030)(void);
void FUN_08016078(u32), FUN_08017cb0(void), FUN_08017cd8(void), FUN_08017cf4(void),
    FUN_0801fba0(u16, u16), CpuFastSet(const void *, void *, u32),
    FUN_080183d0(u8, u8, u8, u8, u8, u8), FUN_0801f638(void), FUN_0801f618(u16), FUN_0803d860(void);
void FUN_0803d748(void) {
    FUN_08016078(1);
    FUN_08017cb0();
    FUN_08017cd8();
    FUN_08017cf4();
    gUnknown_030017cc = 0;
    gUnknown_030017c8 = 0;
    gUnknown_03001388 = 0;
    FUN_0801fba0(0, 0x541);
    u32 zero = 0;
    CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
    *(volatile u16 *)0x04000008 = 0;
    *(volatile u16 *)0x0400000a = 0;
    *(volatile u16 *)0x0400000c = 0;
    *(volatile u16 *)0x0400000e = 0;
    *(volatile u16 *)0x0400000c = 0x5782;
    *(volatile u16 *)0x04000008 = 0x1f0d;
    *(volatile u16 *)0x04000010 = 0;
    *(volatile u16 *)0x04000012 = 0;
    *(volatile u16 *)0x04000014 = 0;
    *(volatile u16 *)0x04000016 = 0;
    *(volatile u16 *)0x04000018 = 0;
    *(volatile u16 *)0x0400001a = 0;
    *(volatile u16 *)0x0400001c = 0;
    *(volatile u16 *)0x0400001e = 0;
    FUN_080183d0(0, 0, 0, 0, 0, 0);
    gUnknown_030016bc = 255;
    gUnknown_03001b2c = gUnknown_08172a3c[0];
    gUnknown_030016c0 = gUnknown_08172a3c[1];
    gUnknown_03001374 = gUnknown_08172a64[0];
    gUnknown_03001b08 = -1;
    FUN_0801f638();
    FUN_0801f618(0);
    gUnknown_03002030 = FUN_0803d860;
}

struct Dma {
    const void *source;
    void *destination;
    u32 control;
};
extern s16 gUnknown_030016bc, gUnknown_03001b08, gUnknown_03001b2c, gUnknown_030016c0,
    gUnknown_03001374, gUnknown_03001b24, gUnknown_03002100, gUnknown_03001b04, gUnknown_030016c8;
extern u16 gUnknown_030048e0[];
extern const s16 gUnknown_08172a3c[20], gUnknown_08172a64[10];
#define gUnknown_08172a50 (gUnknown_08172a3c + 10)
#define gUnknown_08172a6e (gUnknown_08172a64 + 5)
extern void (*gUnknown_03002030)(void);
extern const u8 gUnknown_083f4418[];
extern const u8 gUnknown_083f4618[];
extern const u8 gUnknown_083f8518[];
extern const u8 gUnknown_08409038[];
extern const u8 gUnknown_084093d8[];
extern const u8 gUnknown_083f8918[];
extern const u8 gUnknown_083f8b18[];
extern const u8 gUnknown_083fca98[];
extern const u8 gUnknown_08409bf8[];
extern const u8 gUnknown_0840a418[];
extern const u8 gUnknown_083fce98[];
extern const u8 gUnknown_083fd098[];
extern const u8 gUnknown_08400e18[];
extern const u8 gUnknown_0840ac38[];
extern const u8 gUnknown_0840b318[];
extern const u8 gUnknown_08401218[];
extern const u8 gUnknown_08401418[];
extern const u8 gUnknown_08404cd8[];
extern const u8 gUnknown_0840bb38[];
extern const u8 gUnknown_0840bf38[];
extern const u8 gUnknown_084050d8[];
extern const u8 gUnknown_084052d8[];
extern const u8 gUnknown_08408c18[];
extern const u8 gUnknown_0840c758[];
extern const u8 gUnknown_0840ccd8[];
void FUN_0803dd14(void), FUN_0803e1b0(void), CpuFastSet(const void *, void *, u32);
void FUN_0803d860(void) {

    if (gUnknown_030016bc > 12) {

        ++gUnknown_03001b08;
        switch (gUnknown_03001b08) {
        case 0: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083f4418;
            dma->destination = (void *)0x5000000;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083f4618;
            dma->destination = (void *)0x6000000;
            dma->control = 0x80001f80;
            (void)dma->control;
            dma->source = gUnknown_083f8518;
            dma->destination = (void *)0x600b800;
            dma->control = 0x80000200;
            (void)dma->control;
            dma->source = gUnknown_08409038;
            dma->destination = (void *)0x600c000;
            dma->control = 0x800001d0;
            (void)dma->control;
            dma->source = gUnknown_084093d8;
            dma->destination = (void *)0x600f800;
            dma->control = 0x80000400;
            (void)dma->control;
            break;
        }
        case 1: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083f8918;
            dma->destination = (void *)0x5000000;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083f8b18;
            dma->destination = (void *)0x6000000;
            dma->control = 0x80001fc0;
            (void)dma->control;
            dma->source = gUnknown_083fca98;
            dma->destination = (void *)0x600b800;
            dma->control = 0x80000400;
            (void)dma->control;
            dma->source = gUnknown_08409bf8;
            dma->destination = (void *)0x600c000;
            dma->control = 0x80000410;
            (void)dma->control;
            dma->source = gUnknown_0840a418;
            dma->destination = (void *)0x600f800;
            dma->control = 0x80000400;
            (void)dma->control;
            break;
        }
        case 2: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083fce98;
            dma->destination = (void *)0x5000000;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083fd098;
            dma->destination = (void *)0x6000000;
            dma->control = 0x80001ec0;
            (void)dma->control;
            dma->source = gUnknown_08400e18;
            dma->destination = (void *)0x600b800;
            dma->control = 0x80000400;
            (void)dma->control;
            dma->source = gUnknown_0840ac38;
            dma->destination = (void *)0x600c000;
            dma->control = 0x80000370;
            (void)dma->control;
            dma->source = gUnknown_0840b318;
            dma->destination = (void *)0x600f800;
            dma->control = 0x80000400;
            (void)dma->control;
            break;
        }
        case 3: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08401218;
            dma->destination = (void *)0x5000000;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_08401418;
            dma->destination = (void *)0x6000000;
            dma->control = 0x80001c60;
            (void)dma->control;
            dma->source = gUnknown_08404cd8;
            dma->destination = (void *)0x600b800;
            dma->control = 0x80000400;
            (void)dma->control;
            dma->source = gUnknown_0840bb38;
            dma->destination = (void *)0x600c000;
            dma->control = 0x80000200;
            (void)dma->control;
            dma->source = gUnknown_0840bf38;
            dma->destination = (void *)0x600f800;
            dma->control = 0x80000400;
            (void)dma->control;
            break;
        }
        case 4: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_084050d8;
            dma->destination = (void *)0x5000000;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_084052d8;
            dma->destination = (void *)0x6000000;
            dma->control = 0x80001ca0;
            (void)dma->control;
            dma->source = gUnknown_08408c18;
            dma->destination = (void *)0x600b800;
            dma->control = 0x80000400;
            (void)dma->control;
            dma->source = gUnknown_0840c758;
            dma->destination = (void *)0x600c000;
            dma->control = 0x800002c0;
            (void)dma->control;
            dma->source = gUnknown_0840ccd8;
            dma->destination = (void *)0x600f800;
            dma->control = 0x80000400;
            (void)dma->control;
            break;
        }
        }
        gUnknown_030016bc = 0;

        s16 *initialX = &gUnknown_03001b2c;
        const u8 *initialPositions = (const u8 *)&gUnknown_08172a3c;
        *initialX = *(const s16 *)(initialPositions + gUnknown_03001b08 * 4);

        s16 *initialY = &gUnknown_030016c0;
        s32 initialOffset = gUnknown_03001b08 * 4;
        initialPositions += 2;
        *initialY = *(const s16 *)(initialPositions + initialOffset);

        gUnknown_03001374 = gUnknown_08172a64[gUnknown_03001b08];
    } else {
        ++gUnknown_030016bc;

        if (gUnknown_03001b08 > 3 && gUnknown_030016bc > 7) {
            gUnknown_030016bc = -1;
            gUnknown_03001b08 = -1;
            gUnknown_03001b24 = 1;
            gUnknown_03002100 = 256;
            gUnknown_03002030 = FUN_0803dd14;
        }
    }
    s32 currentX = gUnknown_03001b2c;
    const u8 *targetPositions = (const u8 *)&gUnknown_08172a3c + 20;
    gUnknown_03001b2c -= (currentX - *(const s16 *)(targetPositions + gUnknown_03001b08 * 4)) >> 2;
    s32 currentY = gUnknown_030016c0;
    s32 targetOffset = gUnknown_03001b08 * 4;
    targetPositions += 2;
    gUnknown_030016c0 -= (currentY - *(const s16 *)(targetPositions + targetOffset)) >> 2;
    s32 currentScroll = gUnknown_03001374;
    const s16 *scrollTargets = gUnknown_08172a6e;
    s32 delta = (currentScroll - scrollTargets[gUnknown_03001b08]) >> 2;
    u32 scrollValue = (u16)gUnknown_03001374 - delta;
    gUnknown_03001374 = scrollValue;
    u32 identity = 256;
    u32 cleared = 0;
    s32 affineX = ((120 - gUnknown_03001b2c) << 8) - 0x7800;
    s32 affineY = ((120 - gUnknown_030016c0) << 8) - 0x5000;
    *(volatile u16 *)0x04000020 = identity;
    *(volatile u16 *)0x04000022 = cleared;
    *(volatile u16 *)0x04000024 = cleared;
    *(volatile u16 *)0x04000026 = identity;
    volatile u16 *lowReg = (volatile u16 *)0x04000028;
    register s32 resetInitial asm("r3") = -1;
    asm("" : "+r"(resetInitial));
    s32 reset = resetInitial;
    *lowReg = affineX;
    *(volatile u16 *)0x0400002a = (affineX & 0x0fff0000) >> 16;
    *(volatile u16 *)0x0400002c = affineY;
    *(volatile u16 *)0x0400002e = (affineY & 0x0fff0000) >> 16;
    *(volatile u16 *)0x04000012 = scrollValue;
    if (gUnknown_030048e0[0] & 8) {
        register s16 *resetTimer asm("r0");
        asm("" : "=r"(resetTimer) : "0"(&gUnknown_030016bc));
        *resetTimer = reset;
        gUnknown_03001b08 = reset;
        gUnknown_03001374 = 0;
        gUnknown_03001b2c = 0;
        gUnknown_030016c0 = 0;
        gUnknown_03001b04 = 0;
        gUnknown_030016c8 = 0;
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        u32 secondZero = 0;
        CpuFastSet(&secondZero, (void *)0x05000200, 0x01000100);
        gUnknown_03002030 = FUN_0803e1b0;
    }
}

extern s16 gUnknown_030016bc, gUnknown_03001b08, gUnknown_03001b2c, gUnknown_030016c0,
    gUnknown_03001b04, gUnknown_030016c8, gUnknown_03001b24, gUnknown_03002100, gUnknown_03001374;
extern u16 gUnknown_030048e0[];
extern const s16 gUnknown_0804df7c[];
extern void (*gUnknown_03002030)(void);
extern const u8 gUnknown_0840d4d8[];
extern const u8 gUnknown_0840d6d8[];
extern const u8 gUnknown_0840f318[];
extern const u8 gUnknown_0840f918[];
extern const u8 gUnknown_08411458[];
extern const u8 gUnknown_08411a58[];
extern const u8 gUnknown_08413698[];
extern const u8 gUnknown_08413c98[];
extern const u8 gUnknown_08415998[];
extern const u8 gUnknown_08415f98[];
extern const u8 gUnknown_08417bd8[];
extern const u8 gUnknown_084181d8[];
extern const u8 gUnknown_08419e18[];
void FUN_0801fba0(u16, u16), CpuFastSet(const void *, void *, u32), FUN_0803e1b0(void);
s32 DivArm(s32, s32);
void FUN_0803dd14(void) {
    ++gUnknown_030016bc;
    ++gUnknown_03001b08;
    if (!gUnknown_030016bc) {
        FUN_0801fba0(0, 0x441);
        *(volatile u16 *)0x0400000c = 0x5782;
        gUnknown_03001b2c = -8;
        gUnknown_030016c0 = 30;
        gUnknown_03001b04 = -8;
        gUnknown_030016c8 = 30;
    }
    if (gUnknown_03001b08 > 11)
        gUnknown_03001b08 = 0;
    switch (gUnknown_03001b08) {
    case 0: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_0840d4d8;
        dma->destination = (void *)0x5000000;
        dma->control = 0x80000100;
        (void)dma->control;
        dma->source = gUnknown_0840d6d8;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000e20;
        (void)dma->control;
        dma->source = gUnknown_0840f318;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        break;
    }
    case 2: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_0840f918;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000da0;
        (void)dma->control;
        dma->source = gUnknown_08411458;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        break;
    }
    case 4: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_08411a58;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000e20;
        (void)dma->control;
        dma->source = gUnknown_08413698;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        --gUnknown_030016c8;
        break;
    }
    case 6: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_08413c98;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000e80;
        (void)dma->control;
        dma->source = gUnknown_08415998;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        break;
    }
    case 8: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_08415f98;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000e20;
        (void)dma->control;
        dma->source = gUnknown_08417bd8;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        break;
    }
    case 10: {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_084181d8;
        dma->destination = (void *)0x6000000;
        dma->control = 0x80000e20;
        (void)dma->control;
        dma->source = gUnknown_08419e18;
        dma->destination = (void *)0x600b800;
        dma->control = 0x80000200;
        (void)dma->control;
        --gUnknown_030016c8;
        break;
    }
    }
    gUnknown_03001b2c -= (gUnknown_03001b2c - gUnknown_03001b04) >> 2;
    gUnknown_030016c0 -= (gUnknown_030016c0 - gUnknown_030016c8) >> 2;
    gUnknown_03001b24 -= (gUnknown_03001b24 - gUnknown_03002100) >> 2;
    if (gUnknown_030016bc == 60)
        gUnknown_03002100 = 320;
    else if (gUnknown_030016bc == 75) {
        gUnknown_03002100 = 176;
        gUnknown_03001b04 = 54;
        gUnknown_030016c8 = -24;
    } else if (gUnknown_030016bc == 90) {
        gUnknown_030016bc = -1;
        gUnknown_03001b08 = -1;
        gUnknown_03001374 = 0;
        gUnknown_03001b2c = 0;
        gUnknown_030016c0 = 0;
        gUnknown_03001b04 = 0;
        gUnknown_030016c8 = 0;
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        u32 zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000200, 0x01000100);
        gUnknown_03002030 = FUN_0803e1b0;
    }
    register s32 scale asm("r0") = gUnknown_03001b24;
    s32 cosine = gUnknown_0804df7c[0x800] << 3;
    register u32 raw = DivArm(scale, cosine);
    register u32 pa asm("r10") = raw;
    asm("" : "+r"(pa));
    register u32 narrow asm("r3") = pa;
    asm("" : : "r"(narrow));
    narrow = (u16)narrow;

    pa = narrow;
    scale = gUnknown_03001b24;
    s32 sine = gUnknown_0804df7c[0] << 3;
    asm("" : : "r"(narrow));
    raw = DivArm(scale, sine);
    register u32 pb asm("r9") = raw;
    asm("" : "+r"(pb));
    narrow = pb;
    asm("" : : "r"(narrow));
    narrow = (u16)narrow;

    pb = narrow;
    scale = gUnknown_03001b24;
    asm("" : : "r"(narrow));
    u16 pc = -DivArm(scale, sine);
    u16 pd = DivArm(gUnknown_03001b24, cosine);
    s32 dx = ((120 - gUnknown_03001b2c) << 8) - (s16)pa * 120 - (s16)pb * 80;
    s32 dy = ((120 - gUnknown_030016c0) << 8) - (s16)pc * 120 - (s16)pd * 80;
    *(volatile u16 *)0x04000020 = pa;
    *(volatile u16 *)0x04000022 = pb;
    *(volatile u16 *)0x04000024 = pc;
    *(volatile u16 *)0x04000026 = pd;
    volatile u16 *xLow = (volatile u16 *)0x04000028;

    register s32 resetValue asm("r1") = -1;
    asm("" : "+r"(resetValue));
    s32 savedReset = resetValue;
    *xLow = dx;
    *(volatile u16 *)0x0400002a = (dx & 0x0fff0000) >> 16;
    *(volatile u16 *)0x0400002c = dy;
    *(volatile u16 *)0x0400002e = (dy & 0x0fff0000) >> 16;
    if (gUnknown_030048e0[0] & 8) {
        gUnknown_030016bc = savedReset;
        gUnknown_03001b08 = savedReset;
        gUnknown_03001374 = 0;
        gUnknown_03001b2c = 0;
        gUnknown_030016c0 = 0;
        gUnknown_03001b04 = 0;
        gUnknown_030016c8 = 0;
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        u32 zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000200, 0x01000100);
        gUnknown_03002030 = FUN_0803e1b0;
    }
}

typedef unsigned long long u64;
union MatrixWords {
    // Synthetic r0/r1 ABI carrier; all four fields are initialized before the
    // GNU union-representation read. See the TU notes for consumer evidence.
    struct {
        s16 pa;
        s16 pb;
        s16 pc;
        s16 pd;
    } values;
    u64 packed;
};
extern s16 gUnknown_030016bc, gUnknown_03001b08, gUnknown_03001b2c, gUnknown_030016c0,
    gUnknown_03001b04, gUnknown_030016c8, gUnknown_03001b24, gUnknown_03002100, gUnknown_03001374;
extern u8 gUnknown_03002110[];
extern u16 gUnknown_030048e0[];
extern const s16 gUnknown_0804df7c[];
extern void (*gUnknown_03002030)(void);
extern const u8 gUnknown_0841a418[];
extern const u8 gUnknown_0841dbd8[];
extern const u8 gUnknown_0841e5d8[];
extern const u8 gUnknown_08421f18[];
extern const u8 gUnknown_08423fd8[];
extern const u8 gUnknown_084245d8[];
extern const u8 gUnknown_08424df8[];
extern const u8 gUnknown_084253f8[];
extern const u8 gUnknown_08425c18[];
extern const u8 gUnknown_08426038[];
extern const u8 gUnknown_08422738[];
extern const u8 gUnknown_08426858[];
extern const u8 gUnknown_08422718[];
extern const u8 gUnknown_08426838[];
extern const u8 gUnknown_0841a218[];
void FUN_0801fba0(u16, u16), FUN_08017ed0(void), FUN_0801ff30(void), FUN_08017690(void),
    FUN_08017fb0(void), FUN_08017c5c(void), FUN_0803e6e8(void), FUN_0803e74c(void);
void FUN_08018004(u16, u16, u8, u16, u8, u8, u8, u8, u8);
void FUN_08017f34(u64);
void FUN_0801f618(u16), FUN_0801f718(u16, u16);
s32 DivArm(s32, s32);
void FUN_0803e1b0(void) {
    ++gUnknown_030016bc;
    ++gUnknown_03001b08;
    if (gUnknown_030016bc == 0) {
        FUN_0801fba0(0, 0x40);
        *(volatile u16 *)0x04000008 = 0x0f07;
        *(volatile u16 *)0x0400000a = 0x170b;
        *(volatile u16 *)0x0400000c = 0x1f0f;
        *(volatile u16 *)0x0400000e = 0x1e81;
        if (!gUnknown_03002110[119]) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0841a418;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80001be0;
            (void)dma->control;
            dma->source = gUnknown_0841dbd8;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000400;
            (void)dma->control;
        } else {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0841e5d8;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80001ca0;
            (void)dma->control;
            dma->source = gUnknown_08421f18;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000400;
            (void)dma->control;
        }
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_08423fd8;
        dma->destination = (void *)0x06004000;
        dma->control = 0x80000300;
        (void)dma->control;
        dma->source = gUnknown_084245d8;
        dma->destination = (void *)0x06007800;
        dma->control = 0x80000400;
        (void)dma->control;
        dma->source = gUnknown_08424df8;
        dma->destination = (void *)0x06008000;
        dma->control = 0x80000300;
        (void)dma->control;
        dma->source = gUnknown_084253f8;
        dma->destination = (void *)0x0600b800;
        dma->control = 0x80000400;
        (void)dma->control;
        dma->source = gUnknown_08425c18;
        dma->destination = (void *)0x0600c000;
        dma->control = 0x80000210;
        (void)dma->control;
        dma->source = gUnknown_08426038;
        dma->destination = (void *)0x0600f800;
        dma->control = 0x80000400;
        (void)dma->control;
        gUnknown_03001b2c = -16;
        gUnknown_030016c0 = 0;
        s16 *targetX = &gUnknown_03001b04;
        s16 *targetY = &gUnknown_030016c8;
        gUnknown_03001b24 = 256;
        gUnknown_03002100 = 256;
        *(volatile u16 *)0x400001c = 0;
        *(volatile u16 *)0x400001e = 0;
        *(volatile u16 *)0x4000020 = 256;
        *(volatile u16 *)0x4000022 = 0;
        *(volatile u16 *)0x4000024 = 0;
        *(volatile u16 *)0x4000026 = 256;
        *(volatile u16 *)0x4000028 = 0;
        *(volatile u16 *)0x400002a = 0;
        *(volatile u16 *)0x400002c = 0;
        *(volatile u16 *)0x400002e = 0;
        dma->source = gUnknown_08422738;
        dma->destination = (void *)0x06010000;
        dma->control = 0x80000c40;
        (void)dma->control;
        dma->source = gUnknown_08426858;
        dma->destination = (void *)0x06011000;
        dma->control = 0x80000800;
        (void)dma->control;
        *targetX = 36;
        *targetY = 0;
    } else if (gUnknown_030016bc == 1) {
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_08422718;
        dma->destination = (void *)0x05000200;
        dma->control = 0x80000010;
        (void)dma->control;
        dma->source = gUnknown_08426838;
        dma->destination = (void *)0x05000220;
        dma->control = 0x80000010;
        (void)dma->control;
        dma->source = gUnknown_0841a218;
        dma->destination = (void *)0x05000000;
        dma->control = 0x80000100;
        (void)dma->control;
        FUN_0801fba0(0, 8000);
    } else if (gUnknown_030016bc == 15)
        gUnknown_030016c8 = 40;
    if (gUnknown_03001b08 == 15) {
        if (++gUnknown_03001374 > 3) {
            gUnknown_03001374 = 0;
            gUnknown_03001b24 = 448;
        } else
            gUnknown_03001b24 = 352;
        gUnknown_03001b08 = 0;
        gUnknown_03002100 = 256;
    }
    gUnknown_03001b24 -= (gUnknown_03001b24 - gUnknown_03002100) >> 2;
    gUnknown_03001b2c -= (gUnknown_03001b2c - gUnknown_03001b04) >> 2;
    s16 *y = &gUnknown_030016c0;
    *y -= (*y - gUnknown_030016c8) >> 2;
    volatile u16 *scrollAddress = (volatile u16 *)0x04000018;
    u32 scroll = (u16)gUnknown_030016bc * 2;
    *scrollAddress = scroll;
    *(volatile u16 *)0x0400001a = -scroll;
    *(volatile u16 *)0x04000014 = -gUnknown_03001b2c;
    *(volatile u16 *)0x04000016 = 48 - *y;
    *(volatile u16 *)0x04000010 = gUnknown_03001b2c;
    *(volatile u16 *)0x04000012 = 48 + *y;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(32, 110, 0, 0, 0, 0, 106, 0, 0);
    FUN_08018004(88, 110, 0, 32, 0, 0, 106, 0, 0);
    FUN_08018004(0, 128, 0, 128, 1, 0, 117, 0, 0);
    FUN_08018004(64, 128, 0, 160, 1, 0, 117, 0, 0);
    FUN_08018004(128, 128, 0, 192, 1, 0, 117, 0, 0);
    FUN_08018004(192, 128, 0, 224, 1, 0, 117, 0, 0);
    MatrixWords matrix;
    register s32 scale asm("r0") = gUnknown_03001b24;
    const s16 *trig = gUnknown_0804df7c;
    s32 rawCosine = trig[0x800] << 3;
    s32 cosine = rawCosine;
    matrix.values.pa = DivArm(scale, cosine);
    scale = gUnknown_03001b24;
    s32 sine = trig[0] << 3;
    matrix.values.pb = DivArm(scale, sine);
    matrix.values.pc = -DivArm(gUnknown_03001b24, sine);
    matrix.values.pd = DivArm(gUnknown_03001b24, cosine);
    FUN_08017f34(matrix.packed);
    FUN_08017690();
    FUN_08017fb0();
    FUN_08017c5c();
    if ((gUnknown_030048e0[2] & 8) && gUnknown_030016bc > 80) {
        gUnknown_030016bc = 0;
        gUnknown_03001b2c = 0;
        *y = 0;
        gUnknown_03001b04 = 0;
        gUnknown_030016c8 = 0;
        gUnknown_03001b08 = 0;
        FUN_08017ed0();
        FUN_0801f618(404);
        FUN_0801f718(0, 120);
        gUnknown_03002030 = FUN_0803e6e8;
    } else if (gUnknown_030016bc > 600) {
        gUnknown_030016bc = 0;
        gUnknown_03001b2c = 0;
        gUnknown_030016c0 = 0;
        gUnknown_03001b04 = 0;
        gUnknown_030016c8 = 0;
        gUnknown_03001b08 = 0;
        FUN_08017ed0();
        gUnknown_03002030 = FUN_0803e74c;
    }
}

extern void (*gUnknown_03002030)(void);
extern u8 gUnknown_03005380;
u32 FUN_0802067c(u16 *, u16);
void FUN_080183d0(u8, u8, u8, u8, u8, u8), CpuFastSet(const void *, void *, u32),
    FUN_0801fba0(u16, u16), FUN_08036560(void), FUN_0801c930(void);
void FUN_0803e6e8(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 256)) {
        FUN_080183d0(0, 0, 0, 0, 0, 0);
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        gUnknown_03002030 = FUN_08036560;
        gUnknown_03005380 = 0;
        FUN_0801fba0(0, 8000);
    }
}
void FUN_0803e74c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 256)) {
        FUN_080183d0(0, 0, 0, 0, 0, 0);
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        gUnknown_03002030 = FUN_0801c930;
        FUN_0801fba0(0, 8000);
    }
}

extern const s16 gUnknown_08172a3c[20] = {120, 65, -50, 55, 70, 65, -80, 30, 0, 60,
                                          80,  60, 0,   60, 20, 60, -30, 40, 0, 60};
extern const s16 gUnknown_08172a64[10] = {40, 20, 30, -10, 30, 30, 30, 20, 0, 30};
}
