#include "types.h"

struct MultiBootParam {
    u32 systemWork[5];
    u8 handshakeData;
    u8 padding15;
    u16 handshakeTimeout;
    u8 probeCount;
    u8 clientData[3];
    u8 paletteData;
    u8 responseBit;
    u8 clientBit;
    u8 reserved1;
    u8 *bootSource;
    u8 *bootEnd;
    u8 *master;
    u8 *reserved2[3];
    u32 systemWork2[4];
    u8 sendFlag;
    u8 probeTargetBit;
    u8 checkWait;
    u8 serverType;
};

#define REG_SIOCNT (*(volatile u16 *)0x04000128)
#define REG_RCNT (*(volatile u16 *)0x04000134)
#define REG_SIODATA8 (*(volatile u16 *)0x0400012A)
#define REG_SIOMULTI0 ((volatile u16 *)0x04000120)

#define MULTIBOOT_INITIALIZE(param)                                                                \
    (param)->clientBit = 0;                                                                        \
    (param)->probeCount = 0;                                                                       \
    (param)->responseBit = 0;                                                                      \
    (param)->checkWait = 15;                                                                       \
    (param)->sendFlag = 0;                                                                         \
    (param)->handshakeTimeout = 0;                                                                 \
    REG_RCNT = 0;                                                                                  \
    REG_SIOCNT = 0x2003;                                                                           \
    REG_SIODATA8 = 0

static s32 MultiBootHandShake(struct MultiBootParam *param);
static void MultiBootWaitSendDone(void);
void MultiBootStartProbe(struct MultiBootParam *param);
s32 MultiBootCheckComplete(struct MultiBootParam *param);
static s32 MultiBootSend(struct MultiBootParam *param, u16 data);
extern s32 MultiBoot(struct MultiBootParam *param);

static u16 gMultiBootRequiredData[3];

