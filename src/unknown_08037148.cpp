// C++ reconstruction fallback; original source language and linkage are unknown.
// Complete inferred scene TU; evidence and constraints: docs/scene-37148-tu-cpp.md.
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
struct Part {
    u32 words[4];
};
struct Allocation {
    u8 prefix[16];
    Part part;
};
struct Label {
    u8 x, y, text, alignment;
};
struct AlignedFive {
    u16 values[5];
} __attribute__((aligned(4)));
extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const Label gUnknown_081586b4[17];
extern const u16 *const *gUnknown_03005390;
extern u8 gUnknown_03002110[], gUnknown_03005394, gUnknown_0300539c, gUnknown_030052e8[];
extern u16 gUnknown_030053a0[];
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_08037148(u8 mode) {
    // Layout constraint for the observed unused stack word; original declaration unknown.
    volatile u32 unusedFrameWord;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 24, 18, 0);
    switch (mode) {
    case 0: {
        register u32 zero asm("r0") = 0;
        register u32 *row asm("r6") = (u32 *)0x06008078;
        register u32 rowIndex asm("r3") = 0;
        const Label *label = &gUnknown_081586b4[3];
        register const u16 *const **tableAddress asm("r8") = &gUnknown_03005390;

        do {
            register u32 x asm("r2") = 0;
            register u32 stride asm("r5") = 576;
            register u32 *nextRow asm("r4") = (u32 *)((u8 *)row + stride);
            register u32 nextIndex asm("r5") = rowIndex + 1;
            register u32 *destination asm("r3") = row;
            do {
                *destination++ = zero;
                ++x;
            } while (x <= 15);
            row = nextRow;
            rowIndex = nextIndex;
        } while (rowIndex <= 23);

        {
            register u32 index = label->text;
            register const u16 *const **address asm("r2") = tableAddress;
            register const u16 *const *table = *address;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (alignment) {
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
        label = &(gUnknown_081586b4 + 8)[gUnknown_03002110[119]];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment asm("r0") = label->alignment;
            u8 x = label->x;
            u8 y = label->y;
            const u16 *text = *entry;
            switch (alignment) {
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
        gUnknown_030052e8[0] = FUN_08020ad0(gUnknown_03005390[label->text]);
        break;
    }
    case 1: {
        register u32 zero asm("r0") = 0;
        register u32 *row asm("r6") = (u32 *)0x060080f8;
        register u32 rowIndex = 0;
        register const u16 *const **tableInitial = &gUnknown_03005390;
        register const u16 *const **tableAddress asm("r8") = tableInitial;
        register const Label *pendingLabel asm("r1") = &gUnknown_081586b4[4];

        do {
            register u32 x = 0;
            register u32 stride asm("r5") = 576;
            register u32 *nextRow = (u32 *)((u8 *)row + stride);
            register u32 nextIndex = rowIndex + 1;
            register u32 *destination asm("r3") = row;
            do {
                *destination++ = zero;
                ++x;
            } while (x <= 15);
            row = nextRow;
            rowIndex = nextIndex;
        } while (rowIndex <= 23);
        const Label *label = pendingLabel;

        {
            register u32 index = label->text;
            register const u16 *const **address asm("r2") = tableAddress;
            register const u16 *const *table = *address;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            register u32 y = label->y;
            const u16 *text = *entry;
            switch (alignment) {
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
        register u16 *digits asm("r6") = gUnknown_030053a0;
        u32 first = (u8)(gUnknown_03005394 / 10) + 128;
        digits[0] = first;
        digits[1] = (u8)(gUnknown_03005394 % 10) + 128;
        register u32 sentinelInitial = 0xfffe;
        register u32 sentinel = sentinelInitial;
        register u32 value = sentinel;
        digits[2] = value;
        register u32 skipInitial asm("r1") = 0;
        asm("" : "+r"(skipInitial));
        register u32 skip asm("r9") = skipInitial;
        if (first == 128) {
            register u32 one asm("r2") = 1;
            asm("" : "+r"(one));
            skip = one;
            digits[0] = 0;
        }
        register u32 x = 160;
        register u32 y = label->y;
        register const u16 *text asm("r4") = digits;
        value = x - FUN_08020ad0(text);
        x = (u8)value;
        register u32 letter = *text;
        register u32 skipBytes = skip << 1;
        if (letter != sentinel) {
            do {
                value = x + FUN_08020978(x, y, *text, 2);
                x = (u8)value;
                ++text;
            } while (*text != sentinel);
        }
        gUnknown_030052e8[1] = FUN_08020ad0((const u16 *)(skipBytes + (u32)gUnknown_030053a0));
        break;
    }
    case 2: {
        register u32 zero asm("r0") = 0;
        register u32 *row asm("r6") = (u32 *)0x06008138;
        register u32 rowIndex = 0;
        register const u16 *const **tableInitial = &gUnknown_03005390;
        register const u16 *const **tableAddress asm("r8") = tableInitial;
        register const Label *pendingLabel asm("r1") = &gUnknown_081586b4[5];

        do {
            register u32 x = 0;
            register u32 stride asm("r5") = 576;
            register u32 *nextRow = (u32 *)((u8 *)row + stride);
            register u32 nextIndex = rowIndex + 1;
            register u32 *destination asm("r3") = row;
            do {
                *destination++ = zero;
                ++x;
            } while (x <= 15);
            row = nextRow;
            rowIndex = nextIndex;
        } while (rowIndex <= 23);
        const Label *label = pendingLabel;

        {
            register u32 index = label->text;
            register const u16 *const **address asm("r2") = tableAddress;
            register const u16 *const *table = *address;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            register u32 y = label->y;
            const u16 *text = *entry;
            switch (alignment) {
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
        register u16 *digits asm("r5") = gUnknown_030053a0;
        u32 first = (u8)(gUnknown_0300539c / 100) + 128;
        register u32 digitZero asm("r10") = 0;
        digits[0] = first;
        register u32 second asm("r8") = (u8)((u8)(gUnknown_0300539c % 100) / 10) + 128;
        digits[1] = second;
        digits[2] = (u8)(gUnknown_0300539c % 10) + 128;
        register u32 value = 0xfffe;
        digits[3] = value;
        register u32 skipInitial asm("r2") = 0;
        asm("" : "+r"(skipInitial));
        register u32 skip asm("r9") = skipInitial;
        register u16 *working = digits;
        if (first == 128) {
            register u32 one asm("r5") = 1;
            asm("" : "+r"(one));
            skip = one;
            register u32 blank = digitZero;
            working[0] = blank;
            register u32 tens = second;
            if (tens == 128) {
                one = 2;
                skip = one;
                working[1] = blank;
            }
        }
        register u32 x = 160;
        register u32 y asm("r7") = label->y;
        register const u16 *text = working;
        value = x - FUN_08020ad0(text);
        x = (u8)value;
        register u32 letter = *text;
        register u32 sentinelInitial = 0xfffe;
        register u32 skipBytes = skip << 1;
        if (letter != sentinelInitial) {
            register u32 sentinel asm("r8") = sentinelInitial;
            do {
                value = x + FUN_08020978(x, y, *text, 2);
                x = (u8)value;
                ++text;
            } while (*text != sentinel);
        }
        gUnknown_030052e8[2] = FUN_08020ad0((const u16 *)(skipBytes + (u32)gUnknown_030053a0));
        break;
    }
    case 3: {
        register u32 zero asm("r0") = 0;
        register u32 *row asm("r6") = (u32 *)0x060081b8;
        register u32 rowIndex = 0;
        register const u16 *const **tableInitial = &gUnknown_03005390;
        register const u16 *const **tableAddress asm("r8") = tableInitial;
        register const Label *pendingLabel = &gUnknown_081586b4[6];

        do {
            register u32 x = 0;
            register u32 stride asm("r5") = 576;
            register u32 *nextRow = (u32 *)((u8 *)row + stride);
            register u32 nextIndex = rowIndex + 1;
            register u32 *destination asm("r3") = row;
            do {
                *destination++ = zero;
                ++x;
            } while (x <= 15);
            row = nextRow;
            rowIndex = nextIndex;
        } while (rowIndex <= 23);
        u32 labelBits = (u32)pendingLabel;

        {
            register u32 index = ((const Label *)labelBits)->text;
            register const u16 *const **address asm("r2") = tableAddress;
            register const u16 *const *table = *address;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = ((const Label *)labelBits)->alignment;
            u8 x = ((const Label *)labelBits)->x;
            labelBits = ((const Label *)labelBits)->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            register u32 firstGlyph = *text;
            register u32 initialSentinel asm("r1") = 0xfffe;
            if (firstGlyph != initialSentinel) {
                register u32 sentinel asm("r6") = initialSentinel;
                do {
                    x += FUN_08020978(x, labelBits, *text, 2);
                    ++text;
                } while (*text != sentinel);
            }
        }
        gUnknown_030052e8[3] = 0;
        break;
    }
    }
}
}

extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const Label gUnknown_081586b4[17];
extern const u16 *const *gUnknown_03005390;
extern u8 gUnknown_03005394, gUnknown_0300539c, gUnknown_03005398, gUnknown_03002110[],
    gUnknown_030052e8[];
extern u16 gUnknown_030053a0[];
void CpuFastSet(const void *, void *, u32);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_080375d8(u8 mode) {
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06017a00, 24, 2, 0);
    u32 zero;
    switch (mode) {
    case 0: {
        zero = 0;
        register const u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        register const Label *label asm("r6") = &gUnknown_081586b4[3];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        register u32 selected asm("r0") = gUnknown_03002110[119] << 2;
        register const Label *choices asm("r1") = (gUnknown_081586b4 + 8);
        label = (const Label *)(selected + (u32)choices);
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        break;
    }
    case 1: {
        zero = 0;
        register const u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        register const Label *label asm("r6") = &gUnknown_081586b4[4];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        u16 *digits = gUnknown_030053a0;
        u32 first = (u8)(gUnknown_03005394 / 10) + 128;
        digits[0] = first;
        digits[1] = (u8)(gUnknown_03005394 % 10) + 128;
        register u32 sentinel asm("r6") = 0xfffe;
        digits[2] = sentinel;
        if (first == 128)
            digits[0] = 0;
        register u32 x = 160;
        register const u16 *text asm("r4") = digits;
        register u32 value = x - FUN_08020ad0(text);
        x = (u8)value;
        while (*text != sentinel) {
            value = x + FUN_08020978(x, 0, *text, 2);
            x = (u8)value;
            ++text;
        }
        break;
    }
    case 2: {
        zero = 0;
        register const u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        register const Label *label asm("r6") = &gUnknown_081586b4[5];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        register u16 *digits = gUnknown_030053a0;
        u32 first = (u8)(gUnknown_0300539c / 100) + 128;
        register u32 digitZero = 0;
        digits[0] = first;
        register u32 value = (u8)((u8)(gUnknown_0300539c % 100) / 10);
        register u32 second = value;
        second += 128;
        digits[1] = second;
        digits[2] = (u8)(gUnknown_0300539c % 10) + 128;
        value = 0xfffe;
        digits[3] = value;
        register u16 *working = digits;
        if (first == 128) {
            register u32 blank = digitZero;
            working[0] = blank;
            if (second == 128)
                working[1] = blank;
        }
        register u32 x = 160;
        register const u16 *text = working;
        value = x - FUN_08020ad0(text);
        x = (u8)value;
        while (*text != 0xfffe) {
            value = x + FUN_08020978(x, 0, *text, 2);
            x = (u8)value;
            ++text;
        }
        break;
    }
    case 3: {
        zero = 0;
        register const u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        register const Label *label asm("r6") = &gUnknown_081586b4[6];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        break;
    }
    case 4: {
        zero = 0;
        register const u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        register const Label *label = &gUnknown_081586b4[14];
        {
            register u32 index = label->text;
            register const u16 *const *table = gUnknown_03005390;
            index <<= 2;
            const u16 *const *entry = (const u16 *const *)(index + (u32)table);
            register u32 alignment = label->alignment;
            u8 x = label->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) >> 1;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                ++text;
            }
        }
        if (gUnknown_03005398) {
            label = &gUnknown_081586b4[16];
            {
                register u32 index = label->text;
                register const u16 *const *table = gUnknown_03005390;
                index <<= 2;
                const u16 *const *entry = (const u16 *const *)(index + (u32)table);
                register u32 alignment = label->alignment;
                u8 x = label->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) >> 1;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    ++text;
                }
            }
        } else {
            label = &gUnknown_081586b4[15];
            {
                register u32 index = label->text;
                register const u16 *const *table = gUnknown_03005390;
                index <<= 2;
                const u16 *const *entry = (const u16 *const *)(index + (u32)table);
                register u32 alignment = label->alignment;
                u8 x = label->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) >> 1;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    ++text;
                }
            }
        }
        gUnknown_030052e8[4] = FUN_08020ad0(gUnknown_03005390[label->text]);
        break;
    }
    }
}
}

