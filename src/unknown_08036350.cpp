// Inferred complete text-entry scene TU: 0x08036350..0x08037148.
// C++ fallback; original language, names and declarations are unknown.
// See docs/scene-36350-tu-cpp.md for ownership and verification evidence.
#include "types.h"
struct Position {
    const void *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, timer;
};
struct Node {
    void (*callback)(Node *);
    u8 field4, previous, index, next;
    Position *position;
    void *allocation;
};
struct Scene {
    void (*callback)(void);
    u16 entries[3];
    u8 count, flag;
};
struct Input {
    u16 fields[5];
};
struct State {
    u8 prefix[16], first, second, padding[2];
    u16 scroll;
};
extern "C" {

extern const u16 gUnknown_08156c70[], gUnknown_081327d4[];
extern const u8 gUnknown_08156d10[], gUnknown_08156f08[], gUnknown_0815711c[], gUnknown_08157934[],
    gUnknown_08156ea8[], gUnknown_08156df0[];
extern const Position gUnknown_08edcc0c, gUnknown_08edcc1c, gUnknown_08edcc2c;

extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern u16 gUnknown_03005200[];
void CpuFastSet(const void *, void *, u32);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020f64(u16);
u32 FUN_08020978(u32, u32, u16, u32);
extern u16 gUnknown_03005384;
extern u8 gUnknown_0300537c;
extern const u32 gUnknown_0807163c[];
extern const u16 *const gUnknown_08edcc3c[];
void FUN_08036350(void) {
    u16 y = 0;
    u16 rowIndex = gUnknown_03005384 / 10;
    u32 zero = 0;
    u16 row;
    CpuFastSet(&zero, (void *)0x06000800, 0x01000780);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06000800, 20, 12, 0);
    for (row = 0; row <= 5; row++) {
        const u16 *entry = gUnknown_08edcc3c[rowIndex];
        u16 x = 0;
        while (*entry != 0xfffe) {
            u16 offset = 8 - (FUN_08020f64(*entry) >> 1);
            FUN_08020978(x + offset, y, *entry, 2);
            ++entry;
            x += 16;
        }
        y += 16;
        rowIndex++;
        if (rowIndex > 34)
            rowIndex = 0;
    }
}
u8 FUN_08036428(u16 tile) {
    u16 slot = 0;
    u8 result;
    if ((gUnknown_0300537c & gUnknown_0807163c[slot]) != 0) {
        u8 *usedSlots = &gUnknown_0300537c;
        const u32 *slotMasks = gUnknown_0807163c;
        do {
            slot++;
            if (slot > 15)
                break;
        } while ((*usedSlots & slotMasks[slot]) != 0);
    }
    if (slot <= 15) {
        gUnknown_0300537c |= gUnknown_0807163c[slot];
        u8 *destination = (u8 *)0x06017800 + slot * 128;
        u32 zero = 0;
        CpuFastSet(&zero, destination, 0x01000020);
        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 2, 2, 0);
        u16 x = 8 - (FUN_08020f64(tile) >> 1);
        FUN_08020978(x, 0, tile, 2);
        result = slot;
    } else {
        result = 0;
    }
    return result;
}
void FUN_080364d8(void) {
    u32 zero = 0;
    CpuFastSet(&zero, (void *)0x06002600, 0x010000c0);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06002600, 12, 2, 0);
    gUnknown_03005200[5] = 0xfffe;
    const u16 *text = gUnknown_03005200;
    u16 x = 0;
    while (*text != 0xfffe) {
        u16 offset = 8 - (FUN_08020f64(*text) >> 1);
        FUN_08020978(x + offset, 0, *text, 2);
        ++text;
        x += 16;
    }
}

