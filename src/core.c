#include "types.h"

typedef void (*Callback)(void);

extern u8 gUnknown_0300138c;
extern u16 gUnknown_030016c0;
extern const u8 gUnknown_083270b4[];
extern Callback gMainCallback;

extern void FUN_080003a8(void);
extern void FUN_080183d0(u32, u32, u32, u32, u32, u32);
extern void FUN_0801835c(void);
extern u8 FUN_0802046c(void *, u32);
extern u8 FUN_080202f0(void *, const void *, u32);
extern void FUN_0803d748(void);
extern void FUN_0804a384(const void *, void *, u32);
extern void FUN_0804a3c0(void);

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
