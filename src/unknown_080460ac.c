#include "types.h"

struct UnknownState460ac {
    u8 filler0[2];
    u8 field2;
    u8 field3;
    const void *callback;
    u16 field8;
    u16 field10;
    union {
        u32 fixed;
        struct {
            u16 low;
            u16 high;
        } half;
    } field12;
    const void *graphics;
    u16 field20;
    u8 field22;
    u8 field23;
    u8 field24;
    u8 filler25;
    u8 field26;
    u8 field27;
    union {
        u32 fixed;
        const u16 *script;
        struct {
            u16 low;
            u16 high;
        } half;
    } field28;
    u8 filler32[2];
    u16 field34;
    u8 field36;
    u8 field37;
    u8 field38;
    u8 field39;
    u16 field40;
};

struct UnknownTransferRecord460ac {
    const void *source;
    void *destination;
    u32 size;
};

struct UnknownGraphicsRecord460ac {
    const void *first;
    const void *variants[4];
};

struct UnknownGlobalState460ac {
    const void *callback;
    union {
        u32 word;
        struct {
            u16 low;
            u16 high;
        } half;
    } field4;
    u16 field8;
    u8 filler10[18];
    u8 field28;
    u8 filler29[7];
    u8 field36;
    u8 filler37[9];
    u8 field46;
};

struct UnknownPoolOrder460ac {
    u8 indices[3];
    u8 count;
};

struct UnknownPoolNode460ac {
    u8 filler0[2];
    u8 field2;
    u8 field3;
    const void *callback;
    u8 filler8[2];
    s16 field10;
    u8 filler12[24];
    u8 field36;
    u8 filler37[7];
};

extern const u8 gUnknown_081a7f18[];
extern const struct UnknownGraphicsRecord460ac gUnknown_081b94c8[];
extern void *gUnknown_03005478;
extern volatile struct UnknownTransferRecord460ac gUnknown_030000d4;
extern struct UnknownGlobalState460ac gUnknown_03005440;
extern struct UnknownInputState460ac {
    u16 first;
    u16 second;
    u16 third;
} gUnknown_030048e0;
extern struct UnknownPoolOrder460ac gUnknown_03000278;
extern struct UnknownPoolOrder460ac gUnknown_0300027c;
extern u8 gUnknown_03000280[];
extern s8 gUnknown_03000285;
extern struct UnknownPair460ac {
    u16 first;
    u16 second;
} gUnknown_0300028c;
extern struct UnknownPoolNode460ac *gUnknown_0300547c;
extern const u16 gUnknown_081a7f04[][3];
extern const u8 gUnknown_081a7f38[];
extern void FUN_0804a5b8(const void *source, void *destination);
extern void FUN_0804033c(const void *source, void *destination, u32 size);
extern void FUN_080403c0(const void *source, void *destination, u32 width, u32 height, u32 flags);
extern void FUN_0803fe98(u16 first, u16 second, u16 third);
extern void FUN_0801fba0(u16 offset, u16 value);
extern void FUN_0804051c(void *state);
extern void FUN_080405a8(u8 first, u8 second);
extern void FUN_080405f4(u8 first, u8 second);
extern s32 FUN_0804a59c(s32 value, s32 divisor);
extern void FUN_08047fe4(struct UnknownState460ac *state);
extern s32 FUN_08020978(u16 first, u16 second, s32 third, u8 fourth);
extern void FUN_0801f618(u16 value);
extern s16 *gUnknown_03000274;
extern s32 FUN_080406d4(s32 value, s8 *destination, s32 width);
extern void *FUN_0803ff98(const void *callback, void *parent, u32 flag);
extern void FUN_08048284(struct UnknownState460ac *state);
extern void FUN_08020f18(void);
extern const u8 gUnknown_081a81d0[];
extern const u8 gUnknown_081a7f58[];
extern const u8 gUnknown_081a8770[];
extern const u32 *const gUnknown_08eeb228[];
extern void FUN_08045a5c(u8 value);
extern void FUN_08045d30(struct UnknownState460ac *state);