extern u8 gUnknown_03002110[], gUnknown_03005380, gUnknown_030020f8, gUnknown_0300537c;
extern u16 gUnknown_03005200[6], gUnknown_03005388, gUnknown_03005384, gUnknown_0300538c;
extern u32 gUnknown_03002610;
extern void (*gUnknown_03002030)(void);
extern Node gUnknown_03003e20[];
extern const u8 gUnknown_08132544[];
void FUN_08039e20(void), FUN_08020134(u32), FUN_08036350(void), FUN_080364d8(void),
    FUN_08036888(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void),
    FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(u16 *, const u16 *, u32, u32, u16), FUN_0801fba0(u16, u16), FUN_0801f618(u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d20(Node *), FUN_08036d90(Node *), FUN_08036e08(Node *), FUN_08037110(Node *),
    FUN_0801f9d8(Node *), FUN_08036898(Node *);
void FUN_08036560(void) {
    u32 zeroPalette;
    u32 zeroF800;
    u32 zeroF000;
    u32 zero0800;
    u32 zeroE800;
    u32 row;
    u32 column;
    Node *node;
    u32 *zeroE800Address;

    if (gUnknown_03005380 == 0) {
        u8 *state = (u8 *)&gUnknown_03002110;

        if (*(u16 *)(state + 96) != 0) {
            gUnknown_03002030 = FUN_08039e20;
            gUnknown_030020f8 = 1;
            FUN_08020134(gUnknown_03002610);
            return;
        }
    }

    gUnknown_03005200[4] = 0;
    gUnknown_03005200[3] = 0;
    gUnknown_03005200[2] = 0;
    gUnknown_03005200[1] = 0;
    gUnknown_03005200[0] = 0;
    gUnknown_03005200[5] = 0xFFFE;
    gUnknown_03005388 = 0;
    gUnknown_03005384 = 0;
    gUnknown_0300538c = 0;
    gUnknown_0300537c = 0;

    FUN_0801fbfc(gUnknown_08156c70, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();

    zeroPalette = 0;
    CpuFastSet(&zeroPalette, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_08156d10, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600C000);
    LZ77UnCompVram(gUnknown_08156f08, (void *)0x06010000);
    {
        register s32 variant = gUnknown_03002110[119];

        if (variant == 0) {
            LZ77UnCompVram(gUnknown_0815711c, (void *)0x06010C00);
        } else {
            if (variant >= 0) {
                if (variant <= 5) {
                    LZ77UnCompVram(gUnknown_08157934, (void *)0x06010C00);
                    gUnknown_03005384 = 200;
                }
            }
        }
    }

    zeroF800 = 0;
    CpuFastSet(&zeroF800, (void *)0x0600F800, 0x01000200);
    LZ77UnCompVram(gUnknown_08156ea8, (void *)0x0600F800);
    zeroF000 = 0;
    CpuFastSet(&zeroF000, (void *)0x0600F000, 0x01000200);
    zero0800 = 0;
    CpuFastSet(&zero0800, (void *)0x06000800, 0x01000780);
    {
        register u16 *base asm("r3") = (u16 *)0x0600F1CA;
        u16 tile = 0x1040;
        register u32 outer asm("r6") = 0;

        zeroE800Address = &zeroE800;

        do {
            register u32 inner = 0;
            register u16 *destination = base;

            do {
                u16 current = tile;

                tile = tile + 1;
                *destination = current;
                destination += 32;
                inner++;
            } while (inner <= 11);
            base++;
            outer++;
        } while (outer <= 19);
    }
    {
        register u16 *base = (u16 *)0x0600F114;
        register u16 tile = 0x1130;
        register u32 counter asm("r6") = 0;

        do {
            u16 first = tile;
            u16 second;

            tile++;
            second = tile;
            base[0] = first;
            {
                register u16 *secondDestination = base + 32;

                tile++;
                *secondDestination = second;
            }
            base++;
            counter++;
        } while (counter <= 9);
    }
    FUN_08036350();
    zeroE800 = 0;
    CpuFastSet(zeroE800Address, (void *)0x0600E800, 0x01000200);
    LZ77UnCompVram(gUnknown_08156df0, (void *)0x0600E8C0);

    {
        u16 *destination = (u16 *)0x0600E000;
        register u32 rowCounter asm("r6") = 0;

        do {
            register u32 columnCounter = 0;

            do {
                FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xF200);
                destination += 8;
                columnCounter++;
            } while (columnCounter <= 3);
            destination += 224;
            rowCounter++;
        } while (rowCounter <= 3);
    }

    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08036d90, 8, gUnknown_03003e20, 0);
    {
        register u32 rowCounter asm("r6") = 0;
        register u32 base asm("r7") = 9;

        do {
            register u32 columnCounter = 0;
            register u32 currentBase = base;

            do {
                node = FUN_0801f7d0(FUN_08036e08, 24, gUnknown_03003e20, 0);
                node->position->player = currentBase - columnCounter;
                columnCounter++;
            } while (columnCounter <= 9);
            base += 10;
            rowCounter++;
        } while (rowCounter <= 5);
    }
    {
        register u32 counter asm("r6") = 0;
        register u32 base = 4;

        do {
            node = FUN_0801f7d0(FUN_08037110, 24, gUnknown_03003e20, 0);
            node->position->player = base - counter;
            counter++;
        } while (counter <= 4);
    }

    FUN_080364d8();
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    if (gUnknown_03005380 != 0) {
        *node->position = gUnknown_08edcc2c;
    } else {
        *node->position = gUnknown_08edcc0c;
    }
    node = FUN_0801f7d0(FUN_08036898, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcc1c;

    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08036888;
    if (gUnknown_03005380 == 0) {
        FUN_0801f618(4);
    }
}

extern u8 gUnknown_03005380, gUnknown_0300537c;
extern u16 gUnknown_0300538c;
extern const u32 gUnknown_0807163c[];
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_0801fed8(u8, u8);
void FUN_08036888(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_08036898(Node *node) {
    if (gUnknown_03005380 || gUnknown_0300538c)
        FUN_0801fed8(node->index, 0);
}
void FUN_080368c0(u8 slot) { gUnknown_0300537c &= ~gUnknown_0807163c[slot]; }

extern Input gUnknown_030048e0;
extern u8 gUnknown_03005380, gUnknown_03002110[];
extern u16 gUnknown_0300538c, gUnknown_03005384, gUnknown_03005388, gUnknown_03005200[6];
extern u32 gUnknown_03002610;
extern const u8 gUnknown_08158672;
extern const u16 gUnknown_08158660[];
extern const u32 gUnknown_0807163c[];
extern const u16 *const gUnknown_08edcce8[], *const gUnknown_08edcc3c[];
extern Scene gUnknown_03005330;
void FUN_080402b0(void), FUN_08036d4c(void), FUN_08036d1c(void), FUN_08036ce4(void);
void FUN_0801f718(u16, u16), FUN_0801f618(u16), FUN_08020134(u32);
void FUN_080364d8(void), FUN_08036350(void);
void FUN_080368dc(Node *node) {
    struct Frame {
        Node *node;
        u32 offset, selected;
    } frame;
    frame.node = node;
    if (gUnknown_030048e0.fields[2] & 8) {
        register u32 initialMode asm("r1") = gUnknown_03005380;
        if (initialMode) {
            register u32 i asm("r4") = gUnknown_0300538c;
            if (i <= 5) {
                register u16 *base = gUnknown_03005200;
                register u32 terminator = 0xfffe;
                register u16 *destination = (u16 *)((i << 1) + (u32)base);
                do {
                    *destination++ = terminator;
                    ++i;
                } while (i <= 5);
            }
            register u32 entry asm("r10") = 0;
            register const u8 *entryCount asm("r1") = &gUnknown_08158672;
            if (entry < *entryCount) {
                register Scene *sceneBase asm("r2") = &gUnknown_03005330;
                asm("" : : "r"(sceneBase));
                register Scene *scene asm("r12") = sceneBase;
                register u32 offsetZero asm("r4") = 0;
                frame.offset = offsetZero;
                do {
                    register const u16 *base asm("r6") = gUnknown_03005200;
                    register const u16 *input asm("r8") = base;
                    register const u8 *table asm("r0") = (const u8 *)gUnknown_08edcce8;
                    register u32 offset asm("r1") = frame.offset;
                    register const u16 *text asm("r5") = *(const u16 *const *)(offset + (u32)table);
                    u32 i = 0;
                    register u32 letter;
                    letter = *text;
                    register u32 inputLetter asm("r2") = *base;
                    asm("" : : "r"(inputLetter));
                    if (letter == inputLetter) {
                        register const u8 *maskBase = (const u8 *)gUnknown_0807163c;
                        register u32 maskOffset asm("r6") = frame.offset;
                        maskOffset += (u32)maskBase;
                        register const u32 *maskPointer asm("r9") = (const u32 *)maskOffset;
                    compare_letter:
                        if (letter == 0xfffe) {
                            register const u16 *selectionTable = gUnknown_08158660;
                            register const u16 *selectionAddress =
                                (const u16 *)((entry << 1) + (u32)selectionTable);
                            register u32 selection = *selectionAddress;
                            frame.selected = selection;
                            register u8 *save asm("r0") = gUnknown_03002110;
                            register u32 flagsOffset asm("r6") = 0x4dc;
                            asm("" : : "r"(flagsOffset));
                            register u32 *flags asm("r7") = (u32 *)(save + flagsOffset);
                            register u32 bits = *flags;
                            register const u32 *maskAddress asm("r6") = maskPointer;
                            register u32 mask asm("r3") = *maskAddress;
                            if (!(bits & mask)) {
                                save += 0x120;
                                u8 *count = (u8 *)(selection + (u32)save);
                                if (*count == 255)
                                    *count = 0;
                                if (*count > 8)
                                    goto next_entry;
                                *flags |= mask;
                                ++*count;
                                register void (*callback)(void) = FUN_080402b0;
                                register Scene *result asm("r6") = scene;
                                result->callback = callback;
                                result->entries[2] = *(u16 *)&frame.selected;
                                register u32 selectedValue asm("r1") = frame.selected;
                                register u32 value asm("r0") = (s16)selectedValue;
                                asm("" : "+r"(value));
                                register u32 mask16 asm("r2") = 0xffff;
                                value &= mask16;
                                result->entries[1] = value;
                                value &= mask16;
                                result->entries[0] = value;
                                result->count = 1;
                                register u32 zero asm("r4") = 0;
                                result->flag = zero;
                                register void (*next)(Node *) = (void (*)(Node *))FUN_08036d4c;
                                register Node *owner asm("r6") = frame.node;
                                owner->callback = next;
                                register const u8 *mode asm("r1") = &gUnknown_03005380;
                                if (!*mode)
                                    goto fade_normal;
                                goto fade_alternate;
                            }
                        }
                        ++text;
                        register u32 step asm("r2") = 2;
                        asm("" : : "r"(step));
                        input = (const u16 *)((u32)input + step);
                        if (++i <= 5) {
                            letter = *text;
                            register const u16 *currentInput asm("r6") = input;
                            if (letter == *currentInput)
                                goto compare_letter;
                        }
                    }
                next_entry:
                    frame.offset += 4;
                    register u32 nextEntry asm("r1") = 1;
                    asm("" : : "r"(nextEntry));
                    entry += nextEntry;
                    register const u8 *countAddress asm("r2") = &gUnknown_08158672;
                    if (entry >= *countAddress)
                        break;
                } while (1);
            }
            register void (*next)(Node *) = (void (*)(Node *))FUN_08036d1c;
            register Node *owner asm("r4") = frame.node;
            owner->callback = next;
            register const u8 *mode asm("r6") = &gUnknown_03005380;
            if (!*mode) {
                FUN_0801f718(4, 120);
                asm("" : : : "memory");
            } else
                FUN_0801f718(31, 120);
            goto rejected;
        } else {
            if (!gUnknown_0300538c)
                goto rejected;
            FUN_08020134(gUnknown_03002610);
            u8 i = 0;
            for (; i < gUnknown_0300538c; i++)
                ((u16 *)(gUnknown_03002110 + 96))[i] = gUnknown_03005200[i];
            register void (*next)(Node *) = (void (*)(Node *))FUN_08036ce4;
            if (i <= 5) {
                register u16 *destinationBase = (u16 *)(gUnknown_03002110 + 96);
                register u32 terminator = 0xfffe;
                do {
                    destinationBase[i] = terminator;
                    ++i;
                } while (i <= 5);
            }
            register Node *owner asm("r2") = frame.node;
            owner->callback = next;
        }
        {
            register const u8 *mode asm("r4") = &gUnknown_03005380;
            if (*mode)
                goto fade_alternate;
        }
    fade_normal:
        FUN_0801f718(4, 120);
        goto confirmed;
    fade_alternate:
        FUN_0801f718(31, 120);
    confirmed:
        FUN_0801f618(404);
        return;
    rejected:
        FUN_0801f618(419);
    } else if (gUnknown_030048e0.fields[2] & 1) {
        if (gUnknown_0300538c > 4)
            gUnknown_0300538c = 4;
        u16 index = gUnknown_03005384 + gUnknown_03005388;
        if (index > 349) {
            register s32 adjustment asm("r6") = -350;
            asm("" : : "r"(adjustment));
            register u32 adjusted asm("r0") = index + adjustment;
            index = adjusted;
        }
        const u16 *row = gUnknown_08edcc3c[(u16)(index / 10)];
        register u16 *destinationBase = gUnknown_03005200;
        u16 *destination = (u16 *)((gUnknown_0300538c << 1) + (u32)destinationBase);
        u16 value = row[(u16)(index % 10)];
        if (*destination != value) {
            *destination = value;
            FUN_0801f618(402);
        }
        ++gUnknown_0300538c;
        FUN_080364d8();
    } else if (gUnknown_030048e0.fields[2] & 2) {
        if (gUnknown_0300538c) {
            --gUnknown_0300538c;
            gUnknown_03005200[gUnknown_0300538c] = 0;
            FUN_080364d8();
            FUN_0801f618(403);
        }
    } else if (gUnknown_030048e0.fields[4] & 64) {
        if (gUnknown_03005388 > 19)
            gUnknown_03005388 -= 10;
        else {
            if (gUnknown_03005384 > 9)
                gUnknown_03005384 -= 10;
            else
                gUnknown_03005384 += 340;
        redraw:
            FUN_08036350();
        }
        goto sound;
    } else if (gUnknown_030048e0.fields[4] & 128) {
        if (gUnknown_03005388 <= 39)
            gUnknown_03005388 += 10;
        else {
            if ((gUnknown_03005384 += 10) > 349)
                gUnknown_03005384 -= 350;
            goto redraw;
        }
        goto sound;
    } else if (gUnknown_030048e0.fields[4] & 32) {
        {
            register u32 row asm("r5") = (u16)(gUnknown_03005388 / 10);
            if (row != (u16)(--gUnknown_03005388 / 10))
                gUnknown_03005388 += 10;
        }
    sound:
        FUN_0801f618(401);
    } else if (gUnknown_030048e0.fields[4] & 16) {
        register u32 row asm("r5") = (u16)(gUnknown_03005388 / 10);
        if (row != (u16)(++gUnknown_03005388 / 10))
            gUnknown_03005388 -= 10;
        FUN_0801f618(401);
    }
}

extern u8 gUnknown_030020f8, gUnknown_03005380;
extern void (*gUnknown_03002030)(void);
extern Scene gUnknown_03005330;
extern const u16 gUnknown_08156cd0[], gUnknown_08132754[], gUnknown_08158194[];
extern const u8 gUnknown_081581f4[];
u8 FUN_0802067c(u16 *, u32), FUN_08020500(u16 *, const u16 *, u32);
void FUN_08039e20(void), FUN_080402b0(void), FUN_08034f28(void);
void FUN_080368dc(Node *), FUN_08036e64(Node *), FUN_080217d0(u8);
void FUN_08036ce4(void) {
    if (FUN_0802067c((u16 *)0x05000000, 512)) {
        gUnknown_03002030 = FUN_08039e20;
        gUnknown_030020f8 = 1;
        FUN_080217d0(1);
    }
}
void FUN_08036d1c(void) {
    if (FUN_0802067c((u16 *)0x05000000, 512)) {
        gUnknown_03005380 = 0;
        gUnknown_03002030 = FUN_080402b0;
    }
}
void FUN_08036d4c(void) {
    if (FUN_0802067c((u16 *)0x05000000, 512)) {
        gUnknown_03005380 = 1;
        gUnknown_03005330.callback = FUN_080402b0;
        gUnknown_03005330.flag = 1;
        gUnknown_03002030 = FUN_08034f28;
    }
}
void FUN_08036d90(Node *node) {
    register u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_08156cd0, 32) == 0;
    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_08132754, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_08158194, 48) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (!result)
        node->callback = FUN_080368dc;
}
void FUN_08036e08(Node *node) {
    u8 *state = (u8 *)node->allocation;
    u32 zero = 0;
    state[16] = zero;
    state[17] = zero;
    node->position->parts = gUnknown_081581f4;
    node->position->tile = zero;
    node->position->x = (u8)(node->position->player % 10) * 16 + 40;
    node->position->y = (u8)(node->position->player / 10) * 16 + 56;
    node->position->attr0 = zero;
    node->position->attr1 = zero;
    node->position->attr2 = 12;
    node->callback = FUN_08036e64;
}

