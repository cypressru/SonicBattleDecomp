#include "types.h"

typedef volatile u16 vu16;

struct MultiSioSyncState {
    u8 isParent;
    u8 stage;
    u8 unknown2Low : 4;
    u8 connectedFlags : 4;
    u8 receivedFlags;
    u8 sendReady;
    u8 receiveReady;
    u8 unknown6Low : 4;
    u8 status4 : 1;
    u8 status5 : 1;
    u8 status6 : 1;
    u8 status7 : 1;
    u8 errorFlags;
    u8 syncCounter;
    u8 sioInterrupted;
    u8 unusedA;
    u8 frameCounter;
    u8 paddingC[8];
    s32 sendIndex;
    s32 receiveIndex;
    void *sendBuffer;
    void *nextSendBuffer;
    void *receiveBuffer;
    void *nextReceiveBuffer;
    void *completedReceiveBuffer;
    u8 buffers[0x150];
};

struct SioMultiCnt {
    u16 baudRate : 2;
    u16 si : 1;
    u16 sd : 1;
    u16 id : 2;
    u16 error : 1;
    u16 enable : 1;
    u16 unused8 : 4;
    u16 mode : 2;
    u16 intrEnable : 1;
    u16 unused15 : 1;
    u16 data;
};

struct MultiSioPacket {
    u8 counter;
    u8 receivedFlags : 4;
    u8 flag4 : 1;
    u8 flag5 : 1;
    u8 flag6 : 1;
    u8 flag7 : 1;
    u16 checksum;
    u8 data[16];
};

struct MultiSioSendState {
    u8 padding[3];
    u8 flags;
};

extern void CpuSet(const void *, void *, u32);
extern struct MultiSioSyncState gMultiSioSyncState;
extern struct MultiSioSendState gMultiSioSendState;
extern s32 FUN_08018918(void *);

#define REG_SIOCNT (*(vu16 *)0x04000128)
#define REG_TM3CNT (*(volatile u32 *)0x0400010C)
#define REG_RCNT (*(vu16 *)0x04000134)
#define REG_IE (*(vu16 *)0x04000200)
#define REG_IF (*(vu16 *)0x04000202)
#define REG_IME (*(vu16 *)0x04000208)

void MultiSioSyncInitialize(u32 connectedFlags) {
    u32 zero;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;

    REG_RCNT = 0;
    REG_SIOCNT = 0x2000;
    REG_SIOCNT |= 0x4003;

    zero = 0;
    CpuSet(&zero, &gMultiSioSyncState, 0x05000060);
    gMultiSioSyncState.connectedFlags = connectedFlags;
    gMultiSioSyncState.sendIndex = 12;
    gMultiSioSyncState.receiveIndex = 12;
    gMultiSioSyncState.sendBuffer = &gMultiSioSyncState.buffers[0x00];
    gMultiSioSyncState.nextSendBuffer = &gMultiSioSyncState.buffers[0x18];
    gMultiSioSyncState.receiveBuffer = &gMultiSioSyncState.buffers[0x30];
    gMultiSioSyncState.nextReceiveBuffer = &gMultiSioSyncState.buffers[0x90];
    gMultiSioSyncState.completedReceiveBuffer = &gMultiSioSyncState.buffers[0xF0];

    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

s32 FUN_08018730(void *receive) {
    struct SioMultiCnt sioControl;

    sioControl = *(volatile struct SioMultiCnt *)0x04000128;
    switch (gMultiSioSyncState.stage) {
    case 0:
        if (sioControl.id == 0) {
            if (!sioControl.sd || sioControl.enable)
                break;

            if (!sioControl.si && (gMultiSioSyncState.sendIndex == 12)) {
                REG_IME = 0;
                REG_IE &= 0xFF7F;
                REG_IE |= 0x40;
                REG_IME = 1;

                ((volatile struct SioMultiCnt *)0x04000128)->intrEnable = 0;
                REG_TM3CNT = 0xABFB;
                REG_IF = 0xC0;
                gMultiSioSyncState.isParent = 8;
            }
        }

        gMultiSioSyncState.stage = 1;
    case 1:
        if (gMultiSioSyncState.connectedFlags != 0) {
            if (!gMultiSioSyncState.status6) {
                if (gMultiSioSyncState.syncCounter < 8)
                    gMultiSioSyncState.syncCounter++;
                else
                    gMultiSioSyncState.stage = 2;
            }
        }
    case 2:
        FUN_08018918(receive);
        break;
    }

    gMultiSioSyncState.frameCounter++;
    return gMultiSioSyncState.receivedFlags | gMultiSioSyncState.status4 << 4 |
           gMultiSioSyncState.status5 << 5 | gMultiSioSyncState.status6 << 6 |
           (gMultiSioSyncState.isParent == 8) << 7 | gMultiSioSyncState.connectedFlags << 8 |
           (gMultiSioSyncState.errorFlags != 0) << 12 | (sioControl.id > 3) << 13 |
           (gMultiSioSyncState.syncCounter >> 3) << 15;
}

void FUN_0801886c(const void *data, u32 flag) {
    s32 checksum;
    u32 i;

    checksum = 0;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->flag4 = flag & 1;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->flag5 = gMultiSioSendState.flags & 1;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->flag6 = gMultiSioSyncState.status6;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->counter =
        gMultiSioSyncState.frameCounter;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->receivedFlags =
        gMultiSioSyncState.unknown2Low ^ gMultiSioSyncState.receivedFlags;
    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->checksum = 0;
    CpuSet(data, ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->data, 0x04000004);

    for (i = 0; i < 10; i++)
        checksum += ((u16 *)gMultiSioSyncState.sendBuffer)[i];

    ((struct MultiSioPacket *)gMultiSioSyncState.sendBuffer)->checksum = ~checksum - 12;
    gMultiSioSyncState.sendReady = 1;
}
