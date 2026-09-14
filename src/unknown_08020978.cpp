// C++ reconstruction fallback; ownership and ABI evidence: docs/glyph-tu-cpp.md.
#include "types.h"
extern "C" {
struct BufferState {
    const u8 *glyphs;
    const u8 *widths;
    u8 *destination;
    u32 end;
    u16 width, rowSize, stride, blockSize;
    u32 fill;
};
static BufferState gUnknown_03004b10;
extern const u32 gUnknown_0807a37c[], gUnknown_0807a77c[];
extern const u8 gUnknown_0807173c[], gUnknown_08071b7c[];
extern const u32 gUnknown_080716bc[];
u32 FUN_08020978(u32 x, u32 y, u16 tile, u32 value) {
    u16 normalizedTile = tile;
    u8 count;
    BufferState *state = &gUnknown_03004b10;
    u32 column = x >> 3;
    u32 shift = x & 7;
    u32 *output = (u32 *)(state->destination + (column * state->stride + y) * 4);
    const u8 *source = state->glyphs + ((normalizedTile & 0x7fff) << 5);
    if (state->rowSize <= y) {
        count = 0;
    } else {
        count = state->rowSize - y;
        if (count > 16)
            count = 16;
    }
    u8 i = 0;
    const u8 *widths = state->widths;
    if (i < count) {
        u32 reverseShift = 8 - shift;
        do {
            s32 first = source[0];
            u8 upper = first << shift;
            s32 shiftedFirst = first >> reverseShift;
            s32 second = source[1];
            u8 middle = shiftedFirst | (second << shift);
            u8 lower = second >> reverseShift;
            if (upper != 0 && (u32)output < state->end) {
                output[0] =
                    (output[0] & gUnknown_0807a37c[upper]) | (gUnknown_0807a77c[upper] * value);
            }
            if (middle != 0) {
                u32 *next = output + state->stride;
                if ((u32)next < state->end)
                    *next =
                        (*next & gUnknown_0807a37c[middle]) | (gUnknown_0807a77c[middle] * value);
            }
            if (lower != 0) {
                u32 *next = output + state->blockSize;
                if ((u32)next < state->end)
                    *next = (*next & gUnknown_0807a37c[lower]) | (gUnknown_0807a77c[lower] * value);
            }
            source += 2;
            output++;
            i++;
        } while (i < count);
    }
    return widths[normalizedTile & 0x7fff];
}

u32 FUN_08020ad0(const u16 *stream) {
    const u16 *streamPosition = stream;
    BufferState *state = &gUnknown_03004b10;
    u32 maximum = 0;
    u32 width = 0;
    u32 token = *streamPosition;

    if (token != 0xFFFE) {
        u32 newline = 0xFFFD;
        u32 skip = 0xFFFC;
        u32 extraFirst = 0xFFFB;
        u32 extraSecond = 0xFFFA;
        u32 end = 0xFFFE;

        do {
            u32 current = token & 0xffff;

            if (current == newline) {
                if (maximum < width) {
                    maximum = width;
                }
                width = 0;
            } else if (current != skip) {
                if (current == extraFirst) {
                    streamPosition++;
                } else if (current == extraSecond) {
                    streamPosition++;
                } else if (current == 0xFFF9) {
                    streamPosition++;
                } else {
                    if (current == 0xFFF8) {
                    } else if (current == 0xFFF7) {
                    } else {
                        u32 glyph = 0x7FFF;
                        glyph &= token;
                        width += state->widths[glyph];
                    }
                }
            }
            streamPosition++;
            token = *streamPosition;
        } while (token != end);
    }
    return width;
}

u32 FUN_08020b74(u32 x, u32 y, const u16 *stream, u32 color, u32 shadow) {
    const u16 *position = stream;
    u32 drawColor = color;
    u32 drawShadow = shadow;
    u32 currentX = x;
    u32 currentY = y;
    u32 token = *position;
    if (token != 0xfffe) {
        u32 newline = 0xfffd;
        u32 end = 0xfffe;
        do {
            u32 current = (u16)token;
            if (current == newline) {
                currentX = 0;
                currentY += 16;
            } else if (current != 0xfffc) {
                if (current == 0xfffb) {
                    drawColor = *++position;
                } else if (current == 0xfffa) {
                    position++;
                } else if (current == 0xfff9) {
                    position++;
                } else {
                    u32 noWidth = 0xfff8;
                    if (current != noWidth && current != noWidth - 1) {
                        if (drawShadow != 0)
                            FUN_08020978(currentX + 1, currentY + 1, *position, drawShadow);
                        currentX += FUN_08020978(currentX, currentY, *position, drawColor);
                    }
                }
            }
            position++;
            token = *position;
        } while (token != end);
    }
    return currentX;
}

void FUN_08020c24(u32 x, u32 y, u32 width, u32 height, u32 color) {
    BufferState *state = &gUnknown_03004b10;
    u32 column = x >> 3;
    u32 shift = x & 7;
    u32 byteOffset = (column * state->stride + y) << 2;
    u8 *destination = state->destination;
    width += shift;
    u32 *output = (u32 *)(destination + byteOffset);
    u32 *next = output + state->stride;
    u32 initialTable = (u32)gUnknown_080716bc;
    u32 pattern = *(const u32 *)(initialTable + ((shift + 8) << 2));
    pattern *= color;
    u32 mask = *(const u32 *)(initialTable + ((shift + 16) << 2));
    u32 table = (u32)gUnknown_080716bc;
    if (width <= 7) {
        pattern &= *(const u32 *)((u32)table + ((width + 16) << 2));
        mask |= *(const u32 *)((u32)table + ((width + 24) << 2));
        width = 0;
    }
    u8 row;
    for (row = 0; row < height; row++) {
        *output = (*output & mask) | pattern;
        output++;
    }
    u32 repeated = color + (color << 4);
    repeated += repeated << 8;
    pattern = repeated + (repeated << 16);
    while (width > 7) {
        width -= 8;
        output = next;
        next = output + state->stride;
        for (row = 0; row < height; row++)
            *output++ = pattern;
    }
    if (width != 0) {
        pattern &= *(const u32 *)((u32)table + ((width + 16) << 2));
        mask = *(const u32 *)((u32)table + ((width + 24) << 2));
        for (row = 0; row < height; row++) {
            *output = (*output & mask) | pattern;
            output++;
        }
    }
}

u8 FUN_08020d20(u32 *destination, u32 x, u32 y, u16 tile, u32 value) {
    u16 normalizedTile = tile;
    u32 offset = x >> 3;
    u32 shift = 7;
    u32 *output;
    const u8 *source;
    u8 i;
    u32 reverseShift;

    shift &= x;
    offset <<= 5;
    offset += y;
    offset <<= 2;
    output = (u32 *)((u8 *)destination + offset);
    source = &gUnknown_08071b7c[(normalizedTile & 0x7FFF) << 5];
    i = 0;
    reverseShift = 8 - shift;

    do {
        s32 first;
        s32 second;
        u8 upper;
        u8 middle;
        u8 lower;
        s32 shiftedFirst;

        first = source[0];
        upper = first << shift;
        shiftedFirst = first >> reverseShift;
        second = source[1];
        middle = shiftedFirst | (second << shift);
        lower = second >> reverseShift;

        if (upper != 0) {
            output[0] = (output[0] & gUnknown_0807a37c[upper]) | (gUnknown_0807a77c[upper] * value);
        }
        if (middle != 0) {
            output[32] =
                (output[32] & gUnknown_0807a37c[middle]) | (gUnknown_0807a77c[middle] * value);
        }
        if (lower != 0) {
            output[64] =
                (output[64] & gUnknown_0807a37c[lower]) | (gUnknown_0807a77c[lower] * value);
        }
        source += 2;
        output++;
        i++;
    } while (i <= 15);

    return gUnknown_0807173c[normalizedTile & 0x7FFF];
}

u32 FUN_08020e28(const u16 *stream) {
    const u16 *streamPosition = stream;
    u32 maximum = 0;
    u32 width = 0;
    u32 token = *streamPosition;

    if (token != 0xFFFE) {
        u32 newline = 0xFFFD;
        u32 skip = 0xFFFC;
        const u8 *widths = gUnknown_0807173c;
        u32 extraFirst = 0xFFFB;
        u32 extraSecond = 0xFFFA;
        u32 end = 0xFFFE;

        do {
            u32 current = token & 0xffff;

            if (current == newline) {
                if (maximum < width) {
                    maximum = width;
                }
                width = 0;
            } else if (current != skip) {
                if (current == extraFirst) {
                    streamPosition++;
                } else if (current == extraSecond) {
                    streamPosition++;
                } else if (current == 0xFFF9) {
                    streamPosition++;
                } else {
                    if (current == 0xFFF8) {
                    } else if (current == 0xFFF7) {
                    } else {
                        u32 glyph = 0x7FFF;
                        glyph &= token;
                        width += widths[glyph];
                    }
                }
            }
            streamPosition++;
            token = *streamPosition;
        } while (token != end);
    }
    return width;
}

void FUN_08020ecc(u32 first, const u8 *source, u8 *destination, u32 width, u32 height, u8 fill) {
    u32 pattern;
    u32 value;

    gUnknown_03004b10.glyphs = (const u8 *)first;
    gUnknown_03004b10.widths = source;
    gUnknown_03004b10.destination = destination;
    gUnknown_03004b10.end = (u32)destination + width * height * 32;
    gUnknown_03004b10.width = width;
    gUnknown_03004b10.rowSize = height * 8;
    gUnknown_03004b10.stride = height * 8;
    gUnknown_03004b10.blockSize = height * 16;
    value = fill & 0xF;
    pattern = value | (value << 4) | (value << 8) | (value << 12);
    pattern |= pattern << 16;
    gUnknown_03004b10.fill = pattern;
}

void FUN_08020f18(void) {
    BufferState *state = &gUnknown_03004b10;
    u32 *destination = (u32 *)state->destination;
    u32 count = state->rowSize * state->width - 2;
    u32 offset;
    u32 i;

    for (i = 0; i < count; i++) {
        *destination = destination[2];
        destination++;
    }

    offset = state->stride * 4 - 8;
    destination = (u32 *)(state->destination + offset);
    for (i = 0; i < state->width; i++) {
        destination[0] = destination[1] = state->fill;
        destination += state->stride;
    }
}

u32 FUN_08020f64(u16 value) {
    BufferState *state = &gUnknown_03004b10;

    value &= 0x7FFF;
    return state->widths[value];
}

void FUN_08020f78(u32 *data) {
    u32 *start = data;
    u32 i;

    for (i = 0; i <= 0x3FD; i++) {
        *data = data[2];
        data++;
    }

    data = start + 30;
    for (i = 0; i <= 31; i++) {
        data[1] = 0;
        data[0] = 0;
        data += 32;
    }
}

u16 FUN_08020fac(u16 value) {
    const u8 *source = gUnknown_0807173c;

    value &= 0x7FFF;
    return source[value];
}

void FUN_08020fbc(u16 *destination, const u16 *source, u16 width, u16 rows) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination++ = *source++;
        }
        destination += 32 - width;
    }
}

