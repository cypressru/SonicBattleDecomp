#include "types.h"

struct MP2KPlayerState {
    const void *songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 padding10;
    u8 checkSongPriority;
    u32 clock;
    u8 padding16[8];
    u8 *memAccArea;
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
    u8 padding1[7];
    s8 keyShiftCalculated;
    u8 pitchCalculated;
    s8 keyShift;
    s8 keyShiftPublic;
    s8 tune;
    u8 pitchPublic;
    s8 bend;
    u8 bendRange;
    u8 volRightCalculated;
    u8 volLeftCalculated;
    u8 volume;
    u8 volPublic;
    s8 pan;
    s8 panPublic;
    s8 modCalculated;
    u8 modDepth;
    u8 modType;
    u8 lfoSpeed;
    u8 lfoSpeedCounter;
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
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelopeVolume;
    u8 envelopeGoal;
    u8 envelopeCounter;
    u8 echoVolume;
    u8 echoLength;
    u8 padding14[11];
    u8 sustainGoal;
    u8 nrx4;
    u8 pan;
    u8 panMask;
    u8 cgbStatus;
    u8 length;
    u8 sweep;
    u32 frequency;
    void *wave;
    void *current;
    u8 padding44[20];
};

struct SoundMixerState {
    u32 lockStatus;
    volatile u8 dmaCounter;
    u8 reverb;
    u8 numChannels;
    u8 masterVolume;
    u8 freqOption;
    u8 extensionFlags;
    u8 cgbCounter15;
    u8 framesPerDmaCycle;
    u8 maxScanlines;
    u8 padding13[3];
    s32 samplesPerFrame;
    s32 sampleRate;
    s32 sampleRateReciprocal;
    struct MixerSource *cgbChans;
    void (*playerMain)(void);
    struct MP2KPlayerState *playerHead;
    void (*cgbSound)(void);
    void (*cgbOscOff)(u8 channel);
    u32 (*midiKeyToCgbFreq)(u8, u8, u8);
    void **mplayJumpTable;
    void (*playNote)(void);
    void (*extVolPit)(void);
    u8 padding64[16];
    struct MixerSource channels[12];
    u8 pcmBuffer[0xC60];
};

extern void SoundMain(void);
extern void SoundMainRAM(void);
extern u8 SoundMainRAM_Buffer[];
extern void FUN_08048c08(struct MP2KPlayerState *player, struct MP2KTrack *track);
extern const struct MusicPlayer gMPlayTable[];
extern const struct Song gSongTable[];
extern u8 gNumMusicPlayers[];
extern void FUN_08049544(u32 mode);
extern struct SoundMixerState *gSoundInfo;
extern void MP2KPlayerMain(void);
extern void CpuSet(const void *source, void *destination, u32 mode);
extern const u16 gPcmSamplesPerVBlankTable[];
extern u8 gMaxLines[];
extern struct SoundMixerState gSoundInfoState;
extern struct MixerSource gCgbChans[];
extern u8 gMPlayMemAccArea[];
extern const u8 gNoiseTable[];
extern const u8 gCgbScaleTable[];
extern const s16 gCgbFreqTable[];
extern const u8 gCgb3Vol[];
extern void (*gMPlayJumpTable34)(void *);
extern void (*gMPlayJumpTable35)(void *);
extern void (*gMPlayJumpTable0)(void *, void *);
extern void (*gMPlayJumpTable1)(struct MP2KPlayerState *, struct MP2KTrack *);
extern void (*gXcmdTable[])(struct MP2KPlayerState *, struct MP2KTrack *);
extern void *gMPlayJumpTable[];
extern void MP2K_event_nxx(void);
extern void MP2K_event_null(void);
extern void MPlayJumpTableCopy(void **table);
extern void MP2K_event_memacc(struct MP2KPlayerState *, struct MP2KTrack *);
extern void MP2K_event_lfos(struct MP2KPlayerState *, struct MP2KTrack *);
extern void MP2K_event_mod(struct MP2KPlayerState *, struct MP2KTrack *);
extern void MP2K_event_xcmd(struct MP2KPlayerState *, struct MP2KTrack *);
extern void MP2K_event_endtie(struct MP2KPlayerState *, struct MP2KTrack *);
extern void TrackStop(void);
extern void TrkVolPitSet(struct MP2KPlayerState *, struct MP2KTrack *);
extern void CgbSound(void);
extern void CgbOscOff(u8 channel);
extern u32 MidiKeyToCgbFreq(u8 channel, u8 key, u8 fineAdjust);
void Clear64byte(void *memory);
void MPlayContinue(struct MP2KPlayerState *player);
void MPlayStop(struct MP2KPlayerState *player);
void MPlayStart(struct MP2KPlayerState *player, const void *songHeader);
void MPlayOpen(struct MP2KPlayerState *player, struct MP2KTrack *tracks, u8 trackCount);
void FadeOutBody(struct MP2KPlayerState *player);
void m4aSoundVSync(void);
void SoundClear(void);
void m4aSoundVSyncOff(void);
void m4aSoundVSyncOn(void);
void SampleFreqSet(u32 frequency);
void m4aSoundMode(u32 mode);
void SoundInit(struct SoundMixerState *soundInfo);
void MPlayExtender(struct MixerSource *cgbChannels);
void m4aSoundInit(void);

