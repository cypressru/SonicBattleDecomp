// C++ reconstruction fallback; see docs/text-menu-tu-cpp.md.
#include "types.h"
struct TextDescriptor {
    u8 x, y, index, alignment;
};
extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern u8 gUnknown_03002600[];
extern const u16 *const *gUnknown_030052f0;
extern const TextDescriptor gUnknown_0812e648[];
extern const TextDescriptor gUnknown_0812e65c[];
extern const TextDescriptor gUnknown_0812e664[];
extern const TextDescriptor gUnknown_0812e660[];
extern const TextDescriptor gUnknown_0812e64c[];
extern const TextDescriptor gUnknown_0812e668[];
extern const TextDescriptor gUnknown_0812e650[];
extern const TextDescriptor gUnknown_0812e654[];
extern const TextDescriptor gUnknown_0812e658[];
extern const TextDescriptor gUnknown_0812e66c[];
extern const TextDescriptor gUnknown_0812e678[];
extern const TextDescriptor gUnknown_0812e6a4[];
extern const TextDescriptor gUnknown_0812e68c[];
extern const TextDescriptor gUnknown_0812e6ec[];
extern const TextDescriptor gUnknown_0812e6b4[];
extern const TextDescriptor gUnknown_0812e6bc[];
extern const TextDescriptor gUnknown_0812e6cc[];
extern const TextDescriptor gUnknown_0812e6d4[];
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void CpuFastSet(const void *, void *, u32);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
extern u8 gUnknown_030052e8[];
void FUN_0802df68(u8 selected) {
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06008020, 24, 18, 0);
    u32 zero;
    const TextDescriptor *descriptor;
    switch (selected) {
    case 0: {
        if (selected != 255) {
            u32 fill = 0;
            register u32 offset asm("r0") = selected * 64;
            u32 base = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        {
            descriptor = gUnknown_0812e648;
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            u8 alignment = descriptor->alignment;
            u8 x = descriptor->x;
            u8 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[0] * 4;
            register const TextDescriptor *base asm("r1") = gUnknown_0812e66c;
            descriptor = (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            u32 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        gUnknown_030052e8[0] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        register u32 nextSelected asm("r4") = selected + 1;
        asm volatile("" : : "r"(nextSelected));
        register u32 shifted asm("r0") = nextSelected << 24;
        asm volatile("" : : "r"(shifted));
        selected = shifted >> 24;
    }
    case 1: {
        if (selected != 255) {
            u32 fill = 0;
            register u32 offset asm("r0") = selected * 64;
            u32 base = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        if (gUnknown_03002600[0] == 0) {
            {
                descriptor = gUnknown_0812e65c;
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                u8 alignment = descriptor->alignment;
                u8 x = descriptor->x;
                u8 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[1] * 4;
                register const TextDescriptor *base asm("r1") = gUnknown_0812e678;
                descriptor = (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                u32 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
        } else if (gUnknown_03002600[0] == 1) {
            {
                descriptor = gUnknown_0812e664;
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                u8 alignment = descriptor->alignment;
                u8 x = descriptor->x;
                u8 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[3] * 4;
                register const TextDescriptor *base asm("r1") = gUnknown_0812e6a4;
                descriptor = (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                register u32 yValue asm("r4") = descriptor->y;
                asm volatile("" : : "r"(yValue));
                register u32 y asm("r8") = yValue;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
        } else if (gUnknown_03002600[0] == 2) {
            {
                descriptor = gUnknown_0812e660;
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                u8 alignment = descriptor->alignment;
                u8 x = descriptor->x;
                u8 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[2] * 4;
                register const TextDescriptor *base asm("r1") = gUnknown_0812e68c;
                descriptor = (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                u32 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
        } else
            break;
        gUnknown_030052e8[1] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        break;
    }
    case 2: {
        if (selected != 255) {
            u32 fill = 0;
            register u32 offset asm("r0") = selected * 64;
            u32 base = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            u32 row = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        {
            descriptor = gUnknown_0812e64c;
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            u8 alignment = descriptor->alignment;
            u8 x = descriptor->x;
            u8 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[4] * 4;
            register const TextDescriptor *base asm("r1") = gUnknown_0812e6ec;
            descriptor = (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            u32 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        gUnknown_030052e8[2] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        register u32 nextSelected asm("r4") = selected + 1;
        asm volatile("" : : "r"(nextSelected));
        register u32 shifted asm("r0") = nextSelected << 24;
        asm volatile("" : : "r"(shifted));
        selected = shifted >> 24;
    }
    case 3: {
        if (selected != 255) {
            u32 fill = 0;
            register u32 offset asm("r0") = selected * 64;
            u32 base = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        if (gUnknown_03002600[4] == 1) {
            {
                descriptor = gUnknown_0812e668;
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                u8 alignment = descriptor->alignment;
                u8 x = descriptor->x;
                u8 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[5] * 4;
                register const TextDescriptor *base asm("r1") = gUnknown_0812e6b4;
                descriptor = (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;
                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                u32 y = descriptor->y;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, y, *text, 2);
                    text++;
                }
            }
            gUnknown_030052e8[3] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        } else
            gUnknown_030052e8[3] = 0;
        break;
    }
    case 4: {
        if (selected != 255) {
            u32 fill = 0;
            u32 offset = selected * 64;
            register u32 base asm("r4") = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        {
            descriptor = gUnknown_0812e650;
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            u8 alignment = descriptor->alignment;
            u8 x = descriptor->x;
            u8 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[6] * 4;
            register const TextDescriptor *base asm("r1") = gUnknown_0812e6bc;
            descriptor = (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            u32 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        gUnknown_030052e8[4] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        break;
    }
    case 5: {
        if (selected != 255) {
            u32 fill = 0;
            u32 offset = selected * 64;
            register u32 base asm("r4") = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        {
            descriptor = gUnknown_0812e654;
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            u8 alignment = descriptor->alignment;
            u8 x = descriptor->x;
            u8 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[7] * 4;
            register const TextDescriptor *base asm("r1") = gUnknown_0812e6cc;
            descriptor = (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            u32 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        gUnknown_030052e8[5] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        break;
    }
    case 6: {
        if (selected != 255) {
            u32 fill = 0;
            u32 offset = selected * 64;
            register u32 base asm("r4") = 0x06008020;
            u32 *out = (u32 *)(offset + base);
            register u32 row asm("r2") = 0;
            do {
                u32 col = 0;
                register u32 stride asm("r4") = 576;
                asm volatile("" : : "r"(stride));
                u32 *next = (u32 *)((u32)out + stride);
                row++;
                do {
                    *out++ = fill;
                    col++;
                } while (col < 16);
                out = next;
            } while (row < 24);
        } else {
            zero = 0;
            register u32 *fill asm("r0") = &zero;
            register void *destination asm("r1") = (void *)0x06017a00;
            CpuFastSet(fill, destination, 0x01000180);
        }
        {
            descriptor = gUnknown_0812e658;
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            u8 alignment = descriptor->alignment;
            u8 x = descriptor->x;
            u8 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[8] * 4;
            register const TextDescriptor *base asm("r1") = gUnknown_0812e6d4;
            descriptor = (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;
            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            u32 y = descriptor->y;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, y, *text, 2);
                text++;
            }
        }
        gUnknown_030052e8[6] = FUN_08020ad0(gUnknown_030052f0[descriptor->index]);
        break;
    }
    }
}
}
extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern u8 gUnknown_03002600[];
extern const u16 *const *gUnknown_030052f0;
extern const TextDescriptor gUnknown_0812e648[];
extern const TextDescriptor gUnknown_0812e65c[];
extern const TextDescriptor gUnknown_0812e664[];
extern const TextDescriptor gUnknown_0812e660[];
extern const TextDescriptor gUnknown_0812e64c[];
extern const TextDescriptor gUnknown_0812e668[];
extern const TextDescriptor gUnknown_0812e650[];
extern const TextDescriptor gUnknown_0812e654[];
extern const TextDescriptor gUnknown_0812e658[];
extern const TextDescriptor gUnknown_0812e66c[];
extern const TextDescriptor gUnknown_0812e678[];
extern const TextDescriptor gUnknown_0812e6a4[];
extern const TextDescriptor gUnknown_0812e68c[];
extern const TextDescriptor gUnknown_0812e6ec[];
extern const TextDescriptor gUnknown_0812e6b4[];
extern const TextDescriptor gUnknown_0812e6bc[];
extern const TextDescriptor gUnknown_0812e6cc[];
extern const TextDescriptor gUnknown_0812e6d4[];
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
void CpuFastSet(const void *, void *, u32);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
void FUN_0802ea64(u8 selected) {
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06017a00, 24, 2, 0);
    u32 zero;
    switch (selected) {
    case 0: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        {
            const TextDescriptor *descriptor = gUnknown_0812e648;
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            register const u16 *text asm("r5") = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[0] * 4;

            register const TextDescriptor *base asm("r1") = gUnknown_0812e66c;
            register const TextDescriptor *descriptor asm("r2") =
                (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        break;
    }
    case 1: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        if (gUnknown_03002600[0] == 0) {
            {
                register const TextDescriptor *descriptor asm("r2") = gUnknown_0812e65c;
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r1") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[1] * 4;

                register const TextDescriptor *base asm("r1") = gUnknown_0812e678;
                register const TextDescriptor *descriptor asm("r2") =
                    (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
        } else if (gUnknown_03002600[0] == 1) {
            {
                register const TextDescriptor *descriptor asm("r2") = gUnknown_0812e664;
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r1") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[3] * 4;

                register const TextDescriptor *base asm("r1") = gUnknown_0812e6a4;
                register const TextDescriptor *descriptor asm("r2") =
                    (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
        } else if (gUnknown_03002600[0] == 2) {
            {
                register const TextDescriptor *descriptor asm("r2") = gUnknown_0812e660;
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r1") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[2] * 4;

                register const TextDescriptor *base asm("r1") = gUnknown_0812e68c;
                register const TextDescriptor *descriptor asm("r2") =
                    (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
        }
        break;
    }
    case 2: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        {
            const TextDescriptor *descriptor = gUnknown_0812e64c;
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[4] * 4;

            register const TextDescriptor *base asm("r1") = gUnknown_0812e6ec;
            register const TextDescriptor *descriptor asm("r2") =
                (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        break;
    }
    case 3: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        if (gUnknown_03002600[4] == 1) {
            {
                register const TextDescriptor *descriptor asm("r2") = gUnknown_0812e668;
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r1") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
            {
                register u32 offset asm("r0") = gUnknown_03002600[5] * 4;

                register const TextDescriptor *base asm("r1") = gUnknown_0812e6b4;
                register const TextDescriptor *descriptor asm("r2") =
                    (const TextDescriptor *)(offset + (u32)base);
                u32 index = descriptor->index;

                const u16 *const *table = gUnknown_030052f0;
                const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
                register u8 alignment asm("r0") = descriptor->alignment;
                u8 x = descriptor->x;
                const u16 *text = *entry;
                switch (alignment) {
                case 1:
                    x -= FUN_08020ad0(text);
                    break;
                case 2:
                    x -= FUN_08020ad0(text) / 2;
                    break;
                }
                while (*text != 0xfffe) {
                    x += FUN_08020978(x, 0, *text, 2);
                    text++;
                }
            }
        }
        break;
    }
    case 4: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        {
            const TextDescriptor *descriptor = gUnknown_0812e650;
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[6] * 4;

            register const TextDescriptor *base asm("r1") = gUnknown_0812e6bc;
            register const TextDescriptor *descriptor asm("r2") =
                (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        break;
    }
    case 5: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        {
            const TextDescriptor *descriptor = gUnknown_0812e654;
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[7] * 4;

            register const TextDescriptor *base asm("r1") = gUnknown_0812e6cc;
            register const TextDescriptor *descriptor asm("r2") =
                (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        break;
    }
    case 6: {
        zero = 0;
        register u32 *fill asm("r0") = &zero;
        register void *destination asm("r1") = (void *)0x06017a00;
        CpuFastSet(fill, destination, 0x01000180);
        {
            const TextDescriptor *descriptor = gUnknown_0812e658;
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        {
            register u32 offset asm("r0") = gUnknown_03002600[8] * 4;

            register const TextDescriptor *base asm("r1") = gUnknown_0812e6d4;
            register const TextDescriptor *descriptor asm("r2") =
                (const TextDescriptor *)(offset + (u32)base);
            u32 index = descriptor->index;

            const u16 *const *table = gUnknown_030052f0;
            const u16 *const *entry = (const u16 *const *)((index * 4) + (u32)table);
            register u8 alignment asm("r0") = descriptor->alignment;
            u8 x = descriptor->x;
            const u16 *text = *entry;
            switch (alignment) {
            case 1:
                x -= FUN_08020ad0(text);
                break;
            case 2:
                x -= FUN_08020ad0(text) / 2;
                break;
            }
            while (*text != 0xfffe) {
                x += FUN_08020978(x, 0, *text, 2);
                text++;
            }
        }
        break;
    }
    }
}
}

#include "types.h"
extern "C" {
extern u8 gUnknown_03002600[], gUnknown_03005268[];
void FUN_0802f328(u8 *options) {
    register u8 *values = gUnknown_03002600;
    register u32 value asm("r2") = values[0];
    register u32 maskValue = 3;
    register u32 mask3 = maskValue;
    register u32 field asm("r1") = maskValue & value;
    register u32 incoming asm("r3") = options[0];
    register u32 preserveValue = ~3u;
    register u32 preserve3 asm("r9") = preserveValue;
    value = preserveValue & incoming;
    value |= field;
    incoming = values[1];
    register u32 mask7 asm("r5") = 7;
    field = mask7 & incoming;
    field <<= 2;
    incoming = ~28u;
    value &= incoming;
    value |= field;
    incoming = values[2];
    field = mask7 & incoming;
    field <<= 5;
    incoming = 31;
    value &= incoming;
    value |= field;
    options[0] = value;
    field = values[3];
    value = mask3 & field;
    incoming = options[1];
    field = preserve3 & incoming;
    field |= value;
    incoming = values[4];
    register u32 mask1 asm("r4") = 1;
    value = mask1 & incoming;
    value <<= 2;
    incoming = ~4u;
    field &= incoming;
    field |= value;
    incoming = values[5];
    value = mask1 & incoming;
    value <<= 3;
    incoming = ~8u;
    field &= incoming;
    field |= value;
    incoming = values[6];
    value = mask3 & incoming;
    value <<= 4;
    incoming = ~48u;
    register u32 preserve48 = incoming;
    field &= incoming;
    field |= value;
    value = values[7];
    mask1 &= value;
    mask1 <<= 6;
    value = ~64u;
    field &= value;
    field |= mask1;
    options[1] = field;
    field = values[8];
    mask7 &= field;
    mask7 <<= 15;
    field = *(u32 *)options;
    value = 0xfffc7fff;
    field &= value;
    field |= mask7;
    *(u32 *)options = field;
    register u8 *players = gUnknown_03005268;
    value = players[0];
    field = mask3 & value;
    field <<= 2;
    incoming = options[2];
    value = ~12u;
    value &= incoming;
    value |= field;
    incoming = players[1];
    field = mask3 & incoming;
    field <<= 4;
    incoming = preserve48;
    value &= incoming;
    value |= field;
    incoming = players[2];
    field = mask3 & incoming;
    field <<= 6;
    incoming = 63;
    value &= incoming;
    value |= field;
    options[2] = value;
    field = players[3];
    value = mask3 & field;
    field = options[3];
    incoming = preserve3 & field;
    incoming |= value;
    options[3] = incoming;
}
}
#include "types.h"
extern "C" {
// Observed packed fields, not original names or source-language evidence.
struct PackedOptions {
    u32 field0 : 2;
    u32 field1 : 3;
    u32 field2 : 3;
    u32 field3 : 2;
    u32 field4 : 1;
    u32 field5 : 1;
    u32 field6 : 2;
    u32 field7 : 1;
    u32 field8 : 3;
    u32 player0 : 2;
    u32 player1 : 2;
    u32 player2 : 2;
    u32 player3 : 2;
    u32 unused : 6;
};
extern u8 gUnknown_03002600[], gUnknown_03005268[];
void FUN_0802f428(const PackedOptions *options) {
    gUnknown_03002600[0] = options->field0;
    gUnknown_03002600[1] = options->field1;
    gUnknown_03002600[2] = options->field2;
    gUnknown_03002600[3] = options->field3;
    gUnknown_03002600[4] = options->field4;
    gUnknown_03002600[5] = options->field5;
    gUnknown_03002600[6] = options->field6;
    gUnknown_03002600[7] = options->field7;
    gUnknown_03002600[8] = options->field8;
    gUnknown_03005268[0] = options->player0;
    gUnknown_03005268[1] = options->player1;
    gUnknown_03005268[2] = options->player2;
    gUnknown_03005268[3] = options->player3;
}
}

extern "C" {
void FUN_0802f488(const PackedOptions *argument) {
    register const PackedOptions *initial asm("r2") = argument;
    register const PackedOptions *options = initial;
    register u32 shifted asm("r0") = *(const u32 *)initial;
    shifted <<= 30;
    register u32 first asm("r4") = shifted >> 30;
    register u8 *values asm("r3") = gUnknown_03002600;
    register u32 incoming asm("r1") = values[0];
    register u32 mask3 = 3;
    asm volatile("" : "+r"(mask3));
    register u32 masked asm("r0") = mask3 & incoming;
    if (first != masked)
        values[0] = first;
    register u32 word asm("r6") = *(const u32 *)initial;
    shifted = word << 27;
    register u32 value = shifted >> 29;
    incoming = values[1];
    register u32 mask7 = 7;
    masked = mask7 & incoming;
    register u32 copy = word;
    if (value != masked)
        values[1] = value;
    shifted = copy << 24;
    value = shifted >> 29;
    incoming = values[2];
    masked = mask7 & incoming;
    if (value != masked)
        values[2] = value;
    shifted = copy << 22;
    value = shifted >> 30;
    incoming = values[3];
    masked = mask3 & incoming;
    if (value != masked)
        values[3] = value;
    shifted = copy << 21;
    value = shifted >> 31;
    incoming = values[4];
    register u32 mask1 = 1;
    asm volatile("" : "+r"(mask1));
    masked = mask1 & incoming;
    if (value != masked)
        values[4] = value;
    shifted = copy << 20;
    value = shifted >> 31;
    incoming = values[5];
    masked = mask1 & incoming;
    if (value != masked)
        values[5] = value;
    shifted = copy << 18;
    value = shifted >> 30;
    incoming = values[6];
    masked = mask3 & incoming;
    if (value != masked)
        values[6] = value;
    shifted = copy << 17;
    value = shifted >> 31;
    incoming = values[7];
    masked = mask1 & incoming;
    if (value != masked)
        values[7] = value;
    shifted = word << 14;
    value = shifted >> 29;
    incoming = values[8];
    masked = mask7 & incoming;
    if (value != masked)
        values[8] = value;
    register u8 *players = gUnknown_03005268;
    register u32 packed = *(const u32 *)options;
    players[0] = (packed << 12) >> 30;
    players[1] = (packed << 10) >> 30;
    players[2] = (packed << 8) >> 30;
    players[3] = (packed << 6) >> 30;
}
}
#include "types.h"
extern "C" {
// Observed packed fields, not original names or source-language evidence.
extern u8 gUnknown_03002600[], gUnknown_03005268[];
extern u8 gUnknown_030052e0;
extern const u8 gUnknown_0812f800[], gUnknown_0812f714[], gUnknown_0812f748[], gUnknown_0812f6d0[],
    gUnknown_0812f7a8[], gUnknown_0812f6e8[];
void FUN_0802df68(u8), FUN_0802ea64(u8);
void FUN_08020408(void *, const void *);
void FUN_0802f560(const PackedOptions *options) {
    if (options->field0 != (gUnknown_03002600[0] & 3)) {
        gUnknown_03002600[0] = options->field0;
        FUN_0802df68(0);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field1 != (gUnknown_03002600[1] & 7)) {
        gUnknown_03002600[1] = options->field1;
        FUN_0802df68(1);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field2 != (gUnknown_03002600[2] & 7)) {
        gUnknown_03002600[2] = options->field2;
        FUN_0802df68(1);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field3 != (gUnknown_03002600[3] & 3)) {
        gUnknown_03002600[3] = options->field3;
        FUN_0802df68(1);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field4 != (gUnknown_03002600[4] & 1)) {
        gUnknown_03002600[4] = options->field4;
        if (options->field4 != 0) {
            if (gUnknown_030052e0 == 2)
                FUN_08020408((void *)0x0600da00, gUnknown_0812f800);
            else
                FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
        } else {
            if (gUnknown_030052e0 == 2)
                FUN_08020408((void *)0x0600da00, gUnknown_0812f6d0);
            else
                FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        }
        FUN_0802df68(2);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field5 != (gUnknown_03002600[5] & 1)) {
        gUnknown_03002600[5] = options->field5;
        FUN_0802df68(3);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field6 != (gUnknown_03002600[6] & 3)) {
        gUnknown_03002600[6] = options->field6;
        FUN_0802df68(4);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field7 != (gUnknown_03002600[7] & 1)) {
        gUnknown_03002600[7] = options->field7;
        FUN_0802df68(5);
        FUN_0802ea64(gUnknown_030052e0);
    }
    if (options->field8 != (gUnknown_03002600[8] & 7)) {
        gUnknown_03002600[8] = options->field8;
        FUN_0802df68(6);
        FUN_0802ea64(gUnknown_030052e0);
    }
    gUnknown_03005268[0] = options->player0;
    gUnknown_03005268[1] = options->player1;
    gUnknown_03005268[2] = options->player2;
    gUnknown_03005268[3] = options->player3;
}
}
#include "types.h"
extern "C" {
extern u8 gUnknown_03002600[];
extern const u8 gUnknown_0812f6d0[], gUnknown_0812f6e8[], gUnknown_0812f714[], gUnknown_0812f748[],
    gUnknown_0812f778[], gUnknown_0812f7a8[], gUnknown_0812f7d4[], gUnknown_0812f800[];
void FUN_08020408(void *, const void *);
void FUN_0802f748(u8 selected) {
    switch (selected) {
    case 0:
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6d0);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f800);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f748);
        break;
    case 1:
        FUN_08020408((void *)0x0600d900, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f6e8);
        if (gUnknown_03002600[4] == 1)
            FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
        else
            FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
        break;
    case 2:
        FUN_08020408((void *)0x0600d980, gUnknown_0812f7d4);
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f800);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
        } else {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f6d0);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
            FUN_08020408((void *)0x0600db00, gUnknown_0812f778);
        }
        break;
    case 3:
        FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600db00, gUnknown_0812f778);
        break;
    case 4:
        if (gUnknown_03002600[4] == 1)
            FUN_08020408((void *)0x0600da80, gUnknown_0812f7d4);
        else
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6d0);
        FUN_08020408((void *)0x0600db00, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f778);
        break;
    case 5:
        FUN_08020408((void *)0x0600db00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f7a8);
        break;
    case 6:
        FUN_08020408((void *)0x0600db80, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f6d0);
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f714);
        break;
    }
}
}
#include "types.h"
extern "C" {
extern u8 gUnknown_03002600[];
extern const u8 gUnknown_0812f6d0[], gUnknown_0812f6e8[], gUnknown_0812f714[], gUnknown_0812f748[],
    gUnknown_0812f778[], gUnknown_0812f7a8[], gUnknown_0812f7d4[], gUnknown_0812f800[];
void FUN_08020408(void *, const void *);
void FUN_0802f94c(u8 selected) {
    switch (selected) {
    case 0:
        FUN_08020408((void *)0x0600db80, gUnknown_0812f778);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6d0);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f800);
        break;
    case 1:
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f6e8);
        break;
    case 2:
        FUN_08020408((void *)0x0600d900, gUnknown_0812f714);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f7d4);
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f800);
        } else {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f6d0);
        }
        break;
    case 3:
        FUN_08020408((void *)0x0600d980, gUnknown_0812f748);
        FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        break;
    case 4:
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f7d4);
        } else {
            FUN_08020408((void *)0x0600d980, gUnknown_0812f748);
            FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6d0);
        }
        FUN_08020408((void *)0x0600db00, gUnknown_0812f6e8);
        break;
    case 5:
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
        } else {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        }
        FUN_08020408((void *)0x0600db00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f6e8);
        break;
    case 6:
        FUN_08020408((void *)0x0600db00, gUnknown_0812f778);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f6d0);
        break;
    }
}
}
#include "types.h"
extern "C" {
extern u8 gUnknown_03002600[];
extern const u8 gUnknown_0812f6d0[], gUnknown_0812f6e8[], gUnknown_0812f714[], gUnknown_0812f748[],
    gUnknown_0812f778[], gUnknown_0812f7a8[], gUnknown_0812f7d4[], gUnknown_0812f800[];
void FUN_08020408(void *, const void *);
void FUN_0802fb58(u8 selected) {
    switch (selected) {
    case 0:
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6e8);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f714);
        break;
    case 1:
        FUN_08020408((void *)0x0600d900, gUnknown_0812f714);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f748);
        break;
    case 2:
        FUN_08020408((void *)0x0600d980, gUnknown_0812f748);
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
        } else {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
        }
        break;
    case 3:
        FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
        FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
        break;
    case 4:
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
        } else {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        }
        FUN_08020408((void *)0x0600db00, gUnknown_0812f778);
        break;
    case 5:
        FUN_08020408((void *)0x0600db00, gUnknown_0812f778);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f778);
        break;
    case 6:
        FUN_08020408((void *)0x0600db80, gUnknown_0812f778);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f7a8);
        break;
    }
}
void FUN_0802fcb4(u8 selected) {
    switch (selected) {
    case 0:
        FUN_08020408((void *)0x0600d880, gUnknown_0812f6d0);
        FUN_08020408((void *)0x0600d900, gUnknown_0812f800);
        break;
    case 1:
        FUN_08020408((void *)0x0600d900, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600d980, gUnknown_0812f6e8);
        break;
    case 2:
        FUN_08020408((void *)0x0600d980, gUnknown_0812f7d4);
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f800);
        } else {
            FUN_08020408((void *)0x0600da00, gUnknown_0812f6d0);
        }
        break;
    case 3:
        FUN_08020408((void *)0x0600da00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600da80, gUnknown_0812f6e8);
        break;
    case 4:
        if (gUnknown_03002600[4] == 1) {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f7d4);
        } else {
            FUN_08020408((void *)0x0600da80, gUnknown_0812f6d0);
        }
        FUN_08020408((void *)0x0600db00, gUnknown_0812f6e8);
        break;
    case 5:
        FUN_08020408((void *)0x0600db00, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600db80, gUnknown_0812f6e8);
        break;
    case 6:
        FUN_08020408((void *)0x0600db80, gUnknown_0812f7a8);
        FUN_08020408((void *)0x0600dc00, gUnknown_0812f6d0);
        break;
    }
}
}

