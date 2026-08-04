#include "types.h"

extern u8 gUnknown_03001740[];

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