void m4aSoundInit(void) {
    s32 i;

    CpuSet((void *)((u32)SoundMainRAM & ~1), SoundMainRAM_Buffer, 0x04000100);
    SoundInit(&gSoundInfoState);
    MPlayExtender(gCgbChans);
    m4aSoundMode(0x9300E800);

    for (i = 0; i < (u16)gNumMusicPlayers; i++) {
        struct MP2KPlayerState *player = gMPlayTable[i].player;

        MPlayOpen(player, gMPlayTable[i].tracks, gMPlayTable[i].trackCount);
        player->checkSongPriority = gMPlayTable[i].padding10;
        player->memAccArea = gMPlayMemAccArea;
    }
}

void m4aSoundMain(void) { SoundMain(); }

void m4aSongNumStart(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    MPlayStart(musicPlayer->player, song->header);
}

void m4aSongNumStartOrChange(u16 number) {
    const struct MusicPlayer *musicPlayerTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[number];
    const struct MusicPlayer *musicPlayer = &musicPlayerTable[song->playerIndex];

    if (musicPlayer->player->songHeader != song->header) {
        MPlayStart(musicPlayer->player, song->header);
    } else {
        if ((musicPlayer->player->status & 0xFFFF) == 0 ||
            (musicPlayer->player->status & 0x80000000)) {
            MPlayStart(musicPlayer->player, song->header);
        }
    }
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
    soundInfo->midiKeyToCgbFreq = (u32 (*)(u8, u8, u8))MP2K_event_null;
    soundInfo->extVolPit = MP2K_event_null;
    MPlayJumpTableCopy(gMPlayJumpTable);
    soundInfo->mplayJumpTable = gMPlayJumpTable;
    SampleFreqSet(0x40000);
    soundInfo->lockStatus = 0x68736D53;
}

void MPlayExtender(struct MixerSource *cgbChannels) {
    struct SoundMixerState *soundInfo;
    u32 lockStatus;
    u32 zero;

    *(volatile u16 *)0x04000084 = 0x008F;
    *(volatile u16 *)0x04000080 = 0;
    *(volatile u8 *)0x04000063 = 8;
    *(volatile u8 *)0x04000069 = 8;
    *(volatile u8 *)0x04000079 = 8;
    *(volatile u8 *)0x04000065 = 0x80;
    *(volatile u8 *)0x0400006D = 0x80;
    *(volatile u8 *)0x0400007D = 0x80;
    *(volatile u8 *)0x04000070 = 0;
    *(volatile u8 *)0x04000080 = 0x77;

    soundInfo = gSoundInfo;
    lockStatus = soundInfo->lockStatus;
    if (lockStatus != 0x68736D53) {
        return;
    }
    soundInfo->lockStatus++;

    gMPlayJumpTable[8] = MP2K_event_memacc;
    gMPlayJumpTable[17] = MP2K_event_lfos;
    gMPlayJumpTable[19] = MP2K_event_mod;
    gMPlayJumpTable[28] = MP2K_event_xcmd;
    gMPlayJumpTable[29] = MP2K_event_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;

    soundInfo->cgbChans = cgbChannels;
    soundInfo->cgbSound = CgbSound;
    soundInfo->cgbOscOff = CgbOscOff;
    soundInfo->midiKeyToCgbFreq = MidiKeyToCgbFreq;
    soundInfo->maxScanlines = (u32)gMaxLines;

    zero = 0;
    CpuSet(&zero, cgbChannels, 0x05000040);
    cgbChannels[0].type = 1;
    cgbChannels[0].panMask = 0x11;
    cgbChannels[1].type = 2;
    cgbChannels[1].panMask = 0x22;
    cgbChannels[2].type = 3;
    cgbChannels[2].panMask = 0x44;
    cgbChannels[3].type = 4;
    cgbChannels[3].panMask = 0x88;
    soundInfo->lockStatus = lockStatus;
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
    track->lfoSpeedCounter = 0;
    track->modCalculated = 0;
    if (track->modType == 0) {
        track->status |= 12;
    } else {
        track->status |= 3;
    }
}

