#include "types.h"

struct MP2KPlayerState {
    const void *songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 padding10;
    u8 checkSongPriority;
    u32 clock;
    u8 padding16[12];
    u16 tempoRawBPM;
    u16 tempoScale;
    u16 tempoInterval;
    u16 tempoCounter;
    u16 fadeInterval;
    u16 fadeCounter;
    u16 fadeVolume;
    u8 padding42[2];
    struct MP2KTrack *tracks;
    u8 padding48[4];
    u32 lockStatus;
    void (*nextPlayerFunction)(void);
    struct MP2KPlayerState *nextPlayer;
};

struct MP2KTrack {
    u8 status;
    u8 padding1[10];
    s8 keyShiftPublic;
    u8 padding12;
    u8 pitchPublic;
    u8 padding14;
    u8 bendRange;
    u8 padding16[3];
    u8 volPublic;
    u8 padding20;
    s8 panPublic;
    u8 lfoSpeedCounter;
    u8 modDepth;
    u8 modType;
    u8 lfoSpeed;
    u8 modCalculated;
    u8 padding27[3];
    u8 echoVolume;
    u8 echoLength;
    void *channel;
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

struct MusicPlayer {
    struct MP2KPlayerState *player;
    struct MP2KTrack *tracks;
    u8 trackCount;
    u8 priority;
    u16 padding10;
};

struct Song {
    const void *header;
    u16 playerIndex;
    u16 padding6;
};

struct MP2KSongHeader {
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    const void *voicegroup;
    const u8 *parts[1];
};

struct MixerSource {
    u8 status;
    u8 padding1[63];
};

struct SoundMixerState {
    u32 lockStatus;
    volatile u8 dmaCounter;
    u8 reverb;
    u8 numChannels;
    u8 masterVolume;
    u8 freqOption;
    u8 padding9[2];
    u8 framesPerDmaCycle;
    u8 padding12[4];
    s32 samplesPerFrame;
    s32 sampleRate;
    s32 sampleRateReciprocal;
    struct MixerSource *cgbChans;
    void (*playerMain)(void);
    struct MP2KPlayerState *playerHead;
    void (*cgbSound)(void);
    void (*cgbOscOff)(u8 channel);
    void (*midiKeyToCgbFreq)(void);
    void **mplayJumpTable;
    void (*playNote)(void);
    void (*extVolPit)(void);
    u8 padding64[16];
    struct MixerSource channels[12];
    u8 pcmBuffer[0xC60];
};

extern void SoundMain(void);
extern void FUN_08048c08(struct MP2KPlayerState *player, struct MP2KTrack *track);
extern const struct MusicPlayer gMPlayTable[];
extern const struct Song gSongTable[];
extern u8 gNumMusicPlayers[];
extern void FUN_08049544(u32 mode);
extern struct SoundMixerState *gSoundInfo;
extern void MP2KPlayerMain(void);
extern void CpuSet(const void *source, void *destination, u32 mode);
extern const u16 gPcmSamplesPerVBlankTable[];
extern void (*gMPlayJumpTable34)(void *);
extern void (*gMPlayJumpTable35)(void *);
extern void (*gMPlayJumpTable0)(void *, void *);
extern void (*gXcmdTable[])(struct MP2KPlayerState *, struct MP2KTrack *);
extern void *gMPlayJumpTable[];
extern void MP2K_event_nxx(void);
extern void MP2K_event_null(void);
extern void MPlayJumpTableCopy(void **table);
void Clear64byte(void *memory);
void MPlayContinue(struct MP2KPlayerState *player);
void MPlayStop(struct MP2KPlayerState *player);
void MPlayStart(struct MP2KPlayerState *player, const void *songHeader);
void MPlayOpen(struct MP2KPlayerState *player, struct MP2KTrack *tracks, u8 trackCount);
void m4aSoundVSync(void);
void SoundClear(void);
void m4aSoundVSyncOff(void);
void m4aSoundVSyncOn(void);
void SampleFreqSet(u32 frequency);
void m4aSoundMode(u32 mode);
void SoundInit(struct SoundMixerState *soundInfo);

void m4aSoundMain(void) { SoundMain(); }

void m4aSongNumStart(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    MPlayStart(musicPlayer->player, song->header);
}

void m4aSongNumStartOrContinue(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    if (musicPlayer->player->songHeader != song->header) {
        MPlayStart(musicPlayer->player, song->header);
    } else if ((musicPlayer->player->status & 0xFFFF) == 0) {
        MPlayStart(musicPlayer->player, song->header);
    } else if (musicPlayer->player->status & 0x80000000) {
        MPlayContinue(musicPlayer->player);
    }
}

void m4aSongNumStop(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    if (musicPlayer->player->songHeader == song->header) {
        MPlayStop(musicPlayer->player);
    }
}

void m4aSongNumContinue(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    if (musicPlayer->player->songHeader == song->header) {
        MPlayContinue(musicPlayer->player);
    }
}

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
        player->fadeCounter = speed;
        player->fadeInterval = speed;
        player->fadeVolume = 0x100;
        player->lockStatus = 0x68736D53;
    }
}

