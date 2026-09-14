// Inferred complete scene TU: 0x08034F28..0x08036350.
// C++ fallback; original language, names and declarations are unknown.
// See docs/scene-34f28-tu-cpp.md for ownership and verification evidence.
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
struct Scene {
    void (*callback)(void);
    u16 entries[3];
    u8 count, flag;
};
struct Save {
    u8 prefix[0x77], language;
};
struct CallbackState {
    s16 value, counter;
    u8 nodeIndex;
};
struct MovementState {
    u8 prefix[16];
    s32 velocity;
    union {
        s32 fixed;
        struct {
            u16 low;
            s16 high;
        } half;
    } y;
};
struct Input {
    u16 first, second, third, fourth;
};
struct State {
    s16 value, counter;
    u8 field4, children[8];
};
struct Motion {
    u8 prefix[16];
    s32 velocity, y;
};
extern "C" {
extern const u16 gUnknown_08155348[];

extern u8 gUnknown_03001620[];
extern Save gUnknown_03002110;
extern Scene gUnknown_03005330;
extern Node gUnknown_03003e20[];
extern const u8 *gUnknown_03004db4;
extern const u16 *const *gUnknown_03004da4, *const *gUnknown_03005340;
extern const u16 *const gUnknown_08ed8c18[], *const gUnknown_08ed90ec[];
extern const u16 *const *const gUnknown_08edca4c[];
extern const u8 gUnknown_0807c8b8[], gUnknown_0808fdb8[], gUnknown_0810bf3e[], gUnknown_08edca74[];
extern const u8 gUnknown_08155648[], gUnknown_08155c5c[], gUnknown_081560a0[], gUnknown_08155acc[],
    gUnknown_08155bb0[], gUnknown_08155a44[], gUnknown_081559bc[];
extern u8 gUnknown_0300533c, gUnknown_03005374;
extern u16 gUnknown_03005370, gUnknown_03005368, gUnknown_03005378, gUnknown_0300536c;
extern void (*gUnknown_03002030)(void);
void FUN_08007e9c(u8), FUN_0801fbfc(const void *, u32);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void),
    FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08035a8c(Node *), FUN_08035c0c(Node *), FUN_08035c24(Node *), FUN_08035258(void);
