#include "types.h"
// C++ reconstruction fallback; original language and names are unknown.
// Full-TU evidence and compiler constraints: docs/lobby-tu-cpp.md.
extern "C" {
struct Position {
    const void *graphics;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, index, timer, state;
};
struct Node {
    const void *callback;
    u8 flags, previous, index, next;
    Position *position;
    void *allocation;
};
struct LobbyState {
    u32 phase;
    u8 selection, child;
};
struct LabelState {
    const void *destination;
    u16 tile, unused;
};
struct Coordinates {
    s16 idleX, idleY, readyX, readyY;
};
struct SpritePart {
    u16 tile;
    u8 attr0, attr1, attr2;
    s8 x, y;
    u8 more;
};
typedef char SpritePartSizeMustBeEight[(sizeof(SpritePart) == 8) ? 1 : -1];
struct Record {
    u8 prefix[2];
    s16 command;
    u8 payload[12];
};
struct Input {
    u16 held, pressed, repeated;
};
struct SettingsView {
    u8 prefix[108];
    u8 a, b, c, d, e, f, g, h, i;
    u8 suffix[3];
};
extern Node gUnknown_03003e20[];
extern u8 gUnknown_03002110[];
extern Record gUnknown_030016f0;
extern Input gUnknown_030048e0;
extern u8 gUnknown_03002600[], gUnknown_03005268[], gUnknown_0300524c[];
extern u8 gUnknown_0300525c, gUnknown_03005260, gUnknown_030017c4, gUnknown_03005300;
extern u32 gUnknown_03005264, gUnknown_03005258, gUnknown_03005254, gUnknown_03001380,
    gUnknown_03001730;
extern u16 gUnknown_03001b10[], gUnknown_03005200[][8];
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_0810c5b4[], gUnknown_081327d4[];
extern const u8 gUnknown_0815c4b4[], gUnknown_081323d4[], gUnknown_0810cd78[];
extern const u8 gUnknown_0810d13c[], gUnknown_0810d20c[], gUnknown_0810d250[];
extern const u8 gUnknown_0810d784[], gUnknown_0810d928[];
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *const gUnknown_08edb9ac[], *const gUnknown_08edb9cc[];
extern const u16 *const gUnknown_08edb9ec[], *const gUnknown_08edba0c[];
extern const u16 *const gUnknown_08edba2c[], *const gUnknown_08edba4c[];
extern u8 gUnknown_0600dfc0[], gUnknown_0600da80[];
extern u16 gUnknown_05000080[], gUnknown_050001c0[], gUnknown_050001e0[], gUnknown_05000200[];
extern const u16 gUnknown_0810c5f4[], gUnknown_0815e67c[], gUnknown_081326f4[], gUnknown_0810c634[];
extern const SpritePart gUnknown_08edb974[], gUnknown_08edb94c[], gUnknown_08edb97c[],
    gUnknown_08edb984[];
extern const u8 gUnknown_0804df7c[];
extern const Coordinates gUnknown_08edb98c[];
void CpuFastSet(const void *, void *, u32);
void LZ77UnCompVram(const void *, void *);
void FUN_0801fbfc(const u16 *, u8);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_0801f89c(void), FUN_0801fda0(void);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16), FUN_0801f718(u16, u16);
void FUN_080184c8(void), FUN_08018444(void), FUN_08018c3c(void), FUN_08021268(u8),
    FUN_08021534(void);
void FUN_08030d3c(Node *), FUN_08039dd8(Node *);
void FUN_0803281c(void), FUN_08029250(void), FUN_080315bc(void), FUN_08039e20(void),
    FUN_0803d1a0(void);
u32 FUN_08020ad0(const u16 *), FUN_08020b74(u32, u32, const u16 *, u32, u32);
u32 FUN_0802067c(u16 *, u16), FUN_0801fab0(u16), FUN_0801f9e8(u16), FUN_080214c0(u32);
u8 FUN_08020500(u16 *, const u16 *, u16), FUN_08021484(void);
void FUN_0802f328(void *), FUN_0802f428(void *);
u32 FUN_0801f92c(Node *, s32, s32), FUN_0801fd18(s16, u32);
void FUN_0801fed8(u8, u32);
u16 FUN_08020fac(u16);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_080283f8(u32), FUN_080284b4(void), FUN_08028760(void);
void FUN_08028770(Node *), FUN_08028814(Node *), FUN_080288b4(Node *);
void FUN_08028bec(void), FUN_08028c80(Node *), FUN_08028d30(Node *), FUN_08028ed8(Node *);
void FUN_08028f1c(Node *), FUN_08028f5c(void), FUN_08028f80(Node *);
void FUN_08028f98(Node *), FUN_08029014(Node *), FUN_08029060(Node *), FUN_080290b4(Node *);
void FUN_080290e8(u32, u32, u32), FUN_080291a8(void), FUN_08029200(void);
}

