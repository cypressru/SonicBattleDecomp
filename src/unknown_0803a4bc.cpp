// C++ reconstruction fallback; original language and linkage are unknown.
// Full inferred TU: docs/scene-3a4bc-tu-cpp.md.
#include "types.h"
struct Label {
    u8 x, y, index, align;
};
struct AlignedFive {
    u16 values[5];
} __attribute__((aligned(4)));
#define gUnknown_0816ec30 (gUnknown_0816ec2c + 1)
#define gUnknown_0816ec34 (gUnknown_0816ec2c + 2)
#define gUnknown_0816ec3c (gUnknown_0816ec2c + 4)
#define gUnknown_0816ec44 (gUnknown_0816ec2c + 6)
#define gUnknown_0816ec4c (gUnknown_0816ec2c + 8)
#define gUnknown_0816ec68 (gUnknown_0816ec2c + 15)
extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const Label gUnknown_0816ec2c[];
extern const u16 *const *gUnknown_030053e4, *const *gUnknown_030053ec, *const *gUnknown_03005400;
extern u8 gUnknown_030052d0[], gUnknown_030052e8[], gUnknown_030053f8, gUnknown_030053e8,
    gUnknown_030053f0, gUnknown_030053e0;
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
void FUN_0803a4bc(u8 selection) {
    // Retail reserves four unaccessed bytes beyond its outgoing arguments.
    // This empty memory operand reproduces layout, not an asserted semantic local.
    u32 frameSlot;
    asm("" : "=m"(frameSlot));
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 24, 20, 0);
    switch (selection) {
    case 0: {
        register u32 zero asm("r6") = 0;
        register u32 *row asm("r5") = (u32 *)0x06008078;
        register u32 r asm("r3") = 0;
        register const Label *labelBase asm("r7") = gUnknown_0816ec30;

        register const u16 *const **globalTableAddress asm("r8") = &gUnknown_030053e4;

        do {
            register u32 c asm("r2") = 0;
            register u32 stride asm("r0") = 640;

            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextR = r + 1;
            register u32 *walker asm("r3") = row;
            do {
                *walker++ = zero;
            } while (++c <= 15);
            row = nextRow;
            r = nextR;
        } while (r <= 23);
        const Label *label = labelBase;
        {
            u32 index = label->index;
            register const u16 *const **tableAddress asm("r2") = globalTableAddress;
            u32 table = (u32)*tableAddress;

            register const u16 *const *entry = (const u16 *const *)((index << 2) + table);
            u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        {
            register u32 valueIndex = gUnknown_030052d0[gUnknown_030053f8];

            register u32 valueTable = (u32)gUnknown_030053ec;

            const u16 *const *valueEntry = (const u16 *const *)((valueIndex << 2) + valueTable);
            u8 x = 160;
            u8 y = label->y;
            const u16 *text = *valueEntry;
            x -= FUN_08020ad0(text);
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        gUnknown_030052e8[0] =
            FUN_08020ad0(gUnknown_030053ec[gUnknown_030052d0[gUnknown_030053f8]]);
        break;
    }
    case 1: {
        register u32 zero asm("r6") = 0;
        register u32 *row asm("r5") = (u32 *)0x060080b8;
        register u32 r asm("r3") = 0;
        register const u16 *const **globalTableAddress asm("r8") = &gUnknown_030053e4;

        do {
            register u32 c asm("r2") = 0;
            register u32 stride asm("r0") = 640;

            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextR = r + 1;
            register u32 *walker asm("r3") = row;
            do {
                *walker++ = zero;
            } while (++c <= 15);
            row = nextRow;
            r = nextR;
        } while (r <= 23);
        const Label *label = gUnknown_0816ec34;
        {
            u32 index = label->index;
            register const u16 *const **tableAddress asm("r2") = globalTableAddress;
            u32 table = (u32)*tableAddress;

            register const u16 *const *entry = (const u16 *const *)((index << 2) + table);
            u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        {
            register u32 valueIndex = gUnknown_030052d0[gUnknown_030053e8];

            register u32 valueTable = (u32)gUnknown_030053ec;

            const u16 *const *valueEntry = (const u16 *const *)((valueIndex << 2) + valueTable);
            u8 x = 160;
            u8 y = label->y;
            const u16 *text = *valueEntry;
            x -= FUN_08020ad0(text);
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        gUnknown_030052e8[1] =
            FUN_08020ad0(gUnknown_030053ec[gUnknown_030052d0[gUnknown_030053e8]]);
        break;
    }
    case 2: {
        register u32 zero asm("r6") = 0;
        register u32 *row asm("r5") = (u32 *)0x06008138;
        register u32 r asm("r3") = 0;
        register const u16 *const **globalTableAddress asm("r8") = &gUnknown_030053e4;

        do {
            register u32 c asm("r2") = 0;
            register u32 stride asm("r0") = 640;
            asm("" : "+r"(stride));
            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextR = r + 1;
            register u32 *walker asm("r3") = row;
            do {
                *walker++ = zero;
            } while (++c <= 15);
            row = nextRow;
            r = nextR;
        } while (r <= 23);
        const Label *label = gUnknown_0816ec3c;
        {
            u32 index = label->index;
            register const u16 *const **tableAddress asm("r2") = globalTableAddress;
            u32 table = (u32)*tableAddress;

            register const u16 *const *entry = (const u16 *const *)((index << 2) + table);
            u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        register u32 labelOffset = gUnknown_030053f0 << 2;

        register u32 labelAddress = (u32)gUnknown_0816ec4c;
        label = (const Label *)(labelOffset + labelAddress);
        {
            register u32 index = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            index <<= 2;
            index += table;
            const u16 *const *entry = (const u16 *const *)index;
            register u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        gUnknown_030052e8[2] = FUN_08020ad0(gUnknown_030053e4[label->index]);
        break;
    }
    case 3: {
        register u32 zero asm("r6") = 0;
        register u32 *row asm("r5") = (u32 *)0x060081b8;
        register u32 r asm("r3") = 0;
        register const u16 *const **globalTableAddress asm("r8") = &gUnknown_030053e4;

        do {
            register u32 c asm("r2") = 0;
            register u32 stride asm("r0") = 640;

            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextR = r + 1;
            register u32 *walker asm("r3") = row;
            do {
                *walker++ = zero;
            } while (++c <= 15);
            row = nextRow;
            r = nextR;
        } while (r <= 23);
        const Label *label = gUnknown_0816ec44;
        {
            u32 index = label->index;
            register const u16 *const **tableAddress asm("r2") = globalTableAddress;
            u32 table = (u32)*tableAddress;

            register const u16 *const *entry = (const u16 *const *)((index << 2) + table);
            u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        {
            register u32 valueIndex = gUnknown_030053e0;

            register u32 valueTable = (u32)gUnknown_03005400;

            const u16 *const *valueEntry = (const u16 *const *)((valueIndex << 2) + valueTable);
            u8 x = 160;
            u8 y = label->y;
            const u16 *text = *valueEntry;
            x -= FUN_08020ad0(text);
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        gUnknown_030052e8[3] = FUN_08020ad0(gUnknown_03005400[gUnknown_030053e0]);
        break;
    }
    case 4: {
        register u32 zero asm("r6") = 0;
        register u32 *row asm("r5") = (u32 *)0x06008238;
        register u32 r asm("r3") = 0;
        register const u16 *const **globalTableAddress asm("r8") = &gUnknown_030053e4;

        register const Label *labelBase = gUnknown_0816ec68;

        do {
            register u32 c asm("r2") = 0;
            register u32 stride asm("r0") = 640;

            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextR = r + 1;
            register u32 *walker asm("r3") = row;
            do {
                *walker++ = zero;
            } while (++c <= 15);
            row = nextRow;
            r = nextR;
        } while (r <= 23);
        register const Label *labelInput asm("r6") = labelBase;
        asm("" : "+r"(labelInput));
        const Label *label = labelInput;
        {
            u32 index = label->index;
            register const u16 *const **tableAddress asm("r2") = globalTableAddress;
            u32 table = (u32)*tableAddress;

            register const u16 *const *entry = (const u16 *const *)((index << 2) + table);
            u32 align = label->align;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                ++text;
            }
        }
        break;
    }
    }
}
}

extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const Label gUnknown_0816ec2c[];
extern const u16 *const *gUnknown_030053e4, *const *gUnknown_030053ec, *const *gUnknown_03005400;
extern u8 gUnknown_030052d0[], gUnknown_030053f8, gUnknown_030053e8, gUnknown_030053f0,
    gUnknown_030053e0;
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void CpuFastSet(const void *, void *, u32);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
void FUN_0803a9dc(u8 selection) {
    u32 zero;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06017a00, 24, 2, 0);
    switch (selection) {
    case 0: {
        zero = 0;
        register u32 *clearSource asm("r0") = &zero;

        register void *clearDestination asm("r1") = (void *)0x06017a00;

        CpuFastSet(clearSource, clearDestination, 0x01000180);
        {
            register const Label *label asm("r2") = gUnknown_0816ec30;
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        {
            register u32 valueEntry = gUnknown_030052d0[gUnknown_030053f8];

            register u32 names = (u32)gUnknown_030053ec;

            valueEntry <<= 2;
            valueEntry += names;
            u8 x = 160;
            const u16 *text = *(const u16 **)valueEntry;
            x = (u8)(x - FUN_08020ad0(text));
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        break;
    }
    case 1: {
        zero = 0;
        register u32 *clearSource asm("r0") = &zero;

        register void *clearDestination asm("r1") = (void *)0x06017a00;

        CpuFastSet(clearSource, clearDestination, 0x01000180);
        {
            register const Label *label asm("r2") = gUnknown_0816ec34;
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        {
            register u32 valueEntry = gUnknown_030052d0[gUnknown_030053e8];

            register u32 names = (u32)gUnknown_030053ec;

            valueEntry <<= 2;
            valueEntry += names;
            u8 x = 160;
            const u16 *text = *(const u16 **)valueEntry;
            x = (u8)(x - FUN_08020ad0(text));
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        break;
    }
    case 2: {
        zero = 0;
        register u32 *clearSource asm("r0") = &zero;

        register void *clearDestination asm("r1") = (void *)0x06017a00;

        CpuFastSet(clearSource, clearDestination, 0x01000180);
        {
            register const Label *label asm("r2") = gUnknown_0816ec3c;
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_030053f0 << 2;

            register u32 base asm("r1") = (u32)gUnknown_0816ec4c;
            register const Label *label asm("r2") = (const Label *)(offset + base);
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        break;
    }
    case 3: {
        zero = 0;
        register u32 *clearSource asm("r0") = &zero;

        register void *clearDestination asm("r1") = (void *)0x06017a00;

        CpuFastSet(clearSource, clearDestination, 0x01000180);
        {
            register const Label *label asm("r2") = gUnknown_0816ec44;
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        {
            register u32 valueEntry = gUnknown_030053e0;

            register u32 names = (u32)gUnknown_03005400;

            valueEntry <<= 2;
            valueEntry += names;
            u8 x = 160;
            const u16 *text = *(const u16 **)valueEntry;
            x = (u8)(x - FUN_08020ad0(text));
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        break;
    }
    case 4: {
        zero = 0;
        register u32 *clearSource asm("r0") = &zero;

        register void *clearDestination asm("r1") = (void *)0x06017a00;

        CpuFastSet(clearSource, clearDestination, 0x01000180);
        {
            register const Label *label = gUnknown_0816ec68;
            register u32 entry = label->index;

            register u32 table = (u32)gUnknown_030053e4;

            entry <<= 2;
            entry += table;
            register u32 align = label->align;
            u8 x = label->x;
            const u16 *text = *(const u16 **)entry;
            switch (align) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x = (u8)(x + FUN_08020978(x, 0, *text, 2));
                ++text;
            }
        }
        break;
    }
    }
}
}

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
extern u8 gUnknown_03002110[], gUnknown_030052d0[], gUnknown_030053f4, gUnknown_030053fc;
extern u8 gUnknown_030052e0, gUnknown_030052e4, gUnknown_030052f8;
extern const u16 *const *gUnknown_03005400, *const *gUnknown_030053ec, *const *gUnknown_030053e4;
extern const u16 *const gUnknown_08edc8d8[], *const gUnknown_08edc904[];
extern const u16 *const gUnknown_08edd518[], *const gUnknown_08edd4f0[];
extern const u16 *const gUnknown_08edd370[], *const gUnknown_08edd3b0[], *const gUnknown_08edd3f0[];
extern const u16 *const gUnknown_08edd430[], *const gUnknown_08edd470[], *const gUnknown_08edd4b0[];
extern const u16 gUnknown_0816ebec[], gUnknown_081327d4[];
extern const u8 gUnknown_08132544[], gUnknown_081586f8[], gUnknown_0816ed4c[];
extern const u8 gUnknown_0816ef44[], gUnknown_0816f4e4[], gUnknown_0816ecec[];
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u8 gUnknown_08158904[], gUnknown_08158958[], gUnknown_08158930[];
extern const u8 gUnknown_08158a14[], gUnknown_081589b4[], gUnknown_081589e8[];
extern const Label gUnknown_0816ec2c[];
extern const Position gUnknown_08edd344[2];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void), (*gUnknown_03003150[])(void);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void), FUN_080210d8(void),
    FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
void FUN_0803a4bc(u8), FUN_0803a9dc(u8), FUN_08020408(u32, u32);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d20(Node *), FUN_0803bd8c(Node *), FUN_0803bea8(void), FUN_0803be50(Node *);
void FUN_0801f9d8(Node *), FUN_0803bef0(Node *), FUN_0803b53c(void), FUN_0803b478(void);
void FUN_0801fba0(u16, u16), FUN_0801f618(u32);
void FUN_0803ae04(void) {
    if (gUnknown_03002110[121] & 1)
        gUnknown_030053f4 = 11;
    else
        gUnknown_030053f4 = 10;
    u32 count;
    for (count = 0; count <= 6; ++count)
        gUnknown_030052d0[count] = count;
    if (gUnknown_03002110[121] & 4)
        gUnknown_030052d0[count++] = 7;
    if (gUnknown_03002110[121] & 2)
        gUnknown_030052d0[count++] = 8;
    gUnknown_030052d0[count++] = 9;
    if (count > 9)
        count = 10;
    gUnknown_030053fc = count;
    FUN_0801fbfc(gUnknown_0816ebec, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600c000);
    LZ77UnCompVram(gUnknown_081586f8, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_0816ed4c, (void *)0x06010000);
    switch (gUnknown_03002110[119]) {
    case 0:
        LZ77UnCompVram(gUnknown_0816ef44, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc8d8;
        gUnknown_030053ec = gUnknown_08edd518;
        gUnknown_030053e4 = gUnknown_08edd370;
        break;
    case 2:
        LZ77UnCompVram(gUnknown_0816f4e4, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc904;
        gUnknown_030053ec = gUnknown_08edd4f0;
        gUnknown_030053e4 = gUnknown_08edd3f0;
        break;
    case 3:
        LZ77UnCompVram(gUnknown_0816f4e4, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc904;
        gUnknown_030053ec = gUnknown_08edd4f0;
        gUnknown_030053e4 = gUnknown_08edd430;
        break;
    case 4:
        LZ77UnCompVram(gUnknown_0816f4e4, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc904;
        gUnknown_030053ec = gUnknown_08edd4f0;
        gUnknown_030053e4 = gUnknown_08edd470;
        break;
    case 5:
        LZ77UnCompVram(gUnknown_0816f4e4, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc904;
        gUnknown_030053ec = gUnknown_08edd4f0;
        gUnknown_030053e4 = gUnknown_08edd4b0;
        break;
    case 1:
    default:
        LZ77UnCompVram(gUnknown_0816f4e4, (void *)0x06010c20);
        gUnknown_03005400 = gUnknown_08edc904;
        gUnknown_030053ec = gUnknown_08edd4f0;
        gUnknown_030053e4 = gUnknown_08edd3b0;
        break;
    }
    u32 firstZero = 0;
    CpuFastSet(&firstZero, (void *)0x0600f800, 0x01000200);
    LZ77UnCompVram(gUnknown_0816ecec, (void *)0x0600f800);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    u32 thirdZero = 0;
    CpuFastSet(&thirdZero, (void *)0x06008000, 0x01000f08);
    u16 *column = (u16 *)0x0600f10a;
    u16 tile = 0x2001;
    register u32 columnIndex asm("r6") = 0;
    u8 *selection = &gUnknown_030052e0;

    register u8 *scroll asm("r5") = &gUnknown_030052e4;

    do {
        u32 y = 0;
        u16 *nextColumn = column + 1;
        u16 *row = column;
        do {
            *row = tile++;
            row += 32;
        } while (++y <= 19);
        column = nextColumn;
    } while (++columnIndex <= 23);
    *selection = 0;
    *scroll = 0;
    gUnknown_030052f8 = 4;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 24, 20, 0);
    for (u32 i = 0; i <= 7; ++i) {
        register u32 record = i << 2;

        record += (u32)gUnknown_0816ec2c;
        const Label *label = (const Label *)record;
        register u32 entry = label->index;

        register u32 table = (u32)gUnknown_030053e4;

        entry <<= 2;
        entry += table;
        register u32 align = label->align;
        u8 x = label->x;
        u8 y = label->y;
        const u16 *text = *(const u16 **)entry;
        switch (align) {
        case 1:
            x -= FUN_08020ad0(text);
            break;
        case 2:
            x -= FUN_08020ad0(text) >> 1;
            break;
        }
        while (*text != 0xfffe) {
            x += FUN_08020978(x, y, *text, 2);
            ++text;
        }
    }
    FUN_0803a4bc(0);
    FUN_0803a4bc(1);
    FUN_0803a4bc(2);
    FUN_0803a4bc(3);
    FUN_0803a4bc(4);
    u32 fourthZero = 0;
    CpuFastSet(&fourthZero, (void *)0x0600e800, 0x01000200);
    FUN_08020408(0x0600e900, (u32)gUnknown_08158904);
    FUN_08020408(0x0600e980, (u32)gUnknown_08158958);
    FUN_08020408(0x0600ea00, (u32)gUnknown_08158930);
    FUN_08020408(0x0600ea80, (u32)gUnknown_08158a14);
    FUN_08020408(0x0600eb00, (u32)gUnknown_081589b4);
    FUN_08020408(0x0600eb80, (u32)gUnknown_08158a14);
    FUN_08020408(0x0600ec00, (u32)gUnknown_081589b4);
    FUN_08020408(0x0600ec80, (u32)gUnknown_08158a14);
    FUN_08020408(0x0600ed00, (u32)gUnknown_081589b4);
    FUN_08020408(0x0600ed80, (u32)gUnknown_081589e8);
    u16 *destination = (u16 *)0x0600e000;
    register u32 tileRow asm("r2") = 0;
    do {
        u32 x = 0;
        u32 nextRow = tileRow + 1;
        do {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf200);
            destination += 8;
        } while (++x <= 3);
        destination += 224;
        tileRow = nextRow;
    } while (tileRow <= 3);
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0803bd8c, 16, gUnknown_03003e20, 0);
    FUN_0801f7d0((void (*)(Node *))FUN_0803bea8, 16, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0803be50, 16, gUnknown_03003e20, 0);
    FUN_0803a9dc(gUnknown_030052e0);
    Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd344[0];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edd344[1];
    FUN_0801f7d0(FUN_0803bef0, 32, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_0803b53c;
    FUN_0801f618(4);
    gUnknown_03003150[1] = FUN_0803b478;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
}
}

extern "C" {
extern const u16 gUnknown_0816ebec[], gUnknown_08edd364[];
extern u8 gUnknown_03001620[], gUnknown_030052d0[];
extern u8 gUnknown_030053f8, gUnknown_030053e8, gUnknown_030053e0, gUnknown_030053f0;
extern u8 gUnknown_0300138c, gUnknown_030052e0, gUnknown_030052e4;
extern u16 gUnknown_030052f4, gUnknown_03001378, gUnknown_03007ff8;
extern unsigned long long gUnknown_03002610;
extern void (*gUnknown_03003150[])(void), (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_0803b5a8(void);
void FUN_080184c8(void), FUN_08018c3c(void), FUN_0801c82c(void);
void FUN_08018a8c(void), FUN_0803b54c(void), FUN_0801f60c(void), FUN_0801fbd8(void);
void FUN_0801ffa4(u8);
void FUN_0803b3c4(void) {
    FUN_0801fbfc(gUnknown_0816ebec, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    FUN_0803b5a8();
    u8 *state = gUnknown_03001620;
    state[4] = 0;
    state[5] = 10;
    state[6] = 0;
    state[7] = 0;
    state[8] = 0;
    state[9] = 0;
    state[10] = 0;
    state[11] = 0;
    state[36] = 2;
    state[20] = gUnknown_030052d0[gUnknown_030053f8];
    state[21] = 255;
    register s32 negative = -1;
    ((s8 *)state)[22] = negative;
    state[23] = gUnknown_030052d0[gUnknown_030053e8];
    state[1] = 0;
    state[2] = 1;
    state[3] = gUnknown_030053e0;
    register u32 option = gUnknown_030053f0;

    state[38] = option;
    state[125] = 4;
    state[0] = 0;
    FUN_080184c8();
    FUN_08018c3c();
    gUnknown_03002030 = FUN_0801c82c;
}
void FUN_0803b478(void) {
    if (gUnknown_0300138c)
        FUN_08018a8c();
    gUnknown_03003150[2] = FUN_0803b54c;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
    *(volatile u16 *)0x0400000a = 0x1e0a;
    *(volatile u16 *)0x0400000c = 0x1d02;
    register u16 *scanline = &gUnknown_030052f4;

    register u32 coordinate = gUnknown_08edd364[gUnknown_030052e0];

    *scanline = ((coordinate - gUnknown_030052e4) << 8) | 40;
    FUN_0801f60c();
    ++gUnknown_03001378;
    gUnknown_03007ff8 |= 1;
    FUN_0801fbd8();
    FUN_0801ffa4(0);
    ++gUnknown_03002610;
}
}

extern "C" {
extern void (*gUnknown_03003150[])(void);
extern u16 gUnknown_030052f4;
void FUN_0801f89c(void), FUN_0801fda0(void), FUN_0801fc60(void), FUN_0801f600(void);
void FUN_080185d8(void), FUN_08018654(void), FUN_0803b588(void);
void CpuFastSet(const void *, void *, u32);
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_0803b53c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0803b54c(void) {
    gUnknown_03003150[2] = FUN_0803b588;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = gUnknown_030052f4;
    *(volatile u16 *)0x04000208 = 1;
    FUN_0801fc60();
    FUN_0801f600();
}
void FUN_0803b588(void) {
    register volatile u16 *registers = (volatile u16 *)0x0400000a;
    register u32 value asm("r2") = 0x1e09;
    register u32 copy asm("r0");
    asm("" : "+r"(value));
    copy = value;
    *registers = copy;
    registers++;
    value = 0x1d01;
    asm("" : "+r"(value));
    copy = value;
    *registers = copy;
}
void FUN_0803b5a8(void) {
    gUnknown_03003150[1] = FUN_080185d8;
    gUnknown_03003150[2] = FUN_08018654;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
}
void FUN_0803b5dc(u8 x, u8 y, const u16 *text, u8 align) {
    switch (align) {
    case 1:
        x -= FUN_08020ad0(text);
        break;
    case 2:
        x -= FUN_08020ad0(text) >> 1;
        break;
    }
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, 2);
        ++text;
    }
}
void FUN_0803b63c(u8 index) {
    if (index != 0xff) {
        u32 zero = 0;
        u32 *row = (u32 *)(0x06008038 + index * 64);
        for (u32 y = 0; y <= 23; ++y) {
            for (u32 x = 0; x <= 15; ++x)
                row[x] = zero;
            row = (u32 *)((u8 *)row + 640);
        }
    } else {
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x06017a00, 0x01000180);
    }
}
void FUN_0803b694(void) {}
void FUN_0803b698(void) {}
}

extern "C" {
void FUN_08020408(u32, u32);
extern const u8 gUnknown_08158958[], gUnknown_08158930[], gUnknown_081589e8[];
extern const u8 gUnknown_08158904[], gUnknown_081588ec[], gUnknown_081589b4[];
extern const u8 gUnknown_08158a44[], gUnknown_08158a14[];
void FUN_0803b69c(u8 selection) {
    switch (selection) {
    case 0:
        FUN_08020408((u32)0x0600e980, (u32)gUnknown_08158958);
        FUN_08020408((u32)0x0600ea00, (u32)gUnknown_08158930);
        break;
    case 1:
        FUN_08020408((u32)0x0600ea00, (u32)gUnknown_081589e8);
        FUN_08020408((u32)0x0600ea80, (u32)gUnknown_08158904);
        break;
    case 2:
        FUN_08020408((u32)0x0600eb00, (u32)gUnknown_08158958);
        FUN_08020408((u32)0x0600eb80, (u32)gUnknown_08158904);
        break;
    case 3:
        FUN_08020408((u32)0x0600ec00, (u32)gUnknown_08158958);
        FUN_08020408((u32)0x0600ec80, (u32)gUnknown_08158904);
        break;
    case 4:
        FUN_08020408((u32)0x0600ed00, (u32)gUnknown_08158958);
        FUN_08020408((u32)0x0600ed80, (u32)gUnknown_081588ec);
        break;
    }
}
void FUN_0803b764(u8 selection) {
    switch (selection) {
    case 0:
        FUN_08020408((u32)0x0600e980, (u32)gUnknown_081589b4);
        FUN_08020408((u32)0x0600ea00, (u32)gUnknown_08158a44);
        break;
    case 1:
        FUN_08020408((u32)0x0600ea00, (u32)gUnknown_08158a44);
        FUN_08020408((u32)0x0600ea80, (u32)gUnknown_08158a14);
        break;
    case 2:
        FUN_08020408((u32)0x0600eb00, (u32)gUnknown_081589b4);
        FUN_08020408((u32)0x0600eb80, (u32)gUnknown_08158a14);
        break;
    case 3:
        FUN_08020408((u32)0x0600ec00, (u32)gUnknown_081589b4);
        FUN_08020408((u32)0x0600ec80, (u32)gUnknown_08158a14);
        break;
    case 4:
        FUN_08020408((u32)0x0600ed00, (u32)gUnknown_081589b4);
        FUN_08020408((u32)0x0600ed80, (u32)gUnknown_081589e8);
        break;
    }
}
}

extern "C" {
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_030052e0, gUnknown_030053f8, gUnknown_030053e8, gUnknown_030053f0;
extern u8 gUnknown_030053e0, gUnknown_030053fc, gUnknown_030053f4;
void FUN_0803bd5c(void), FUN_0803bcdc(void);
void FUN_0803bc38(Node *), FUN_0803bac0(Node *), FUN_0803bb7c(Node *);
void FUN_0801f718(u32, u32), FUN_0801f618(u32);
void FUN_0803a4bc(u8), FUN_0803a9dc(u8);
void FUN_0803b82c(Node *node) {
    register u16 pressed asm("r1") = gUnknown_030048e0[2];
    if (pressed & 8) {
        node->callback = (void (*)(Node *))FUN_0803bd5c;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    } else if (pressed & 1) {
        if (gUnknown_030052e0 == 4) {
            node->callback = (void (*)(Node *))FUN_0803bcdc;
            FUN_0801f718(4, 120);
            FUN_0801f618(405);
        }
    } else if (pressed & 2) {
        if (gUnknown_030052e0 != 4) {
            node->callback = FUN_0803bc38;
            FUN_0801f618(401);
        }
    }
    pressed = gUnknown_030048e0[4];
    if (pressed & 64) {
        node->callback = FUN_0803bac0;
        FUN_0801f618(401);
    } else if (pressed & 128) {
        node->callback = FUN_0803bb7c;
        FUN_0801f618(401);
    }
    register u32 repeated asm("r1") = gUnknown_030048e0[4];
    register u32 masked = (repeated & 32) << 16;

    register u32 left = masked >> 16;
    if (left) {
        switch (gUnknown_030052e0) {
        case 0: {
            u32 value = gUnknown_030053f8;
            if (!value)
                value = gUnknown_030053fc;
            gUnknown_030053f8 = value - 1;
            FUN_0803a4bc(0);
            FUN_0803a9dc(0);
            break;
        }
        case 1: {
            u32 value = gUnknown_030053e8;
            if (!value)
                value = gUnknown_030053fc;
            gUnknown_030053e8 = value - 1;
            FUN_0803a4bc(1);
            FUN_0803a9dc(1);
            break;
        }
        case 2:
            if (gUnknown_030053f0)
                --gUnknown_030053f0;
            else
                gUnknown_030053f0 = 6;
            FUN_0803a4bc(2);
            FUN_0803a9dc(2);
            break;
        case 3: {
            u32 value = gUnknown_030053e0;
            if (!value)
                value = gUnknown_030053f4;
            gUnknown_030053e0 = value - 1;
            FUN_0803a4bc(3);
            FUN_0803a9dc(3);
            break;
        }
        }
        if (gUnknown_030052e0 != 4)
            FUN_0801f618(401);
    } else if (repeated & 16) {
        switch (gUnknown_030052e0) {
        case 0:
            if (++gUnknown_030053f8 >= gUnknown_030053fc)
                gUnknown_030053f8 = left;
            FUN_0803a4bc(0);
            FUN_0803a9dc(0);
            break;
        case 1:
            if (++gUnknown_030053e8 >= gUnknown_030053fc)
                gUnknown_030053e8 = left;
            FUN_0803a4bc(1);
            FUN_0803a9dc(1);
            break;
        case 2:
            if (++gUnknown_030053f0 > 6)
                gUnknown_030053f0 = left;
            FUN_0803a4bc(2);
            FUN_0803a9dc(2);
            break;
        case 3:
            if (++gUnknown_030053e0 >= gUnknown_030053f4)
                gUnknown_030053e0 = left;
            FUN_0803a4bc(3);
            FUN_0803a9dc(3);
            break;
        }
        if (gUnknown_030052e0 != 4)
            FUN_0801f618(401);
    }
}
}

extern "C" {
extern u8 gUnknown_030052e0, gUnknown_030052f8, gUnknown_03005398, gUnknown_030025f0;
extern u16 gUnknown_030048e0[];
extern unsigned long long gUnknown_03002610;
extern void (*gUnknown_03002030)(void);
void FUN_0803b764(u8), FUN_0803a9dc(u8), FUN_0803b69c(u8);
void FUN_0803bb08(Node *), FUN_0803bbc4(Node *), FUN_0803bb34(Node *), FUN_0803bbf0(Node *);
void FUN_0803bb54(Node *), FUN_0803bc10(Node *), FUN_0803b82c(Node *);
void FUN_0803bd0c(void), FUN_0803b5a8(void), FUN_08039e20(void), FUN_0803b3c4(void);
void FUN_08000210(void), FUN_0802188c(void), FUN_080215a8(void);
void FUN_080217d0(u8), FUN_0801f718(u32, u32), FUN_0801f618(u32);
u32 FUN_0802067c(u16 *, u16);
void FUN_0803bac0(Node *node) {
    if (gUnknown_030052f8 > 1)
        --gUnknown_030052f8;
    else {
        gUnknown_030052f8 = 0;
        FUN_0803b764(gUnknown_030052e0);
        if (!gUnknown_030052e0)
            gUnknown_030052e0 = 4;
        else
            --gUnknown_030052e0;
        node->callback = FUN_0803bb08;
    }
}
void FUN_0803bb08(Node *node) {
    FUN_0803a9dc(gUnknown_030052e0);
    ++gUnknown_030052f8;
    node->callback = FUN_0803bb34;
}
void FUN_0803bb34(Node *node) {
    FUN_0803b69c(gUnknown_030052e0);
    node->callback = FUN_0803bb54;
}
void FUN_0803bb54(Node *node) {
    if (gUnknown_030052f8 <= 3)
        ++gUnknown_030052f8;
    else {
        gUnknown_030052f8 = 4;
        node->callback = FUN_0803b82c;
    }
}
void FUN_0803bb7c(Node *node) {
    if (gUnknown_030052f8 > 1)
        --gUnknown_030052f8;
    else {
        gUnknown_030052f8 = 0;
        FUN_0803b764(gUnknown_030052e0);
        if (++gUnknown_030052e0 > 4)
            gUnknown_030052e0 = 0;
        node->callback = FUN_0803bbc4;
    }
}
void FUN_0803bbc4(Node *node) {
    FUN_0803a9dc(gUnknown_030052e0);
    ++gUnknown_030052f8;
    node->callback = FUN_0803bbf0;
}
void FUN_0803bbf0(Node *node) {
    FUN_0803b69c(gUnknown_030052e0);
    node->callback = FUN_0803bc10;
}
void FUN_0803bc10(Node *node) {
    if (gUnknown_030052f8 <= 3)
        ++gUnknown_030052f8;
    else {
        gUnknown_030052f8 = 4;
        node->callback = FUN_0803b82c;
    }
}
void FUN_0803bc38(Node *node) {
    if (gUnknown_030052f8)
        --gUnknown_030052f8;
    else {
        FUN_0803b764(gUnknown_030052e0);
        gUnknown_030052e0 = 4;
        node->callback = FUN_0803bbc4;
    }
}
void FUN_0803bc70(Node *input) {
    register Node *node asm("r2") = input;
    register u16 pressed asm("r1") = gUnknown_030048e0[2];
    if (pressed & 2)
        node->callback = FUN_0803b82c;
    else if (pressed & 1) {
        if (gUnknown_03005398) {
            node->callback = (void (*)(Node *))FUN_0803bd0c;
            FUN_0801f718(4, 120);
            FUN_0801f618(404);
        } else
            node->callback = FUN_0803b82c;
    } else if (pressed & 48)
        gUnknown_03005398 ^= 1;
}
void FUN_0803bcdc(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_0803b5a8();
        gUnknown_03002030 = FUN_08039e20;
        FUN_080217d0(0);
    }
}
void FUN_0803bd0c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_0803b5a8();
        gUnknown_03002030 = FUN_08000210;
        FUN_0802188c();
        FUN_080215a8();
        register u32 *state = (u32 *)&gUnknown_03002610;
        register u32 one = 1;
        register u32 zero = 0;
        state[0] = one;
        state[1] = zero;
        gUnknown_030025f0 = 15;
        FUN_080217d0(0);
    }
}
void FUN_0803bd5c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_0803b5a8();
        gUnknown_03002030 = FUN_0803b3c4;
        FUN_080217d0(0);
    }
}
}

extern "C" {
extern u8 gUnknown_030052e0, gUnknown_030052e4, gUnknown_030052f8, gUnknown_030052e8[];
extern const u16 gUnknown_08edd540[];
extern const AlignedFive gUnknown_08edd554;
extern const u8 gUnknown_08edd54c[], gUnknown_0816fa0c[];
extern const Position gUnknown_0816faf4;
extern const u16 gUnknown_08158b94[], gUnknown_08132754[], gUnknown_0816f98c[];
u8 FUN_08020500(u16 *, const u16 *, u16);
void FUN_0803b82c(Node *), FUN_0803be04(Node *), FUN_0803bf68(Node *);
void FUN_0801fed8(u8, u32), FUN_0801fba0(u16, u16);
void FUN_0803bd8c(Node *node) {
    register u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_08158b94, 48) == 0;

    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_08132754, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_0816f98c, 64) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (!result)
        node->callback = FUN_0803b82c;
}
void FUN_0803be04(Node *node) {
    node->position->x = gUnknown_030052f8 + 120;
    node->position->y =
        gUnknown_08edd540[gUnknown_030052e0] - gUnknown_030052e4 - gUnknown_030052f8;
    if (gUnknown_030052f8)
        FUN_0801fed8(node->index, 0);
}
void FUN_0803be50(Node *node) {
    node->position->parts = gUnknown_0816fa0c;
    node->position->tile = 0;
    node->position->x = 120;
    node->position->y = gUnknown_08edd540[gUnknown_030052e0] - gUnknown_030052e4;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 8;
    node->callback = FUN_0803be04;
}
void FUN_0803bea8(void) {
    u8 *state = &gUnknown_030052e4;
    const u8 *targets = gUnknown_08edd54c;
    const u8 *indexPointer = &gUnknown_030052e0;
    const u8 *targetPointer = (const u8 *)(u32)*indexPointer;
    targetPointer += (u32)targets;
    register u32 current asm("r1") = *state;
    register u32 comparison = current;
    u8 target = *targetPointer;
    u8 *savedState = state;
    register u32 result asm("r0");
    if (comparison < target)
        result = current + 1;
    else if (comparison > target)
        result = current - 1;
    else
        goto unchanged;
    *savedState = result;
unchanged:
    FUN_0801fba0(22, *savedState);
    FUN_0801fba0(26, *savedState);
}
void FUN_0803bef0(Node *node) {
    register u8 *allocation asm("r3") = (u8 *)node->allocation;
    register Position *graphics = (Position *)(allocation + 16);
    *graphics = gUnknown_0816faf4;
    u8 graphicsOffset = -(gUnknown_030052e8[gUnknown_030052e0] + 12);
    u16 tile = 0;
    allocation[21] = graphicsOffset;
    Position *position = node->position;

    allocation += 16;
    position->parts = allocation;
    register u32 zero = 0;
    position->tile = tile;
    node->position->x = 207;
    node->position->y = gUnknown_08edd554.values[gUnknown_030052e0] - gUnknown_030052e4;
    node->position->attr0 = zero;
    node->position->attr1 = zero;
    node->position->attr2 = 4;
    node->callback = FUN_0803bf68;
}
void FUN_0803bf68(Node *node) {
    Node *owner = node;
    u8 *allocation = (u8 *)owner->allocation;
    const u8 *graphicsOffsets = gUnknown_030052e8;
    u8 *indexPointer = &gUnknown_030052e0;
    const u8 *graphicsOffsetPointer = (const u8 *)(u32)*indexPointer;
    graphicsOffsetPointer += (u32)graphicsOffsets;
    register u32 value asm("r0") = *graphicsOffsetPointer;
    value += 12;
    value = -value;
    allocation[21] = value;
    Position *position = owner->position;
    u8 *fadePointer = &gUnknown_030052f8;
    value = *fadePointer;
    value += 199;
    position->x = value;
    Position *savedPosition = owner->position;
    value = gUnknown_08edd554.values[*indexPointer];
    value += 8;
    value -= *fadePointer;
    value -= gUnknown_030052e4;
    savedPosition->y = value;
    if (*indexPointer <= 3)
        FUN_0801fed8(owner->index, 0);
}
}

extern "C" {
extern const u8 gUnknown_0816fae4[], gUnknown_0816fb04[];
extern const u16 gUnknown_0816fb24[];
extern const u16 gUnknown_0816fb34[];
extern const u16 gUnknown_0816fb3c[];
extern const u16 gUnknown_0816fb44[];
extern const u16 gUnknown_0816fb50[];
extern const u16 gUnknown_0816fb58[];
extern const u16 gUnknown_0816fb6c[];
extern const u16 gUnknown_0816fb80[];
extern const u16 gUnknown_0816fb90[];
extern const u16 gUnknown_0816fb9c[];
extern const u16 gUnknown_0816fba4[];
extern const u16 gUnknown_0816fbac[];
extern const u16 gUnknown_0816fbbc[];
extern const u16 gUnknown_0816fbcc[];
extern const u16 gUnknown_0816fbe0[];
extern const u16 gUnknown_0816fbe8[];
extern const u16 gUnknown_0816fbf0[];
extern const u16 gUnknown_0816fc04[];
extern const u16 gUnknown_0816fc0c[];
extern const u16 gUnknown_0816fc18[];
extern const u16 gUnknown_0816fc38[];
extern const u16 gUnknown_0816fc48[];
extern const u16 gUnknown_0816fc64[];
extern const u16 gUnknown_0816fc88[];
extern const u16 gUnknown_0816fca0[];
extern const u16 gUnknown_0816fcac[];
extern const u16 gUnknown_0816fcb4[];
extern const u16 gUnknown_0816fcc0[];
extern const u16 gUnknown_0816fcdc[];
extern const u16 gUnknown_0816fcf8[];
extern const u16 gUnknown_0816fd14[];
extern const u16 gUnknown_0816fd1c[];
extern const u16 gUnknown_0816fd2c[];
extern const u16 gUnknown_0816fd44[];
extern const u16 gUnknown_0816fd4c[];
extern const u16 gUnknown_0816fd58[];
extern const u16 gUnknown_0816fd78[];
extern const u16 gUnknown_0816fd88[];
extern const u16 gUnknown_0816fdb4[];
extern const u16 gUnknown_0816fde0[];
extern const u16 gUnknown_0816fdfc[];
extern const u16 gUnknown_0816fe0c[];
extern const u16 gUnknown_0816fe1c[];
extern const u16 gUnknown_0816fe2c[];
extern const u16 gUnknown_0816fe48[];
extern const u16 gUnknown_0816fe64[];
extern const u16 gUnknown_0816fe80[];
extern const u16 gUnknown_0816fe8c[];
extern const u16 gUnknown_0816fe98[];
extern const u16 gUnknown_0816feac[];
extern const u16 gUnknown_0816feb4[];
extern const u16 gUnknown_0816fec4[];
extern const u16 gUnknown_0816fee4[];
extern const u16 gUnknown_0816fef4[];
extern const u16 gUnknown_0816ff14[];
extern const u16 gUnknown_0816ff38[];
extern const u16 gUnknown_0816ff54[];
extern const u16 gUnknown_0816ff64[];
extern const u16 gUnknown_0816ff70[];
extern const u16 gUnknown_0816ff80[];
extern const u16 gUnknown_0816ff9c[];
extern const u16 gUnknown_0816ffb8[];
extern const u16 gUnknown_0816ffd4[];
extern const u16 gUnknown_0816ffe0[];
extern const u16 gUnknown_0816fff0[];
extern const u16 gUnknown_08170004[];
extern const u16 gUnknown_0817000c[];
extern const u16 gUnknown_08170018[];
extern const u16 gUnknown_0817003c[];
extern const u16 gUnknown_0817004c[];
extern const u16 gUnknown_08170074[];
extern const u16 gUnknown_081700a0[];
extern const u16 gUnknown_081700bc[];
extern const u16 gUnknown_081700cc[];
extern const u16 gUnknown_081700dc[];
extern const u16 gUnknown_081700f4[];
extern const u16 gUnknown_08170110[];
extern const u16 gUnknown_0817012c[];
extern const u16 gUnknown_0817014c[];
extern const u16 gUnknown_08170158[];
extern const u16 gUnknown_08170168[];
extern const u16 gUnknown_08170180[];
extern const u16 gUnknown_08170188[];
extern const u16 gUnknown_08170198[];
extern const u16 gUnknown_081701bc[];
extern const u16 gUnknown_081701cc[];
extern const u16 gUnknown_081701f8[];
extern const u16 gUnknown_0817022c[];
extern const u16 gUnknown_0817024c[];
extern const u16 gUnknown_08170258[];
extern const u16 gUnknown_08170264[];
extern const u16 gUnknown_08170274[];
extern const u16 gUnknown_08170294[];
extern const u16 gUnknown_081702b4[];
extern const u16 gUnknown_081702d8[];
extern const u16 gUnknown_081702e4[];
extern const u16 gUnknown_081702f0[];
extern const u16 gUnknown_081702fc[];
extern const u16 gUnknown_08170308[];
extern const u16 gUnknown_0817031c[];
extern const u16 gUnknown_0817032c[];
extern const u16 gUnknown_08170338[];
extern const u16 gUnknown_08170340[];
extern const u16 gUnknown_0817034c[];
extern const u16 gUnknown_08170358[];
extern const u16 gUnknown_08170364[];
extern const u16 gUnknown_08170370[];
extern const u16 gUnknown_0817037c[];
extern const u16 gUnknown_08170388[];
extern const u16 gUnknown_08170394[];
extern const u16 gUnknown_081703a0[];
extern const u16 gUnknown_081703ac[];
extern const u16 gUnknown_081703b4[];
extern const u16 gUnknown_081703c0[];
extern const u16 gUnknown_081703c8[];
extern const u16 gUnknown_081703d0[];
extern const Position gUnknown_08edd344[2] = {{gUnknown_0816fae4, 72, 16, 97, 0, 0, 0, 0, 0, 0},
                                              {gUnknown_0816fb04, 192, 12, 161, 0, 0, 0, 0, 0, 0}};
extern const u16 gUnknown_08edd364[5] = {70, 86, 118, 150, 182};
extern const u16 *const gUnknown_08edd370[16] = {
    gUnknown_0816fb24, gUnknown_0816fb34, gUnknown_0816fb3c, gUnknown_0816fb44,
    gUnknown_0816fb50, gUnknown_0816fb58, gUnknown_0816fb6c, gUnknown_0816fb80,
    gUnknown_0816fb90, gUnknown_0816fb9c, gUnknown_0816fba4, gUnknown_0816fbac,
    gUnknown_0816fbbc, gUnknown_0816fbcc, gUnknown_0816fbe0, gUnknown_0816fbe8};
extern const u16 *const gUnknown_08edd3b0[16] = {
    gUnknown_0816fbf0, gUnknown_0816fc04, gUnknown_0816fc0c, gUnknown_0816fc18,
    gUnknown_0816fc38, gUnknown_0816fc48, gUnknown_0816fc64, gUnknown_0816fc88,
    gUnknown_0816fca0, gUnknown_0816fcac, gUnknown_0816fcb4, gUnknown_0816fcc0,
    gUnknown_0816fcdc, gUnknown_0816fcf8, gUnknown_0816fd14, gUnknown_0816fd1c};
extern const u16 *const gUnknown_08edd3f0[16] = {
    gUnknown_0816fd2c, gUnknown_0816fd44, gUnknown_0816fd4c, gUnknown_0816fd58,
    gUnknown_0816fd78, gUnknown_0816fd88, gUnknown_0816fdb4, gUnknown_0816fde0,
    gUnknown_0816fdfc, gUnknown_0816fe0c, gUnknown_0816fe1c, gUnknown_0816fe2c,
    gUnknown_0816fe48, gUnknown_0816fe64, gUnknown_0816fe80, gUnknown_0816fe8c};
extern const u16 *const gUnknown_08edd430[16] = {
    gUnknown_0816fe98, gUnknown_0816feac, gUnknown_0816feb4, gUnknown_0816fec4,
    gUnknown_0816fee4, gUnknown_0816fef4, gUnknown_0816ff14, gUnknown_0816ff38,
    gUnknown_0816ff54, gUnknown_0816ff64, gUnknown_0816ff70, gUnknown_0816ff80,
    gUnknown_0816ff9c, gUnknown_0816ffb8, gUnknown_0816ffd4, gUnknown_0816ffe0};
extern const u16 *const gUnknown_08edd470[16] = {
    gUnknown_0816fff0, gUnknown_08170004, gUnknown_0817000c, gUnknown_08170018,
    gUnknown_0817003c, gUnknown_0817004c, gUnknown_08170074, gUnknown_081700a0,
    gUnknown_081700bc, gUnknown_081700cc, gUnknown_081700dc, gUnknown_081700f4,
    gUnknown_08170110, gUnknown_0817012c, gUnknown_0817014c, gUnknown_08170158};
extern const u16 *const gUnknown_08edd4b0[16] = {
    gUnknown_08170168, gUnknown_08170180, gUnknown_08170188, gUnknown_08170198,
    gUnknown_081701bc, gUnknown_081701cc, gUnknown_081701f8, gUnknown_0817022c,
    gUnknown_0817024c, gUnknown_08170258, gUnknown_08170264, gUnknown_08170274,
    gUnknown_08170294, gUnknown_081702b4, gUnknown_081702d8, gUnknown_081702e4};
extern const u16 *const gUnknown_08edd4f0[10] = {
    gUnknown_081702f0, gUnknown_081702fc, gUnknown_08170308, gUnknown_0817031c, gUnknown_0817032c,
    gUnknown_08170338, gUnknown_08170340, gUnknown_0817034c, gUnknown_08170358, gUnknown_08170364};
extern const u16 *const gUnknown_08edd518[10] = {
    gUnknown_08170370, gUnknown_0817037c, gUnknown_08170388, gUnknown_08170394, gUnknown_081703a0,
    gUnknown_081703ac, gUnknown_081703b4, gUnknown_081703c0, gUnknown_081703c8, gUnknown_081703d0};
extern const u16 gUnknown_08edd540[5] = {48, 64, 96, 128, 160};
extern const u8 gUnknown_08edd54c[5] __attribute__((aligned(4))) = {0, 4, 13, 22, 32};
extern const AlignedFive gUnknown_08edd554 = {{52, 68, 100, 132, 164}};
extern const u16 gUnknown_0816ebec[32] __attribute__((section(".rodata.layout"))) = {
    0,  0, 8,  0x1f00, 16, 0,      18, 0, 10, 0x1e09, 20, 0,      22, 0,      12, 0x1d01,
    24, 0, 26, 0,      14, 0x1c0b, 28, 0, 30, 0,      80, 0x3f41, 82, 0x0808, 84, 0};
extern const Label gUnknown_0816ec2c[16] __attribute__((section(".rodata.layout"))) = {
    {0, 6, 0, 0},     {16, 22, 1, 0},   {16, 38, 2, 0},   {0, 54, 3, 0},
    {16, 70, 4, 0},   {0, 86, 5, 0},    {16, 102, 14, 0}, {0, 118, 6, 0},
    {160, 70, 7, 1},  {160, 70, 8, 1},  {160, 70, 9, 1},  {160, 70, 10, 1},
    {160, 70, 11, 1}, {160, 70, 12, 1}, {160, 70, 13, 1}, {160, 134, 15, 1}};
}

extern "C" {
u8 gUnknown_030053e0 __attribute__((section(".bss"))) = 0;
const u16 *const *gUnknown_030053e4 __attribute__((section(".bss.state_30053e4"))) = 0;
u8 gUnknown_030053e8 __attribute__((section(".bss.state_30053e8"))) = 0;
const u16 *const *gUnknown_030053ec __attribute__((section(".bss.state_30053ec"))) = 0;
u8 gUnknown_030053f0 __attribute__((section(".bss.state_30053f0"))) = 0;
u8 gUnknown_030053f4 __attribute__((section(".bss.state_30053f4"))) = 0;
u8 gUnknown_030053f8 __attribute__((section(".bss.state_30053f8"))) = 0;
u8 gUnknown_030053fc __attribute__((section(".bss.state_30053fc"))) = 0;
const u16 *const *gUnknown_03005400 __attribute__((section(".bss.state_3005400"))) = 0;
}