void FUN_0801fba0(u16, u16);
void FUN_08034f28(void) {
    u32 zeros[5];
    FUN_08007e9c(0);
    FUN_08007e9c(1);
    FUN_08007e9c(2);
    FUN_08007e9c(3);
    gUnknown_03001620[24] = 0;
    gUnknown_03001620[25] = 0;
    gUnknown_03001620[26] = 0;
    gUnknown_03001620[27] = 0;
    switch (gUnknown_03002110.language) {
    case 0:
        gUnknown_03004db4 = gUnknown_0807c8b8;
        gUnknown_03004da4 = gUnknown_08ed8c18;
        break;
    case 1:
        gUnknown_03004db4 = gUnknown_0808fdb8;
        gUnknown_03004da4 = gUnknown_08ed90ec;
        break;
    case 2:
        gUnknown_03004db4 = gUnknown_0808fdb8;
        gUnknown_03004da4 = gUnknown_08ed90ec;
        break;
    case 3:
        gUnknown_03004db4 = gUnknown_0808fdb8;
        gUnknown_03004da4 = gUnknown_08ed90ec;
        break;
    case 4:
        gUnknown_03004db4 = gUnknown_0808fdb8;
        gUnknown_03004da4 = gUnknown_08ed90ec;
        break;
    case 5:
        gUnknown_03004db4 = gUnknown_0808fdb8;
        gUnknown_03004da4 = gUnknown_08ed90ec;
        break;
    }
    gUnknown_03005340 = gUnknown_08edca4c[gUnknown_03002110.language];
    Save *save = &gUnknown_03002110;
    register Scene *initialScene = &gUnknown_03005330;
    register u32 initialFlag = initialScene->flag;

    register Scene *scene = initialScene;
    register u32 *zero1Address = &zeros[1];
    register u8 *zeroBase = (u8 *)zeros;
    asm("" : "+r"(zeroBase));
    u32 *zero2Address = (u32 *)(zeroBase + 8);

    register u32 *third asm("r2") = &zeros[3];
    asm("" : : "r"(third));
    register u32 *zero3Address asm("r9") = third;
    register u32 *fourth asm("r7") = &zeros[4];

    register u32 *zero4Address asm("r10") = fourth;
    asm("" : "+r"(zero1Address), "+r"(zero3Address), "+r"(zero4Address));
    if (!initialFlag) {
        register u32 i asm("r4") = 0;
        register u32 count = scene->count;
        if (i < count) {
            register Scene *loopScene asm("r8") = scene;
            register u8 *countsBase = (u8 *)0x120;

            countsBase = (u8 *)((u32)countsBase + (u32)save);

            register u8 *counts asm("r12") = countsBase;
            register u32 one asm("r5") = 1;
            register u16 *selection = scene->entries;
            do {
                u32 selected = *selection;
                u8 *entry = (u8 *)(selected + (u32)counts);
                if (*entry <= 8)
                    ++*entry;
                if (*entry == 255)
                    *entry = one;
                ++selection;
                ++i;
            } while (i < loopScene->count);
        }
    }
    register u32 active = gUnknown_0810bf3e[scene->entries[0]];

    if (active != 0) {
        gUnknown_0300533c = 1;
    } else {
        gUnknown_0300533c = active;
    }
    FUN_0801fbfc(gUnknown_08155348, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    zeros[0] = 0;
    CpuFastSet(&zeros[0], (void *)0x05000000, 0x01000100);
    CpuFastSet(gUnknown_08edca74, (void *)0x05000380, 32);
    LZ77UnCompVram(gUnknown_08155648, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08155c5c, (void *)0x06010000);
    LZ77UnCompVram(gUnknown_081560a0, (void *)0x06014000);
    zeros[1] = 0;
    CpuFastSet(zero1Address, (void *)0x0600f800, 0x01000200);
    zeros[2] = 0;
    register void *clearDestination = (void *)0x060006c0;
    register u32 clearControl = 0x010001e0;

    CpuFastSet(zero2Address, clearDestination, clearControl);
    u16 *map = (u16 *)0x0600fc42;
    u16 tile = 0x2036;
    for (u32 i = 0; i < 30; ++i) {
        map[0] = tile++;
        map[32] = tile++;
        ++map;
    }
    LZ77UnCompVram(gUnknown_08155acc, (void *)0x0600e800);
    LZ77UnCompVram(gUnknown_08155bb0, (void *)0x0600f000);
    zeros[3] = 0;
    CpuFastSet(zero3Address, (void *)0x0600e000, 0x01000200);
    zeros[4] = 0;
    CpuFastSet(zero4Address, (void *)0x0600d800, 0x01000200);
    if (gUnknown_0300533c) {
        LZ77UnCompVram(gUnknown_08155a44, (void *)0x0600d900);
        FUN_0801f7d0(FUN_08035a8c, 16, gUnknown_03003e20, 0);
    } else {
        LZ77UnCompVram(gUnknown_081559bc, (void *)0x0600d900);
        FUN_0801f7d0(FUN_08035a8c, 16, gUnknown_03003e20, 0);
    }
    FUN_0801f7d0(FUN_08035c0c, 4, gUnknown_03003e20, 0);
    Node *node = FUN_0801f7d0(FUN_08035c24, 32, gUnknown_03003e20, 0);
    *(u16 *)((u8 *)node->allocation + 28) = 0;
    gUnknown_03005374 = 12;
    gUnknown_03005370 = 512;
    gUnknown_03005368 = gUnknown_03005330.entries[0];
    gUnknown_03005378 = 256;
    gUnknown_0300536c = 32;
    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08035258;
}

extern const u16 *gUnknown_03005358, *gUnknown_03005354;
extern u16 gUnknown_0300535c, gUnknown_03005348, gUnknown_0300534c, gUnknown_03005368;
extern u8 gUnknown_03005350;
extern u16 gUnknown_03005360[4];
extern const u16 *const *gUnknown_03004da4;
extern Input gUnknown_030048e0;
void FUN_0801f89c(void), FUN_0801fda0(void);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_08035258(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}
u32 FUN_08035268(void) {
    const u16 *text = gUnknown_03005358;
    if (*text == 0xfffe) {
        if (gUnknown_0300535c == 0)
            return 1;
        gUnknown_03005358 = gUnknown_03005354;
        gUnknown_0300535c = 0;
    } else if (*text == 0xfffd) {
        gUnknown_03005350 = 0;
    } else if (*text == 0xfffc) {
        if (gUnknown_030048e0.third & 1)
            gUnknown_03005358 = text + 1;
    } else if (*text == 0xfffb) {
        gUnknown_03005348 = text[1];
        gUnknown_03005358 = text + 2;
    } else if (*text == 0xfffa) {
        if (++gUnknown_0300534c > text[1]) {
            gUnknown_0300534c = 0;
            gUnknown_03005358 = text + 2;
        }
    } else if (*text == 0xfff9) {
        u16 kind = text[1];
        switch (kind) {
        case 1:
            gUnknown_03005354 = text + 2;
            gUnknown_03005360[0] = gUnknown_03005368 / 100 + 16;
            gUnknown_03005360[1] = (u16)(gUnknown_03005368 % 100) / 10 + 16;
            gUnknown_03005360[2] = gUnknown_03005368 % 10 + 16;
            gUnknown_03005360[3] = 0xfffe;
            gUnknown_03005358 = gUnknown_03005360;
            gUnknown_0300535c = 1;
            break;
        case 2:
            gUnknown_03005354 = text + 2;
            gUnknown_03005358 = gUnknown_03004da4[gUnknown_03005368];
            gUnknown_0300535c = 1;
            break;
        default:
            gUnknown_03005358 = text + 2;
        }
    } else if (*text == 0xfff8) {
        gUnknown_03005358 = text + 1;
    } else if (*text == 0xfff7) {
        gUnknown_03005358 = text + 1;
    } else {
        u32 width = FUN_08020978(gUnknown_03005350, 0, *text, gUnknown_03005348);
        gUnknown_03005350 += width;
        ++gUnknown_03005358;
    }
    return 0;
}

extern Node gUnknown_03003e20[];
extern u8 gUnknown_0300533c;
extern u16 gUnknown_03005378;
void CpuFastSet(const void *, void *, u32);
void FUN_0801f8c0(Node *), FUN_080355f0(Node *);
void FUN_0801fba0(u16, u16);
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *const *gUnknown_03005340;
extern const u16 *gUnknown_03005358;
extern u16 gUnknown_0300535c, gUnknown_03005348, gUnknown_0300534c;
extern u8 gUnknown_03005350;
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08035904(Node *), FUN_08035938(Node *), FUN_08035970(Node *), FUN_080359a4(Node *),
    FUN_08035830(Node *);
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8), FUN_0801f618(u16);
void FUN_08035408(Node *node) {
    State *state = (State *)node->allocation;
    switch (state->counter) {
    case 0:
        state->children[0] = FUN_0801f7d0(FUN_08035904, 16, gUnknown_03003e20, 0)->index;
        break;
    case 16:
        state->children[1] = FUN_0801f7d0(FUN_08035938, 16, gUnknown_03003e20, 0)->index;
        break;
    case 32:
        state->children[2] = FUN_0801f7d0(FUN_08035970, 16, gUnknown_03003e20, 0)->index;
        break;
    case 48:
        state->children[3] = FUN_0801f7d0(FUN_080359a4, 16, gUnknown_03003e20, 0)->index;
        break;
    case 64: {
        FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x060006c0, 30, 2, 0);
        register const u16 *text = *gUnknown_03005340;

        register u32 one = 1;

        gUnknown_03005358 = text;
        gUnknown_0300535c = 0;
        gUnknown_03005348 = one;
        gUnknown_0300534c = 0;
        gUnknown_03005350 = 0;
        FUN_0801f618(415);
        state->counter = 30;
        node->callback = FUN_08035830;
        break;
    }
    }
    ++state->counter;
}
void FUN_0803551c(Node *node) {
    State *state = (State *)node->allocation;
    if (state->counter > 0) {
        --state->counter;
    } else {
        u16 value = state->value;
        if (state->value == 0)
            state->value = 1;
        else
            state->value = value * 2;
        if (state->value > 255) {
            u32 zero = 0;
            CpuFastSet(&zero, (void *)0x060006c0, 0x010001e0);
            FUN_0801f8c0(&gUnknown_03003e20[state->children[0]]);
            FUN_0801f8c0(&gUnknown_03003e20[state->children[1]]);
            FUN_0801f8c0(&gUnknown_03003e20[state->children[2]]);
            FUN_0801f8c0(&gUnknown_03003e20[state->children[3]]);
            if (gUnknown_0300533c != 0) {
                FUN_0801f8c0(&gUnknown_03003e20[state->children[4]]);
                FUN_0801f8c0(&gUnknown_03003e20[state->children[5]]);
                FUN_0801f8c0(&gUnknown_03003e20[state->children[6]]);
                FUN_0801f8c0(&gUnknown_03003e20[state->children[7]]);
            }
            state->counter = 60;
            node->callback = FUN_080355f0;
        }
        gUnknown_03005378 = 84 - state->value;
        FUN_0801fba0(20, state->value);
    }
}

