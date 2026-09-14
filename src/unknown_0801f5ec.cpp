#include "types.h"
/* Original language is unknown; C++ is the reconstruction fallback.
 * C linkage preserves synthetic labels, not recovered retail linkage. */
extern "C" {
struct UnknownSoundIndex {
    u8 filler0[4];
    u16 index;
    u8 filler6[2];
};
struct UnknownSoundEntry {
    const void *value;
    u8 filler4[8];
};
extern const struct UnknownSoundIndex gUnknown_08bf7244[];
extern const struct UnknownSoundEntry gUnknown_08bf71fc[];
extern void FUN_08048fb8(void);
extern void FUN_08049544(const void *);
extern void FUN_08049030(void);
extern void FUN_08049724(void);
extern void m4aSongNumStart(u16);
extern void FUN_08049108(u16);
extern void FUN_08049170(void);
extern void FUN_08049234(const void *);
extern void FUN_0804a1a0(const void *, u16, s8);
extern void FUN_0804a0c4(const void *, u16, u16);
extern void FUN_0804a0a0(const void *, u16);
extern void FUN_0804962c(void);
extern void FUN_080496ac(void);
extern void FUN_080491d4(const void *, u16);
extern void FUN_080491e4(const void *, u16);
extern void FUN_080490b4(u16);
void FUN_0801f5ec(void) {
    FUN_08048fb8();
    FUN_08049544((const void *)0x0093e800);
}

void FUN_0801f600(void) { FUN_08049030(); }

void FUN_0801f60c(void) { FUN_08049724(); }

void FUN_0801f618(u16 value) { m4aSongNumStart(value); }

void FUN_0801f628(u16 value) { FUN_08049108(value); }

void FUN_0801f638(void) { FUN_08049170(); }

void FUN_0801f644(u16 value) {
    FUN_08049234(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value);
}

void FUN_0801f66c(u16 value, u16 first, s8 second) {
    FUN_0804a1a0(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, first, second);
}

void FUN_0801f6a0(u16 value, u16 first, u16 second) {
    FUN_0804a0c4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, first, second);
}

void FUN_0801f6d4(u16 value, u16 other) {
    FUN_0804a0a0(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other);
}

void FUN_0801f700(void) { FUN_0804962c(); }

void FUN_0801f70c(void) { FUN_080496ac(); }

void FUN_0801f718(u16 value, u16 other) {
    FUN_080491d4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other >> 4);
}

void FUN_0801f744(u16 value, u16 other) {
    FUN_080491e4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other);
}

void FUN_0801f770(u16 value) { FUN_080490b4(value); }
}
