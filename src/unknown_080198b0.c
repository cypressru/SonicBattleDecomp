#include "types.h"
#include <string.h>

struct UnknownListNode;

extern void FUN_08012b98(u32 value);
extern void FUN_08016078(u32 value);
extern void FUN_0801bcac(void);
extern void FUN_0801b394(void);
extern void FUN_0801c770(void);
extern void FUN_08020840(u16 value);
extern u32 FUN_080205d0(void);
extern u32 FUN_0801cfc8(u8 value);
extern u8 FUN_0801d068(u8 value);
extern u8 FUN_0801d188(u8 value);
extern void FUN_0801d870(u8 value);
extern void FUN_0801fed8(u8 value, u32 other);
extern void FUN_08018664(void);
extern void *FUN_08021180(void *value);
extern void FUN_08049108(u16 value);
extern void FUN_080490b4(u16 value);
extern void FUN_080491d4(const void *value, u16 other);
extern void FUN_080491e4(const void *value, u16 other);
extern void FUN_08049234(const void *value);
extern void FUN_0804962c(void);
extern void FUN_080496ac(void);
extern void FUN_0804a0a0(const void *value, u16 other);
extern void FUN_0804a0c4(const void *value, u16 first, u16 second);
extern void FUN_0804a1a0(const void *value, u16 first, s8 second);
extern void FUN_0804af6c(struct UnknownListNode *node, const void *data);
extern u16 FUN_0804afa4(u32 value, u32 divisor);

typedef void (*UnknownCallback)(void);

struct UnknownEntity {
    UnknownCallback callback;
    const void *data;
    u16 field8;
    u16 field10;
    u8 field12;
    u8 field13;
    u8 field14;
    u8 field15;
    u8 field16;
    u8 filler17[7];
};

struct UnknownEntityData {
    u8 filler0[16];
    u8 field16;
    u8 filler17[3];
    u16 field20;
    u8 filler22[28];
    u8 field50;
    u8 filler51[3];
    s16 field54[4];
    s16 field62[4];
    u8 filler70[110];
    u32 field180;
    u8 filler184[7];
    u8 field191;
    u8 filler192[60];
};

struct UnknownSoundIndex {
    u8 filler0[4];
    u16 index;
    u8 filler6[2];
};

struct UnknownSoundEntry {
    const void *value;
    u8 filler4[8];
};

struct UnknownPosition {
    const void *field0;
    s16 x;
    s16 y;
    u16 tile;
    u8 field10;
    u8 field11;
    u8 field12;
    u8 field13;
    u8 field14;
};

struct UnknownListNode {
    const void *data;
    u8 field4;
    u8 previous;
    u8 field6;
    u8 next;
    struct UnknownPosition *position;
    void *allocation;
};

struct UnknownQueuedValue {
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;
};

struct UnknownState080201f8 {
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;
    u16 fifth;
    u8 sixth;
    u8 seventh;
    u8 eighth;
};

struct UnknownCommandRecord {
    u32 first;
    u32 second;
    u32 third;
    u16 fourth;
    u16 type;
};

struct UnknownBufferState {
    u32 field0;
    const u8 *source;
    u8 *destination;
    u32 end;
    u16 width;
    u16 rowSize;
    u16 stride;
    u16 blockSize;
    u32 fill;
};

struct UnknownHeapBlock {
    struct UnknownHeapBlock *next;
    s32 size;
};

struct UnknownState08021484 {
    u8 filler0[29];
    u8 firstFlags;
    u8 secondFlags;
};

struct UnknownState03002110 {
    u8 filler0[0x120];
    u8 validity[0x200];
    u8 selector;
    u8 filler321;
    u8 records[1];
};

struct UnknownState03004dbc {
    u8 filler0[2];
    u8 field2;
    u8 field3;
    u8 filler4[8];
    u16 field12;
    u16 field14;
    u16 field16;
    u8 filler18[2];
    u32 bits[16];
};

struct UnknownAllocation248f0 {
    u8 filler0[6];
    u8 field6;
    u8 filler7[7];
    u8 field14;
};

