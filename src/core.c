#include "types.h"

typedef void (*Callback)(void);
typedef struct {
    u16 value;
    u8 padding[6];
} UnknownRecord;

extern u8 gUnknown_0300138c;
extern u16 gUnknown_030016c0;
extern s16 gUnknown_03001b08;
extern s16 gUnknown_03001b2c;
extern UnknownRecord gUnknown_03002110[];
extern volatile u16 gUnknown_030048e0[];
extern const u8 gUnknown_083270b4[];
extern Callback gMainCallback;

extern void FUN_080003a8(void);
extern void FUN_080006d0(void);
extern void FUN_080006ec(void);
extern void FUN_08000724(void);
extern void FUN_08016078(u32);
extern void FUN_080163c0(u32);
extern void FUN_08016438(u32, u32, u32, u32, u32, u32, u32, u32);
extern void FUN_08017d78(u32, u32);
extern void FUN_08017de8(u32, u32);
extern void FUN_08017e5c(u32, u32);
extern void FUN_080183d0(u32, u32, u32, u32, u32, u32);
extern void FUN_0801835c(void);
extern void FUN_080184c8(void);
extern void FUN_0801f5ec(void);
extern void FUN_0801f618(u32);
extern void FUN_0801f638(void);
extern void FUN_08020198(void);
extern u8 FUN_080202f0(void *, const void *, u32);
extern u8 FUN_0802046c(void *, u32);
extern u8 FUN_0802067c(void *, u32);
extern void FUN_08021920(void);
extern void FUN_0803d748(void);
extern void FUN_08049170(void);
extern void FUN_0804962c(void);
extern void FUN_0804a384(const void *, void *, u32);
extern void FUN_0804a3c0(void);

#define REG_DISPSTAT (*(volatile u16 *)0x04000004)
#define REG_IE (*(volatile u16 *)0x04000200)
#define REG_IF (*(volatile u16 *)0x04000208)
#define REG_SIOCNT (*(volatile u16 *)0x04000128)
#define MULTI_SIO_ENABLED (*(volatile u8 *)0x030020f8)
#define MULTI_SIO_DATA gUnknown_030048e0
#define RESET_REQUESTED (*(volatile u32 *)0x03005254)

void FUN_08000210(void) {
    u32 zero;

    *(volatile u16 *)0x03005424 = gUnknown_03002110[0x92].value;
    FUN_08016078(1);

    {
        volatile u32 *dma = (volatile u32 *)0x040000d4;

        dma[0] = 0x08328c74;
        dma[1] = 0x06000000;
        dma[2] = 0x800010a0;
        dma[2];
        dma[0] = 0x0832adb4;
        dma[1] = 0x06007000;
        dma[2] = 0x80000200;
        dma[2];
        dma[0] = 0x08330134;
        dma[1] = 0x06008000;
        dma[2] = 0x80000020;
        dma[2];
        dma[0] = 0x08330174;
        dma[1] = 0x0600f000;
        dma[2] = 0x80000200;
        dma[2];
    }

    FUN_080163c0(2);
    FUN_08017d78(2, 0x4000);
    FUN_08017d78(2, 0);
    FUN_08017d78(2, 0x80);
    FUN_08017d78(2, 0);
    FUN_08017d78(2, 0);
    FUN_08017de8(2, 0);
    FUN_08017e5c(2, 0xe);
    FUN_080163c0(3);
    FUN_08017d78(3, 0x4000);
    FUN_08017d78(3, 2);
    FUN_08017d78(3, 0x80);
    FUN_08017d78(3, 0);
    FUN_08017d78(3, 0);
    FUN_08017de8(3, 2);
    FUN_08017e5c(3, 0x1e);

    {
        volatile u16 *affine = (volatile u16 *)0x04000020;

        *affine++ = 0x100;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0x100;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0x100;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0x100;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0;
        *affine++ = 0;
    }

    FUN_080183d0(1, 4, 8, 0, 0x10, 0);
    gMainCallback = FUN_080006ec;
    FUN_0801f638();
    zero = 0;
    gUnknown_03001b08 = zero;
    gUnknown_03001b2c = zero;
    gUnknown_030016c0 = zero;
}