void FUN_080461b4(struct UnknownState460ac *state);
void FUN_080462c8(struct UnknownState460ac *state);
void FUN_080463f4(struct UnknownState460ac *state);
void FUN_08046538(struct UnknownState460ac *state);
extern void FUN_08048014(struct UnknownState460ac *state);
extern void FUN_08048074(struct UnknownState460ac *state);
void FUN_08046998(struct UnknownState460ac *state);
void FUN_08046a18(struct UnknownState460ac *state);

static void (*const gUnknown_08edda24[])(struct UnknownState460ac *) = {
    FUN_080461b4,
    FUN_080462c8,
    FUN_080463f4,
    FUN_08046538,
};

static void (*const gUnknown_08edda34[])(struct UnknownState460ac *) = {
    FUN_08048014,
    FUN_08048074,
    FUN_08046998,
    FUN_08046a18,
};

static const u16 gUnknown_08edda44[] = {
    0x19c, 0x19c, 0x19c, 0x19d, 0x19d, 0x19b, 0x19b, 0x19d,
    0x19b, 0x19d, 0x19c, 0x19c, 0x19c, 0x19d, 0x19b,
};

static const u8 gUnknown_08edda62[] = {0, 4, 8, 4};
static const u16 gUnknown_08edda66 = 0;

void FUN_080460ac(struct UnknownState460ac *state) {
    if (state->field37 > 3) {
        state->field37 = 0;
    }
    if (state->field27 > 3) {
        state->field27 = 2;
    }
    state->field3 = 0x80;
    state->field12.half.high = 0x43;
    state->graphics = gUnknown_081a7f18;
    state->field20 = state->field38 * 0x90 + 0x250;
    state->field24 = (state->field38 + 13) * 16 | 8;
    gUnknown_030000d4.source = gUnknown_081b94c8[state->field36 - 1].first;
    gUnknown_030000d4.destination = (u8 *)gUnknown_03005478 + (state->field38 * 0x20 + 0x3a0);
    gUnknown_030000d4.size = 0x80000010;
    (void)gUnknown_030000d4.size;
    FUN_0804a5b8(gUnknown_081b94c8[state->field36 - 1].variants[state->field37],
                 (void *)(0x02016a00 + state->field38 * 0x3600));
    FUN_0804033c((void *)(0x02016a00 + state->field38 * 0x3600),
                 (void *)(0x06010000 + state->field20 * 0x20), 0x1200);
    state->callback = gUnknown_08edda24[state->field27];
    state->field27 = 0;
}