#include "types.h"
struct Parts {
    u32 a;
    u8 b[12];
};
struct Allocation {
    u32 unknown[4];
    Parts parts;
};
struct Position {
    const Parts *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, unused;
};
struct MenuNode {
    void (*callback)(MenuNode *);
    u8 field4, previous, index, next;
    Position *position;
    Allocation *allocation;
};
extern "C" {
extern const u16 *const *gUnknown_030052f0;
extern const u16 *const *const gUnknown_08edc21c[];
extern u8 gUnknown_03002110[], gUnknown_03002600[], gUnknown_03005260;
extern u8 gUnknown_030052e0, gUnknown_030052e4, gUnknown_030052f8;
extern u32 gUnknown_03005254, gUnknown_03005258;
extern u16 gUnknown_03001b10[];
extern const u16 gUnknown_0812e608[], gUnknown_081327d4[];
extern const u8 gUnknown_0812f46c[], gUnknown_08132544[], gUnknown_0812f89c[], gUnknown_0812f828[];
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[], gUnknown_0812e6e8[];
extern const u8 gUnknown_0812f62c[], gUnknown_0812f714[], gUnknown_0812f748[];
extern const Position gUnknown_08edbe94[];
extern MenuNode gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void), (*gUnknown_03003150[])(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_0802df68(u8), FUN_0802ea64(u8);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020ad0(const u16 *), FUN_08020978(u32, u32, u16, u32);
void FUN_08020408(void *, const void *), FUN_08021000(void *, const u16 *, u32, u32, u16);
MenuNode *FUN_0801f7d0(void (*)(MenuNode *), u32, MenuNode *, u32);
void FUN_08030d20(MenuNode *), FUN_08030d58(MenuNode *), FUN_08030ca8(MenuNode *),
    FUN_0801f9d8(MenuNode *);
void FUN_08030e6c(MenuNode *), FUN_08030dac(MenuNode *), FUN_080301f4(void), FUN_080302a0(void);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16);
void FUN_0802fdf8(void) {
    gUnknown_030052f0 = gUnknown_08edc21c[gUnknown_03002110[119]];
    FUN_0801fbfc(gUnknown_0812e608, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    u32 zero1 = 0;
    CpuFastSet(&zero1, (void *)0x05000000, 0x01000100);
    LZ77UnCompVram(gUnknown_0812f46c, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x06004000);
    LZ77UnCompVram(gUnknown_0812f89c, (void *)0x06010000);
    u32 zero2 = 0;
    CpuFastSet(&zero2, (void *)0x0600f000, 0x01000200);
    LZ77UnCompVram(gUnknown_0812f828, (void *)0x0600f000);
    if (!gUnknown_03005254 || !gUnknown_03005260) {
        u16 tile = *(u16 *)0x0600f000;
        u16 *out = (u16 *)0x0600f480;
        for (u32 i = 0; i < 64; i++)
            *out++ = tile;
    }
    u32 zero3 = 0;
    CpuFastSet(&zero3, (void *)0x06017280, 0x01000200);
    u32 zero4 = 0;
    CpuFastSet(&zero4, (void *)0x0600e000, 0x01000200);
    u32 zero5 = 0;
    CpuFastSet(&zero5, (void *)0x06008000, 0x01000d88);
    register u16 *column asm("r2") = (u16 *)0x0600e0ca;
    u16 tile = 0x3001;
    u32 x = 0;
    do {
        u32 y = 0;
        register u16 *nextColumn asm("r5") = column + 1;
        u32 next = x + 1;
        do {
            *column = tile++;
            column += 32;
            y++;
        } while (y < 18);
        column = nextColumn;
        x = next;
    } while (x < 24);
    gUnknown_030052e0 = 0;
    gUnknown_030052f8 = 8;
    gUnknown_030052e4 = 16;
    FUN_0802df68(0);
    FUN_0802df68(1);
    FUN_0802df68(2);
    FUN_0802df68(3);
    FUN_0802df68(4);
    FUN_0802df68(5);
    FUN_0802df68(6);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x06017280, 30, 2, 0);
    u16 textX = gUnknown_0812e6e8[0];
    u16 textY = gUnknown_0812e6e8[1];
    const u16 *text = gUnknown_030052f0[gUnknown_0812e6e8[2]];
    textX -= (u8)(FUN_08020ad0(text) / 2);
    while (*text != 0xfffe) {
        FUN_08020978(textX + 2, textY + 2, *text, 6);
        textX += FUN_08020978(textX, textY, *text, 1);
        text++;
    }
    FUN_0802ea64(gUnknown_030052e0);
    u32 zero6 = 0;
    CpuFastSet(&zero6, (void *)0x0600d800, 0x01000200);
    LZ77UnCompVram(gUnknown_0812f62c, (void *)0x0600d900);
    if (gUnknown_03002600[4] == 1) {
        FUN_08020408((void *)0x0600da00, gUnknown_0812f714);
        FUN_08020408((void *)0x0600da80, gUnknown_0812f748);
    }
    u8 *out = (u8 *)0x0600d000;
    for (u32 row = 0; row < 4; row++) {
        for (u32 col = 0; col < 4; col++) {
            FUN_08021000(out, gUnknown_081327d4, 8, 8, 0xf200);
            out += 16;
        }
        u32 stride = 448;
        out += stride;
    }
    FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08030d58, 0, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_08030ca8, 4, gUnknown_03003e20, 0);
    register void (*callback)(MenuNode *) asm("r6") = FUN_0801f9d8;
    MenuNode *node = FUN_0801f7d0(callback, 16, gUnknown_03003e20, 0);
    const Position *positions = gUnknown_08edbe94;
    *node->position = positions[0];
    node = FUN_0801f7d0(callback, 16, gUnknown_03003e20, 0);
    *node->position = positions[1];
    node = FUN_0801f7d0(callback, 16, gUnknown_03003e20, 0);
    *node->position = positions[2];
    if (!gUnknown_03005254 || !gUnknown_03005260) {
        node = FUN_0801f7d0(callback, 16, gUnknown_03003e20, 0);
        asm volatile("" : : : "r7");
        *node->position = positions[3];
    }
    FUN_0801f7d0(FUN_08030e6c, 16, gUnknown_03003e20, 0);
    if (!gUnknown_03005254 || !gUnknown_03005260)
        FUN_0801f7d0(FUN_08030dac, 32, gUnknown_03003e20, 0);
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_080301f4;
    FUN_0801f618(4);
    gUnknown_03003150[1] = FUN_080302a0;
    *(volatile u16 *)0x04000208 = 0;
    volatile u16 *displayStatus = (volatile u16 *)0x04000004;
    u32 status = 296;
    register u16 writeStatus asm("r0") = status;
    *displayStatus = writeStatus;
    *(volatile u16 *)0x04000208 = 1;
    gUnknown_03005258 = 0;
    gUnknown_03001b10[1] = gUnknown_03001b10[2] = gUnknown_03001b10[3] = gUnknown_03001b10[4] =
        gUnknown_03001b10[5] = gUnknown_03001b10[6] = gUnknown_03001b10[7] = 0;
}
}
extern "C" {
extern u32 gUnknown_03005254, gUnknown_03005258;
extern u16 gUnknown_03001b10[];
extern u8 gUnknown_030052e0, gUnknown_0300525c, gUnknown_030052e4, gUnknown_0300138c;
extern u16 gUnknown_030052f4, gUnknown_03001378;
extern volatile u16 gUnknown_03007ff8;
extern unsigned long long gUnknown_03002610;
extern void (*gUnknown_03002030)(void), (*gUnknown_03003150[])(void);
void FUN_0802f328(u8 *), FUN_0803d1a0(void), FUN_08030390(void);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_0801f89c(void), FUN_0801fda0(void);
void FUN_08018a8c(void), FUN_0801f60c(void), FUN_0801fbd8(void), FUN_0801ffa4(u8);
u8 FUN_0802067c(void *, u32), FUN_0801fab0(u16);
void FUN_080301f4(void) {
    if (gUnknown_03005254) {
        gUnknown_03001b10[1] = 0x5678;
        FUN_0802f328((u8 *)&gUnknown_03001b10[2]);
        gUnknown_03001b10[4] = gUnknown_030052e0;
        if (gUnknown_03005254) {
            if (gUnknown_03005258 > 59) {
                if (FUN_0802067c((void *)0x05000000, 512)) {
                    gUnknown_03002030 = FUN_0803d1a0;
                    FUN_0801fb60();
                    FUN_0801fb94();
                    FUN_0801ff30();
                    FUN_0801f780();
                    FUN_080210d8();
                    FUN_0802110c();
                }
                return;
            }
            if (gUnknown_0300525c == FUN_0801fab0(0x2468))
                gUnknown_03005258 = 0;
            else
                gUnknown_03005258++;
        }
    }
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_080302a0(void) {
    if (gUnknown_0300138c)
        FUN_08018a8c();
    gUnknown_03003150[2] = FUN_08030390;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 296;
    *(volatile u16 *)0x04000208 = 1;
    *(volatile u16 *)0x0400000a = 0x1c0a;
    *(volatile u16 *)0x0400000c = 0x1b02;
    gUnknown_030052f4 = ((gUnknown_030052e0 * 16 + (gUnknown_030052e4 + 38)) << 8) | 40;
    FUN_0801f60c();
    gUnknown_03001378++;
    gUnknown_03007ff8 |= 1;
    FUN_0801fbd8();
    FUN_0801ffa4(0);
    gUnknown_03002610++;
}
}
extern "C" {
extern void (*gUnknown_03003150[])(void);
extern void (*gUnknown_03002030)(void);
extern u16 gUnknown_030052f4;
extern const u16 gUnknown_0812e608[];
void FUN_080185d8(void), FUN_08018654(void), FUN_080303cc(void);
void FUN_0801fc60(void), FUN_0801f600(void);
u32 FUN_08020ad0(const u16 *);
u32 FUN_08020978(u32, u32, u16, u32);
void CpuFastSet(const void *, void *, u32);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void), FUN_080184c8(void), FUN_08018c3c(void),
    FUN_08000210(void);
void FUN_0803035c(void) {
    gUnknown_03003150[1] = FUN_080185d8;
    gUnknown_03003150[2] = FUN_08018654;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 296;
    *(volatile u16 *)0x04000208 = 1;
}
void FUN_08030390(void) {
    gUnknown_03003150[2] = FUN_080303cc;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = gUnknown_030052f4;
    *(volatile u16 *)0x04000208 = 1;
    FUN_0801fc60();
    FUN_0801f600();
}
void FUN_080303cc(void) {
    *(volatile u16 *)0x0400000a = 0x1c09;
    *(volatile u16 *)0x0400000c = 0x1b01;
}
void FUN_080303ec(u8 x, u8 y, const u16 *text, u8 alignment) {
    switch (alignment) {
    case 1:
        x -= FUN_08020ad0(text);
        break;
    case 2:
        x -= FUN_08020ad0(text) / 2;
        break;
    }
    while (*text != 0xfffe) {
        x += FUN_08020978(x, y, *text, 2);
        text++;
    }
}
void FUN_0803044c(u8 column) {
    if (column != 255) {
        u32 fill = 0;
        u32 *row = (u32 *)(0x06008020 + column * 64);
        register u32 y asm("r3") = 0;
        do {
            u32 x = 0;
            register u32 next asm("r0") = y + 1;
            u32 *destination = row;
            do {
                *destination++ = fill;
                x++;
            } while (x < 16);
            row += 144;
            y = next;
        } while (y < 24);
    } else {
        u32 zero = 0;
        CpuFastSet(&zero, (void *)0x06017a00, 0x01000180);
    }
}
void FUN_080304a4(void) {
    FUN_0801fbfc(gUnknown_0812e608, 16);
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    FUN_0803035c();
    FUN_080184c8();
    FUN_08018c3c();
    gUnknown_03002030 = FUN_08000210;
}
}
extern "C" {
extern u8 gUnknown_03005260, gUnknown_030052e0, gUnknown_03002600[], gUnknown_03005268[];
extern u16 gUnknown_030048e0[];
extern s16 gUnknown_030016f0[][8];
void FUN_08030c08(MenuNode *), FUN_08030ac8(MenuNode *), FUN_08030b68(MenuNode *);
void FUN_08030960(MenuNode *), FUN_08030a30(MenuNode *), FUN_08030a8c(MenuNode *);
void FUN_08029200(void), FUN_0801f618(u16);
void FUN_0802df68(u8), FUN_0802ea64(u8), FUN_0802f748(u8), FUN_0802f560(const PackedOptions *);
void FUN_080304e4(MenuNode *node) {
    if (gUnknown_03005260 == 0) {
        if ((gUnknown_030048e0[2] & 4) && (gUnknown_030048e0[0] & 8))
            node->callback = FUN_08030c08;
        if ((gUnknown_030048e0[2] & 8) && (gUnknown_030048e0[0] & 4))
            node->callback = FUN_08030c08;
        if (gUnknown_030048e0[2] & 256) {
            node->callback = FUN_08030ac8;
            FUN_08029200();
        } else if (gUnknown_030048e0[2] & 512) {
            node->callback = FUN_08030b68;
            FUN_08029200();
        }
        if (gUnknown_030048e0[2] & 64) {
            node->callback = FUN_08030960;
            FUN_0801f618(401);
        } else if (gUnknown_030048e0[2] & 128) {
            node->callback = FUN_08030a30;
            FUN_0801f618(401);
        }
        if (gUnknown_030048e0[2] & 32) {
            FUN_0801f618(401);
            switch (gUnknown_030052e0) {
            case 0:
                if (gUnknown_03002600[0] == 0)
                    gUnknown_03002600[0] = 2;
                else
                    gUnknown_03002600[0]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 1:
                if (gUnknown_03002600[0] == 0) {
                    if (gUnknown_03002600[1] == 0)
                        gUnknown_03002600[1] = 4;
                    else
                        gUnknown_03002600[1]--;
                } else if (gUnknown_03002600[0] == 1) {
                    if (gUnknown_03002600[3] == 0)
                        gUnknown_03002600[3] = 3;
                    else
                        gUnknown_03002600[3]--;
                } else if (gUnknown_03002600[0] == 2) {
                    if (gUnknown_03002600[2] == 0)
                        gUnknown_03002600[2] = 4;
                    else
                        gUnknown_03002600[2]--;
                }
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 2:
                if (gUnknown_03002600[4] == 0)
                    gUnknown_03002600[4] = 1;
                else
                    gUnknown_03002600[4]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                FUN_0802f748(gUnknown_030052e0);
                if (gUnknown_03002600[4]) {
                    gUnknown_03005268[0] = 0;
                    gUnknown_03005268[1] = 2;
                    gUnknown_03005268[2] = 0;
                    gUnknown_03005268[3] = 2;
                } else {
                    gUnknown_03005268[0] = 0;
                    gUnknown_03005268[1] = 0;
                    gUnknown_03005268[2] = 0;
                    gUnknown_03005268[3] = 0;
                }
                break;
            case 3:
                if (gUnknown_03002600[5] == 0)
                    gUnknown_03002600[5] = 1;
                else
                    gUnknown_03002600[5]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 4:
                if (gUnknown_03002600[6] == 0)
                    gUnknown_03002600[6] = 3;
                else
                    gUnknown_03002600[6]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 5:
                if (gUnknown_03002600[7] == 0)
                    gUnknown_03002600[7] = 1;
                else
                    gUnknown_03002600[7]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 6:
                gUnknown_03002600[8]++;
                if (gUnknown_03002600[8] > 4)
                    gUnknown_03002600[8] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            }
        } else if (gUnknown_030048e0[2] & 16) {
            FUN_0801f618(401);
            switch (gUnknown_030052e0) {
            case 0:
                gUnknown_03002600[0]++;
                if (gUnknown_03002600[0] > 2)
                    gUnknown_03002600[0] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 1:
                if (gUnknown_03002600[0] == 0) {
                    gUnknown_03002600[1]++;
                    if (gUnknown_03002600[1] > 4)
                        gUnknown_03002600[1] = 0;
                } else if (gUnknown_03002600[0] == 1) {
                    gUnknown_03002600[3]++;
                    if (gUnknown_03002600[3] > 3)
                        gUnknown_03002600[3] = 0;
                } else if (gUnknown_03002600[0] == 2) {
                    gUnknown_03002600[2]++;
                    if (gUnknown_03002600[2] > 4)
                        gUnknown_03002600[2] = 0;
                }
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 2:
                gUnknown_03002600[4]++;
                if (gUnknown_03002600[4] > 1)
                    gUnknown_03002600[4] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                FUN_0802f748(gUnknown_030052e0);
                if (gUnknown_03002600[4]) {
                    gUnknown_03005268[0] = 0;
                    gUnknown_03005268[1] = 2;
                    gUnknown_03005268[2] = 0;
                    gUnknown_03005268[3] = 2;
                } else {
                    gUnknown_03005268[0] = 0;
                    gUnknown_03005268[1] = 0;
                    gUnknown_03005268[2] = 0;
                    gUnknown_03005268[3] = 0;
                }
                break;
            case 3:
                gUnknown_03002600[5]++;
                if (gUnknown_03002600[5] > 1)
                    gUnknown_03002600[5] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 4:
                gUnknown_03002600[6]++;
                if (gUnknown_03002600[6] > 3)
                    gUnknown_03002600[6] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 5:
                gUnknown_03002600[7]++;
                if (gUnknown_03002600[7] > 1)
                    gUnknown_03002600[7] = 0;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            case 6:
                if (gUnknown_03002600[8] == 0)
                    gUnknown_03002600[8] = 4;
                else
                    gUnknown_03002600[8]--;
                FUN_0802df68(gUnknown_030052e0);
                FUN_0802ea64(gUnknown_030052e0);
                break;
            }
        }
    } else {
        if (gUnknown_030016f0[0][1] == 0x5678) {
            FUN_0802f560((const PackedOptions *)&gUnknown_030016f0[0][2]);
            if (gUnknown_030016f0[0][4] != gUnknown_030052e0) {
                *(u16 *)node->allocation = gUnknown_030016f0[0][4];
                node->callback = FUN_08030a8c;
            }
        }
        if (gUnknown_030016f0[0][1] == 0x6789) {
            FUN_0802f560((const PackedOptions *)&gUnknown_030016f0[0][2]);
            if (gUnknown_030016f0[0][4] != gUnknown_030052e0) {
                *(u16 *)node->allocation = gUnknown_030016f0[0][4];
                node->callback = FUN_08030a8c;
            }
            node->callback = FUN_08030ac8;
        }
        if (gUnknown_030016f0[0][1] == 0x7890) {
            FUN_0802f560((const PackedOptions *)&gUnknown_030016f0[0][2]);
            if (gUnknown_030016f0[0][4] != gUnknown_030052e0) {
                *(u16 *)node->allocation = gUnknown_030016f0[0][4];
                node->callback = FUN_08030a8c;
            }
            node->callback = FUN_08030b68;
        }
        if (gUnknown_030016f0[0][1] == 0x7891) {
            FUN_0802f560((const PackedOptions *)&gUnknown_030016f0[0][2]);
            if (gUnknown_030016f0[0][4] != gUnknown_030052e0) {
                *(u16 *)node->allocation = gUnknown_030016f0[0][4];
                node->callback = FUN_08030a8c;
            }
            node->callback = FUN_08030c08;
        }
    }
    return;
}
}