void MPlayStop(struct MP2KPlayerState *player) {
    s32 i;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }

    player->lockStatus++;
    player->status |= 0x80000000;
    i = player->trackCount;
    track = player->tracks;
    while (i > 0) {
        FUN_08048c08(player, track);
        i--;
        track++;
    }
    player->lockStatus = 0x68736D53;
}

void MPlayStart(struct MP2KPlayerState *player, const void *header) {
    const struct MP2KSongHeader *songHeader = header;
    s32 i;
    u8 checkSongPriority;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }

    player->lockStatus++;
    checkSongPriority = player->checkSongPriority;
    if (!checkSongPriority ||
        ((!player->songHeader || !(player->tracks[0].status & 0x40)) &&
         ((player->status & 0xFFFF) == 0 || (player->status & 0x80000000))) ||
        player->priority <= songHeader->priority) {
        player->status = 0;
        player->songHeader = songHeader;
        *(const void **)((u8 *)player + 48) = songHeader->voicegroup;
        player->priority = songHeader->priority;
        player->clock = 0;
        player->tempoRawBPM = 150;
        player->tempoInterval = 150;
        player->tempoScale = 0x100;
        player->tempoCounter = 0;
        player->fadeInterval = 0;

        i = 0;
        track = player->tracks;
        while (i < songHeader->trackCount && i < player->trackCount) {
            FUN_08048c08(player, track);
            track->status = 0xC0;
            track->channel = 0;
            track->command = (u8 *)songHeader->parts[i];
            i++;
            track++;
        }
        while (i < player->trackCount) {
            FUN_08048c08(player, track);
            track->status = 0;
            i++;
            track++;
        }
        if (songHeader->reverb & 0x80) {
            FUN_08049544(songHeader->reverb);
        }
    }
    player->lockStatus = 0x68736D53;
}

void MPlayOpen(struct MP2KPlayerState *player, struct MP2KTrack *tracks, u8 trackCount) {
    struct SoundMixerState *soundInfo;

    if (trackCount == 0) {
        return;
    }
    if (trackCount > 16) {
        trackCount = 16;
    }

    soundInfo = gSoundInfo;
    if (soundInfo->lockStatus != 0x68736D53) {
        return;
    }
    soundInfo->lockStatus++;
    Clear64byte(player);
    player->tracks = tracks;
    player->trackCount = trackCount;
    player->status = 0x80000000;
    while (trackCount != 0) {
        tracks->status = 0;
        trackCount--;
        tracks++;
    }

    if (soundInfo->playerMain != 0) {
        player->nextPlayerFunction = soundInfo->playerMain;
        player->nextPlayer = soundInfo->playerHead;
        soundInfo->playerMain = 0;
    }
    soundInfo->playerHead = player;
    soundInfo->playerMain = MP2KPlayerMain;
    soundInfo->lockStatus = 0x68736D53;
    player->lockStatus = 0x68736D53;
}