s32 MultiBootMain(struct MultiBootParam *param) {
    s32 i;
    s32 data;
    s32 response;

    if (MultiBootCheckComplete(param))
        return 0;
    if (param->checkWait > 15) {
        --param->checkWait;
        return 0;
    }
sendBurst:
    if (param->sendFlag) {
        param->sendFlag = 0;
        i = REG_SIOCNT & 0xFC;
        if (i != 8) {
            MULTIBOOT_INITIALIZE(param);
            return i ^ 8;
        }
    }
    if (param->probeCount >= 0xE0) {
        i = MultiBootHandShake(param);
        if (i)
            return i;
        if ((param->serverType == 1) && (param->probeCount > 0xE1) &&
            (MultiBootCheckComplete(param) == 0)) {
            MultiBootWaitSendDone();
            goto sendBurst;
        }
        if (MultiBootCheckComplete(param) == 0) {
            if (param->handshakeTimeout == 0) {
                MULTIBOOT_INITIALIZE(param);
                return 0x71;
            }
            --param->handshakeTimeout;
        }
        return 0;
    }

    switch (param->probeCount) {
    case 0:
        response = 0xE;
        for (i = 3; i != 0; --i) {
            if (*(volatile u16 *)(0x04000120 + i * 2) != 0xFFFF) {
                break;
            }
            response >>= 1;
        }
        response &= 0xE;
        param->responseBit = response;
        for (i = 3; i != 0; --i) {
            data = *(volatile u16 *)(0x04000120 + i * 2);
            if (param->clientBit & (1 << i)) {
                if (data != (0x7200 | (1 << i))) {
                    response = 0;
                    break;
                }
            }
        }
        param->clientBit &= response;
        if (response == 0)
            param->checkWait = 15;
        if (param->checkWait) {
            --param->checkWait;
        } else if (param->responseBit != param->clientBit) {
            MultiBootStartProbe(param);
            goto probe;
        }
    sendMasterInfo:
        return MultiBootSend(param, 0x6200 | param->clientBit);

    case 1:
    probe:
        param->probeTargetBit = 0;
        for (i = 3; i != 0; --i) {
            data = *(volatile u16 *)(0x04000120 + i * 2);
            if ((data >> 8) == 0x72) {
                gMultiBootRequiredData[i - 1] = data;
                data &= 0xFF;
                if (data == (1 << i))
                    param->probeTargetBit |= data;
            }
        }
        if (param->responseBit != param->probeTargetBit)
            goto sendMasterInfo;
        param->probeCount = 2;
        return MultiBootSend(param, 0x6100 | param->probeTargetBit);

    case 2:
        for (i = 3; i != 0; --i) {
            if (param->probeTargetBit & (1 << i)) {
                data = *(volatile u16 *)(0x04000120 + i * 2);
                if (data != gMultiBootRequiredData[i - 1])
                    param->probeTargetBit ^= 1 << i;
            }
        }
        goto sendHeader;

    case 0xD0:
        response = 1;
        for (i = 3; i != 0; --i) {
            data = *(volatile u16 *)(0x04000120 + i * 2);
            param->clientData[i - 1] = data;
            if (param->probeTargetBit & (1 << i)) {
                if (((data >> 8) != 0x72) && ((data >> 8) != 0x73)) {
                    MULTIBOOT_INITIALIZE(param);
                    return 0x60;
                }
                if (data == gMultiBootRequiredData[i - 1])
                    response = 0;
            }
        }
        if (response == 0)
            return MultiBootSend(param, 0x6300 | param->paletteData);
        param->probeCount = 0xD1;
        response = 0x11;
        for (i = 3; i != 0; --i)
            response += param->clientData[i - 1];
        param->handshakeData = response;
        return MultiBootSend(param, 0x6400 | (response & 0xFF));

    case 0xD1:
        for (i = 3; i != 0; --i) {
            data = *(volatile u16 *)(0x04000120 + i * 2);
            if (param->probeTargetBit & (1 << i)) {
                if ((data >> 8) != 0x73) {
                    MULTIBOOT_INITIALIZE(param);
                    return 0x60;
                }
            }
        }
        i = MultiBoot(param);
        if (i == 0) {
            param->probeCount = 0xE0;
            param->handshakeTimeout = 400;
            return 0;
        }
        MULTIBOOT_INITIALIZE(param);
        param->checkWait = 30;
        return 0x70;

    default:
        for (i = 3; i != 0; --i) {
            if (param->probeTargetBit & (1 << i)) {
                data = *(volatile u16 *)(0x04000120 + i * 2);
                if (((data >> 8) != (0x62 - (param->probeCount >> 1))) ||
                    ((data & 0xFF) != (1 << i)))
                    param->probeTargetBit ^= 1 << i;
            }
        }
        if (param->probeCount == 0xC4) {
            param->clientBit = param->probeTargetBit & 0xE;
            param->probeCount = 0;
            goto sendMasterInfo;
        }
    sendHeader:
        if (param->probeTargetBit == 0) {
            MULTIBOOT_INITIALIZE(param);
            return 0x50;
        }
        param->probeCount += 2;
        if (param->probeCount == 0xC4)
            goto sendMasterInfo;
        i = MultiBootSend(param, (param->master[param->probeCount - 3] << 8) |
                                     param->master[param->probeCount - 4]);
        if (i)
            return i;
        if (param->serverType == 1) {
            MultiBootWaitSendDone();
            goto sendBurst;
        }
        return 0;
    }
}

static s32 MultiBootSend(struct MultiBootParam *param, u16 data) {
    s32 status;

    status = REG_SIOCNT & 0x8C;
    if (status != 8) {
        MULTIBOOT_INITIALIZE(param);
        return status ^ 8;
    }

    REG_SIODATA8 = data;
    REG_SIOCNT = 0x2083;
    param->sendFlag = 1;
    return 0;
}

