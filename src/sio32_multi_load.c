#include "types.h"

typedef unsigned long long u64;

struct Sio32MultiLoadArea {
    u8 type;
    u8 state;
    u8 frameCounter;
    u8 downloadSuccessFlag;
    u32 *data;
    s32 dataCounter;
    u32 checkSum;
    u32 checkSumTemporary;
    s32 checkSumCounter;
};

#define REG_SIODATA32 (*(volatile u32 *)0x04000120)
#define REG_SIOCNT (*(volatile u16 *)0x04000128)
#define REG_TIMER3 (*(volatile u32 *)0x0400010C)
#define REG_TIMER3_H (*(volatile u16 *)0x0400010E)
#define REG_IE (*(volatile u16 *)0x04000200)
#define REG_IF (*(volatile u16 *)0x04000202)
#define REG_IME (*(volatile u16 *)0x04000208)

extern void CpuSet(const void *source, void *destination, u32 control);

struct Sio32MultiLoadArea gSio32MultiLoadArea;

u32 Sio32MultiLoadMain(u32 *progressCounter) {
    s32 dataCounter;
    s32 savedDataCounter;

    switch (gSio32MultiLoadArea.state) {
    case 0:
        if (gSio32MultiLoadArea.type || gSio32MultiLoadArea.frameCounter)
            gSio32MultiLoadArea.state = 1;
        break;
    case 1:
        if (gSio32MultiLoadArea.type == 1) {
            if (gSio32MultiLoadArea.frameCounter < 6)
                break;
        } else {
            REG_SIOCNT = 0x1000;
        }
        REG_SIODATA32 = 0;
        REG_IF = 0xC0;
        if (gSio32MultiLoadArea.type == 1) {
            REG_SIOCNT |= 0x80;
            REG_TIMER3 = 0x00C0F318;
            REG_IME = 0;
            REG_IE |= 0x40;
            REG_IME = 1;
        } else {
            REG_SIOCNT |= 0x4080;
            REG_IME = 0;
            REG_IE |= 0x80;
            REG_IME = 1;
        }
        gSio32MultiLoadArea.frameCounter = 0;
        gSio32MultiLoadArea.state = 2;
        break;
    case 2:
        dataCounter = gSio32MultiLoadArea.dataCounter;
        savedDataCounter = dataCounter;
        if (dataCounter > 0x2000)
            dataCounter = 0x2000;
        else if (dataCounter < 0)
            dataCounter = 0;
        if (progressCounter)
            *progressCounter = dataCounter;
        if (gSio32MultiLoadArea.type != 1) {
            while (gSio32MultiLoadArea.checkSumCounter < dataCounter) {
                gSio32MultiLoadArea.checkSumTemporary +=
                    ((s32 *)gSio32MultiLoadArea.data)[gSio32MultiLoadArea.checkSumCounter++];
            }
            if (savedDataCounter > 0x2000) {
                if ((gSio32MultiLoadArea.checkSum += gSio32MultiLoadArea.checkSumTemporary) == -1)
                    gSio32MultiLoadArea.downloadSuccessFlag = 1;
            }
        }
        if ((savedDataCounter > 0x2000) || (gSio32MultiLoadArea.frameCounter == 0x8C))
            gSio32MultiLoadArea.state = 3;
        break;
    case 3:
        REG_IME = 0;
        REG_IE &= 0xFF3F;
        REG_IME = 1;
        REG_SIOCNT = 0x1000;
        *(volatile u32 *)0x04000128 = 0x2000;
        *(volatile u32 *)0x04000128 = 0x2003;
        *(volatile u64 *)0x04000120 = 0;
        if (gSio32MultiLoadArea.type)
            REG_TIMER3 = 0;
        REG_IF = 0xC0;
        if (!gSio32MultiLoadArea.type)
            return 1;
        gSio32MultiLoadArea.frameCounter = 0;
        gSio32MultiLoadArea.state = 4;
        break;
    case 4:
        if (gSio32MultiLoadArea.frameCounter >= 3)
            return 1;
        break;
    }
    ++gSio32MultiLoadArea.frameCounter;
    return 0;
}

void Sio32MultiLoadIntr(void) {
    u32 received = REG_SIODATA32;

    if (gSio32MultiLoadArea.type != 1)
        REG_SIOCNT |= 0x80;
    if (gSio32MultiLoadArea.type == 1) {
        REG_TIMER3_H = 0;
        if (gSio32MultiLoadArea.dataCounter < 0)
            REG_SIODATA32 = 0xFEFEFEFE;
        else if (gSio32MultiLoadArea.dataCounter < 0x2000)
            REG_SIODATA32 = gSio32MultiLoadArea.data[gSio32MultiLoadArea.dataCounter];
        else
            REG_SIODATA32 = gSio32MultiLoadArea.checkSum;
    } else {
        if (gSio32MultiLoadArea.dataCounter < 0) {
            if (received != 0xFEFEFEFE)
                --gSio32MultiLoadArea.dataCounter;
        } else if (gSio32MultiLoadArea.dataCounter < 0x2000) {
            gSio32MultiLoadArea.data[gSio32MultiLoadArea.dataCounter] = received;
        } else {
            gSio32MultiLoadArea.checkSum = received;
        }
    }
    if (gSio32MultiLoadArea.dataCounter < 0x2003) {
        ++gSio32MultiLoadArea.dataCounter;
        if (gSio32MultiLoadArea.type == 1) {
            REG_SIOCNT |= 0x80;
            REG_TIMER3_H = 0xC0;
        }
    }
}

void Sio32MultiLoadInit(u32 type, void *data) {
    s32 checkSum = 0;
    s32 i;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    {
        volatile u32 zero = 0;
        CpuSet((const void *)&zero, &gSio32MultiLoadArea, 0x05000006);
    }
    *(volatile u32 *)0x04000128 = 0x2003;
    gSio32MultiLoadArea.data = data;
    gSio32MultiLoadArea.dataCounter = -1;
    if (type) {
        REG_TIMER3 = 0;
        gSio32MultiLoadArea.type = 1;
        for (i = 0; i < 0x2000; ++i)
            checkSum += ((s32 *)data)[i];
        gSio32MultiLoadArea.checkSum = ~checkSum;
        REG_SIOCNT = 0x1000;
        REG_SIOCNT = 0x1001;
    }
}