void m4aSoundVSync(void) {
    volatile struct SoundMixerState *soundInfo = gSoundInfo;

    if (soundInfo->lockStatus - 0x68736D53 <= 1) {
        if ((s8)--soundInfo->dmaCounter <= 0) {
            soundInfo->dmaCounter = soundInfo->framesPerDmaCycle;
            if (*(volatile u32 *)0x040000C4 & 0x02000000) {
                *(volatile u32 *)0x040000C4 = 0x84400004;
            }
            if (*(volatile u32 *)0x040000D0 & 0x02000000) {
                *(volatile u32 *)0x040000D0 = 0x84400004;
            }
            *(volatile u16 *)0x040000C6 = 0x0400;
            *(volatile u16 *)0x040000D2 = 0x0400;
            *(volatile u16 *)0x040000C6 = 0xB600;
            *(volatile u16 *)0x040000D2 = 0xB600;
        }
    }
}

void SoundClear(void) {
    struct SoundMixerState *soundInfo = gSoundInfo;
    s32 i;
    struct MixerSource *channel;

    if (soundInfo->lockStatus != 0x68736D53) {
        return;
    }
    soundInfo->lockStatus++;

    i = 12;
    channel = soundInfo->channels;
    while (i > 0) {
        channel->status = 0;
        i--;
        channel++;
    }

    channel = soundInfo->cgbChans;
    if (channel != 0) {
        i = 1;
        while (i <= 4) {
            soundInfo->cgbOscOff(i);
            channel->status = 0;
            i++;
            channel++;
        }
    }
    soundInfo->lockStatus = 0x68736D53;
}

void m4aSoundVSyncOff(void) {
    struct SoundMixerState *soundInfo = gSoundInfo;
    u32 zero;

    if (soundInfo->lockStatus - 0x68736D53 <= 1) {
        soundInfo->lockStatus += 10;
        *(volatile u16 *)0x04000102 = 0;
        if (*(volatile u32 *)0x040000C4 & 0x02000000) {
            *(volatile u32 *)0x040000C4 = 0x84400004;
        }
        if (*(volatile u32 *)0x040000D0 & 0x02000000) {
            *(volatile u32 *)0x040000D0 = 0x84400004;
        }
        *(volatile u16 *)0x040000C6 = 0x0400;
        *(volatile u16 *)0x040000D2 = 0x0400;
        zero = 0;
        CpuSet(&zero, soundInfo->pcmBuffer, 0x05000318);
    }
}

void m4aSoundVSyncOn(void) {
    struct SoundMixerState *soundInfo = gSoundInfo;
    u32 lockStatus = soundInfo->lockStatus;

    if (lockStatus == 0x68736D53) {
        return;
    }

    *(volatile u16 *)0x040000C6 = 0xB600;
    *(volatile u16 *)0x040000D2 = 0xB600;
    soundInfo->dmaCounter = 0;
    soundInfo->lockStatus = lockStatus - 10;

    while (*(volatile u8 *)0x04000006 == 159) {
    }
    while (*(volatile u8 *)0x04000006 != 159) {
    }

    *(volatile u16 *)0x04000100 = -(0x44940 / soundInfo->samplesPerFrame);
    *(volatile u16 *)0x04000102 = 0x80;
}

void SampleFreqSet(u32 frequency) {
    struct SoundMixerState *soundInfo;
    s32 samplesPerFrame;

    m4aSoundVSyncOff();
    soundInfo = gSoundInfo;
    frequency = (frequency & 0xF0000) >> 16;
    soundInfo->freqOption = frequency;
    samplesPerFrame = gPcmSamplesPerVBlankTable[frequency - 1];
    soundInfo->samplesPerFrame = samplesPerFrame;
    soundInfo->framesPerDmaCycle = 0x630 / samplesPerFrame;
    soundInfo->sampleRate = (597275 * samplesPerFrame + 5000) / 10000;
    soundInfo->sampleRateReciprocal = ((0x1000000 / soundInfo->sampleRate) + 1) >> 1;
    m4aSoundVSyncOn();
}

void m4aSoundMode(u32 mode) {
    struct SoundMixerState *soundInfo = gSoundInfo;
    u32 value;

    if (soundInfo->lockStatus != 0x68736D53) {
        return;
    }
    soundInfo->lockStatus++;

    value = mode & 0xFF;
    if (value != 0) {
        soundInfo->reverb = value & 0x7F;
    }

    value = mode & 0xF00;
    if (value != 0) {
        struct MixerSource *channel;

        soundInfo->numChannels = value >> 8;
        value = 12;
        channel = soundInfo->channels;
        while (value != 0) {
            channel->status = 0;
            value--;
            channel++;
        }
    }

    value = mode & 0xF000;
    if (value != 0) {
        soundInfo->masterVolume = value >> 12;
    }

    value = mode & 0xB00000;
    if (value != 0) {
        value = (value & 0x300000) >> 14;
        *(volatile u8 *)0x04000089 = (*(volatile u8 *)0x04000089 & 0x3F) | value;
    }

    value = mode & 0xF0000;
    if (value != 0) {
        SampleFreqSet(value);
    }
    soundInfo->lockStatus = 0x68736D53;
}