void FUN_080461b4(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0: {
        s16 index;
        u8 id;

        if ((gUnknown_03005440.field8 & 8) == 0) {
            FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, 0);
        }
        state->field10 = 0x120;
        id = state->field2;
        for (index = 0; index < gUnknown_03000278.count; index++) {
            if (gUnknown_0300547c[gUnknown_03000278.indices[index]].field2 == id) {
                break;
            }
        }
        state->field28.half.high = gUnknown_081a7f04[gUnknown_03000278.count - 1][(u8)index];
        state->field27++;
        /* fallthrough */
    }
    case 1: {
        s32 *position = (s32 *)&state->field8;
        s32 delta = FUN_0804a59c(*position - (s32)state->field28.fixed, 8);

        *position -= delta;
        if ((s16)state->field28.half.high == (s16)state->field10) {
            state->field8 = 0;
            state->field3 &= 0x7f;
            state->callback = FUN_08047fe4;
        }
        break;
    }
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_080462c8(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0: {
        s16 index;
        u8 id;

        if ((gUnknown_03005440.field8 & 8) == 0) {
            FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, 0);
        }
        state->field3 |= 4;
        state->graphics = gUnknown_081a7f38;
        state->field10 = -0x30;
        id = state->field2;
        for (index = 0; index < gUnknown_03000278.count; index++) {
            if (gUnknown_0300547c[gUnknown_03000278.indices[index]].field2 == id) {
                break;
            }
        }
        state->field28.half.high = gUnknown_081a7f04[gUnknown_03000278.count - 1][(u8)index] + 1;
        state->field27++;
        /* fallthrough */
    }
    case 1: {
        s32 *position = (s32 *)&state->field8;
        s32 delta = FUN_0804a59c(*position - (s32)state->field28.fixed, 8);

        *position -= delta;
        if ((s16)state->field28.half.high - 1 == (s16)state->field10) {
            state->field8 = 0;
            state->field3 &= 0x7f;
            state->callback = FUN_08047fe4;
        }
        break;
    }
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_080463f4(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0: {
        s16 index;
        u8 id;

        if ((gUnknown_03005440.field8 & 8) == 0) {
            FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, 0x10);
        }
        state->field26 = 0x10;
        id = state->field2;
        for (index = 0; index < gUnknown_03000278.count; index++) {
            if (gUnknown_0300547c[gUnknown_03000278.indices[index]].field2 == id) {
                break;
            }
        }
        state->field10 = gUnknown_081a7f04[gUnknown_03000278.count - 1][(u8)index];
        state->field27++;
        break;
    }
    case 1:
        if ((gUnknown_03005440.field4.word & 1) != 0) {
            if ((gUnknown_03005440.field8 & 8) == 0) {
                state->field26--;
                FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, state->field26);
            } else {
                state->field26 = 0;
            }
            if (state->field26 == 0) {
                state->field3 &= 0x7f;
                state->callback = FUN_08047fe4;
            }
        }
        break;
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_08046538(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0: {
        s16 index;
        u8 id;
        u8 column;

        if ((gUnknown_03005440.field8 & 8) == 0) {
            FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, 0);
            state->field26 = 0x10;
        } else {
            state->field26 = 1;
        }
        state->field22 = 4;
        FUN_0801fba0(0x52, 0x1000);
        id = state->field2;
        for (index = 0; index < gUnknown_03000278.count; index++) {
            if (gUnknown_0300547c[gUnknown_03000278.indices[index]].field2 == id) {
                break;
            }
        }
        column = index;
        state->field10 = gUnknown_081a7f04[gUnknown_03000278.count - 1][column];
        state->field27++;
        break;
    }
    case 1:
        if ((gUnknown_03005440.field4.word & 1) != 0) {
            state->field26--;
            FUN_0801fba0(0x52, (state->field26 << 8) | (0x10 - state->field26));
            if (state->field26 == 0) {
                state->field22 = 0;
                state->field3 &= 0x7f;
                state->callback = FUN_08047fe4;
            }
        }
        break;
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_0804666c(struct UnknownState460ac *state) {
    s16 index;

    switch (state->field27) {
    case 0: {
        s16 values[6];
        s16 sourceIndex;
        u16 mode;

        for (index = 0, sourceIndex = state->field20; index < 6; index++, sourceIndex++) {
            values[index] = gUnknown_03000274[sourceIndex];
        }
        if (values[4] == values[2]) {
            values[4] = 0;
        }
        if (values[4] == values[0]) {
            values[4] = 0;
        }
        if (values[2] == values[0]) {
            values[2] = 0;
        }

        gUnknown_0300027c.count = 0;
        for (index = 0; index < 6; index += 2) {
            for (sourceIndex = 0; sourceIndex < gUnknown_03000278.count; sourceIndex++) {
                if (gUnknown_0300547c[gUnknown_03000278.indices[sourceIndex]].field36 ==
                    values[index]) {
                    break;
                }
            }
            if (sourceIndex < gUnknown_03000278.count) {
                mode = values[index + 1];

                if (mode > 3) {
                    mode = 2;
                }
                gUnknown_0300547c[gUnknown_03000278.indices[sourceIndex]].callback =
                    gUnknown_08edda34[(s16)mode];
                ((u8 *)&gUnknown_0300547c[gUnknown_03000278.indices[sourceIndex]])[27] = 0;
                gUnknown_0300027c.count++;
            }
        }
        if (gUnknown_0300027c.count != 0) {
            gUnknown_0300027c.count = gUnknown_03000278.count - gUnknown_0300027c.count;
            state->field27++;
            break;
        }
        gUnknown_03005440.field8 &= 0xfffb;
        FUN_0804051c(state);
        break;
    }
    case 1:
        if (gUnknown_03000278.count != gUnknown_0300027c.count) {
            break;
        }
        if (gUnknown_03000278.count == 0) {
            gUnknown_03005440.field8 &= 0xfffb;
            FUN_0804051c(state);
        } else {
            s16 outer;

            for (outer = 0; outer < 2; outer++) {
                for (index = 0; index < 2; index++) {
                    if (gUnknown_03000278.indices[index] == 0) {
                        gUnknown_03000278.indices[index] = gUnknown_03000278.indices[index + 1];
                        gUnknown_03000278.indices[index + 1] = 0;
                    }
                }
            }
            for (index = 0; index < gUnknown_03000278.count; index++) {
                gUnknown_0300547c[gUnknown_03000278.indices[index]].callback = FUN_08045d30;
            }
            state->field27++;
        }
        break;
    case 2: {
        for (index = 0; index < gUnknown_03000278.count; index++) {
            if ((gUnknown_0300547c[gUnknown_03000278.indices[index]].field3 & 0x80) != 0) {
                break;
            }
        }
        if (index >= gUnknown_03000278.count) {
            gUnknown_03005440.field8 &= 0xfffb;
            FUN_0804051c(state);
        }
        break;
    }
    }
}

