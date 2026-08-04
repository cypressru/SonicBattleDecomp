#include "types.h"

#define FLASH_BASE ((u8 *)0x0E000000)
#define FLASH_WRITE(address, data) (*(volatile u8 *)(FLASH_BASE + (address)) = (data))
#define REG_IE (*(volatile u16 *)0x04000200)
#define REG_IF (*(volatile u16 *)0x04000202)
#define REG_WAITCNT (*(volatile u16 *)0x04000204)
#define REG_IME (*(volatile u16 *)0x04000208)
#define REG_TIMER_BASE ((volatile u16 *)0x04000100)

struct FlashSector {
    u32 size;
    u8 shift;
    u8 padding5;
    u16 count;
    u16 top;
};

struct FlashType {
    u32 romSize;
    struct FlashSector sector;
    u16 wait[2];
    union {
        struct {
            u8 makerId;
            u8 deviceId;
        } separate;
        u16 joined;
    } ids;
};

static u8 sTimerNum;
static u16 sTimerCount;
static volatile u16 *sTimerReg;
static u16 sSavedIme;

u8 gFlashTimeoutFlag;
u8 (*PollFlashStatus)(u8 *address);
u16 (*WaitForFlashWrite)(u8 phase, u8 *address, u8 lastData);
u16 (*ProgramFlashSector)(u16 sectorNum, void *src);
const struct FlashType *gFlash;
u16 gFlashNumRemainingBytes;
u16 (*EraseFlashChip)(void);
u16 (*EraseFlashSector)(u16 sectorNum);
const u16 *gFlashMaxTime;

void SetReadFlash1(u16 *dest);

void SwitchFlashBank(u8 bankNum) {
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0xB0);
    FLASH_WRITE(0, bankNum);
}

u16 ReadFlashId(void) {
    u16 flashId;
    u16 readFlash1Buffer[0x20];
    u8 (*readFlash1)(u8 *address);
    volatile u16 delay;

    SetReadFlash1(readFlash1Buffer);
    readFlash1 = (u8 (*)(u8 *))((u32)readFlash1Buffer + 1);

    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0x90);
    for (delay = 20000; delay != 0; delay--) {
    }

    flashId = readFlash1(FLASH_BASE + 1) << 8;
    flashId |= readFlash1(FLASH_BASE);

    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0xF0);
    FLASH_WRITE(0x5555, 0xF0);
    for (delay = 20000; delay != 0; delay--) {
    }

    return flashId;
}

void FlashTimerIntr(void) {
    if (sTimerCount != 0 && --sTimerCount == 0) {
        gFlashTimeoutFlag = 1;
    }
}

u16 SetFlashTimerIntr(u8 timerNum, void (**intrFunc)(void)) {
    if (timerNum >= 4) {
        return 1;
    }

    sTimerNum = timerNum;
    sTimerReg = REG_TIMER_BASE + sTimerNum * 2;
    *intrFunc = FlashTimerIntr;
    return 0;
}

void StartFlashTimer(u8 phase) {
    const u16 *maxTime = &gFlashMaxTime[phase * 3];

    sSavedIme = REG_IME;
    REG_IME = 0;
    sTimerReg[1] = 0;
    REG_IE |= 8 << sTimerNum;
    gFlashTimeoutFlag = 0;
    sTimerCount = *maxTime++;
    *sTimerReg++ = *maxTime++;
    *sTimerReg-- = *maxTime++;
    REG_IF = 8 << sTimerNum;
    REG_IME = 1;
}

void StopFlashTimer(void) {
    REG_IME = 0;
    *sTimerReg++ = 0;
    *sTimerReg-- = 0;
    REG_IE &= ~(8 << sTimerNum);
    REG_IME = sSavedIme;
}

u8 ReadFlash1(u8 *address) { return *address; }

void SetReadFlash1(u16 *dest) {
    u16 *src;
    u16 i;

    PollFlashStatus = (u8 (*)(u8 *))((u32)dest + 1);
    src = (u16 *)ReadFlash1;
    src = (u16 *)((u32)src & ~1);
    i = ((u32)SetReadFlash1 - (u32)ReadFlash1) >> 1;

    while (i != 0) {
        *dest++ = *src++;
        i--;
    }
}

void ReadFlash_Core(u8 *src, u8 *dest, u32 size) {
    while (size-- != 0) {
        *dest++ = *src++;
    }
}