// Symbolic text-pointer facts and four coordinate rows; assets remain external.
extern "C" {
extern const u16 gUnknown_0810c6b4[];
extern const u16 gUnknown_0810c6c8[];
extern const u16 gUnknown_0810c6dc[];
extern const u16 gUnknown_0810c6f0[];
extern const u16 gUnknown_0810c704[];
extern const u16 gUnknown_0810c718[];
extern const u16 gUnknown_0810c72c[];
extern const u16 gUnknown_0810c740[];
extern const u16 gUnknown_0810c754[];
extern const u16 gUnknown_0810c770[];
extern const u16 gUnknown_0810c79c[];
extern const u16 gUnknown_0810c7c8[];
extern const u16 gUnknown_0810c7f4[];
extern const u16 gUnknown_0810c80c[];
extern const u16 gUnknown_0810c838[];
extern const u16 gUnknown_0810c864[];
extern const u16 gUnknown_0810c890[];
extern const u16 gUnknown_0810c8b0[];
extern const u16 gUnknown_0810c8dc[];
extern const u16 gUnknown_0810c908[];
extern const u16 gUnknown_0810c934[];
extern const u16 gUnknown_0810c95c[];
extern const u16 gUnknown_0810c984[];
extern const u16 gUnknown_0810c9ac[];
extern const u16 gUnknown_0810c9d4[];
extern const u16 gUnknown_0810c9ec[];
extern const u16 gUnknown_0810ca18[];
extern const u16 gUnknown_0810ca44[];
extern const u16 gUnknown_0810ca70[];
extern const u16 gUnknown_0810ca8c[];
extern const u16 gUnknown_0810cab4[];
extern const u16 gUnknown_0810cadc[];
extern const u16 gUnknown_0810cb04[];
extern const u16 gUnknown_0810cb30[];
extern const u16 gUnknown_0810cb60[];
extern const u16 gUnknown_0810cb90[];
extern const u16 gUnknown_0810cbc0[];
extern const u16 gUnknown_0810cbdc[];
extern const u16 gUnknown_0810cbf8[];
extern const u16 gUnknown_0810cc14[];
extern const u16 gUnknown_0810cc30[];
extern const u16 gUnknown_0810cc54[];
extern const u16 gUnknown_0810cc84[];
extern const u16 gUnknown_0810ccb4[];
extern const u16 gUnknown_0810cce4[];
extern const u16 gUnknown_0810cd00[];
extern const u16 gUnknown_0810cd28[];
extern const u16 gUnknown_0810cd50[];
// Renderer1FDA0 consumes tile/attribute bytes, signed offsets, and continuation.
const SpritePart gUnknown_08edb94c[] = {
    {0, 0x40, 0xc0, 0, -32, -16, 0},
};
// Four-part layout retained in place; no direct pointer reference found.
extern const SpritePart gUnknown_08edb954[] = {
    {32, 0, 0x80, 0x10, 46, 15, 1},
    {32, 0, 0x80, 0x10, -66, 15, 1},
    {32, 0, 0x80, 0x10, 46, -49, 1},
    {32, 0, 0x80, 0x10, -66, -49, 0},
};
const SpritePart gUnknown_08edb974[] = {
    {112, 0x40, 0xc0, 0x10, -32, -16, 0},
};
const SpritePart gUnknown_08edb97c[] = {
    {48, 0x40, 0xc0, 0x20, 0, 0, 0},
};
const SpritePart gUnknown_08edb984[] = {
    {80, 0x40, 0xc0, 0x30, 0, 0, 0},
};
const Coordinates gUnknown_08edb98c[] = {
    {32, 32, 32, 24},
    {144, 32, 144, 24},
    {32, 96, 32, 88},
    {144, 96, 144, 88},
};
const u16 *const gUnknown_08edb9ac[] = {
    gUnknown_0810c6b4, gUnknown_0810c6c8, gUnknown_0810c6dc, gUnknown_0810c6f0,
    gUnknown_0810c704, gUnknown_0810c718, gUnknown_0810c72c, gUnknown_0810c740,
};
const u16 *const gUnknown_08edb9cc[] = {
    gUnknown_0810c754, gUnknown_0810c770, gUnknown_0810c79c, gUnknown_0810c7c8,
    gUnknown_0810c7f4, gUnknown_0810c80c, gUnknown_0810c838, gUnknown_0810c864,
};
const u16 *const gUnknown_08edb9ec[] = {
    gUnknown_0810c890, gUnknown_0810c8b0, gUnknown_0810c8dc, gUnknown_0810c908,
    gUnknown_0810c934, gUnknown_0810c95c, gUnknown_0810c984, gUnknown_0810c9ac,
};
const u16 *const gUnknown_08edba0c[] = {
    gUnknown_0810c9d4, gUnknown_0810c9ec, gUnknown_0810ca18, gUnknown_0810ca44,
    gUnknown_0810ca70, gUnknown_0810ca8c, gUnknown_0810cab4, gUnknown_0810cadc,
};
const u16 *const gUnknown_08edba2c[] = {
    gUnknown_0810cb04, gUnknown_0810cb30, gUnknown_0810cb60, gUnknown_0810cb90,
    gUnknown_0810cbc0, gUnknown_0810cbdc, gUnknown_0810cbf8, gUnknown_0810cc14,
};
const u16 *const gUnknown_08edba4c[] = {
    gUnknown_0810cc30, gUnknown_0810cc54, gUnknown_0810cc84, gUnknown_0810ccb4,
    gUnknown_0810cce4, gUnknown_0810cd00, gUnknown_0810cd28, gUnknown_0810cd50,
};
}

