#include "types.h"
// C++ is the reconstruction fallback; original source language is unknown.
// Address-based C linkage labels are synthetic. See docs/node-animation-tu-cpp.md.
extern "C" {
struct UnknownPosition {
    const void *field0;
    s16 x, y;
    u16 tile;
    u8 field10, field11, field12, field13, field14, field15;
};
struct UnknownListNode {
    const void *data;
    u8 field4, previous, field6, next;
    UnknownPosition *position;
    void *allocation;
};
struct UnknownAllocation27db8 {
    u8 filler0[16];
    u16 field16, field18, field20, field22;
};
s32 __divsi3(s32, s32);
u32 FUN_0801fd18(s16, u32);
void FUN_0801fed8(u8, u32);
void FUN_08027db8(struct UnknownListNode *node);
void FUN_08027e38(struct UnknownListNode *node);
void FUN_08027eb8(struct UnknownListNode *node);
void FUN_08027f38(struct UnknownListNode *node);
void FUN_08027fb8(struct UnknownListNode *node);
void FUN_08028038(struct UnknownListNode *node);
u32 FUN_080280b8(struct UnknownListNode *node, s32 x, s32 y);
u32 FUN_08028100(struct UnknownListNode *node, s32 x);
u32 FUN_0802812c(struct UnknownListNode *node, s32 y);
void FUN_08028158(struct UnknownListNode *node);
void FUN_08028190(struct UnknownListNode *node);
void FUN_080281c8(struct UnknownListNode *node);
void FUN_08028200(struct UnknownListNode *node);
void FUN_08028238(struct UnknownListNode *node);
void FUN_08028270(struct UnknownListNode *node);
void FUN_080282a8(struct UnknownListNode *node);
void FUN_080282e0(struct UnknownListNode *node);
void FUN_08028318(struct UnknownListNode *node);
void FUN_08028350(struct UnknownListNode *node);
void FUN_08028388(struct UnknownListNode *node);
void FUN_080283c0(struct UnknownListNode *node);
void FUN_08027db8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_080282a8;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value + 32;
        position->x = allocation->field20 - offset;
    }
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027e38(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_080282e0;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value - 32;
        position->x = allocation->field20 + offset;
    }
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027eb8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_08028318;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    node->position->x = allocation->field20 - 32;
    {
        struct UnknownPosition *position = node->position;

        offset = value + 32;
        position->y = allocation->field22 - offset;
    }
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027f38(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_08028350;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    node->position->x = allocation->field20 - 32;
    {
        struct UnknownPosition *position = node->position;

        offset = value - 32;
        position->y = allocation->field22 + offset;
    }
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027fb8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_08028388;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value + 64;
        position->x = allocation->field20 - offset;
    }
    node->position->y = allocation->field22 - 64;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08028038(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)FUN_080283c0;
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - __divsi3(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value - 64;
        position->x = allocation->field20 + offset;
    }
    node->position->y = allocation->field22 - 64;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

u32 FUN_080280b8(struct UnknownListNode *node, s32 x, s32 y) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s32 currentX = (s16)allocation->field20;
    s32 targetX = (s16)x;
    s32 currentY;
    s32 targetY;

    s32 newX = targetX + (currentX - targetX) / 2;
    allocation->field20 = newX;
    currentY = (s16)allocation->field22;
    targetY = (s16)y;
    s32 newY = targetY + (currentY - targetY) / 2;
    allocation->field22 = newY;
    if ((s16)newX == targetX && (s16)newY == targetY) {
        return 1;
    }
    return 0;
}

u32 FUN_08028100(struct UnknownListNode *node, s32 x) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s32 newX = (s16)allocation->field20;
    s32 targetX = (s16)x;

    newX = targetX + (newX - targetX) / 2;
    allocation->field20 = newX;
    if ((s16)newX == targetX) {
        return 1;
    }
    return 0;
}

u32 FUN_0802812c(struct UnknownListNode *node, s32 y) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    s32 newY = (s16)allocation->field22;
    s32 targetY = (s16)y;

    newY = targetY + (newY - targetY) / 2;
    allocation->field22 = newY;
    if ((s16)newY == targetY) {
        return 1;
    }
    return 0;
}

void FUN_08028158(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_080282a8;
}

void FUN_08028190(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_080282e0;
}

void FUN_080281c8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_08028318;
}

void FUN_08028200(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_08028350;
}

void FUN_08028238(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_08028388;
}

void FUN_08028270(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 0;
    node->position->field11 = 0;
    allocation->field16 = 256;
    allocation->field18 = 0;
    node->data = (const void *)FUN_080283c0;
}

void FUN_080282a8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080282e0(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028318(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028350(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028388(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080283c0(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = (UnknownAllocation27db8 *)node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    u32 zero = 0;

    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}
}
