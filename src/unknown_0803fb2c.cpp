#include "types.h"
// C++ reconstruction fallback; original source language and type names are unknown.
// Full services family: 0803FB2C..08040684. See docs/services-tu-cpp.md.
struct UnknownTransferRecord4033c {
    const void *source;
    void *destination;
    u32 size;
};
struct UnknownTransferList4033c {
    UnknownTransferRecord4033c records[21];
};
struct UnknownTransferRecord403c0 {
    const void *source;
    void *destination;
    u8 width, height;
    u16 flags;
};
struct UnknownTransferList403c0 {
    UnknownTransferRecord403c0 records[21];
};
struct UnknownPoolCommand4051c {
    u8 node, replacement, value;
};

struct SpritePart {
    u16 tile;
    u8 attr0, attr1, attr2;
    s8 x, y;
    u8 more;
};
struct ServiceNode {
    u8 previous, next, index, flags;
    const void *callback;
    u8 pad8[2];
    u16 x;
    u8 pad12[2];
    u16 y;
    const SpritePart *parts;
    u16 tile;
    u8 attr0, attr1, attr2;
    u8 tail[19];
};
struct SceneState {
    u32 unknown0, unknown4;
    u16 unknown8;
    u8 pad10[4];
    u16 unknown14;
    u8 pad16[4];
    u16 x, y, previousX, previousY;
    u8 character, hasCharacter, stage, room;
    u8 pad32[3];
    u8 field35, field36, rewardsPending, field38, field39;
    u32 field40;
    u8 field44, field45, field46, pad47;
    u16 flagIndex;
};
struct SaveView {
    u8 prefix[119];
    u8 character;
    u8 middle[0x488 - 120];
    u8 resume, stage, room, field48b;
    u32 field48c;
    u8 pad490[8];
    u16 x, y;
    u8 packedFlags[64];
};