void FUN_08021000(u16 *destination, const u16 *source, u16 width, u16 rows, u16 offset) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination = offset + *source;
            destination++;
            source++;
        }
        destination += 32 - width;
    }
}
}

// Successive nibble runs; reconstruct arithmetic without copying a ROM array.
#define RUNS(v)                                                                                    \
    0, ((v) & 0xf0000000U), ((v) & 0xff000000U), ((v) & 0xfff00000U), ((v) & 0xffff0000U),         \
        ((v) & 0xfffff000U), ((v) & 0xffffff00U), ((v) & 0xfffffff0U), (v), ((v) >> 4),            \
        ((v) >> 8), ((v) >> 12), ((v) >> 16), ((v) >> 20), ((v) >> 24), ((v) >> 28)
extern "C" {
extern const u32 gUnknown_080716bc[32]
    __attribute__((section(".rodata.span"))) = {RUNS(0x11111111U), RUNS(0xffffffffU)};
}

// Arithmetic reconstruction, not an extracted table initializer.
#define EXPAND(v)                                                                                  \
    (((v) & 1) | (((v) & 2) << 3) | (((v) & 4) << 6) | (((v) & 8) << 9) | (((v) & 16) << 12) |     \
     (((v) & 32) << 15) | (((v) & 64) << 18) | (((v) & 128) << 21))
#define MASK(v) (~(EXPAND(v) * 15U))
#define ROW(f, b)                                                                                  \
    f((b) + 0), f((b) + 1), f((b) + 2), f((b) + 3), f((b) + 4), f((b) + 5), f((b) + 6),            \
        f((b) + 7), f((b) + 8), f((b) + 9), f((b) + 10), f((b) + 11), f((b) + 12), f((b) + 13),    \
        f((b) + 14), f((b) + 15)
#define TABLE(f)                                                                                   \
    ROW(f, 0), ROW(f, 16), ROW(f, 32), ROW(f, 48), ROW(f, 64), ROW(f, 80), ROW(f, 96),             \
        ROW(f, 112), ROW(f, 128), ROW(f, 144), ROW(f, 160), ROW(f, 176), ROW(f, 192), ROW(f, 208), \
        ROW(f, 224), ROW(f, 240)
extern "C" {
extern const u32 gUnknown_0807a37c[256] __attribute__((section(".rodata.pixels"))) = {TABLE(MASK)};
extern const u32 gUnknown_0807a77c[256]
    __attribute__((section(".rodata.pixels"))) = {TABLE(EXPAND)};
}