void FUN_08046918(struct UnknownState460ac *state) {
    s16 index;
    u8 id = state->field2;

    for (index = 0; index < gUnknown_03000278.count; index++) {
        if (gUnknown_0300547c[gUnknown_03000278.indices[index]].field2 == id) {
            break;
        }
    }
    gUnknown_03000278.indices[(u8)index] = 0;
    gUnknown_03000278.count--;
    gUnknown_0300027c.indices[state->field38] = 0;
}

void FUN_08046998(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0:
        state->field26 = 0;
        state->field27++;
        /* fallthrough */
    case 1:
        if ((gUnknown_03005440.field4.word & 1) == 0) {
            break;
        }
        if ((gUnknown_03005440.field8 & 8) == 0) {
            state->field26++;
            FUN_0803fe98((state->field38 * 0x100000 + 0x1d00000) >> 16, 0x10, state->field26);
        } else {
            state->field26 = 0x10;
        }
        if (state->field26 > 0xf) {
            FUN_08046918(state);
            FUN_0804051c(state);
            return;
        }
        break;
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_08046a18(struct UnknownState460ac *state) {
    switch (state->field27) {
    case 0:
        state->field22 = 4;
        if ((gUnknown_03005440.field8 & 8) == 0) {
            state->field26 = 0;
        } else {
            state->field26 = 0x10;
        }
        FUN_0801fba0(0x52, 0x10);
        state->field27++;
        break;
    case 1:
        if ((gUnknown_03005440.field4.word & 1) == 0) {
            break;
        }
        state->field26++;
        FUN_0801fba0(0x52, (state->field26 << 8) | (0x10 - state->field26));
        if (state->field26 > 0xf) {
            FUN_08046918(state);
            FUN_0804051c(state);
            return;
        }
        break;
    }
    FUN_080405f4(state->field2, state->field39);
}

void FUN_08046aa4(struct UnknownState460ac *state) {
    state->field26++;
    if (state->field26 > 6) {
        state->field26 = 0;
        state->field27++;
    }
    state->field20 = gUnknown_08edda62[state->field27 & 3] + 0x10;
    if ((gUnknown_03005440.field4.half.low & 1) != 0) {
        FUN_0804051c(state);
    } else {
        FUN_080405a8(state->field2, 0);
    }
}

void FUN_08046af8(struct UnknownState460ac *state) {
    const u8 *sequence = gUnknown_03000280;
    s8 index = gUnknown_03000285++;
    u16 value = sequence[index] + 0x10;

    gUnknown_0300028c.second = 0;
    if ((value == 0 || value == 0x338) &&
        (gUnknown_0300028c.first == 0 || gUnknown_0300028c.first == 0x338)) {
        gUnknown_0300028c.second = 1;
    }
    gUnknown_0300028c.first = value;
    state->field8 +=
        FUN_08020978(state->field8, state->field12.half.low, (s16)value, state->field37);
    FUN_0804033c((const void *)0x02000600, (void *)0x06008a00, 0xe00);
    if (state->field38 != 0) {
        if (gUnknown_0300028c.second == 0) {
            FUN_0801f618(gUnknown_08edda44[state->field36]);
        }
    } else if ((state->field28.half.low & 2) != 0 && gUnknown_0300028c.second == 0) {
        FUN_0801f618(gUnknown_08edda44[state->field36]);
    }
}

void FUN_08046bc4(struct UnknownState460ac *state) {
    s32 destination;
    s32 delta;

    if (state->field40 != 0) {
        state->field40--;
    }
    if (state->field27 != 0xff && state->field27 != 2 && (gUnknown_030048e0.third & 1) != 0) {
        state->field40 = 0xf;
    }

    switch (((volatile struct UnknownState460ac *)state)->field27) {
    case 0: {
        destination = (s16)state->field34;
        if (state->field23 != 0) {
            destination++;
        }
        destination = FUN_0804a59c(*(s32 *)&state->field8 - (destination << 16), 6);
        delta = *(s32 *)&state->field8;
        delta -= destination;
        *(s32 *)&state->field8 = delta;
        if ((s16)state->field34 == (s16)state->field10) {
            state->field8 = 8;
            state->field27++;
        }
        break;
    }
    case 1:
        if ((gUnknown_030048e0.third & 1) != 0) {
            state->field38 = 0;
        }
        state->field26++;
        if (state->field26 >= state->field38) {
            u8 done;
            u8 *field36;

            state->field26 = 0;
            field36 = &state->field36;
            {
                u32 emptyCommand = 0xce;
                const u16 *soundTable;

                emptyCommand <<= 2;
                soundTable = gUnknown_08edda44;
            scriptLoop:
            parseNext: {
                const u16 *script = state->field28.script;
                u16 command = script[0];
                const u16 *nextScript = script + 1;

                state->field28.script = nextScript;

                switch (command) {
                case 0xfffe:
                    state->field27 = 0xff;
                    if (state->field40 != 0) {
                        state->field40 = 0xf;
                    }
                    break;
                case 0xfffd:
                    state->field8 = 8;
                    state->field12.half.low += 0x10;
                    state->field39++;
                    if (state->field12.half.low > 0x1f) {
                        state->field12.half.low -= 0x10;
                        state->filler25 = 0;
                        if (state->field39 == 2) {
                            FUN_0803ff98((const void *)((u32)FUN_08048284 + 1), state, 1);
                            state->field39 = 0;
                            state->field27++;
                        } else {
                            state->field27 = 3;
                        }
                    } else {
                        goto parseNext;
                    }
                    break;
                case 0xfffb:
                    command = nextScript[0];
                    state->field28.script = nextScript + 1;
                    state->field37 = command;
                    goto parseNext;
                case 0xfff9: {
                    s32 conversionResult;

                    command = nextScript[0];
                    state->field28.script = nextScript + 1;
                    conversionResult =
                        FUN_080406d4(gUnknown_03000274[command], (s8 *)gUnknown_03000280, 5);
                    gUnknown_03000285 = conversionResult;
                    if ((s8)conversionResult < 0) {
                        gUnknown_03000285 = 0;
                    }
                    FUN_08046af8(state);
                    if (gUnknown_03000285 > 4) {
                        state->field27 = 1;
                    } else {
                        state->field27 = 4;
                    }
                    break;
                }
                default:
                    gUnknown_0300028c.second = 0;
                    if ((command == 0 || command == emptyCommand) &&
                        (gUnknown_0300028c.first == 0 || gUnknown_0300028c.first == emptyCommand)) {
                        gUnknown_0300028c.second = 1;
                    }
                    gUnknown_0300028c.first = command;
                    state->field8 += FUN_08020978(state->field8, state->field12.half.low, command,
                                                  state->field37);
                    FUN_0804033c((const void *)0x02000600, (void *)0x06008a00, 0xe00);
                    if (state->field38 != 0) {
                        if (gUnknown_0300028c.second == 0) {
                            FUN_0801f618(soundTable[*field36]);
                        }
                    } else if ((state->field28.half.low & 2) != 0 &&
                               gUnknown_0300028c.second == 0) {
                        FUN_0801f618(soundTable[*field36]);
                    }
                    break;
                }
                done = emptyCommand != 0;
            }
            }
            if (done != 0) {
                goto switchDone;
            }
            goto scriptLoop;
        }
        goto switchDone;
    case 2:
        if ((gUnknown_030048e0.third & 1) != 0) {
            state->field27++;
        }
        break;
    case 3:
        FUN_08020f18();
        FUN_0804033c((const void *)0x02000600, (void *)0x06008a00, 0xe00);
        state->filler25 += 2;
        if (state->filler25 > 0xf) {
            state->field27 = 1;
        }
        break;
    case 4:
        if ((gUnknown_030048e0.third & 1) != 0) {
            state->field38 = 0;
        }
        state->field26++;
        if (state->field26 >= state->field38) {
            state->field26 = 0;
            FUN_08046af8(state);
            if (gUnknown_03000285 > 4) {
                state->field27 = 1;
            }
        }
        break;
    default:
        if ((state->field40 == 0 && (gUnknown_030048e0.third & 1) != 0) ||
            (state->field3 & 0x80) != 0) {
            gUnknown_03005440.field8 &= 0xfffb;
            FUN_0804051c(state);
            return;
        }
        break;
    }
switchDone:
    if (state->field36 != 0) {
        FUN_080405f4(state->field2, 0);
    }
}

void FUN_08046f00(struct UnknownState460ac *state) {
    s16 poolIndex;

    gUnknown_0300028c.second = 0;
    gUnknown_0300028c.first = 0;
    poolIndex = 0;
    for (poolIndex = 0; poolIndex < gUnknown_03000278.count; poolIndex++) {
        if (gUnknown_0300547c[gUnknown_03000278.indices[poolIndex]].field36 == state->field36) {
            break;
        }
    }
    if (poolIndex >= gUnknown_03000278.count) {
        state->field36 = 0;
    }

    if (state->field36 == 0) {
        FUN_080403c0(gUnknown_081a81d0, (void *)0x06009b80, 0x1e, 6, 0);
        gUnknown_03005440.field46 = 0;
        state->field27 = 1;
        state->field8 = 8;
    } else {
        u16 basePosition;

        gUnknown_03005440.field36++;
        if (gUnknown_03005440.field36 > 3) {
            gUnknown_03005440.field36 = 1;
        }
        FUN_080403c0(gUnknown_081a81d0 + gUnknown_03005440.field36 * 0x168, (void *)0x06009b80,
                     0x1e, 6, 0);
        gUnknown_03005440.field46 = gUnknown_03005440.field36;
        basePosition = gUnknown_0300547c[gUnknown_03000278.indices[poolIndex]].field10;
        state->field10 = basePosition;
        state->field12.half.high = 0x68;
        state->graphics = gUnknown_081a7f58;
        state->field20 = 0;
        if ((gUnknown_0300547c[gUnknown_03000278.indices[poolIndex]].field3 & 4) != 0) {
            state->field23 = 0x10;
            state->field34 = basePosition + 0x18;
        } else {
            state->field34 = basePosition - 0x18;
        }
        FUN_08045a5c(state->field36);
    }

    FUN_080403c0(gUnknown_081a8770, (void *)0x06009bc2, 0x1c, 4, 0x50);
    {
        volatile u16 fill[1] = {0x1111};

        gUnknown_030000d4.source = (const void *)fill;
        gUnknown_030000d4.destination = (void *)0x02000600;
        gUnknown_030000d4.size = 0x81000700;
        (void)gUnknown_030000d4.size;
        FUN_0804033c((const void *)0x02000600, (void *)0x06008a00, 0xe00);
    }
    state->field28.fixed = gUnknown_08eeb228[gUnknown_03005440.field28][state->field28.half.low];
    state->field37 = 3;
    state->field38 = 5;
    state->callback = FUN_08046bc4;
}