extern void (*gUnknown_03002030)(void);
extern u8 gUnknown_03001620;
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03001b00[8];
extern struct UnknownEntity gUnknown_03003db0[];
extern struct UnknownEntityData gUnknown_03001c40[];
extern u8 gUnknown_03003e10;
extern u16 gUnknown_08071264[];
extern const u8 gUnknown_08ed89d0[];
extern const u8 gUnknown_08ed89e4[];
extern const u8 gUnknown_08ed89ec[];
extern const u8 gUnknown_08ed89f8[];
extern const u8 gUnknown_08ed8a0c[];
extern const u8 gUnknown_08ed8a8c[];
extern const u8 gUnknown_08ed8a9c[];
extern const u8 gUnknown_08ed8aac[];
extern const u8 gUnknown_08ed8ae4[];
extern const struct UnknownSoundIndex gUnknown_08bf7244[];
extern const struct UnknownSoundEntry gUnknown_08bf71fc[];
extern u8 gUnknown_03000008[100];
extern u8 gUnknown_0300006c;
extern struct UnknownListNode gUnknown_03003e20[100];
extern u8 gUnknown_030000c0;
extern u16 gUnknown_03000070[20][2];
extern const void *gUnknown_03003150[];
extern u8 gUnknown_03004470;
extern u32 gUnknown_0300019c;
extern s8 gUnknown_030048d4;
extern u8 gUnknown_030048d0;
extern struct UnknownQueuedValue gUnknown_030044d0[];
extern u8 gUnknown_0300019a;
extern u8 gUnknown_030044c0;
extern u8 gUnknown_030000c8[4];
extern struct UnknownState080201f8 gUnknown_030048e0;
extern u32 gUnknown_030048f0;
extern struct UnknownCommandRecord gUnknown_03004900[];
extern u16 gUnknown_03004b00;
extern u8 gUnknown_03004b04;
extern u16 gUnknown_03004b08;
extern struct UnknownBufferState gUnknown_03004b10;
extern const u8 gUnknown_0807173c[];
extern u16 gUnknown_03004b30[];
extern struct UnknownHeapBlock *gUnknown_03004d30;
extern struct UnknownHeapBlock gUnknown_030033e0;
extern u32 gUnknown_03004d34;
extern u32 gUnknown_03004d38;
extern void CpuSet(const void *source, void *destination, u32 mode);
extern struct UnknownState08021484 gUnknown_03004d40;
extern u32 gUnknown_020000e0;
extern const void *gUnknown_03004d94;
extern u32 gUnknown_03004d8c;
extern void SoftResetExram(u32 flags);
extern void LZ77UnCompWram(const void *source, void *destination);
extern u32 FUN_08018c8c(void *state);
extern u32 FUN_0801950c(void *state);
extern void ReadFlash(u16 sector, u32 offset, void *destination, u32 size);
extern u32 VerifyFlashSector(u16 sector, u8 *source);
extern u16 SetFlashTimerIntr(u8 timer, void (**handler)(void));
extern void (*gUnknown_0300315c)(void);
extern void (*gUnknown_03006788)(void);
extern u32 (*gUnknown_0300677c)(u16 sector, u8 *source);
extern const u8 gUnknown_0807b780[];
extern const u32 gUnknown_0807b880[];
extern struct UnknownState03004dbc *gUnknown_03004dbc;
extern struct UnknownState03002110 gUnknown_03002110;
extern const u32 gUnknown_0807163c[];
extern const u8 gUnknown_08edb498[];
extern const u8 gUnknown_08edb820[];
extern const u8 gUnknown_08edb4f0[];
extern const u8 gUnknown_08edb678[];
extern const u16 gUnknown_08edb834[];
extern const void *gUnknown_08edb750;
extern const u16 gUnknown_08edb91c[];
extern const void *gUnknown_08edb760[];
extern u8 gUnknown_08edb5c8[];
extern const void *gUnknown_08edb7f0[];
extern const u16 gUnknown_08edb854[];
extern const void *gUnknown_08edb740[];
extern const u8 gUnknown_08edb84c[];
extern const u8 gUnknown_08edb570[];
extern const u8 gUnknown_08edb488[];
extern const u8 gUnknown_08edb4f8[];
extern const u8 gUnknown_08edb5a0[];
extern const u8 gUnknown_08edb548[];
extern const u8 gUnknown_08edb558[];
extern const u16 gUnknown_08edb86c[];
extern u16 *gUnknown_03004db0;
extern const u16 data_gap_003[];
extern u32 gUnknown_03004dc0;
extern u32 gUnknown_03004dc8;
extern u16 gUnknown_03004dd8;
extern u16 gUnknown_03004dd4;
extern u16 gUnknown_03004ddc;
extern u16 gUnknown_03004de0;
extern void FUN_0801f89c(void);
extern void FUN_0801fda0(void);
extern void FUN_08021b0c(void);
extern void FUN_08021e70(u16 value);

extern void FUN_0801d618(void);
extern void FUN_0801dfdc(void);
extern void FUN_0801e044(void);
extern void FUN_0801e174(void);
extern void FUN_0801e4f4(u8 value);
extern u8 FUN_0801ee4c(u8 value);
extern u32 FUN_08020160(u16 value);
extern u32 FUN_08020144(void);
extern void FUN_0801eea8(u8 value);
extern u16 ArcTan2(s16 x, s16 y);
extern u16 gUnknown_08071250[];

