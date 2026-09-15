#include "types.h"

// Ending sequences: C++ reconstruction fallback; original language is unknown.
// Address-based names are synthetic linkage, not recovered retail symbols.
struct Dma {
    const void *source;
    void *destination;
    u32 control;
};

extern "C" {
// Shared engine, save, and ending-dispatch state; this TU owns no BSS.
extern u8 gUnknown_03001388, gUnknown_030017c8, gUnknown_030017cc;
extern u8 gUnknown_03005428, gUnknown_03002110[];
extern s16 gUnknown_03001374, gUnknown_030016bc, gUnknown_030016c0;
extern s16 gUnknown_03001b04, gUnknown_03001b08, gUnknown_03001b24, gUnknown_03001b2c;
extern u16 gUnknown_030048e0[], gUnknown_03005424;
extern void (*gUnknown_03002030)(void);

// External opaque graphics, tilemaps, and palettes; no asset bytes reproduced.
extern const u8 gUnknown_08335f74[];
extern const u8 gUnknown_08335f94[];
extern const u8 gUnknown_08336fb4[];
extern const u8 gUnknown_083386b4[];
extern const u8 gUnknown_083396d4[];
extern const u8 gUnknown_0833b7b4[];
extern const u8 gUnknown_0833c7d4[];
extern const u8 gUnknown_0833e914[];
extern const u8 gUnknown_0833f934[];
extern const u8 gUnknown_08341a34[];
extern const u8 gUnknown_08342a54[];
extern const u8 gUnknown_08344514[];
extern const u8 gUnknown_08345534[];
extern const u8 gUnknown_08346994[];
extern const u8 gUnknown_083479b4[];
extern const u8 gUnknown_08349934[];
extern const u8 gUnknown_0834a954[];
extern const u8 gUnknown_0834c814[];
extern const u8 gUnknown_0834d834[];
extern const u8 gUnknown_0834f814[];
extern const u8 gUnknown_08350834[];
extern const u8 gUnknown_08352574[];
extern const u8 gUnknown_08353594[];
extern const u8 gUnknown_08355594[];
extern const u8 gUnknown_083565b4[];
extern const u8 gUnknown_08358a74[];
extern const u8 gUnknown_08359a94[];
extern const u8 gUnknown_0835be54[];
extern const u8 gUnknown_0835ce74[];
extern const u8 gUnknown_0835e454[];
extern const u8 gUnknown_08361074[];
extern const u8 gUnknown_08361094[];
extern const u8 gUnknown_08362134[];
extern const u8 gUnknown_08363154[];
extern const u8 gUnknown_08363774[];
extern const u8 gUnknown_08364794[];
extern const u8 gUnknown_08364a74[];
extern const u8 gUnknown_08365a74[];
extern const u8 gUnknown_08365c74[];
extern const u8 gUnknown_0836bc74[];
extern const u8 gUnknown_0836be74[];
extern const u8 gUnknown_08371e74[];
extern const u8 gUnknown_08372074[];
extern const u8 gUnknown_08378074[];
extern const u8 gUnknown_08378274[];
extern const u8 gUnknown_0837e274[];
extern const u8 gUnknown_0837e474[];
extern const u8 gUnknown_08384474[];
extern const u8 gUnknown_08384674[];
extern const u8 gUnknown_0838a674[];
extern const u8 gUnknown_0838a874[];
extern const u8 gUnknown_08390874[];
extern const u8 gUnknown_08390a74[];
extern const u8 gUnknown_08396a74[];
extern const u8 gUnknown_08396c74[];
extern const u8 gUnknown_0839cc74[];
extern const u8 gUnknown_0839ce74[];
extern const u8 gUnknown_083a2e74[];
extern const u8 gUnknown_083a3074[];
extern const u8 gUnknown_083a9074[];
extern const u8 gUnknown_083a9274[];
extern const u8 gUnknown_083af274[];
extern const u8 gUnknown_083af474[];
extern const u8 gUnknown_083b5474[];
extern const u8 gUnknown_083b5674[];
extern const u8 gUnknown_083bb674[];
extern const u8 gUnknown_083bb874[];
extern const u8 gUnknown_083c1874[];
extern const u8 gUnknown_083c1a74[];
extern const u8 gUnknown_083c7a74[];
extern const u8 gUnknown_083c7c74[];
extern const u8 gUnknown_083cdc74[];
extern const u8 gUnknown_083cde74[];
extern const u8 gUnknown_083d3e74[];
extern const u8 gUnknown_083d3e94[];
extern const u8 gUnknown_083d5e94[];
extern const u8 gUnknown_083d5eb4[];
extern const u8 gUnknown_083d7eb4[];
extern const u8 gUnknown_083d7ed4[];
extern const u8 gUnknown_083d9ed4[];
extern const u8 gUnknown_083d9ef4[];
extern const u8 gUnknown_083dbef4[];
extern const u8 gUnknown_083dbf14[];
extern const u8 gUnknown_083ddf14[];
extern const u8 gUnknown_083ddf34[];

void CpuFastSet(const void *, void *, u32);
void FUN_08000210(void), FUN_08016078(u32), FUN_08017690(void);
void FUN_08017c5c(void), FUN_08017cb0(void), FUN_08017cd8(void), FUN_08017cf4(void);
void FUN_08017ed0(void), FUN_08017f6c(void), FUN_08017fb0(void);
void FUN_08018004(u16, u16, u8, u16, u8, u8, u8, u8, u8);
void FUN_080183d0(u8, u8, u8, u8, u8, u8);
void FUN_0801f618(u16), FUN_0801f638(void), FUN_0801f718(u16, u16);
void FUN_0801fba0(u16, u16), FUN_0801ff30(void), FUN_08020840(u16);
u32 FUN_080205d0(void), FUN_0802067c(u16 *, u16);
void FUN_0803e7a8(void);
void FUN_0803e8d8(void);
void FUN_0803f0c8(void);
void FUN_0803f6a4(void);
void FUN_0803f7cc(void);

void FUN_0803e7a8(void) {
    FUN_08016078(1);
    FUN_08017cb0();
    FUN_08017cd8();
    FUN_08017cf4();
    gUnknown_030017cc = 0;
    gUnknown_030017c8 = 0;
    gUnknown_03001388 = 0;
    FUN_0801fba0(0, 0x1341);
    u32 zero = 0;
    CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
    *(volatile u16 *)0x04000008 = 0;
    *(volatile u16 *)0x0400000a = 0;
    *(volatile u16 *)0x0400000c = 0;
    *(volatile u16 *)0x0400000e = 0;
    *(volatile u16 *)0x04000008 = 0x8e00;
    *(volatile u16 *)0x0400000a = 0x9e08;
    *(volatile u16 *)0x04000010 = 0;
    *(volatile u16 *)0x04000012 = 0;
    *(volatile u16 *)0x04000014 = 0;
    *(volatile u16 *)0x04000016 = 0;
    *(volatile u16 *)0x04000018 = 0;
    *(volatile u16 *)0x0400001a = 0;
    *(volatile u16 *)0x0400001c = 0;
    *(volatile u16 *)0x0400001e = 0;
    FUN_080183d0(0, 0, 0, 0, 0, 0);
    gUnknown_030016bc = -1;
    gUnknown_03001b2c = 255;
    gUnknown_030016c0 = 0;
    gUnknown_03001b04 = 0;
    gUnknown_03001b08 = 2;
    FUN_0801f638();
    if (gUnknown_03005428 == 7) {
        FUN_0801f618(39);
        gUnknown_03002030 = FUN_0803e8d8;
    } else {
        FUN_0801f618(32);
        gUnknown_03002030 = FUN_0803f0c8;
    }
    FUN_08020840(24);
    FUN_080205d0();
}

void FUN_0803e8d8(void) {
    if (gUnknown_03001b08 == 2) {
        ++gUnknown_03001b2c;
        gUnknown_03001b08 = 0;
    } else
        ++gUnknown_03001b08;
    if (gUnknown_030016c0 == 5 && gUnknown_03001b2c == 224)
        FUN_0801f718(39, 64);
    if ((u16)(gUnknown_030016c0 - 2) > 12)
        FUN_080183d0(3, 16, 16, 0, 0, 16);
    else if (gUnknown_03001b2c > 239 && gUnknown_030016c0 != 11 && gUnknown_030016c0 != 13)
        FUN_080183d0(3, 16, 16, 0, 0, (u8)(gUnknown_03001b2c + 16));
    else if (gUnknown_03001b2c <= 16 && gUnknown_030016c0 != 12 && gUnknown_030016c0 != 14)
        FUN_080183d0(3, 16, 16, 0, 0, (u8)(16 - gUnknown_03001b2c));
    if (gUnknown_03001b2c > 255) {
        switch (gUnknown_030016c0) {
        case 0: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08361074;
            dma->destination = (void *)0x05000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_08336fb4;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000b80;
            (void)dma->control;
            dma->source = gUnknown_083386b4;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;

            break;
        }
        case 1: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083396d4;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80001070;
            (void)dma->control;
            dma->source = gUnknown_0833b7b4;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_08390874;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_08390a74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 2: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0833c7d4;
            dma->destination = (void *)0x06008000;
            dma->control = 0x800010a0;
            (void)dma->control;
            dma->source = gUnknown_0833e914;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_08396a74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_08396c74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 3: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0833f934;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80001080;
            (void)dma->control;
            dma->source = gUnknown_08341a34;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_0839cc74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_0839ce74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 4: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08342a54;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000d60;
            (void)dma->control;
            dma->source = gUnknown_08344514;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083af274;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083af474;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 5: {
            FUN_0801f618(32);
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08345534;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000a30;
            (void)dma->control;
            dma->source = gUnknown_08346994;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083a2e74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083a3074;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 6: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083479b4;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000fc0;
            (void)dma->control;
            dma->source = gUnknown_08349934;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083a9074;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083a9274;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 7: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0834a954;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000f60;
            (void)dma->control;
            dma->source = gUnknown_0834c814;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083b5474;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083b5674;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 8: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0834d834;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000ff0;
            (void)dma->control;
            dma->source = gUnknown_0834f814;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083bb674;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083bb874;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 9: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08350834;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000ea0;
            (void)dma->control;
            dma->source = gUnknown_08352574;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083c1874;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083c1a74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 10: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08353594;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80001000;
            (void)dma->control;
            dma->source = gUnknown_08355594;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083c7a74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083c7c74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 11: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083565b4;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80001260;
            (void)dma->control;
            dma->source = gUnknown_08358a74;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;

            break;
        }
        case 12: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08359a94;
            dma->destination = (void *)0x06008000;
            dma->control = 0x800011e0;
            (void)dma->control;
            dma->source = gUnknown_0835be54;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_083cdc74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000100;
            (void)dma->control;
            dma->source = gUnknown_083cde74;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80003000;
            (void)dma->control;

            break;
        }
        case 13: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_0835ce74;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000af0;
            (void)dma->control;
            dma->source = gUnknown_0835e454;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;

            break;
        }
        case 14: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08361094;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000850;
            (void)dma->control;
            dma->source = gUnknown_08362134;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;

            break;
        }
        case 15: {
            FUN_0801f718(32, 256);
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;

            break;
        }
        case 16: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            gUnknown_03002030 = FUN_0803f7cc;
            break;
        }
        }
        gUnknown_03001b2c = 0;
        ++gUnknown_030016c0;
        gUnknown_03001b04 ^= 1;
    }
    s16 *firstScroll = &gUnknown_03001374;
    s32 firstOffset = (s16)(gUnknown_03001b04 ^ 1) << 8;
    u32 positionValue = (u16)gUnknown_03001b2c;
    *firstScroll = positionValue - firstOffset;
    s16 *secondScroll = &gUnknown_03001b24;
    s32 secondOffset = gUnknown_03001b04 << 8;
    *secondScroll = positionValue - secondOffset;
    *(volatile u16 *)0x04000010 = 0;
    *(volatile u16 *)0x04000012 = gUnknown_03001374;
    *(volatile u16 *)0x04000014 = 0;
    *(volatile u16 *)0x04000016 = gUnknown_03001b24;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(128, 0, 1, 0, 0, 0, 131, 0, 0);
    FUN_08018004(192, 0, 1, 128, 0, 0, 131, 0, 0);
    FUN_08018004(128, 64, 1, 256, 0, 0, 131, 0, 0);
    FUN_08018004(192, 64, 1, 384, 0, 0, 131, 0, 0);
    FUN_08018004(128, 128, 1, 512, 0, 0, 131, 0, 0);
    FUN_08018004(192, 128, 1, 640, 0, 0, 131, 0, 0);
    FUN_08017f6c();
    FUN_08017690();
    FUN_08017fb0();
    FUN_08017c5c();
    FUN_080205d0();
}

