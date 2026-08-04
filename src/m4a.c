#include "types.h"

struct MP2KPlayerState;

struct MP2KTrack {
    u8 padding0[30];
    u8 echoVolume;
    u8 echoLength;
    u8 padding32[4];
    u8 voiceType;
    u8 padding37;
    u8 cgbLength;
    u8 panSweep;
    void *wave;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 padding48[16];
    u8 *command;
};

extern void FUN_08048f94(struct MP2KPlayerState *player, u16 speed);
extern void FUN_08048f74(struct MP2KPlayerState *player);
extern void SoundMain(void);
extern void (*gMPlayJumpTable34)(void *);
extern void (*gMPlayJumpTable35)(void *);
extern void (*gMPlayJumpTable0)(void *, void *);
extern void (*gXcmdTable[])(struct MP2KPlayerState *, struct MP2KTrack *);

void m4aSoundMain(void) { SoundMain(); }

void m4aMPlayContinue(struct MP2KPlayerState *player) { FUN_08048f74(player); }

void m4aMPlayFadeOut(struct MP2KPlayerState *player, u16 speed) { FUN_08048f94(player, speed); }

void ClearChain(void *channel) {
    void (*function)(void *) = gMPlayJumpTable34;

    function(channel);
}

void Clear64byte(void *memory) {
    void (*function)(void *) = gMPlayJumpTable35;

    function(memory);
}

void MP2K_event_xxx(void *player, void *track) {
    void (*function)(void *, void *) = gMPlayJumpTable0;

    function(player, track);
}

void MP2K_event_xcmd(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    u32 command = *track->command;

    track->command++;
    gXcmdTable[command](player, track);
}

void MP2K_event_xtype(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->voiceType = *track->command;
    track->command++;
}

void MP2K_event_xatta(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->attack = *track->command;
    track->command++;
}

void MP2K_event_xdeca(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->decay = *track->command;
    track->command++;
}

void MP2K_event_xsust(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->sustain = *track->command;
    track->command++;
}

void MP2K_event_xrele(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->release = *track->command;
    track->command++;
}

void MP2K_event_xiecv(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->echoVolume = *track->command;
    track->command++;
}

void MP2K_event_xiecl(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->echoLength = *track->command;
    track->command++;
}

void MP2K_event_xleng(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->cgbLength = *track->command;
    track->command++;
}

void MP2K_event_xswee(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    track->panSweep = *track->command;
    track->command++;
}

void MP2K_event_null(void) {}