void FUN_0801eb94(u8 value);
void FUN_0801ebf4(u8 value);
void FUN_0801ed50(u8 value);
void FUN_0801edc0(u8 value);
void FUN_0801ee30(u8 value);
void FUN_080244ac(struct UnknownListNode *node);
void FUN_0802440c(struct UnknownListNode *node);
void FUN_080243a4(struct UnknownListNode *node);
void FUN_080245a0(struct UnknownListNode *node);
void FUN_08024794(struct UnknownListNode *node);
void FUN_08024a34(struct UnknownListNode *node);
void FUN_08024aac(struct UnknownListNode *node);
void FUN_08024b1c(struct UnknownListNode *node);
void FUN_08024c20(struct UnknownListNode *node);
void FUN_08024c30(struct UnknownListNode *node);
void FUN_08024d0c(struct UnknownListNode *node);
void FUN_08025734(struct UnknownListNode *node);
void FUN_080257b8(struct UnknownListNode *node);
void FUN_08025838(struct UnknownListNode *node);
void FUN_080258ac(struct UnknownListNode *node);
void FUN_08025994(struct UnknownListNode *node);
void FUN_08025a08(struct UnknownListNode *node);

void FUN_0801c8f0(void) {
    FUN_08012b98(60);
    gUnknown_03002030 = FUN_0801bcac;
    gUnknown_03002030();
}

void FUN_0801c910(void) {
    FUN_08012b98(30);
    gUnknown_03002030 = FUN_0801b394;
    gUnknown_03002030();
}

void FUN_0801c930(void) {
    FUN_08016078(6);
    gUnknown_03001620 = 0;
    gUnknown_03002030 = FUN_0801c770;
    FUN_08020840(24);
    FUN_080205d0();
    gUnknown_030013a0 = 1;
}

void FUN_0801ce70(void) {
    gUnknown_03001b00[0] = 0;
    gUnknown_03001b00[1] = 0;
    gUnknown_03001b00[2] = 0;
    gUnknown_03001b00[3] = 0;
    gUnknown_03001b00[4] = 0;
    gUnknown_03001b00[5] = 0;
    gUnknown_03001b00[6] = 0;
    gUnknown_03001b00[7] = 0;
}

void FUN_0801eacc(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801dfdc;
    }
}

void FUN_0801eaf8(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801e044;
    }
}

void FUN_0801eb24(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801d618;
    }
}