void TrkVolPitSet(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    if (track->status & 1) {
        s32 x;
        s32 y;

        x = (u32)(track->volume * track->volPublic) >> 5;
        if (track->modType == 1) {
            x = (u32)(x * (track->modCalculated + 128)) >> 7;
        }
        y = 2 * track->pan + track->panPublic;
        if (track->modType == 2) {
            y += track->modCalculated;
        }
        if (y < -128) {
            y = -128;
        } else if (y > 127) {
            y = 127;
        }
        track->volRightCalculated = (u32)((y + 128) * x) >> 8;
        track->volLeftCalculated = (u32)((127 - y) * x) >> 8;
    }

    if (track->status & 4) {
        s32 bend = track->bend * track->bendRange;
        s32 x = (track->tune + bend) * 4 + (track->keyShift << 8) + (track->keyShiftPublic << 8) +
                track->pitchPublic;

        if (track->modType == 0) {
            x += 16 * track->modCalculated;
        }
        track->keyShiftCalculated = x >> 8;
        track->pitchCalculated = x;
    }
    track->status &= 0xFA;
}

u32 MidiKeyToCgbFreq(u8 channel, u8 key, u8 fineAdjust) {
    if (channel == 4) {
        if (key <= 20) {
            key = 0;
        } else {
            key -= 21;
            if (key > 59) {
                key = 59;
            }
        }
        return gNoiseTable[key];
    } else {
        s32 value1;
        s32 value2;

        if (key <= 35) {
            fineAdjust = 0;
            key = 0;
        } else {
            key -= 36;
            if (key > 130) {
                key = 130;
                fineAdjust = 255;
            }
        }
        value1 = gCgbScaleTable[key];
        value1 = gCgbFreqTable[value1 & 0xF] >> (value1 >> 4);
        value2 = gCgbScaleTable[key + 1];
        value2 = gCgbFreqTable[value2 & 0xF] >> (value2 >> 4);
        return value1 + ((fineAdjust * (value2 - value1)) >> 8) + 2048;
    }
}

#define MEMACC_CONDITIONAL_JUMP(condition)                                                         \
    if (condition) {                                                                               \
        goto conditionTrue;                                                                        \
    } else {                                                                                       \
        goto conditionFalse;                                                                       \
    }

