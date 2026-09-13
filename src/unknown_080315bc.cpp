// Inferred complete extra-menu TU: 0x080315BC..0x0803281C.
// C++ reconstruction fallback; no independent original-language evidence.
// Layout views and empty compiler constraints are not original declarations.
// All owned ROM sections and private BSS are independently verified.
// See docs/extra-menu-tu-cpp.md for boundaries, ownership, and verification.
#include "types.h"
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
struct MenuData {
    u8 prefix[16];
    u16 selected, state;
    u8 nodes[6];
};
struct MarkerData {
    const void *parts;
    u8 gap4[4];
    u16 tile;
    u8 gap10[10];
    s16 x, y;
};
extern "C" {
extern const u16 gUnknown_08132394[] __attribute__((section(".rodata.registers")));
extern const u16 gUnknown_081327d4[];
extern const u8 gUnknown_08132544[], gUnknown_08132a14[], gUnknown_08133118[], gUnknown_081334d8[];
extern u8 gUnknown_03002110[];
extern const u16 *const *gUnknown_030052fc;
extern const u16 *const gUnknown_08edc3bc[], *const gUnknown_08edc3e0[];
extern const u16 *const gUnknown_08edc404[], *const gUnknown_08edc428[];
extern const u16 *const gUnknown_08edc44c[], *const gUnknown_08edc470[];
extern const Position gUnknown_08edc2d4[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_0801f89c(void), FUN_0801fda0(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08021000(void *, const u16 *, u32, u32, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08032724(Node *), FUN_08032778(Node *), FUN_0801f9d8(Node *);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16), FUN_0803186c(void);
extern const u32 gUnknown_0807163c[];
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[], gUnknown_08edb93c[];
extern const void *const gUnknown_08edc384[], *const gUnknown_08edc3a0[];
void FUN_08032790(Node *), FUN_080281c8(Node *), FUN_08028200(Node *), FUN_08031e68(Node *);
void FUN_080211d8(u32);
u8 FUN_080211f0(void);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *);
void FUN_08020b74(u32, u32, const void *, u32, u32);
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_03005300;
extern const s16 gUnknown_08edc4a4[];
extern const void *const gUnknown_08edc494[];
extern const u8 gUnknown_08edb84c[];
void FUN_0803256c(void), FUN_08032594(void), FUN_080325f0(void);
void FUN_080327bc(Node *), FUN_080327ec(Node *), FUN_08027eb8(Node *), FUN_08027f38(Node *);
void FUN_0801f618(u16), FUN_0801f718(u16, u16), FUN_0801fed8(u8, u32);
u32 FUN_0801f9a8(Node *, s16);
s16 FUN_0801f914(s16, s16);
extern const u8 gUnknown_08f81d10[], gUnknown_08071b7c[], gUnknown_0807173c[];
extern u32 gUnknown_03002610;
extern const u16 gUnknown_08132774[], gUnknown_081329b4[];
void FUN_08039e20(void), FUN_080284b4(void), FUN_0803187c(Node *);
u8 FUN_0802067c(void *, u16), FUN_080206ec(void *, u16);
u8 FUN_08020500(void *, const u16 *, u16);
void LZ77UnCompWram(const void *, void *), SoftResetExram(u32);
void CpuFastSet(const void *, void *, u32);
void FUN_0801fba0(u16, u16), FUN_0801fed8(u8, u32);
u32 FUN_0801f92c(Node *, s16, s16), FUN_0801f9a8(Node *, s16);
void FUN_08021244(u8), FUN_0801f8c0(Node *);
void FUN_080315bc(void) {
    FUN_0801fbfc(gUnknown_08132394, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000000, 0x01000100);
    u32 zero1 = 0;
    CpuFastSet(&zero1, (void *)0x06000000, 0x01000008);
    u32 zero2 = 0;
    CpuFastSet(&zero2, (void *)0x06013e00, 0x01000080);
    u32 zero3 = 0;
    CpuFastSet(&zero3, (void *)0x06014000, 0x01000400);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x06000020);
    LZ77UnCompVram(gUnknown_08132a14, (void *)0x06010000);
    switch (gUnknown_03002110[119]) {
    case 0:
        LZ77UnCompVram(gUnknown_08133118, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc3bc;
        break;
    case 2:
        LZ77UnCompVram(gUnknown_081334d8, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc404;
        break;
    case 3:
        LZ77UnCompVram(gUnknown_081334d8, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc428;
        break;
    case 4:
        LZ77UnCompVram(gUnknown_081334d8, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc44c;
        break;
    case 5:
        LZ77UnCompVram(gUnknown_081334d8, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc470;
        break;
    default:
        LZ77UnCompVram(gUnknown_081334d8, (void *)0x06012420);
        gUnknown_030052fc = gUnknown_08edc3e0;
        break;
    }
    u32 zero4 = 0;
    CpuFastSet(&zero4, (void *)0x0600f800, 0x01000200);
    u32 zero5 = 0;
    CpuFastSet(&zero5, (void *)0x0600f000, 0x01000200);
    u32 zero6 = 0;
    CpuFastSet(&zero6, (void *)0x0600e800, 0x01000200);
    u8 *tiles = (u8 *)0x0600e000;
    u32 row = 0;
    do {
        u32 col = 0;
        u32 nextRow = row + 1;
        do {
            FUN_08021000(tiles, gUnknown_081327d4, 8, 8, 1);
            tiles += 16;
            col++;
        } while (col < 4);
        tiles += 448;
        row = nextRow;
    } while (row < 4);
    FUN_0801f7d0(FUN_08032724, 28, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08032778, 4, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edc2d4[0];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edc2d4[1];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edc2d4[9];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edc2d4[10];
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_0803186c;
    FUN_0801f618(1);
}
void FUN_0803186c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0803187c(Node *owner) {
    u32 zero;
    asm volatile("" : "=m"(zero));
    MenuData *initialMenu = (MenuData *)owner->allocation;
    register MenuData *menu asm("r10") = initialMenu;
    asm volatile("" : "+m"(owner));
    register u32 firstZero asm("r1") = 0;
    asm volatile("" : : "r"(firstZero));
    u32 initialZero = firstZero;
    register u32 storedZero asm("r2") = initialZero;
    initialMenu->selected = storedZero;
    initialMenu->state = storedZero;
    FUN_080211d8(6);
    {
        Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
        asm volatile("" : "+r"(sprite) : : "r4", "r5", "r6");
        u32 nodeIndex = sprite->index;
        register MenuData *nodeMenu asm("r3") = menu;
        nodeMenu->nodes[0] = nodeIndex;
        *sprite->position = gUnknown_08edc2d4[2];
        sprite->position->state = FUN_080211f0();
        register u32 tileValue asm("r0") = sprite->position->state * 64;
        register u32 tileBase asm("r4") = 640;
        asm volatile("" : : "r"(tileBase));
        sprite->position->tile = tileValue + tileBase;
        u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[0];
        if (enabled) {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[0];
            slot <<= 11;
            u32 base = 0x06015000;
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4,
                         initialZero);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        } else {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[6];
            slot <<= 11;
            register u32 base asm("r3") = 0x06015000;
            asm volatile("" : : "r"(base));
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, enabled);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        }
    }
    {
        Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
        asm volatile("" : "+r"(sprite) : : "r4", "r5", "r6");
        u32 nodeIndex = sprite->index;
        register MenuData *nodeMenu asm("r4") = menu;
        nodeMenu->nodes[1] = nodeIndex;
        *sprite->position = gUnknown_08edc2d4[3];
        sprite->position->state = FUN_080211f0();
        register u32 tileValue asm("r0") = sprite->position->state * 64;
        register u32 tileBase asm("r2") = 640;
        asm volatile("" : : "r"(tileBase));
        sprite->position->tile = tileValue + tileBase;
        u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[1];
        if (enabled) {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[1];
            slot <<= 11;
            register u32 base asm("r3") = 0x06015000;
            asm volatile("" : : "r"(base));
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, 0);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        } else {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[6];
            slot <<= 11;
            u32 base = 0x06015000;
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, enabled);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        }
    }
    {
        Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
        asm volatile("" : "+r"(sprite) : : "r4", "r5", "r6");
        register u32 nodeIndex asm("r0") = sprite->index;
        MenuData *nodeMenu = menu;
        nodeMenu->nodes[2] = nodeIndex;
        *sprite->position = gUnknown_08edc2d4[4];
        sprite->position->state = FUN_080211f0();
        register u32 tileValue asm("r0") = sprite->position->state * 64;
        register u32 tileBase asm("r2") = 640;
        asm volatile("" : : "r"(tileBase));
        sprite->position->tile = tileValue + tileBase;
        u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[2];
        if (enabled) {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[2];
            slot <<= 11;
            register u32 base asm("r3") = 0x06015000;
            asm volatile("" : : "r"(base));
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, 0);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        } else {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[6];
            slot <<= 11;
            u32 base = 0x06015000;
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, enabled);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        }
    }
    {
        Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
        asm volatile("" : "+r"(sprite) : : "r4", "r5", "r6");
        register u32 nodeIndex asm("r0") = sprite->index;
        MenuData *nodeMenu = menu;
        nodeMenu->nodes[3] = nodeIndex;
        *sprite->position = gUnknown_08edc2d4[5];
        sprite->position->state = FUN_080211f0();
        register u32 tileValue asm("r0") = sprite->position->state * 64;
        register u32 tileBase asm("r2") = 640;
        asm volatile("" : : "r"(tileBase));
        sprite->position->tile = tileValue + tileBase;
        u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[3];
        if (enabled) {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[3];
            slot <<= 11;
            register u32 base asm("r3") = 0x06015000;
            asm volatile("" : : "r"(base));
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, 0);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        } else {
            u32 slot = sprite->position->state;
            const u16 *text = gUnknown_030052fc[6];
            slot <<= 11;
            u32 base = 0x06015000;
            u8 *destination = (u8 *)(slot + base);
            const void *copySource = (const void *)0x06010420;
            register u8 *copyDestination asm("r1") = destination;
            CpuFastSet(copySource, copyDestination, 512);
            FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, enabled);
            register u32 half asm("r1") = FUN_08020ad0(text);
            asm volatile("" : "+r"(half));
            half >>= 1;
            u32 center = 64;
            register u32 x asm("r1") = center - half;
            FUN_08020b74(x, 2, text, 8, 9);
        }
    }
    Node *sprite = FUN_0801f7d0(FUN_080281c8, 28, gUnknown_03003e20, 0);
    register u32 markerIndex asm("r0") = sprite->index;
    register u32 markerZero asm("r1") = 0;
    MenuData *firstMarkerMenu = menu;
    firstMarkerMenu->nodes[4] = markerIndex;
    MarkerData *marker = (MarkerData *)sprite->allocation;
    register const void *parts asm("r3") = gUnknown_08edb93c;
    const void *savedParts = parts;
    asm volatile("" : : "r"(savedParts));
    marker->parts = parts;
    marker->tile = markerZero;
    marker->x = 168;
    marker->y = 16;
    sprite->position->attr2 = 240;
    sprite = FUN_0801f7d0(FUN_08028200, 28, gUnknown_03003e20, 0);
    markerIndex = sprite->index;
    MenuData *secondMarkerMenu = menu;
    secondMarkerMenu->nodes[5] = markerIndex;
    marker = (MarkerData *)sprite->allocation;
    parts = savedParts;
    marker->parts = parts;
    marker->tile = 16;
    marker->x = 168;
    marker->y = 144;
    sprite->position->attr2 = 240;
    u32 flags = gUnknown_03002110[120];
    const u32 *masks = gUnknown_0807163c;
    u32 selectedOffset = secondMarkerMenu->selected * 4;
    flags &= *(const u32 *)(selectedOffset + (u32)masks);
    if (flags) {
        u32 graphicsAddress = selectedOffset + (u32)gUnknown_08edc384;
        const void *graphics = *(const void **)graphicsAddress;
        LZ77UnCompVram(graphics, (void *)0x06014000);
        const void *const *paletteTable = gUnknown_08edc3a0;
        register MenuData *reloadMenu asm("r4") = menu;
        LZ77UnCompVram(paletteTable[reloadMenu->selected], (void *)0x05000200);
    } else {
        LZ77UnCompVram(gUnknown_08edc384[6], (void *)0x06014000);
        LZ77UnCompVram(gUnknown_08edc3a0[6], (void *)0x05000200);
    }
    u8 index = menu->selected;
    u8 *destination = (u8 *)0x06013e00;
    zero = 0;
    u32 *zeroSource = &zero;
    register u8 *zeroDestination asm("r1") = destination;
    asm volatile("" : : "r"(zeroSource), "r"(zeroDestination));
    CpuFastSet(zeroSource, zeroDestination, 0x01000080);
    if (gUnknown_03002110[120] & gUnknown_0807163c[index]) {
        const u16 *text;
        if (index == 2)
            text = gUnknown_030052fc[7];
        else
            text = gUnknown_030052fc[8];
        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 8, 2, 0);
        register u32 half asm("r1") = FUN_08020ad0(text);
        asm volatile("" : "+r"(half));
        half >>= 1;
        u32 center = 32;
        register u32 x asm("r1") = center - half;
        FUN_08020b74(x, 0, text, 8, 9);
    }
    register Node *positionOwner asm("r2") = owner;
    Position *finalPosition = positionOwner->position;
    const Position *finalTemplate = &gUnknown_08edc2d4[8];
    *finalPosition = *finalTemplate;
    void (*callback)(Node *) = FUN_08031e68;
    register Node *callbackOwner asm("r3") = owner;
    callbackOwner->callback = callback;
}
void FUN_08031e68(Node *owner) {
    MenuData *menu = (MenuData *)owner->allocation;
    u32 keys = gUnknown_030048e0[2];
    u32 zero;
    if (keys & 1) {
        if (gUnknown_03002110[120] & gUnknown_0807163c[menu->selected]) {
            switch (menu->selected) {
            case 2:
                owner->callback = (void (*)(Node *))FUN_08032594;
                break;
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
                gUnknown_03005300 = menu->selected;
                owner->callback = (void (*)(Node *))FUN_080325f0;
                break;
            }
            FUN_0801f618(404);
            FUN_0801f718(1, 60);
        } else
            FUN_0801f618(419);
    } else if (keys & 2) {
        owner->callback = (void (*)(Node *))FUN_0803256c;
        FUN_0801f618(405);
    } else if (keys & 64) {
        if (menu->selected != 0) {
            menu->selected--;
            if (gUnknown_03002110[120] & gUnknown_0807163c[menu->selected]) {
                LZ77UnCompVram(gUnknown_08edc384[menu->selected], (void *)0x06014000);
                LZ77UnCompVram(gUnknown_08edc3a0[menu->selected], (void *)0x05000200);
            } else {
                LZ77UnCompVram(gUnknown_08edc384[6], (void *)0x06014000);
                LZ77UnCompVram(gUnknown_08edc3a0[6], (void *)0x05000200);
            }
            u8 index = menu->selected;
            u8 *destination = (u8 *)0x06013e00;
            zero = 0;
            u32 *zeroSource = &zero;
            register u8 *zeroDestination asm("r1") = destination;
            asm volatile("" : : "r"(zeroSource), "r"(zeroDestination));
            CpuFastSet(zeroSource, zeroDestination, 0x01000080);
            if (gUnknown_03002110[120] & gUnknown_0807163c[index]) {
                const u16 *text;
                if (index == 2)
                    text = gUnknown_030052fc[7];
                else
                    text = gUnknown_030052fc[8];
                FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 8, 2, 0);
                register u32 half asm("r1") = FUN_08020ad0(text);
                asm volatile("" : "+r"(half));
                half >>= 1;
                u32 center = 32;
                register u32 x asm("r1") = center - half;
                FUN_08020b74(x, 0, text, 8, 9);
            }
            FUN_0801f618(401);
        }
        if (menu->selected < menu->state + 1 && menu->state != 0) {
            menu->state--;
            gUnknown_03003e20[menu->nodes[3]].callback = FUN_080327ec;
            gUnknown_03003e20[menu->nodes[2]].position->player = 3;
            menu->nodes[3] = menu->nodes[2];
            gUnknown_03003e20[menu->nodes[1]].position->player = 2;
            menu->nodes[2] = menu->nodes[1];
            gUnknown_03003e20[menu->nodes[0]].position->player = 1;
            menu->nodes[1] = menu->nodes[0];
            Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
            menu->nodes[0] = sprite->index;
            *sprite->position = gUnknown_08edc2d4[6];
            sprite->position->state = FUN_080211f0();
            sprite->position->tile = sprite->position->state * 64 + 640;
            u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[menu->state];
            if (enabled) {
                u32 slot = sprite->position->state;
                const u16 *text = gUnknown_030052fc[(u8)menu->state];
                u8 *destination = (u8 *)(slot * 2048 + 0x06015000);
                const void *copySource = (const void *)0x06010420;
                register u8 *copyDestination asm("r1") = destination;
                CpuFastSet(copySource, copyDestination, 512);
                FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, 0);
                register u32 half asm("r1") = FUN_08020ad0(text);
                asm volatile("" : "+r"(half));
                half >>= 1;
                u32 center = 64;
                register u32 x asm("r1") = center - half;
                FUN_08020b74(x, 2, text, 8, 9);
            } else {
                u32 slot = sprite->position->state;
                const u16 *text = gUnknown_030052fc[6];
                u8 *destination = (u8 *)(slot * 2048 + 0x06015000);
                const void *copySource = (const void *)0x06010420;
                register u8 *copyDestination asm("r1") = destination;
                CpuFastSet(copySource, copyDestination, 512);
                FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4,
                             enabled);
                register u32 half asm("r1") = FUN_08020ad0(text);
                asm volatile("" : "+r"(half));
                half >>= 1;
                u32 center = 64;
                register u32 x asm("r1") = center - half;
                FUN_08020b74(x, 2, text, 8, 9);
            }
        }
        gUnknown_03003e20[menu->nodes[4]].callback = FUN_08027eb8;
        gUnknown_03003e20[menu->nodes[4]].position->state = 0;
    } else {
        register u32 downPressed asm("r0") = keys & 128;
        if (downPressed) {
            menu->selected++;
            if (menu->selected > 4)
                menu->selected = 4;
            else {
                if (gUnknown_03002110[120] & gUnknown_0807163c[menu->selected]) {
                    LZ77UnCompVram(gUnknown_08edc384[menu->selected], (void *)0x06014000);
                    LZ77UnCompVram(gUnknown_08edc3a0[menu->selected], (void *)0x05000200);
                } else {
                    LZ77UnCompVram(gUnknown_08edc384[6], (void *)0x06014000);
                    LZ77UnCompVram(gUnknown_08edc3a0[6], (void *)0x05000200);
                }
                u8 index = menu->selected;
                u8 *destination = (u8 *)0x06013e00;
                zero = 0;
                u32 *zeroSource = &zero;
                register u8 *zeroDestination asm("r1") = destination;
                asm volatile("" : : "r"(zeroSource), "r"(zeroDestination));
                CpuFastSet(zeroSource, zeroDestination, 0x01000080);
                if (gUnknown_03002110[120] & gUnknown_0807163c[index]) {
                    const u16 *text;
                    if (index == 2)
                        text = gUnknown_030052fc[7];
                    else
                        text = gUnknown_030052fc[8];
                    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 8, 2, 0);
                    register u32 half asm("r1") = FUN_08020ad0(text);
                    asm volatile("" : "+r"(half));
                    half >>= 1;
                    u32 center = 32;
                    register u32 x asm("r1") = center - half;
                    FUN_08020b74(x, 0, text, 8, 9);
                }
                FUN_0801f618(401);
            }
            s32 selected = menu->selected;
            s32 previous = menu->state;
            s32 next = previous + 1;
            if (selected > next) {
                u32 priorState;
                asm volatile("" : "=l"(priorState) : "0"(previous));
                if (priorState == 0) {
                    menu->state = next;
                    gUnknown_03003e20[menu->nodes[0]].callback = FUN_080327bc;
                    gUnknown_03003e20[menu->nodes[1]].position->player = 0;
                    menu->nodes[0] = menu->nodes[1];
                    gUnknown_03003e20[menu->nodes[2]].position->player = 1;
                    menu->nodes[1] = menu->nodes[2];
                    gUnknown_03003e20[menu->nodes[3]].position->player = 2;
                    menu->nodes[2] = menu->nodes[3];
                    Node *sprite = FUN_0801f7d0(FUN_08032790, 16, gUnknown_03003e20, 0);
                    menu->nodes[3] = sprite->index;
                    *sprite->position = gUnknown_08edc2d4[7];
                    sprite->position->state = FUN_080211f0();
                    sprite->position->tile = sprite->position->state * 64 + 640;
                    u32 enabled = gUnknown_03002110[120] & gUnknown_0807163c[menu->state + 3];
                    if (enabled) {
                        u32 slot = sprite->position->state;
                        const u16 *text = gUnknown_030052fc[(u8)(menu->state + 3)];
                        u8 *destination = (u8 *)(slot * 2048 + 0x06015000);
                        const void *copySource = (const void *)0x06010420;
                        register u8 *copyDestination asm("r1") = destination;
                        CpuFastSet(copySource, copyDestination, 512);
                        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4,
                                     priorState);
                        register u32 half asm("r1") = FUN_08020ad0(text);
                        asm volatile("" : "+r"(half));
                        half >>= 1;
                        u32 center = 64;
                        register u32 x asm("r1") = center - half;
                        FUN_08020b74(x, 2, text, 8, 9);
                    } else {
                        u32 slot = sprite->position->state;
                        const u16 *text = gUnknown_030052fc[6];
                        u8 *destination = (u8 *)(slot * 2048 + 0x06015000);
                        const void *copySource = (const void *)0x06010420;
                        register u8 *copyDestination asm("r1") = destination;
                        CpuFastSet(copySource, copyDestination, 512);
                        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4,
                                     enabled);
                        register u32 half asm("r1") = FUN_08020ad0(text);
                        asm volatile("" : "+r"(half));
                        half >>= 1;
                        u32 center = 64;
                        register u32 x asm("r1") = center - half;
                        FUN_08020b74(x, 2, text, 8, 9);
                    }
                }
            }
            gUnknown_03003e20[menu->nodes[5]].callback = FUN_08027f38;
            gUnknown_03003e20[menu->nodes[5]].position->state = 0;
        }
    }
    FUN_0801f9a8(owner, gUnknown_08edc4a4[menu->selected - menu->state] + 12);
    Node *displayOwner = owner;
    Position *animationPosition = displayOwner->position;
    const void *const *animationParts = gUnknown_08edc494;
    animationPosition->parts =
        animationParts[gUnknown_08edb84c[(animationPosition->state & 28) >> 2]];
    FUN_0801fed8(displayOwner->index, 0);
    Position *incrementPosition = displayOwner->position;
    incrementPosition->state++;
    MarkerData *marker;
    if (menu->selected != 0) {
        marker = (MarkerData *)gUnknown_03003e20[menu->nodes[4]].allocation;
        s32 currentY = marker->y;
        marker->y = FUN_0801f914(16, currentY);
    } else {
        marker = (MarkerData *)gUnknown_03003e20[menu->nodes[4]].allocation;
        marker->y = FUN_0801f914(-16, marker->y);
    }
    if (menu->selected <= 3) {
        marker = (MarkerData *)gUnknown_03003e20[menu->nodes[5]].allocation;
        marker->y = FUN_0801f914(144, marker->y);
    } else {
        marker = (MarkerData *)gUnknown_03003e20[menu->nodes[5]].allocation;
        marker->y = FUN_0801f914(176, marker->y);
    }
}
void FUN_0803256c(void) {
    if (FUN_0802067c((void *)0x05000000, 512))
        gUnknown_03002030 = FUN_08039e20;
}
void FUN_08032594(void) {
    if (FUN_080206ec((void *)0x05000000, 512)) {
        LZ77UnCompWram(gUnknown_08f81d10, (void *)0x02000000);
        u32 *parameters = (u32 *)0x020000c8;
        *parameters = gUnknown_03002110[119];
        asm volatile("" : : "r"(parameters));
        parameters++;
        *parameters = 1;
        asm volatile("" : : "r"(parameters));
        parameters++;
        *parameters = gUnknown_03002610;
        parameters += 4;
        asm volatile("" : "+r"(parameters));
        *parameters = 0x12345678;
        SoftResetExram(0);
    }
}
void FUN_080325f0(void) {
    if (FUN_0802067c((void *)0x05000000, 512))
        gUnknown_03002030 = FUN_080284b4;
}
void FUN_08032618(u32 row, u32 index) {
    u32 shifted = row;
    shifted <<= 24;
    u32 indexShifted = index << 24;
    const u16 *const *table = gUnknown_030052fc;
    u32 textAddress = (indexShifted >> 22) + (u32)table;
    const u16 *text = *(const u16 **)textAddress;
    const void *source = (void *)0x06010420;
    u32 offset = shifted >> 13;
    u32 base = 0x06015000;
    u8 *destination = (u8 *)(offset + base);
    CpuFastSet(source, destination, 512);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 16, 4, 0);
    register u32 half asm("r1") = FUN_08020ad0(text);
    asm volatile("" : "+r"(half));
    half >>= 1;
    u32 center = 64;
    register u32 x asm("r1") = center - half;
    FUN_08020b74(x, 2, text, 8, 9);
}
void FUN_0803268c(u8 index) {
    u8 *destination = (u8 *)0x06013e00;
    u32 zero = 0;
    CpuFastSet(&zero, destination, 0x01000080);
    if (gUnknown_03002110[120] & gUnknown_0807163c[index]) {
        const u16 *text;
        if (index == 2)
            text = gUnknown_030052fc[7];
        else
            text = gUnknown_030052fc[8];
        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 8, 2, 0);
        register u32 half asm("r1") = FUN_08020ad0(text);
        asm volatile("" : "+r"(half));
        half >>= 1;
        u32 center = 32;
        register u32 x asm("r1") = center - half;
        FUN_08020b74(x, 0, text, 8, 9);
    }
}
void FUN_08032724(Node *node) {
    u32 first = !FUN_08020500((void *)0x05000000, gUnknown_08132774, 16);
    u32 pending = first;
    asm volatile("" : "+r"(pending));
    u32 result;
    if (!FUN_08020500((void *)0x050003a0, gUnknown_081329b4, 48)) {
        result = 1;
        asm volatile("" : : "r"(result));
    } else {
        result = (u8)pending;
        asm volatile("" : : "r"(result));
        if (!result)
            node->callback = FUN_0803187c;
    }
}
void FUN_08032778(Node *node) {
    u32 *counter = (u32 *)node->allocation;
    FUN_0801fba0(30, *(u8 *)counter);
    *counter -= 1;
}
void FUN_08032790(Node *node) {
    FUN_0801f92c(node, 104, gUnknown_08edc4a4[node->position->player]);
    FUN_0801fed8(node->index, 0);
}
void FUN_080327bc(Node *node) {
    if ((u8)FUN_0801f9a8(node, -16)) {
        FUN_08021244(node->position->state);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->index, 0);
    }
}
void FUN_080327ec(Node *node) {
    if ((u8)FUN_0801f9a8(node, 160)) {
        FUN_08021244(node->position->state);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->index, 0);
    }
}
extern const u8 gUnknown_08137e6c[];
extern const u8 gUnknown_08137e7c[];
extern const u8 gUnknown_08137edc[];
extern const u8 gUnknown_08137f5c[];
extern const u8 gUnknown_08137e64[];
extern const u8 gUnknown_08137e9c[];
extern const u8 gUnknown_081338c8[];
extern const u8 gUnknown_08134148[];
extern const u8 gUnknown_08134c60[];
extern const u8 gUnknown_081359d4[];
extern const u8 gUnknown_08136304[];
extern const u8 gUnknown_08136e08[];
extern const u8 gUnknown_08137004[];
extern const u8 gUnknown_0813731c[];
extern const u8 gUnknown_0813742c[];
extern const u8 gUnknown_0813753c[];
extern const u8 gUnknown_08137650[];
extern const u8 gUnknown_08137764[];
extern const u8 gUnknown_08137870[];
extern const u8 gUnknown_08137968[];
extern const u16 gUnknown_08137a0c[];
extern const u16 gUnknown_08137a20[];
extern const u16 gUnknown_08137a34[];
extern const u16 gUnknown_08137a44[];
extern const u16 gUnknown_08137a58[];
extern const u16 gUnknown_08137a70[];
extern const u16 gUnknown_08137a84[];
extern const u16 gUnknown_08137a98[];
extern const u16 gUnknown_08137aa4[];
extern const u16 gUnknown_08137ab0[];
extern const u16 gUnknown_08137ac8[];
extern const u16 gUnknown_08137adc[];
extern const u16 gUnknown_08137af0[];
extern const u16 gUnknown_08137b08[];
extern const u16 gUnknown_08137b28[];
extern const u16 gUnknown_08137b3c[];
extern const u16 gUnknown_08137b50[];
extern const u16 gUnknown_08137b60[];
extern const u16 gUnknown_08137b6c[];
extern const u16 gUnknown_08137b84[];
extern const u16 gUnknown_08137b98[];
extern const u16 gUnknown_08137bac[];
extern const u16 gUnknown_08137bc4[];
extern const u16 gUnknown_08137be4[];
extern const u16 gUnknown_08137bf8[];
extern const u16 gUnknown_08137c0c[];
extern const u16 gUnknown_08137c20[];
extern const u16 gUnknown_08137c2c[];
extern const u16 gUnknown_08137c44[];
extern const u16 gUnknown_08137c58[];
extern const u16 gUnknown_08137c6c[];
extern const u16 gUnknown_08137c84[];
extern const u16 gUnknown_08137ca4[];
extern const u16 gUnknown_08137cb8[];
extern const u16 gUnknown_08137ccc[];
extern const u16 gUnknown_08137cdc[];
extern const u16 gUnknown_08137ce8[];
extern const u16 gUnknown_08137d00[];
extern const u16 gUnknown_08137d14[];
extern const u16 gUnknown_08137d28[];
extern const u16 gUnknown_08137d40[];
extern const u16 gUnknown_08137d60[];
extern const u16 gUnknown_08137d74[];
extern const u16 gUnknown_08137d88[];
extern const u16 gUnknown_08137d9c[];
extern const u16 gUnknown_08137da8[];
extern const u16 gUnknown_08137dc0[];
extern const u16 gUnknown_08137dd4[];
extern const u16 gUnknown_08137de8[];
extern const u16 gUnknown_08137e00[];
extern const u16 gUnknown_08137e20[];
extern const u16 gUnknown_08137e34[];
extern const u16 gUnknown_08137e48[];
extern const u16 gUnknown_08137e58[];
extern const u8 gUnknown_08137f7c[];
extern const u8 gUnknown_08137f9c[];
extern const u8 gUnknown_08137fbc[];
const Position gUnknown_08edc2d4[] = {{gUnknown_08137e6c, 0, 4, 289, 0, 0, 4, 0, 0, 0},
                                      {gUnknown_08137e7c, 8, 38, 97, 0, 0, 4, 0, 0, 0},
                                      {gUnknown_08137edc, 200, -16, 640, 0, 0, 4, 0, 0, 0},
                                      {gUnknown_08137edc, 256, 20, 640, 0, 0, 4, 1, 0, 0},
                                      {gUnknown_08137edc, 256, 110, 640, 0, 0, 4, 2, 0, 0},
                                      {gUnknown_08137edc, 200, 176, 640, 0, 0, 4, 3, 0, 0},
                                      {gUnknown_08137edc, 104, -16, 640, 0, 0, 4, 0, 0, 0},
                                      {gUnknown_08137edc, 104, 176, 640, 0, 0, 4, 3, 0, 0},
                                      {gUnknown_08137f5c, 168, 44, 32, 0, 0, 0, 3, 0, 0},
                                      {gUnknown_08137e64, 21, 49, 512, 32, 0, 0, 0, 0, 0},
                                      {gUnknown_08137e9c, 22, 134, 496, 0, 0, 0, 0, 0, 0}};