void FUN_0801eb50(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801eb94;
    {
        const void *data = gUnknown_08ed89d0;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801eb94(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ebb0(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ebf4;
    {
        const void *data = gUnknown_08ed89e4;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801ebf4(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ec10(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed89ec;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ec64(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed89f8;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ecb8(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed8a0c;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ed0c(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ed50;
    {
        const void *data = gUnknown_08ed8a8c;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801ed50(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ed6c(u8 value) {
    if (gUnknown_03003db0[value].field15 == value) {
        FUN_0801d870(value);
    } else {
        gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801edc0;
        {
            const void *data = gUnknown_08ed8a9c;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801edc0(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801eddc(u8 value) {
    if (gUnknown_03003db0[value].field15 == value) {
        FUN_0801d870(value);
    } else {
        gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ee30;
        {
            const void *data = gUnknown_08ed8aac;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ee30(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

u8 FUN_0801ee4c(u8 value) {
    if (FUN_08020160(gUnknown_08071264[gUnknown_03003e10]) != 0) {
        struct UnknownEntity *entities = gUnknown_03003db0;
        struct UnknownEntity *entity = &entities[value];
        u8 linked = entity->field15;

        {
            struct UnknownEntityData *data = gUnknown_03001c40;

            if (data[linked].field20 == 53) {
                entity->callback = (UnknownCallback)FUN_0801eea8;
                return 1;
            }
        }
    }

    return 0;
}

void FUN_0801eea8(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];
    u8 linked = entity->field15;

    {
        struct UnknownEntityData *data = gUnknown_03001c40;

        if (data[linked].field20 != 53) {
            entity->callback = FUN_0801d618;
        }
    }
}

void FUN_0801eee0(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->field8 = (entity->field8 & 0xFF0F) | 0x200;
    entity->field12 = 0;
    entity->callback = (UnknownCallback)FUN_0801e4f4;
}

void FUN_0801ef14(u8 value, const void *data) {
    gUnknown_03003db0[value].data = data;
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

u16 FUN_0801ef4c(void) {
    u32 random = FUN_08020144();
    u16 *table = gUnknown_08071250;
    u16 *base = &table[gUnknown_03003e10];

    return *base + ((random & 0xFFF) * *base >> 12);
}

u8 FUN_0801ef7c(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    if (entity->field15 == value) {
        return 1;
    }

    {
        struct UnknownEntityData *data = gUnknown_03001c40;
        u8 linked = entity->field15;

        if (gUnknown_03001c40[value].field54[linked] < 0) {
            if (data[value].field16 == 0) {
                return 0;
            }
        } else if (data[value].field16 != 0) {
            return 0;
        }
    }

    return 1;
}

u8 FUN_0801efd4(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];
    u8 linked = entity->field15;
    struct UnknownEntityData *data = gUnknown_03001c40;
    u32 offset = linked * 2 + value * sizeof(*data);
    u8 *firstBase = (u8 *)data + 54;
    s16 *first = (s16 *)(firstBase + offset);

    {
        u8 *secondBase = (u8 *)data + 62;
        s16 *second = (s16 *)(secondBase + offset);

        {
            const u8 *lookup = gUnknown_08ed8ae4;
            u16 angle = ArcTan2(*first, *second);

            return lookup[angle >> 12];
        }
    }
}

void FUN_0801f024(u8 value) { gUnknown_03003e10 = value; }

void FUN_0801f030(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->callback = FUN_0801d618;
    entity->field15 = FUN_0801d068(value);
}

void FUN_0801f058(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->callback = FUN_0801d618;
    entity->field15 = FUN_0801d188(value);
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

void FUN_0801f628(u16 value) { FUN_08049108(value); }

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

void FUN_0801f89c(void) {
    u8 index = 0;

    do {
        struct UnknownListNode *node = &gUnknown_03003e20[index];

        FUN_0804af6c(node, node->data);
        index = node->next;
    } while (index != 0);
}

void FUN_0801f8c0(struct UnknownListNode *node) {
    gUnknown_03003e20[node->previous].next = node->next;
    gUnknown_03003e20[node->next].previous = node->previous;

    gUnknown_03000008[gUnknown_0300006c++] = node->field6;
    if (gUnknown_0300006c > 99) {
        gUnknown_0300006c = 0;
    }

    if (node->allocation != 0) {
        FUN_08021180(node->allocation);
    }
}

s16 FUN_0801f914(s16 first, s16 second) { return first + (second - first) / 2; }

u32 FUN_0801f92c(struct UnknownListNode *node, s16 x, s16 y) {
    node->position->x = x + (node->position->x - x) / 2;
    node->position->y = y + (node->position->y - y) / 2;

    if (node->position->x == x && node->position->y == y) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f978(struct UnknownListNode *node, s16 x) {
    node->position->x = x + (node->position->x - x) / 2;
    if (node->position->x == x) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f9a8(struct UnknownListNode *node, s16 y) {
    node->position->y = y + (node->position->y - y) / 2;
    if (node->position->y == y) {
        return 1;
    }
    return 0;
}

void FUN_0801f9d8(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_0801fb94(void) { gUnknown_030000c0 = 0; }

void FUN_0801fba0(u16 offset, u16 value) {
    if (gUnknown_030000c0 <= 19) {
        gUnknown_03000070[gUnknown_030000c0][0] = offset;
        gUnknown_03000070[gUnknown_030000c0++][1] = value;
    }
}

void FUN_0801fbfc(const u16 *entries, u8 count);

void FUN_0801fbd8(void) {
    if (gUnknown_030000c0 != 0) {
        FUN_0801fbfc(&gUnknown_03000070[0][0], gUnknown_030000c0);
        gUnknown_030000c0 = 0;
    }
}

void FUN_0801fbfc(const u16 *entries, u8 count) {
    count--;
    while (count != 0xFF) {
        u16 offset = *entries++;

        *(volatile u16 *)(0x04000000 + offset) = *entries++;
        count--;
    }
}

void FUN_0801fc30(u8 value, const void *data) {
    if (data == 0) {
        data = (const void *)FUN_08018664;
    }
    gUnknown_03003150[value] = data;
}

void FUN_0801fc54(void) { gUnknown_03004470 = 0; }

void FUN_0802002c(u8 value, u8 *destination) { *destination = value; }

u32 FUN_08020034(u16 first, u16 second, u16 third) {
    struct UnknownQueuedValue *entry;

    if (gUnknown_030048d4 < 0) {
        return 0;
    }
    entry = &gUnknown_030044d0[(u8)gUnknown_030048d4];
    entry->first = first;
    entry->second = second;
    entry->third = third;
    gUnknown_030048d4++;
    return 1;
}

void FUN_080200bc(u16 index, u16 first, u16 second, u16 third) {
    struct UnknownQueuedValue *entry = &gUnknown_030044d0[index];

    entry->first = first;
    entry->second = second;
    entry->third = third;
}

void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth) {
    struct UnknownQueuedValue *entries = &gUnknown_030044d0[index * 4];

    entries[0].fourth = first;
    entries[1].fourth = second;
    entries[2].fourth = third;
    entries[3].fourth = fourth;
}

void FUN_080200f8(void) {
    s16 i;

    for (i = 0; i <= 3; i++) {
        gUnknown_030000c8[i] = 0;
    }
    gUnknown_0300019a = 1;
    gUnknown_030044c0 = 0;
}

void FUN_08020134(u32 value) { gUnknown_0300019c = value | 1; }

void FUN_0802021c(u8 first, u8 second);

void FUN_080201f8(void) {
    gUnknown_030048e0.fifth = 0;
    gUnknown_030048e0.third = 0;
    gUnknown_030048e0.first = 0;
    gUnknown_030048e0.second = 0xFFFF;
    FUN_0802021c(0, 0);
}

void FUN_0802021c(u8 first, u8 second) {
    if (first == 0 || second == 0) {
        first = 15;
        second = 7;
    }
    gUnknown_030048e0.seventh = first;
    gUnknown_030048e0.sixth = first;
    gUnknown_030048e0.eighth = second;
}

void FUN_08020360(void) { gUnknown_030048f0 = 0; }

void FUN_0802036c(u32 first, u32 second, u32 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 0;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_080203a4(u32 first, u32 second, u16 third, u16 fourth, u16 fifth) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third | (fourth << 16);
        gUnknown_03004900[index].fourth = fifth;
        gUnknown_03004900[index].type = 1;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_08020408(u32 first, u32 second) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = 0;
        gUnknown_03004900[index].type = 2;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_08020440(u32 first, u16 second, u16 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 3;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_0802047c(u32 first, u8 second, u16 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 4;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_080204b8(u32 first, u16 second, u8 third, u16 fourth) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].fourth = third;
        gUnknown_03004900[index].third = fourth;
        gUnknown_03004900[index].type = 5;
        gUnknown_030048f0 = index + 1;
    }
}

u32 FUN_08020500(u16 *destination, const u16 *source, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*destination & 0x7FFF) != (*source & 0x7FFF)) {
            if ((*destination & 0x1F) > (*source & 0x1F)) {
                (*destination)--;
            }
            if ((*destination & 0x1F) < (*source & 0x1F)) {
                (*destination)++;
            }
            if ((*destination & 0x3E0) > (*source & 0x3E0)) {
                *destination -= 0x20;
            }
            if ((*destination & 0x3E0) < (*source & 0x3E0)) {
                *destination += 0x20;
            }
            if ((*destination & 0x7C00) > (*source & 0x7C00)) {
                *destination -= 0x400;
            }
            if ((*destination & 0x7C00) < (*source & 0x7C00)) {
                *destination += 0x400;
            }
            result = 0;
        }
        destination++;
        source++;
        i++;
    }
    return result;
}

u32 FUN_080205d0(void) {
    switch (gUnknown_03004b04) {
    case 0:
        return 1;
    case 1:
        if (gUnknown_03004b00 & 0x8000) {
            return 1;
        }
        gUnknown_03004b00 += gUnknown_03004b08;
        if (gUnknown_03004b00 > 0x8000) {
            gUnknown_03004b00 = 0x8000;
            FUN_0801fba0(0x54, 0x10);
        } else {
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    case 2:
        if (gUnknown_03004b00 == 0) {
            return 1;
        }
        if (gUnknown_03004b00 < gUnknown_03004b08) {
            gUnknown_03004b00 = 0;
            FUN_0801fba0(0x54, 0);
        } else {
            gUnknown_03004b00 -= gUnknown_03004b08;
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    }
    return 0;
}

u32 FUN_0802067c(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if (*colors & 0x7FFF) {
            if (*colors & 0x1F) {
                (*colors)--;
            }
            if (*colors & 0x3E0) {
                *colors -= 0x20;
            }
            if (*colors & 0x7C00) {
                *colors -= 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

u32 FUN_080206ec(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*colors & 0x7FFF) != 0x7FFF) {
            if ((*colors & 0x1F) <= 0x1E) {
                (*colors)++;
            }
            if ((*colors & 0x3E0) <= 0x3DF) {
                *colors += 0x20;
            }
            if ((*colors & 0x7C00) <= 0x7BFF) {
                *colors += 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

void FUN_08020774(u16 *destination, const u16 *source, u16 count, u16 factor) {
    u16 i = 0;

    while (i < count) {
        u16 result;

        result = (((0x1FU & *source) * factor) >> 4) & 0x1F;
        result |= (((0x3E0U & *source) * factor) >> 4) & 0x3E0;
        result |= (((0x7C00U & *source) * factor) >> 4) & 0x7C00;
        *destination = result;
        destination++;
        source++;
        i++;
    }
}

void FUN_080207ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020840(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020898(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_080208ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020944(void) {
    FUN_0801fba0(0x50, 0);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 0;
    gUnknown_03004b00 = 0;
    gUnknown_03004b08 = 0;
}

void FUN_08020ecc(u32 first, const u8 *source, u8 *destination, u32 width, u32 height, u8 fill) {
    u32 pattern;
    u32 value;

    gUnknown_03004b10.field0 = first;
    gUnknown_03004b10.source = source;
    gUnknown_03004b10.destination = destination;
    gUnknown_03004b10.end = (u32)destination + width * height * 32;
    gUnknown_03004b10.width = width;
    gUnknown_03004b10.rowSize = height * 8;
    gUnknown_03004b10.stride = height * 8;
    gUnknown_03004b10.blockSize = height * 16;
    value = fill & 0xF;
    pattern = value | (value << 4) | (value << 8) | (value << 12);
    pattern |= pattern << 16;
    gUnknown_03004b10.fill = pattern;
}

void FUN_08020f18(void) {
    struct UnknownBufferState *state = &gUnknown_03004b10;
    u32 *destination = (u32 *)state->destination;
    u32 count = state->rowSize * state->width - 2;
    u32 offset;
    u32 i;

    for (i = 0; i < count; i++) {
        *destination = destination[2];
        destination++;
    }

    offset = state->stride * 4 - 8;
    destination = (u32 *)(state->destination + offset);
    for (i = 0; i < state->width; i++) {
        destination[0] = destination[1] = state->fill;
        destination += state->stride;
    }
}

void FUN_08020f78(u32 *data) {
    u32 *start = data;
    u32 i;

    for (i = 0; i <= 0x3FD; i++) {
        *data = data[2];
        data++;
    }

    data = start + 30;
    for (i = 0; i <= 31; i++) {
        data[1] = 0;
        data[0] = 0;
        data += 32;
    }
}

u8 FUN_08020f64(u16 value) {
    struct UnknownBufferState *state = &gUnknown_03004b10;

    value &= 0x7FFF;
    return state->source[value];
}

u8 FUN_08020fac(u16 value) {
    const u8 *source = gUnknown_0807173c;

    value &= 0x7FFF;
    return source[value];
}

void FUN_08020fbc(u16 *destination, const u16 *source, u16 width, u16 rows) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination++ = *source++;
        }
        destination += 32 - width;
    }
}

void FUN_08021000(u16 *destination, const u16 *source, u16 width, u16 rows, u16 offset) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination = offset + *source;
            destination++;
            source++;
        }
        destination += 32 - width;
    }
}

void FUN_080210d8(void) {
    u32 zero = 0;

    CpuSet(&zero, gUnknown_03004b30, 0x05000080);
}

void FUN_080210f8(u16 value) { gUnknown_03004b30[value >> 2] = 0; }

void FUN_0802110c(void) {
    gUnknown_03004d30 = &gUnknown_030033e0;
    gUnknown_030033e0.next = 0;
    gUnknown_030033e0.size = 0xFF8;
}

void FUN_080211d8(u8 value) {
    gUnknown_03004d38 = value;
    gUnknown_03004d34 = 0;
}

void FUN_08021244(u8 index) {
    u32 bit = 1 << index;

    if (gUnknown_03004d34 & bit) {
        gUnknown_03004d34 &= ~bit;
    }
}

u8 FUN_08021484(void) {
    u8 result = 1;
    u8 index;

    for (index = 1; index <= 3; index++) {
        if (((gUnknown_03004d40.firstFlags >> index) & 1) &&
            ((gUnknown_03004d40.secondFlags >> index) & 1)) {
            result++;
        }
    }
    return result;
}

void FUN_08021518(void) {
    gUnknown_020000e0 = 0x12345678;
    SoftResetExram(0x40);
}

u32 FUN_08021534(void) {
    if (FUN_08018c8c(&gUnknown_03004d40) != 0) {
        return 0xFF;
    }
    if (FUN_0801950c(&gUnknown_03004d40) != 0) {
        return 1;
    }
    return 0;
}

u32 FUN_0802158c(void) {
    LZ77UnCompWram(gUnknown_03004d94, (void *)0x02000100);
    return 0;
}

u32 FUN_08021564(void) {
    const void *source = gUnknown_03004d94;
    u32 size = gUnknown_03004d8c;

    CpuSet(source, (void *)(0x0203B000 - size), (size << 10) >> 11);
    return 0;
}

u32 FUN_080218ac(u8 sector, u8 *data) {
    ReadFlash(sector, 0, data, 0x1000);
    if (VerifyFlashSector(sector, data) == 0) {
        return 0;
    }
    return 1;
}

u32 FUN_0802188c(void) {
    SetFlashTimerIntr(2, &gUnknown_0300315c);
    gUnknown_03006788();
    return 0;
}

u32 FUN_080218dc(u8 sector, u8 *data) {
    SetFlashTimerIntr(2, &gUnknown_0300315c);
    if ((u16)gUnknown_0300677c(sector, data) != 0) {
        return 1;
    }
    if (VerifyFlashSector(sector, data) != 0) {
        return 1;
    }
    return 0;
}

void FUN_08021a10(u8 *data, u32 count) {
    u32 end = count - 1;
    u8 previous = data[0];
    u32 i;

    for (i = 0; i < end; i++) {
        u8 next = data[1];
        data[1] = next - gUnknown_0807b780[previous];
        previous = next;
        data++;
    }
}

u32 FUN_08021a40(const u8 *data, u32 size) {
    u32 value = -1;
    u32 i;

    for (i = 0; i < size; i++) {
        u32 index = (data[0] ^ value) & 0xFF;
        value = ((value >> 8) & 0xFFFFFF) ^ gUnknown_0807b880[index];
        data++;
    }
    value = ~value;
    return value;
}

void FUN_08021a84(void) {
    u32 i;
    u32 offset;
    u8 *validity;
    u16 **list;

    memset(gUnknown_03004dbc->bits, 0, sizeof(gUnknown_03004dbc->bits));
    gUnknown_03004db0 = (u16 *)(gUnknown_03002110.records + gUnknown_03002110.selector * 56);
    i = 0;
    validity = gUnknown_03002110.validity;
    list = &gUnknown_03004db0;
    offset = 0;
    do {
        u16 value = *(u16 *)((u32)offset + (u32)gUnknown_03004db0);

        if (*(u8 *)((u32)value + (u32)validity) != 0xFF &&
            *(u8 *)((u32)value + (u32)validity) != 0) {
            FUN_08021e70(value);
        } else {
            u16 *entry = (u16 *)((u32)offset + (u32)*list);
            *entry = *(const u16 *)((const u8 *)data_gap_003 + offset);
            FUN_08021e70(*entry);
        }
        offset += 2;
        i++;
    } while (i <= 0x1A);
}

u32 FUN_08021e48(u16 value) {
    if (gUnknown_03002110.validity[value] != 0xFF) {
        return 1;
    }
    return 0;
}

void FUN_08021e70(u16 value) {
    gUnknown_03004dbc->bits[value >> 5] |= gUnknown_0807163c[value & 0x1F];
}

u32 FUN_08021ec8(u16 value) {
    if ((gUnknown_03004dbc->bits[value >> 5] & gUnknown_0807163c[value & 0x1F]) != 0) {
        return 1;
    }
    return 0;
}

void FUN_08021f04(void) {
    gUnknown_03004dc0++;
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08021f20(void) {
    FUN_08021b0c();
    gUnknown_03004dc8 = 1;
}

void FUN_0802436c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb4f0;
    node->position->tile = 0;
    node->position->x = 461;
    node->position->y = 14;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080243a4;
}

void FUN_080243a4(struct UnknownListNode *node) {
    if (gUnknown_03004dbc->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        node->position->x = gUnknown_03004dbc->field12 + 205;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080243d4(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb820;
    node->position->tile = 0;
    node->position->x = 487;
    node->position->y = 34;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_0802440c;
}

void FUN_0802440c(struct UnknownListNode *node) {
    struct UnknownState03004dbc *state = gUnknown_03004dbc;

    if (state->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        u16 *count = &gUnknown_03004dd8;

        if (*count <= 12) {
            return;
        }
        {
            struct UnknownPosition *position = node->position;
            u32 numerator = 115 * gUnknown_03004ddc;
            u32 denominator = ((*count + 3) & -4) - 12;

            position->y = FUN_0804afa4(numerator, denominator) + 34;
        }
        node->position->x = state->field12 + 231;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0802446c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = 256;
    node->position->y = node->position->field13 * 24 + 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244ac;
}

void FUN_080244ac(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_080244bc(struct UnknownListNode *node) {
    FUN_0801f92c(node, 4, 4);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080244d8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = -128;
    node->position->y = 4;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244ac;
}

void FUN_0802450c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = -128;
    node->position->y = 4;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244bc;
}

void FUN_08024540(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, 256) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08024570(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, -128) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080245a0(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + 120;
    FUN_0801f9a8(node, node->position->field13 * 24 + 36);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080245dc(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_080245ec(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + 0x68;
    FUN_0801fed8(node->field6, 0);
}

void FUN_0802460c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = 256;
    node->position->y = node->position->field13 * 24 + 36;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080245a0;
}

void FUN_0802464c(struct UnknownListNode *node) {
    if ((u8)FUN_0801f92c(node, 120, node->position->field13 * 24 + 36) != 0 &&
        (s16)gUnknown_03004dbc->field12 == 0) {
        node->data = FUN_080245a0;
    }
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024698(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, 256) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080246c8(struct UnknownListNode *node) {
    FUN_08021244(node->position->field14);
    FUN_0801f8c0(node);
}

void FUN_08024708(struct UnknownListNode *node) {
    node->position->tile = 0;
    node->position->x = 360;
    node->position->y = 8;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080245ec;
}

void FUN_08024738(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb678;
    node->position->tile = node->position->field13 << 4;
    node->position->x = 256 + gUnknown_08edb834[node->position->field13 * 2];
    node->position->y = gUnknown_08edb834[node->position->field13 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_08024794;
}

void FUN_08024794(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + gUnknown_08edb834[node->position->field13 * 2];
    FUN_0801fed8(node->field6, 0);
}

void FUN_080247c4(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004dbc->field16 - gUnknown_03004dbc->field14;
    u32 remainder = difference % 6;
    u32 quotient = difference / 6;

    node->position->field0 = gUnknown_08edb750;
    node->position->tile = 336;
    node->position->x = remainder * 32 + 24;
    node->position->y = quotient * 40 + 32;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024a34;
}

void FUN_0802482c(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004de0 - gUnknown_03004ddc;
    u32 column = difference & 3;
    u32 row = difference >> 2;

    node->position->field0 = gUnknown_08edb750;
    node->position->tile = 336;
    node->position->x = gUnknown_08edb91c[column];
    node->position->y = gUnknown_08edb91c[row + 4];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024aac;
}

void FUN_08024894(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb760[0];
    node->position->tile = 336;
    node->position->x = gUnknown_08edb834[gUnknown_03004dbc->field2 * 2];
    node->position->y = gUnknown_08edb834[gUnknown_03004dbc->field2 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024b1c;
}

void FUN_080248f0(struct UnknownListNode *node) {
    struct UnknownAllocation248f0 *allocation = node->allocation;

    CpuSet(allocation, gUnknown_08edb5c8, 0x04000004);
    allocation->field6 = 0;
    allocation->field14 = 126;
    node->position->field0 = allocation;
    node->position->tile = 0;
    node->position->x = 160;
    node->position->y = 29;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024c20;
}

void FUN_08024940(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb7f0[0];
    node->position->tile = 336;
    node->position->x = gUnknown_08edb854[node->position->field13 * 2];
    node->position->y = gUnknown_08edb854[node->position->field13 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024c30;
}

void FUN_08024994(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801f9a8(node, node->position->field13 * 24 + 16);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080249e4(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801f9a8(node, node->position->field13 * 24 + 36);
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024a34(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004dbc->field16 - gUnknown_03004dbc->field14;
    u32 remainder = difference % 6;
    u32 quotient = difference / 6;
    s16 x = remainder * 32 + 24;

    FUN_0801f92c(node, x, (s16)(quotient * 40 + 32));
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024aac(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004de0 - gUnknown_03004ddc;
    u32 column = difference & 3;
    u32 row = difference >> 2;

    FUN_0801f92c(node, (s16)gUnknown_08edb91c[column], (s16)gUnknown_08edb91c[row + 4]);
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024b1c(struct UnknownListNode *node) {
    FUN_0801f92c(node, (s16)gUnknown_08edb834[gUnknown_03004dbc->field2 * 2],
                 (s16)gUnknown_08edb834[gUnknown_03004dbc->field2 * 2 + 1]);
    node->position->field0 = gUnknown_08edb760[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024b90(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[0];
    node->position->tile = 336;
    node->position->x = 120;
    node->position->y = node->position->field13 * 24 + 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024994;
}

void FUN_08024bd8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[0];
    node->position->tile = 336;
    node->position->x = 120;
    node->position->y = node->position->field13 * 24 + 36;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080249e4;
}

void FUN_08024c20(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_08024c30(struct UnknownListNode *node) {
    FUN_0801f92c(node, (s16)gUnknown_08edb854[node->position->field13 * 2],
                 (s16)gUnknown_08edb854[node->position->field13 * 2 + 1]);
    node->position->field0 = gUnknown_08edb7f0[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024c90(struct UnknownListNode *node) {
    u8 value = node->position->field13;
    u8 column = value % 6;
    u8 row = value / 6;

    node->position->field0 = gUnknown_08edb570;
    node->position->tile = 0;
    node->position->x = 256 + gUnknown_08edb86c[column];
    node->position->y = gUnknown_08edb86c[row + 6];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_08024d0c;
}

static inline u8 FUN_080256fc_validity(struct UnknownState03002110 *state, u16 index) {
    return state->validity[index];
}

void FUN_080256fc(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb488;
    node->position->tile = 656;
    node->position->x = 272;
    node->position->y = 45;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025734;
}

void FUN_08025734(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 16;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025770(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb4f8;
    node->position->tile = 0;
    node->position->x = node->position->field13 * 6 + 316;
    node->position->y = 37;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080257b8;
}

void FUN_080257b8(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        struct UnknownPosition *position = node->position;
        struct UnknownState03004dbc *state = gUnknown_03004dbc;
        u32 x = position->field13 * 6 + 60;

        position->x = x + state->field12;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025800(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb5a0;
    node->position->tile = 0;
    node->position->x = 272;
    node->position->y = 38;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025838;
}

void FUN_08025838(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 16;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025874(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb548;
    node->position->tile = 0;
    node->position->x = 300;
    node->position->y = 106;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080258ac;
}

void FUN_080258ac(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 44;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080258e8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb548;
    node->position->tile = 0;
    node->position->x = 300;
    node->position->y = 112;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080258ac;
}

void FUN_08025920(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 44;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0802595c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb558;
    node->position->tile = 0;
    node->position->x = 328;
    node->position->y = 141;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025994;
}

void FUN_08025994(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 72;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080259d0(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb558;
    node->position->tile = 40;
    node->position->x = 312;
    node->position->y = 141;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025a08;
}