extern "C" {
void FUN_08020408(void *, const u8 *);
extern const u8 gUnknown_08158958[];
extern const u8 gUnknown_08158904[];
extern const u8 gUnknown_081589b4[];
extern const u8 gUnknown_08158a44[];
extern const u8 gUnknown_08158930[];
extern const u8 gUnknown_08158a14[];
extern const u8 gUnknown_081589e8[];
extern const u8 gUnknown_081588ec[];
void FUN_08037b10(u8 mode) {
    switch (mode) {
    case 0:
        FUN_08020408((void *)0x0600e980, gUnknown_08158958);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158904);
        FUN_08020408((void *)0x0600ea80, gUnknown_081589b4);
        FUN_08020408((void *)0x0600eb00, gUnknown_08158a44);
        break;
    case 1:
        FUN_08020408((void *)0x0600ea80, gUnknown_08158958);
        FUN_08020408((void *)0x0600eb00, gUnknown_08158930);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158a14);
        break;
    case 2:
        FUN_08020408((void *)0x0600eb00, gUnknown_081589e8);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158904);
        FUN_08020408((void *)0x0600ec00, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ec80, gUnknown_081589e8);
        break;
    case 3:
        FUN_08020408((void *)0x0600ec00, gUnknown_08158958);
        FUN_08020408((void *)0x0600ec80, gUnknown_081588ec);
        FUN_08020408((void *)0x0600e980, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158a14);
        break;
    }
}
void FUN_08037c30(u8 mode) {
    switch (mode) {
    case 0:
        FUN_08020408((void *)0x0600ec00, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ec80, gUnknown_081589e8);
        FUN_08020408((void *)0x0600e980, gUnknown_08158958);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158904);
        break;
    case 1:
        FUN_08020408((void *)0x0600e980, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158a14);
        FUN_08020408((void *)0x0600ea80, gUnknown_08158958);
        FUN_08020408((void *)0x0600eb00, gUnknown_08158930);
        break;
    case 2:
        FUN_08020408((void *)0x0600ea80, gUnknown_081589b4);
        FUN_08020408((void *)0x0600eb00, gUnknown_081589e8);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158904);
        break;
    case 3:
        FUN_08020408((void *)0x0600eb00, gUnknown_08158a44);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158a14);
        FUN_08020408((void *)0x0600ec00, gUnknown_08158958);
        FUN_08020408((void *)0x0600ec80, gUnknown_081588ec);
        break;
    }
}
}

