// C++ reconstruction fallback; see docs/briefing-tu-cpp.md.
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
extern "C" {
extern u8 gUnknown_03001620[], gUnknown_03002110[];
extern const u8 gUnknown_0811dd40[], gUnknown_081305c4[], gUnknown_081303e4[];
extern const u16 gUnknown_08130324[] __attribute__((section(".rodata.registers")));
extern const void *const gUnknown_08edc23c[][2];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb94(void), FUN_0801ff30(void);
void FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_080312c8(Node *), FUN_080312f8(Node *), FUN_08031154(void);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16);
void FUN_08030f38(void) {
    u32 fills[5];
    u32 *fill1;
    register u32 *fill2 asm("r8");
    register u32 *fill3;
    register u32 *fill4 asm("r10");
    register const u16 *registers asm("r4");
    {
        register u8 *scene asm("r12") = gUnknown_03001620;
        register u8 *save = gUnknown_03002110;
        register u8 *selectedAddress asm("r1") = save + 117;
        register u32 selected asm("r0") = *selectedAddress;
        register u32 initialZero = 0;
        {
            register u8 *firstStore = scene;
            firstStore[20] = selected;
            firstStore[28] = initialZero;
        }
        register u8 *countAddress asm("r6") = &scene[36];
        register u32 one = 1;
        *countAddress = one;
        const u8 *record =
            gUnknown_0811dd40 + *selectedAddress * 120 + scene[124] * 24 + save[118] * 8;
        {
            register u8 *out = scene;
            out[1] = initialZero;
            out[2] = one;
        }
        {
            register u32 value = record[6];
            register u8 *out = scene;
            out[3] = value;
            out[11] = record[1] - 1;
        }
        register u32 i = 1;
        registers = gUnknown_08130324;
        fill1 = &fills[1];
        {
            register u32 *address = &fills[2];
            asm volatile("" : "+r"(address));
            fill2 = address;
        }
        {
            register u32 *address = &fills[3];
            fill3 = address;
        }
        {
            register u32 *address = &fills[4];
            asm volatile("" : "+r"(address));
            fill4 = address;
        }
        register u8 *count = countAddress;
        register u8 *character = countAddress - 15;
        do {
            register u32 value asm("r1") = *record;
            character[0] = value;
            record++;
            character[8] = *record++;
            asm volatile("" : "+r"(value));
            if ((u8)value != 255)
                (*count)++;
            character++;
            i++;
        } while (i < 4);
    }
    FUN_0801fbfc(registers, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    fills[0] = 0;
    CpuFastSet(&fills[0], (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_081305c4, (void *)0x06000000);
    fills[1] = 0;
    CpuFastSet(fill1, (void *)0x0600f800, 0x01000200);
    fills[2] = 0;
    CpuFastSet(fill2, (void *)0x0600f000, 0x01000200);
    fills[3] = 0;
    CpuFastSet(fill3, (void *)0x0600e800, 0x01000200);
    u16 *out = (u16 *)0x0600e800;
    {
        register u32 i asm("r5") = 0;
        register u32 tile asm("r1") = 0x1001;
        register u32 pixel = tile;
        asm volatile("" : : "r"(tile), "r"(pixel));
        do {
            *out++ = pixel;
            i++;
        } while (i < 128);
    }
    out = (u16 *)0x0600ec00;
    {
        register u32 i asm("r5") = 0;
        register u32 tile asm("r2") = 0x1001;
        register u32 pixel = tile;
        asm volatile("" : : "r"(tile), "r"(pixel));
        do {
            *out++ = pixel;
            i++;
        } while (i < 128);
    }
    fills[4] = 0;
    CpuFastSet(fill4, (void *)0x0600e000, 0x01000200);
    LZ77UnCompVram(gUnknown_081303e4, (void *)0x0600e100);
    u32 i = 1;
    register u8 *scene = gUnknown_03001620;
    register u8 *countAddress = scene + 36;
    register u32 countValue = *countAddress;
    if (i < countValue) {
        register const void *const(*table)[2] asm("r8") = gUnknown_08edc23c;
        register u8 *base asm("r9") = scene;
        register u8 *count = countAddress;
        u8 *palette = (u8 *)0x05000200;
        register u8 *graphics = (u8 *)0x06010000;
        do {
            register u8 *entry asm("r4") = base + 20;
            entry = (u8 *)(i + (u32)entry);
            LZ77UnCompVram(table[*entry][0], graphics);
            register u32 paletteOffset = *entry * 8;
            register const void *const(*paletteTable)[2] =
                (const void *const(*)[2])((u32)gUnknown_08edc23c + 4);
            CpuFastSet(*(const void **)(paletteOffset + (u32)paletteTable), palette, 8);
            palette += 32;
            register u32 stride asm("r2") = 0x1200;
            asm volatile("" : : "r"(stride));
            graphics += stride;
            i++;
        } while (i < *count);
    }
    FUN_0801f7d0(FUN_080312c8, 8, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_080312f8, 4, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08031154;
    FUN_0801f618(45);
}
}
extern "C" {
extern const u16 gUnknown_08130364[];
extern u8 gUnknown_03001620[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_0801fb94(void), FUN_0801ff30(void);
void FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void FUN_080184c8(void), FUN_08018c3c(void), FUN_0801c82c(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fba0(u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_0803156c(Node *), FUN_08031310(Node *), FUN_080312a0(void);
u8 FUN_0802067c(void *, u16), FUN_08020500(void *, const u16 *, u16);
void FUN_08031154(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_08031164(void) {
    FUN_0801fbfc(gUnknown_08130324, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    gUnknown_03001620[125] = 1;
    gUnknown_03001620[0] = 0;
    FUN_080184c8();
    FUN_08018c3c();
    gUnknown_03002030 = FUN_0801c82c;
}
void FUN_080311b4(Node *node) {
    u16 *data = (u16 *)node->allocation;
    switch (data[1]) {
    case 0:
    case 1:
    case 2:
        if (--data[2] == 0) {
            Node *sprite = FUN_0801f7d0(FUN_0803156c, 16, gUnknown_03003e20, 0);
            switch (gUnknown_03001620[36]) {
            case 2:
                sprite->position->player = (u8)data[1] + 6;
                data[1] = 2;
                break;
            case 3:
                sprite->position->player = (u8)data[1] + 3;
                if (data[1] != 0)
                    data[1] = 2;
                break;
            case 4:
                sprite->position->player = data[1];
                break;
            default:
                data[1] = 2;
                break;
            }
            data[2] = 10;
            data[1]++;
        }
        break;
    case 3:
        if (--data[2] == 0) {
            FUN_0801f7d0(FUN_08031310, 28, gUnknown_03003e20, 0);
            data[1]++;
            data[2] = 240;
        }
        break;
    case 4:
        if (--data[2] == 0)
            node->callback = (void (*)(Node *))FUN_080312a0;
        break;
    }
}
void FUN_0803128c(Node *node) {
    u16 *data = (u16 *)node->allocation;
    register u32 zero = 0;
    data[2] = 30;
    data[1] = zero;
    node->callback = FUN_080311b4;
}
void FUN_080312a0(void) {
    if (FUN_0802067c((void *)0x05000000, 512))
        gUnknown_03002030 = FUN_08031164;
}
void FUN_080312c8(Node *node) {
    u32 pending = !FUN_08020500((void *)0x05000000, gUnknown_08130364, 64);
    if (!pending)
        node->callback = FUN_0803128c;
}
void FUN_080312f8(Node *node) {
    u32 *counter = (u32 *)node->allocation;
    FUN_0801fba0(28, *(u8 *)counter);
    *counter -= 12;
}
}
extern "C" {
extern u8 gUnknown_03001620[];
extern const u8 *const gUnknown_08edc28c[];
extern const u8 gUnknown_08131f70[], gUnknown_08132374[], gUnknown_08edc2c8[];
extern const u16 gUnknown_081303a4[], gUnknown_081303c4[], gUnknown_08edc2a4[];
extern const s16 gUnknown_08edc2b6[];
void FUN_0801fba0(u16, u16), LZ77UnCompVram(const void *, void *);
void FUN_08020774(void *, const u16 *, u16, u16);
void FUN_0801f978(Node *, s16), FUN_0801fed8(u8, u32);
void FUN_0803139c(Node *);
void FUN_08031310(Node *node) {
    s16 *data = (s16 *)node->allocation;
    register u32 zero = 0;
    data[9] = 32;
    data[10] = zero;
    FUN_0801fba0(16, 480);
    FUN_0801fba0(20, 32);
    FUN_0801fba0(82, 4096);
    LZ77UnCompVram(gUnknown_08edc28c[gUnknown_03001620[124]], (void *)0x0600fc00);
    LZ77UnCompVram(gUnknown_08edc28c[gUnknown_03001620[124]], (void *)0x0600f400);
    u16 *tiles = (u16 *)0x0600f400;
    for (u32 i = 0; i < 128; i++) {
        *tiles = (*tiles & 0xfff) | 0x4000;
        tiles++;
    }
    node->callback = FUN_0803139c;
}
void FUN_0803139c(Node *node) {
    s16 *data = (s16 *)node->allocation;
    switch (data[10]) {
    case 0: {
        s32 offset = (u16)data[9] - 1;
        register u32 zero = 0;
        data[9] = offset;
        if ((s16)offset <= 0) {
            data[9] = zero;
            data[8] = zero;
            data[10] = 1;
        }
        FUN_08020774((void *)0x05000080, gUnknown_081303c4, 16, 16 - ((data[9] >> 1) & 31));
        break;
    }
    case 1:
        if (++data[8] > 59)
            data[10] = 2;
        break;
    case 2:
        if (++data[9] > 31)
            data[10] = 3;
        FUN_08020774((void *)0x05000080, gUnknown_081303c4, 16, 16 - ((data[9] >> 1) & 31));
        break;
    case 3: {
        LZ77UnCompVram(gUnknown_08131f70, (void *)0x0600fc00);
        LZ77UnCompVram(gUnknown_08131f70, (void *)0x0600f400);
        u16 *tiles = (u16 *)0x0600f400;
        for (u32 i = 0; i < 128; i++) {
            *tiles = (*tiles & 0xfff) | 0x4000;
            tiles++;
        }
        data[10] = 4;
        break;
    }
    case 4: {
        s32 offset = (u16)data[9] - 1;
        register u32 zero = 0;
        data[9] = offset;
        if ((s16)offset <= 0) {
            data[9] = zero;
            data[8] = zero;
            data[10] = 5;
        }
        FUN_08020774((void *)0x05000080, gUnknown_081303a4, 16, 16 - ((data[9] >> 1) & 31));
        break;
    }
    case 5:
        if (++data[8] > 59)
            data[10] = 6;
        break;
    case 6:
        if (++data[9] > 31)
            data[10] = 7;
        FUN_08020774((void *)0x05000080, gUnknown_081303a4, 16, 16 - ((data[9] >> 1) & 31));
        break;
    case 7:
        return;
    }
    FUN_0801fba0(16, -data[9] & 511);
    FUN_0801fba0(20, data[9] & 511);
    u32 blend = (data[9] >> 1) & 31;
    FUN_0801fba0(82, (blend << 8) | (16 - blend));
}
void FUN_08031540(Node *node) {
    FUN_0801f978(node, gUnknown_08edc2b6[node->position->player]);
    FUN_0801fed8(node->index, 0);
}
void FUN_0803156c(Node *node) {
    node->position->parts = gUnknown_08132374;
    node->position->tile = gUnknown_08edc2a4[node->position->player];
    node->position->x = 256;
    node->position->y = 32;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = gUnknown_08edc2c8[node->position->player] << 4;
    node->callback = FUN_08031540;
}
}

// Interpreted private metadata; assets remain external.
extern "C" {
extern const u16 gUnknown_08130324[] __attribute__((section(".rodata.registers"))) = {
    0x0,  0x0,  0x8,  0x1f00, 0x10,   0x0,    0x12, 0x0,    0xa,  0x1e00, 0x14,
    0x0,  0x16, 0x0,  0xc,    0x1d02, 0x18,   0x0,  0x1a,   0x0,  0xe,    0x1c03,
    0x1c, 0x0,  0x1e, 0x0,    0x50,   0x3f41, 0x52, 0x1000, 0x54, 0x0,
};
extern const u8 gUnknown_08132014[];
extern const u8 gUnknown_081320ac[];
extern const u8 gUnknown_08132148[];
extern const u8 gUnknown_081321e8[];
extern const u8 gUnknown_08132288[];
extern const u8 gUnknown_081aa95c[];
extern const u8 gUnknown_081aa97c[];
extern const u8 gUnknown_081ac484[];
extern const u8 gUnknown_081ac4a4[];
extern const u8 gUnknown_081ad6a0[];
extern const u8 gUnknown_081ad6c0[];
extern const u8 gUnknown_081aebf8[];
extern const u8 gUnknown_081aec18[];
extern const u8 gUnknown_081b01a4[];
extern const u8 gUnknown_081b01c4[];
extern const u8 gUnknown_081b1a3c[];
extern const u8 gUnknown_081b1a5c[];
extern const u8 gUnknown_081b2858[];
extern const u8 gUnknown_081b2878[];
extern const u8 gUnknown_081b3b7c[];
extern const u8 gUnknown_081b3b9c[];
extern const u8 gUnknown_081b4f8c[];
extern const u8 gUnknown_081b4fac[];
extern const u8 gUnknown_081b6b1c[];
extern const u8 gUnknown_081b6b3c[];
extern const void *const gUnknown_08edc23c[][2] = {
    {gUnknown_081aa97c, gUnknown_081aa95c}, {gUnknown_081ac4a4, gUnknown_081ac484},
    {gUnknown_081ad6c0, gUnknown_081ad6a0}, {gUnknown_081aec18, gUnknown_081aebf8},
    {gUnknown_081b1a5c, gUnknown_081b1a3c}, {gUnknown_081b01c4, gUnknown_081b01a4},
    {gUnknown_081b3b9c, gUnknown_081b3b7c}, {gUnknown_081b2878, gUnknown_081b2858},
    {gUnknown_081b4fac, gUnknown_081b4f8c}, {gUnknown_081b6b3c, gUnknown_081b6b1c},
};
extern const u8 *const gUnknown_08edc28c[] = {
    gUnknown_08132014, gUnknown_081320ac, gUnknown_08132148,
    gUnknown_081321e8, gUnknown_08132288, gUnknown_08132288,
};
extern const u16 gUnknown_08edc2a4[] = {0, 144, 288, 0, 144, 288, 0, 144, 288};
extern const s16 gUnknown_08edc2b6[] = {0, 72, 144, 36, 108, 255, 72, 255, 255};
extern const u8 gUnknown_08edc2c8[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
// Alignment before the next screen metadata.
extern const u8 briefingAlignment[3] = {0, 0, 0};
}