extern "C" {
extern u8 gUnknown_030052e0, gUnknown_030052f8;
extern u8 gUnknown_030052e8[];
void FUN_0802fb58(u8), FUN_0802fcb4(u8), FUN_0802ea64(u8);
void FUN_080309c0(MenuNode *), FUN_080309e0(MenuNode *), FUN_08030a08(MenuNode *),
    FUN_080304e4(MenuNode *);
void FUN_08030960(MenuNode *node) {
    if (gUnknown_030052f8 > 2) {
        gUnknown_030052f8 -= 2;
    } else {
        gUnknown_030052f8 = 0;
        FUN_0802fb58(gUnknown_030052e0);
        if (gUnknown_030052e0 == 0)
            gUnknown_030052e0 = 6;
        else
            gUnknown_030052e0--;
        if (!gUnknown_030052e8[gUnknown_030052e0])
            gUnknown_030052e0--;
        node->callback = FUN_080309c0;
    }
}
void FUN_080309c0(MenuNode *node) {
    FUN_0802ea64(gUnknown_030052e0);
    node->callback = FUN_080309e0;
}
void FUN_080309e0(MenuNode *node) {
    FUN_0802fcb4(gUnknown_030052e0);
    gUnknown_030052f8 = 1;
    node->callback = FUN_08030a08;
}
void FUN_08030a08(MenuNode *node) {
    if (gUnknown_030052f8 < 8) {
        gUnknown_030052f8 += 2;
    } else {
        gUnknown_030052f8 = 8;
        node->callback = FUN_080304e4;
    }
}
void FUN_08030a30(MenuNode *node) {
    if (gUnknown_030052f8 > 2) {
        gUnknown_030052f8 -= 2;
    } else {
        gUnknown_030052f8 = 0;
        FUN_0802fb58(gUnknown_030052e0);
        gUnknown_030052e0++;
        if (gUnknown_030052e0 > 6)
            gUnknown_030052e0 = 0;
        if (!gUnknown_030052e8[gUnknown_030052e0])
            gUnknown_030052e0++;
        node->callback = FUN_080309c0;
    }
}
void FUN_08030a8c(MenuNode *node) {
    if (gUnknown_030052f8 > 2) {
        gUnknown_030052f8 -= 2;
    } else {
        u16 *data = (u16 *)node->allocation;
        gUnknown_030052f8 = 0;
        FUN_0802fb58(gUnknown_030052e0);
        gUnknown_030052e0 = *data;
        node->callback = FUN_080309c0;
    }
}
}
extern "C" {
extern u16 gUnknown_03001b10[];
extern s16 gUnknown_030016f0[][8];
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern void (*gUnknown_03002030)(void);
void FUN_0801f718(u16, u16), FUN_0801f618(u16);
u8 FUN_0802067c(void *, u32);
void FUN_0803035c(void), FUN_080217d0(u32);
void FUN_08029250(void), FUN_080340b8(void), FUN_080304a4(void);
void FUN_08030b38(MenuNode *), FUN_08030bd8(MenuNode *), FUN_08030c78(MenuNode *);
void FUN_08030ac8(MenuNode *node) {
    gUnknown_03001b10[1] = 0x6789;
    u32 ready = 1;
    for (u32 i = 0; i < gUnknown_0300525c; i++) {
        if (i != gUnknown_03005260 && gUnknown_030016f0[i][1] != 0x6789)
            ready = 0;
    }
    if (ready) {
        node->callback = FUN_08030b38;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    }
}
void FUN_08030b38(MenuNode *) {
    if (FUN_0802067c((void *)0x05000000, 512)) {
        FUN_0803035c();
        gUnknown_03002030 = FUN_08029250;
        FUN_080217d0(0);
    }
}
void FUN_08030b68(MenuNode *node) {
    gUnknown_03001b10[1] = 0x7890;
    u32 ready = 1;
    for (u32 i = 0; i < gUnknown_0300525c; i++) {
        if (i != gUnknown_03005260 && gUnknown_030016f0[i][1] != 0x7890)
            ready = 0;
    }
    if (ready) {
        node->callback = FUN_08030bd8;
        FUN_0801f718(4, 120);
        FUN_0801f618(404);
    }
}
void FUN_08030bd8(MenuNode *) {
    if (FUN_0802067c((void *)0x05000000, 512)) {
        FUN_0803035c();
        gUnknown_03002030 = FUN_080340b8;
        FUN_080217d0(0);
    }
}
void FUN_08030c08(MenuNode *node) {
    gUnknown_03001b10[1] = 0x7891;
    u32 ready = 1;
    for (u32 i = 0; i < gUnknown_0300525c; i++) {
        if (i != gUnknown_03005260 && gUnknown_030016f0[i][1] != 0x7891)
            ready = 0;
    }
    if (ready) {
        node->callback = FUN_08030c78;
        FUN_0801f718(4, 120);
        FUN_0801f618(405);
    }
}
void FUN_08030c78(MenuNode *) {
    if (FUN_0802067c((void *)0x05000000, 512)) {
        FUN_0803035c();
        gUnknown_03002030 = FUN_080304a4;
        FUN_080217d0(0);
    }
}
}
extern "C" {
extern const u16 gUnknown_0812e6f4[], gUnknown_08132714[], gUnknown_0812f3d0[];
extern const u8 gUnknown_08edc234[];
extern u8 gUnknown_030052e0, gUnknown_030052e4;
u8 FUN_08020500(void *, const u16 *, u16);
void FUN_080304e4(MenuNode *), FUN_0801fba0(u16, u16);
void FUN_08030ca8(MenuNode *node) {
    u32 first = !FUN_08020500((void *)0x05000000, gUnknown_0812e6f4, 80);
    u32 pending = first;
    u32 second;
    if (!FUN_08020500((void *)0x050001e0, gUnknown_08132714, 16)) {
        second = 1;
    } else {
        second = (u8)pending;
    }
    asm volatile("" : "+r"(second));
    pending = second;
    u32 third;
    if (!FUN_08020500((void *)0x05000200, gUnknown_0812f3d0, 64)) {
        third = pending | 1;
    } else {
        third = (u8)pending;
    }
    if (!third)
        node->callback = FUN_080304e4;
}
void FUN_08030d20(MenuNode *node) {
    (node->allocation->unknown[0])--;
    FUN_0801fba0(30, (node->allocation->unknown[0] & 510) >> 1);
}
void FUN_08030d3c(MenuNode *node) {
    (node->allocation->unknown[0])--;
    FUN_0801fba0(28, (node->allocation->unknown[0] & 510) >> 1);
}
void FUN_08030d58(MenuNode *) {
    if (gUnknown_030052e4 < gUnknown_08edc234[gUnknown_030052e0])
        gUnknown_030052e4++;
    else if (gUnknown_030052e4 > gUnknown_08edc234[gUnknown_030052e0])
        gUnknown_030052e4--;
    FUN_0801fba0(22, 2 - gUnknown_030052e4);
    FUN_0801fba0(26, -gUnknown_030052e4);
}
}