extern "C" {
void FUN_080283f8(u32 index) {
    u32 selectedIndex = index;
    const void *fillSource = gUnknown_0600dfc0;
    u8 *destination = gUnknown_0600da80;
    for (u32 i = 0; i <= 20; i++) {
        CpuFastSet(fillSource, destination, 16);
        destination += 64;
    }
    if (selectedIndex == 0)
        return;
    const u16 *text;
    switch (gUnknown_03002110[119]) {
    case 0:
        text = gUnknown_08edb9ac[selectedIndex - 1];
        break;
    case 2:
        text = gUnknown_08edb9ec[selectedIndex - 1];
        break;
    case 3:
        text = gUnknown_08edba0c[selectedIndex - 1];
        break;
    case 4:
        text = gUnknown_08edba2c[selectedIndex - 1];
        break;
    case 5:
        text = gUnknown_08edba4c[selectedIndex - 1];
        break;
    default:
        text = gUnknown_08edb9cc[selectedIndex - 1];
        break;
    }
    u32 x = FUN_08020ad0(text);
    x = 88 - x / 2;
    FUN_08020b74(x, 0, text, 5, 6);
}

void FUN_080284b4(void) {
    u32 fills[5];
    FUN_0801fbfc(gUnknown_0810c5b4, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 i = 0;
    fills[0] = i;
    CpuFastSet(&fills[0], (void *)0x05000000, 0x01000100);
    fills[1] = i;
    u32 *clearSource = &fills[1];
    u8 *vram = (u8 *)0x06000000;
    CpuFastSet(clearSource, vram, 0x01000010);
    LZ77UnCompVram(gUnknown_0815c4b4, (void *)0x06000040);
    LZ77UnCompVram(gUnknown_081323d4, (void *)0x06005280);
    LZ77UnCompVram(gUnknown_0810cd78, (void *)0x06008000);
    fills[2] = i;
    u32 *backgroundClearSource = &fills[2];
    void *background = (void *)0x0600f800;
    CpuFastSet(backgroundClearSource, background, 0x01000200);
    LZ77UnCompVram(gUnknown_0810d13c, background);
    LZ77UnCompVram(gUnknown_0810d20c, (void *)0x0600fc00);
    u16 tile = 0x52d4;
    u16 *map = (u16 *)0x0600fc42;
    vram += ((*map & 0x3ff) + 0x400) * 32;
    u8 *destination = (u8 *)0x0600dfc0;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x0600da80, 21, 2, 0);
    for (; i <= 1; i++) {
        CpuFastSet(vram, destination, 8);
        destination += 32;
    }
    FUN_080283f8(0);
    i = 0;
    u16 *bottom = map + 32;
    u16 *top = map;
    for (; i <= 20; i++) {
        *top = tile++;
        *bottom++ = tile++;
        top++;
    }
    fills[3] = 0;
    CpuFastSet(&fills[3], (void *)0x0600f000, 0x01000200);
    fills[4] = 0;
    CpuFastSet(&fills[4], (void *)0x0600e800, 0x01000200);
    vram = (u8 *)0x0600e000;
    for (i = 0; i <= 3; i++) {
        for (u32 column = 0; column <= 3; column++) {
            FUN_08021000((u16 *)vram, gUnknown_081327d4, 8, 8, 0xf294);
            vram += 16;
        }
        vram += 448;
    }
    LZ77UnCompVram(gUnknown_0810d250, (void *)0x06010000);
    switch (gUnknown_03002110[0x77]) {
    case 0:
        LZ77UnCompVram(gUnknown_0810d784, (void *)0x06010e00);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LZ77UnCompVram(gUnknown_0810d928, (void *)0x06010e00);
        break;
    }
    FUN_0801f7d0(FUN_08028770, 8, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_08039dd8, 8, gUnknown_03003e20, 0);
    LabelState *label = (LabelState *)node->allocation;
    label->destination = (void *)0x0600f092;
    label->tile = 0xe002;
    label->unused = 0;
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08028760;
    gUnknown_0300525c = 0;
    gUnknown_03005254 = 0;
    if (gUnknown_03005264 == 4) {
        gUnknown_03001730 = 0;
        gUnknown_03001380 = 255;
        FUN_080184c8();
        FUN_08021268(gUnknown_03005300);
    } else {
        FUN_08018444();
    }
    FUN_0801f618(2);
}

void FUN_08028760(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08028770(Node *node) {
    LobbyState *allocation = (LobbyState *)node->allocation;
    allocation->phase = 1;
    Node *created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->index = 0;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->index = 1;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->index = 2;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->index = 3;
    created = FUN_0801f7d0(FUN_080290b4, 16, gUnknown_03003e20, 0);
    allocation->child = created->index;
    if (gUnknown_03005264 == 4)
        FUN_080283f8(0);
    else
        FUN_080283f8(1);
    node->callback = (const void *)FUN_08028814;
}

void FUN_08028814(Node *node) {
    u8 firstPending = FUN_08020500(gUnknown_05000080, gUnknown_0810c5f4, 32) == 0;
    u32 pending = firstPending;
    u8 result = FUN_08020500(gUnknown_050001c0, gUnknown_0815e67c, 16);
    if (result == 0)
        result = pending | 1;
    else
        result = pending;
    pending = result;
    result = FUN_08020500(gUnknown_050001e0, gUnknown_081326f4, 16);
    if (result == 0)
        result = pending | 1;
    else
        result = pending;
    pending = result;
    result = FUN_08020500(gUnknown_05000200, gUnknown_0810c634, 64);
    if (result == 0)
        result = pending | 1;
    else
        result = pending;
    pending = result;
    if (pending == 0)
        node->callback = (const void *)FUN_080288b4;
}

void FUN_080288b4(struct Node *node) {
    struct Node *current = node;
    // Register bindings and empty asm constraints reproduce observed lifetimes.
    // They are reconstruction choices, not recovered original declarations.
    register struct LobbyState *allocation asm("r8") = (LobbyState *)current->allocation;
    u8 count;
    u16 keys;
    u32 ready;
    register u32 one asm("r9");
    register u32 oneAgain asm("r10");
    register u32 secondOne asm("r2");
    register u32 keyMask asm("r5");
    register u32 zero asm("r4");
    register u8 *countAddress asm("r6");
    register u8 *selectionAddress asm("r2");
    register u8 *validationAddress asm("r3");
    register u32 selectionValue asm("r0");
    register u32 secondMask asm("r0");
    register struct LobbyState *selectionRead asm("r4");
    register struct LobbyState *selectionWrite asm("r5");
    register u16 *resetWords asm("r0");
    register u32 *resetFlagAddress asm("r0");
    register u8 *resetCountAddress asm("r0");
    register struct Node *nodesAddress asm("r1");
    register s32 recordType asm("r1");
    u8 limitedSelection;

    gUnknown_03001b10[1] = 0x1234;
    if (gUnknown_03005264 == 4) {
        gUnknown_0300525c = FUN_08021484();
    } else {
        count = FUN_0801f9e8(0x1357);
        if (gUnknown_030016f0.command != 0x2345) {
            gUnknown_0300525c = count;
        }
    }

    selectionValue = (u32)&gUnknown_0300525c;
    limitedSelection = *(u8 *)selectionValue;
    validationAddress = (u8 *)selectionValue;
    if (limitedSelection == 0xff || limitedSelection == 0) {
        gUnknown_030017c4 = 0;
        *validationAddress = 1;
    }
    selectionAddress = validationAddress;
    limitedSelection = *selectionAddress;
    selectionValue = limitedSelection;
    selectionRead = allocation;
    if (selectionValue != *(u8 *)selectionRead) {
        if (selectionValue > 4) {
            limitedSelection = 4;
        }
        *selectionAddress = limitedSelection;
        selectionValue = *selectionAddress;
        selectionWrite = allocation;
        selectionWrite->phase = selectionValue;
        if (gUnknown_03005264 == 4) {
            if (*selectionAddress <= 1) {
                FUN_080283f8(0);
            } else {
                FUN_080283f8(*selectionAddress + 4);
            }
        } else {
            FUN_080283f8(*validationAddress);
        }
    }

    keys = gUnknown_030048e0.repeated;
    selectionValue = 1;
    asm volatile("" : "+r"(selectionValue));
    one = selectionValue;
    secondOne = 1;
    asm volatile("" : "+r"(secondOne));

    oneAgain = secondOne;
    keyMask = oneAgain;

    keyMask &= keys;
    if (keyMask != 0) {
        if (gUnknown_03005264 == 4) {
            if (gUnknown_0300525c <= 1) {
                goto update_child;
            }
            current->callback = (const void *)FUN_08028bec;
            FUN_0801f618(404);
            FUN_0801f718(2, 60);
            goto update_child;
        }

        FUN_080291a8();
        keyMask = gUnknown_030017c4;
        if (keyMask != 0) {
            keyMask = gUnknown_03001380;
            if (keyMask != 0) {
                goto update_child;
            }
            countAddress = &gUnknown_0300525c;
            if (*countAddress == 1) {
                resetWords = gUnknown_03001b10;
                zero = 0;
                resetWords[0] = keyMask;
                resetWords[1] = keyMask;
                FUN_080184c8();
                FUN_08018c3c();
                gUnknown_03005260 = zero;
                validationAddress = (u8 *)one;
                *countAddress = (u32)validationAddress;
            } else {
                gUnknown_03005260 = keyMask;
                resetFlagAddress = &gUnknown_03005254;
                zero = oneAgain;
                asm volatile("" : "+r"(zero));

                *resetFlagAddress = zero;
                gUnknown_03005258 = keyMask;
                current->callback = (const void *)FUN_08028c80;
                FUN_0801f618(402);
                goto update_child;
            }
        } else {
            if (gUnknown_03005264 == 4) {
                goto update_child;
            }
            resetWords = gUnknown_03001b10;
            zero = 0;
            resetWords[0] = keyMask;
            resetWords[1] = keyMask;
            FUN_080184c8();
            FUN_08018c3c();
            gUnknown_03005260 = zero;
            resetCountAddress = &gUnknown_0300525c;
            register u32 resetCount asm("r1") = one;
            asm volatile("" : "+r"(resetCount));
            *resetCountAddress = resetCount;
        }
        gUnknown_03005254 = keyMask;
        current->callback = (const void *)FUN_08028bec;
        FUN_0801f618(404);
    } else {
        secondMask = 2;

        secondMask &= keys;
        if (secondMask == 0) {
            goto update_child;
        }
        resetWords = gUnknown_03001b10;
        zero = 0;
        resetWords[0] = keyMask;
        resetWords[1] = keyMask;
        FUN_080184c8();
        FUN_08018c3c();
        gUnknown_03005260 = zero;
        resetCountAddress = &gUnknown_0300525c;
        secondOne = one;
        *resetCountAddress = secondOne;
        gUnknown_03005254 = keyMask;
        current->callback = (const void *)FUN_08028ed8;
        FUN_0801f618(405);
        FUN_0801f718(2, 120);
        goto done;
    }

update_child:
    if (gUnknown_03005264 == 4) {
        if (gUnknown_0300525c <= 1) {
            nodesAddress = gUnknown_03003e20;
            validationAddress = (u8 *)allocation;
            selectionValue = ((struct LobbyState *)validationAddress)->child * 16;

            nodesAddress = (struct Node *)((u8 *)nodesAddress + 8);

            selectionValue += (u32)nodesAddress;

            (*(struct Position **)selectionValue)->graphics = gUnknown_08edb974;
            selectionValue = (u32)gUnknown_08edb974;
        } else {
            nodesAddress = gUnknown_03003e20;
            selectionRead = allocation;
            selectionValue = selectionRead->child * 16;

            nodesAddress = (struct Node *)((u8 *)nodesAddress + 8);

            selectionValue += (u32)nodesAddress;

            (*(struct Position **)selectionValue)->graphics = gUnknown_08edb94c;
            selectionValue = (u32)gUnknown_08edb94c;
        }
    } else if (gUnknown_030017c4 != 0 && gUnknown_03001380 != 0) {
        nodesAddress = gUnknown_03003e20;
        selectionWrite = allocation;
        selectionValue = selectionWrite->child * 16;

        nodesAddress = (struct Node *)((u8 *)nodesAddress + 8);

        selectionValue += (u32)nodesAddress;

        (*(struct Position **)selectionValue)->graphics = gUnknown_08edb974;
        selectionValue = (u32)gUnknown_08edb974;
    } else {
        nodesAddress = gUnknown_03003e20;
        validationAddress = (u8 *)allocation;
        selectionValue = ((struct LobbyState *)validationAddress)->child * 16;

        nodesAddress = (struct Node *)((u8 *)nodesAddress + 8);

        selectionValue += (u32)nodesAddress;

        (*(struct Position **)selectionValue)->graphics = gUnknown_08edb94c;
        selectionValue = (u32)gUnknown_08edb94c;
    }

    ready = gUnknown_03001380;
    if (ready != 0) {
        validationAddress = (u8 *)&gUnknown_030016f0;
        zero = 2;

        recordType = *(s16 *)(validationAddress + zero);
        asm volatile("" : : "r"(selectionValue));
        if (recordType == 0x2345) {
            gUnknown_03005260 = ready;
            gUnknown_03005254 = 1;
            FUN_0802f428(validationAddress + 4);
            gUnknown_03005258 = 0;
            current->callback = (const void *)FUN_08028c80;
            FUN_0801f618(402);
        }
    }
    if (gUnknown_03005264 == 4) {
        FUN_08021534();
    }
done:;
}

void FUN_08028bec(void) {
    u8 value;
    if (gUnknown_03005264 == 4)
        FUN_08021534();
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        if (gUnknown_03005264 == 4) {
            gUnknown_03002030 = FUN_0803281c;
        } else {
            gUnknown_03002030 = FUN_08029250;
            value = gUnknown_03002600[4];
            if (value != 0) {
                u8 *values = gUnknown_03005268;
                values[0] = 0;
                u8 selected = 2;
                values[1] = selected;
                values[2] = 0;
                values[3] = selected;
            } else {
                u8 *values = gUnknown_03005268;
                values[0] = value;
                values[1] = value;
                values[2] = value;
                values[3] = value;
            }
            gUnknown_0300524c[0] = 0;
            gUnknown_0300524c[1] = 1;
            gUnknown_0300524c[2] = 2;
            gUnknown_0300524c[3] = 3;
        }
    }
}

void FUN_08028c80(Node *owner) {
    s32 command;
    u16 *commandState;
    u32 complete, count, i, loopCount;
    u8 *records;
    s32 expected;
    s16 *recordValue;
    commandState = gUnknown_03001b10;
    command = 0x2345;
    commandState[1] = command;
    FUN_0802f328(&commandState[2]);
    FUN_0801fab0(0x1357);
    if (gUnknown_03005260 == 0) {
        complete = 1;
        i = 1;
        count = gUnknown_0300525c;
        if (complete < count) {
            records = (u8 *)&gUnknown_030016f0;
            expected = command;
            loopCount = count;
            recordValue = (s16 *)(records + 18);
            do {
                if (*recordValue != expected)
                    complete = 0;
                recordValue = (s16 *)((u8 *)recordValue + 16);
                i++;
            } while (i < loopCount);
        }
        if (complete != 0) {
            gUnknown_03005258 = 0;
            owner->callback = (const void *)FUN_08028d30;
        }
    } else if (gUnknown_030016f0.command == command + 1) {
        gUnknown_03005258 = 0;
        owner->callback = (const void *)FUN_08028d30;
    }
    gUnknown_03005258++;
    if (gUnknown_03005258 > 299)
        owner->callback = (const void *)FUN_08028f1c;
}

void FUN_08028d30(Node *node) {
    Node *owner = node;
    u16 *command = gUnknown_03001b10;
    u32 zero = 0;
    u32 commandCode = 0x2346;
    command[1] = commandCode;
    command[2] = zero;
    const u8 *state = gUnknown_03002110;
    command[3] = *(const u16 *)(state + 96);
    command[4] = *(const u16 *)(state + 98);
    command[5] = *(const u16 *)(state + 100);
    command[6] = *(const u16 *)(state + 102);
    command[7] = *(const u16 *)(state + 104);
    FUN_0801fab0(0x1357);
    u32 failed = 0;
    u32 i = 0;
    if (failed < gUnknown_0300525c) {
        u32 expected = commandCode;
        u16 *destinationBase = gUnknown_03005200[0];
        u8 *localIndex = &gUnknown_03005260;
        const u8 *records = ((const u8 *)&gUnknown_030016f0);
        const u8 *count = &gUnknown_0300525c;
        u16 *destination = destinationBase;
        u32 sentinel = 0xfffe;
        do {
            if (i != *localIndex) {
                u32 offset = i * 16;
                const u8 *sourceAddress = records + 2;
                u32 readAddress = offset + (u32)sourceAddress;
                if (*(const s16 *)readAddress == expected) {
                    sourceAddress = records + 6;
                    u8 *destinationAddress;
                    u8 *columnAddress;
                    readAddress = offset + (u32)sourceAddress;
                    destination[0] = *(const u16 *)readAddress;
                    destinationAddress = (u8 *)destinationBase + 2;
                    columnAddress = destinationAddress;
                    destinationAddress = (u8 *)(offset + (u32)columnAddress);
                    sourceAddress = records + 8;
                    readAddress = offset + (u32)sourceAddress;
                    *(u16 *)destinationAddress = *(const u16 *)readAddress;
                    destinationAddress = (u8 *)destinationBase + 4;
                    columnAddress = destinationAddress;
                    destinationAddress = (u8 *)(offset + (u32)columnAddress);
                    sourceAddress = records + 10;
                    readAddress = offset + (u32)sourceAddress;
                    *(u16 *)destinationAddress = *(const u16 *)readAddress;
                    destinationAddress = (u8 *)destinationBase + 6;
                    columnAddress = destinationAddress;
                    destinationAddress = (u8 *)(offset + (u32)columnAddress);
                    sourceAddress = records + 12;
                    readAddress = offset + (u32)sourceAddress;
                    *(u16 *)destinationAddress = *(const u16 *)readAddress;
                    destinationAddress = (u8 *)destinationBase + 8;
                    columnAddress = destinationAddress;
                    destinationAddress = (u8 *)(offset + (u32)columnAddress);
                    sourceAddress = records + 14;
                    readAddress = offset + (u32)sourceAddress;
                    *(u16 *)destinationAddress = *(const u16 *)readAddress;
                    destination[5] = sentinel;
                } else
                    failed = 1;
            }
            destination += 8;
            i++;
        } while (i < *count);
    }
    const void *next;
    if (failed != 0) {
        gUnknown_03005258++;
        if (gUnknown_03005258 > 299)
            next = (const void *)FUN_08028f1c;
        else
            return;
    } else {
        u16 *destinationBase = gUnknown_03005200[0];
        u8 *localIndex = &gUnknown_03005260;
        const u8 *source;
        *(u16 *)((u8 *)destinationBase + *localIndex * 16) =
            *(const u16 *)((source = gUnknown_03002110) + 96);
        {
            u32 offset = *localIndex * 16;
            u8 *column = (u8 *)destinationBase;
            column += 2;
            u16 *destination = (u16 *)(offset + (u32)column);
            *destination = *(const u16 *)(source + 98);
        }
        {
            u32 offset = *localIndex * 16;
            u8 *column = (u8 *)destinationBase;
            column += 4;
            u16 *destination = (u16 *)(offset + (u32)column);
            *destination = *(const u16 *)(source + 100);
        }
        {
            u32 offset = *localIndex * 16;
            u8 *column = (u8 *)destinationBase;
            column += 6;
            u16 *destination = (u16 *)(offset + (u32)column);
            *destination = *(const u16 *)(source + 102);
        }
        {
            u32 offset = *localIndex * 16;
            u8 *column = (u8 *)destinationBase;
            column += 8;
            u16 *destination = (u16 *)(offset + (u32)column);
            *destination = *(const u16 *)(source + 104);
        }
        u32 offset = *localIndex * 16;
        destinationBase = (u16 *)((u8 *)destinationBase + 10);
        u16 *destination = (u16 *)(offset + (u32)destinationBase);
        u32 sentinel = 0xfffe;
        *destination = sentinel;
        next = (const void *)FUN_08028bec;
    }
    owner->callback = next;
}

void FUN_08028ed8(Node *node) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        if (gUnknown_03005264 == 4)
            gUnknown_03002030 = FUN_080315bc;
        else
            gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_08028f1c(Node *node) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_0803d1a0;
        FUN_0801fb60();
        FUN_0801fb94();
        FUN_0801ff30();
        FUN_0801f780();
        FUN_080210d8();
        FUN_0802110c();
    }
}