extern Scene gUnknown_03005330;
extern u16 gUnknown_03005368, gUnknown_03005378;
extern Node gUnknown_03003e20[];
extern const u8 gUnknown_08edc9b0[];
extern const u16 gUnknown_08edca6c[], gUnknown_08edca64[];
void FUN_0801fba0(u16, u16), FUN_0801f718(u16, u16);
void FUN_08035798(Node *), FUN_080358dc(Node *), FUN_080356f8(Node *), FUN_080359d8(Node *);
void FUN_080358b4(void);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_080355f0(Node *node) {
    s16 *state = (s16 *)node->allocation;
    if (gUnknown_03005330.count > 1) {
        --gUnknown_03005330.count;
        gUnknown_03005330.entries[0] = gUnknown_03005330.entries[1];
        gUnknown_03005330.entries[1] = gUnknown_03005330.entries[2];
        gUnknown_03005368 = gUnknown_03005330.entries[0];
        register u16 *offset = &gUnknown_03005378;

        register u32 initial = 256;
        register u16 stored asm("r0") = initial;
        asm("" : "+r"(stored));
        *offset = stored;
        stored = initial;
        asm("" : "+r"(stored));
        state[0] = stored;
        FUN_0801fba0(20, state[0]);
        u16 value = state[0];
        *offset = value + 84;
        FUN_0801fba0(20, -value);
        node->callback = FUN_08035798;
    } else {
        node->callback = (void (*)(Node *))FUN_080358b4;
        FUN_0801f718(56, 120);
    }
}
void FUN_08035668(Node *node) {
    u8 *state = (u8 *)node->allocation;
    register Node *child = FUN_0801f7d0(FUN_080356f8, 24, gUnknown_03003e20, 0);
    u8 firstIndex = child->index;
    register u32 zero = 0;

    state[9] = firstIndex;
    child->position->player = zero;
    child = FUN_0801f7d0(FUN_080356f8, 24, gUnknown_03003e20, 0);
    state[10] = child->index;
    child->position->player = 1;
    child = FUN_0801f7d0(FUN_080356f8, 24, gUnknown_03003e20, 0);
    state[11] = child->index;
    child->position->player = 2;
    child = FUN_0801f7d0(FUN_080356f8, 24, gUnknown_03003e20, 0);
    state[12] = child->index;
    child->position->player = 3;
    *(u16 *)(state + 2) = 90;
    node->callback = FUN_080358dc;
}
void FUN_080356f8(Node *node) {
    Motion *state = (Motion *)node->allocation;
    state->velocity = -0x80000;
    state->y = 160 << 16;
    node->position->parts = gUnknown_08edc9b0;
    node->position->tile = gUnknown_08edca6c[node->position->player];
    node->position->x = gUnknown_08edca64[node->position->player];
    node->position->y = 160;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->position->timer = node->position->player * 4;
    node->callback = FUN_080359d8;
}