extern "C" {
extern u8 gUnknown_03005394, gUnknown_0300539c, gUnknown_030052e4;
extern u8 gUnknown_03002110[], gUnknown_030052e0, gUnknown_030052f8;
extern const u16 *const *gUnknown_03005390;
extern const u16 *const *const gUnknown_08edced0[];
extern const u16 gUnknown_08158674[], gUnknown_081327d4[];
extern const u8 gUnknown_081586f8[], gUnknown_08132544[], gUnknown_08158bf4[], gUnknown_08158e1c[],
    gUnknown_08159314[], gUnknown_08158a70[], gUnknown_08158ad0[], gUnknown_08071b7c[],
    gUnknown_0807173c[];
extern const Label gUnknown_081586b4[];
extern const Position gUnknown_08edcd0c[2];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void), (*gUnknown_03003150[])(void);
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb60(void);
void FUN_0801fb94(void);
void FUN_0801ff30(void);
void FUN_0801f780(void);
void FUN_080210d8(void);
void FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32);
void LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_08037148(u8);
void FUN_080375d8(u8);
void FUN_08037b10(u8);
void FUN_08021000(u16 *, const u16 *, u32, u32, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08030d20(Node *);
void FUN_080388a0(Node *);
void FUN_0803895c(Node *);
void FUN_080389a8(Node *);
void FUN_0801f9d8(Node *);
void FUN_0801fba0(u16, u16);
void FUN_080380e4(void);
void FUN_080380f4(void);
void FUN_08037d44(void) {
    gUnknown_03005394 = 0;
    gUnknown_0300539c = 0;
    gUnknown_030052e4 = 0;
    FUN_0801fbfc(gUnknown_08158674, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 paletteZero = 0;
    CpuFastSet(&paletteZero, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_081586f8, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x06004000);
    LZ77UnCompVram(gUnknown_08158bf4, (void *)0x06010000);
    switch (gUnknown_03002110[119]) {
    case 0:
        LZ77UnCompVram(gUnknown_08158e1c, (void *)0x06010c80);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LZ77UnCompVram(gUnknown_08159314, (void *)0x06010c80);
        break;
    }
    gUnknown_03005390 = gUnknown_08edced0[gUnknown_03002110[119]];
    u32 mapZero = 0;
    CpuFastSet(&mapZero, (void *)0x0600f800, 0x01000200);
    LZ77UnCompVram(gUnknown_08158a70, (void *)0x0600f800);
    u32 secondZero = 0;
    CpuFastSet(&secondZero, (void *)0x0600f000, 0x01000200);
    u32 tileZero = 0;
    CpuFastSet(&tileZero, (void *)0x06008000, 0x01000d88);
    u16 *column = (u16 *)0x0600f10a;
    u16 tile = 0x2001;
    register u32 columnIndex asm("r6") = 0;
    do {
        register u32 y = 0;
        register u16 *nextColumn = column + 1;
        u16 *row = column;
        do {
            *row = tile++;
            row += 32;
            ++y;
        } while (y <= 17);
        column = nextColumn;
        ++columnIndex;
    } while (columnIndex <= 23);
    gUnknown_030052e0 = 0;
    gUnknown_030052f8 = 4;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 24, 18, 0);
    for (u32 i = 0; i <= 2; ++i) {
        const Label *label = &gUnknown_081586b4[i];
        register u32 textIndex = label->text;
        register const u16 *const *table = gUnknown_03005390;
        textIndex <<= 2;
        const u16 *const *entry = (const u16 *const *)(textIndex + (u32)table);
        register u32 alignment asm("r0") = label->alignment;
        register u32 x asm("r4") = label->x;
        u8 y = label->y;
        register const u16 *text = *entry;
        register u32 result asm("r0");
        switch (alignment) {
        case 1:
            result = FUN_08020ad0(text);
            goto adjust;
        case 2:
            result = FUN_08020ad0(text) >> 1;
        adjust:
            result = x - result;
            x = (u8)result;
            break;
        }
        while (*text != 0xfffe) {
            result = FUN_08020978(x, y, *text, 2);
            result = x + result;
            x = (u8)result;
            ++text;
        }
    }
    FUN_08037148(0);
    FUN_08037148(1);
    FUN_08037148(2);
    FUN_08037148(3);
    u32 finalZero = 0;
    CpuFastSet(&finalZero, (void *)0x0600e800, 0x01000200);
    LZ77UnCompVram(gUnknown_08158ad0, (void *)0x0600e900);
    FUN_08037b10(gUnknown_030052e0);
    u16 *destination = (u16 *)0x0600e000;
    for (u32 y = 0; y <= 3; ++y) {
        for (u32 x = 0; x <= 3; ++x) {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xf200);
            destination += 8;
        }
        destination += 224;
    }
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_080388a0, 32, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0803895c, 16, gUnknown_03003e20, 0);
    FUN_080375d8(gUnknown_030052e0);
    Node *node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcd0c[0];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edcd0c[1];
    FUN_0801f7d0(FUN_080389a8, 32, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_080380e4;
    gUnknown_03003150[1] = FUN_080380f4;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
}
}