void MP2K_event_memacc(struct MP2KPlayerState *player, struct MP2KTrack *track) {
    u32 operation;
    u8 *address;
    u8 data;

    operation = *track->command;
    track->command++;
    address = player->memAccArea + *track->command;
    track->command++;
    data = *track->command;
    track->command++;

    switch (operation) {
    case 0:
        *address = data;
        return;
    case 1:
        *address += data;
        return;
    case 2:
        *address -= data;
        return;
    case 3:
        *address = player->memAccArea[data];
        return;
    case 4:
        *address += player->memAccArea[data];
        return;
    case 5:
        *address -= player->memAccArea[data];
        return;
    case 6:
        MEMACC_CONDITIONAL_JUMP(*address == data)
        return;
    case 7:
        MEMACC_CONDITIONAL_JUMP(*address != data)
        return;
    case 8:
        MEMACC_CONDITIONAL_JUMP(*address > data)
        return;
    case 9:
        MEMACC_CONDITIONAL_JUMP(*address >= data)
        return;
    case 10:
        MEMACC_CONDITIONAL_JUMP(*address <= data)
        return;
    case 11:
        MEMACC_CONDITIONAL_JUMP(*address < data)
        return;
    case 12:
        MEMACC_CONDITIONAL_JUMP(*address == player->memAccArea[data])
        return;
    case 13:
        MEMACC_CONDITIONAL_JUMP(*address != player->memAccArea[data])
        return;
    case 14:
        MEMACC_CONDITIONAL_JUMP(*address > player->memAccArea[data])
        return;
    case 15:
        MEMACC_CONDITIONAL_JUMP(*address >= player->memAccArea[data])
        return;
    case 16:
        MEMACC_CONDITIONAL_JUMP(*address <= player->memAccArea[data])
        return;
    case 17:
        MEMACC_CONDITIONAL_JUMP(*address < player->memAccArea[data])
        return;
    default:
        return;
    }

conditionTrue:
    gMPlayJumpTable1(player, track);
    return;

conditionFalse:
    track->command += 4;
}

#undef MEMACC_CONDITIONAL_JUMP

void CgbOscOff(u8 channel) {
    switch (channel) {
    case 1:
        *(volatile u8 *)0x04000063 = 8;
        *(volatile u8 *)0x04000065 = 0x80;
        break;
    case 2:
        *(volatile u8 *)0x04000069 = 8;
        *(volatile u8 *)0x0400006D = 0x80;
        break;
    case 3:
        *(volatile u8 *)0x04000070 = 0;
        break;
    default:
        *(volatile u8 *)0x04000079 = 8;
        *(volatile u8 *)0x0400007D = 0x80;
        break;
    }
}

static inline int CgbPan(struct MixerSource *channel) {
    u32 rightRaw = channel->rightVolume;
    u32 leftRaw = channel->leftVolume;
    u32 rightVolume = (u8)rightRaw;
    u32 leftVolume = (u8)leftRaw;

    if (rightVolume >= leftVolume) {
        if (rightVolume / 2 >= leftVolume) {
            channel->pan = 0x0F;
            return 1;
        }
    } else {
        if (leftVolume / 2 >= rightVolume) {
            channel->pan = 0xF0;
            return 1;
        }
    }
    return 0;
}

void CgbModVol(struct MixerSource *channel) {
    if (!CgbPan(channel)) {
        channel->pan = 0xFF;
        channel->envelopeGoal = (u32)(channel->rightVolume + channel->leftVolume) / 16;
    } else {
        channel->envelopeGoal = (u32)(channel->rightVolume + channel->leftVolume) / 16;
        if (channel->envelopeGoal > 15) {
            channel->envelopeGoal = 15;
        }
    }
    channel->sustainGoal = (channel->envelopeGoal * channel->sustain + 15) >> 4;
    channel->pan &= channel->panMask;
}