extern u16 gUnknown_03005378;
extern u8 gUnknown_0300533c;
extern Node gUnknown_03003e20[];
extern Input gUnknown_030048e0;
extern Scene gUnknown_03005330;
extern void (*gUnknown_03002030)(void);
extern const u8 gUnknown_08edc980[], gUnknown_08edc998[];
extern const u16 gUnknown_08edca64[];
void FUN_0801fba0(u16, u16), FUN_0801f618(u16), FUN_0801fed8(u8, u8);
s16 FUN_0801f914(s16, s16);
u32 FUN_08035268(void);
u8 FUN_0802067c(u16 *, u32);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_0801f8c0(Node *);
void FUN_08035798(Node *), FUN_080357d8(Node *), FUN_08035668(Node *), FUN_08035408(Node *);
void FUN_0803631c(Node *), FUN_0803587c(Node *), FUN_0803551c(Node *);
void FUN_08035ad8(Node *), FUN_08035b28(Node *), FUN_08035b74(Node *), FUN_08035bc0(Node *),
    FUN_08035a2c(Node *);
void FUN_08035760(Node *node) {
    s16 *state = (s16 *)node->allocation;
    s32 value = 256;

    state[0] = value;
    state[1] = 30;
    gUnknown_03005378 = value + 84;
    FUN_0801fba0(20, (u16)-value);
    node->callback = FUN_08035798;
}

void FUN_08035798(Node *node) {
    CallbackState *state = (CallbackState *)node->allocation;

    if (state->counter > 0) {
        state->counter--;
    } else {
        if (gUnknown_0300533c != 0) {
            FUN_0801f618(57);
        } else {
            FUN_0801f618(56);
        }
        node->callback = FUN_080357d8;
    }
}

void FUN_080357d8(Node *node) {
    CallbackState *state = (CallbackState *)node->allocation;

    if ((state->value = FUN_0801f914(0, state->value)) == 0) {
        if (gUnknown_0300533c != 0) {
            node->callback = FUN_08035668;
        } else {
            state->counter = 0;
            node->callback = FUN_08035408;
        }
    }
    gUnknown_03005378 = state->value + 84;
    FUN_0801fba0(20, -state->value);
}

void FUN_08035830(Node *node) {
    CallbackState *state = (CallbackState *)node->allocation;

    if (state->counter > 0) {
        state->counter--;
    } else if ((u8)FUN_08035268() != 0) {
        Node *created = FUN_0801f7d0(FUN_0803631c, 16, gUnknown_03003e20, 0);

        state->nodeIndex = created->index;
        state->counter = 30;
        node->callback = FUN_0803587c;
    }
}

void FUN_0803587c(Node *node) {
    CallbackState *state = (CallbackState *)node->allocation;

    if ((gUnknown_030048e0.third & 1) != 0) {
        FUN_0801f8c0(&gUnknown_03003e20[state->nodeIndex]);
        state->counter = 30;
        node->callback = FUN_0803551c;
    }
}

void FUN_080358b4(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 256) != 0) {
        gUnknown_03002030 = gUnknown_03005330.callback;
    }
}