extern "C" {
extern void (*gUnknown_03003150[])(void);
void FUN_080185d8(void);
void FUN_08018654(void);
void FUN_080381a8(void);
void FUN_080381e4(void);
void FUN_0801f89c(void);
void FUN_0801fda0(void);
void FUN_08018a8c(void);
void FUN_0801f60c(void);
void FUN_0801fbd8(void);
void FUN_0801ffa4(u8);
void FUN_0801fc60(void);
void FUN_0801f600(void);
extern u8 gUnknown_0300138c, gUnknown_030052e0;
extern u16 gUnknown_030052f4, gUnknown_03001378, gUnknown_03007ff8;
extern unsigned long long gUnknown_03002610;
extern const AlignedFive gUnknown_08edcd2c;
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void CpuFastSet(const void *, void *, u32);
void FUN_08020408(void *, const u8 *);
extern const u8 gUnknown_081589b4[], gUnknown_08158a14[], gUnknown_08158a44[], gUnknown_081589e8[],
    gUnknown_08158958[], gUnknown_08158930[], gUnknown_08158904[], gUnknown_081588ec[];
extern const u16 gUnknown_08158674[];
void FUN_0801fbfc(const u16 *, u32);
void FUN_0801fb60(void);
void FUN_0801fb94(void);
void FUN_0801ff30(void);
void FUN_0801f780(void);
void FUN_080210d8(void);
void FUN_0802110c(void);
void FUN_080184c8(void);
void FUN_08018c3c(void);
void FUN_0803d748(void);
extern void (*gUnknown_03002030)(void);
void FUN_080380b0(void) {
    gUnknown_03003150[1] = FUN_080185d8;
    gUnknown_03003150[2] = FUN_08018654;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
}
void FUN_080380e4(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_080380f4(void) {
    if (gUnknown_0300138c)
        FUN_08018a8c();
    gUnknown_03003150[2] = FUN_080381a8;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
    *(volatile u16 *)0x0400000a = 0x1e0a;
    *(volatile u16 *)0x0400000c = 0x1d02;
    gUnknown_030052f4 = gUnknown_08edcd2c.values[gUnknown_030052e0];
    FUN_0801f60c();
    ++gUnknown_03001378;
    gUnknown_03007ff8 |= 1;
    FUN_0801fbd8();
    FUN_0801ffa4(0);
    ++gUnknown_03002610;
}
void FUN_080381a8(void) {
    gUnknown_03003150[2] = FUN_080381e4;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = gUnknown_030052f4;
    *(volatile u16 *)0x04000208 = 1;
    FUN_0801fc60();
    FUN_0801f600();
}
void FUN_080381e4(void) {
    *(volatile u16 *)0x0400000a = 0x1e09;
    *(volatile u16 *)0x0400000c = 0x1d01;
}
void FUN_08038204(u8 x, u8 y, const u16 *text, u8 alignment) {
    switch (alignment) {
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
void FUN_08038264(u8 index) {
    if (index != 0xff) {
        u32 zero = 0;
        u32 *row = (u32 *)(0x06008038 + index * 64);
        for (u32 y = 0; y <= 23; y++) {
            for (u32 x = 0; x <= 15; x++)
                row[x] = zero;
            row = (u32 *)((u8 *)row + 576);
        }
    } else {
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x06017a00, 0x01000180);
    }
}
void FUN_080382bc(u8 mode) {
    switch (mode) {
    case 0:
        FUN_08020408((void *)0x0600e980, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158a14);
        break;
    case 1:
        FUN_08020408((void *)0x0600ea80, gUnknown_081589b4);
        FUN_08020408((void *)0x0600eb00, gUnknown_08158a44);
        break;
    case 2:
        FUN_08020408((void *)0x0600eb00, gUnknown_08158a44);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158a14);
        break;
    case 3:
        FUN_08020408((void *)0x0600ec00, gUnknown_081589b4);
        FUN_08020408((void *)0x0600ec80, gUnknown_081589e8);
        break;
    }
}
void FUN_08038360(u8 mode) {
    switch (mode) {
    case 0:
        FUN_08020408((void *)0x0600e980, gUnknown_08158958);
        FUN_08020408((void *)0x0600ea00, gUnknown_08158904);
        break;
    case 1:
        FUN_08020408((void *)0x0600ea80, gUnknown_08158958);
        FUN_08020408((void *)0x0600eb00, gUnknown_08158930);
        break;
    case 2:
        FUN_08020408((void *)0x0600eb00, gUnknown_081589e8);
        FUN_08020408((void *)0x0600eb80, gUnknown_08158904);
        break;
    case 3:
        FUN_08020408((void *)0x0600ec00, gUnknown_08158958);
        FUN_08020408((void *)0x0600ec80, gUnknown_081588ec);
        break;
    }
}
void FUN_08038404(void) {
    FUN_0801fbfc(gUnknown_08158674, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    FUN_080380b0();
    FUN_080184c8();
    FUN_08018c3c();
    gUnknown_03002030 = FUN_0803d748;
}
}

extern "C" {
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_030052e0, gUnknown_03005394, gUnknown_03005398, gUnknown_0300539c;
extern u8 gUnknown_03002110[];
extern const u16 gUnknown_08071460[], gUnknown_080714ae[];
void FUN_08038820(void);
void FUN_08038698(Node *);
void FUN_08038724(Node *);
void FUN_080387dc(Node *);
void FUN_0801f638(void);
void FUN_0801f618(u16);
void FUN_08037148(u8);
void FUN_080375d8(u8);
void FUN_08038448(Node *node) {
    register u32 input asm("r1") = gUnknown_030048e0[2];
    register u32 cancel = 10;
    cancel &= input;
    if (cancel) {
        node->callback = (void (*)(Node *))FUN_08038820;
        FUN_0801f638();
        FUN_0801f618(405);
    } else if (input & 1) {
        if (gUnknown_030052e0 == 1) {
            FUN_0801f638();
            FUN_0801f618(gUnknown_08071460[gUnknown_03005394]);
        } else if (gUnknown_030052e0 == 2) {
            FUN_0801f638();
            FUN_0801f618(gUnknown_080714ae[gUnknown_0300539c]);
        } else if (gUnknown_030052e0 == 3) {
            gUnknown_030052e0 = 4;
            gUnknown_03005398 = cancel;
            FUN_080375d8(4);
            node->callback = FUN_08038698;
            FUN_0801f618(402);
        }
    }
    input = gUnknown_030048e0[4];
    if (input & 64) {
        node->callback = FUN_08038724;
        FUN_0801f638();
        FUN_0801f618(401);
    } else if (input & 128) {
        node->callback = FUN_080387dc;
        FUN_0801f638();
        FUN_0801f618(401);
    }
    input = gUnknown_030048e0[4];
    register u32 horizontal = input & 32;
    register u32 left = (u16)horizontal;
    if (left) {
        switch (gUnknown_030052e0) {
        case 0:
            if (gUnknown_03002110[119])
                --gUnknown_03002110[119];
            else
                gUnknown_03002110[119] = 5;
            FUN_08037148(0);
            FUN_080375d8(0);
            break;
        case 1:
            if (gUnknown_03005394)
                --gUnknown_03005394;
            else
                gUnknown_03005394 = 38;
            FUN_08037148(1);
            FUN_080375d8(1);
            break;
        case 2:
            if (gUnknown_0300539c)
                --gUnknown_0300539c;
            else
                gUnknown_0300539c = 197;
            FUN_08037148(2);
            FUN_080375d8(2);
            break;
        }
        if (gUnknown_030052e0 <= 2)
            FUN_0801f618(401);
    } else if (input & 16) {
        switch (gUnknown_030052e0) {
        case 0:
            ++gUnknown_03002110[119];
            if (gUnknown_03002110[119] > 5)
                gUnknown_03002110[119] = left;
            FUN_08037148(0);
            FUN_080375d8(0);
            break;
        case 1:
            ++gUnknown_03005394;
            if (gUnknown_03005394 > 38)
                gUnknown_03005394 = left;
            FUN_08037148(1);
            FUN_080375d8(1);
            break;
        case 2:
            ++gUnknown_0300539c;
            if (gUnknown_0300539c > 197)
                gUnknown_0300539c = left;
            FUN_08037148(2);
            FUN_080375d8(2);
            break;
        }
        if (gUnknown_030052e0 <= 2)
            FUN_0801f618(401);
    }
}
}

extern "C" {
extern u8 gUnknown_030052e0, gUnknown_030052f8, gUnknown_030025f0;
extern unsigned long long gUnknown_03002610;
extern void (*gUnknown_03002030)(void);
extern const u16 gUnknown_08158b94[], gUnknown_081327b4[], gUnknown_08159770[];
extern const AlignedFive gUnknown_08edcee8;
extern const u8 gUnknown_08159fd4[];
extern const Part gUnknown_08159fc4;
extern const AlignedFive gUnknown_08edcef4;
extern u8 gUnknown_030052e8[], gUnknown_030052e4;
void FUN_08038a20(Node *);
void FUN_080375d8(u8);
void FUN_080382bc(u8);
void FUN_08038360(u8);
void FUN_08038448(Node *);
void FUN_0803876c(Node *);
void FUN_0803878c(Node *);
void FUN_080387b4(Node *);
void FUN_080380b0(void);
void FUN_08039e20(void);
void FUN_08000210(void);
void FUN_080217d0(u8);
void FUN_0802188c(void);
void FUN_080215a8(void);
u8 FUN_0802067c(u16 *, u32);
u8 FUN_08020500(u16 *, const u16 *, u32);
void FUN_0801fed8(u8, u8);
extern u16 gUnknown_030048e0[];
extern u8 gUnknown_03005398;
void FUN_0801f618(u16);
void FUN_08038850(void);
void FUN_08038698(Node *node) {
    register u32 input asm("r1") = gUnknown_030048e0[2];
    if (input & 2)
        goto cancel;
    if (input & 1) {
        if (!gUnknown_03005398)
            goto cancel;
        node->callback = (void (*)(Node *))FUN_08038850;
        FUN_0801f618(404);
        goto done;
    cancel:
        gUnknown_030052e0 = 3;
        FUN_080375d8(3);
        node->callback = FUN_08038448;
        FUN_0801f618(405);
        goto done;
    }
    if (input & 48) {
        gUnknown_03005398 ^= 1;
        FUN_080375d8(4);
        FUN_0801f618(401);
    }
done:;
}
void FUN_08038724(Node *node) {
    if (gUnknown_030052f8 > 1) {
        --gUnknown_030052f8;
    } else {
        gUnknown_030052f8 = 0;
        FUN_080382bc(gUnknown_030052e0);
        if (gUnknown_030052e0 == 0)
            gUnknown_030052e0 = 3;
        else
            --gUnknown_030052e0;
        node->callback = FUN_0803876c;
    }
}
void FUN_0803876c(Node *node) {
    FUN_080375d8(gUnknown_030052e0);
    node->callback = FUN_0803878c;
}
void FUN_0803878c(Node *node) {
    FUN_08038360(gUnknown_030052e0);
    gUnknown_030052f8 = 1;
    node->callback = FUN_080387b4;
}
void FUN_080387b4(Node *node) {
    if (gUnknown_030052f8 <= 3)
        ++gUnknown_030052f8;
    else {
        gUnknown_030052f8 = 4;
        node->callback = FUN_08038448;
    }
}
void FUN_080387dc(Node *node) {
    if (gUnknown_030052f8 > 1)
        --gUnknown_030052f8;
    else {
        FUN_080382bc(gUnknown_030052e0);
        ++gUnknown_030052e0;
        if (gUnknown_030052e0 > 3)
            gUnknown_030052e0 = 0;
        node->callback = FUN_0803876c;
    }
}
void FUN_08038820(void) {
    if (FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_080380b0();
        gUnknown_03002030 = FUN_08039e20;
        FUN_080217d0(0);
    }
}
void FUN_08038850(void) {
    if (FUN_0802067c((u16 *)0x05000000, 512)) {
        FUN_080380b0();
        gUnknown_03002030 = FUN_08000210;
        FUN_0802188c();
        FUN_080215a8();
        gUnknown_03002610 = 1;
        gUnknown_030025f0 = 15;
        FUN_080217d0(0);
    }
}
void FUN_080388a0(Node *node) {
    register u32 initial = FUN_08020500((u16 *)0x05000000, gUnknown_08158b94, 80) == 0;
    u32 pending = initial;
    register u32 result asm("r0");
    if (FUN_08020500((u16 *)0x050001e0, gUnknown_081327b4, 16) == 0)
        result = 1;
    else
        result = (u8)pending;
    pending = result;
    if (FUN_08020500((u16 *)0x05000200, gUnknown_08159770, 80) == 0)
        result = pending | 1;
    else
        result = (u8)pending;
    if (result == 0)
        node->callback = FUN_08038448;
}
void FUN_08038918(Node *node) {
    node->position->x = gUnknown_030052f8 + 120;
    node->position->y = gUnknown_08edcee8.values[gUnknown_030052e0] - gUnknown_030052f8;
    if (gUnknown_030052f8 != 0)
        FUN_0801fed8(node->index, 0);
}
void FUN_0803895c(Node *node) {
    node->position->parts = gUnknown_08159fd4;
    node->position->tile = 0;
    node->position->x = 120;
    node->position->y = gUnknown_08edcee8.values[gUnknown_030052e0];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 8;
    node->callback = FUN_08038918;
}
void FUN_080389a8(Node *node) {
    Allocation *allocation = (Allocation *)node->allocation;
    allocation->part = gUnknown_08159fc4;
    ((u8 *)allocation)[21] = -(gUnknown_030052e8[gUnknown_030052e0] + 12);
    node->position->parts = &allocation->part;
    node->position->tile = 96;
    node->position->x = 207;
    node->position->y = gUnknown_08edcef4.values[gUnknown_030052e0] - gUnknown_030052e4;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 4;
    node->callback = FUN_08038a20;
}
void FUN_08038a20(Node *node) {
    register u8 *allocation = (u8 *)node->allocation;
    allocation[21] = -(gUnknown_030052e8[gUnknown_030052e0] + 12);
    node->position->x = gUnknown_030052f8 + 199;
    Position *position = node->position;
    register u32 y = gUnknown_08edcef4.values[gUnknown_030052e0] + 8;
    position->y = y - gUnknown_030052f8 - gUnknown_030052e4;
    if (gUnknown_030052e0 != 3)
        FUN_0801fed8(node->index, 0);
}
}

extern "C" {
extern const u8 gUnknown_08159f94[], gUnknown_08159fa4[];
extern const u16 gUnknown_08159810[];
extern const u16 gUnknown_08159824[];
extern const u16 gUnknown_08159834[];
extern const u16 gUnknown_08159840[];
extern const u16 gUnknown_08159850[];
extern const u16 gUnknown_08159864[];
extern const u16 gUnknown_08159874[];
extern const u16 gUnknown_08159884[];
extern const u16 gUnknown_08159898[];
extern const u16 gUnknown_081598a8[];
extern const u16 gUnknown_081598b0[];
extern const u16 gUnknown_081598b8[];
extern const u16 gUnknown_081598c8[];
extern const u16 gUnknown_081598e0[];
extern const u16 gUnknown_081598e8[];
extern const u16 gUnknown_08159900[];
extern const u16 gUnknown_08159908[];
extern const u16 gUnknown_08159910[];
extern const u16 gUnknown_08159934[];
extern const u16 gUnknown_08159948[];
extern const u16 gUnknown_08159954[];
extern const u16 gUnknown_08159964[];
extern const u16 gUnknown_08159978[];
extern const u16 gUnknown_08159988[];
extern const u16 gUnknown_08159998[];
extern const u16 gUnknown_081599ac[];
extern const u16 gUnknown_081599c4[];
extern const u16 gUnknown_081599cc[];
extern const u16 gUnknown_081599d4[];
extern const u16 gUnknown_081599e8[];
extern const u16 gUnknown_08159a0c[];
extern const u16 gUnknown_08159a14[];
extern const u16 gUnknown_08159a30[];
extern const u16 gUnknown_08159a38[];
extern const u16 gUnknown_08159a40[];
extern const u16 gUnknown_08159a70[];
extern const u16 gUnknown_08159a84[];
extern const u16 gUnknown_08159a90[];
extern const u16 gUnknown_08159aa0[];
extern const u16 gUnknown_08159ab4[];
extern const u16 gUnknown_08159ac4[];
extern const u16 gUnknown_08159ad4[];
extern const u16 gUnknown_08159ae8[];
extern const u16 gUnknown_08159afc[];
extern const u16 gUnknown_08159b04[];
extern const u16 gUnknown_08159b0c[];
extern const u16 gUnknown_08159b3c[];
extern const u16 gUnknown_08159b6c[];
extern const u16 gUnknown_08159b74[];
extern const u16 gUnknown_08159b94[];
extern const u16 gUnknown_08159b9c[];
extern const u16 gUnknown_08159ba8[];
extern const u16 gUnknown_08159bc8[];
extern const u16 gUnknown_08159bdc[];
extern const u16 gUnknown_08159be8[];
extern const u16 gUnknown_08159bf8[];
extern const u16 gUnknown_08159c0c[];
extern const u16 gUnknown_08159c1c[];
extern const u16 gUnknown_08159c2c[];
extern const u16 gUnknown_08159c40[];
extern const u16 gUnknown_08159c58[];
extern const u16 gUnknown_08159c60[];
extern const u16 gUnknown_08159c68[];
extern const u16 gUnknown_08159c88[];
extern const u16 gUnknown_08159cb8[];
extern const u16 gUnknown_08159cc0[];
extern const u16 gUnknown_08159ce0[];
extern const u16 gUnknown_08159cec[];
extern const u16 gUnknown_08159cf4[];
extern const u16 gUnknown_08159d14[];
extern const u16 gUnknown_08159d28[];
extern const u16 gUnknown_08159d34[];
extern const u16 gUnknown_08159d44[];
extern const u16 gUnknown_08159d58[];
extern const u16 gUnknown_08159d68[];
extern const u16 gUnknown_08159d78[];
extern const u16 gUnknown_08159d8c[];
extern const u16 gUnknown_08159db0[];
extern const u16 gUnknown_08159db8[];
extern const u16 gUnknown_08159dc0[];
extern const u16 gUnknown_08159ddc[];
extern const u16 gUnknown_08159e0c[];
extern const u16 gUnknown_08159e14[];
extern const u16 gUnknown_08159e30[];
extern const u16 gUnknown_08159e38[];
extern const u16 gUnknown_08159e40[];
extern const u16 gUnknown_08159e64[];
extern const u16 gUnknown_08159e78[];
extern const u16 gUnknown_08159e84[];
extern const u16 gUnknown_08159e94[];
extern const u16 gUnknown_08159ea8[];
extern const u16 gUnknown_08159eb8[];
extern const u16 gUnknown_08159ec8[];
extern const u16 gUnknown_08159edc[];
extern const u16 gUnknown_08159ef4[];
extern const u16 gUnknown_08159efc[];
extern const u16 gUnknown_08159f04[];
extern const u16 gUnknown_08159f2c[];
extern const u16 gUnknown_08159f5c[];
extern const u16 gUnknown_08159f64[];
extern const u16 gUnknown_08159f7c[];
extern const u16 gUnknown_08159f84[];
extern const Position gUnknown_08edcd0c[2] = {{gUnknown_08159f94, 64, 16, 100, 0, 0, 0, 0, 0, 0},
                                              {gUnknown_08159fa4, 192, 12, 164, 0, 0, 0, 0, 0, 0}};
extern const AlignedFive gUnknown_08edcd2c = {{0x4528, 0x6528, 0x7528, 0x9528, 0x9528}};
extern const u16 *const gUnknown_08edcd38[17] = {
    gUnknown_08159810, gUnknown_08159824, gUnknown_08159834, gUnknown_08159840, gUnknown_08159850,
    gUnknown_08159864, gUnknown_08159874, gUnknown_08159884, gUnknown_08159898, gUnknown_081598a8,
    gUnknown_081598b0, gUnknown_081598b8, gUnknown_081598c8, gUnknown_081598e0, gUnknown_081598e8,
    gUnknown_08159900, gUnknown_08159908};
extern const u16 *const gUnknown_08edcd7c[17] = {
    gUnknown_08159910, gUnknown_08159934, gUnknown_08159948, gUnknown_08159954, gUnknown_08159964,
    gUnknown_08159978, gUnknown_08159988, gUnknown_08159998, gUnknown_081599ac, gUnknown_081599c4,
    gUnknown_081599cc, gUnknown_081599d4, gUnknown_081599e8, gUnknown_08159a0c, gUnknown_08159a14,
    gUnknown_08159a30, gUnknown_08159a38};
extern const u16 *const gUnknown_08edcdc0[17] = {
    gUnknown_08159a40, gUnknown_08159a70, gUnknown_08159a84, gUnknown_08159a90, gUnknown_08159aa0,
    gUnknown_08159ab4, gUnknown_08159ac4, gUnknown_08159ad4, gUnknown_08159ae8, gUnknown_08159afc,
    gUnknown_08159b04, gUnknown_08159b0c, gUnknown_08159b3c, gUnknown_08159b6c, gUnknown_08159b74,
    gUnknown_08159b94, gUnknown_08159b9c};
extern const u16 *const gUnknown_08edce04[17] = {
    gUnknown_08159ba8, gUnknown_08159bc8, gUnknown_08159bdc, gUnknown_08159be8, gUnknown_08159bf8,
    gUnknown_08159c0c, gUnknown_08159c1c, gUnknown_08159c2c, gUnknown_08159c40, gUnknown_08159c58,
    gUnknown_08159c60, gUnknown_08159c68, gUnknown_08159c88, gUnknown_08159cb8, gUnknown_08159cc0,
    gUnknown_08159ce0, gUnknown_08159cec};
extern const u16 *const gUnknown_08edce48[17] = {
    gUnknown_08159cf4, gUnknown_08159d14, gUnknown_08159d28, gUnknown_08159d34, gUnknown_08159d44,
    gUnknown_08159d58, gUnknown_08159d68, gUnknown_08159d78, gUnknown_08159d8c, gUnknown_08159db0,
    gUnknown_08159db8, gUnknown_08159dc0, gUnknown_08159ddc, gUnknown_08159e0c, gUnknown_08159e14,
    gUnknown_08159e30, gUnknown_08159e38};
extern const u16 *const gUnknown_08edce8c[17] = {
    gUnknown_08159e40, gUnknown_08159e64, gUnknown_08159e78, gUnknown_08159e84, gUnknown_08159e94,
    gUnknown_08159ea8, gUnknown_08159eb8, gUnknown_08159ec8, gUnknown_08159edc, gUnknown_08159ef4,
    gUnknown_08159efc, gUnknown_08159f04, gUnknown_08159f2c, gUnknown_08159f5c, gUnknown_08159f64,
    gUnknown_08159f7c, gUnknown_08159f84};
extern const u16 *const *const gUnknown_08edced0[6] = {gUnknown_08edcd38, gUnknown_08edcd7c,
                                                       gUnknown_08edcdc0, gUnknown_08edce04,
                                                       gUnknown_08edce48, gUnknown_08edce8c};
extern const AlignedFive gUnknown_08edcee8 = {{48, 80, 96, 128, 128}};
extern const AlignedFive gUnknown_08edcef4 = {{52, 84, 100, 132, 132}};
extern const u16 gUnknown_08158674[32] __attribute__((section(".rodata.settings"))) = {
    0,  0, 8,  7936, 16, 0,    18, 0, 10, 7689, 20, 0,     22, 0,    12, 7425,
    24, 0, 26, 0,    14, 7171, 28, 0, 30, 0,    80, 16193, 82, 2056, 84, 0};
extern const Label gUnknown_081586b4[17] __attribute__((section(".rodata.settings"))) = {
    {0, 6, 0, 0},      {0, 38, 8, 0},    {0, 86, 11, 0},    {16, 22, 1, 0},  {16, 54, 9, 0},
    {16, 70, 10, 0},   {16, 102, 12, 0}, {160, 102, 13, 1}, {160, 22, 2, 1}, {160, 22, 3, 1},
    {160, 22, 4, 1},   {160, 22, 5, 1},  {160, 22, 6, 1},   {160, 22, 7, 1}, {16, 102, 14, 0},
    {160, 102, 15, 1}, {160, 102, 16, 1}};
}

extern "C" {
const u16 *const *gUnknown_03005390 __attribute__((section(".bss"))) = 0;
u8 gUnknown_03005394 __attribute__((section(".bss.state_3005394"))) = 0;
u8 gUnknown_03005398 __attribute__((section(".bss.state_3005398"))) = 0;
u8 gUnknown_0300539c __attribute__((section(".bss.state_300539c"))) = 0;
u16 gUnknown_030053a0[4] __attribute__((section(".bss.state_30053a0"))) = {0};
}