void SoundInit(struct SoundMixerState *soundInfo) {
    u32 zero;

    soundInfo->lockStatus = 0;
    if (*(volatile u32 *)0x040000C4 & 0x02000000) {
        *(volatile u32 *)0x040000C4 = 0x84400004;
    }
    if (*(volatile u32 *)0x040000D0 & 0x02000000) {
        *(volatile u32 *)0x040000D0 = 0x84400004;
    }
    *(volatile u16 *)0x040000C6 = 0x0400;
    *(volatile u16 *)0x040000D2 = 0x0400;
    *(volatile u16 *)0x04000084 = 0x008F;
    *(volatile u16 *)0x04000082 = 0xA90E;
    *(volatile u8 *)0x04000089 = (*(volatile u8 *)0x04000089 & 0x3F) | 0x40;

    *(volatile u32 *)0x040000BC = (u32)soundInfo->pcmBuffer;
    *(volatile u32 *)0x040000C0 = 0x040000A0;
    *(volatile u32 *)0x040000C8 = (u32)(soundInfo->pcmBuffer + 0x630);
    *(volatile u32 *)0x040000CC = 0x040000A4;
    gSoundInfo = soundInfo;
    zero = 0;
    CpuSet(&zero, soundInfo, 0x050003EC);

    soundInfo->numChannels = 8;
    soundInfo->masterVolume = 15;
    soundInfo->playNote = MP2K_event_nxx;
    soundInfo->cgbSound = MP2K_event_null;
    soundInfo->cgbOscOff = (void (*)(u8))MP2K_event_null;
    soundInfo->midiKeyToCgbFreq = MP2K_event_null;
    soundInfo->extVolPit = MP2K_event_null;
    MPlayJumpTableCopy(gMPlayJumpTable);
    soundInfo->mplayJumpTable = gMPlayJumpTable;
    SampleFreqSet(0x40000);
    soundInfo->lockStatus = 0x68736D53;
}

void FadeOutBody(struct MP2KPlayerState *player) {
    s32 i;
    struct MP2KTrack *track;
    u16 fadeVolume;

    if (player->fadeInterval == 0) {
        return;
    }
    if (--player->fadeCounter != 0) {
        return;
    }

    player->fadeCounter = player->fadeInterval;
    if (player->fadeVolume & 2) {
        if ((u16)(player->fadeVolume += 16) >= 0x100) {
            player->fadeVolume = 0x100;
            player->fadeInterval = 0;
        }
    } else if ((s16)(player->fadeVolume -= 16) <= 0) {
        i = player->trackCount;
        track = player->tracks;
        while (i > 0) {
            u32 temporary;

            FUN_08048c08(player, track);
            fadeVolume = player->fadeVolume;
            temporary = 1;
            temporary &= fadeVolume;
            if (!temporary) {
                track->status = 0;
            }
            i--;
            track++;
        }

        if (player->fadeVolume & 1) {
            player->status |= 0x80000000;
        } else {
            player->status = 0x80000000;
        }
        player->fadeInterval = 0;
        return;
    }

    i = player->trackCount;
    track = player->tracks;
    while (i > 0) {
        if (track->status & 0x80) {
            track->volPublic = player->fadeVolume >> 2;
            track->status |= 3;
        }
        i--;
        track++;
    }
}

void m4aMPlayTempoControl(struct MP2KPlayerState *player, u16 tempo) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->tempoScale = tempo;
        player->tempoInterval = (player->tempoRawBPM * player->tempoScale) >> 8;
        player->lockStatus = 0x68736D53;
    }
}