const void *const gUnknown_08edc384[] = {gUnknown_081338c8, gUnknown_08134148, gUnknown_08134c60,
                                         gUnknown_081359d4, gUnknown_08136304, gUnknown_08136e08,
                                         gUnknown_08137004};
const void *const gUnknown_08edc3a0[] = {gUnknown_0813731c, gUnknown_0813742c, gUnknown_0813753c,
                                         gUnknown_08137650, gUnknown_08137764, gUnknown_08137870,
                                         gUnknown_08137968};
const u16 *const gUnknown_08edc3bc[] = {gUnknown_08137a0c, gUnknown_08137a20, gUnknown_08137a34,
                                        gUnknown_08137a44, gUnknown_08137a58, gUnknown_08137a70,
                                        gUnknown_08137a84, gUnknown_08137a98, gUnknown_08137aa4};
const u16 *const gUnknown_08edc3e0[] = {gUnknown_08137ab0, gUnknown_08137ac8, gUnknown_08137adc,
                                        gUnknown_08137af0, gUnknown_08137b08, gUnknown_08137b28,
                                        gUnknown_08137b3c, gUnknown_08137b50, gUnknown_08137b60};
const u16 *const gUnknown_08edc404[] = {gUnknown_08137b6c, gUnknown_08137b84, gUnknown_08137b98,
                                        gUnknown_08137bac, gUnknown_08137bc4, gUnknown_08137be4,
                                        gUnknown_08137bf8, gUnknown_08137c0c, gUnknown_08137c20};
