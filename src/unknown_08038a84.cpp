// C++ reconstruction fallback; original source language and linkage are unknown.
// Full inferred TU; scope and preserved quirks: docs/scene-38a84-tu-cpp.md.
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
extern u16 gUnknown_030053c0[];
extern const u16 *const *gUnknown_030053bc;
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
}
static inline u16 *append(u16 *destination, const u16 *source) {
    while (*source != 0xfffe)
        *destination++ = *source++;
    return destination;
}
extern "C" {
void FUN_08038a84(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 0x157529ff)
        value = 0x157529ff;
    u32 hours = value / 3600;
    u32 minutes = (value % 3600) / 60;
    u32 seconds = value % 60;
    register u16 *buffer = gUnknown_030053c0;
    u16 *destination = buffer;
    if (hours) {
        if (hours > 9999)
            *destination++ = hours / 10000 + 16;
        if (hours > 999)
            *destination++ = (hours % 10000) / 1000 + 16;
        if (hours > 99)
            *destination++ = (hours % 1000) / 100 + 16;
        if (hours > 9)
            *destination++ = (hours % 100) / 10 + 16;
        *destination++ = hours % 10 + 16;
        destination = append(destination, gUnknown_030053bc[16]);
    }
    if (hours || minutes) {
        u32 digit = minutes > 9 ? minutes / 10 + 16 : 0;
        *destination++ = digit;
        *destination++ = minutes % 10 + 16;
        destination = append(destination, gUnknown_030053bc[17]);
    }
    u32 digit = seconds > 9 ? seconds / 10 + 16 : 0;
    *destination++ = digit;
    *destination++ = seconds % 10 + 16;
    destination = append(destination, gUnknown_030053bc[22]);
    *destination = 0xfffe;
    u8 x = xPosition;
    u8 y = yPosition;
    register const u16 *text asm("r6") = buffer;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
static inline u16 *appendFinal(u16 *destination, const u16 *source) {
    register const u16 *initial = source;

    const u16 *input = initial;
    while (*input != 0xfffe)
        *destination++ = *input++;
    return destination;
}
extern "C" {
void FUN_08038c74(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 0x157529ff)
        value = 0x157529ff;
    u32 hours = value / 3600;
    u32 minutes = (value % 3600) / 60;
    register u16 *buffer = gUnknown_030053c0;
    u16 *destination = buffer;
    register const u16 *const **initial asm("r1") = &gUnknown_030053bc;

    register const u16 *const **tableAddress = initial;
    if (hours) {

        if (hours > 9999)
            *destination++ = hours / 10000 + 16;
        if (hours > 999)
            *destination++ = (hours % 10000) / 1000 + 16;
        if (hours > 99)
            *destination++ = (hours % 1000) / 100 + 16;
        if (hours > 9)
            *destination++ = (hours % 100) / 10 + 16;
        *destination++ = hours % 10 + 16;
        register const u16 *const **address = tableAddress;
        destination = append(destination, (*address)[16]);
    }
    u32 digit = minutes > 9 ? minutes / 10 + 16 : 0;
    *destination++ = digit;
    *destination++ = minutes % 10 + 16;
    register const u16 *const **address = tableAddress;
    destination = appendFinal(destination, (*address)[17]);
    u32 sentinelInitial = 0xfffe;
    register u32 sentinel asm("r4") = sentinelInitial;
    *destination = sentinel;
    u8 x = xPosition;
    asm("" : : "r"(sentinelInitial), "r"(x));
    u8 y = yPosition;
    register const u16 *text asm("r6") = buffer;
    x -= FUN_08020ad0(text);
    while (*text != sentinel) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}

extern "C" {
void FUN_08038e04(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 99999)
        value = 99999;
    u16 *destination = gUnknown_030053c0;
    if (value > 9999)
        *destination++ = value / 10000 + 16;
    if (value > 999)
        *destination++ = (value % 10000) / 1000 + 16;
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination++ = value % 10 + 16;
    const u16 *suffix = gUnknown_030053bc[18];
    register u32 first = *suffix;
    if (first != 0 && first != 824) {
        register u16 *output asm("r4") = destination;
        if (first != 0xfffe) {
            register u32 sentinel = 0xfffe;
            do {
                *output++ = *suffix++;
            } while (*suffix != sentinel);
        }
        destination = output;
    }
    *destination = 0xfffe;
    u8 x = xPosition;
    u8 y = yPosition;
    const u16 *text = gUnknown_030053c0;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
void FUN_08038f30(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 99999)
        value = 99999;
    register u16 *initial asm("r5") = gUnknown_030053c0;

    register u32 threshold = 9999;

    register u16 *buffer asm("r6") = initial;
    u16 *destination = initial;
    if (value > threshold) {
        *buffer = value / 10000 + 16;
        destination = buffer + 1;
    }
    if (value > 999)
        *destination++ = (value % 10000) / 1000 + 16;
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination = value % 10 + 16;
    register const u16 *const *table = gUnknown_030053bc;
    register u16 *output asm("r1") = destination + 1;

    register const u16 *suffix = table[19];
    register u32 glyph = *suffix;
    register u32 sentinel = 0xfffe;
    while (glyph != sentinel) {
        *output = glyph;
        ++suffix;
        ++output;
        glyph = *suffix;
    }
    *output = 0xfffe;
    u8 x = xPosition;
    u8 y = yPosition;
    const u16 *text = buffer;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
void FUN_08039044(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 99999)
        value = 99999;
    u16 *destination = gUnknown_030053c0;
    if (value > 9999)
        *destination++ = value / 10000 + 16;
    if (value > 999)
        *destination++ = (value % 10000) / 1000 + 16;
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination++ = value % 10 + 16;
    const u16 *suffix = gUnknown_030053bc[20];
    register u32 first = *suffix;
    if (first != 0 && first != 824) {
        register u16 *output asm("r4") = destination;
        if (first != 0xfffe) {
            register u32 sentinel = 0xfffe;
            do {
                *output++ = *suffix++;
            } while (*suffix != sentinel);
        }
        destination = output;
    }
    *destination = 0xfffe;
    u8 x = xPosition;
    u8 y = yPosition;
    const u16 *text = gUnknown_030053c0;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
void FUN_08039170(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 9999)
        value = 9999;
    register u16 *initial asm("r5") = gUnknown_030053c0;

    register u32 threshold = 999;

    register u16 *buffer asm("r6") = initial;
    u16 *destination = initial;
    if (value > threshold) {
        *buffer = value / 1000 + 16;
        destination = buffer + 1;
    }
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination = value % 10 + 16;
    register const u16 *const *table = gUnknown_030053bc;
    register u16 *output asm("r1") = destination + 1;

    register const u16 *suffix = table[21];
    register u32 glyph = *suffix;
    register u32 sentinel = 0xfffe;
    while (glyph != sentinel) {
        *output = glyph;
        ++suffix;
        ++output;
        glyph = *suffix;
    }
    *output = 0xfffe;
    u8 x = xPosition;
    u8 y = yPosition;
    const u16 *text = buffer;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
void FUN_08039260(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 999999)
        value = 999999;
    register u16 *initial asm("r5") = gUnknown_030053c0;

    register u32 threshold = 99999;

    register u16 *buffer asm("r6") = initial;
    u16 *destination = initial;
    if (value > threshold) {
        *buffer = value / 100000 + 16;
        destination = buffer + 1;
    }
    if (value > 9999)
        *destination++ = (value % 100000) / 10000 + 16;
    if (value > 999)
        *destination++ = (value % 10000) / 1000 + 16;
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination = value % 10 + 16;
    destination[1] = 0xfffe;
    u32 xBits = (u32)xPosition << 24;
    u32 yBits = (u32)yPosition << 24;
    asm("" : "+r"(xBits), "+r"(yBits));
    u8 x = xBits >> 24;
    u8 y = yBits >> 24;
    const u16 *text = buffer;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
void FUN_08039374(u32 value, u16 xPosition, u16 yPosition, u8 color, u32 unusedArgument) {
    if (value > 999999)
        value = 999999;
    u16 *destination = gUnknown_030053c0;
    if (value > 99999)
        *destination++ = value / 100000 + 16;
    if (value > 9999)
        *destination++ = (value % 100000) / 10000 + 16;
    if (value > 999)
        *destination++ = (value % 10000) / 1000 + 16;
    if (value > 99)
        *destination++ = (value % 1000) / 100 + 16;
    if (value > 9)
        *destination++ = (value % 100) / 10 + 16;
    *destination++ = value % 10 + 16;
    const u16 *const *table = gUnknown_030053bc;
    u32 first = *table[20];
    register u32 xBits asm("r2") = (u32)xPosition << 24;
    register u32 yBits = (u32)yPosition << 24;

    if (first != 0 && first != 824) {
        u16 *output = destination;
        const u16 *suffix = table[23];
        while (*suffix != 0xfffe)
            *output++ = *suffix++;
        destination = output;
    }
    *destination = 0xfffe;
    u8 x = xBits >> 24;
    u8 y = yBits >> 24;
    const u16 *text = gUnknown_030053c0;
    x -= FUN_08020ad0(text);
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
}
extern "C" {
extern const u16 *const *gUnknown_030053bc, *const *gUnknown_030053ec;
extern u32 gUnknown_03002110[];
extern u32 gUnknown_030053b0;
extern u8 gUnknown_030053b4, gUnknown_030053b8;
extern unsigned long long gUnknown_03002610;
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_08038c74(u32, u16, u16, u8, u32);
void FUN_08038e04(u32, u16, u16, u8, u32);
void FUN_08038f30(u32, u16, u16, u8, u32);
void FUN_08039044(u32, u16, u16, u8, u32);
void FUN_08039170(u32, u16, u16, u8, u32);
void FUN_08039260(u32, u16, u16, u8, u32);
}
static inline void drawRight(u16 yPosition, u32 selection) {
    register u32 yBits = (u32)yPosition << 24;
    register u32 index asm("r1") = selection;
    register const u16 *const *table = gUnknown_030053ec;
    index <<= 2;
    index += (u32)table;

    register u32 x = 204;
    register u32 y = yBits >> 24;
    register const u16 *text = *(const u16 **)index;
    register u32 result = x - FUN_08020ad0(text);

    x = (u8)result;
    while (*text != 0xfffe) {
        result = x + FUN_08020978(x, y, *text, 2);

        x = (u8)result;
        ++text;
    }
}
extern "C" {
void FUN_080394c0(u8 selection) {
    u32 savedSelection = selection;

    register u32 label = selection;
    u16 y = 6;
    register u32 initialRow = 0;
    register u32 row asm("r12") = initialRow;
    do {
        register u32 yBits = y << 24;
        register const u16 *const *table = gUnknown_030053bc;
        register u32 index = label << 2;
        index += (u32)table;

        register u32 x = 4;
        register u32 drawY = yBits >> 24;

        register const u16 *text = *(const u16 **)index;
        register u32 glyph = *text;

        register u32 nextY = y + 16;
        register u32 nextLabel = label + 1;
        register u32 nextRowInitial = 1;
        nextRowInitial += row;
        register u32 nextRow = nextRowInitial;
        register u32 sentinelInitial asm("r2") = 0xfffe;
        if (glyph != sentinelInitial) {
            register u32 sentinel = sentinelInitial;
            do {
                register u32 result = x + FUN_08020978(x, drawY, *text, 2);

                x = (u8)result;
                ++text;
            } while (*text != sentinel);
        }
        register u32 yValue asm("r1") = nextY;
        asm("" : "+r"(yValue));
        register u32 yCast asm("r0") = yValue << 16;
        asm("" : "+r"(yCast));
        y = yCast >> 16;
        register u32 labelInitial = nextLabel;

        register u32 labelValue = labelInitial << 24;

        label = labelValue >> 24;
        register u32 rowValue = nextRow;

        register u32 rowCast = rowValue << 16;

        row = rowCast >> 16;
    } while (row <= 5);
    y = 6;
    register u32 selectedInitial asm("r2") = savedSelection;
    asm("" : "+r"(selectedInitial));
    u32 selected = selectedInitial;
    switch (selected) {
    case 0: {
        u32 seconds;
        if (gUnknown_03002610 > 0x50775d7ffULL)
            seconds = 0x157529ff;
        else
            seconds = gUnknown_03002610 / 60;
        FUN_08038c74(seconds, 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    }
    case 1:
        FUN_08038c74(gUnknown_03002110[2], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 2:
        FUN_08038e04(gUnknown_03002110[3], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 3:
        FUN_08038e04(gUnknown_03002110[4], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 4:
        FUN_08038e04(gUnknown_03002110[5], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 5:
        FUN_08038e04(gUnknown_03002110[6], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 6:
        FUN_08038f30(gUnknown_03002110[7], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 7:
        FUN_08038f30(gUnknown_03002110[8], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 8:
        FUN_08039044(gUnknown_03002110[9], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 9:
        FUN_08038e04(gUnknown_03002110[10], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 10:
        FUN_08038e04(gUnknown_03002110[11], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 11:
        FUN_08039260(gUnknown_03002110[12], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 12:
        FUN_08039260(gUnknown_03002110[13], 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 13:
        FUN_08039170(gUnknown_030053b0, 204, y, 2, 1);
        y = (u16)(y + 16);
        if (y > 95)
            break;
    case 14: {
        register const u8 *choiceAddress asm("r1") = &gUnknown_030053b4;

        register u32 choice = *choiceAddress;

        register u32 followingInitial = 16;
        followingInitial += y;

        register u32 followingY asm("r10") = followingInitial;
        if (choice <= 8)
            drawRight(y, *choiceAddress);
        y = (u16)followingY;
        if (y > 95)
            break;
    }
    case 15:
        if (gUnknown_030053b8 <= 8)
            drawRight(y, gUnknown_030053b8);
        break;
    }
}
}
extern "C" {
extern u8 gUnknown_030052e0, gUnknown_03002230[];
extern u32 gUnknown_030053b0;
extern u8 gUnknown_030053b4, gUnknown_030053b8;
extern const u16 *const *gUnknown_030053bc, *const *gUnknown_030053ec;
extern const u16 *const gUnknown_08edd518[], *const gUnknown_08edd4f0[];
extern const u16 *const *const gUnknown_08edd2ec[];
extern const u16 gUnknown_0815a0ac[], gUnknown_081327d4[];
extern const u8 gUnknown_0815a0ec[], gUnknown_08132544[], gUnknown_0815a420[], gUnknown_0815a4a0[],
    gUnknown_0815a860[], gUnknown_0815a360[], gUnknown_0815a2a8[], gUnknown_08071b7c[],
    gUnknown_0807173c[];
extern const Position gUnknown_08edcf00[3];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_080217d0(u8);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void FUN_080394c0(u8);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d20(Node *), FUN_08039d28(Node *), FUN_0801f9d8(Node *);
void FUN_08039da0(Node *), FUN_08039dbc(Node *), FUN_08039c5c(void);
void FUN_0801fba0(u16, u16), FUN_0801f618(u32);
void FUN_0803984c(void) {
    FUN_080217d0(0);
    gUnknown_030052e0 = 0;
    register u32 count asm("r6") = 0;
    register u32 i asm("r5") = 0;
    do {
        if (gUnknown_03002230[i] != 255)
            ++count;
        ++i;
    } while (i <= 308);
    gUnknown_030053b0 = count * 100 / 309;
    if (gUnknown_030053b0 > 100)
        gUnknown_030053b0 = 100;
    register u8 *maximumAddress asm("r2") = &gUnknown_030053b4;
    *maximumAddress = 0;
    register u8 *minimumAddress = &gUnknown_030053b8;
    *minimumAddress = 0;
    i = 1;
    register u32 maximum asm("r6") = 0;
    register u32 minimum = 0;
    register const u16 *registers = gUnknown_0815a0ac;
    register u8 *save = (u8 *)gUnknown_03002110;
    register u32 valuesInitial = 60;
    valuesInitial += (u32)save;
    register u32 *values = (u32 *)valuesInitial;
    register u8 *maxOut asm("r12") = maximumAddress;
    u32 tie = 255;
    register u8 *minOut asm("r2") = minimumAddress;
    register u32 *current = (u32 *)(save + 64);
    do {
        register u32 offset asm("r0") = maximum << 2;
        register u32 *base = values;
        register u32 *selected = (u32 *)(offset + (u32)base);
        if (*selected == *current)
            *maxOut = tie;
        if (*selected < *current) {
            maximum = i;
            register u8 *output asm("r1") = maxOut;
            *output = i;
        }
        register u32 minimumInitial = minimum;
        offset = minimumInitial << 2;
        base = values;
        selected = (u32 *)(offset + (u32)base);
        if (*selected == *current)
            *minOut = tie;
        if (*selected > *current) {
            minimum = i;
            *minOut = i;
        }
        ++current;
        ++i;
    } while (i <= 8);
    FUN_0801fbfc(registers, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_0815a0ec, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x06004000);
    LZ77UnCompVram(gUnknown_0815a420, (void *)0x06010000);
    register u8 *languageSave = (u8 *)gUnknown_03002110;

    switch (languageSave[119]) {
    case 0:
        gUnknown_030053ec = gUnknown_08edd518;
        LZ77UnCompVram(gUnknown_0815a4a0, (void *)0x06010100);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        gUnknown_030053ec = gUnknown_08edd4f0;
        LZ77UnCompVram(gUnknown_0815a860, (void *)0x06010100);
        break;
    }
    register const u16 *const **tableAddress = &gUnknown_030053bc;
    register const u16 *const *const *languageTables = gUnknown_08edd2ec;
    register u8 *tableSave = (u8 *)gUnknown_03002110;

    *tableAddress = languageTables[tableSave[119]];
    u32 mapZero = 0;
    CpuFastSet(&mapZero, (void *)0x0600f800, 0x01000200);
    LZ77UnCompVram(gUnknown_0815a360, (void *)0x0600f800);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    u32 tileZero = 0;
    CpuFastSet(&tileZero, (void *)0x06008000, 0x01000b68);
    register u16 *column asm("r2") = (u16 *)0x0600f104;
    u16 tile = 0x2001;
    register u32 x = 0;
    do {
        register u32 y = 0;
        register u16 *nextColumn asm("r5") = column + 1;
        register u32 nextX = x + 1;
        do {
            *column = tile++;
            column += 32;
            ++y;
        } while (y <= 13);
        column = nextColumn;
        x = nextX;
    } while (x <= 25);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 26, 14, 0);
    FUN_080394c0(0);
    u32 finalZero = 0;
    CpuFastSet(&finalZero, (void *)0x0600e800, 0x01000200);
    LZ77UnCompVram(gUnknown_0815a2a8, (void *)0x0600e900);
    register u16 *destination asm("r4") = (u16 *)0x0600e000;
    register u32 outerRow asm("r5") = 0;
    do {
        register u32 innerColumn = 0;
        ++outerRow;
        do {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf200);
            destination += 8;
            ++innerColumn;
        } while (innerColumn <= 3);
        destination += 224;
    } while (outerRow <= 3);
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08039d28, 0, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcf00[0];
    node = FUN_0801f7d0(FUN_08039da0, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcf00[1];
    node = FUN_0801f7d0(FUN_08039dbc, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcf00[2];
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08039c5c;
    FUN_0801f618(4);
}
}
extern "C" {
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void CpuFastSet(const void *, void *, u32);
void FUN_0801f89c(void);
void FUN_0801fda0(void);
void FUN_0801f718(u32, u32);
void FUN_0801f618(u32);
void FUN_080394c0(u8);
u8 FUN_0802067c(u16 *, u32);
u8 FUN_08020500(u16 *, const u16 *, u32);
void FUN_0801fed8(u8, u32);
void FUN_08039e20(void);
void FUN_08039d00(Node *);
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_030052e0;
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_0815a3c0[], gUnknown_08132794[], gUnknown_0815abe8[];

void FUN_08039bac(u8 x, u8 y, const u16 *text, u8 color, u8 alignment) {
    switch (alignment) {
    case 1:
        x -= FUN_08020ad0(text);
        break;
    case 2:
        x -= FUN_08020ad0(text) >> 1;
        break;
    }
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, color);
        ++text;
    }
}
u16 *FUN_08039c1c(u16 *destination, const u16 *source) {
    while (*source != 0xfffe) {
        *destination++ = *source++;
    }
    return destination;
}
void FUN_08039c3c(void) {
    u32 zero = 0;
    CpuFastSet(&zero, (void *)0x06008000, 0x01000b68);
}
void FUN_08039c5c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_08039c6c(Node *node) {
    if (gUnknown_030048e0[2] & 3) {
        node->callback = FUN_08039d00;
        FUN_0801f718(4, 120);
        FUN_0801f618(405);
    } else if (gUnknown_030048e0[4] & 64) {
        if (gUnknown_030052e0) {
            --gUnknown_030052e0;
            FUN_08039c3c();
            FUN_080394c0(gUnknown_030052e0);
            FUN_0801f618(401);
        }
    } else if (gUnknown_030048e0[4] & 128) {
        if (gUnknown_030052e0 <= 9) {
            ++gUnknown_030052e0;
            FUN_08039c3c();
            FUN_080394c0(gUnknown_030052e0);
            FUN_0801f618(401);
        }
    }
}
void FUN_08039d00(Node *) {
    if (FUN_0802067c((u16 *)0x05000000, 512))
        gUnknown_03002030 = FUN_08039e20;
}
void FUN_08039d28(Node *node) {
    register u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_0815a3c0, 48) == 0;
    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_08132794, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_0815abe8, 32) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (!result)
        node->callback = FUN_08039c6c;
}
void FUN_08039da0(Node *node) {
    if (gUnknown_030052e0)
        FUN_0801fed8(node->index, 0);
}
void FUN_08039dbc(Node *node) {
    if (gUnknown_030052e0 <= 9)
        FUN_0801fed8(node->index, 0);
}
}

extern "C" {
extern const u16 gUnknown_0815ac40[];
extern const u16 gUnknown_0815ac50[];
extern const u16 gUnknown_0815ac60[];
extern const u16 gUnknown_0815ac6c[];
extern const u16 gUnknown_0815ac7c[];
extern const u16 gUnknown_0815ac90[];
extern const u16 gUnknown_0815aca0[];
extern const u16 gUnknown_0815acac[];
extern const u16 gUnknown_0815acbc[];
extern const u16 gUnknown_0815acc8[];
extern const u16 gUnknown_0815acdc[];
extern const u16 gUnknown_0815acf0[];
extern const u16 gUnknown_0815ad04[];
extern const u16 gUnknown_0815ad18[];
extern const u16 gUnknown_0815ad28[];
extern const u16 gUnknown_0815ad38[];
extern const u16 gUnknown_0815ad4c[];
extern const u16 gUnknown_0815ad54[];
extern const u16 gUnknown_0815ad58[];
extern const u16 gUnknown_0815ad5c[];
extern const u16 gUnknown_0815ad64[];
extern const u16 gUnknown_0815ad6c[];
extern const u16 gUnknown_0815ad70[];
extern const u16 gUnknown_0815ad74[];
extern const u16 gUnknown_0815ad78[];
extern const u16 gUnknown_0815ad84[];
extern const u16 gUnknown_0815ad88[];
extern const u16 gUnknown_0815ad98[];
extern const u16 gUnknown_0815ad9c[];
extern const u16 gUnknown_0815ada8[];
extern const u16 gUnknown_0815adac[];
extern const u16 gUnknown_0815adbc[];
extern const u16 gUnknown_0815adc0[];
extern const u16 gUnknown_0815adcc[];
extern const u16 gUnknown_0815ade4[];
extern const u16 gUnknown_0815adf8[];
extern const u16 gUnknown_0815ae0c[];
extern const u16 gUnknown_0815ae18[];
extern const u16 gUnknown_0815ae2c[];
extern const u16 gUnknown_0815ae3c[];
extern const u16 gUnknown_0815ae54[];
extern const u16 gUnknown_0815ae74[];
extern const u16 gUnknown_0815ae98[];
extern const u16 gUnknown_0815aeb4[];
extern const u16 gUnknown_0815aed4[];
extern const u16 gUnknown_0815aef8[];
extern const u16 gUnknown_0815af18[];
extern const u16 gUnknown_0815af38[];
extern const u16 gUnknown_0815af68[];
extern const u16 gUnknown_0815af8c[];
extern const u16 gUnknown_0815afac[];
extern const u16 gUnknown_0815afd0[];
extern const u16 gUnknown_0815b000[];
extern const u16 gUnknown_0815b02c[];
extern const u16 gUnknown_0815b058[];
extern const u16 gUnknown_0815b080[];
extern const u16 gUnknown_0815b0ac[];
extern const u16 gUnknown_0815b0b4[];
extern const u16 gUnknown_0815b0bc[];
extern const u16 gUnknown_0815b0c0[];
extern const u16 gUnknown_0815b0c8[];
extern const u16 gUnknown_0815b0cc[];
extern const u16 gUnknown_0815b0d0[];
extern const u16 gUnknown_0815b0e0[];
extern const u16 gUnknown_0815b0f0[];
extern const u16 gUnknown_0815b108[];
extern const u16 gUnknown_0815b10c[];
extern const u16 gUnknown_0815b13c[];
extern const u16 gUnknown_0815b140[];
extern const u16 gUnknown_0815b158[];
extern const u16 gUnknown_0815b15c[];
extern const u16 gUnknown_0815b17c[];
extern const u16 gUnknown_0815b180[];
extern const u16 gUnknown_0815b18c[];
extern const u16 gUnknown_0815b1b4[];
extern const u16 gUnknown_0815b1e0[];
extern const u16 gUnknown_0815b208[];
extern const u16 gUnknown_0815b228[];
extern const u16 gUnknown_0815b250[];
extern const u16 gUnknown_0815b264[];
extern const u16 gUnknown_0815b284[];
extern const u16 gUnknown_0815b2ac[];
extern const u16 gUnknown_0815b2cc[];
extern const u16 gUnknown_0815b2f8[];
extern const u16 gUnknown_0815b328[];
extern const u16 gUnknown_0815b35c[];
extern const u16 gUnknown_0815b384[];
extern const u16 gUnknown_0815b3b4[];
extern const u16 gUnknown_0815b3e8[];
extern const u16 gUnknown_0815b418[];
extern const u16 gUnknown_0815b448[];
extern const u16 gUnknown_0815b478[];
extern const u16 gUnknown_0815b4a4[];
extern const u16 gUnknown_0815b4d4[];
extern const u16 gUnknown_0815b500[];
extern const u16 gUnknown_0815b52c[];
extern const u16 gUnknown_0815b558[];
extern const u16 gUnknown_0815b55c[];
extern const u16 gUnknown_0815b564[];
extern const u16 gUnknown_0815b568[];
extern const u16 gUnknown_0815b570[];
extern const u16 gUnknown_0815b574[];
extern const u16 gUnknown_0815b578[];
extern const u16 gUnknown_0815b58c[];
extern const u16 gUnknown_0815b59c[];
extern const u16 gUnknown_0815b5bc[];
extern const u16 gUnknown_0815b5c0[];
extern const u16 gUnknown_0815b5f4[];
extern const u16 gUnknown_0815b5f8[];
extern const u16 gUnknown_0815b618[];
extern const u16 gUnknown_0815b61c[];
extern const u16 gUnknown_0815b644[];
extern const u16 gUnknown_0815b648[];
extern const u16 gUnknown_0815b654[];
extern const u16 gUnknown_0815b674[];
extern const u16 gUnknown_0815b6a0[];
extern const u16 gUnknown_0815b6cc[];
extern const u16 gUnknown_0815b6e8[];
extern const u16 gUnknown_0815b70c[];
extern const u16 gUnknown_0815b728[];
extern const u16 gUnknown_0815b750[];
extern const u16 gUnknown_0815b770[];
extern const u16 gUnknown_0815b790[];
extern const u16 gUnknown_0815b7ac[];
extern const u16 gUnknown_0815b7cc[];
extern const u16 gUnknown_0815b7f0[];
extern const u16 gUnknown_0815b814[];
extern const u16 gUnknown_0815b838[];
extern const u16 gUnknown_0815b868[];
extern const u16 gUnknown_0815b890[];
extern const u16 gUnknown_0815b8bc[];
extern const u16 gUnknown_0815b8f0[];
extern const u16 gUnknown_0815b920[];
extern const u16 gUnknown_0815b950[];
extern const u16 gUnknown_0815b970[];
extern const u16 gUnknown_0815b9a4[];
extern const u16 gUnknown_0815b9d8[];
extern const u16 gUnknown_0815b9e0[];
extern const u16 gUnknown_0815b9e8[];
extern const u16 gUnknown_0815b9ec[];
extern const u16 gUnknown_0815b9f4[];
extern const u16 gUnknown_0815b9f8[];
extern const u16 gUnknown_0815b9fc[];
extern const u16 gUnknown_0815ba10[];
extern const u16 gUnknown_0815ba20[];
extern const u16 gUnknown_0815ba34[];
extern const u16 gUnknown_0815ba38[];
extern const u16 gUnknown_0815ba68[];
extern const u16 gUnknown_0815ba6c[];
extern const u16 gUnknown_0815ba88[];
extern const u16 gUnknown_0815ba8c[];
extern const u16 gUnknown_0815bab4[];
extern const u16 gUnknown_0815bab8[];
extern const u16 gUnknown_0815bac4[];
extern const u16 gUnknown_0815bae4[];
extern const u16 gUnknown_0815bb10[];
extern const u16 gUnknown_0815bb3c[];
extern const u16 gUnknown_0815bb60[];
extern const u16 gUnknown_0815bb88[];
extern const u16 gUnknown_0815bba4[];
extern const u16 gUnknown_0815bbbc[];
extern const u16 gUnknown_0815bbe0[];
extern const u16 gUnknown_0815bc04[];
extern const u16 gUnknown_0815bc1c[];
extern const u16 gUnknown_0815bc3c[];
extern const u16 gUnknown_0815bc6c[];
extern const u16 gUnknown_0815bc98[];
extern const u16 gUnknown_0815bcac[];
extern const u16 gUnknown_0815bcd4[];
extern const u16 gUnknown_0815bd00[];
extern const u16 gUnknown_0815bd2c[];
extern const u16 gUnknown_0815bd58[];
extern const u16 gUnknown_0815bd80[];
extern const u16 gUnknown_0815bda8[];
extern const u16 gUnknown_0815be0c[];
extern const u16 gUnknown_0815be38[];
extern const u16 gUnknown_0815be40[];
extern const u16 gUnknown_0815be48[];
extern const u16 gUnknown_0815be4c[];
extern const u16 gUnknown_0815be54[];
extern const u16 gUnknown_0815be58[];
extern const u16 gUnknown_0815be5c[];
extern const u16 gUnknown_0815be60[];
extern const u16 gUnknown_0815be70[];
extern const u16 gUnknown_0815be94[];
extern const u16 gUnknown_0815be98[];
extern const u16 gUnknown_0815bec0[];
extern const u16 gUnknown_0815bec4[];
extern const u16 gUnknown_0815bee8[];
extern const u16 gUnknown_0815beec[];
extern const u16 gUnknown_0815bf1c[];
extern const u16 gUnknown_0815bf20[];
extern const u16 gUnknown_0815bf2c[];
extern const u16 gUnknown_0815bf58[];
extern const u16 gUnknown_0815bf88[];
extern const u16 gUnknown_0815bfb8[];
extern const u16 gUnknown_0815bfd8[];
extern const u16 gUnknown_0815c004[];
extern const u16 gUnknown_0815c01c[];
extern const u16 gUnknown_0815c038[];
extern const u16 gUnknown_0815c05c[];
extern const u16 gUnknown_0815c080[];
extern const u16 gUnknown_0815c0a0[];
extern const u16 gUnknown_0815c0cc[];
extern const u16 gUnknown_0815c0f8[];
extern const u16 gUnknown_0815c120[];
extern const u16 gUnknown_0815c140[];
extern const u16 gUnknown_0815c168[];
extern const u16 gUnknown_0815c18c[];
extern const u16 gUnknown_0815c1a8[];
extern const u16 gUnknown_0815c1cc[];
extern const u16 gUnknown_0815c1f8[];
extern const u16 gUnknown_0815c224[];
extern const u16 gUnknown_0815c254[];
extern const u16 gUnknown_0815c280[];
extern const u16 gUnknown_0815c2b0[];
extern const u16 gUnknown_0815c2b8[];
extern const u16 gUnknown_0815c2c0[];
extern const u16 gUnknown_0815c2c4[];
extern const u16 gUnknown_0815c2cc[];
extern const u16 gUnknown_0815c2d0[];
extern const u16 gUnknown_0815c2d4[];
extern const u16 gUnknown_0815c2e4[];
extern const u16 gUnknown_0815c2f0[];
extern const u16 gUnknown_0815c310[];
extern const u16 gUnknown_0815c314[];
extern const u16 gUnknown_0815c344[];
extern const u16 gUnknown_0815c348[];
extern const u16 gUnknown_0815c370[];
extern const u16 gUnknown_0815c374[];
extern const u16 gUnknown_0815c398[];
extern const u16 gUnknown_0815c39c[];
extern const u16 gUnknown_0815c3a8[];
extern const u16 gUnknown_0815c3d0[];
extern const u16 gUnknown_0815c3f8[];
extern const u16 gUnknown_0815c420[];
extern const u16 gUnknown_0815c448[];
extern const u16 gUnknown_0815c470[];
extern const u16 gUnknown_0815c48c[];
extern const u8 gUnknown_0815ac28[];
extern const u8 gUnknown_0815ac38[];
extern const Position gUnknown_08edcf00[3] = {{gUnknown_0815ac28, 64, 16, 8, 0, 0, 0, 0, 0, 0},
                                              {gUnknown_0815ac38, 120, 32, 0, 0, 0, 0, 0, 0, 0},
                                              {gUnknown_0815ac38, 120, 152, 4, 0, 0, 0, 0, 0, 0}};
// Physical pointer pool; language view 4 has 39 entries before view 5.
extern const u16 *const gUnknown_08edcf30[239] = {
    gUnknown_0815ac40, gUnknown_0815ac50, gUnknown_0815ac60, gUnknown_0815ac6c, gUnknown_0815ac7c,
    gUnknown_0815ac90, gUnknown_0815aca0, gUnknown_0815acac, gUnknown_0815acbc, gUnknown_0815acc8,
    gUnknown_0815acdc, gUnknown_0815acf0, gUnknown_0815ad04, gUnknown_0815ad18, gUnknown_0815ad28,
    gUnknown_0815ad38, gUnknown_0815ad4c, gUnknown_0815ad54, gUnknown_0815ad58, gUnknown_0815ad5c,
    gUnknown_0815ad64, gUnknown_0815ad6c, gUnknown_0815ad70, gUnknown_0815ad74, gUnknown_0815ad78,
    gUnknown_0815ad84, gUnknown_0815ad88, gUnknown_0815ad98, gUnknown_0815ad9c, gUnknown_0815ada8,
    gUnknown_0815adac, gUnknown_0815adbc, gUnknown_0815adc0, gUnknown_0815adcc, gUnknown_0815ade4,
    gUnknown_0815adf8, gUnknown_0815ae0c, gUnknown_0815ae18, gUnknown_0815ae2c, gUnknown_0815ae3c,
    gUnknown_0815ae54, gUnknown_0815ae74, gUnknown_0815ae98, gUnknown_0815aeb4, gUnknown_0815aed4,
    gUnknown_0815aef8, gUnknown_0815af18, gUnknown_0815af38, gUnknown_0815af68, gUnknown_0815af8c,
    gUnknown_0815afac, gUnknown_0815afd0, gUnknown_0815b000, gUnknown_0815b02c, gUnknown_0815b058,
    gUnknown_0815b080, gUnknown_0815b0ac, gUnknown_0815b0b4, gUnknown_0815b0bc, gUnknown_0815b0c0,
    gUnknown_0815b0c8, gUnknown_0815b0cc, gUnknown_0815b0d0, gUnknown_0815b0e0, gUnknown_0815b0f0,
    gUnknown_0815b108, gUnknown_0815b10c, gUnknown_0815b13c, gUnknown_0815b140, gUnknown_0815b158,
    gUnknown_0815b15c, gUnknown_0815b17c, gUnknown_0815b180, gUnknown_0815b18c, gUnknown_0815b1b4,
    gUnknown_0815b1e0, gUnknown_0815b208, gUnknown_0815b228, gUnknown_0815b250, gUnknown_0815b264,
    gUnknown_0815b284, gUnknown_0815b2ac, gUnknown_0815b2cc, gUnknown_0815b2f8, gUnknown_0815b328,
    gUnknown_0815b35c, gUnknown_0815b384, gUnknown_0815b3b4, gUnknown_0815b3e8, gUnknown_0815b418,
    gUnknown_0815b448, gUnknown_0815b478, gUnknown_0815b4a4, gUnknown_0815b4d4, gUnknown_0815b500,
    gUnknown_0815b52c, gUnknown_0815b558, gUnknown_0815b55c, gUnknown_0815b564, gUnknown_0815b568,
    gUnknown_0815b570, gUnknown_0815b574, gUnknown_0815b578, gUnknown_0815b58c, gUnknown_0815b59c,
    gUnknown_0815b5bc, gUnknown_0815b5c0, gUnknown_0815b5f4, gUnknown_0815b5f8, gUnknown_0815b618,
    gUnknown_0815b61c, gUnknown_0815b644, gUnknown_0815b648, gUnknown_0815b654, gUnknown_0815b674,
    gUnknown_0815b6a0, gUnknown_0815b6cc, gUnknown_0815b6e8, gUnknown_0815b70c, gUnknown_0815b728,
    gUnknown_0815b750, gUnknown_0815b770, gUnknown_0815b790, gUnknown_0815b7ac, gUnknown_0815b7cc,
    gUnknown_0815b7f0, gUnknown_0815b814, gUnknown_0815b838, gUnknown_0815b868, gUnknown_0815b890,
    gUnknown_0815b8bc, gUnknown_0815b8f0, gUnknown_0815b920, gUnknown_0815b950, gUnknown_0815b970,
    gUnknown_0815b9a4, gUnknown_0815b9d8, gUnknown_0815b9e0, gUnknown_0815b9e8, gUnknown_0815b9ec,
    gUnknown_0815b9f4, gUnknown_0815b9f8, gUnknown_0815b9fc, gUnknown_0815ba10, gUnknown_0815ba20,
    gUnknown_0815ba34, gUnknown_0815ba38, gUnknown_0815ba68, gUnknown_0815ba6c, gUnknown_0815ba88,
    gUnknown_0815ba8c, gUnknown_0815bab4, gUnknown_0815bab8, gUnknown_0815bac4, gUnknown_0815bae4,
    gUnknown_0815bb10, gUnknown_0815bb3c, gUnknown_0815bb60, gUnknown_0815bb88, gUnknown_0815bba4,
    gUnknown_0815bbbc, gUnknown_0815bbe0, gUnknown_0815bc04, gUnknown_0815bc1c, gUnknown_0815bc3c,
    gUnknown_0815bc6c, gUnknown_0815bc98, gUnknown_0815bcac, gUnknown_0815bcd4, gUnknown_0815bd00,
    gUnknown_0815bd2c, gUnknown_0815bd58, gUnknown_0815bd80, gUnknown_0815bda8, gUnknown_0815be0c,
    gUnknown_0815be38, gUnknown_0815be40, gUnknown_0815be48, gUnknown_0815be4c, gUnknown_0815be54,
    gUnknown_0815be58, gUnknown_0815be5c, gUnknown_0815be60, gUnknown_0815be70, gUnknown_0815be94,
    gUnknown_0815be98, gUnknown_0815bec0, gUnknown_0815bec4, gUnknown_0815bee8, gUnknown_0815beec,
    gUnknown_0815bf1c, gUnknown_0815bf20, gUnknown_0815bf2c, gUnknown_0815bf58, gUnknown_0815bf88,
    gUnknown_0815bfb8, gUnknown_0815bfd8, gUnknown_0815c004, gUnknown_0815c01c, gUnknown_0815c038,
    gUnknown_0815c05c, gUnknown_0815c080, gUnknown_0815c0a0, gUnknown_0815c0cc, gUnknown_0815c0f8,
    gUnknown_0815c120, gUnknown_0815c140, gUnknown_0815c168, gUnknown_0815c18c, gUnknown_0815c1a8,
    gUnknown_0815c1cc, gUnknown_0815c1f8, gUnknown_0815c224, gUnknown_0815c254, gUnknown_0815c280,
    gUnknown_0815c2b0, gUnknown_0815c2b8, gUnknown_0815c2c0, gUnknown_0815c2c4, gUnknown_0815c2cc,
    gUnknown_0815c2d0, gUnknown_0815c2d4, gUnknown_0815c2e4, gUnknown_0815c2f0, gUnknown_0815c310,
    gUnknown_0815c314, gUnknown_0815c344, gUnknown_0815c348, gUnknown_0815c370, gUnknown_0815c374,
    gUnknown_0815c398, gUnknown_0815c39c, gUnknown_0815c3a8, gUnknown_0815c3d0, gUnknown_0815c3f8,
    gUnknown_0815c420, gUnknown_0815c448, gUnknown_0815c470, gUnknown_0815c48c,
};
extern const u16 *const *const gUnknown_08edd2ec[6] = {
    gUnknown_08edcf30 + 0,   gUnknown_08edcf30 + 40,  gUnknown_08edcf30 + 80,
    gUnknown_08edcf30 + 120, gUnknown_08edcf30 + 160, gUnknown_08edcf30 + 199};
extern const u16 gUnknown_0815a0ac[32] __attribute__((section(".rodata.registers"))) = {
    0x0,  0x0,  0x8,  0x1f00, 0x10,   0x0,    0x12, 0x0,   0xa,  0x1e09, 0x14,
    0x0,  0x16, 0x0,  0xc,    0x1d01, 0x18,   0x0,  0x1a,  0x0,  0xe,    0x1c03,
    0x1c, 0x0,  0x1e, 0x0,    0x50,   0x3f41, 0x52, 0x808, 0x54, 0x0,
};
}

extern "C" {
u32 gUnknown_030053b0 __attribute__((section(".bss"))) = 0;
u8 gUnknown_030053b4 __attribute__((section(".bss.state_30053b4"))) = 0;
u8 gUnknown_030053b8 __attribute__((section(".bss.state_30053b8"))) = 0;
const u16 *const *gUnknown_030053bc __attribute__((section(".bss.state_30053bc"))) = 0;
// Inferred storage boundary at the independently addressed menu byte 030053e0.
// This is not a safe-capacity claim: retail formatters can write beyond it.
u16 gUnknown_030053c0[16] __attribute__((section(".bss.state_30053c0"))) = {0};
}
