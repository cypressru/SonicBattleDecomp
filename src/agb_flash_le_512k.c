#include "types.h"

#define FLASH_BASE ((u8 *)0x0E000000)
#define FLASH_WRITE(address, data) (*(volatile u8 *)(FLASH_BASE + (address)) = (data))
#define REG_WAITCNT (*(volatile u16 *)0x04000204)

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
    u16 ids;
};

extern const struct FlashType *gFlash;
extern u16 gFlashNumRemainingBytes;
extern u16 (*WaitForFlashWrite)(u8 phase, u8 *address, u8 lastData);

extern void SetReadFlash1(u16 *dest);

u16 EraseFlashChip_LE(void) {
    u16 result;
    u16 readFlash1Buffer[0x20];

    REG_WAITCNT = (REG_WAITCNT & ~3) | gFlash->wait[0];

    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0x80);
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0x10);

    SetReadFlash1(readFlash1Buffer);
    result = WaitForFlashWrite(3, FLASH_BASE, 0xFF);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    return result;
}

u16 EraseFlashSector_LE(u16 sectorNum) {
    u16 result;
    u8 *address;
    u16 readFlash1Buffer[0x20];

    if (sectorNum >= 0x10) {
        return 0x80FF;
    }

    REG_WAITCNT = (REG_WAITCNT & ~3) | gFlash->wait[0];
    address = FLASH_BASE + (sectorNum << gFlash->sector.shift);

    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0x80);
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    *address = 0x30;

    SetReadFlash1(readFlash1Buffer);
    result = WaitForFlashWrite(2, address, 0xFF);

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    return result;
}

u16 ProgramByte(u8 *src, u8 *dest) {
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0xA0);
    *dest = *src;

    return WaitForFlashWrite(1, dest, *src);
}

static u32 VerifyEraseSector_Core(u8 *dest);
static u16 VerifyEraseSector(u8 *dest, u8 *src);

u16 ProgramFlashSector_LE(u16 sectorNum, void *src) {
    u16 result;
    u8 *dest;
    u16 verifyEraseSectorCoreBuffer[0x30];
    u16 *funcSrc;
    u16 *funcDest;
    u16 i;
    u8 tryNum;
    u8 erasesToTry;
    u8 j;

    if (sectorNum > 15) {
        return 0x80FF;
    }

    dest = FLASH_BASE + (sectorNum << gFlash->sector.shift);
    funcSrc = (u16 *)((u32)VerifyEraseSector_Core & ~1);
    funcDest = verifyEraseSectorCoreBuffer;
    i = (u32)VerifyEraseSector - (u32)VerifyEraseSector_Core;

    while (i != 0) {
        *funcDest++ = *funcSrc++;
        i -= 2;
    }

    tryNum = 0;
    while ((result = EraseFlashSector_LE(sectorNum)) ||
           (result = VerifyEraseSector(dest, (u8 *)((u32)verifyEraseSectorCoreBuffer + 1)))) {
        tryNum++;
        if (tryNum == 0x51) {
            return result;
        }
    }

    erasesToTry = 1;
    if (tryNum != 0) {
        erasesToTry = 6;
    }

    for (j = 1; j <= erasesToTry; j++) {
        EraseFlashSector_LE(sectorNum);
    }

    SetReadFlash1(verifyEraseSectorCoreBuffer);
    REG_WAITCNT = (REG_WAITCNT & ~3) | gFlash->wait[0];
    gFlashNumRemainingBytes = gFlash->sector.size;
    while (gFlashNumRemainingBytes && (result = ProgramByte(src, dest), result == 0)) {
        gFlashNumRemainingBytes--;
        src++;
        dest++;
    }
    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    return result;
}

static u32 VerifyEraseSector_Core(u8 *dest) {
    u32 sectorNum;
    u8 src;

    for (sectorNum = gFlash->sector.size; sectorNum != 0; sectorNum--) {
        src = *dest++;
        if (src != 0xFF) {
            break;
        }
    }
    return sectorNum;
}

static u16 VerifyEraseSector(u8 *dest, u8 *src) {
    u32 result;

    result = ((u32 (*)(u8 *))((u32)src))(dest);
    if (result != 0) {
        return 0x8004;
    }
    return 0;
}
