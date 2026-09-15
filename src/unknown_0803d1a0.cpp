// Four-callback menu scene; C++ reconstruction fallback, retail language unknown.
#include "types.h"
struct Dma {
    const void *source;
    void *destination;
    u32 control;
};
extern "C" {
extern u32 gUnknown_03005254;
extern u8 gUnknown_030017cc, gUnknown_030017c8, gUnknown_03001388, gUnknown_03002110[];
extern s16 gUnknown_03001b08;
extern void (*gUnknown_03002030)(void);
extern const u8 gUnknown_083e7714[];
extern const u8 gUnknown_083eb4f4[];
extern const u8 gUnknown_083e64b4[];
extern const u8 gUnknown_083e6ef4[];
extern const u8 gUnknown_083e45f4[];
extern const u8 gUnknown_083e5c94[];
extern const u8 gUnknown_083f05d4[];
extern const u8 gUnknown_083f0df4[];
extern const u8 gUnknown_083ebd14[];
extern const u8 gUnknown_083ec934[];
extern const u8 gUnknown_083ed554[];
extern const u8 gUnknown_083ee174[];
extern const u8 gUnknown_083eed94[];
extern const u8 gUnknown_083ef9b4[];
u32 FUN_0802067c(u16 *, u16);
void FUN_08016078(u32), FUN_080184c8(void), FUN_08018530(void), FUN_08017cb0(void),
    FUN_08017cd8(void), FUN_08017cf4(void);
void CpuFastSet(const void *, void *, u32), FUN_0801fba0(u16, u16),
    FUN_080183d0(u8, u8, u8, u8, u8, u8), FUN_0801f638(void), FUN_0803d510(void);
extern u16 gUnknown_030048e0[];
extern const u16 gUnknown_083e43f4[], gUnknown_083ebcf4[];
void FUN_08017ed0(void), FUN_0801ff30(void), FUN_08017690(void), FUN_08017c5c(void);
void FUN_08018004(u16, u16, u8, u16, u8, u8, u8, u8, u8);
u8 FUN_08020500(u16 *, const u16 *, u16);
u32 FUN_080206ec(u16 *, u16);
void FUN_08000210(void), FUN_0803d408(void), FUN_0803d63c(void);

void FUN_0803d1a0(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_08016078(1);
        gUnknown_03005254 = 0;
        FUN_080184c8();
        FUN_08018530();
        FUN_08017cb0();
        FUN_08017cd8();
        FUN_08017cf4();
        gUnknown_030017cc = 0;
        gUnknown_030017c8 = 0;
        gUnknown_03001388 = 0;
        u32 firstZero = 0;
        CpuFastSet(&firstZero, (void *)0x05000000, 0x01000100);
        u32 secondZero = 0;
        CpuFastSet(&secondZero, (void *)0x05000200, 0x01000100);
        FUN_0801fba0(0, 0x1740);
        volatile Dma *dma = (volatile Dma *)0x040000d4;
        dma->source = gUnknown_083e7714;
        dma->destination = (void *)0x06000000;
        dma->control = 0x80001ef0;
        (void)dma->control;
        dma->source = gUnknown_083eb4f4;
        dma->destination = (void *)0x06007800;
        u32 blockSize = 0x80000400;
        dma->control = blockSize;
        (void)dma->control;
        dma->source = gUnknown_083e64b4;
        dma->destination = (void *)0x06008000;
        dma->control = 0x80000520;
        (void)dma->control;
        dma->source = gUnknown_083e6ef4;
        dma->destination = (void *)0x0600b800;
        dma->control = blockSize;
        (void)dma->control;
        dma->source = gUnknown_083e45f4;
        dma->destination = (void *)0x0600c000;
        dma->control = 0x80000b50;
        (void)dma->control;
        dma->source = gUnknown_083e5c94;
        dma->destination = (void *)0x0600f800;
        dma->control = blockSize;
        (void)dma->control;
        *(volatile u16 *)0x0400000c = 0x0f43;
        *(volatile u16 *)0x0400000a = 0x174b;
        *(volatile u16 *)0x04000008 = 0x1f4f;
        *(volatile u16 *)0x04000010 = 0;
        *(volatile u16 *)0x04000012 = 0;
        *(volatile u16 *)0x04000014 = 0;
        *(volatile u16 *)0x04000016 = 0;
        *(volatile u16 *)0x04000018 = 0;
        *(volatile u16 *)0x0400001a = 0;
        *(volatile u16 *)0x0400001c = 0;
        *(volatile u16 *)0x0400001e = 0;
        if (!gUnknown_03002110[119])
            dma->source = gUnknown_083f05d4;
        else
            dma->source = gUnknown_083f0df4;
        dma->destination = (void *)0x06011000;
        dma->control = blockSize;
        (void)dma->control;
        volatile Dma *endDma;
        switch (gUnknown_03002110[119]) {
        case 0:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083ebd14;
            break;
        case 1:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083ec934;
            break;
        case 2:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083ed554;
            break;
        case 3:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083ee174;
            break;
        case 4:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083eed94;
            break;
        case 5:
            endDma = (volatile Dma *)0x040000d4;
            endDma->source = gUnknown_083ef9b4;
            break;
        default:
            goto paletteDone;
        }
        endDma->destination = (void *)0x06010000;
        endDma->control = 0x80000600;
        (void)endDma->control;
    paletteDone:
        FUN_080183d0(1, 2, 4, 8, 8, 0);
        FUN_0801f638();
        gUnknown_03002030 = FUN_0803d510;
        gUnknown_03001b08 = 0;
    }
}
void FUN_0803d408(void) {
    gUnknown_03001b08 += 2;
    if (gUnknown_03001b08 > 255)
        gUnknown_03001b08 -= 256;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(0, 0, 0, 128, 0, 0, 117, 0, 0);
    FUN_08018004(64, 0, 0, 160, 0, 0, 117, 0, 0);
    FUN_08018004(32, 112, 0, 0, 0, 0, 117, 0, 0);
    FUN_08018004(96, 112, 0, 32, 0, 0, 117, 0, 0);
    FUN_08018004(160, 112, 0, 64, 0, 0, 117, 0, 0);
    FUN_08018004(224, 112, 0, 96, 0, 0, 117, 0, 0);
    FUN_08017690();
    FUN_08017c5c();
    FUN_080183d0(1, 2, 4, 8, 8, 0);
    register u16 pressed asm("r1") = gUnknown_030048e0[0];
    if ((pressed & 8) || (pressed & 1) || (pressed & 2))
        gUnknown_03002030 = FUN_0803d63c;
    *(volatile u16 *)0x04000018 = gUnknown_03001b08;
}
void FUN_0803d510(void) {
    u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_083e43f4, 256) == 0;
    u32 pending = initial;
    asm("" : "+r"(pending));
    u32 result;
    if (!FUN_08020500((u16 *)0x05000200, gUnknown_083ebcf4, 256)) {
        result = 1;
        asm("" : : "r"(result));
    } else {
        result = (u8)pending;
        asm("" : "+r"(result));
        if (!result)
            gUnknown_03002030 = FUN_0803d408;
    }
    gUnknown_03001b08 += 2;
    if (gUnknown_03001b08 > 255)
        gUnknown_03001b08 -= 256;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(0, 0, 0, 128, 0, 0, 117, 0, 0);
    FUN_08018004(64, 0, 0, 160, 0, 0, 117, 0, 0);
    FUN_08018004(32, 112, 0, 0, 0, 0, 117, 0, 0);
    FUN_08018004(96, 112, 0, 32, 0, 0, 117, 0, 0);
    FUN_08018004(160, 112, 0, 64, 0, 0, 117, 0, 0);
    FUN_08018004(224, 112, 0, 96, 0, 0, 117, 0, 0);
    FUN_08017690();
    FUN_08017c5c();
    FUN_080183d0(1, 2, 4, 8, 8, 0);
    *(volatile u16 *)0x04000018 = gUnknown_03001b08;
}
void FUN_0803d63c(void) {
    gUnknown_03001b08 += 2;
    if (gUnknown_03001b08 > 255)
        gUnknown_03001b08 -= 256;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(0, 0, 0, 128, 0, 0, 117, 0, 0);
    FUN_08018004(64, 0, 0, 160, 0, 0, 117, 0, 0);
    FUN_08018004(32, 112, 0, 0, 0, 0, 117, 0, 0);
    FUN_08018004(96, 112, 0, 32, 0, 0, 117, 0, 0);
    FUN_08018004(160, 112, 0, 64, 0, 0, 117, 0, 0);
    FUN_08018004(224, 112, 0, 96, 0, 0, 117, 0, 0);
    FUN_08017690();
    FUN_08017c5c();
    FUN_080183d0(1, 2, 4, 8, 8, 0);
    if ((u8)FUN_080206ec((u16 *)0x05000000, 512)) {
        FUN_080183d0(0, 0, 0, 0, 0, 0);
        gUnknown_03002030 = FUN_08000210;
    }
    *(volatile u16 *)0x04000018 = gUnknown_03001b08;
}
}