void MultiBootStartProbe(struct MultiBootParam *param) {
    if (param->probeCount != 0) {
        MULTIBOOT_INITIALIZE(param);
        return;
    }

    param->checkWait = 0;
    param->clientBit = 0;
    param->probeCount = 1;
}

void MultiBootStartMaster(struct MultiBootParam *param, const u8 *source, s32 length,
                          u8 paletteColor, s8 paletteSpeed) {
    s32 palette;

    if ((param->probeCount != 0) || (param->clientBit == 0) || (param->checkWait != 0)) {
        MULTIBOOT_INITIALIZE(param);
        return;
    }

    param->bootSource = (u8 *)source;
    length = (length + 15) & ~15;
    if ((length < 0x100) || (length > 0x40000)) {
        MULTIBOOT_INITIALIZE(param);
        return;
    }
    param->bootEnd = (u8 *)(source + length);

    switch (paletteSpeed) {
    case -4:
    case -3:
    case -2:
    case -1:
        palette = (paletteColor << 3) | (3 - paletteSpeed);
        break;
    case 0:
        palette = 0x38 | paletteColor;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        palette = (paletteColor << 3) | (paletteSpeed - 1);
        break;
    }

    param->paletteData = ((palette & 0x3F) << 1) | 0x81;
    param->probeCount = 0xD0;
}

static s32 MultiBootHandShake(struct MultiBootParam *param) {
    s32 i;
    s32 data;

#define sendData (param->systemWork[0])
#define requiredData (param->systemWork[1])
    switch (param->probeCount) {
    case 0xE0:
    restart:
        param->probeCount = 0xE1;
        requiredData = 0;
        sendData = 0x100000;
        return MultiBootSend(param, 0);
    default:
        for (i = 3; i != 0; --i) {
            data = REG_SIOMULTI0[i];
            if ((param->clientBit & (1 << i)) && (data != requiredData))
                goto restart;
        }
        ++param->probeCount;
        requiredData = sendData & 0xFFFF;
        if (sendData == 0) {
            requiredData = param->master[0xAC] | (param->master[0xAD] << 8);
            sendData = requiredData << 5;
        }
        sendData >>= 5;
    send:
        return MultiBootSend(param, sendData);
    case 0xE7:
    case 0xE8:
        for (i = 3; i != 0; --i) {
            data = REG_SIOMULTI0[i];
            if ((param->clientBit & (1 << i)) && (data != requiredData)) {
                MULTIBOOT_INITIALIZE(param);
                return 0x71;
            }
        }
        ++param->probeCount;
        if (param->probeCount == 0xE9)
            return 0;
        sendData = param->master[0xAE] | (param->master[0xAF] << 8);
        requiredData = sendData;
        goto send;
    }
#undef sendData
#undef requiredData
}

void MultiBootInit(struct MultiBootParam *param) { MULTIBOOT_INITIALIZE(param); }

s32 MultiBootCheckComplete(struct MultiBootParam *param) {
    if (param->probeCount == 0xE9)
        return 1;
    return 0;
}

static inline void MultiBootWaitCycles(u32 cycles) {
    asm("mov r2, pc\n\t"
        "lsr r2, #24\n\t"
        "mov r1, #12\n\t"
        "cmp r2, #0x02\n\t"
        "beq MultiBootWaitCyclesLoop\n\t"
        "mov r1, #13\n\t"
        "cmp r2, #0x08\n\t"
        "beq MultiBootWaitCyclesLoop\n\t"
        "mov r1, #4\n\t"
        "MultiBootWaitCyclesLoop:\n\t"
        "sub r0, r1\n\t"
        "bgt MultiBootWaitCyclesLoop\n\t"
        :
        :
        : "r0", "r1", "r2");
}

static void MultiBootWaitSendDone(void) {
    s32 i;

    for (i = 0; i < 31069; i++) {
        if ((REG_SIOCNT & 0x80) == 0)
            break;
    }
    MultiBootWaitCycles(600);
}
