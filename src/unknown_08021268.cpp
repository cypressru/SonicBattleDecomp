// Inferred complete multiboot wrapper TU; see docs/multiboot-tu-cpp.md.
#include "types.h"
extern "C" {
struct MultiBootParam {
    u32 systemWork[5];
    u8 handshakeData, padding15;
    u16 handshakeTimeout;
    u8 probeCount, clientData[3], paletteData, responseBit, clientBit, reserved1;
    u8 *bootSource, *bootEnd, *master, *reserved2[3];
    u32 systemWork2[4];
    u8 sendFlag, probeTargetBit, checkWait, serverType;
};
static MultiBootParam gUnknown_03004d40;
extern u8 gUnknown_03002110[];
extern u32 gUnknown_03004d8c;
u32 gUnknown_03004d90 __attribute__((section(".bss.boot_reset"))) = 0;
const u8 *gUnknown_03004d94 __attribute__((section(".bss.boot_source"))) = 0;
u32 gUnknown_03004d9c __attribute__((section(".bss.boot_length"))) = 0;
extern u32 gUnknown_020000c8;
extern const u8 gUnknown_08eeb690[], gUnknown_08eeb868[], gUnknown_08eef9c0[];
// Existing payload-start symbol; the adjacent bootstrap end is a separate boundary expression.
extern const u8 agb_test_lz77_0[];
extern const u8 gUnknown_08f16058[], gUnknown_08f35258[], gUnknown_08f5f04c[];
extern const u8 gUnknown_08f81d10[], gUnknown_08f9ee18[];
extern const void *const gUnknown_08ed8b88[][2];
extern const void *const gUnknown_08ed8bb8[][6];
void CpuSet(const void *, void *, u32);
void MultiBootInit(MultiBootParam *);
extern u8 gUnknown_0300525c;
extern u32 gUnknown_03002610, gUnknown_020000e0;
void MultiBootStartMaster(MultiBootParam *, const u8 *, s32, u8, s8);
s32 MultiBootMain(MultiBootParam *);
s32 MultiBootCheckComplete(MultiBootParam *);
void SoftResetExram(u32);
void LZ77UnCompWram(const void *, void *);
void FUN_08021268(u8 mode) {
    u8 *destination = (u8 *)0x02000200;
    CpuSet(gUnknown_08eeb690, (void *)0x02000000,
           (((u32)gUnknown_08eeb868 - (u32)gUnknown_08eeb690 + 1) >> 1) & 0x1fffff);
    CpuSet(agb_test_lz77_0, destination,
           (((u32)gUnknown_08eef9c0 - (u32)agb_test_lz77_0 + 1) >> 1) & 0x1fffff);
    const void *const *pairs = &gUnknown_08ed8b88[0][0];
    const u8 *language = gUnknown_03002110;
    language += 0x77;
    CpuSet(pairs[*language * 2], destination + 0x4e80, 0x120);
    u32 secondOffset = *language << 3;
    pairs++;
    CpuSet(*(const void *const *)((u32)pairs + secondOffset), destination + 0x50c0, 0x70);
    gUnknown_03004d9c = 0x53a0;
    switch (mode) {
    case 0:
        CpuSet(gUnknown_08ed8bb8[0][gUnknown_03002110[0x77]], destination + 0x4160, 0x690);
        gUnknown_03004d8c = (u32)gUnknown_08f35258 - (u32)gUnknown_08f16058;
        gUnknown_03004d94 = gUnknown_08f16058;
        break;
    case 1:
        CpuSet(gUnknown_08ed8bb8[1][gUnknown_03002110[0x77]], destination + 0x4160, 0x690);
        gUnknown_03004d8c = ((u32)gUnknown_08f16058 - (u32)gUnknown_08eef9c0 + 3) & ~3;
        gUnknown_03004d94 = gUnknown_08eef9c0;
        break;
    case 3:
        CpuSet(gUnknown_08ed8bb8[2][gUnknown_03002110[0x77]], destination + 0x4160, 0x690);
        gUnknown_03004d8c = (u32)gUnknown_08f5f04c - (u32)gUnknown_08f35258;
        gUnknown_03004d94 = gUnknown_08f35258;
        break;
    case 4:
        CpuSet(gUnknown_08ed8bb8[3][gUnknown_03002110[0x77]], destination + 0x4160, 0x690);
        gUnknown_03004d8c = (u32)gUnknown_08f81d10 - (u32)gUnknown_08f5f04c;
        gUnknown_03004d94 = gUnknown_08f5f04c;
        break;
    case 2:
    case 5:
    default:
        gUnknown_03004d8c = (u32)gUnknown_08f9ee18 - (u32)gUnknown_08f81d10;
        gUnknown_03004d94 = gUnknown_08f81d10;
        break;
    }
    gUnknown_020000c8 = gUnknown_03002110[0x77];
    gUnknown_03004d40.master = (u8 *)&gUnknown_020000c8 - 0xc8;
    gUnknown_03004d40.serverType = 0;
    gUnknown_03004d40.probeCount = 0;
    MultiBootInit(&gUnknown_03004d40);
    gUnknown_03004d90 = 0;
}

u8 FUN_08021484(void) {
    u8 result = 1;
    u8 index = 1;
    MultiBootParam *state = &gUnknown_03004d40;
    u8 response = state->responseBit;
    u32 mask = 1;
    do {
        if (((response >> index) & mask) && ((state->clientBit >> index) & mask)) {
            result++;
        }
        index++;
    } while (index <= 3);
    return result;
}

u32 FUN_080214c0(u32 unused) {
    MultiBootParam *state = &gUnknown_03004d40;
    if (state->probeCount != 0 || state->clientBit == 0)
        return 0;
    u32 *metadata = (u32 *)0x020000c0;
    *(u32 *)0x020000cc = gUnknown_0300525c;
    metadata += 4;
    metadata[0] = gUnknown_03002610;
    MultiBootStartMaster(state, (const u8 *)(metadata - 4), gUnknown_03004d9c - 0xc0, 4, 1);
    return 1;
}

void FUN_08021518(void) {
    gUnknown_020000e0 = 0x12345678;
    SoftResetExram(0x40);
}

u32 FUN_08021534(void) {
    if (MultiBootMain(&gUnknown_03004d40) != 0) {
        return 0xFF;
    }
    if (MultiBootCheckComplete(&gUnknown_03004d40) != 0) {
        return 1;
    }
    return 0;
}

u32 FUN_08021564(void) {
    const void *source = gUnknown_03004d94;
    u32 size = gUnknown_03004d8c;

    CpuSet(source, (void *)(0x0203B000 - size), (size << 10) >> 11);
    return 0;
}

u32 FUN_0802158c(void) {
    LZ77UnCompWram(gUnknown_03004d94, (void *)0x02000100);
    return 0;
}
}

