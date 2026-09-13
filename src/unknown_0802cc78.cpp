// C++ reconstruction fallback; see docs/progress-menu-tu-cpp.md.
#include "types.h"
// Observed shared prefix views, not original type or allocation-size claims.
extern "C" {
struct Position {
    const void *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, unused;
};
struct Node {
    void (*callback)(Node *);
    u8 field4, previous, index, next;
    Position *position;
    void *allocation;
};
}
extern "C" {
extern const u16 gUnknown_0811e1f0[], gUnknown_081327d4[];
extern const u32 gUnknown_0807163c[];
extern const u8 gUnknown_0811e230[], gUnknown_0811e25c[], gUnknown_081323d4[];
extern const u8 gUnknown_0811e5c4[], gUnknown_0811fde8[], gUnknown_0811fae4[], gUnknown_0811fd3c[];
extern const Position gUnknown_08edbd0c[], gUnknown_08edbc7c[];
extern u32 gUnknown_03005264;
extern u8 gUnknown_030052b0, gUnknown_030052b4, gUnknown_030052b8;
extern u8 gUnknown_030052d0[], gUnknown_03002110[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u8);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_08030d3c(Node *), FUN_0802cfe0(Node *), FUN_0801f9d8(Node *);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16), FUN_0802cfd0(void);
void FUN_0802cc78(void) {
    u32 fills[2];
    register u32 *secondFill;
    FUN_0801fbfc(gUnknown_0811e1f0, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    if (gUnknown_03005264 == 0) {
        gUnknown_030052b4 = 0;
        gUnknown_030052b8 = 0;
        register u8 *countAddress = &gUnknown_030052b0;
        *countAddress = 1;
        register u8 *save asm("r0") = gUnknown_03002110;
        register u32 offset = 1168;
        asm volatile("" : "+r"(offset));
        register u16 *flags = (u16 *)(save + offset);
        register u32 bits = *flags;
        register const u32 *masks asm("r4") = gUnknown_0807163c;
        bits &= masks[1];
        register u8 *count = countAddress;
        register u32 *fillValue asm("r2") = &fills[1];
        asm volatile("" : : "r"(fillValue));
        secondFill = fillValue;
        asm volatile("" : : : "r6");
        if (bits != 0) {
            register u8 *slot asm("r3") = count;
            do {
                register u32 value = *slot + 1;
                *slot = value;
                if ((u8)value > 7)
                    break;
                register u32 currentFlags asm("r0") = *flags;
                register u32 currentCount = *count;
                register u32 mask asm("r1") = masks[currentCount];
                if ((currentFlags & mask) == 0)
                    break;
            } while (true);
        }
        register u32 i asm("r3") = 0;
        register u8 *limit = count;
        register u32 initialLimit asm("r4") = *limit;
        asm volatile("" : : "r"(initialLimit));
        if (i < initialLimit) {
            do {
                gUnknown_030052d0[i] = gUnknown_0811e230[i];
                i++;
                register u32 nextLimit asm("r7") = *limit;
                if (i >= nextLimit)
                    break;
            } while (true);
        }
    } else {
        register u32 i = 0;
        register u8 *selectedValue = &gUnknown_030052b4;
        asm volatile("" : : "r"(selectedValue));
        register u8 *selectedBase asm("r12") = selectedValue;
        register u8 *variantValue asm("r1") = &gUnknown_030052b8;
        asm volatile("" : : "r"(variantValue));
        register u8 *variantBase asm("r8") = variantValue;
        register u8 *countValue asm("r7") = &gUnknown_030052b0;
        register u8 *saveValue asm("r6") = gUnknown_03002110;
        register u8 *listValue asm("r5") = gUnknown_030052d0;
        asm volatile(""
                     : "+r"(countValue), "+r"(saveValue), "+r"(listValue)
                     : "r"(selectedBase), "r"(variantBase));
        register u8 *selected asm("r12") = selectedBase;
        register u8 *variant asm("r8") = variantBase;
        u8 *count = countValue;
        u8 *save = saveValue;
        u8 *list = listValue;
        register u32 *fillValue asm("r2") = &fills[1];
        asm volatile("" : : "r"(fillValue));
        secondFill = fillValue;
        register u8 *initialList = list;
        for (; i < 7; i++)
            *(u8 *)(i + (u32)initialList) = i;
        register u8 *unlock asm("r4") = save + 121;
        if (*unlock & 4)
            *(u8 *)(i++ + (u32)list) = 7;
        if (*unlock & 2)
            *(u8 *)(i++ + (u32)list) = 8;
        *(u8 *)(i++ + (u32)list) = 9;
        if (i > 9)
            i = 10;
        *count = i;
        register u32 selectedIndex = save[117];
        asm volatile("" : "+r"(selectedIndex));
        register u8 *selectedSlot asm("r3") = selected;
        *selectedSlot = selectedIndex;
        i = 0;
        register u32 tailValue;
        {
            register u32 initialCount = *count;
            if (i >= initialCount)
                goto resetSelected;
            register u32 firstIndex = (u8)selectedIndex;
            register u32 firstRecord asm("r4") = *list;
            asm volatile("" : : "r"(firstRecord));
            if (firstIndex != firstRecord) {
                register u32 limit = initialCount;
                register u8 *selectedRead = selected;
                do {
                    i++;
                    if (i >= limit)
                        goto resetSelected;
                    register u8 *address = (u8 *)(i + (u32)list);
                    register u32 left = *selectedRead;
                    register u32 right = *address;
                    if (left == right)
                        break;
                } while (true);
            }
            tailValue = *count;
            if (i < tailValue)
                goto selectedValid;
        }
    resetSelected: {
        register u32 zero = 0;
        count = selected;
        *count = zero;
    }
    selectedValid:
        register u8 *selectedRead asm("r1") = selected;
        register u32 index = *selectedRead;
        register u32 offset = index * 4;
        register u8 *first = save;
        asm volatile("" : "+r"(first));
        first += 248;
        register u32 firstValue = *(u8 *)(offset + (u32)first);
        if (firstValue == 0) {
            register u8 *out asm("r2") = variant;
            *out = firstValue;
        } else {
            register u8 *second = save + 249;
            register u32 secondValue = *(u8 *)(offset + (u32)second);
            if (secondValue == 0) {
                register u32 one = 1;
                register u8 *out asm("r3") = variant;
                *out = one;
            } else {
                register u32 two = 2;
                register u8 *out asm("r4") = variant;
                *out = two;
            }
        }
    }
    fills[0] = 0;
    CpuFastSet(&fills[0], (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_0811e25c, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_081323d4, (void *)0x0600c000);
    LZ77UnCompVram(gUnknown_0811e5c4, (void *)0x06010000);
    fills[1] = 0;
    CpuFastSet(secondFill, (void *)0x0600f000, 0x01000400);
    if (gUnknown_03005264 == 0)
        LZ77UnCompVram(gUnknown_0811fde8, (void *)0x0600e000);
    else
        LZ77UnCompVram(gUnknown_0811fae4, (void *)0x0600e000);
    LZ77UnCompVram(gUnknown_0811fd3c, (void *)0x0600e800);
    u16 *destination = (u16 *)0x0600d800;
    register u32 row asm("r3") = 0;
    u16 tile = 0xf200;
    do {
        u32 column = 0;
        register u32 nextRow = row + 1;
        for (; column < 4; column++) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, tile);
            destination += 8;
        }
        destination += 224;
        row = nextRow;
    } while (row < 4);
    FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0802cfe0, 12, gUnknown_03003e20, 0);
    if (gUnknown_03005264 == 0) {
        Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        *node->position = gUnknown_08edbd0c[0];
    } else {
        Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        *node->position = gUnknown_08edbc7c[0];
        node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        *node->position = gUnknown_08edbc7c[1];
        node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        *node->position = gUnknown_08edbc7c[2];
        node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
        *node->position = gUnknown_08edbc7c[5];
    }
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_0802cfd0;
    FUN_0801f618(2);
}
}