void FUN_080358dc(Node *node) {
    s16 *counter = (s16 *)node->allocation + 1;

    if (*counter > 0) {
        (*counter)--;
    } else {
        *counter = 0;
        node->callback = FUN_08035408;
    }
}

void FUN_08035904(Node *node) {
    node->position->parts = gUnknown_08edc980;
    node->position->tile = 58;
    node->position->x = 152;
    node->position->y = 120;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 12;
    node->callback = FUN_08035ad8;
}

void FUN_08035938(Node *node) {
    node->position->parts = gUnknown_08edc980;
    node->position->tile = 48;
    node->position->x = 80;
    node->position->y = -40;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 12;
    node->callback = FUN_08035b28;
}

void FUN_08035970(Node *node) {
    node->position->parts = gUnknown_08edc998;
    node->position->tile = 68;
    node->position->x = 24;
    node->position->y = 24;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 12;
    node->callback = FUN_08035b74;
}

void FUN_080359a4(Node *node) {
    node->position->parts = gUnknown_08edc998;
    node->position->tile = 76;
    node->position->x = 152;
    node->position->y = 128;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 12;
    node->callback = FUN_08035bc0;
}

void FUN_080359d8(Node *node) {
    Node *current = node;
    MovementState *state = (MovementState *)current->allocation;
    Position *position = current->position;

    if (position->timer != 0) {
        position->timer--;
        return;
    }

    state->y.fixed += state->velocity;
    current->position->y = state->y.half.high;
    state->velocity += 0x4000;
    if (state->velocity > 0 && state->y.half.high > 79) {
        current->position->y = 80;
        current->callback = FUN_08035a2c;
    }
    FUN_0801fed8(current->index, 0);
}

void FUN_08035a2c(Node *node) {
    Position *position = node->position;
    register u32 value asm("r2") = *(u16 *)&gUnknown_03005378;
    const u16 *offsets = gUnknown_08edca64;

    value -= 84;
    value += offsets[position->player];
    position->x = value;
    FUN_0801fed8(node->index, 0);
}

extern const u16 *gUnknown_03005358;
extern u16 gUnknown_0300535c, gUnknown_03005348, gUnknown_0300534c;
extern u8 gUnknown_03005350;
void FUN_08035a5c(const void *value, u8 mode) {
    gUnknown_03005358 = (const u16 *)value;
    gUnknown_0300535c = 0;
    gUnknown_03005348 = mode;
    gUnknown_0300534c = 0;
    gUnknown_03005350 = 0;
}
extern const u16 gUnknown_081555e8[], gUnknown_08155588[];
u8 FUN_08020500(u16 *, const u16 *, u32);
void FUN_08035b08(Node *), FUN_08035b58(Node *), FUN_08035ba4(Node *), FUN_08035bf0(Node *);
void FUN_08035a8c(Node *node) {
    u32 pending = FUN_08020500((u16 *)0x05000000, gUnknown_081555e8, 48) == 0;
    u32 result;

    result = FUN_08020500((u16 *)0x05000200, gUnknown_08155588, 48);
    pending |= result == 0;
    if (pending == 0) {
        node->callback = FUN_08035760;
    }
}

void FUN_08035ad8(Node *node) {
    node->position->y -= 8;
    if (node->position->y <= 40) {
        node->position->y = 40;
        node->callback = FUN_08035b08;
    }
    FUN_0801fed8(node->index, 0);
}

void FUN_08035b08(Node *node) {
    node->position->x = gUnknown_03005378 + 68;
    node->position->x = gUnknown_03005378 + 68;
    FUN_0801fed8(node->index, 0);
}

void FUN_08035b28(Node *node) {
    node->position->y += 8;
    if (node->position->y > 39) {
        node->position->y = 40;
        node->callback = FUN_08035b58;
    }
    FUN_0801fed8(node->index, 0);
}

void FUN_08035b58(Node *node) {
    node->position->x = gUnknown_03005378 - 4;
    FUN_0801fed8(node->index, 0);
}

void FUN_08035b74(Node *node) {
    node->position->x += 8;
    if (node->position->x > 87) {
        node->position->x = 88;
        node->callback = FUN_08035ba4;
    }
    FUN_0801fed8(node->index, 0);
}

void FUN_08035ba4(Node *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->index, 0);
}

void FUN_08035bc0(Node *node) {
    node->position->x -= 8;
    if (node->position->x <= 88) {
        node->position->x = 88;
        node->callback = FUN_08035bf0;
    }
    FUN_0801fed8(node->index, 0);
}

void FUN_08035bf0(Node *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->index, 0);
}

void FUN_08035c0c(Node *node) {
    u32 *counter = (u32 *)node->allocation;

    FUN_0801fba0(28, *(u8 *)counter);
    *counter -= 4;
}

