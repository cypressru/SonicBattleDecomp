#include "types.h"

struct UnknownListNode;

extern void FUN_08012b98(u32 value);
extern void FUN_08016078(u32 value);
extern void FUN_0801bcac(void);
extern void FUN_0801b394(void);
extern void FUN_0801c770(void);
extern void FUN_08020840(u32 value);
extern void FUN_080205d0(void);
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
    u8 filler0[4];
    s16 x;
    s16 y;
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
    const void *first;
    const void *second;
    const void *third;
    u16 fourth;
    u16 type;
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

void FUN_0802036c(const void *first, const void *second, const void *third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 0;
        gUnknown_030048f0 = index + 1;
    }
}
