#include "types.h"

#define FLASH_BASE ((u8 *)0x0E000000)
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

extern u16 EraseFlashSector_LE(u16 sectorNum);
extern void SetReadFlash1(u16 *dest);
extern u16 ProgramByte(void *src, u8 *dest);

u16 ProgramFlashSector_MX(u16 sectorNum, void *src) {
    u16 result;
    u8 *dest;
    u16 readFlash1Buffer[0x20];

    if (sectorNum >= gFlash->sector.count) {
        return 0x80FF;
    }

    result = EraseFlashSector_LE(sectorNum);
    if (result != 0) {
        return result;
    }

    SetReadFlash1(readFlash1Buffer);

    REG_WAITCNT = (REG_WAITCNT & ~3) | gFlash->wait[0];

    gFlashNumRemainingBytes = gFlash->sector.size;
    dest = FLASH_BASE + (sectorNum << gFlash->sector.shift);

    while (gFlashNumRemainingBytes > 0) {
        result = ProgramByte(src, dest);
        if (result != 0) {
            break;
        }

        gFlashNumRemainingBytes--;
        src++;
        dest++;
    }

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;

    return result;
}