void ReadFlash(u16 sectorNum, u32 offset, void *dest, u32 size) {
    u8 *src;
    u16 i;
    u16 readFlashCoreBuffer[0x40];
    u16 *funcSrc;
    u16 *funcDest;
    void (*readFlashCore)(u8 *src, u8 *dest, u32 size);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    if (gFlash->romSize == 0x20000) {
        SwitchFlashBank(sectorNum / 16);
        sectorNum %= 16;
    }

    funcSrc = (u16 *)ReadFlash_Core;
    funcSrc = (u16 *)((u32)funcSrc & ~1);
    funcDest = readFlashCoreBuffer;
    i = ((u32)ReadFlash - (u32)ReadFlash_Core) >> 1;

    while (i != 0) {
        *funcDest++ = *funcSrc++;
        i--;
    }

    readFlashCore = (void (*)(u8 *, u8 *, u32))((u32)readFlashCoreBuffer + 1);
    src = FLASH_BASE + (sectorNum << gFlash->sector.shift) + offset;
    readFlashCore(src, dest, size);
}

u32 VerifyFlashSector_Core(u8 *src, u8 *target, u32 size) {
    while (size-- != 0) {
        if (*target++ != *src++) {
            return (u32)(target - 1);
        }
    }
    return 0;
}

u32 VerifyFlashSector(u16 sectorNum, u8 *src) {
    u16 i;
    u16 verifyFlashSectorCoreBuffer[0x80];
    u16 *funcSrc;
    u16 *funcDest;
    u8 *target;
    u16 size;
    u32 (*verifyFlashSectorCore)(u8 *src, u8 *target, u32 size);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    if (gFlash->romSize == 0x20000) {
        SwitchFlashBank(sectorNum / 16);
        sectorNum %= 16;
    }

    funcSrc = (u16 *)VerifyFlashSector_Core;
    funcSrc = (u16 *)((u32)funcSrc & ~1);
    funcDest = verifyFlashSectorCoreBuffer;
    i = ((u32)VerifyFlashSector - (u32)VerifyFlashSector_Core) >> 1;

    while (i != 0) {
        *funcDest++ = *funcSrc++;
        i--;
    }

    verifyFlashSectorCore = (u32 (*)(u8 *, u8 *, u32))((u32)verifyFlashSectorCoreBuffer + 1);
    target = FLASH_BASE + (sectorNum << gFlash->sector.shift);
    size = gFlash->sector.size;
    return verifyFlashSectorCore(src, target, size);
}

u32 VerifyFlashSectorNBytes(u16 sectorNum, u8 *src, u32 size) {
    u16 i;
    u16 verifyFlashSectorCoreBuffer[0x80];
    u16 *funcSrc;
    u16 *funcDest;
    u8 *target;
    u32 (*verifyFlashSectorCore)(u8 *src, u8 *target, u32 size);

    if (gFlash->romSize == 0x20000) {
        SwitchFlashBank(sectorNum / 16);
        sectorNum %= 16;
    }

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    funcSrc = (u16 *)VerifyFlashSector_Core;
    funcSrc = (u16 *)((u32)funcSrc & ~1);
    funcDest = verifyFlashSectorCoreBuffer;
    i = ((u32)VerifyFlashSector - (u32)VerifyFlashSector_Core) >> 1;

    while (i != 0) {
        *funcDest++ = *funcSrc++;
        i--;
    }

    verifyFlashSectorCore = (u32 (*)(u8 *, u8 *, u32))((u32)verifyFlashSectorCoreBuffer + 1);
    target = FLASH_BASE + (sectorNum << gFlash->sector.shift);
    return verifyFlashSectorCore(src, target, size);
}

u32 ProgramFlashSectorAndVerify(u16 sectorNum, u8 *src) {
    u8 i;
    u32 result;

    for (i = 0; i < 3; i++) {
        result = ProgramFlashSector(sectorNum, src);
        if (result != 0) {
            continue;
        }

        result = VerifyFlashSector(sectorNum, src);
        if (result == 0) {
            break;
        }
    }
    return result;
}

u32 ProgramFlashSectorAndVerifyNBytes(u16 sectorNum, void *src, u32 size) {
    u8 i;
    u32 result;

    for (i = 0; i < 3; i++) {
        result = ProgramFlashSector(sectorNum, src);
        if (result != 0) {
            continue;
        }

        result = VerifyFlashSectorNBytes(sectorNum, src, size);
        if (result == 0) {
            break;
        }
    }
    return result;
}