extern const u8 gUnknown_08edcaf4[];
extern u16 gUnknown_03005370, gUnknown_03005378, gUnknown_0300536c;
extern u8 gUnknown_03005374;
extern Node gUnknown_03003e20[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u32);
void FUN_08035f54(Node *), FUN_08035fac(Node *), FUN_08036014(Node *), FUN_0803606c(Node *),
    FUN_080360c4(Node *), FUN_0803611c(Node *), FUN_08035d8c(Node *);
void FUN_08035c24(Node *node) {
    u8 *state = (u8 *)node->allocation;
    node->position->parts = gUnknown_08edcaf4;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378;
    node->position->y = gUnknown_0300536c;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    register u32 empty = 0xffff;
    *(u16 *)(state + 26) = empty;
    Node *child = FUN_0801f7d0(FUN_08035f54, 16, gUnknown_03003e20, 0);
    state[16] = child->index;
    child = FUN_0801f7d0(FUN_08035fac, 16, gUnknown_03003e20, 0);
    child->position->player = 0;
    node->position->tile = gUnknown_03005370;
    state[17] = child->index;
    child = FUN_0801f7d0(FUN_08035fac, 16, gUnknown_03003e20, 0);
    child->position->player = 1;
    node->position->tile = gUnknown_03005370;
    state[18] = child->index;
    child = FUN_0801f7d0(FUN_08035fac, 16, gUnknown_03003e20, 0);
    child->position->player = 2;
    node->position->tile = gUnknown_03005370;
    state[19] = child->index;
    child = FUN_0801f7d0(FUN_08036014, 16, gUnknown_03003e20, 0);
    state[20] = child->index;
    child = FUN_0801f7d0(FUN_0803606c, 16, gUnknown_03003e20, 0);
    state[21] = child->index;
    child = FUN_0801f7d0(FUN_080360c4, 16, gUnknown_03003e20, 0);
    state[22] = child->index;
    child = FUN_0801f7d0(FUN_0803611c, 16, gUnknown_03003e20, 0);
    state[24] = child->index;
    node->callback = FUN_08035d8c;
}
extern u16 gUnknown_03005368;
struct Record {
    u8 first, second, third, fourth, value, rest[3];
};
extern const Record gUnknown_0810b32c[];
extern const u8 gUnknown_08155388[], gUnknown_08edcb34[], gUnknown_08edcb8c[];
extern const u8 *gUnknown_03004db4;
void FUN_0801f8c0(Node *), FUN_0801fed8(u8, u8), FUN_0802036c(u32, u32, u32);
void FUN_08035d8c(Node *node) {
    u16 index = gUnknown_03005368;
    u8 *state = (u8 *)node->allocation;
    node->position->x = gUnknown_03005378;
    if (*(u16 *)(state + 28) != 0) {
        FUN_0801f8c0(&gUnknown_03003e20[state[16]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[17]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[18]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[19]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[20]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[21]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[22]]);
        FUN_0801f8c0(&gUnknown_03003e20[state[24]]);
        FUN_0801f8c0(node);
        return;
    }
    if (index != *(u16 *)(state + 26)) {
        u16 selection = gUnknown_0810b32c[gUnknown_03005368].value;
        if (selection > 19)
            selection -= 20;
        if (selection > 9)
            selection = 9;
        FUN_0802036c(0x05000200 + gUnknown_03005374 * 32, (u32)(gUnknown_08155388 + selection * 32),
                     32);
        FUN_0802036c(0x06010f20 + gUnknown_03005370 * 32, (u32)(gUnknown_03004db4 + index * 256),
                     256);
        gUnknown_03003e20[state[17]].position->tile = gUnknown_03005370 + (u8)(index / 100);
        gUnknown_03003e20[state[18]].position->tile =
            gUnknown_03005370 + (u8)((u16)(index % 100) / 10);
        gUnknown_03003e20[state[19]].position->tile = gUnknown_03005370 + (u8)(index % 10);
        gUnknown_03003e20[state[20]].position->parts =
            gUnknown_08edcb34 + (6 - gUnknown_0810b32c[index].first) * 8;
        gUnknown_03003e20[state[21]].position->parts =
            gUnknown_08edcb8c + (10 - gUnknown_0810b32c[index].second) * 8;
        gUnknown_03003e20[state[22]].position->parts =
            gUnknown_08edcb8c + (10 - gUnknown_0810b32c[index].third) * 8;
        *(u16 *)(state + 26) = index;
    }
    FUN_0801fed8(node->index, 0);
}

extern u16 gUnknown_03005368, gUnknown_0300536c, gUnknown_03005370, gUnknown_03005378;
extern u8 gUnknown_03005374;
extern const u8 gUnknown_08edcb24[], gUnknown_08edcb1c[], gUnknown_08edcb5c[], gUnknown_08edcbd4[],
    gUnknown_08edcb6c[];
