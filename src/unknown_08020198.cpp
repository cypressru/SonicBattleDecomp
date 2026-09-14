#include "types.h"
// Original language is unknown; C++ fallback with synthetic linkage.
// Boundary, type and related-reconstruction evidence: docs/input-tu-cpp.md.
extern "C" {
struct InputState08020198 {
    u16 held, inverted, pressed, released, repeated;
    u8 timer, delay, interval;
};
extern InputState08020198 gUnknown_030048e0;
void FUN_0802021c(u8 first, u8 second);
void FUN_08020198(void) {
    InputState08020198 *state = &gUnknown_030048e0;
    u16 oldHeld = state->held;
    u16 oldInverted = state->inverted;
    state->inverted = *(volatile u16 *)0x04000130 | 0xfc00;
    state->held = ~state->inverted;
    state->pressed = oldInverted & state->held;
    state->released = state->inverted & oldHeld;
    if (state->held == 0) {
        state->repeated = 0;
        return;
    }
    if (state->held > oldHeld) {
        state->repeated = oldHeld ^ state->held;
        state->timer = state->delay;
        return;
    }
    if (--state->timer != 0) {
        state->repeated = 0;
        return;
    }
    state->repeated = state->held;
    state->timer = state->interval;
}
void FUN_080201f8(void) {
    gUnknown_030048e0.repeated = 0;
    gUnknown_030048e0.pressed = 0;
    gUnknown_030048e0.held = 0;
    gUnknown_030048e0.inverted = 0xffff;
    FUN_0802021c(0, 0);
}
void FUN_0802021c(u8 first, u8 second) {
    if (first == 0 || second == 0) {
        first = 15;
        second = 7;
    }
    gUnknown_030048e0.delay = first;
    gUnknown_030048e0.timer = first;
    gUnknown_030048e0.interval = second;
}
}
