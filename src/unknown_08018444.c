#include "types.h"

extern u8 gUnknown_030013a0;
extern u16 gUnknown_03001b10[8];
extern u16 gUnknown_030016f0[4][8];

extern void FUN_0801694c(void);
extern void FUN_08017eec(void);
extern void FUN_0801ff30(void);
extern void FUN_08017690(void);
extern void FUN_08017fb0(void);
extern void FUN_08018654(void);
extern void FUN_0801fc60(void);
extern void FUN_0801f600(void);

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

void FUN_080185a8(void) {
    FUN_0801694c();
    FUN_08017eec();
    FUN_0801ff30();
    FUN_08017690();
    FUN_08017fb0();
    gUnknown_030013a0 = 0;
}

void FUN_080185cc(void) { FUN_08018654(); }

void FUN_08018654(void) {
    FUN_0801fc60();
    FUN_0801f600();
}

void FUN_08018664(void) {}

void FUN_08018668(void) { *(volatile u16 *)0x03007ff8 |= 1; }