extern const u16 gUnknown_0810bcd4[];
extern const u32 gUnknown_08edbbbc[];
void FUN_08036244(Node *), FUN_08036260(Node *), FUN_08036288(Node *), FUN_080362a4(Node *),
    FUN_08036174(Node *);
void FUN_08015924(u8, u16, u8, u16, u8);
s16 FUN_08015f40(u8), FUN_08015f58(u8);
void FUN_0802036c(u32, u32, u32), FUN_0801fed8(u8, u8);
void FUN_08035f54(Node *node) {
    node->position->parts = gUnknown_08edcb24;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378 + 4;
    node->position->y = gUnknown_0300536c + 10;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_08036244;
}

void FUN_08035fac(Node *node) {
    node->position->parts = gUnknown_08edcb1c;
    node->position->tile = gUnknown_03005370;
    {
        Position *position = node->position;
        const u16 *base = &gUnknown_03005378;
        u32 index = position->player;
        u32 x = index * 6 + 48;

        x += *base;
        position->x = x;
    }
    node->position->y = gUnknown_0300536c + 2;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_08036260;
}

void FUN_08036014(Node *node) {
    node->position->parts = gUnknown_08edcb5c;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378 + 4;
    node->position->y = gUnknown_0300536c + 3;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_08036288;
}

void FUN_0803606c(Node *node) {
    node->position->parts = gUnknown_08edcbd4;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378 + 32;
    node->position->y = gUnknown_0300536c + 71;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_080362a4;
}

void FUN_080360c4(Node *node) {
    node->position->parts = gUnknown_08edcbd4;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378 + 32;
    node->position->y = gUnknown_0300536c + 77;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_080362a4;
}

void FUN_0803611c(Node *node) {
    node->position->parts = gUnknown_08edcb6c;
    node->position->tile = gUnknown_03005370;
    node->position->x = gUnknown_03005378 + 16;
    node->position->y = gUnknown_0300536c + 16;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_03005374 << 4) | 8;
    node->callback = FUN_08036174;
}

void FUN_08036174(Node *node) {
    const Record *records = (const Record *)gUnknown_0810b32c;
    const u16 *recordIndex = &gUnknown_03005368;
    u16 selection = records[*recordIndex].value;

    if (selection > 19) {
        selection -= 20;
    }
    if (selection > 9) {
        selection = 10;
    }

    {
        Position *position = node->position;
        u32 frame = position->timer + 1;

        position->timer = frame;
        frame &= 0xFF;
        frame &= 1;
        if (frame != 0) {
            FUN_08015924((u8)selection, gUnknown_0810bcd4[*recordIndex], 2, gUnknown_03005370 + 129,
                         0);
        }
    }

    node->position->x = FUN_08015f40(node->position->player) + gUnknown_03005378 + 16;
    node->position->y = FUN_08015f58(node->position->player) + gUnknown_0300536c + 16;
    FUN_0802036c(0x05000260 + gUnknown_03005374 * 32, gUnknown_08edbbbc[selection], 32);
    FUN_0801fed8(node->index, 0);
}

extern u16 gUnknown_03005378;
extern const u16 gUnknown_08edcbe4[];
extern const u8 gUnknown_08edc9a8[];
void FUN_0801fed8(u8, u8);
void FUN_08036244(Node *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->index, 0);
}
void FUN_08036260(Node *node) {
    Position *position = node->position;
    u16 *offset = (u16 *)&gUnknown_03005378;
    int x = position->player * 6 + 48;
    int base = *offset;
    position->x = x + base;
    FUN_0801fed8(node->index, 0);
}
void FUN_08036288(Node *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->index, 0);
}
void FUN_080362a4(Node *node) {
    node->position->x = gUnknown_03005378 + 32;
    FUN_0801fed8(node->index, 0);
}
void FUN_080362c0(Node *node) {
    node->position->x = gUnknown_03005378 + 32;
    FUN_0801fed8(node->index, 0);
}
void FUN_080362dc(Node *node) {
    if (++node->position->state > 31)
        node->position->state = 0;
    node->position->tile = gUnknown_08edcbe4[(node->position->state >> 3) & 3];
    FUN_0801fed8(node->index, 0);
}
void FUN_0803631c(Node *node) {
    node->position->parts = gUnknown_08edc9a8;
    node->position->tile = 84;
    node->position->x = 208;
    node->position->y = 154;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_080362dc;
}

extern const u16 gUnknown_08155348[] __attribute__((section(".rodata.registers"))) = {
    0,  0, 8,  0x5f02, 16, 0,      18, 0, 10, 0x5d02, 20, 0xff00, 22, 0, 12, 0x1c03,
    24, 0, 26, 0,      14, 0x1b03, 28, 0, 30, 0,      80, 0,      82, 0, 84, 0};