extern "C" {
extern const Parts gUnknown_08130074, gUnknown_0813015c, gUnknown_08130084;
extern u8 gUnknown_030052e8[], gUnknown_030052e0, gUnknown_030052e4, gUnknown_030052f8;
void FUN_08030e1c(MenuNode *), FUN_08030ed4(MenuNode *);
void FUN_0801fed8(u8, u8);
void FUN_08030dac(MenuNode *node) {
    Allocation *data = node->allocation;
    data->parts = gUnknown_08130074;
    data->parts.b[1] = -(gUnknown_030052e8[gUnknown_030052e0] + 12);
    node->position->parts = &data->parts;
    node->position->tile = 0;
    node->position->x = 207;
    node->position->y = gUnknown_030052e0 * 16 + (gUnknown_030052e4 + 20);
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 4;
    node->callback = FUN_08030e1c;
}
void FUN_08030e1c(MenuNode *node) {
    Allocation *data = node->allocation;
    data->parts.b[1] = -(gUnknown_030052e8[gUnknown_030052e0] + 12);
    node->position->x = gUnknown_030052f8 + 199;
    node->position->y = (gUnknown_030052e0 * 16 + 28) - gUnknown_030052f8 + gUnknown_030052e4;
    FUN_0801fed8(node->index, 0);
}
void FUN_08030e6c(MenuNode *node) {
    if (gUnknown_030052e0 == 1 || gUnknown_030052e0 == 3)
        node->position->parts = &gUnknown_0813015c;
    else
        node->position->parts = &gUnknown_08130084;
    node->position->tile = 0;
    node->position->x = 120;
    node->position->y = gUnknown_030052e0 * 16 + (gUnknown_030052e4 + 16);
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 8;
    node->callback = FUN_08030ed4;
}
void FUN_08030ed4(MenuNode *node) {
    if (gUnknown_030052e0 == 1 || gUnknown_030052e0 == 3)
        node->position->parts = &gUnknown_0813015c;
    else
        node->position->parts = &gUnknown_08130084;
    node->position->x = gUnknown_030052f8 + 120;
    node->position->y = (gUnknown_030052e0 * 16 + 16) - gUnknown_030052f8 + gUnknown_030052e4;
    if (gUnknown_030052f8)
        FUN_0801fed8(node->index, 0);
}
}

