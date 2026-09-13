// Inferred complete transfer-scene TU: 0x0803281C..0x080336DC.
// C++ fallback: independent original-language evidence is unavailable.
// Address labels and layout views are reconstruction artifacts, not original names.
// See docs/transfer-scene-tu-cpp.md for ownership and verification evidence.
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
extern "C" {
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_08edc544[], gUnknown_08edc590[];
extern const s16 gUnknown_08edc5a0[], gUnknown_08edc5c8[];
extern const Position gUnknown_08edc550[], gUnknown_08edc570[];
extern const Position gUnknown_08edc5e8[], gUnknown_08edc5f8[], gUnknown_08edc608[];
extern const Position gUnknown_08edc618[], gUnknown_08edc628[];
u8 FUN_0802067c(void *, u16);
void FUN_0803d1a0(void), FUN_0801fba0(u16, u16);
void FUN_0801fed8(u8, u32), FUN_0801f8c0(Node *), FUN_0801f9d8(Node *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
u32 FUN_08020144(void);
void FUN_08033104(Node *), FUN_080333dc(Node *), FUN_0803329c(Node *);
void FUN_08033320(Node *), FUN_08033390(Node *), FUN_08033404(Node *);
void FUN_080334ec(Node *), FUN_080335dc(Node *), FUN_0803362c(Node *), FUN_0803367c(Node *);
extern u8 gUnknown_0300525c, gUnknown_03005300;
extern u32 gUnknown_03004d8c, gUnknown_0300530c, gUnknown_03005258;
extern u16 gUnknown_03001b10[];
u8 FUN_08021534(void), FUN_08021484(void), FUN_080206ec(void *, u16);
void FUN_0804962c(void), FUN_080496ac(void), FUN_080214c0(u8), FUN_0804af6c(Node *);
void FUN_08021564(void), FUN_0804a5b8(u32, void *), FUN_0804a5c8(u32), FUN_0804af78(void);
void FUN_08032f10(Node *), FUN_08032f34(Node *), FUN_08032f9c(Node *);
void FUN_08033038(void), FUN_08032be0(Node *), FUN_08033474(Node *);
struct ControlData {
    s32 timeout;
    u8 child;
};
extern const u16 gUnknown_081496d4[], gUnknown_08149874[], gUnknown_081326f4[], gUnknown_081498b4[];
u8 FUN_08020500(void *, const u16 *, u16);
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_0803342c(Node *), FUN_08032ea0(Node *);
extern const u16 gUnknown_08137fdc[], gUnknown_081327d4[];
extern const u8 gUnknown_0813801c[], gUnknown_08132544[], gUnknown_08149934[], gUnknown_0814ad38[];
extern const u8 gUnknown_081388b8[], gUnknown_08138a14[], gUnknown_08138b84[], gUnknown_08138cf4[];
extern const u8 gUnknown_08138e58[], gUnknown_08138fcc[], gUnknown_03002110[];
extern const void *const gUnknown_08edc4ac[], *const gUnknown_08edc4c0[],
                                                  *const gUnknown_08edc4d4[];
extern const void *const gUnknown_08edc4e8[], *const gUnknown_08edc4fc[],
                                                  *const gUnknown_08edc510[];
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), CpuFastSet(const void *, void *, u32);
void LZ77UnCompVram(const void *, void *), FUN_08021000(void *, const u16 *, u32, u32, u16);
void FUN_08032aec(Node *), FUN_08032adc(void);
void FUN_0803281c(void) {
    FUN_0801fbfc(gUnknown_08137fdc, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000000, 0x01000100);
    u32 zero1 = 0;
    CpuFastSet(&zero1, (void *)0x06000000, 0x01000010);
    LZ77UnCompVram(gUnknown_0813801c, (void *)0x06000020);
    u32 zero2 = 0;
    CpuFastSet(&zero2, (void *)0x06008000, 0x01000008);
    const void *const *graphics;
    switch (gUnknown_03002110[119]) {
    case 0:
        graphics = gUnknown_08edc4ac;
        goto language;
    case 1:
        graphics = gUnknown_08edc4c0;
        goto language;
    case 2:
        graphics = gUnknown_08edc4d4;
        goto language;
    case 3:
        graphics = gUnknown_08edc4e8;
        goto language;
    case 4:
        graphics = gUnknown_08edc4fc;
        goto language;
    case 5:
        graphics = gUnknown_08edc510;
    language:
        LZ77UnCompVram(graphics[gUnknown_03005300], (void *)0x06008020);
        break;
    default:
        LZ77UnCompVram(gUnknown_08edc4c0[gUnknown_03005300], (void *)0x06008020);
    }
    u32 zero3 = 0;
    CpuFastSet(&zero3, (void *)0x0600a580, 0x01000008);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600a5a0);
    LZ77UnCompVram(gUnknown_08149934, (void *)0x06010000);
    LZ77UnCompVram(gUnknown_0814ad38, (void *)0x06007de0);
    u32 zero4 = 0;
    CpuFastSet(&zero4, (void *)0x0600d000, 0x01000c00);
    LZ77UnCompVram(gUnknown_081388b8, (void *)0x0600d180);
    LZ77UnCompVram(gUnknown_08138a14, (void *)0x0600d980);
    LZ77UnCompVram(gUnknown_08138b84, (void *)0x0600e180);
    LZ77UnCompVram(gUnknown_08138cf4, (void *)0x0600e980);
    LZ77UnCompVram(gUnknown_08138e58, (void *)0x0600f180);
    LZ77UnCompVram(gUnknown_08138fcc, (void *)0x0600f980);
    u32 zero5 = 0;
    CpuFastSet(&zero5, (void *)0x0600c800, 0x01000200);
    u16 *destination = (u16 *)0x0600c840;
    u16 tile = 0x2001;
    u32 row = 0;
    do {
        register u32 column asm("r5") = 0;
        do {
            *destination++ = tile++;
        } while (++column < 32);
    } while (++row < 3);
    destination = (u16 *)0x0600cb80;
    tile += 0x1000;
    row = 0;
    do {
        register u32 column asm("r5") = 0;
        do {
            *destination++ = tile++;
        } while (++column < 30);
        destination += 2;
    } while (++row < 6);
    u32 zero6 = 0;
    CpuFastSet(&zero6, (void *)0x0600c000, 0x01000200);
    u32 zero7 = 0;
    CpuFastSet(&zero7, (void *)0x0600b800, 0x01000200);
    destination = (u16 *)0x0600b800;
    row = 0;
    do {
        u32 column = 0;
        u32 nextRow = row + 1;
        for (; column < 4; ++column) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf12d);
            destination += 8;
        }
        destination += 224;
        row = nextRow;
    } while (row < 4);
    FUN_0801f7d0(FUN_08032aec, 8, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08032adc;
}
void FUN_08032adc(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_08032aec(Node *node) {
    ControlData *data = (ControlData *)node->allocation;
    u32 initial = !FUN_08020500((void *)0x05000000, gUnknown_081496d4, 32);
    u32 pending = initial;
    register u32 result asm("r0");
    if (!FUN_08020500((void *)0x05000040, gUnknown_08149874, 32))
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (!FUN_08020500((void *)0x050001e0, gUnknown_081326f4, 16))
        result = 1 | pending;
    else
        result = (u8)pending;
    pending = result;
    if (!FUN_08020500((void *)0x05000200, gUnknown_081498b4, 64))
        result = 1 | pending;
    else
        result = (u8)pending;
    if (!result) {
        Node *child = FUN_0801f7d0(FUN_0803342c, 20, gUnknown_03003e20, 0);
        data->child = child->index;
        node->callback = FUN_08032ea0;
    }
    if (FUN_08021534() == 255)
        node->callback = (void (*)(Node *))FUN_08033038;
    u8 status = FUN_08021484();
    if (gUnknown_0300525c != status) {
        if (++data->timeout > 29)
            node->callback = (void (*)(Node *))FUN_08033038;
    } else
        data->timeout = 0;
}
extern u32 gUnknown_030013a4, gUnknown_03005308, gUnknown_03004d98, gUnknown_03005304;
extern u32 gUnknown_03005310, gUnknown_03001730;
extern u8 gUnknown_03003290, gUnknown_0300138c;
extern s16 gUnknown_030016f0[];
extern const void *const gUnknown_08edc524[];
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_08018c3c(void), FUN_08018c20(void);
void FUN_0801fc30(u32, void (*)(void)), FUN_08018678(u32);
void FUN_08018b24(void), FUN_0801974c(void), FUN_08019814(u32, const void *);
u32 FUN_08018730(s16 *), FUN_08019568(u32 *);
void FUN_08032ff8(void);
void FUN_08032be0(Node *node) {
    if (gUnknown_03005258 > 119) {
        if (FUN_0802067c((void *)0x05000000, 512)) {
            gUnknown_03002030 = FUN_0803d1a0;
            FUN_0801fb60();
            FUN_0801fb94();
            FUN_0801ff30();
            FUN_0801f780();
            FUN_080210d8();
            FUN_0802110c();
            FUN_08018c3c();
        }
        return;
    }
    switch (gUnknown_0300530c) {
    case 0:
        gUnknown_030013a4 = 0;
        gUnknown_03005308 = 0;
        gUnknown_03004d98 = 0;
        gUnknown_03005304 = 1;
        gUnknown_03005258 = 0;
    case 1:
        FUN_0801fc30(0, FUN_08018b24);
        FUN_08018678((gUnknown_030013a4 & 0xf00) >> 8);
        gUnknown_03003290 = 0;
        if (gUnknown_0300530c == 0)
            gUnknown_0300530c = 3;
        else
            gUnknown_0300530c = 2;
        gUnknown_03005310 = 60;
        break;
    case 2:
        if (gUnknown_03001730 & 16) {
            if (gUnknown_03001730 & 64) {
                ++gUnknown_03001b10[2];
                gUnknown_03005310 = 0;
            }
            gUnknown_0300530c = 3;
            gUnknown_03005258 = 0;
        }
        gUnknown_0300138c = 1;
        FUN_08018c20();
    case 3:
        if (gUnknown_03001730 & 32) {
            if (!(gUnknown_03001730 & 128)) {
                gUnknown_0300530c = 4;
                gUnknown_0300138c = 0;
            } else {
                gUnknown_0300530c = 4;
                gUnknown_0300138c = 0;
            }
        }
        if (gUnknown_03005304 && (gUnknown_03001730 & 16)) {
            if (gUnknown_03005310)
                --gUnknown_03005310;
            else
                gUnknown_03003290 = 1;
        }
        gUnknown_03001730 = FUN_08018730(gUnknown_030016f0);
        if (gUnknown_0300530c == 3) {
            gUnknown_0300138c = 1;
            FUN_08018c20();
        }
        if (gUnknown_03005308 != (s32)gUnknown_030016f0[2]) {
            gUnknown_03005308 = gUnknown_030016f0[2];
            gUnknown_03004d98 = 0;
            if (!(gUnknown_03001730 & 128)) {
                gUnknown_03004d8c = ((u32)gUnknown_030016f0[3] << 16) | (u16)gUnknown_030016f0[4];
            }
        }
        ++gUnknown_03005258;
        break;
    case 4:
        FUN_08018c3c();
        FUN_0801fc30(0, 0);
        if (gUnknown_03005308 == 8)
            node->callback = (void (*)(Node *))FUN_08032ff8;
        gUnknown_0300530c = 6;
        break;
    case 6:
        FUN_0801fc30(0, FUN_0801974c);
        FUN_08019814(gUnknown_03001730 & 128, gUnknown_08edc524[gUnknown_03005308]);
        gUnknown_0300530c = 5;
        break;
    case 5:
        if (FUN_08019568(&gUnknown_03004d98)) {
            gUnknown_030013a4 = gUnknown_03001730;
            gUnknown_03001730 = 0;
            gUnknown_0300530c = 1;
        }
        break;
    }
}
void FUN_08032ea0(Node *node) {
    ControlData *data = (ControlData *)node->allocation;
    if (gUnknown_03003e20[data->child].callback == FUN_080333dc) {
        FUN_0804962c();
        node->callback = FUN_08032f10;
    } else {
        if (FUN_08021534() == 255)
            node->callback = (void (*)(Node *))FUN_08033038;
        u8 status = FUN_08021484();
        if (gUnknown_0300525c != status) {
            if (++data->timeout > 29)
                node->callback = (void (*)(Node *))FUN_08033038;
        } else
            data->timeout = 0;
    }
}
void FUN_08032f10(Node *node) {
    FUN_080214c0(gUnknown_03005300);
    register void (*callback)(Node *) asm("r1") = FUN_08032f34;
    node->callback = callback;
    FUN_0804af6c(node);
}
void FUN_08032f34(Node *node) {
    ControlData *data = (ControlData *)node->allocation;
    switch (FUN_08021534()) {
    case 0:
        break;
    case 255:
        FUN_080496ac();
        node->callback = (void (*)(Node *))FUN_08033038;
        break;
    default:
        FUN_080496ac();
        node->callback = FUN_08032f9c;
    }
    u8 status = FUN_08021484();
    if (gUnknown_0300525c != status) {
        if (++data->timeout > 29) {
            FUN_080496ac();
            node->callback = (void (*)(Node *))FUN_08033038;
        }
    } else
        data->timeout = 0;
}
void FUN_08032f9c(Node *input) {
    Node *node = input;
    ControlData *data = (ControlData *)node->allocation;
    FUN_08021564();
    u16 *header = gUnknown_03001b10;
    u32 size = gUnknown_03004d8c;
    u32 mask = 7 & ~(size >> 15);
    u32 zero = 0;
    header[2] = mask;
    header[3] = size >> 16;
    header[4] = size;
    gUnknown_0300530c = zero;
    gUnknown_03003e20[data->child].callback = FUN_08033474;
    gUnknown_03005258 = zero;
    node->callback = FUN_08032be0;
}
void FUN_08032ff8(void) {
    if (FUN_080206ec((void *)0x05000000, 512)) {
        u32 start = 0x0203b000 - gUnknown_03004d8c;
        register void *destination asm("r4") = (void *)0x02000100;
        FUN_0804a5b8(start, destination);
        FUN_0804a5c8(194);
        FUN_0804af78();
    }
}
void FUN_08033038(void) {
    if (FUN_0802067c((void *)0x05000000, 512))
        gUnknown_03002030 = FUN_0803d1a0;
}
void FUN_08033060(Node *node) {
    u32 *angle = (u32 *)node->allocation;
    *angle += 16;
    if (*angle > 95)
        *angle -= 96;
    FUN_0801fba0(8, gUnknown_08edc544[*angle >> 4]);
}
void FUN_08033090(Node *node) {
    if (++node->position->x > 23) {
        node->position->x = 24;
        node->callback = FUN_08033104;
    }
    node->position->tile = gUnknown_08edc590[node->position->state >> 5];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x + 7;
    gUnknown_03003e20[node->position->player].position->y = node->position->y + 36;
    node->position->state += 24;
}
void FUN_08033104(Node *node) {
    node->position->tile = gUnknown_08edc590[node->position->state >> 5];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x + 7;
    gUnknown_03003e20[node->position->player].position->y = node->position->y + 36;
    node->position->state += 16;
}
void FUN_0803315c(Node *node) {
    if (++node->position->state > 29) {
        node->position->state = 0;
        node->callback = FUN_08033090;
    }
}
void FUN_08033184(Node *node) {
    *node->position = gUnknown_08edc550[0];
    Node *child = FUN_0801f7d0(FUN_0801f9d8, 16, node, 0);
    node->position->player = child->index;
    *child->position = gUnknown_08edc550[1];
    node->position->state = 0;
    node->callback = FUN_0803315c;
}
void FUN_080331d0(Node *node) {
    if (++node->position->state > 14) {
        node->position->state = 15;
        node->callback = FUN_080333dc;
    }
    node->position->x = gUnknown_08edc5c8[node->position->state];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
}
void FUN_08033228(Node *node) {
    if ((node->position->x -= 3) <= 120) {
        node->position->x = 120;
        node->position->timer = 0;
        node->callback = FUN_0803329c;
    }
    node->position->y = gUnknown_08edc5a0[node->position->state];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
    if (++node->position->state > 19)
        node->position->state = 0;
}
void FUN_0803329c(Node *node) {
    if (++node->position->timer > 4) {
        node->position->timer = 0;
        if (--node->position->x <= 90) {
            node->position->x = 90;
            node->callback = FUN_08033320;
        }
    }
    node->position->y = gUnknown_08edc5a0[node->position->state];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
    if (++node->position->state > 19)
        node->position->state = 0;
}
void FUN_08033320(Node *node) {
    if (++node->position->x > 119) {
        node->position->x = 120;
        node->callback = FUN_0803329c;
    }
    node->position->y = gUnknown_08edc5a0[node->position->state];
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
    if (++node->position->state > 19)
        node->position->state = 0;
}
void FUN_08033390(Node *node) {
    if ((node->position->x += 6) > 59) {
        node->position->x = 60;
        node->position->state = 0;
        node->callback = FUN_080331d0;
    }
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
}
void FUN_080333dc(Node *node) {
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
}
void FUN_08033404(Node *node) {
    if (++node->position->state > 59) {
        node->position->state = 0;
        node->callback = FUN_08033228;
    }
}
void FUN_0803342c(Node *node) {
    *node->position = gUnknown_08edc570[0];
    Node *child = FUN_0801f7d0(FUN_0801f9d8, 16, node, 0);
    node->position->player = child->index;
    *child->position = gUnknown_08edc570[1];
    node->callback = FUN_08033390;
}
void FUN_08033474(Node *node) {
    if ((node->position->x += 8) > 239) {
        node->position->state = 0;
        node->callback = FUN_08033404;
        FUN_0801f7d0(FUN_08033060, 4, gUnknown_03003e20, 0);
        FUN_0801f7d0(FUN_08033184, 16, gUnknown_03003e20, 0);
        FUN_0801f7d0(FUN_080334ec, 20, gUnknown_03003e20, 0);
    }
    FUN_0801fed8(node->index, 0);
    gUnknown_03003e20[node->position->player].position->x = node->position->x;
}
void FUN_080334ec(Node *node) {
    u16 *data = (u16 *)node->allocation;
    if (data[1]) {
        --data[1];
    } else {
        Node *child;
        switch ((FUN_08020144() >> 2) & 7) {
        case 0:
        case 1:
            child = FUN_0801f7d0(FUN_080335dc, 16, node, 0);
            *child->position = gUnknown_08edc5e8[0];
            break;
        case 2:
            child = FUN_0801f7d0(FUN_080335dc, 16, node, 0);
            *child->position = gUnknown_08edc5f8[0];
            break;
        case 3:
        case 4:
            child = FUN_0801f7d0(FUN_0803362c, 16, node, 0);
            *child->position = gUnknown_08edc608[0];
            break;
        case 5:
        case 6:
            child = FUN_0801f7d0(FUN_0803362c, 16, node, 0);
            *child->position = gUnknown_08edc618[0];
            break;
        case 7:
            child = FUN_0801f7d0(FUN_0803367c, 16, node, 0);
            *child->position = gUnknown_08edc628[0];
            break;
        }
        data[1] = (FUN_08020144() & 28) + 4;
    }
}
void FUN_080335dc(Node *node) {
    if (((u8)++node->position->state & 4) != 0)
        node->position->tile = 128;
    else
        node->position->tile = 148;
    node->position->x -= 8;
    if (node->position->x < -16)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
void FUN_0803362c(Node *node) {
    if (((u8)++node->position->state & 4) != 0)
        node->position->tile = 168;
    else
        node->position->tile = 174;
    node->position->x -= 6;
    if (node->position->x < -16)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
void FUN_0803367c(Node *node) {
    node->position->x -= 6;
    if (node->position->x < -16)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
void FUN_080336ac(Node *node) {
    node->position->x -= 6;
    if (node->position->x < -16)
        FUN_0801f8c0(node);
    else
        FUN_0801fed8(node->index, 0);
}
extern const u8 gUnknown_08139140[];
extern const u8 gUnknown_0813caf8[];
extern const u8 gUnknown_08140770[];
extern const u8 gUnknown_08144df0[];
const void *const gUnknown_08edc4ac[] = {gUnknown_08139140, gUnknown_0813caf8, gUnknown_0813caf8,
                                         gUnknown_08140770, gUnknown_08144df0};
extern const u8 gUnknown_08139c90[];
extern const u8 gUnknown_0813d628[];
extern const u8 gUnknown_081413b0[];
extern const u8 gUnknown_08145a58[];
const void *const gUnknown_08edc4c0[] = {gUnknown_08139c90, gUnknown_0813d628, gUnknown_0813d628,
                                         gUnknown_081413b0, gUnknown_08145a58};
extern const u8 gUnknown_0813a5cc[];
extern const u8 gUnknown_0813dfa4[];
extern const u8 gUnknown_08141f1c[];
extern const u8 gUnknown_08146640[];
const void *const gUnknown_08edc4d4[] = {gUnknown_0813a5cc, gUnknown_0813dfa4, gUnknown_0813dfa4,
                                         gUnknown_08141f1c, gUnknown_08146640};
extern const u8 gUnknown_0813af3c[];
extern const u8 gUnknown_0813e9c8[];
extern const u8 gUnknown_08142af4[];
extern const u8 gUnknown_08147250[];
const void *const gUnknown_08edc4e8[] = {gUnknown_0813af3c, gUnknown_0813e9c8, gUnknown_0813e9c8,
                                         gUnknown_08142af4, gUnknown_08147250};
extern const u8 gUnknown_0813b884[];
extern const u8 gUnknown_0813f3f4[];
extern const u8 gUnknown_08143690[];
extern const u8 gUnknown_08147ebc[];
const void *const gUnknown_08edc4fc[] = {gUnknown_0813b884, gUnknown_0813f3f4, gUnknown_0813f3f4,
                                         gUnknown_08143690, gUnknown_08147ebc};
extern const u8 gUnknown_0813c184[];
extern const u8 gUnknown_0813fdbc[];
extern const u8 gUnknown_08144270[];
extern const u8 gUnknown_08148af4[];
const void *const gUnknown_08edc510[] = {gUnknown_0813c184, gUnknown_0813fdbc, gUnknown_0813fdbc,
                                         gUnknown_08144270, gUnknown_08148af4};
const void *const gUnknown_08edc524[] = {(const void *)0x02000100, (const void *)0x02003000,
                                         (const void *)0x0200b000, (const void *)0x02013000,
                                         (const void *)0x0201b000, (const void *)0x02023000,
                                         (const void *)0x0202b000, (const void *)0x02033000};
const u16 gUnknown_08edc544[] = {6659, 6915, 7171, 7427, 7683, 7939};
extern const u8 gUnknown_0814ad18[];
extern const u8 gUnknown_0814ad10[];
extern const Position gUnknown_08edc550[];
const Position gUnknown_08edc550[] = {{gUnknown_0814ad18, -32, 40, 196, 0, 0, 52, 0, 0, 0},
                                      {gUnknown_0814ad10, -32, 76, 188, 4, 0, 52, 0, 0, 0}};
extern const u8 gUnknown_0814acc8[];
extern const u8 gUnknown_0814acc8[];
extern const Position gUnknown_08edc570[];
const Position gUnknown_08edc570[] = {{gUnknown_0814acc8, -60, 56, 0, 0, 0, 4, 0, 0, 0},
                                      {gUnknown_0814acc8, -60, 56, 64, 4, 0, 4, 0, 0, 0}};
const u16 gUnknown_08edc590[] = {304, 268, 232, 196, 448, 412, 376, 340};
const s16 gUnknown_08edc5a0[] = {56, 57, 58, 58, 59, 59, 59, 58, 58, 57,
                                 56, 55, 54, 54, 53, 53, 53, 54, 54, 55};
const s16 gUnknown_08edc5c8[] = {64, 60, 56, 60, 63, 60, 57, 60, 62, 60, 58, 60, 61, 60, 59, 60};
extern const u8 gUnknown_0814acd8[];
extern const Position gUnknown_08edc5e8[];
const Position gUnknown_08edc5e8[] = {{gUnknown_0814acd8, 256, 93, 128, 0, 0, 16, 0, 0, 0}};
extern const u8 gUnknown_0814ace8[];
extern const Position gUnknown_08edc5f8[];
const Position gUnknown_08edc5f8[] = {{gUnknown_0814ace8, 256, 93, 128, 0, 0, 16, 0, 0, 0}};
extern const u8 gUnknown_0814acf0[];
extern const Position gUnknown_08edc608[];
const Position gUnknown_08edc608[] = {{gUnknown_0814acf0, 256, 72, 168, 0, 0, 28, 0, 0, 0}};
extern const u8 gUnknown_0814ad00[];
extern const Position gUnknown_08edc618[];
const Position gUnknown_08edc618[] = {{gUnknown_0814ad00, 256, 72, 168, 0, 0, 28, 0, 0, 0}};
extern const u8 gUnknown_0814ad08[];
extern const Position gUnknown_08edc628[];
const Position gUnknown_08edc628[] = {{gUnknown_0814ad08, 256, 80, 180, 0, 0, 44, 0, 0, 0}};
extern const u8 gUnknown_0814ad08[];
extern const Position gUnknown_08edc638[];
const Position gUnknown_08edc638[] = {{gUnknown_0814ad08, 256, 78, 180, 0, 0, 44, 0, 0, 0}};
extern const u16 gUnknown_08137fdc[] __attribute__((section(".rodata.registers")));
const u16 gUnknown_08137fdc[] = {0,  0,  8,  6659, 16,   0,     18, 0,    10, 6411, 20,
                                 0,  22, 0,  12,   6147, 24,    0,  26,   0,  14,   5899,
                                 28, 0,  30, 0,    80,   16128, 82, 2056, 84, 0};
u32 gUnknown_03005304 __attribute__((section(".bss"))) = 0;
u32 gUnknown_03005308 __attribute__((section(".bss.state4"))) = 0;
u32 gUnknown_0300530c __attribute__((section(".bss.state8"))) = 0;
u32 gUnknown_03005310 __attribute__((section(".bss.state12"))) = 0;
}
