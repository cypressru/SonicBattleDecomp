#include "types.h"

struct MP2KPlayerState {
    u32 padding0;
    u32 status;
    u8 trackCount;
    u8 padding9[27];
    u16 fadeCounter;
    u16 fadeInterval;
    u16 fadeVolume;
    u8 padding42[2];
    struct MP2KTrack *tracks;
    u8 padding48[4];
    u32 lockStatus;
};

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
    u8 padding68[12];
};

extern void SoundMain(void);
extern void (*gMPlayJumpTable34)(void *);
extern void (*gMPlayJumpTable35)(void *);
extern void (*gMPlayJumpTable0)(void *, void *);
extern void (*gXcmdTable[])(struct MP2KPlayerState *, struct MP2KTrack *);
void Clear64byte(void *memory);

void m4aSoundMain(void) { SoundMain(); }

void MPlayContinue(struct MP2KPlayerState *player) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->status &= 0x7FFFFFFF;
        player->lockStatus = 0x68736D53;
    }
}

void MPlayFadeOut(struct MP2KPlayerState *player, u16 speed) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->fadeInterval = speed;
        player->fadeCounter = speed;
        player->fadeVolume = 0x100;
        player->lockStatus = 0x68736D53;
    }
}

void m4aMPlayContinue(struct MP2KPlayerState *player) { MPlayContinue(player); }

void m4aMPlayFadeOut(struct MP2KPlayerState *player, u16 speed) { MPlayFadeOut(player, speed); }

void m4aMPlayFadeOutTemporarily(struct MP2KPlayerState *player, u16 speed) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->fadeInterval = speed;
        player->fadeCounter = speed;
        player->fadeVolume = 0x101;
        player->lockStatus = 0x68736D53;
    }
}

void m4aMPlayFadeIn(struct MP2KPlayerState *player, u16 speed) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->fadeInterval = speed;
        player->fadeCounter = speed;
        player->fadeVolume = 2;
        player->status &= 0x7FFFFFFF;
        player->lockStatus = 0x68736D53;
    }
}

void m4aMPlayImmInit(struct MP2KPlayerState *player) {
    if (player->lockStatus == 0x68736D53) {
        s32 trackCount;
        struct MP2KTrack *track;

        player->lockStatus++;
        trackCount = player->trackCount;
        track = player->tracks;
        while (trackCount > 0) {
            if (track->padding0[0] & 0x80) {
                if (track->padding0[0] & 0x40) {
                    Clear64byte(track);
                    track->padding0[0] = 0x80;
                    track->padding0[15] = 2;
                    track->padding0[19] = 64;
                    track->padding0[25] = 22;
                    track->voiceType = 1;
                }
            }
            trackCount--;
            track++;
        }
        player->lockStatus = 0x68736D53;
    }
}

void MusicPlayerJumpTableCopy(void) { asm("swi 0x2A"); }

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

void MP2K_event_xwave(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    union {
        u8 *pointer;
        u8 bytes[sizeof(void *)];
    } wave;

    wave.bytes[0] = track->command[0];
    wave.bytes[1] = track->command[1];
    wave.bytes[2] = track->command[2];
    wave.bytes[3] = track->command[3];
    track->wave = wave.pointer;
    track->command += sizeof(void *);
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