extern u16 gUnknown_03005388, gUnknown_03005384;
extern Node gUnknown_03003e20[];
extern const Position gUnknown_08edcbec[2];
extern const u16 *const gUnknown_08edcc3c[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_0801f9d8(Node *), FUN_08037100(Node *), FUN_0801f8c0(Node *);
void FUN_080368c0(u8), FUN_0801fed8(u8, u8);
u8 FUN_08036428(u16);
void FUN_08036e64(Node *node) {
    State *state = (State *)node->allocation;
    if (node->position->player == gUnknown_03005388) {
        if (++node->position->state > 3)
            node->position->state = 4;
    } else {
        if (node->position->state == 0)
            goto inactive;
        --node->position->state;
    }
    if (node->position->state) {
        Node *child;
        u16 index;
        node->position->tile = 80;
        node->position->x = (u8)(node->position->player % 10) * 16 + (node->position->state + 40);
        node->position->y = (u8)(node->position->player / 10) * 16 - (node->position->state - 56);
        if (!state->first) {
            state->scroll = gUnknown_03005384;
            child = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
            state->first = child->index;
            *child->position = gUnknown_08edcbec[0];
            child = FUN_0801f7d0(FUN_08037100, 16, gUnknown_03003e20, 0);
            state->second = child->index;
            *child->position = gUnknown_08edcbec[1];
            index = gUnknown_03005384 + gUnknown_03005388;
            if (index > 349)
                index -= 350;
            goto update;
        } else if (state->scroll != gUnknown_03005384) {
            state->scroll = gUnknown_03005384;
            child = &gUnknown_03003e20[state->second];
            FUN_080368c0(child->position->player);
            index = gUnknown_03005384 + gUnknown_03005388;
            if (index > 349)
                index -= 350;
        update:
            const u16 *row = gUnknown_08edcc3c[(u16)(index / 10)];
            child->position->player = FUN_08036428(row[(u16)(index % 10)]);
            child->position->tile = child->position->player * 4;
        }
        gUnknown_03003e20[state->first].position->tile = node->position->state * 16;
        gUnknown_03003e20[state->first].position->x = node->position->x;
        gUnknown_03003e20[state->first].position->y = node->position->y;
        gUnknown_03003e20[state->second].position->x = node->position->x;
        gUnknown_03003e20[state->second].position->y = node->position->y;
    } else {
    inactive:
        register Node *inactiveNode = node;
        register Position *position = inactiveNode->position;
        register u32 zero asm("r5") = 0;
        position->tile = 0;
        node->position->x = (u8)(node->position->player % 10) * 16 + 40;
        node->position->y = (u8)(node->position->player / 10) * 16 + 56;
        if (state->first) {
            FUN_0801f8c0(&gUnknown_03003e20[state->first]);
            FUN_080368c0(gUnknown_03003e20[state->second].position->player);
            FUN_0801f8c0(&gUnknown_03003e20[state->second]);
            state->first = zero;
            state->second = zero;
        }
    }
    FUN_0801fed8(node->index, 0);
}

extern u16 gUnknown_0300538c;
extern const u8 gUnknown_081581f4[];
void FUN_0801fed8(u8, u8);
void FUN_080370b8(Node *node) {
    u8 selected;
    if (gUnknown_0300538c <= 3)
        selected = gUnknown_0300538c;
    else
        selected = 4;
    if (node->position->player == selected)
        node->position->tile = 80;
    else
        node->position->tile = 0;
    node->position->x = node->position->player * 16 + 80;
    node->position->y = 32;
    FUN_0801fed8(node->index, 0);
}
void FUN_08037100(Node *node) { FUN_0801fed8(node->index, 0); }
void FUN_08037110(Node *node) {
    node->position->parts = gUnknown_081581f4;
    node->position->tile = 0;
    node->position->x = node->position->player * 16 + 80;
    node->position->y = 32;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 12;
    node->callback = FUN_080370b8;
}

extern const u8 gUnknown_0815823c[];
extern const u8 gUnknown_0815822c[];
extern const u8 gUnknown_081581fc[];
extern const u8 gUnknown_0815820c[];
extern const u8 gUnknown_081581fc[];
extern const u16 gUnknown_0815824c[];
extern const u16 gUnknown_08158264[];
extern const u16 gUnknown_0815827c[];
extern const u16 gUnknown_08158294[];
extern const u16 gUnknown_081582ac[];
extern const u16 gUnknown_081582c4[];
extern const u16 gUnknown_081582dc[];
extern const u16 gUnknown_081582f4[];
extern const u16 gUnknown_0815830c[];
extern const u16 gUnknown_08158324[];
extern const u16 gUnknown_0815833c[];
extern const u16 gUnknown_08158354[];
extern const u16 gUnknown_0815836c[];
extern const u16 gUnknown_08158384[];
extern const u16 gUnknown_0815839c[];
extern const u16 gUnknown_081583b4[];
extern const u16 gUnknown_081583cc[];
extern const u16 gUnknown_081583e4[];
extern const u16 gUnknown_081583fc[];
extern const u16 gUnknown_08158414[];
extern const u16 gUnknown_0815842c[];
extern const u16 gUnknown_08158444[];
extern const u16 gUnknown_0815845c[];
extern const u16 gUnknown_08158474[];
extern const u16 gUnknown_0815848c[];
extern const u16 gUnknown_081584a4[];
extern const u16 gUnknown_081584bc[];
extern const u16 gUnknown_081584d4[];
extern const u16 gUnknown_081584ec[];
extern const u16 gUnknown_08158504[];
extern const u16 gUnknown_0815851c[];
extern const u16 gUnknown_08158534[];
extern const u16 gUnknown_0815854c[];
extern const u16 gUnknown_08158564[];
extern const u16 gUnknown_0815857c[];
extern const u16 gUnknown_08158594[];
extern const u16 gUnknown_081585a0[];
extern const u16 gUnknown_081585ac[];
extern const u16 gUnknown_081585b8[];
extern const u16 gUnknown_081585c4[];
extern const u16 gUnknown_081585d0[];
extern const u16 gUnknown_081585dc[];
extern const u16 gUnknown_081585e8[];
extern const u16 gUnknown_081585f4[];
extern const u16 gUnknown_08158600[];
extern const u16 gUnknown_0815860c[];
extern const u16 gUnknown_08158618[];
extern const u16 gUnknown_08158624[];
extern const u16 gUnknown_08158630[];
extern const u16 gUnknown_0815863c[];
extern const u16 gUnknown_08158648[];
extern const u16 gUnknown_08158654[];
extern const Position gUnknown_08edcbec[2] __attribute__((section(".rodata"))) = {
    {gUnknown_0815823c, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {gUnknown_0815822c, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
extern const Position gUnknown_08edcc0c
    __attribute__((section(".rodata"))) = {gUnknown_081581fc, 64, 16, 96, 0, 0, 0, 0, 0, 0};
extern const Position gUnknown_08edcc1c
    __attribute__((section(".rodata"))) = {gUnknown_0815820c, 192, 12, 160, 0, 0, 0, 0, 0, 0};
extern const Position gUnknown_08edcc2c
    __attribute__((section(".rodata"))) = {gUnknown_081581fc, 64, 16, 192, 0, 0, 0, 0, 0, 0};
extern const u16 *const gUnknown_08edcc3c[] __attribute__((section(".rodata"))) = {
    gUnknown_0815824c, gUnknown_08158264, gUnknown_0815827c, gUnknown_08158294, gUnknown_081582ac,
    gUnknown_081582c4, gUnknown_081582dc, gUnknown_081582f4, gUnknown_0815830c, gUnknown_08158324,
    gUnknown_0815833c, gUnknown_08158354, gUnknown_0815836c, gUnknown_08158384, gUnknown_0815839c,
    gUnknown_081583b4, gUnknown_081583cc, gUnknown_081583e4, gUnknown_081583fc, gUnknown_08158414,
    gUnknown_0815842c, gUnknown_08158444, gUnknown_0815845c, gUnknown_08158474, gUnknown_0815848c,
    gUnknown_081584a4, gUnknown_081584bc, gUnknown_081584d4, gUnknown_081584ec, gUnknown_08158504,
    gUnknown_0815851c, gUnknown_08158534, gUnknown_0815854c, gUnknown_08158564, gUnknown_0815857c};
extern const u16 *const gUnknown_08edccc8[] __attribute__((section(".rodata"))) = {
    gUnknown_08158594, gUnknown_081585a0, gUnknown_081585ac, gUnknown_081585b8,
    gUnknown_081585c4, gUnknown_081585d0, gUnknown_081585dc, gUnknown_081585e8};
extern const u16 *const gUnknown_08edcce8[] __attribute__((section(".rodata"))) = {
    gUnknown_081585f4, gUnknown_08158600, gUnknown_0815860c, gUnknown_08158618, gUnknown_08158624,
    gUnknown_08158630, gUnknown_0815863c, gUnknown_08158648, gUnknown_08158654};
extern const u16 gUnknown_08156c70[] __attribute__((section(".rodata.registers"))) = {
    0,  0, 8,  7936, 16, 0,    18, 0, 10, 7682, 20, 0,     22, 0,    12, 7427,
    24, 0, 26, 0,    14, 7179, 28, 0, 30, 0,    80, 16193, 82, 2566, 84, 0};
struct CodeMetadata {
    u16 selections[9];
    u8 count;
};
extern const CodeMetadata sceneCodeMetadata __attribute__((section(".rodata.codes"))) = {
    {238 + 8 * 0, 238 + 8 * 1, 238 + 8 * 2, 238 + 8 * 3, 238 + 8 * 4, 238 + 8 * 5, 238 + 8 * 6,
     238 + 8 * 7, 238 + 8 * 8},
    9};

u8 gUnknown_0300537c __attribute__((section(".bss"))) = 0;
// Shared scene entry/return mode; external callers also set and inspect this byte.
u8 gUnknown_03005380 __attribute__((section(".bss.state_3005380"))) = 0;
u16 gUnknown_03005384 __attribute__((section(".bss.state_3005384"))) = 0;
u16 gUnknown_03005388 __attribute__((section(".bss.state_3005388"))) = 0;
u16 gUnknown_0300538c __attribute__((section(".bss.state_300538c"))) = 0;
}