void CgbSound(void) {
    s32 channelNumber;
    struct MixerSource *channel;
    s32 previousCounter;
    struct SoundMixerState *soundInfo = gSoundInfo;
    volatile u8 *nrx0;
    volatile u8 *nrx1;
    volatile u8 *nrx2;
    volatile u8 *nrx3;
    volatile u8 *nrx4;
    s32 envelopeDirection;
    volatile u8 channelIndex;
    volatile u8 *channelIndexPointer;
    int mask = 0xFF;

    if (soundInfo->cgbCounter15) {
        soundInfo->cgbCounter15--;
    } else {
        soundInfo->cgbCounter15 = 14;
    }

    for (channelNumber = 1, channel = soundInfo->cgbChans; channelNumber <= 4;
         channelNumber++, channel++) {
        channelIndexPointer = &channelIndex;
        if (!(channel->status & 0xC7)) {
            continue;
        }

        switch (channelNumber) {
        case 1:
            nrx0 = (volatile u8 *)0x04000060;
            nrx1 = (volatile u8 *)0x04000062;
            nrx2 = (volatile u8 *)0x04000063;
            nrx3 = (volatile u8 *)0x04000064;
            nrx4 = (volatile u8 *)0x04000065;
            *channelIndexPointer = 0;
            break;
        case 2:
            nrx0 = (volatile u8 *)0x04000061;
            nrx1 = (volatile u8 *)0x04000068;
            nrx2 = (volatile u8 *)0x04000069;
            nrx3 = (volatile u8 *)0x0400006C;
            nrx4 = (volatile u8 *)0x0400006D;
            *channelIndexPointer = 1;
            break;
        case 3:
            nrx0 = (volatile u8 *)0x04000070;
            nrx1 = (volatile u8 *)0x04000072;
            nrx2 = (volatile u8 *)0x04000073;
            nrx3 = (volatile u8 *)0x04000074;
            nrx4 = (volatile u8 *)0x04000075;
            *channelIndexPointer = 2;
            break;
        default:
            nrx0 = (volatile u8 *)0x04000071;
            nrx1 = (volatile u8 *)0x04000078;
            nrx2 = (volatile u8 *)0x04000079;
            nrx3 = (volatile u8 *)0x0400007C;
            nrx4 = (volatile u8 *)0x0400007D;
            *channelIndexPointer = 3;
            break;
        }

        previousCounter = soundInfo->cgbCounter15;
        envelopeDirection = *nrx2;

        if (channel->status & 0x80) {
            if (!(channel->status & 0x40)) {
                channel->status = 3;
                channel->cgbStatus = 3;
                CgbModVol(channel);
                switch (channelNumber) {
                case 1:
                    *nrx0 = channel->sweep;
                case 2:
                    *nrx1 = ((u32)channel->wave << 6) + channel->length;
                    goto initializeEnvelope;
                case 3:
                    if (channel->wave != channel->current) {
                        *nrx0 = 0x40;
                        *(volatile u32 *)0x04000090 = ((u32 *)channel->wave)[0];
                        *(volatile u32 *)0x04000094 = ((u32 *)channel->wave)[1];
                        *(volatile u32 *)0x04000098 = ((u32 *)channel->wave)[2];
                        *(volatile u32 *)0x0400009C = ((u32 *)channel->wave)[3];
                        channel->current = channel->wave;
                    }
                    *nrx0 = 0;
                    *nrx1 = channel->length;
                    if (channel->length) {
                        channel->nrx4 = 0xC0;
                    } else {
                        channel->nrx4 = 0x80;
                    }
                    break;
                default:
                    *nrx1 = channel->length;
                    *nrx3 = (u32)channel->wave << 3;
                initializeEnvelope:
                    envelopeDirection = channel->attack + 8;
                    if (channel->length) {
                        channel->nrx4 = 0x40;
                    } else {
                        channel->nrx4 = 0;
                    }
                    break;
                }
                channel->envelopeCounter = channel->attack;
                if ((s8)(channel->attack & mask)) {
                    channel->envelopeVolume = 0;
                    goto envelopeStepComplete;
                } else {
                    goto envelopeDecayStart;
                }
            } else {
                goto oscillatorOff;
            }
        } else if ((channel->status & 4) ||
                   !(*(volatile u8 *)0x04000084 & (1 << *channelIndexPointer))) {
            channel->echoLength--;
            if ((s8)(channel->echoLength & mask) <= 0) {
            oscillatorOff:
                CgbOscOff(channelNumber);
                channel->status = 0;
                goto channelComplete;
            }
            goto envelopeComplete;
        } else if ((channel->status & 0x40) && (channel->status & 3)) {
            channel->status &= ~3;
            channel->envelopeCounter = channel->release;
            if ((s8)(channel->release & mask)) {
                channel->cgbStatus |= 1;
                if (channelNumber != 3) {
                    envelopeDirection = channel->release;
                }
                goto envelopeStepComplete;
            } else {
                goto envelopePseudoEchoStart;
            }
        } else {
        envelopeStepRepeat:
            if (channel->envelopeCounter == 0) {
                if (channelNumber == 3) {
                    channel->cgbStatus |= 1;
                }
                CgbModVol(channel);
                if ((channel->status & 3) == 0) {
                    channel->envelopeVolume--;
                    if ((s8)(channel->envelopeVolume & mask) <= 0) {
                    envelopePseudoEchoStart:
                        channel->envelopeVolume =
                            ((channel->envelopeGoal * channel->echoVolume) + 0xFF) >> 8;
                        if (channel->envelopeVolume) {
                            channel->status |= 4;
                            channel->cgbStatus |= 1;
                            if (channelNumber != 3) {
                                envelopeDirection = 8;
                            }
                            goto envelopeComplete;
                        } else {
                            goto oscillatorOff;
                        }
                    } else {
                        channel->envelopeCounter = channel->release;
                    }
                } else if ((channel->status & 3) == 1) {
                envelopeSustain:
                    channel->envelopeVolume = channel->sustainGoal;
                    channel->envelopeCounter = 7;
                } else if ((channel->status & 3) == 2) {
                    int envelopeVolume;
                    int sustainGoal;

                    channel->envelopeVolume--;
                    envelopeVolume = (s8)(channel->envelopeVolume & mask);
                    sustainGoal = (s8)channel->sustainGoal;
                    if (envelopeVolume <= sustainGoal) {
                    envelopeSustainStart:
                        if (channel->sustain == 0) {
                            channel->status &= ~3;
                            goto envelopePseudoEchoStart;
                        } else {
                            channel->status--;
                            channel->cgbStatus |= 1;
                            if (channelNumber != 3) {
                                envelopeDirection = 8;
                            }
                            goto envelopeSustain;
                        }
                    } else {
                        channel->envelopeCounter = channel->decay;
                    }
                } else {
                    channel->envelopeVolume++;
                    if ((u8)(channel->envelopeVolume & mask) >= channel->envelopeGoal) {
                    envelopeDecayStart:
                        channel->status--;
                        channel->envelopeCounter = channel->decay;
                        if ((u8)(channel->envelopeCounter & mask)) {
                            channel->cgbStatus |= 1;
                            channel->envelopeVolume = channel->envelopeGoal;
                            if (channelNumber != 3) {
                                envelopeDirection = channel->decay;
                            }
                        } else {
                            goto envelopeSustainStart;
                        }
                    } else {
                        channel->envelopeCounter = channel->attack;
                    }
                }
            }
        }

    envelopeStepComplete:
        channel->envelopeCounter--;
        if (previousCounter == 0) {
            previousCounter--;
            goto envelopeStepRepeat;
        }

    envelopeComplete:
        if (channel->cgbStatus & 2) {
            int pwmRate;

            if (channelNumber < 4 && (channel->type & 8)) {
                pwmRate = *(volatile u8 *)0x04000089;

                // This is unreachable for the byte-wide register read, but keeps agbcc's promoted
                // temporary distinct from the volatile load result as in the retail emission.
                if (pwmRate < 0) {
                    channel->frequency = 0;
                }

                if (pwmRate < 0x40) {
                    channel->frequency = (channel->frequency + 2) & 0x7FC;
                } else if (pwmRate < 0x80) {
                    channel->frequency = (channel->frequency + 1) & 0x7FE;
                }
            }
            if (channelNumber != 4) {
                *nrx3 = channel->frequency;
            } else {
                *nrx3 = (*nrx3 & 8) | channel->frequency;
            }
            channel->nrx4 = (channel->nrx4 & 0xC0) + ((channel->frequency & 0x3F00) >> 8);
            *nrx4 = (s8)(channel->nrx4 & mask);
        }

        if (channel->cgbStatus & 1) {
            *(volatile u8 *)0x04000081 =
                (*(volatile u8 *)0x04000081 & ~channel->panMask) | channel->pan;
            if (channelNumber == 3) {
                *nrx2 = gCgb3Vol[channel->envelopeVolume];
                if (channel->nrx4 & 0x80) {
                    *nrx0 = 0x80;
                    *nrx4 = channel->nrx4;
                    channel->nrx4 &= 0x7F;
                }
            } else {
                u32 envelopeMask = 0xF;

                *nrx2 = (envelopeDirection & envelopeMask) + (channel->envelopeVolume << 4);
                *nrx4 = channel->nrx4 | 0x80;
                if (channelNumber == 1 && !(*nrx0 & 8)) {
                    *nrx4 = channel->nrx4 | 0x80;
                }
            }
        }

    channelComplete:
        channel->cgbStatus = 0;
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