void FUN_080003a8(void) {
    volatile u32 *dma;

    gUnknown_03001b08++;
    switch (gUnknown_03001b08) {
    case 8:
        dma = (volatile u32 *)0x040000d4;
        dma[0] = 0x083272b4;
        dma[1] = 0x06008000;
        dma[2] = 0x80000ae0;
        dma[2];
        dma[0] = 0x08328874;
        dma[1] = 0x0600f000;
        dma[2] = 0x80000200;
        dma[2];
        gUnknown_030016c0 = 0;
        break;
    case 0x80:
        gUnknown_030016c0 = 0x10;
        break;
    case 0x88:
        dma = (volatile u32 *)0x040000d4;
        dma[0] = 0x0832b1b4;
        dma[1] = 0x06008000;
        dma[2] = 0x80001600;
        dma[2];
        dma[0] = 0x0832ddb4;
        dma[1] = 0x0600f000;
        dma[2] = 0x80000200;
        dma[2];
        gUnknown_030016c0 = 0;
        break;
    case 0x90:
        FUN_0801f618(400);
        dma = (volatile u32 *)0x040000d4;
        dma[0] = 0x0832e1b4;
        dma[1] = 0x06000000;
        dma[2] = 0x80000dc0;
        dma[2];
        dma[0] = 0x0832fd34;
        dma[1] = 0x06007000;
        dma[2] = 0x80000200;
        dma[2];
        gUnknown_030016c0 = 0x10;
        break;
    case 0x108:
        gUnknown_030016c0 = 0;
        break;
    case 0x110:
        dma = (volatile u32 *)0x040000d4;
        dma[0] = 0x08330134;
        dma[1] = 0x06000000;
        dma[2] = 0x80000020;
        dma[2];
        dma[0] = 0x08330174;
        dma[1] = 0x06007000;
        dma[2] = 0x80000200;
        dma[2];
        gUnknown_030016c0 = 0x10;
        break;
    case 0x118:
        gMainCallback = FUN_08000724;
        break;
    }

    if ((MULTI_SIO_DATA[0] & 8) != 0) {
        u16 counter = gUnknown_03001b08;

        if ((u16)(counter - 0x19) <= 0x66) {
            gUnknown_03001b08 = 0x7f;
        } else if ((u16)(counter - 0xa1) <= 0x66) {
            gUnknown_03001b08 = 0x107;
        }
    }

    if (gUnknown_03001b2c > (s16)gUnknown_030016c0) {
        gUnknown_03001b2c -= 2;
    }
    if (gUnknown_03001b2c < (s16)gUnknown_030016c0) {
        gUnknown_03001b2c += 2;
    }

    FUN_080183d0(1, 4, 8, (u8)gUnknown_03001b2c, (u8)(0x10 - (u8)gUnknown_03001b2c), 0);
    FUN_08016438(0, 0, 0x100, 0x100, 1, 1, 0, 2);
    FUN_08016438(0, 0, 0x100, 0x100, 1, 1, 0, 3);
}

void FUN_080005ac(void) {
    if (MULTI_SIO_ENABLED != 0) {
        volatile u16 *multiSioData = MULTI_SIO_DATA;

        if ((multiSioData[2] & 0xf) == 0 || (multiSioData[0] & 0xf) != 0xf) {
            return;
        }
        do {
            FUN_080006d0();
        } while (!FUN_0802067c((void *)0x05000000, 0x200));

        if (RESET_REQUESTED != 0) {
            RESET_REQUESTED = 0;
            FUN_080184c8();
        }

        REG_IE = 0;
        REG_IF = 0;
        REG_DISPSTAT = 0;
        FUN_08049170();
        FUN_0804962c();

        {
            volatile u16 *dma = (volatile u16 *)0x040000b0;
            dma[5] &= 0xc5ff;
            dma[5] &= 0x7fff;
            dma[5];
            dma += 6;
            dma[5] &= 0xc5ff;
            dma[5] &= 0x7fff;
            dma[5];
            dma += 6;
            dma[5] &= 0xc5ff;
            dma[5] &= 0x7fff;
            dma[5];
            dma += 6;
            dma[5] &= 0xc5ff;
            dma[5] &= 0x7fff;
            dma[5];
        }

        while ((REG_SIOCNT & 0xf) == 0xf) {
            FUN_08020198();
        }
        FUN_08021920();
        MULTI_SIO_ENABLED = 0;
        FUN_08016078(0);
        FUN_0801f5ec();
        gMainCallback = FUN_08000210;
    }
}

void FUN_080006d0(void) {
    if (gUnknown_0300138c == 0) {
        FUN_0804a3c0();
    } else {
        FUN_0801835c();
    }
}

void FUN_080006ec(void) {
    if (FUN_080202f0((void *)0x05000000, gUnknown_083270b4, 0x100)) {
        gUnknown_030016c0 = 0x10;
        gMainCallback = FUN_080003a8;
    }
}

void FUN_08000724(void) {
    u32 paletteFill;

    if (FUN_0802046c((void *)0x05000000, 0x100)) {
        FUN_080183d0(0, 0, 0, 0, 0, 0);
        paletteFill = 0;
        FUN_0804a384(&paletteFill, (void *)0x05000000, 0x01000100);
        gMainCallback = FUN_0803d748;
    }
}