struct SeedSnapshot {
    u32 first, second;
};
extern "C" {
extern SceneState gUnknown_03005440;
extern SaveView gUnknown_03002110;
extern u32 gUnknown_03005430;
extern SeedSnapshot gUnknown_03002610, gUnknown_03005488;
extern const u16 gUnknown_0831eae4[][3];
extern const void *const gUnknown_08eeb240[8];
extern u16 gUnknown_030044d0[512];
extern u8 gUnknown_030048d0, gUnknown_03005380;
extern void (*gUnknown_03005330)(void);
extern void (*gUnknown_03002030)(void);
void FUN_08016078(u32);
void FUN_08043fc0(ServiceNode *);
void FUN_08040758(void);
void FUN_080411fc(void);
u32 FUN_0803f81c(void);
void FUN_08034f28(void);
void FUN_08040408(const u16 *, u16 *, s32, s32, s32);

extern UnknownTransferList4033c *gUnknown_030001a0;
extern UnknownTransferList403c0 *gUnknown_030001a4;
extern volatile UnknownTransferRecord4033c gUnknown_040000d4;
extern void *gUnknown_03005478;
extern u8 gUnknown_030001c8, gUnknown_030001b0[4], gUnknown_030001b8;
extern u8 (*gUnknown_030001b4)[2], (*gUnknown_030001c0)[2];
extern u8 *gUnknown_030001bc, *gUnknown_030001c4;
extern ServiceNode *gUnknown_0300547c;
extern u8 gUnknown_030001ac, gUnknown_030001ad, *gUnknown_030001a8, gUnknown_03005480;
void FUN_0804af6c(void *, const void *);

void FUN_0803fb2c(void) {
    FUN_08016078(1);
    gUnknown_03005440.unknown14 = 0xffd0;
    gUnknown_03005440.character = gUnknown_03002110.character;
    gUnknown_03005440.hasCharacter = gUnknown_03005440.character != 0;
    gUnknown_03005440.unknown4 = 0;
    gUnknown_03005440.unknown8 = 0;
    gUnknown_03005440.flagIndex = 0;
    gUnknown_03005440.field46 = 0;
    gUnknown_03005440.field45 = 0;
    gUnknown_03005440.rewardsPending = 0;
    gUnknown_03005440.field36 = 0;
    gUnknown_03005440.field35 = 0;
    gUnknown_03005430 = gUnknown_03002610.first;
    if (!gUnknown_03002110.resume) {
        gUnknown_03005440.stage = gUnknown_03002110.stage;
        gUnknown_03005440.room = gUnknown_0831eae4[gUnknown_03005440.stage][0];
        gUnknown_03005440.previousX = gUnknown_03005440.x =
            gUnknown_0831eae4[gUnknown_03005440.stage][1];
        gUnknown_03005440.previousY = gUnknown_03005440.y =
            gUnknown_0831eae4[gUnknown_03005440.stage][2];
        u16 *flags = (u16 *)0x02000200;
        for (s16 i = 0; i <= 63; i++) {
            for (s16 bit = 0; bit <= 7; bit++) {
                register const u8 *packed asm("r4") = &gUnknown_03002110.packedFlags[i];
                *flags++ = (*packed >> bit) & 1;
            }
        }
        ServiceNode *node = (ServiceNode *)0x02002600;
        gUnknown_0300547c = node;
        u32 zero = 0;
        register volatile UnknownTransferRecord4033c *dma asm("r1") = &gUnknown_040000d4;
        dma->source = &zero;
        dma->destination = node;
        dma->size = 0x8500000b;
        (void)dma->size;
        node->flags = 1;
        node->parts = (const SpritePart *)gUnknown_08eeb240[gUnknown_03005440.stage];
        FUN_08043fc0(node);
        gUnknown_03005440.field40 = 0;
        gUnknown_03005440.field44 = 255;
        gUnknown_03005440.field38 = 1;
        gUnknown_03005440.field39 = 0;
    } else {
        gUnknown_03005440.stage = gUnknown_03002110.stage;
        gUnknown_03005440.room = gUnknown_03002110.room;
        gUnknown_03005440.previousX = gUnknown_03005440.x = gUnknown_03002110.x;
        gUnknown_03005440.previousY = gUnknown_03005440.y = gUnknown_03002110.y;
        u16 *flags = (u16 *)0x02000200;
        for (s16 i = 0; i <= 63; i++) {
            for (s16 bit = 0; bit <= 7; bit++) {
                register const u8 *packed asm("r4") = &gUnknown_03002110.packedFlags[i];
                *flags++ = (*packed >> bit) & 1;
            }
        }
        gUnknown_03005440.field40 = gUnknown_03002110.field48c;
        gUnknown_03005440.field44 = gUnknown_03002110.field48b;
        gUnknown_03005440.field38 = 0;
        gUnknown_03005440.field39 = 1;
    }
    gUnknown_03005488 = gUnknown_03002610;
    FUN_08040758();
}

void FUN_0803fd4c(void) {
    u32 index = 1;
    struct UnknownTransferList403c0 **queue = &gUnknown_030001a4;
    struct UnknownTransferList403c0 **queueCopy;

    if (index < (*queue)->records[0].flags) {
        queueCopy = queue;
        do {
            struct UnknownTransferRecord403c0 *recordBase =
                (struct UnknownTransferRecord403c0 *)*queueCopy;
            u32 recordOffset = index * 12;
            struct UnknownTransferRecord403c0 *record =
                (struct UnknownTransferRecord403c0 *)(recordOffset + (u32)recordBase);
            const u16 *source = (const u16 *)record->source;
            u16 *destination = (u16 *)record->destination;
            u32 width = record->width;
            u32 height = record->height;
            u32 flags = record->flags;

            FUN_08040408(source, destination, width, height, flags);
            {
                u32 nextIndex = index + 1;

                index = (u16)nextIndex;
            }
        } while (index < (*queueCopy)->records[0].flags);
    }
    gUnknown_030001a4->records[0].flags = 1;
}

void FUN_0803fd9c(u16 first, u32 countInput, u32 amountInput) {
    register u32 savedFirst asm("r12") = first;
    u16 count = countInput;
    u16 amount = amountInput;
    u16 *source = (u16 *)gUnknown_03005478 + first;
    u16 *destination = (u16 *)gUnknown_03005478 + (first + 512);
    for (s16 index = 0; index < count; index++) {
        register s32 color = *source++;
        register u16 red = color;
        red &= 31;
        red += ((31 - red) * amount >> 4) & 31;
        register s32 green = color;
        green &= 0x3e0;
        green += ((0x3e0 - green) * amount >> 4) & 0x3e0;
        red |= green;
        s32 blue = color & 0x7c00;
        blue += ((0x7c00 - blue) * amount >> 4) & 0x7c00;
        red |= blue;
        *destination++ = red;
    }
    register u32 originalFirst asm("r1") = savedFirst;
    count = count + originalFirst;
    originalFirst &= 0x1f0;
    asm("" : : "r"(originalFirst));
    u32 alignedFirst = originalFirst;
    count = count - alignedFirst;
    register u32 alignedCount = count + 15;
    register u32 mask asm("r3") = 0x3f0;
    asm("" : : "r"(mask));
    register u32 maskCopy asm("r0") = mask;
    asm("" : : "r"(maskCopy));
    alignedCount &= maskCopy;
    register u32 offset asm("r4") = alignedFirst * 2;
    register void **paletteAddress asm("r7");
    // The matching input initializes the output in the same register; no opcode is emitted.
    asm("" : "=r"(paletteAddress) : "0"(&gUnknown_03005478));
    register u8 *transferSource asm("r2") = (u8 *)*paletteAddress;
    transferSource = (u8 *)(offset + (u32)transferSource);
    register u32 secondBank = 0x400;
    transferSource += secondBank;
    register u32 destinationBase = 0x05000000;
    register void *transferDestination = (void *)(offset + destinationBase);
    u32 size = alignedCount * 2;
    register UnknownTransferList4033c **queueAddress asm("r7") = &gUnknown_030001a0;
    UnknownTransferList4033c *queue = *queueAddress;
    u32 entry = queue->records[0].size;
    UnknownTransferRecord4033c *record = (UnknownTransferRecord4033c *)(entry * 12 + (u32)queue);
    record->source = transferSource;
    record->destination = transferDestination;
    record->size = size;
    queue->records[0].size = entry + 1;
}
void FUN_0803fe98(u16 first, u32 countInput, u32 amountInput) {
    register u32 savedFirst asm("r12") = first;
    u16 count = countInput;
    u16 amount = amountInput;
    u16 *source = (u16 *)gUnknown_03005478 + first;
    u16 *destination = (u16 *)gUnknown_03005478 + (first + 512);
    for (s16 index = 0; index < count; index++) {
        register s32 color = *source++;
        register s32 red = 31;
        red &= color;
        s32 redScaled = (red * amount) >> 4;
        s32 redMask = 31;
        red -= redScaled & redMask;
        register s32 green = color;
        green &= 0x3e0;
        green -= (green * amount >> 4) & 0x3e0;
        green |= red;
        s32 blue = color & 0x7c00;
        blue -= (blue * amount >> 4) & 0x7c00;
        blue |= green;
        *destination++ = blue;
    }
    register u32 originalFirst asm("r7") = savedFirst;
    count = count + originalFirst;
    register u32 alignedFirst asm("r1") = originalFirst & 0x1f0;
    count = count - alignedFirst;
    register u32 alignedCount = count + 15;
    register u32 mask asm("r2") = 0x3f0;
    asm("" : : "r"(mask));
    register u32 maskCopy asm("r0") = mask;
    asm("" : : "r"(maskCopy));
    alignedCount &= maskCopy;
    register u32 offset = alignedFirst * 2;
    register void **paletteAddress asm("r3");
    // The matching input initializes the output in the same register; no opcode is emitted.
    asm("" : "=r"(paletteAddress) : "0"(&gUnknown_03005478));
    register u8 *transferSource asm("r2") = (u8 *)*paletteAddress;
    transferSource = (u8 *)(offset + (u32)transferSource);
    register u32 secondBank asm("r7") = 0x400;
    transferSource += secondBank;
    void *transferDestination = (void *)(0x05000000 + offset);
    u32 size = alignedCount * 2;
    register UnknownTransferList4033c **queueAddress asm("r1") = &gUnknown_030001a0;
    UnknownTransferList4033c *queue = *queueAddress;
    u32 entry = queue->records[0].size;
    UnknownTransferRecord4033c *record = (UnknownTransferRecord4033c *)(entry * 12 + (u32)queue);
    record->source = transferSource;
    record->destination = transferDestination;
    record->size = size;
    queue->records[0].size = entry + 1;
}

ServiceNode *FUN_0803ff98(const void *callback, ServiceNode *parent, u8 after) {
    u32 read = gUnknown_030001ad++;
    u32 index = gUnknown_030001a8[read];
    if (gUnknown_030001ad > 126)
        gUnknown_030001ad = 0;
    ServiceNode **pool = &gUnknown_0300547c;
    ServiceNode *node = &(*pool)[index];
    u32 zero = 0;
    gUnknown_040000d4.source = &zero;
    gUnknown_040000d4.destination = node;
    gUnknown_040000d4.size = 0x8500000b;
    (void)gUnknown_040000d4.size;
    if (after) {
        node->previous = parent->index;
        node->next = parent->next;
        u32 nextIndex = parent->next;
        ServiceNode *base = *pool;
        nextIndex *= 44;
        ServiceNode *next = (ServiceNode *)(nextIndex + (u32)base);
        parent->next = index;
        next->previous = index;
    } else {
        node->previous = parent->previous;
        node->next = parent->index;
        u32 previousIndex = parent->previous;
        ServiceNode *base = *pool;
        previousIndex *= 44;
        ServiceNode *previous = (ServiceNode *)(previousIndex + (u32)base);
        parent->previous = index;
        previous->next = index;
    }
    node->index = index;
    node->callback = callback;
    ((u8 *)node)[25] = parent->index;
    gUnknown_03005480++;
    return node;
}

void FUN_08040044(void) {
    if (gUnknown_030001c8) {
        s16 i;
        for (i = 0; i <= 255; i++)
            gUnknown_030001bc[i] = 0;
        for (i = 0; i < gUnknown_030001c8; i++)
            gUnknown_030001bc[gUnknown_030001c0[i][0]]++;
        for (i = 1; i <= 255; i++)
            gUnknown_030001bc[i] += gUnknown_030001bc[i - 1];
        for (i = gUnknown_030001c8 - 1; i >= 0; i--) {
            u8 position = --gUnknown_030001bc[gUnknown_030001c0[i][0]];
            gUnknown_030001c4[position] = gUnknown_030001c0[i][1];
        }
        for (i = 0; i < gUnknown_030001c8; i++) {
            u32 node = gUnknown_030001c4[i];
            u32 priority = (gUnknown_0300547c[node].attr2 >> 2) & 3;
            gUnknown_030001b4[gUnknown_030001b8][0] = gUnknown_030001b0[priority];
            gUnknown_030001b4[gUnknown_030001b8][1] = node;
            gUnknown_030001b0[priority] = gUnknown_030001b8++;
        }
    }
}

// Emit up to 128 OAM entries; leave affine words untouched, hide unused sprites.
void FUN_08040198(void) {
    u16 *output = gUnknown_030044d0;
    u8 remaining = 128;
    for (s16 priority = 0; priority <= 3; priority++) {
        u32 link = gUnknown_030001b0[priority];
        while (link) {
            ServiceNode *node = &gUnknown_0300547c[gUnknown_030001b4[link][1]];
            const SpritePart *part = node->parts;
        emit_part:
            u32 attribute0 = (part->attr0 | node->attr0) << 8;
            register u16 result0 asm("r2") = attribute0;
            result0 |= (node->y + part->y) & 255;
            *output++ = result0;
            u32 attribute1 = (part->attr1 | node->attr1) << 8;
            register u16 result1 asm("r2") = attribute1;
            result1 |= (node->x + part->x) & 511;
            *output++ = result1;
            *output = ((part->attr2 | node->attr2) << 8) | (part->tile + node->tile);
            if (--remaining == 0)
                goto finished;
            output += 2;
            if (part->more) {
                part++;
                goto emit_part;
            }
            link = gUnknown_030001b4[link][0];
        }
    }
    while (--remaining != 255) {
        *output = 160;
        output += 4;
    }
finished:
    gUnknown_030048d0 = 1;
}

void FUN_080402a0(void) {
    FUN_08016078(1);
    FUN_080411fc();
}
void FUN_080402b0(void) {
    FUN_08016078(1);
    if (gUnknown_03005440.rewardsPending) {
        gUnknown_03005440.rewardsPending = 0;
        if ((u8)FUN_0803f81c()) {
            gUnknown_03005330 = FUN_080402b0;
            gUnknown_03002030 = FUN_08034f28;
            return;
        }
    }
    if (gUnknown_03005440.flagIndex) {
        // Nonzero one-based index selects an EWRAM halfword; allocation bounds
        // remain an entry-precondition audit, not an inferred C array extent.
        u16 *flag = (u16 *)(0x01fffffeu + gUnknown_03005440.flagIndex * 2u);
        *flag = gUnknown_03005380 != 0;
        gUnknown_03005440.flagIndex = 0;
    }
    FUN_080411fc();
}

void FUN_08040328(void) {
    gUnknown_030001a0 = (struct UnknownTransferList4033c *)0x02001600;
    gUnknown_030001a0->records[0].size = 1;
}

void FUN_0804033c(const void *source, void *destination, u32 size) {
    struct UnknownTransferList4033c *list = gUnknown_030001a0;
    u32 index = list->records[0].size;
    u32 recordAddress;
    struct UnknownTransferRecord4033c *record;

    recordAddress = index * 12;
    recordAddress += (u32)list;
    record = (struct UnknownTransferRecord4033c *)recordAddress;
    record->source = source;
    record->destination = destination;
    record->size = size;
    list->records[0].size = index + 1;
}

void FUN_08040360(void) {
    register u32 index asm("r4") = 1;
    struct UnknownTransferList4033c **queue;
    struct UnknownTransferList4033c **globalAddress = &gUnknown_030001a0;
    struct UnknownTransferList4033c *list = *globalAddress;
    u32 count = list->records[0].size;

    queue = globalAddress;
    if (index < count) {
        volatile struct UnknownTransferRecord4033c *destination = &gUnknown_040000d4;
        struct UnknownTransferRecord4033c *record = &list->records[1];
        u32 flags = 0x84000000;

        do {
            destination->source = record->source;
            destination->destination = record->destination;
            destination->size = (record->size >> 2) | flags;
            destination->size;
            record++;
            index++;
        } while (index < list->records[0].size);
    }
    (*queue)->records[0].size = 1;
}

void FUN_080403ac(void) {
    gUnknown_030001a4 = (struct UnknownTransferList403c0 *)0x02001700;
    gUnknown_030001a4->records[0].flags = 1;
}

void FUN_080403c0(const void *source, void *destination, u32 width, u32 height, u32 flags) {
    register u32 storedFlags asm("r9") = flags;
    struct UnknownTransferList403c0 **queue = &gUnknown_030001a4;
    register struct UnknownTransferList403c0 *recordBase asm("r5") = *queue;
    u32 index = recordBase->records[0].flags;
    u32 offset = index * 12;
    struct UnknownTransferList403c0 **queueCopy;
    register struct UnknownTransferList403c0 *current asm("r0");
    struct UnknownTransferRecord403c0 *record;

    recordBase = (struct UnknownTransferList403c0 *)(offset + (u32)recordBase);
    record = (struct UnknownTransferRecord403c0 *)recordBase;
    record->source = source;
    record->destination = destination;
    record->width = width;
    queueCopy = queue;
    current = *queueCopy;
    current = (struct UnknownTransferList403c0 *)(offset + (u32)current);
    current->records[0].height = height;
    current = *queueCopy;
    offset += (u32)current;
    ((struct UnknownTransferRecord403c0 *)offset)->flags = storedFlags;
    current->records[0].flags = index + 1;
}

void FUN_08040408(const u16 *source, u16 *destination, s32 width, s32 height, s32 offset) {
    const u16 *sourceCursor = source;
    u16 *destinationCursor = destination;
    s32 rawWidth = width;
    u32 encodedRows;
    u32 rawOffset;
    register s32 columns asm("r5");
    u16 tileOffset;
    u32 rowStride;

    rawOffset = offset;
    rawWidth = (s32)((u32)rawWidth << 24);
    columns = (u32)rawWidth >> 24;
    encodedRows = (u32)height << 24;
    rawOffset <<= 16;
    tileOffset = rawOffset >> 16;
    rawOffset = 32 - columns;
    rawOffset <<= 24;
    rowStride = rawOffset >> 24;

    {
        u32 decrement = 0xFFu << 24;

        encodedRows += decrement;
    }
    rawOffset = encodedRows >> 24;
    if (rawOffset != 0xFF) {
        u32 strideBytes = rowStride << 1;

        do {
            s16 column = 0;

            encodedRows = rawOffset - 1;
            while (column < columns) {
                *destinationCursor++ = tileOffset + *sourceCursor++;
                column++;
            }
            destinationCursor = (u16 *)((u8 *)destinationCursor + strideBytes);
            rawOffset = (encodedRows << 24) >> 24;
        } while (rawOffset != 0xFF);
    }
}

void FUN_08040460(void) { gUnknown_03005478 = (void *)0x02001800; }

void FUN_08040470(void) {
    s16 index;
    u32 zero;
    volatile u32 *dma;
    u8 *recycleIndex;
    u8 *secondaryIndex;
    u8 *activeCount;
    struct ServiceNode **poolAddress;
    struct ServiceNode **poolCopy;

    gUnknown_030001a8 = (u8 *)0x02002580;
    gUnknown_0300547c = (struct ServiceNode *)0x02002600;
    index = 0;
    poolAddress = (struct ServiceNode **)&gUnknown_0300547c;
    recycleIndex = &gUnknown_030001ac;
    secondaryIndex = &gUnknown_030001ad;
    activeCount = &gUnknown_03005480;
    do {
        gUnknown_030001a8[index] = index + 1;
        index++;
    } while (index <= 126);
    *activeCount = 0;
    *secondaryIndex = 0;
    *recycleIndex = 0;
    zero = 0;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&zero;
    poolCopy = poolAddress;
    dma[1] = (u32)*poolCopy;
    dma[2] = 0x8500000b;
    dma[2];
}

void FUN_080404ec(void) {
    struct ServiceNode **address = (struct ServiceNode **)&gUnknown_0300547c;
    u32 index = (*address)[0].next;

    if (index != 0) {
        struct ServiceNode **globalAddress = address;
        u32 stride = sizeof(struct ServiceNode);

        do {
            struct ServiceNode *node = *globalAddress;
            u32 nodeAddress;

            index *= stride;
            nodeAddress = index + (u32)node;
            node = (struct ServiceNode *)nodeAddress;
            FUN_0804af6c((void *)node, node->callback);
            node = *globalAddress;
            index += (u32)node;
            index = ((struct ServiceNode *)index)->next;
        } while (index != 0);
    }
}

void FUN_0804051c(void *value) {
    struct UnknownPoolCommand4051c *command = (struct UnknownPoolCommand4051c *)value;

    gUnknown_0300547c[command->node].next = command->replacement;
    gUnknown_0300547c[command->replacement].previous = command->node;
    gUnknown_030001a8[gUnknown_030001ac++] = command->value;
    if (gUnknown_030001ac > 126) {
        gUnknown_030001ac = 0;
    }
    gUnknown_03005480--;
}

void FUN_08040578(void) {
    s16 index = 0;

    do {
        gUnknown_030001b0[index] = 0;
        index++;
    } while (index <= 3);
    gUnknown_030001b8 = 1;
}

void FUN_080405a8(u8 first, u8 second) {
    gUnknown_030001b4[gUnknown_030001b8][0] = gUnknown_030001b0[second];
    gUnknown_030001b4[gUnknown_030001b8][1] = first;
    gUnknown_030001b0[second] = gUnknown_030001b8++;
}

void FUN_080405e8(void) { gUnknown_030001c8 = 0; }

void FUN_080405f4(u8 first, u8 second) {
    gUnknown_030001c0[gUnknown_030001c8][0] = second;
    gUnknown_030001c0[gUnknown_030001c8++][1] = first;
}

void FUN_08040624(void) {
    u32 fill;
    volatile u32 *dma;

    gUnknown_030001b4 = (u8(*)[2])0x02002200;
    gUnknown_030001bc = (u8 *)0x02002300;
    gUnknown_030001c0 = (u8(*)[2])0x02002400;
    gUnknown_030001c4 = (u8 *)0x02002500;
    fill = 160;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&fill;
    dma[1] = 0x030044d0;
    dma[2] = 0x85000100;
    dma[2];
}

extern const u8 gUnknown_082f968c[], gUnknown_082f96c0[], gUnknown_082f96ea[];
extern const u8 gUnknown_082f9714[], gUnknown_082f9743[], gUnknown_082f976d[];
extern const u8 gUnknown_082f9797[], gUnknown_082f97c1[];
// Stage starts: room, x, y. Valid saved-stage entries select one of eight rows.
const u16 gUnknown_0831eae4[][3] __attribute__((section(".rodata.stage"))) = {
    {0, 152, 360}, {0, 184, 208}, {4, 312, 120}, {0, 296, 320},
    {0, 248, 208}, {3, 32, 224},  {3, 104, 160}, {1, 136, 240}};
const void *const gUnknown_08eeb240[8] __attribute__((section(".rodata.scripts"))) = {
    gUnknown_082f968c, gUnknown_082f96c0, gUnknown_082f96ea, gUnknown_082f9714,
    gUnknown_082f9743, gUnknown_082f976d, gUnknown_082f9797, gUnknown_082f97c1};

UnknownTransferList4033c *gUnknown_030001a0 __attribute__((section(".bss"))) = 0;
UnknownTransferList403c0 *gUnknown_030001a4 __attribute__((section(".bss.queue_rect"))) = 0;
u8 *gUnknown_030001a8 __attribute__((section(".bss.recycle"))) = 0;
u8 gUnknown_030001ac __attribute__((section(".bss.recycle_write"))) = 0;
u8 gUnknown_030001ad __attribute__((section(".bss.recycle_read"))) = 0;
u8 gUnknown_030001b0[4] __attribute__((section(".bss.priority_heads"))) = {0};
u8 (*gUnknown_030001b4)[2] __attribute__((section(".bss.render_links"))) = 0;
u8 gUnknown_030001b8 __attribute__((section(".bss.render_count"))) = 0;
u8 *gUnknown_030001bc __attribute__((section(".bss.key_counts"))) = 0;
u8 (*gUnknown_030001c0)[2] __attribute__((section(".bss.sort_pairs"))) = 0;
u8 *gUnknown_030001c4 __attribute__((section(".bss.sorted_nodes"))) = 0;
u8 gUnknown_030001c8 __attribute__((section(".bss.sort_count"))) = 0;
}