void FUN_0803f0c8(void) {
    if (gUnknown_03001b08 == 2) {
        ++gUnknown_03001b2c;
        gUnknown_03001b08 = 0;
    } else
        ++gUnknown_03001b08;
    if (gUnknown_030016c0 == 3) {
        if (gUnknown_03001b2c > 239)
            FUN_080183d0(3, 16, 16, 0, 0, (u8)(gUnknown_03001b2c + 16));
    } else if (gUnknown_030016c0 == 4)
        FUN_080183d0(3, 16, 16, 0, 0, 16);
    if (gUnknown_030016c0 == 4 && gUnknown_03001b2c > 47) {
        if (gUnknown_03002110[119] == 0) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083ddf14;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083ddf34;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        } else if (gUnknown_03002110[119] == 1) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083d3e74;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083d3e94;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        } else if (gUnknown_03002110[119] == 2) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083d7eb4;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083d7ed4;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        } else if (gUnknown_03002110[119] == 3) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083d5e94;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083d5eb4;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        } else if (gUnknown_03002110[119] == 4) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083d9ed4;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083d9ef4;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        } else if (gUnknown_03002110[119] == 5) {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_083dbef4;
            dma->destination = (void *)0x05000200;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_083dbf14;
            dma->destination = (void *)0x06010000;
            dma->control = 0x80001000;
            (void)dma->control;
        }
        gUnknown_030016bc = 0;
        if ((gUnknown_03005424 >> (gUnknown_03005428 + 1)) & 1)
            gUnknown_03002030 = FUN_0803f7cc;
        else
            gUnknown_03002030 = FUN_0803f6a4;
    }
    if (gUnknown_03001b2c > 255) {
        switch (gUnknown_030016c0) {
        case 0: {
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08361074;
            dma->destination = (void *)0x05000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            dma->source = gUnknown_08363154;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000310;
            (void)dma->control;
            dma->source = gUnknown_08363774;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            if (gUnknown_03005428 == 0) {
                dma->source = gUnknown_08365a74;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_08365c74;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 1) {
                dma->source = gUnknown_0836bc74;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_0836be74;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 2) {
                dma->source = gUnknown_0837e274;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_0837e474;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 3) {
                dma->source = gUnknown_08371e74;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_08372074;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 4) {
                dma->source = gUnknown_08384474;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_08384674;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 5) {
                dma->source = gUnknown_0838a674;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_0838a874;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            } else if (gUnknown_03005428 == 6) {
                dma->source = gUnknown_08378074;
                dma->destination = (void *)0x05000200;
                dma->control = 0x80000100;
                (void)dma->control;
                dma->source = gUnknown_08378274;
                dma->destination = (void *)0x06010000;
                dma->control = 0x80003000;
                (void)dma->control;
            }
            break;
        }
        case 1: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08361094;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000850;
            (void)dma->control;
            dma->source = gUnknown_08362134;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            break;
        }
        case 2: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08364794;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000170;
            (void)dma->control;
            dma->source = gUnknown_08364a74;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            break;
        }
        case 3: {
            FUN_0801f718(39, 256);
            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06000000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x06007000;
            dma->control = 0x80000800;
            (void)dma->control;
            break;
        }
        case 4: {

            volatile Dma *dma = (volatile Dma *)0x040000d4;
            dma->source = gUnknown_08335f74;
            dma->destination = (void *)0x06008000;
            dma->control = 0x80000010;
            (void)dma->control;
            dma->source = gUnknown_08335f94;
            dma->destination = (void *)0x0600f000;
            dma->control = 0x80000800;
            (void)dma->control;
            break;
        }
        }
        gUnknown_03001b2c = 0;
        ++gUnknown_030016c0;
        gUnknown_03001b04 ^= 1;
    }
    s16 *firstScroll = &gUnknown_03001374;
    s32 firstOffset = (s16)(gUnknown_03001b04 ^ 1) << 8;
    u32 positionValue = (u16)gUnknown_03001b2c;
    *firstScroll = positionValue - firstOffset;
    s16 *secondScroll = &gUnknown_03001b24;
    s32 secondOffset = gUnknown_03001b04 << 8;
    *secondScroll = positionValue - secondOffset;
    *(volatile u16 *)0x04000010 = 0;
    *(volatile u16 *)0x04000012 = gUnknown_03001374;
    *(volatile u16 *)0x04000014 = 0;
    *(volatile u16 *)0x04000016 = gUnknown_03001b24;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(128, 0, 1, 0, 0, 0, 131, 0, 0);
    FUN_08018004(192, 0, 1, 128, 0, 0, 131, 0, 0);
    FUN_08018004(128, 64, 1, 256, 0, 0, 131, 0, 0);
    FUN_08018004(192, 64, 1, 384, 0, 0, 131, 0, 0);
    FUN_08018004(128, 128, 1, 512, 0, 0, 131, 0, 0);
    FUN_08018004(192, 128, 1, 640, 0, 0, 131, 0, 0);
    FUN_08017f6c();
    FUN_08017690();
    FUN_08017fb0();
    FUN_08017c5c();
    FUN_080205d0();
}