extern "C" {
extern const u8 gUnknown_0814b220[];
extern const u8 gUnknown_0814adcc[];
extern const u8 gUnknown_0814b3f0[];
extern const u8 gUnknown_0814ae74[];
extern const u8 gUnknown_0814b5c4[];
extern const u8 gUnknown_0814af20[];
extern const u8 gUnknown_0814b804[];
extern const u8 gUnknown_0814afec[];
extern const u8 gUnknown_0814ba00[];
extern const u8 gUnknown_0814b0a4[];
extern const u8 gUnknown_0814bc08[];
extern const u8 gUnknown_0814b15c[];
extern const u8 gUnknown_08139140[];
extern const u8 gUnknown_08139c90[];
extern const u8 gUnknown_0813a5cc[];
extern const u8 gUnknown_0813af3c[];
extern const u8 gUnknown_0813b884[];
extern const u8 gUnknown_0813c184[];
extern const u8 gUnknown_0813caf8[];
extern const u8 gUnknown_0813d628[];
extern const u8 gUnknown_0813dfa4[];
extern const u8 gUnknown_0813e9c8[];
extern const u8 gUnknown_0813f3f4[];
extern const u8 gUnknown_0813fdbc[];
extern const u8 gUnknown_08140770[];
extern const u8 gUnknown_081413b0[];
extern const u8 gUnknown_08141f1c[];
extern const u8 gUnknown_08142af4[];
extern const u8 gUnknown_08143690[];
extern const u8 gUnknown_08144270[];
extern const u8 gUnknown_08144df0[];
extern const u8 gUnknown_08145a58[];
extern const u8 gUnknown_08146640[];
extern const u8 gUnknown_08147250[];
extern const u8 gUnknown_08147ebc[];
extern const u8 gUnknown_08148af4[];
extern const void *const gUnknown_08ed8b88[6][2] = {
    {gUnknown_0814b220, gUnknown_0814adcc}, {gUnknown_0814b3f0, gUnknown_0814ae74},
    {gUnknown_0814b5c4, gUnknown_0814af20}, {gUnknown_0814b804, gUnknown_0814afec},
    {gUnknown_0814ba00, gUnknown_0814b0a4}, {gUnknown_0814bc08, gUnknown_0814b15c},
};
extern const void *const gUnknown_08ed8bb8[4][6] = {
    {gUnknown_08139140, gUnknown_08139c90, gUnknown_0813a5cc, gUnknown_0813af3c, gUnknown_0813b884,
     gUnknown_0813c184},
    {gUnknown_0813caf8, gUnknown_0813d628, gUnknown_0813dfa4, gUnknown_0813e9c8, gUnknown_0813f3f4,
     gUnknown_0813fdbc},
    {gUnknown_08140770, gUnknown_081413b0, gUnknown_08141f1c, gUnknown_08142af4, gUnknown_08143690,
     gUnknown_08144270},
    {gUnknown_08144df0, gUnknown_08145a58, gUnknown_08146640, gUnknown_08147250, gUnknown_08147ebc,
     gUnknown_08148af4},
};
}