void m4aMPlayVolumeControl(struct MP2KPlayerState *player, u16 trackBits, u16 volume) {
    s32 i;
    u32 bit;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }
    player->lockStatus++;
    i = player->trackCount;
    track = player->tracks;
    bit = 1;
    while (i > 0) {
        if (trackBits & bit) {
            if (track->status & 0x80) {
                track->volPublic = volume / 4;
                track->status |= 3;
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    player->lockStatus = 0x68736D53;
}

void m4aMPlayPitchControl(struct MP2KPlayerState *player, u16 trackBits, s16 pitch) {
    s32 i;
    u32 bit;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }
    player->lockStatus++;
    i = player->trackCount;
    track = player->tracks;
    bit = 1;
    while (i > 0) {
        if (trackBits & bit) {
            if (track->status & 0x80) {
                track->keyShiftPublic = pitch >> 8;
                track->pitchPublic = pitch;
                track->status |= 12;
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    player->lockStatus = 0x68736D53;
}

void m4aMPlayPanpotControl(struct MP2KPlayerState *player, u16 trackBits, u8 pan) {
    s32 i;
    u32 bit;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }
    player->lockStatus++;
    i = player->trackCount;
    track = player->tracks;
    bit = 1;
    while (i > 0) {
        if (trackBits & bit) {
            if (track->status & 0x80) {
                track->panPublic = pan;
                track->status |= 3;
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    player->lockStatus = 0x68736D53;
}

void ClearModM(struct MP2KTrack *track) {
    track->modCalculated = 0;
    track->lfoSpeedCounter = 0;
    if (track->modType == 0) {
        track->status |= 12;
    } else {
        track->status |= 3;
    }
}

void m4aMPlayModDepthSet(struct MP2KPlayerState *player, u16 trackBits, u8 modDepth) {
    s32 i;
    u32 bit;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }
    player->lockStatus++;
    i = player->trackCount;
    track = player->tracks;
    bit = 1;
    while (i > 0) {
        if (trackBits & bit) {
            if (track->status & 0x80) {
                track->modDepth = modDepth;
                if (!track->modDepth) {
                    ClearModM(track);
                }
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    player->lockStatus = 0x68736D53;
}

void m4aMPlayLFOSpeedSet(struct MP2KPlayerState *player, u16 trackBits, u8 lfoSpeed) {
    s32 i;
    u32 bit;
    struct MP2KTrack *track;

    if (player->lockStatus != 0x68736D53) {
        return;
    }
    player->lockStatus++;
    i = player->trackCount;
    track = player->tracks;
    bit = 1;
    while (i > 0) {
        if (trackBits & bit) {
            if (track->status & 0x80) {
                track->lfoSpeed = lfoSpeed;
                if (!track->lfoSpeed) {
                    ClearModM(track);
                }
            }
        }
        i--;
        track++;
        bit <<= 1;
    }
    player->lockStatus = 0x68736D53;
}

void m4aMPlayContinue(struct MP2KPlayerState *player) { MPlayContinue(player); }

void m4aMPlayAllStop(void) {
    s32 i;

    for (i = 0; i < (u16)(u32)gNumMusicPlayers; i++) {
        MPlayStop(gMPlayTable[i].player);
    }
}

void m4aMPlayAllContinue(void) {
    s32 i;

    for (i = 0; i < (u16)(u32)gNumMusicPlayers; i++) {
        MPlayContinue(gMPlayTable[i].player);
    }
}

void m4aMPlayFadeOut(struct MP2KPlayerState *player, u16 speed) { MPlayFadeOut(player, speed); }

void m4aMPlayFadeOutTemporarily(struct MP2KPlayerState *player, u16 speed) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->fadeCounter = speed;
        player->fadeInterval = speed;
        player->fadeVolume = 0x101;
        player->lockStatus = 0x68736D53;
    }
}

void m4aMPlayFadeIn(struct MP2KPlayerState *player, u16 speed) {
    if (player->lockStatus == 0x68736D53) {
        player->lockStatus++;
        player->fadeCounter = speed;
        player->fadeInterval = speed;
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
            if (track->status & 0x80) {
                if (track->status & 0x40) {
                    Clear64byte(track);
                    track->status = 0x80;
                    track->bendRange = 2;
                    track->volPublic = 64;
                    track->lfoSpeed = 22;
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
