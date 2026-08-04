#include "types.h"

typedef void (*Callback)(void);

extern void FUN_08000210(void);
extern void FUN_080005ac(void);
extern void FUN_080006d0(void);
extern void FUN_08016078(u32);
extern void FUN_08017c74(void);
extern void FUN_0801f5ec(void);
extern void FUN_0801f780(void);
extern void FUN_0801fc54(void);
extern void FUN_08020198(void);
extern void FUN_080201f8(void);
extern void FUN_08020244(void);
extern void FUN_08020360(void);
extern void FUN_080210d8(void);
extern void FUN_0802110c(void);
extern void FUN_080216e4(void);
extern void CpuFastSet(const void *, void *, u32);
extern void VBlankIntrWait(void);

#define REG_WAITCNT (*(volatile u16 *)0x04000204)
#define MAIN_CALLBACK (*(Callback *)0x03002030)

void AgbMain(void) {
    u32 paletteFill;

    FUN_08017c74();
    REG_WAITCNT = 0x4014;
    FUN_080216e4();
    FUN_0801fc54();
    FUN_080201f8();
    FUN_08020360();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    FUN_08016078(5);
    VBlankIntrWait();

    paletteFill = 0x7FFF7FFF;
    CpuFastSet(&paletteFill, (void *)0x05000000, 0x01000100);
    FUN_0801f5ec();
    MAIN_CALLBACK = FUN_08000210;

    while (1) {
        FUN_08020198();
        FUN_080005ac();
        MAIN_CALLBACK();
        FUN_080006d0();
        FUN_08020244();
    }
}