void FUN_0803f6a4(void) {
    if (++gUnknown_030016bc <= 16) {
        FUN_080183d0(3, 16, 16, 0, 0, 16 - gUnknown_030016bc);
        if (gUnknown_030016bc == 16)
            FUN_0801f618(333);
    }
    if (gUnknown_030016bc > 511) {
        FUN_080183d0(3, 16, 16, 0, 0, gUnknown_030016bc);
        if (gUnknown_030016bc == 528)
            gUnknown_03002030 = FUN_0803f7cc;
    }
    if ((gUnknown_030048e0[2] & 1) && gUnknown_030016bc <= 511)
        gUnknown_030016bc = 512;
    FUN_08017ed0();
    FUN_0801ff30();
    FUN_08018004(0, 60, 0, 0, 0, 0, 115, 0, 0);
    FUN_08018004(64, 60, 0, 64, 0, 0, 115, 0, 0);
    FUN_08018004(128, 60, 0, 128, 0, 0, 115, 0, 0);
    FUN_08018004(192, 60, 0, 192, 0, 0, 115, 0, 0);
    FUN_08017f6c();
    FUN_08017690();
    FUN_08017fb0();
    FUN_08017c5c();
}

void FUN_0803f7cc(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 256)) {
        FUN_080183d0(0, 0, 0, 0, 0, 0);
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x05000000, 0x01000100);
        gUnknown_03002030 = FUN_08000210;
    }
}
}