void FUN_08028f5c(void) {
    FUN_08021484();
    if ((gUnknown_030048e0.repeated & 1) != 0)
        FUN_080214c0(0);
    FUN_08021534();
}

void FUN_08028f80(Node *node) {
    FUN_08021268(0);
    node->callback = (const void *)FUN_08028f5c;
}

void FUN_08028f98(Node *node) {
    Position *position = node->position;
    position->graphics = gUnknown_08edb97c;
    s32 index;
    if (gUnknown_0300525c >= (index = position->index) + 1) {
        const u8 *table = (const u8 *)gUnknown_08edb98c;
        u32 offset = index * 8;
        const s16 *xAddress = (const s16 *)(table + 4);
        xAddress = (const s16 *)(offset + (u32)xAddress);
        s32 x = *xAddress;
        table += 6;
        const s16 *yAddress = (const s16 *)(offset + (u32)table);
        s32 y = *yAddress;
        if ((u8)FUN_0801f92c(node, x, y) != 0) {
            node->position->graphics = gUnknown_08edb984;
        }
    } else {
        const u8 *table = (const u8 *)gUnknown_08edb98c;
        u32 offset = index * 8;
        const s16 *xAddress = (const s16 *)(offset + (u32)table);
        s32 x = *xAddress;
        table += 2;
        const s16 *yAddress = (const s16 *)(offset + (u32)table);
        s32 y = *yAddress;
        FUN_0801f92c(node, x, y);
    }
    FUN_0801fed8(node->index, 0);
}

