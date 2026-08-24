#include "types.h"

typedef u32 (*UnknownEntityCondition)(u8 value, u8 other, const u32 **stream);

struct UnknownEntity {
    void (*callback)(void);
    const void *data;
    u16 field8;
    u16 field10;
    u8 field12;
    u8 field13;
    u8 field14;
    u8 field15;
    u8 field16;
    u8 filler17;
    u8 field18;
    u8 filler19;
    u8 field20;
    u8 filler21[3];
};

struct UnknownEntityData {
    u8 filler0[16];
    u8 field16;
    u8 filler17[3];
    u16 field20;
    u8 filler22[4];
    s16 field26;
    u8 filler28[9];
    u8 field37;
    u8 filler38[12];
    u8 field50;
    u8 filler51[3];
    s16 field54[4];
    s16 field62[4];
    u8 filler70[2];
    s32 field72[4];
    s16 field88[14];
    u32 field116;
    s32 field120[13];
    u16 field172;
    u16 field174;
    u32 field176;
    u32 field180;
    u8 filler184[7];
    u8 field191;
    u8 filler192[4];
    u8 field196;
    u8 filler197[3];
    u16 field200;
    u8 filler202[50];
};

extern struct UnknownEntity gUnknown_03003db0[];
extern struct UnknownEntityData gUnknown_03001c40[];
extern u32 FUN_08020160(u32 threshold);
extern const UnknownEntityCondition gUnknown_08ed8b04[];

u32 FUN_0801f080(u8 value, u8 other, const u32 **stream) {
    u32 word = **stream;
    s16 operand = word >> 16;
    u8 operation = (word & 0xFF00) >> 8;
    u32 result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field54[other] == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field54[other] < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field54[other] > operand) {
            result = 1;
        }
        break;
    }

    (*stream)++;
    return result;
}

u32 FUN_0801f128(u8 value, u8 other, const u32 **stream) {
    u32 word = **stream;
    s16 operand = word >> 16;
    u8 operation = (word & 0xFF00) >> 8;
    u32 result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field62[other] == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field62[other] < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field62[other] > operand) {
            result = 1;
        }
        break;
    }

    (*stream)++;
    return result;
}

u32 FUN_0801f1d0(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;
    s16 operand = word >> 16;
    u8 operation = (word & 0xFF00) >> 8;
    u32 result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field88[other] == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field88[other] < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field88[other] > operand) {
            result = 1;
        }
        break;
    }

    return result;
}

u32 FUN_0801f274(u8 value, u8 other, const u32 **stream) {
    const u32 *current = *stream;
    u32 word = *current;
    s32 operand;
    u8 operation;
    u32 result;

    *stream = current + 1;
    operand = current[1];
    operation = (word & 0xFF00) >> 8;
    result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field72[other] == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field72[other] < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field72[other] > operand) {
            result = 1;
        }
        break;
    }

    (*stream)++;
    return result;
}

u32 FUN_0801f308(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;

    return FUN_08020160(word >> 16);
}

u32 FUN_0801f31c(u8 value, u8 other, const u32 **stream) {
    *stream += 1;

    if ((gUnknown_03001c40[value].field50 & 0xF) != 0) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f350(u8 value, u8 other, const u32 **stream) {
    u32 result;
    const UnknownEntityCondition *conditions;

    (*stream)++;
    result = 0;
    conditions = gUnknown_08ed8b04;
    for (;;) {
        const u32 *current = *stream;
        u8 operation = *(const u8 *)current;

        if (operation == 0xFF) {
            return result;
        }
        if (operation == 7) {
            *stream = current + 1;
            return result;
        } else if (conditions[*(const u8 *)*stream](value, other, stream) != 0) {
            result = 1;
        }
    }
}

u32 FUN_0801f3a4(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return 1;
}

u32 FUN_0801f3b0(u8 value, u8 other, const u32 **stream) {
    u32 operand = (*stream)[1];
    *stream += 2;

    return (gUnknown_03001c40[other].field180 & operand) == 1;
}

u32 FUN_0801f3e4(u8 value, u8 other, const u32 **stream) {
    u32 operand = (*stream)[1];
    *stream += 2;

    return (gUnknown_03001c40[value].field180 & operand) == 1;
}

u32 FUN_0801f418(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;

    {
        u16 operand = word >> 16;
        return gUnknown_03001c40[value].field20 == operand;
    }
}

u32 FUN_0801f448(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return gUnknown_03003db0[value].field10 == 0;
}

u32 FUN_0801f474(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;
    u16 operand = word >> 16;
    u8 operation = (word & 0xFF00) >> 8;
    u32 result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field191 == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field191 < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field191 > operand) {
            result = 1;
        }
        break;
    }

    return result;
}

u32 FUN_0801f4f4(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return (u16)(gUnknown_03001c40[other].field20 - 252) <= 3;
}

u32 FUN_0801f524(u8 value, u8 other, const u32 *stream) {
    if (*(const u8 *)stream != 0xFF) {
        const UnknownEntityCondition *conditions = gUnknown_08ed8b04;
        u32 mask = 0xFF;

        do {
            if (conditions[*stream & mask](value, other, &stream) == 0) {
                return 0x10;
            }
        } while ((*stream & mask) != 0xFF);
    }

    return ((const u16 *)stream)[1];
}

u32 FUN_0801f578(u8 value, u8 other, const u32 **streams) {
    while (*streams != 0) {
        const u32 *stream = *streams;
        const u32 *current = stream;
        u32 result;

        if (*(const u8 *)current != 0xFF) {
            const UnknownEntityCondition *conditions = gUnknown_08ed8b04;
            u32 mask = 0xFF;

            do {
                if (conditions[*current & mask](value, other, &stream) == 0) {
                    result = 0x10;
                    goto checkResult;
                }
                current = stream;
            } while ((*stream & mask) != 0xFF);
        }

        result = ((const u16 *)stream)[1];

    checkResult:
        if (result != 0x10) {
            return result;
        }
        streams++;
    }

    return 0x10;
}

const UnknownEntityCondition gUnknown_08ed8b04[] = {
    FUN_0801f080, FUN_0801f128, FUN_0801f274, FUN_0801f1d0, FUN_0801f308,
    FUN_0801f31c, FUN_0801f350, FUN_0801f3a4, FUN_0801f3b0, FUN_0801f3e4,
    FUN_0801f418, FUN_0801f448, FUN_0801f474, FUN_0801f4f4,
};