// Interpreted private metadata; opaque glyph and sprite assets remain external.
extern "C" {
const u16 *const *gUnknown_030052f0 __attribute__((section(".bss"))) = 0;
extern const Parts gUnknown_0813005c, gUnknown_08130054, gUnknown_08130234;
extern const u16 gUnknown_0812e7b4[];
extern const u16 gUnknown_0812e7bc[];
extern const u16 gUnknown_0812e7c4[];
extern const u16 gUnknown_0812e7d0[];
extern const u16 gUnknown_0812e7dc[];
extern const u16 gUnknown_0812e7e4[];
extern const u16 gUnknown_0812e7ec[];
extern const u16 gUnknown_0812e7f8[];
extern const u16 gUnknown_0812e800[];
extern const u16 gUnknown_0812e810[];
extern const u16 gUnknown_0812e820[];
extern const u16 gUnknown_0812e830[];
extern const u16 gUnknown_0812e838[];
extern const u16 gUnknown_0812e83c[];
extern const u16 gUnknown_0812e840[];
extern const u16 gUnknown_0812e848[];
extern const u16 gUnknown_0812e850[];
extern const u16 gUnknown_0812e858[];
extern const u16 gUnknown_0812e860[];
extern const u16 gUnknown_0812e864[];
extern const u16 gUnknown_0812e870[];
extern const u16 gUnknown_0812e87c[];
extern const u16 gUnknown_0812e888[];
extern const u16 gUnknown_0812e894[];
extern const u16 gUnknown_0812e89c[];
extern const u16 gUnknown_0812e8a4[];
extern const u16 gUnknown_0812e8b0[];
extern const u16 gUnknown_0812e8bc[];
extern const u16 gUnknown_0812e8c8[];
extern const u16 gUnknown_0812e8d4[];
extern const u16 gUnknown_0812e8e0[];
extern const u16 gUnknown_0812e8e8[];
extern const u16 gUnknown_0812e8f0[];
extern const u16 gUnknown_0812e8f8[];
extern const u16 gUnknown_0812e904[];
extern const u16 gUnknown_0812e930[];
extern const u16 gUnknown_0812e93c[];
extern const u16 gUnknown_0812e944[];
extern const u16 gUnknown_0812e950[];
extern const u16 gUnknown_0812e964[];
extern const u16 gUnknown_0812e978[];
extern const u16 gUnknown_0812e984[];
extern const u16 gUnknown_0812e9a0[];
extern const u16 gUnknown_0812e9a8[];
extern const u16 gUnknown_0812e9c0[];
extern const u16 gUnknown_0812e9d4[];
extern const u16 gUnknown_0812e9f0[];
extern const u16 gUnknown_0812e9f8[];
extern const u16 gUnknown_0812e9fc[];
extern const u16 gUnknown_0812ea00[];
extern const u16 gUnknown_0812ea08[];
extern const u16 gUnknown_0812ea10[];
extern const u16 gUnknown_0812ea18[];
extern const u16 gUnknown_0812ea20[];
extern const u16 gUnknown_0812ea24[];
extern const u16 gUnknown_0812ea30[];
extern const u16 gUnknown_0812ea3c[];
extern const u16 gUnknown_0812ea48[];
extern const u16 gUnknown_0812ea54[];
extern const u16 gUnknown_0812ea5c[];
extern const u16 gUnknown_0812ea64[];
extern const u16 gUnknown_0812ea70[];
extern const u16 gUnknown_0812ea7c[];
extern const u16 gUnknown_0812ea88[];
extern const u16 gUnknown_0812ea94[];
extern const u16 gUnknown_0812eab4[];
extern const u16 gUnknown_0812eac8[];
extern const u16 gUnknown_0812ead8[];
extern const u16 gUnknown_0812eae4[];
extern const u16 gUnknown_0812eb04[];
extern const u16 gUnknown_0812eb3c[];
extern const u16 gUnknown_0812eb48[];
extern const u16 gUnknown_0812eb50[];
extern const u16 gUnknown_0812eb5c[];
extern const u16 gUnknown_0812eb6c[];
extern const u16 gUnknown_0812eb8c[];
extern const u16 gUnknown_0812eb94[];
extern const u16 gUnknown_0812ebb0[];
extern const u16 gUnknown_0812ebb8[];
extern const u16 gUnknown_0812ebd8[];
extern const u16 gUnknown_0812ebf0[];
extern const u16 gUnknown_0812ec0c[];
extern const u16 gUnknown_0812ec14[];
extern const u16 gUnknown_0812ec18[];
extern const u16 gUnknown_0812ec1c[];
extern const u16 gUnknown_0812ec24[];
extern const u16 gUnknown_0812ec2c[];
extern const u16 gUnknown_0812ec34[];
extern const u16 gUnknown_0812ec3c[];
extern const u16 gUnknown_0812ec40[];
extern const u16 gUnknown_0812ec48[];
extern const u16 gUnknown_0812ec50[];
extern const u16 gUnknown_0812ec58[];
extern const u16 gUnknown_0812ec64[];
extern const u16 gUnknown_0812ec6c[];
extern const u16 gUnknown_0812ec74[];
extern const u16 gUnknown_0812ec7c[];
extern const u16 gUnknown_0812ec84[];
extern const u16 gUnknown_0812ec8c[];
extern const u16 gUnknown_0812ec94[];
extern const u16 gUnknown_0812ecb4[];
extern const u16 gUnknown_0812ecc8[];
extern const u16 gUnknown_0812ecd4[];
extern const u16 gUnknown_0812ece4[];
extern const u16 gUnknown_0812ed0c[];
extern const u16 gUnknown_0812ed50[];
extern const u16 gUnknown_0812ed5c[];
extern const u16 gUnknown_0812ed64[];
extern const u16 gUnknown_0812ed70[];
extern const u16 gUnknown_0812ed84[];
extern const u16 gUnknown_0812ed9c[];
extern const u16 gUnknown_0812eda8[];
extern const u16 gUnknown_0812edc8[];
extern const u16 gUnknown_0812edd0[];
extern const u16 gUnknown_0812edf4[];
extern const u16 gUnknown_0812ee00[];
extern const u16 gUnknown_0812ee1c[];
extern const u16 gUnknown_0812ee24[];
extern const u16 gUnknown_0812ee28[];
extern const u16 gUnknown_0812ee2c[];
extern const u16 gUnknown_0812ee34[];
extern const u16 gUnknown_0812ee3c[];
extern const u16 gUnknown_0812ee44[];
extern const u16 gUnknown_0812ee4c[];
extern const u16 gUnknown_0812ee50[];
extern const u16 gUnknown_0812ee5c[];
extern const u16 gUnknown_0812ee68[];
extern const u16 gUnknown_0812ee74[];
extern const u16 gUnknown_0812ee80[];
extern const u16 gUnknown_0812ee88[];
extern const u16 gUnknown_0812ee90[];
extern const u16 gUnknown_0812ee9c[];
extern const u16 gUnknown_0812eea8[];
extern const u16 gUnknown_0812eeb4[];
extern const u16 gUnknown_0812eec0[];
extern const u16 gUnknown_0812eed8[];
extern const u16 gUnknown_0812eee4[];
extern const u16 gUnknown_0812ef08[];
extern const u16 gUnknown_0812ef18[];
extern const u16 gUnknown_0812ef38[];
extern const u16 gUnknown_0812ef74[];
extern const u16 gUnknown_0812ef84[];
extern const u16 gUnknown_0812ef8c[];
extern const u16 gUnknown_0812ef98[];
extern const u16 gUnknown_0812efb4[];
extern const u16 gUnknown_0812efc0[];
extern const u16 gUnknown_0812efcc[];
extern const u16 gUnknown_0812efec[];
extern const u16 gUnknown_0812eff4[];
extern const u16 gUnknown_0812f020[];
extern const u16 gUnknown_0812f038[];
extern const u16 gUnknown_0812f054[];
extern const u16 gUnknown_0812f05c[];
extern const u16 gUnknown_0812f060[];
extern const u16 gUnknown_0812f064[];
extern const u16 gUnknown_0812f06c[];
extern const u16 gUnknown_0812f074[];
extern const u16 gUnknown_0812f07c[];
extern const u16 gUnknown_0812f084[];
extern const u16 gUnknown_0812f088[];
extern const u16 gUnknown_0812f094[];
extern const u16 gUnknown_0812f0a0[];
extern const u16 gUnknown_0812f0ac[];
extern const u16 gUnknown_0812f0b8[];
extern const u16 gUnknown_0812f0c0[];
extern const u16 gUnknown_0812f0c8[];
extern const u16 gUnknown_0812f0d4[];
extern const u16 gUnknown_0812f0e0[];
extern const u16 gUnknown_0812f0ec[];
extern const u16 gUnknown_0812f0f8[];
extern const u16 gUnknown_0812f114[];
extern const u16 gUnknown_0812f124[];
extern const u16 gUnknown_0812f130[];
extern const u16 gUnknown_0812f140[];
extern const u16 gUnknown_0812f168[];
extern const u16 gUnknown_0812f1b0[];
extern const u16 gUnknown_0812f1bc[];
extern const u16 gUnknown_0812f1c4[];
extern const u16 gUnknown_0812f1d4[];
extern const u16 gUnknown_0812f1f0[];
extern const u16 gUnknown_0812f204[];
extern const u16 gUnknown_0812f210[];
extern const u16 gUnknown_0812f230[];
extern const u16 gUnknown_0812f238[];
extern const u16 gUnknown_0812f25c[];
extern const u16 gUnknown_0812f270[];
extern const u16 gUnknown_0812f294[];
extern const u16 gUnknown_0812f29c[];
extern const u16 gUnknown_0812f2a0[];
extern const u16 gUnknown_0812f2a4[];
extern const u16 gUnknown_0812f2ac[];
extern const u16 gUnknown_0812f2b4[];
extern const u16 gUnknown_0812f2bc[];
extern const u16 gUnknown_0812f2c4[];
extern const u16 gUnknown_0812f2c8[];
extern const u16 gUnknown_0812f2d4[];
extern const u16 gUnknown_0812f2e0[];
extern const u16 gUnknown_0812f2ec[];
extern const u16 gUnknown_0812f2f8[];
extern const u16 gUnknown_0812f300[];
extern const u16 gUnknown_0812f308[];
extern const u16 gUnknown_0812f314[];
extern const u16 gUnknown_0812f320[];
extern const u16 gUnknown_0812f32c[];
extern const u16 gUnknown_0812f338[];
extern const u16 gUnknown_0812f354[];
extern const u16 gUnknown_0812f364[];
extern const u16 gUnknown_0812f370[];
extern const u16 gUnknown_0812f37c[];
extern const u16 gUnknown_0812f390[];
extern const u16 gUnknown_0812e608[] __attribute__((section(".rodata.display"))) = {
    0x0,  0x0,    // Register offset / value
    0x8,  0x1e00, // Register offset / value
    0x10, 0x0,    // Register offset / value
    0x12, 0x0,    // Register offset / value
    0xa,  0x1c09, // Register offset / value
    0x14, 0x0,    // Register offset / value
    0x16, 0xffee, // Register offset / value
    0xc,  0x1b01, // Register offset / value
    0x18, 0x0,    // Register offset / value
    0x1a, 0xffec, // Register offset / value
    0xe,  0x1a03, // Register offset / value
    0x1c, 0x0,    // Register offset / value
    0x1e, 0x0,    // Register offset / value
    0x50, 0x3f41, // Register offset / value
    0x52, 0x808,  // Register offset / value
    0x54, 0x0,    // Register offset / value
};
extern const TextDescriptor gUnknown_0812e648[] __attribute__((section(".rodata.display"))) = {
    {0, 0, 0, 0},
};
extern const TextDescriptor gUnknown_0812e64c[] __attribute__((section(".rodata.display"))) = {
    {0, 32, 7, 0},
};
extern const TextDescriptor gUnknown_0812e650[] __attribute__((section(".rodata.display"))) = {
    {0, 64, 9, 0},
};
extern const TextDescriptor gUnknown_0812e654[] __attribute__((section(".rodata.display"))) = {
    {0, 80, 10, 0},
};
extern const TextDescriptor gUnknown_0812e658[] __attribute__((section(".rodata.display"))) = {
    {0, 96, 11, 0},
};
extern const TextDescriptor gUnknown_0812e65c[] __attribute__((section(".rodata.display"))) = {
    {16, 16, 4, 0},
};
extern const TextDescriptor gUnknown_0812e660[] __attribute__((section(".rodata.display"))) = {
    {16, 16, 5, 0},
};
extern const TextDescriptor gUnknown_0812e664[] __attribute__((section(".rodata.display"))) = {
    {16, 16, 6, 0},
};
extern const TextDescriptor gUnknown_0812e668[] __attribute__((section(".rodata.display"))) = {
    {16, 48, 8, 0},
};
extern const TextDescriptor gUnknown_0812e66c[] __attribute__((section(".rodata.display"))) = {
    {160, 0, 1, 1},
    {160, 0, 2, 1},
    {160, 0, 3, 1},
};
extern const TextDescriptor gUnknown_0812e678[] __attribute__((section(".rodata.display"))) = {
    {160, 16, 13, 1}, {160, 16, 14, 1}, {160, 16, 15, 1}, {160, 16, 16, 1}, {160, 16, 17, 1},
};
extern const TextDescriptor gUnknown_0812e68c[] __attribute__((section(".rodata.display"))) = {
    {160, 16, 12, 1}, {160, 16, 13, 1}, {160, 16, 14, 1},
    {160, 16, 15, 1}, {160, 16, 16, 1}, {160, 16, 18, 1},
};
extern const TextDescriptor gUnknown_0812e6a4[] __attribute__((section(".rodata.display"))) = {
    {160, 16, 19, 1},
    {160, 16, 20, 1},
    {160, 16, 21, 1},
    {160, 16, 22, 1},
};
extern const TextDescriptor gUnknown_0812e6b4[] __attribute__((section(".rodata.display"))) = {
    {160, 48, 24, 1},
    {160, 48, 23, 1},
};
extern const TextDescriptor gUnknown_0812e6bc[] __attribute__((section(".rodata.display"))) = {
    {160, 64, 25, 1},
    {160, 64, 26, 1},
    {160, 64, 27, 1},
    {160, 64, 28, 1},
};
extern const TextDescriptor gUnknown_0812e6cc[] __attribute__((section(".rodata.display"))) = {
    {160, 80, 23, 1},
    {160, 80, 24, 1},
};
extern const TextDescriptor gUnknown_0812e6d4[] __attribute__((section(".rodata.display"))) = {
    {160, 96, 29, 1}, {160, 96, 30, 1}, {160, 96, 31, 1}, {160, 96, 32, 1}, {160, 96, 33, 1},
};
extern const u8 gUnknown_0812e6e8[] __attribute__((section(".rodata.display"))) = {120, 0, 34, 2};
extern const TextDescriptor gUnknown_0812e6ec[] __attribute__((section(".rodata.display"))) = {
    {160, 32, 23, 1},
    {160, 32, 24, 1},
};
extern const Position gUnknown_08edbe94[] = {
    {&gUnknown_0813005c, 120, 16, 192, 0, 0, 0, 0, 0, 0},
    {&gUnknown_08130054, 32, 16, 240, 0, 0, 0, 0, 0, 0},
    {&gUnknown_08130054, 208, 16, 272, 0, 0, 0, 0, 0, 0},
    {&gUnknown_08130234, 120, 144, 916, 0, 0, 0, 0, 0, 0},
};
extern const u16 *const gUnknown_08edbed4[] = {
    gUnknown_0812e7b4, gUnknown_0812e7bc, gUnknown_0812e7c4, gUnknown_0812e7d0, gUnknown_0812e7dc,
    gUnknown_0812e7e4, gUnknown_0812e7ec, gUnknown_0812e7f8, gUnknown_0812e800, gUnknown_0812e810,
    gUnknown_0812e820, gUnknown_0812e830, gUnknown_0812e838, gUnknown_0812e83c, gUnknown_0812e840,
    gUnknown_0812e848, gUnknown_0812e850, gUnknown_0812e858, gUnknown_0812e860, gUnknown_0812e864,
    gUnknown_0812e870, gUnknown_0812e87c, gUnknown_0812e888, gUnknown_0812e894, gUnknown_0812e89c,
    gUnknown_0812e8a4, gUnknown_0812e8b0, gUnknown_0812e8bc, gUnknown_0812e8c8, gUnknown_0812e8d4,
    gUnknown_0812e8e0, gUnknown_0812e8e8, gUnknown_0812e8f0, gUnknown_0812e8f8, gUnknown_0812e904,
};
extern const u16 *const gUnknown_08edbf60[] = {
    gUnknown_0812e930, gUnknown_0812e93c, gUnknown_0812e944, gUnknown_0812e950, gUnknown_0812e964,
    gUnknown_0812e978, gUnknown_0812e984, gUnknown_0812e9a0, gUnknown_0812e9a8, gUnknown_0812e9c0,
    gUnknown_0812e9d4, gUnknown_0812e9f0, gUnknown_0812e9f8, gUnknown_0812e9fc, gUnknown_0812ea00,
    gUnknown_0812ea08, gUnknown_0812ea10, gUnknown_0812ea18, gUnknown_0812ea20, gUnknown_0812ea24,
    gUnknown_0812ea30, gUnknown_0812ea3c, gUnknown_0812ea48, gUnknown_0812ea54, gUnknown_0812ea5c,
    gUnknown_0812ea64, gUnknown_0812ea70, gUnknown_0812ea7c, gUnknown_0812ea88, gUnknown_0812ea94,
    gUnknown_0812eab4, gUnknown_0812eac8, gUnknown_0812ead8, gUnknown_0812eae4, gUnknown_0812eb04,
};
extern const u16 *const gUnknown_08edbfec[] = {
    gUnknown_0812eb3c, gUnknown_0812eb48, gUnknown_0812eb50, gUnknown_0812eb5c, gUnknown_0812eb6c,
    gUnknown_0812eb8c, gUnknown_0812eb94, gUnknown_0812ebb0, gUnknown_0812ebb8, gUnknown_0812ebd8,
    gUnknown_0812ebf0, gUnknown_0812ec0c, gUnknown_0812ec14, gUnknown_0812ec18, gUnknown_0812ec1c,
    gUnknown_0812ec24, gUnknown_0812ec2c, gUnknown_0812ec34, gUnknown_0812ec3c, gUnknown_0812ec40,
    gUnknown_0812ec48, gUnknown_0812ec50, gUnknown_0812ec58, gUnknown_0812ec64, gUnknown_0812ec6c,
    gUnknown_0812ec74, gUnknown_0812ec7c, gUnknown_0812ec84, gUnknown_0812ec8c, gUnknown_0812ec94,
    gUnknown_0812ecb4, gUnknown_0812ecc8, gUnknown_0812ecd4, gUnknown_0812ece4, gUnknown_0812ed0c,
};
extern const u16 *const gUnknown_08edc078[] = {
    gUnknown_0812ed50, gUnknown_0812ed5c, gUnknown_0812ed64, gUnknown_0812ed70, gUnknown_0812ed84,
    gUnknown_0812ed9c, gUnknown_0812eda8, gUnknown_0812edc8, gUnknown_0812edd0, gUnknown_0812edf4,
    gUnknown_0812ee00, gUnknown_0812ee1c, gUnknown_0812ee24, gUnknown_0812ee28, gUnknown_0812ee2c,
    gUnknown_0812ee34, gUnknown_0812ee3c, gUnknown_0812ee44, gUnknown_0812ee4c, gUnknown_0812ee50,
    gUnknown_0812ee5c, gUnknown_0812ee68, gUnknown_0812ee74, gUnknown_0812ee80, gUnknown_0812ee88,
    gUnknown_0812ee90, gUnknown_0812ee9c, gUnknown_0812eea8, gUnknown_0812eeb4, gUnknown_0812eec0,
    gUnknown_0812eed8, gUnknown_0812eee4, gUnknown_0812ef08, gUnknown_0812ef18, gUnknown_0812ef38,
};
extern const u16 *const gUnknown_08edc104[] = {
    gUnknown_0812ef74, gUnknown_0812ef84, gUnknown_0812ef8c, gUnknown_0812ef98, gUnknown_0812efb4,
    gUnknown_0812efc0, gUnknown_0812efcc, gUnknown_0812efec, gUnknown_0812eff4, gUnknown_0812f020,
    gUnknown_0812f038, gUnknown_0812f054, gUnknown_0812f05c, gUnknown_0812f060, gUnknown_0812f064,
    gUnknown_0812f06c, gUnknown_0812f074, gUnknown_0812f07c, gUnknown_0812f084, gUnknown_0812f088,
    gUnknown_0812f094, gUnknown_0812f0a0, gUnknown_0812f0ac, gUnknown_0812f0b8, gUnknown_0812f0c0,
    gUnknown_0812f0c8, gUnknown_0812f0d4, gUnknown_0812f0e0, gUnknown_0812f0ec, gUnknown_0812f0f8,
    gUnknown_0812f114, gUnknown_0812f124, gUnknown_0812f130, gUnknown_0812f140, gUnknown_0812f168,
};
extern const u16 *const gUnknown_08edc190[] = {
    gUnknown_0812f1b0, gUnknown_0812f1bc, gUnknown_0812f1c4, gUnknown_0812f1d4, gUnknown_0812f1f0,
    gUnknown_0812f204, gUnknown_0812f210, gUnknown_0812f230, gUnknown_0812f238, gUnknown_0812f25c,
    gUnknown_0812f270, gUnknown_0812f294, gUnknown_0812f29c, gUnknown_0812f2a0, gUnknown_0812f2a4,
    gUnknown_0812f2ac, gUnknown_0812f2b4, gUnknown_0812f2bc, gUnknown_0812f2c4, gUnknown_0812f2c8,
    gUnknown_0812f2d4, gUnknown_0812f2e0, gUnknown_0812f2ec, gUnknown_0812f2f8, gUnknown_0812f300,
    gUnknown_0812f308, gUnknown_0812f314, gUnknown_0812f320, gUnknown_0812f32c, gUnknown_0812f338,
    gUnknown_0812f354, gUnknown_0812f364, gUnknown_0812f370, gUnknown_0812f37c, gUnknown_0812f390,
};
extern const u16 *const *const gUnknown_08edc21c[] = {
    gUnknown_08edbed4, gUnknown_08edbf60, gUnknown_08edbfec,
    gUnknown_08edc078, gUnknown_08edc104, gUnknown_08edc190,
};
extern const u8 gUnknown_08edc234[] = {20, 16, 13, 10, 6, 3, 0};
// Alignment before the following, externally owned pointer table.
extern const u8 textMenuAlignment = 0;
}