const u16 *const gUnknown_08edc428[] = {gUnknown_08137c2c, gUnknown_08137c44, gUnknown_08137c58,
                                        gUnknown_08137c6c, gUnknown_08137c84, gUnknown_08137ca4,
                                        gUnknown_08137cb8, gUnknown_08137ccc, gUnknown_08137cdc};
const u16 *const gUnknown_08edc44c[] = {gUnknown_08137ce8, gUnknown_08137d00, gUnknown_08137d14,
                                        gUnknown_08137d28, gUnknown_08137d40, gUnknown_08137d60,
                                        gUnknown_08137d74, gUnknown_08137d88, gUnknown_08137d9c};
const u16 *const gUnknown_08edc470[] = {gUnknown_08137da8, gUnknown_08137dc0, gUnknown_08137dd4,
                                        gUnknown_08137de8, gUnknown_08137e00, gUnknown_08137e20,
                                        gUnknown_08137e34, gUnknown_08137e48, gUnknown_08137e58};
const void *const gUnknown_08edc494[] = {gUnknown_08137f5c, gUnknown_08137f7c, gUnknown_08137f9c,
                                         gUnknown_08137fbc};
const s16 gUnknown_08edc4a4[] = {29, 55, 81, 107};
const u16 gUnknown_08132394[] __attribute__((section(".rodata.registers"))) = {
    0,  0x0, 8,  0x1f00, 16, 0x0,    18, 0x0, 10, 0x1e00, 20, 0x0, 22, 0x0, 12, 0x1d02,
    24, 0x0, 26, 0x0,    14, 0x1c03, 28, 0x0, 30, 0x0,    80, 0x0, 82, 0x0, 84, 0x0,
};
const u16 *const *gUnknown_030052fc __attribute__((section(".bss"))) = 0;
}