extern const u16 gUnknown_081565cc[];
extern const u16 gUnknown_081565fc[];
extern const u16 gUnknown_0815662c[];
extern const u16 gUnknown_0815665c[];
extern const u16 gUnknown_0815668c[];
extern const u16 gUnknown_081566bc[];
extern const u16 gUnknown_081566ec[];
extern const u16 gUnknown_08156718[];
extern const u16 gUnknown_08156744[];
extern const u16 gUnknown_08156770[];
extern const u16 gUnknown_0815679c[];
extern const u16 gUnknown_081567c8[];
extern const u16 gUnknown_081567f4[];
extern const u16 gUnknown_08156820[];
extern const u16 gUnknown_08156848[];
extern const u16 gUnknown_08156870[];
extern const u16 gUnknown_08156898[];
extern const u16 gUnknown_081568c0[];
extern const u16 gUnknown_081568e8[];
extern const u16 gUnknown_08156910[];
extern const u16 gUnknown_08156944[];
extern const u16 gUnknown_08156978[];
extern const u16 gUnknown_081569ac[];
extern const u16 gUnknown_081569e0[];
extern const u16 gUnknown_08156a14[];
extern const u16 gUnknown_08156a48[];
extern const u16 gUnknown_08156a74[];
extern const u16 gUnknown_08156aa0[];
extern const u16 gUnknown_08156acc[];
extern const u16 gUnknown_08156af8[];
extern const u16 gUnknown_08156b24[];
extern const u16 gUnknown_08156b50[];
extern const u16 gUnknown_08156b80[];
extern const u16 gUnknown_08156bb0[];
extern const u16 gUnknown_08156be0[];
extern const u16 gUnknown_08156c10[];
extern const u16 gUnknown_08156c40[];
extern const u16 *const gUnknown_08edc9b8[] __attribute__((section(".rodata.labels"))) = {
    gUnknown_081565cc, gUnknown_081565fc, gUnknown_0815662c, gUnknown_0815665c, gUnknown_0815668c,
    gUnknown_081566bc, gUnknown_081566ec, gUnknown_08156718, gUnknown_08156744, gUnknown_08156770,
    gUnknown_0815679c, gUnknown_081567c8, gUnknown_081567f4, gUnknown_08156820, gUnknown_08156848,
    gUnknown_08156870, gUnknown_08156898, gUnknown_081568c0, gUnknown_081568e8, gUnknown_08156910,
    gUnknown_08156944, gUnknown_08156978, gUnknown_081569ac, gUnknown_081569e0, gUnknown_08156a14,
    gUnknown_08156a48, gUnknown_08156a74, gUnknown_08156aa0, gUnknown_08156acc, gUnknown_08156af8,
    gUnknown_08156b24, gUnknown_08156b50, gUnknown_08156b80, gUnknown_08156bb0, gUnknown_08156be0,
    gUnknown_08156c10, gUnknown_08156c40};
extern const u16 *const *const gUnknown_08edca4c[] __attribute__((section(".rodata.labels"))) = {
    gUnknown_08edc9b8 + 0,  gUnknown_08edc9b8 + 6,  gUnknown_08edc9b8 + 13,
    gUnknown_08edc9b8 + 19, gUnknown_08edc9b8 + 31, gUnknown_08edc9b8 + 25};
extern const u16 gUnknown_08edca64[]
    __attribute__((section(".rodata.labels"))) = {76, 106, 134, 164};
extern const u16 gUnknown_08edca6c[] __attribute__((section(".rodata.labels"))) = {0, 16, 0, 32};
extern const u16 gUnknown_08edcbe4[] __attribute__((section(".rodata.tiles"))) = {84, 88, 92, 88};
u8 gUnknown_0300533c __attribute__((section(".bss"))) = 0;
const u16 *const *gUnknown_03005340 __attribute__((section(".bss.state_3005340"))) = 0;
u16 gUnknown_03005348 __attribute__((section(".bss.state_3005348"))) = 0;
u16 gUnknown_0300534c __attribute__((section(".bss.state_300534c"))) = 0;
u8 gUnknown_03005350 __attribute__((section(".bss.state_3005350"))) = 0;
const u16 *gUnknown_03005354 __attribute__((section(".bss.state_3005354"))) = 0;
const u16 *gUnknown_03005358 __attribute__((section(".bss.state_3005358"))) = 0;
u16 gUnknown_0300535c __attribute__((section(".bss.state_300535c"))) = 0;
u16 gUnknown_03005360[4] __attribute__((section(".bss.state_3005360"))) = {0};
u16 gUnknown_03005368 __attribute__((section(".bss.state_3005368"))) = 0;
u16 gUnknown_0300536c __attribute__((section(".bss.state_300536c"))) = 0;
u16 gUnknown_03005370 __attribute__((section(".bss.state_3005370"))) = 0;
u8 gUnknown_03005374 __attribute__((section(".bss.state_3005374"))) = 0;
u16 gUnknown_03005378 __attribute__((section(".bss.state_3005378"))) = 0;
}