extern "C" {
struct MenuControl {
    u8 children[6], unused6[2];
    u16 selectedIndex, unused10;
};
struct AnimationState {
    const void *sequence;
    u32 unused4;
    u16 tile;
    u8 unused10[10];
    s16 x, y;
};
extern u8 gUnknown_030052b0, gUnknown_030052b4, gUnknown_030052b8, gUnknown_030052d0[];
extern Node gUnknown_03003e20[];
extern const Position gUnknown_08edbcac[];
extern const u8 gUnknown_08edb92c[];
extern const s16 gUnknown_0812e5f8[];
void FUN_0801f89c(void), FUN_0801fda0(void);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802dc0c(Node *), FUN_08028158(Node *), FUN_08028190(Node *);
void FUN_0802d980(Node *), FUN_0802db34(Node *), FUN_0802d134(Node *);
void FUN_0802cfd0(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0802cfe0(Node *node) {
    MenuControl *state = (MenuControl *)node->allocation;
    u8 i = 0;
    register u8 *countValue asm("r0") = &gUnknown_030052b0;
    asm volatile("" : : "r"(countValue));
    register u8 *count asm("r4") = countValue;
    register u8 *selected asm("r5") = &gUnknown_030052b4;
    register void (*firstCallback)(Node *) = FUN_0802dc0c;
    register Node *poolValue = gUnknown_03003e20;
    Node *pool = poolValue;
    register u32 initialCount asm("r1") = *count;
    asm volatile("" : : "r"(initialCount));
    if (i < initialCount) {
        register u8 *listValue = gUnknown_030052d0;
        asm volatile("" : : "r"(listValue));
        register u32 selectedValue = *selected;
        register u8 *list = listValue;
        if (selectedValue != *list) {
            do {
                i = (u8)(i + 1);
                if (i >= *count)
                    goto invalidSelection;
                asm volatile("" : "+r"(selected));
                register u8 *address = (u8 *)(i + (u32)list);
                register u32 left asm("r0") = *selected;
                register u32 right = *address;
                if (left == right)
                    break;
            } while (true);
        }
        state->selectedIndex = i;
        if (i < *count)
            goto selectionReady;
    }
invalidSelection: {
    *selected = 0;
    state->selectedIndex = 0;
}
selectionReady:
    Node *child = FUN_0801f7d0(firstCallback, 40, pool, 0);
    state->children[2] = child->index;
    *child->position = gUnknown_08edbcac[0];
    child->position->player = gUnknown_030052b8;
    child = FUN_0801f7d0(FUN_08028158, 28, pool, 0);
    state->children[0] = child->index;
    AnimationState *animation = (AnimationState *)child->allocation;
    animation->sequence = gUnknown_08edb92c;
    animation->tile = 0;
    animation->x = gUnknown_0812e5f8[0];
    animation->y = gUnknown_0812e5f8[1];
    child = FUN_0801f7d0(FUN_08028190, 28, pool, 0);
    state->children[1] = child->index;
    animation = (AnimationState *)child->allocation;
    animation->sequence = gUnknown_08edb92c;
    animation->tile = 16;
    animation->x = gUnknown_0812e5f8[2];
    animation->y = gUnknown_0812e5f8[3];
    child = FUN_0801f7d0(FUN_0802d980, 72, pool, 0);
    state->children[3] = child->index;
    *child->position = gUnknown_08edbcac[1];
    child = FUN_0801f7d0(FUN_0802db34, 44, pool, 0);
    state->children[4] = child->index;
    *child->position = gUnknown_08edbcac[4];
    node->callback = FUN_0802d134;
}
}

extern "C" {
extern u32 gUnknown_03005264;
extern const u16 gUnknown_081326f4[], gUnknown_08132734[], gUnknown_0811e23c[], gUnknown_0811ff24[];
extern Node gUnknown_03003e20[];
u32 FUN_08020500(u16 *, const u16 *, u32);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802df40(Node *), FUN_0802d1ec(Node *);
void FUN_0802d134(Node *node) {
    MenuControl *state = (MenuControl *)node->allocation;
    u32 firstPending;
    if (gUnknown_03005264 == 0)
        firstPending = (u8)FUN_08020500((u16 *)0x050001e0, gUnknown_081326f4, 16) == 0;
    else
        firstPending = (u8)FUN_08020500((u16 *)0x050001e0, gUnknown_08132734, 16) == 0;
    u32 pending = firstPending;
    asm volatile("" : "+r"(pending));
    register u32 secondPending asm("r0");
    if ((u8)FUN_08020500((u16 *)0x05000000, gUnknown_0811e23c, 16) == 0)
        secondPending = (pending | 1) << 24;
    else
        secondPending = pending << 24;
    secondPending >>= 24;
    asm volatile("" : "+r"(secondPending));
    pending = secondPending;
    u32 finalPending;
    if ((u8)FUN_08020500((u16 *)0x05000200, gUnknown_0811ff24, 256) == 0)
        finalPending = pending | 1;
    else
        finalPending = (u8)pending;
    if (finalPending == 0) {
        Node *child = FUN_0801f7d0(FUN_0802df40, 8, gUnknown_03003e20, 0);
        state->children[5] = child->index;
        ((u8 *)child->allocation)[6] = state->selectedIndex;
        node->callback = FUN_0802d1ec;
    }
}
}

extern "C" {
extern u32 gUnknown_03005264;
extern u8 gUnknown_030052b0, gUnknown_030052b4, gUnknown_030052b8, gUnknown_03002110[];
extern u16 gUnknown_030048e0[];
extern Node gUnknown_03003e20[];
extern const s16 gUnknown_0812e5f8[];
void FUN_0802d678(Node *), FUN_0802d4dc(Node *), FUN_0802d734(Node *);
void FUN_08027db8(Node *), FUN_08027e38(Node *), FUN_0802de2c(Node *);
void FUN_0801f618(u16), FUN_0801f718(u16, u16);
s32 FUN_0801f914(s32, s32);
void FUN_0802d1ec(Node *incoming) {
    register Node *node = incoming;
    MenuControl *state = (MenuControl *)node->allocation;
    register Node *pool = gUnknown_03003e20;
    register u32 transitionOffset = state->children[5] * 16;
    register u8 *allocationBase = (u8 *)pool + 12;
    register s16 *transition asm("r1") = *(s16 **)(transitionOffset + (u32)allocationBase);
    if (*transition == 0) {
        register u32 offset asm("r0") = state->children[3] * 16;
        register u8 *positionBase asm("r1") = (u8 *)pool + 8;
        register Position *position = *(Position **)(offset + (u32)positionBase);
        if (position->state == 0)
            position->state = 1;
        offset = state->children[4] * 16;
        register Position *second = *(Position **)(offset + (u32)positionBase);
        if (second->state == 0)
            second->state = 1;
    }
    u32 keys = gUnknown_030048e0[2];
    if (keys & 1) {
        if (gUnknown_03005264 == 0) {
            node->callback = FUN_0802d678;
            FUN_0801f618(404);
            FUN_0801f718(2, 120);
        } else {
            node->callback = FUN_0802d4dc;
            FUN_0801f618(402);
        }
    } else {
        register u32 cancel = keys & 2;
        asm volatile("" : : "r"(cancel));
        if (cancel) {
            node->callback = FUN_0802d734;
            FUN_0801f618(405);
            FUN_0801f718(2, 120);
        }
    }
    keys = gUnknown_030048e0[2];
    register u32 leftMask = keys & 32;
    register u32 left = (u16)leftMask;
    if (left) {
        u32 index = state->selectedIndex;
        if (index == 0)
            index = gUnknown_030052b0;
        state->selectedIndex = index - 1;
        asm volatile("" : "+r"(state));

        gUnknown_030052b4 = state->selectedIndex;
        if (gUnknown_03005264 != 0) {
            register u8 *save = gUnknown_03002110;
            register u32 selection = gUnknown_030052b4;
            register u32 offset = selection * 4;
            register u8 *first = save + 248;
            register u32 value asm("r2") = *(u8 *)(offset + (u32)first);
            u8 *variantAddress;
            if (value == 0) {
                register u8 *out = &gUnknown_030052b8;
                *out = value;
                variantAddress = out;
            } else {
                register u8 *second asm("r0") = save + 249;
                if (*(u8 *)(offset + (u32)second) == 0)
                    gUnknown_030052b8 = 1;
                else
                    gUnknown_030052b8 = 2;
                variantAddress = &gUnknown_030052b8;
            }
            gUnknown_03003e20[state->children[2]].position->player = *variantAddress;
        }
        gUnknown_03003e20[state->children[0]].callback = FUN_08027db8;
        gUnknown_03003e20[state->children[0]].position->state = 0;
        gUnknown_03003e20[state->children[5]].callback = FUN_0802de2c;
        u8 *transition = (u8 *)gUnknown_03003e20[state->children[5]].allocation;
        transition[6] = state->selectedIndex;
        transition[7] = 0;
        gUnknown_03003e20[state->children[3]].position->state = 0;
        gUnknown_03003e20[state->children[4]].position->state = 0;
        FUN_0801f618(401);

    } else {
        register u32 right = keys & 16;
        asm volatile("" : : "r"(right));
        if (right) {
            state->selectedIndex++;
            if (state->selectedIndex >= gUnknown_030052b0)
                state->selectedIndex = left;

            gUnknown_030052b4 = state->selectedIndex;
            if (gUnknown_03005264 != 0) {
                register u8 *save = gUnknown_03002110;
                u32 offset = gUnknown_030052b4 * 4;
                u8 *first = save + 248;
                if (*(u8 *)(offset + (u32)first) == 0)
                    gUnknown_030052b8 = 0;
                else {
                    register u8 *second asm("r0") = save + 249;
                    if (*(u8 *)(offset + (u32)second) == 0)
                        gUnknown_030052b8 = 1;
                    else
                        gUnknown_030052b8 = 2;
                }
                gUnknown_03003e20[state->children[2]].position->player = gUnknown_030052b8;
            }
            gUnknown_03003e20[state->children[1]].callback = FUN_08027e38;
            gUnknown_03003e20[state->children[1]].position->state = 0;
            gUnknown_03003e20[state->children[5]].callback = FUN_0802de2c;
            u8 *transition = (u8 *)gUnknown_03003e20[state->children[5]].allocation;
            transition[6] = state->selectedIndex;
            transition[7] = 0;
            gUnknown_03003e20[state->children[3]].position->state = 0;
            gUnknown_03003e20[state->children[4]].position->state = 0;
            FUN_0801f618(401);
        }
    }
    AnimationState *animation = (AnimationState *)gUnknown_03003e20[state->children[0]].allocation;
    animation->x = FUN_0801f914(gUnknown_0812e5f8[0], animation->x);
    animation->y = FUN_0801f914(gUnknown_0812e5f8[1], animation->y);
    animation = (AnimationState *)gUnknown_03003e20[state->children[1]].allocation;
    animation->x = FUN_0801f914(gUnknown_0812e5f8[2], animation->x);
    animation->y = FUN_0801f914(gUnknown_0812e5f8[3], animation->y);
}
}

extern "C" {
extern u32 gUnknown_03005264;
extern u8 gUnknown_030052b0, gUnknown_030052b4, gUnknown_030052b8, gUnknown_03002110[];
extern u16 gUnknown_030048e0[];
extern Node gUnknown_03003e20[];
extern const s16 gUnknown_0812e5f8[];
void FUN_0802d678(Node *), FUN_0802d4dc(Node *), FUN_0802d734(Node *);
void FUN_08027db8(Node *), FUN_08027e38(Node *), FUN_0802de2c(Node *);
void FUN_0802d1ec(Node *);
void FUN_0801f618(u16), FUN_0801f718(u16, u16);
s32 FUN_0801f914(s32, s32);
void FUN_0802d4dc(Node *incoming) {
    register Node *node asm("r2") = incoming;
    MenuControl *state = (MenuControl *)node->allocation;
    register Node *pool = gUnknown_03003e20;
    register u32 offset = state->children[3] * 16;
    register u8 *positionBase = (u8 *)pool + 8;
    Position *position = *(Position **)(offset + (u32)positionBase);
    if (position->state == 0)
        position->state = 1;
    position = *(Position **)(state->children[4] * 16 + (u32)positionBase);
    if (position->state == 0)
        position->state = 1;
    u32 keys = gUnknown_030048e0[2];
    if (keys & 1) {
        node->callback = FUN_0802d678;
        FUN_0801f618(404);
        FUN_0801f718(2, 120);
    } else {
        register u32 cancel = 2;
        cancel &= keys;
        if (cancel) {
            node->callback = FUN_0802d1ec;
            FUN_0801f618(403);
        } else {
            register u32 mask = keys & 32;
            register u32 left = (u16)mask;
            if (left) {
                register u8 *variantValue = &gUnknown_030052b8;
                register u32 value = *variantValue;
                register u8 *variant = variantValue;
                register u32 next asm("r0");
                if (value == 0)
                    next = 2;
                else
                    next = value - 1;
                *variant = next;
                register Node *leftPool = gUnknown_03003e20;
                register u32 offset = state->children[2] * 16;
                register u8 *positions = (u8 *)leftPool + 8;
                Position *child = *(Position **)(offset + (u32)positions);
                u32 player = *variant;
                register u32 zero = 0;
                child->player = player;
                leftPool[state->children[0]].callback = FUN_08027db8;
                (*(Position **)(state->children[0] * 16 + (u32)positions))->state = zero;
                (*(Position **)(state->children[3] * 16 + (u32)positions))->state = zero;
                FUN_0801f618(401);
            } else {
                register u32 right = keys & 16;
                asm volatile("" : : "r"(right));
                if (right) {
                    gUnknown_030052b8++;
                    if (gUnknown_030052b8 > 2)
                        gUnknown_030052b8 = left;
                    (*(Position **)(state->children[2] * 16 + (u32)positionBase))->player =
                        gUnknown_030052b8;
                    pool[state->children[1]].callback = FUN_08027e38;
                    (*(Position **)(state->children[1] * 16 + (u32)positionBase))->state = left;
                    (*(Position **)(state->children[3] * 16 + (u32)positionBase))->state = left;
                    FUN_0801f618(401);
                }
            }
        }
    }
    AnimationState *animation = (AnimationState *)gUnknown_03003e20[state->children[0]].allocation;
    animation->x = FUN_0801f914(gUnknown_0812e5f8[4], animation->x);
    animation->y = FUN_0801f914(gUnknown_0812e5f8[5], animation->y);
    animation = (AnimationState *)gUnknown_03003e20[state->children[1]].allocation;
    animation->x = FUN_0801f914(gUnknown_0812e5f8[6], animation->x);
    animation->y = FUN_0801f914(gUnknown_0812e5f8[7], animation->y);
}
}
extern "C" {
extern u32 gUnknown_03005264;
extern u8 gUnknown_03002110[], gUnknown_03001620[], gUnknown_030052b4, gUnknown_030052d0[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
u32 FUN_0802067c(u16 *, u32);
void FUN_0803fb2c(void), FUN_08030f38(void), FUN_08039e20(void);
void FUN_080217d0(u32), FUN_0801fed8(u8, u32);
void FUN_0802d678(Node *node) {
    MenuControl *state = (MenuControl *)node->allocation;
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        if (gUnknown_03005264 == 0) {
            gUnknown_03002110[1161] = state->selectedIndex;
            gUnknown_03002110[1160] = 0;
            gUnknown_03002030 = FUN_0803fb2c;
        } else {
            gUnknown_030052b4 = gUnknown_030052d0[state->selectedIndex];
            gUnknown_03002110[117] = gUnknown_030052b4;
            gUnknown_03002110[118] = gUnknown_03003e20[state->children[2]].position->player;
            gUnknown_03001620[4] = 0;
            gUnknown_03001620[5] = 10;
            gUnknown_03001620[6] = 0;
            gUnknown_03001620[7] = 0;
            gUnknown_03001620[8] = 0;
            gUnknown_03001620[9] = 0;
            gUnknown_03001620[10] = 0;
            gUnknown_03001620[11] = 0;
            *(u32 *)(gUnknown_03001620 + 120) = 0;
            gUnknown_03001620[124] = 0;
            gUnknown_03002030 = FUN_08030f38;
            FUN_080217d0(0);
        }
    }
}
void FUN_0802d734(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_08039e20;
}
void FUN_0802d75c(Node *node) { FUN_0801fed8(node->index, 0); }
}

extern "C" {
extern u8 gUnknown_030052b4, gUnknown_030052b8, gUnknown_03002110[];
void FUN_0801fed8(u8, u32);
void FUN_0802d8d8(Node *), FUN_0802d95c(Node *);
void FUN_0802d76c(Node *argument) {
    register Node *node = argument;
    u8 *state = (u8 *)node->allocation;
    register Node *current asm("r4");
    for (u32 i = 0; i < 6; i++) {
        current = node;
        *(u16 *)(state + i * 8 + 16) = current->position->unused & 0xfffc;
    }
    register Position *position = current->position;
    u32 next = position->unused + 1;
    position->unused = next;
    if ((u8)next > 39)
        current->position->unused = 0;
    register Node *queued asm("r1") = node;
    FUN_0801fed8(queued->index, 0);
    current = node;
    asm volatile("" : : "r"(current));
    if (current->position->state != 0) {
        register u32 playerValue asm("r0") = gUnknown_030052b4;
        if (playerValue > 9)
            playerValue = 9;
        register u32 player = playerValue;
        register u32 variant = gUnknown_030052b8;
        if (variant > 2)
            variant = 2;
        register u8 *save asm("r0") = gUnknown_03002110;
        register u32 offset asm("r1") = (variant + player * 3) * 4;
        save += 128;
        offset += (u32)save;
        register u32 score = *(u32 *)offset;
        if (score > 999998) {
            state[69] = 9;
            state[68] = 9;
            state[67] = 9;
            state[66] = 9;
            state[65] = 9;
            state[64] = 9;
        } else {
            register u32 quotient = score / 100000;
            register u8 *digits asm("r5") = state + 64;
            digits[0] = quotient;
            score %= 100000;
            quotient = score / 10000;
            {
                register u8 *destination = state + 65;
                *destination = quotient;
            }
            score %= 10000;
            quotient = score / 1000;
            {
                register u8 *destination = state + 66;
                *destination = quotient;
            }
            score %= 1000;
            quotient = score / 100;
            {
                register u8 *destination = state + 67;
                *destination = quotient;
            }
            score %= 100;
            quotient = score / 10;
            {
                register u8 *destination = state + 68;
                *destination = quotient;
            }
            quotient = score % 10;
            {
                register u8 *destination = state + 69;
                *destination = quotient;
            }
            u32 i = 0;
            if (digits[0] == 0) {
                register u8 *base asm("r1") = digits;
                do {
                    *(u8 *)((u32)base + i) = 10;
                    i++;
                    if (i > 4)
                        break;
                } while (*(u8 *)((u32)digits + i) == 0);
            }
        }
        node->callback = FUN_0802d8d8;
    }
}
}
extern "C" {
void FUN_0801fed8(u8, u32);
void FUN_0802d76c(Node *), FUN_0802d95c(Node *);
void FUN_0802d8d8(Node *node) {
    u8 *state = (u8 *)node->allocation;
    u32 tick = node->position->state;
    u32 shifted = tick << 24;
    if (shifted == 0)
        node->callback = FUN_0802d76c;
    else {
        node->position->state = tick + 1;
        u32 digit = shifted >> 27;
        u32 offset = digit * 8;
        register u16 *destination = (u16 *)((u32)state + offset);
        register u8 *digits = state + 64;
        destination[8] = digits[digit] * 4;
        digit++;
        for (; digit < 6; digit++) {
            asm volatile("" : : : "memory");
            *(u16 *)(state + digit * 8 + 16) = node->position->unused & 0xfffc;
        }
        u32 next = node->position->unused + 1;
        node->position->unused = next;
        if ((u8)next > 39)
            node->position->unused = 0;
        if (node->position->state > 47)
            node->callback = FUN_0802d95c;
    }
    FUN_0801fed8(node->index, 0);
}
void FUN_0802d95c(Node *node) {
    FUN_0801fed8(node->index, 0);
    if (node->position->state == 0)
        node->callback = FUN_0802d76c;
}
}
extern "C" {
struct DigitPart {
    u16 tile;
    u8 unused2[3], x, unused6, more;
};
extern const DigitPart gUnknown_08120144;
extern u32 gUnknown_03005264;
void FUN_0802d76c(Node *);
void FUN_0802d980(Node *argument) {
    register Node *node = argument;
    u8 *state = (u8 *)node->allocation;
    if (gUnknown_03005264 != 0) {
        u8 x = 0;
        register u32 i = 0;
        register u8 *end = state + 63;
        register DigitPart *initial asm("r1") = (DigitPart *)(state + 16);
        asm volatile("" : : "r"(initial));
        DigitPart *first = initial;
        asm volatile("" : "+m"(first));
        register void (*callbackValue)(Node *) asm("r1") = FUN_0802d76c;
        register void (*callback)(Node *) asm("r9") = callbackValue;
        register const DigitPart *sourceValue asm("r6") = &gUnknown_08120144;
        asm volatile("" : : "r"(sourceValue));
        register const DigitPart *source asm("r8") = sourceValue;
        register u32 oneValue asm("r7") = 1;
        asm volatile("" : "+r"(oneValue));
        register u32 one = oneValue;
        register DigitPart *parts = first;
        do {
            *parts = *source;
            parts->x = x;
            register u32 flag = one;
            parts->more = flag;
            register u32 shifted = (u32)x << 24;
            register u32 step = 14 << 24;
            shifted += step;
            x = shifted >> 24;
            parts++;
            i++;
        } while (i < 6);
        register u32 zero = 0;
        register u8 *last asm("r6") = end;
        *last = zero;
        register Position *position = node->position;
        register DigitPart *storedParts asm("r7") = first;
        position->parts = storedParts;
        register void (*storedCallback)(Node *) = callback;
        asm volatile("" : : "r"(storedCallback));
        node->callback = storedCallback;
    }
}
}
extern "C" {
extern u8 gUnknown_030052b4, gUnknown_03002110[];
void FUN_0801fed8(u8, u32), FUN_0802da8c(Node *);
void FUN_0802da00(Node *node) {
    u8 *state = (u8 *)node->allocation;
    u32 tick = node->position->unused;
    for (u32 i = 0; i < 3; i++)
        *(u16 *)(state + 16 + i * 8) = tick & 0xfffc;
    tick++;
    if (tick > 15)
        tick = 0;
    node->position->unused = tick;
    FUN_0801fed8(node->index, 0);
    if (node->position->state != 0) {
        register u32 player asm("r0") = gUnknown_030052b4;
        if (player > 9)
            player = 9;
        register u8 *save asm("r2") = gUnknown_03002110;
        register u32 offset asm("r3") = player * 4;
        register u8 *source asm("r0") = save + 248;
        source = (u8 *)(offset + (u32)source);
        register u32 first = *source;
        state[40] = first;
        source = save + 249;
        source = (u8 *)(offset + (u32)source);
        register u32 second = *source;
        state[41] = second;
        save += 250;
        offset += (u32)save;
        first = *(u8 *)offset;
        state[42] = first;
        node->callback = FUN_0802da8c;
    }
}
}
extern "C" {
void FUN_0801fed8(u8, u32);
void FUN_0802da00(Node *), FUN_0802db10(Node *);
void FUN_0802da8c(Node *node) {
    u8 *state = (u8 *)node->allocation;
    u32 tick = node->position->state;
    u32 shifted = tick << 24;
    if (shifted == 0)
        node->callback = FUN_0802da00;
    else {
        node->position->state = tick + 1;
        u32 digit = shifted >> 27;
        u32 offset = digit * 8;
        register u16 *destination = (u16 *)((u32)state + offset);
        register u8 *digits = state + 40;
        destination[8] = digits[digit] * 4;
        digit++;
        for (; digit < 3; digit++) {
            asm volatile("" : : : "memory");
            *(u16 *)(state + digit * 8 + 16) = (node->position->unused & 0xfffc) + 4;
        }
        u32 next = node->position->unused + 1;
        node->position->unused = next;
        if ((u8)next > 15)
            node->position->unused = 0;
        if (node->position->state > 23)
            node->callback = FUN_0802db10;
    }
    FUN_0801fed8(node->index, 0);
}
void FUN_0802db10(Node *node) {
    FUN_0801fed8(node->index, 0);
    if (node->position->state == 0)
        node->callback = FUN_0802da00;
}
}

extern "C" {
extern const DigitPart gUnknown_08120144;
extern u32 gUnknown_03005264;
void FUN_0802da00(Node *);
void FUN_0802db34(Node *argument) {
    register Node *node = argument;
    u8 *state = (u8 *)node->allocation;
    if (gUnknown_03005264 != 0) {
        u8 x = 0;
        register u32 i = 0;
        register u8 *end = state + 39;
        register DigitPart *initial asm("r1") = (DigitPart *)(state + 16);
        asm volatile("" : : "r"(initial));
        DigitPart *first = initial;
        asm volatile("" : "+m"(first));
        register void (*callbackValue)(Node *) asm("r1") = FUN_0802da00;
        register void (*callback)(Node *) asm("r9") = callbackValue;
        register const DigitPart *sourceValue asm("r6") = &gUnknown_08120144;
        asm volatile("" : : "r"(sourceValue));
        register const DigitPart *source asm("r8") = sourceValue;
        register u32 oneValue asm("r7") = 1;
        asm volatile("" : "+r"(oneValue));
        register u32 one = oneValue;
        register DigitPart *parts = first;
        do {
            *parts = *source;
            parts->x = x;
            register u32 flag = one;
            parts->more = flag;
            register u32 shifted = (u32)x << 24;
            register u32 step = 29 << 24;
            shifted += step;
            x = shifted >> 24;
            parts++;
            i++;
        } while (i < 3);
        register u32 zero = 0;
        register u8 *last asm("r6") = end;
        *last = zero;
        register Position *position = node->position;
        register DigitPart *storedParts asm("r7") = first;
        position->parts = storedParts;
        register void (*storedCallback)(Node *) = callback;
        asm volatile("" : : "r"(storedCallback));
        node->callback = storedCallback;
    }
}
}

extern "C" {
extern const s16 gUnknown_08edbe7c[];
s32 FUN_0801f914(s32, s32);
void FUN_0801fed8(u8, u32);
void FUN_0802dbb4(Node *node) {
    s8 *state = (s8 *)node->allocation;
    const s16 *coordinates = gUnknown_08edbe7c + node->position->player * 3;
    state[21] = FUN_0801f914(*coordinates++, state[21]);
    state[29] = FUN_0801f914(*coordinates++, state[29]);
    state[37] = FUN_0801f914(*coordinates, state[37]);
    FUN_0801fed8(node->index, 0);
}
}
extern "C" {
extern const DigitPart gUnknown_08120124;
extern u32 gUnknown_03005264;
void FUN_0802dbb4(Node *);
void FUN_0802dc0c(Node *argument) {
    register Node *node asm("r4") = argument;
    u8 *state = (u8 *)node->allocation;
    if (gUnknown_03005264 != 0) {
        register u32 i asm("r3") = 0;
        register u8 *end = state + 39;
        asm volatile("" : : "r"(end));
        register DigitPart *first asm("r5") = (DigitPart *)(state + 16);
        register void (*callbackValue)(Node *) asm("r1") = FUN_0802dbb4;
        register void (*callback)(Node *) = callbackValue;
        register const DigitPart *sourceValue asm("r6") = &gUnknown_08120124;
        asm volatile("" : : "r"(sourceValue));
        register const DigitPart *source = sourceValue;
        register u32 oneValue asm("r7") = 1;
        asm volatile("" : "+r"(oneValue));
        register u32 one = oneValue;
        register DigitPart *parts = first;
        do {
            *parts = *source;
            register u32 flag = one;
            parts->more = flag;
            parts++;
            i++;
        } while (i < 3);
        register u32 zero = 0;
        register u8 *last = end;
        *last = zero;
        register Position *position = node->position;
        position->parts = first;
        register void (*storedCallback)(Node *) asm("r6") = callback;
        node->callback = storedCallback;
    }
}
}
extern "C" {
void FUN_0801f978(Node *, s32), FUN_0801fed8(u8, u32), FUN_0801f8c0(Node *);
void FUN_0802dc78(Node *node) {
    FUN_0801f978(node, 32);
    FUN_0801fed8(node->index, 0);
}
void FUN_0802dc90(Node *node) {
    node->position->x += 1 + (node->position->x - 32) * 2;
    if (node->position->x > 255)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
void FUN_0802dcc8(Node *node) {
    FUN_0801f978(node, 28);
    FUN_0801fed8(node->index, 0);
}
void FUN_0802dce0(Node *node) {
    node->position->x += 1 + (node->position->x - 28) * 2;
    if (node->position->x > 255)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
}
extern "C" {
struct SlideState {
    s16 offset;
    u8 children[2], unused4[2], selected, tick;
};
extern Node gUnknown_03003e20[];
extern const Position gUnknown_08edbcdc, gUnknown_08edbcfc;
extern const void *const gUnknown_08edbd74[];
extern u8 gUnknown_03002110[], gUnknown_030052d0[];
extern u32 gUnknown_03005264;
extern const u32 gUnknown_0807163c[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802dc78(Node *), FUN_0802dcc8(Node *);
void FUN_08020408(void *, const void *);
s32 FUN_0801f914(s32, s32);
void FUN_0801fba0(u16, u16);
void FUN_0802dd18(Node *node) {
    SlideState *state = (SlideState *)node->allocation;
    if (state->tick <= 5) {
        if (state->tick == 5) {
            if (state->children[0] == 0) {
                register Node *child asm("r1") =
                    FUN_0801f7d0(FUN_0802dc78, 16, gUnknown_03003e20, 0);
                state->children[0] = child->index;
                *child->position = gUnknown_08edbcdc;
                if (gUnknown_03002110[119] == 0)
                    FUN_08020408((void *)0x06012a80,
                                 gUnknown_08edbd74[gUnknown_030052d0[state->selected]]);
                else {
                    register void *destination = (void *)0x06012a80;
                    register const void *const *table asm("r2") = gUnknown_08edbd74;
                    register u8 *mapping asm("r3") = gUnknown_030052d0;
                    register u32 index = state->selected;
                    index += (u32)mapping;
                    index = *(u8 *)index * 4;
                    table += 11;
                    FUN_08020408(destination, *(const void **)(index + (u32)table));
                }
            }
            if (gUnknown_03005264 == 0) {
                register u8 *save = gUnknown_03002110;
                register u32 offset = 1168;
                if ((*(u16 *)(save + offset) & gUnknown_0807163c[state->selected + 1]) != 0 &&
                    state->children[1] == 0) {
                    register Node *child asm("r1") =
                        FUN_0801f7d0(FUN_0802dcc8, 16, gUnknown_03003e20, 0);
                    state->children[1] = child->index;
                    *child->position = gUnknown_08edbcfc;
                }
            }
        }
        state->tick++;
    }
    state->offset = FUN_0801f914(0, state->offset);
    FUN_0801fba0(16, state->offset);
}
}
extern "C" {
extern Node gUnknown_03003e20[];
void FUN_0802dc90(Node *), FUN_0802dce0(Node *), FUN_0802df40(Node *);
void FUN_0801fba0(u16, u16);
void FUN_0802de2c(Node *node) {
    SlideState *state = (SlideState *)node->allocation;
    if (state->tick < 255) {
        if (state->tick == 5) {
            if (state->children[0] != 0) {
                gUnknown_03003e20[state->children[0]].callback = FUN_0802dc90;
                state->children[0] = 0;
            }
            if (state->children[1] != 0) {
                gUnknown_03003e20[state->children[1]].callback = FUN_0802dce0;
                state->children[1] = 0;
            }
        }
        state->tick++;
    }
    state->offset = state->offset * 2 - 1;
    if (state->offset <= -256) {
        if (state->children[0] != 0) {
            gUnknown_03003e20[state->children[0]].callback = FUN_0802dc90;
            state->children[0] = 0;
        }
        if (state->children[1] != 0) {
            gUnknown_03003e20[state->children[1]].callback = FUN_0802dce0;
            state->children[1] = 0;
        }
        node->callback = FUN_0802df40;
        state->offset = -256;
    }
    FUN_0801fba0(16, state->offset);
}
}
extern "C" {
extern const void *const gUnknown_08edbd1c[], *const gUnknown_08edbd48[];
extern const u16 gUnknown_081201ec[];
extern u8 gUnknown_030052d0[];
void LZ77UnCompVram(const void *, void *), CpuFastSet(const void *, void *, u32);
void FUN_0801fba0(u16, u16), FUN_0802dd18(Node *);
void FUN_0802ded4(Node *node) {
    SlideState *state = (SlideState *)node->allocation;
    register u32 index = state->selected;
    register const void *const *images = gUnknown_08edbd1c;
    u8 *selected = gUnknown_030052d0 + index;
    LZ77UnCompVram(images[*selected], (void *)0x06008000);
    LZ77UnCompVram(gUnknown_08edbd48[*selected], (void *)0x0600f080);
    CpuFastSet(gUnknown_081201ec + *selected * 16, (void *)0x05000020, 8);
    state->tick = 0;
    node->callback = FUN_0802dd18;
}
void FUN_0802df40(Node *node) {
    SlideState *state = (SlideState *)node->allocation;
    state->offset = -256;
    FUN_0801fba0(20, 0xff00);
    state->children[0] = 0;
    state->children[1] = 0;
    node->callback = FUN_0802ded4;
}
}

extern "C" {
extern const u8 gUnknown_0812014c[];
extern const u8 gUnknown_08120134[];
extern const u8 gUnknown_081201a4[];
extern const u8 gUnknown_08120174[];
extern const u8 gUnknown_081201bc[];
extern const u8 gUnknown_0812034c[];
extern const u8 gUnknown_081214a4[];
extern const u8 gUnknown_08122984[];
extern const u8 gUnknown_081239e4[];
extern const u8 gUnknown_08124b9c[];
extern const u8 gUnknown_08125d88[];
extern const u8 gUnknown_08126f10[];
extern const u8 gUnknown_081280f0[];
extern const u8 gUnknown_08128f9c[];
extern const u8 gUnknown_0812a0bc[];
extern const u8 gUnknown_08121258[];
extern const u8 gUnknown_08122728[];
extern const u8 gUnknown_081237b0[];
extern const u8 gUnknown_08124950[];
extern const u8 gUnknown_08125b4c[];
extern const u8 gUnknown_08126cdc[];
extern const u8 gUnknown_08127edc[];
extern const u8 gUnknown_08128d5c[];
extern const u8 gUnknown_08129ea0[];
extern const u8 gUnknown_0812aee8[];
extern const u8 gUnknown_0812b0d8[];
extern const u8 gUnknown_0812b338[];
extern const u8 gUnknown_0812b5a4[];
extern const u8 gUnknown_0812b854[];
extern const u8 gUnknown_0812bab8[];
extern const u8 gUnknown_0812bd3c[];
extern const u8 gUnknown_0812bf38[];
extern const u8 gUnknown_0812c19c[];
extern const u8 gUnknown_0812c3f4[];
extern const u8 gUnknown_0812c61c[];
extern const u8 gUnknown_0812c84c[];
extern const u8 gUnknown_0812cb70[];
extern const u8 gUnknown_0812cee0[];
extern const u8 gUnknown_0812d248[];
extern const u8 gUnknown_0812d5d0[];
extern const u8 gUnknown_0812d8cc[];
extern const u8 gUnknown_0812db44[];
extern const u8 gUnknown_0812dea4[];
extern const u8 gUnknown_0812e100[];
extern const u8 gUnknown_0812e38c[];
extern const Position gUnknown_08edbc7c[3] = {
    {&gUnknown_0812014c, 8, 8, 48, 0, 0, 16, 0, 0, 0},
    {&gUnknown_08120134, 44, 96, 88, 0, 0, 32, 0, 0, 0},
    {&gUnknown_08120134, 0, 144, 104, 0, 0, 32, 0, 0, 0},
};
extern const Position gUnknown_08edbcac[3] = {
    {&gUnknown_08120124, 46, 86, 32, 0, 0, 4, 0, 0, 0},
    {&gUnknown_08120144, 64, 143, 120, 0, 0, 32, 0, 0, 0},
    {&gUnknown_081201a4, 0, 120, 184, 0, 0, 36, 0, 0, 0},
};
extern const Position gUnknown_08edbcdc = {&gUnknown_08120174, 255, 36, 340, 0, 0, 32, 0, 0, 0};
extern const Position gUnknown_08edbcec = {&gUnknown_08120144, 14, 125, 164, 0, 0, 32, 0, 0, 0};
extern const Position gUnknown_08edbcfc = {&gUnknown_081201bc, 255, 80, 272, 0, 0, 48, 0, 0, 0};
extern const Position gUnknown_08edbd0c[1] = {
    {&gUnknown_0812014c, 8, 8, 232, 0, 0, 16, 0, 0, 0},
};
extern const void *const gUnknown_08edbd1c[11] = {gUnknown_0812034c,
                                                  gUnknown_081214a4,
                                                  gUnknown_08122984,
                                                  gUnknown_081239e4,
                                                  gUnknown_08124b9c,
                                                  gUnknown_08125d88,
                                                  gUnknown_08126f10,
                                                  gUnknown_081280f0,
                                                  gUnknown_08128f9c,
                                                  gUnknown_0812a0bc,
                                                  0};
extern const void *const gUnknown_08edbd48[11] = {gUnknown_08121258,
                                                  gUnknown_08122728,
                                                  gUnknown_081237b0,
                                                  gUnknown_08124950,
                                                  gUnknown_08125b4c,
                                                  gUnknown_08126cdc,
                                                  gUnknown_08127edc,
                                                  gUnknown_08128d5c,
                                                  gUnknown_08129ea0,
                                                  gUnknown_0812aee8,
                                                  0};
extern const void *const gUnknown_08edbd74[66] = {gUnknown_0812b0d8,
                                                  gUnknown_0812b338,
                                                  gUnknown_0812b5a4,
                                                  gUnknown_0812b854,
                                                  gUnknown_0812bab8,
                                                  gUnknown_0812bd3c,
                                                  gUnknown_0812bf38,
                                                  gUnknown_0812c19c,
                                                  gUnknown_0812c3f4,
                                                  gUnknown_0812c61c,
                                                  0,
                                                  gUnknown_0812c84c,
                                                  gUnknown_0812cb70,
                                                  gUnknown_0812cee0,
                                                  gUnknown_0812d248,
                                                  gUnknown_0812d5d0,
                                                  gUnknown_0812d8cc,
                                                  gUnknown_0812db44,
                                                  gUnknown_0812dea4,
                                                  gUnknown_0812e100,
                                                  gUnknown_0812e38c,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0};
extern const s16 gUnknown_08edbe7c[12] = {0, 0, 0, -7, 7, 7, -14, 0, 14, -14, 0, 14};
extern const s16 gUnknown_0812e5f8[8]
    __attribute__((section(".rodata.coordinates"))) = {21, 62, 119, 62, 16, 102, 114, 102};
u8 gUnknown_030052b0;
u8 gUnknown_030052b4 __attribute__((section(".bss.selected"))) = 0;
u8 gUnknown_030052b8 __attribute__((section(".bss.variant"))) = 0;
}