void FUN_08029014(Node *node) {
    Position *position = node->position;
    position->graphics = gUnknown_08edb97c;
    position->tile = 0;
    Position *selected = node->position;
    const u8 *table = (const u8 *)gUnknown_08edb98c;
    u32 offset = selected->index * 8;
    selected->x = *(const u16 *)(offset + (u32)table);
    Position *second = node->position;
    offset = second->index * 8;
    table += 2;
    second->y = *(const u16 *)(offset + (u32)table);
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = (const void *)FUN_08028f98;
}

void FUN_08029060(Node *node) {
    const u8 *table = gUnknown_0804df7c;
    s32 value = (s8)(*(const u16 *)(table + node->position->timer * 64) >> 8);
    node->position->attr0 = 1;
    Position *position = node->position;
    position->attr1 &= 0xc1;
    value += 256;
    node->position->attr1 |= FUN_0801fd18(value, 0) * 2;
    FUN_0801fed8(node->index, 0);
    node->position->timer += 4;
}

void FUN_080290b4(Node *node) {
    Position *position = node->position;
    position->graphics = gUnknown_08edb94c;
    position->tile = 0;
    node->position->x = 214;
    node->position->y = 145;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = (const void *)FUN_08029060;
}

void FUN_080290e8(u32 index, u32 variant, u32 unused) {
    u8 *destination = (u8 *)0x06016a00 + index * 640;
    u32 fill = 0;
    CpuFastSet(&fill, destination, 0x010000a0);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 10, 2, 0);
    if (variant <= 3) {
        u16 *entries = gUnknown_03005200[index];
        s32 origin = 30;
        u32 count = 0;
        for (; count <= 4 && entries[count] != 0xfffe; count++) {
            origin -= 6;
        }
        while (*entries != 0xfffe) {
            s32 width = (s16)FUN_08020fac(*entries);
            s32 x = (s16)((12 - width) / 2) + origin;
            FUN_08020978(x + 1, 1, *entries, 1);
            FUN_08020978(x, 0, *entries, 15);
            origin += 12;
            entries++;
        }
    }
}

void FUN_080291a8(void) {
    u8 *destination = gUnknown_03002600;
    const u8 *source = (const u8 *)&gUnknown_03002110;
    destination[0] = source[108];
    destination[1] = source[109];
    destination[2] = source[110];
    destination[3] = source[111];
    destination[4] = source[112];
    destination[5] = source[113];
    destination[6] = source[114];
    destination[7] = source[115];
    destination[8] = source[116];
}

void FUN_08029200(void) {
    SettingsView *destination = (SettingsView *)gUnknown_03002110;
    const u8 *source = gUnknown_03002600;
    destination->a = source[0];
    destination->b = source[1];
    destination->c = source[2];
    destination->d = source[3];
    destination->e = source[4];
    destination->f = source[5];
    destination->g = source[6];
    destination->h = source[7];
    destination->i = source[8];
}
}
