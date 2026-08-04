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
    union {
        struct {
            u8 makerId;
            u8 deviceId;
        } separate;
        u16 joined;
    } ids;
};

struct FlashSetupInfo {
    u16 (*programFlashSector)(u16 sectorNum, void *src);
    u16 (*eraseFlashChip)(void);
    u16 (*eraseFlashSector)(u16 sectorNum);
    u16 (*waitForFlashWrite)(u8 phase, u8 *address, u8 lastData);
    const u16 *maxTime;
    struct FlashType type;
};

extern const struct FlashSetupInfo *const gSetup512KInfos[];

extern u16 (*ProgramFlashSector)(u16 sectorNum, void *src);
extern u16 (*EraseFlashChip)(void);
extern u16 (*EraseFlashSector)(u16 sectorNum);
extern u16 (*WaitForFlashWrite)(u8 phase, u8 *address, u8 lastData);
extern const u16 *gFlashMaxTime;
extern const struct FlashType *gFlash;
extern u8 gFlashTimeoutFlag;
extern u8 (*PollFlashStatus)(u8 *address);

extern u16 ReadFlashId(void);
extern void StartFlashTimer(u8 phase);
extern void StopFlashTimer(void);

u16 IdentifyFlash(void) {
    u16 result;
    u16 flashId;
    const struct FlashSetupInfo *const *setupInfo;

    REG_WAITCNT = (REG_WAITCNT & ~3) | 3;
    flashId = ReadFlashId();

    setupInfo = gSetup512KInfos;
    result = 1;

    for (;;) {
        if ((*setupInfo)->type.ids.separate.makerId == 0) {
            break;
        }

        if (flashId == (*setupInfo)->type.ids.joined) {
            result = 0;
            break;
        }

        setupInfo++;
    }

    ProgramFlashSector = (*setupInfo)->programFlashSector;
    EraseFlashChip = (*setupInfo)->eraseFlashChip;
    EraseFlashSector = (*setupInfo)->eraseFlashSector;
    WaitForFlashWrite = (*setupInfo)->waitForFlashWrite;
    gFlashMaxTime = (*setupInfo)->maxTime;
    gFlash = &(*setupInfo)->type;

    return result;
}

u16 WaitForFlashWrite512K_Common(u8 phase, u8 *address, u8 lastData) {
    u16 result = 0;
    u8 status;

    StartFlashTimer(phase);

    while ((status = PollFlashStatus(address)) != lastData) {
        if (gFlashTimeoutFlag) {
            if (PollFlashStatus(address) == lastData) {
                break;
            }

            if (gFlash->ids.separate.makerId == 0xC2) {
                FLASH_WRITE(0x5555, 0xF0);
            }

            result = phase | 0xC000;
            break;
        }
    }

    StopFlashTimer();
    return result;
}
