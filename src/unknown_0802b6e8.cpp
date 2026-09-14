// C++ reconstruction fallback; evidence and ownership: docs/results-tu-cpp.md.
#include "types.h"
// Observed shared prefix views, not original type or allocation-size claims.
extern "C" {
struct Position {
    const void *parts;
    s16 x, y;
    u16 tile;
    u8 attr0, attr1, attr2, player, state, unused;
};
struct Node {
    void (*callback)(Node *);
    u8 field4, previous, index, next;
    Position *position;
    void *allocation;
};
}

extern "C" {
extern u8 gUnknown_03001620[], gUnknown_03002110[];
extern u32 gUnknown_03005264;
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *gUnknown_08edd4f0[];
extern u16 gUnknown_030051f0[][8];
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u16 FUN_08020fac(u16);
u32 FUN_08020978(u32, u32, u16, u32);
void FUN_0802b6e8(u32 player, u32 incoming) {
    register u32 selection = incoming;
    register u32 playerOffset = player * 1280;
    register u8 *destination = (u8 *)(playerOffset + 0x06016c00);
    register u32 row = 0;
    register u32 zero = 0;
    do {
        u32 column = 0;
        u32 next = row + 1;
        u32 *out = (u32 *)(row * 128 + (u32)destination);
        for (; column < 16; column++)
            *out++ = zero;
        row = next;
    } while (row < 10);
    if (selection == 0)
        return;
    register u8 *characterBase asm("r0") = gUnknown_03001620;
    characterBase += selection;
    asm volatile("" : : "r"(characterBase));
    register u8 *character = characterBase;
    character += 19;
    if (*character == 255)
        return;
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 10, 4, 0);
    if (gUnknown_03005264 == 2 && gUnknown_03002110[119] != 0) {
        const u16 *text = gUnknown_08edd4f0[*character];
        u32 advance = 0;
        while (*text != 0xfffe) {
            s16 offset = (14 - (s16)FUN_08020fac(*text)) / 2;
            u32 x = offset + advance;
            FUN_08020978(x + 1, 1, *text, 8);
            FUN_08020978(x, 0, *text, 7);
            advance += 10;
            text++;
        }
    } else {
        register u32 nameOffset asm("r1") = selection * 16;
        u16 *text = (u16 *)((u32)gUnknown_030051f0 + nameOffset);
        text[5] = 0xfffe;
        u32 advance = 0;
        while (*text != 0xfffe) {
            s16 offset = (14 - (s16)FUN_08020fac(*text)) / 2;
            u32 x = offset + advance;
            FUN_08020978(x + 1, 1, *text, 8);
            FUN_08020978(x, 0, *text, 7);
            advance += 14;
            text++;
        }
    }
}
}

extern "C" {
extern const u8 gUnknown_08071b7c[], gUnknown_0807173c[];
extern const u16 *const *gUnknown_03005280;
extern u8 gUnknown_03001620[], gUnknown_03005278[];
extern u16 gUnknown_03005290[];
extern const u16 gUnknown_0811dc88[];
void FUN_08020ecc(u32, const u8 *, u8 *, u32, u32, u8);
u32 FUN_08020b74(u32, u32, const u16 *, u32, u32);
u32 FUN_08020ad0(const u16 *);
void FUN_0802b81c(u32 player, u32 selection) {
    u32 offset = player * 1280;
    u8 *destination = (u8 *)(offset + 0x06016c40);
    u32 row = 0;
    const u8 *tiles = gUnknown_08071b7c;
    const u8 *layout = gUnknown_0807173c;
    u8 *drawDestination = (u8 *)(offset + 0x06016c38);
    u32 zero = 0;
    do {
        u32 column = 0;
        u32 next = row + 1;
        u32 *out = (u32 *)(row * 128 + (u32)destination);
        for (; column < 16; column++)
            *out++ = zero;
        row = next;
    } while (row < 10);
    FUN_08020ecc((u32)tiles, layout, drawDestination, 10, 4, 0);
    u32 width;
    register u8 *values asm("r1");
    register u8 *mapping;
    if (selection != 0) {
        FUN_08020b74(0, 0, gUnknown_03005280[1], 7, 8);
        width = FUN_08020ad0(gUnknown_03005280[1]);
        values = gUnknown_03001620;
        mapping = gUnknown_03005278 + player;
        values += 51;
    } else {
        FUN_08020b74(0, 0, gUnknown_03005280[0], 7, 8);
        width = FUN_08020ad0(gUnknown_03005280[0]);
        values = gUnknown_03001620;
        mapping = gUnknown_03005278 + player;
        values += 39;
    }
    register u8 *valueAddress = values + *mapping;
    u32 value = *valueAddress;
    if (value > 999)
        value = 999;
    u16 *buffer = gUnknown_03005290;
    u16 *out = buffer;
    const u16 *digits = gUnknown_0811dc88;
    if (value > 99)
        *out++ = digits[(u16)(value / 100)];
    if (value > 9)
        *out++ = digits[(u16)((u16)(value % 100) / 10)];
    *out++ = digits[(u16)(value % 10)];
    *out = 0xfffe;
    FUN_08020b74(width, 0, buffer, 7, 8);
    asm volatile("" : : "r"(buffer));
}
}

extern "C" {
extern u32 gUnknown_03005264, gUnknown_03005254, gUnknown_03005258;
extern u8 gUnknown_030052a4[], gUnknown_03005278[], gUnknown_030052a0, gUnknown_0300527c;
extern u8 gUnknown_03001620[], gUnknown_03001634[], gUnknown_0300162c[], gUnknown_03002600[],
    gUnknown_03002110[];
extern u8 gUnknown_03005200[], gUnknown_03001d0c[];
extern u16 gUnknown_03005270[], gUnknown_03001b10[];
extern const u16 *const gUnknown_08edd518[];
extern const u16 *const gUnknown_08edbbe8[],
    *const gUnknown_08edbbf4[], *const gUnknown_08edbbfc[], *const gUnknown_08edbc04[],
                                                                *const gUnknown_08edbc0c[],
                                                                    *const gUnknown_08edbc14[];
extern const u16 *const *gUnknown_03005280;
extern const u16 gUnknown_0811c244[], gUnknown_081327d4[];
extern const u8 gUnknown_081323d4[], gUnknown_08132544[], gUnknown_0811c3a4[], gUnknown_0811d818[],
    gUnknown_0811d9bc[];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_080217d0(u32), FUN_0802cc78(void), FUN_080336dc(void), FUN_08029250(void);
void FUN_0801fbfc(const u16 *, u8), FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void),
    FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), CpuSet(const void *, void *, u32),
    LZ77UnCompVram(const void *, void *);
void *memcpy(void *, const void *, unsigned long);
void FUN_0802b6e8(u32, u32), FUN_0802b81c(u32, u32),
    FUN_08021000(u16 *, const u16 *, u16, u16, u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_08030d3c(Node *), FUN_08030d20(Node *), FUN_0802c37c(Node *);
void FUN_080158e4(void), FUN_0801fba0(u8, u16), FUN_0802c1d4(void), FUN_08018444(void),
    FUN_0801f618(u16), FUN_0801f9e8(u16);
void FUN_0802b980(void) {
    u32 fills[5];
    register u32 *mode asm("r6") = &gUnknown_03005264;
    if (*mode == 1)
        FUN_080217d0(0);
    register u8 *ranks = gUnknown_030052a4;
    register u8 *mapping asm("r3") = gUnknown_03005278;
    mapping[0] = 0;
    ranks[0] = 0;
    mapping[1] = 1;
    ranks[1] = 1;
    mapping[2] = 2;
    ranks[2] = 2;
    mapping[3] = 3;
    ranks[3] = 3;
    register u8 *winner asm("r5") = &gUnknown_030052a0;
    *winner = 2;
    register u8 *countAddress asm("r0") = &gUnknown_0300527c;
    *countAddress = 0;
    register u32 i asm("r7") = 0;
    register u8 *sceneBase = gUnknown_03001620;
    u8 *scene = sceneBase;
    register u8 *characters asm("r3") = scene + 20;
    for (; i < 4; i++)
        if (*(u8 *)(i + (u32)characters) != 255)
            gUnknown_0300527c++;
    if (scene[4] == 2) {
        register u32 first = 0;
        do {
            register u32 nextFirstValue asm("r2") = first + 1;
            register u32 nextFirst asm("r8") = nextFirstValue;
            register u32 second = nextFirst;
            if (nextFirstValue < 4) {
                register u8 *active asm("r2") = gUnknown_03001634;
                register u32 scoreOffset asm("r3") = 86;
                asm volatile("" : "+r"(scoreOffset));
                register u16 *scoreValue = (u16 *)(scoreOffset + (u32)active);
                register u16 *scoreBase asm("r12") = scoreValue;
                register u8 *firstSlotValue asm("r5") = gUnknown_03005278;
                firstSlotValue += first;
                register u8 *firstSlot asm("r9") = firstSlotValue;
                register u8 *orderLoad asm("r6") = gUnknown_03005278;
                asm volatile("" : "+r"(orderLoad));
                register u8 *orderBase = orderLoad;
                do {
                    register u8 *order asm("r1") = gUnknown_03005278;
                    register u32 candidate = *(u8 *)(second + (u32)order);
                    register u32 present = *(u8 *)(candidate + (u32)active);
                    register u32 nextSecond asm("r3") = second + 1;
                    if (present != 255) {
                        register u8 *currentOrder asm("r5") = order;
                        asm volatile("" : : "r"(currentOrder));
                        register u8 *currentAddress asm("r0") = (u8 *)(first + (u32)currentOrder);
                        u32 current = *currentAddress;
                        if (*(u8 *)(current + (u32)active) == 255 ||
                            scoreBase[current] < scoreBase[candidate]) {
                            register u32 selected asm("r1") = candidate;
                            register u32 move asm("r6") = second;
                            asm volatile("" : "+r"(second));
                            nextSecond = second + 1;
                            if (second > first) {
                                register u32 previous asm("r0") = second - 1;
                                u8 *out = (u8 *)(previous + (u32)orderBase);
                                do {
                                    out[1] = out[0];
                                    out--;
                                    move--;
                                } while (move > first);
                            }
                            register u8 *writeSlot asm("r6") = firstSlot;
                            *writeSlot = selected;
                        }
                    }
                    second = nextSecond;
                } while (second < 4);
            }
            first = nextFirst;
        } while (first < 4);
        register u8 *sceneView asm("r1") = scene;
        if (sceneView[8] != 0) {
            register u8 *teams asm("r0") = sceneView + 32;
            register u8 *teamMapping asm("r2") = gUnknown_03005278;
            register u32 player asm("r2") = *teamMapping;
            register u32 team = teams[player];
            register u8 *winnerSlot asm("r3") = &gUnknown_030052a0;
            *winnerSlot = team;
        }
        register u8 *firstMapping asm("r4") = gUnknown_03005278;
        register u32 leftOffset = firstMapping[0] * 2;
        register u16 *scores asm("r4") = (u16 *)scene;
        scores += 53;
        register u16 *left asm("r0") = (u16 *)(leftOffset + (u32)scores);
        register u8 *secondMapping asm("r5") = gUnknown_03005278;
        register u16 *right asm("r1") = (u16 *)(secondMapping[1] * 2 + (u32)scores);
        if (*left == *right) {
            register u8 *rankSlot asm("r6") = gUnknown_030052a4;
            rankSlot[1] = rankSlot[0];
        }
        register u8 *middleMapping asm("r1") = gUnknown_03005278;
        left = (u16 *)(middleMapping[1] * 2 + (u32)scores);
        right = (u16 *)(middleMapping[2] * 2 + (u32)scores);
        register u32 leftValue asm("r0") = *left;
        register u32 rightValue = *right;
        asm volatile("" : : "r"(rightValue));
        if (leftValue == rightValue) {
            register u8 *rankSlot asm("r3") = gUnknown_030052a4;
            rankSlot[2] = rankSlot[1];
        }
        register u8 *lastMapping asm("r5") = gUnknown_03005278;
        left = (u16 *)(lastMapping[3] * 2 + (u32)scores);
        if (*right == *left) {
            register u8 *rankSlot asm("r6") = gUnknown_030052a4;
            rankSlot[3] = rankSlot[2];
        }
    } else {
        register u8 *teamScene asm("r1") = scene;
        if (teamScene[8] != 0) {
            register u8 *firstTeam asm("r1") = teamScene + 55;
            register u8 *secondTeam asm("r2") = scene + 56;
            register u32 firstTeamValue asm("r0") = *firstTeam;
            register u32 secondTeamValue = *secondTeam;
            asm volatile("" : : "r"(secondTeamValue));
            if (firstTeamValue < secondTeamValue) {
                register u32 one = 1;
                register u8 *result asm("r4") = &gUnknown_030052a0;
                *result = one;
            }
            if (*firstTeam > *secondTeam) {
                register u32 zero = 0;
                register u8 *result asm("r5") = &gUnknown_030052a0;
                *result = zero;
            }
            u32 first = 0;
            do {
                register u32 nextFirstValue asm("r6") = first + 1;
                register u32 nextFirst asm("r8") = nextFirstValue;
                register u32 second asm("r4") = nextFirst;
                if (nextFirstValue < 4) {
                    register u8 *orderValue = gUnknown_03005278;
                    register u8 *orderBase asm("r12") = orderValue;
                    register u8 *active asm("r5") = gUnknown_03001634;
                    register u32 teamsOffset asm("r1") = 12;
                    register u8 *teamsValue = (u8 *)(teamsOffset + (u32)active);
                    register u8 *teams asm("r10") = teamsValue;
                    register u32 scoresOffset asm("r2") = 35;
                    asm volatile("" : "+r"(scoresOffset));
                    register u8 *scoresValue = (u8 *)(scoresOffset + (u32)active);
                    register u8 *scores = scoresValue;
                    register u8 *slotValue asm("r3") = orderBase;
                    asm volatile("" : "+r"(slotValue));
                    slotValue = (u8 *)(first + (u32)slotValue);
                    u8 *firstSlot = slotValue;
                    asm volatile("" : "+m"(firstSlot));
                    do {
                        register u8 *order asm("r6") = orderBase;
                        asm volatile("" : : "r"(order));
                        register u8 *candidateAddress asm("r0") = (u8 *)(second + (u32)order);
                        register u32 candidate asm("r2") = *candidateAddress;
                        register u32 present = *(u8 *)(candidate + (u32)active);
                        register u32 nextSecond asm("r3") = second + 1;
                        if (present != 255) {
                            register u8 *currentOrder asm("r1") = gUnknown_03005278;
                            register u8 *currentAddress asm("r0") =
                                (u8 *)(first + (u32)currentOrder);
                            u32 current = *currentAddress;
                            if (*(u8 *)(current + (u32)active) != 255) {
                                register u8 *teamBase asm("r6") = teams;
                                register u8 *address = (u8 *)(current + (u32)teamBase);
                                register u32 currentTeam = *address;
                                register u8 *currentScore = (u8 *)(currentTeam + (u32)scores);
                                address = (u8 *)(candidate + (u32)teamBase);
                                register u32 candidateTeam asm("r0") = *address;
                                register u8 *candidateScore = (u8 *)(candidateTeam + (u32)scores);
                                if (*currentScore >= *candidateScore)
                                    goto nextTeamCandidate;
                            }
                            {
                                register u32 move = second;
                                asm volatile("" : "+r"(second));
                                nextSecond = second + 1;
                                if (second > first) {
                                    register u32 previous asm("r0") = second - 1;
                                    register u8 *shiftBase = gUnknown_03005278;
                                    u8 *out = (u8 *)(previous + (u32)shiftBase);
                                    do {
                                        out[1] = out[0];
                                        out--;
                                        move--;
                                    } while (move > first);
                                }
                                register u8 *writeSlot asm("r6") = firstSlot;
                                *writeSlot = candidate;
                            }
                        }
                    nextTeamCandidate:
                        second = nextSecond;
                    } while (second < 4);
                }
                first = nextFirst;
            } while (first < 4);
        } else {
            register u32 first = 0;
            do {
                register u32 nextFirstValue = first + 1;
                register u32 nextFirst asm("r8") = nextFirstValue;
                register u32 second = nextFirst;
                if (nextFirstValue < 4) {
                    register u8 *active asm("r2") = gUnknown_03001634;
                    register u32 scoreOffset asm("r1") = 19;
                    asm volatile("" : "+r"(scoreOffset));
                    register u8 *scoreValue = (u8 *)(scoreOffset + (u32)active);
                    register u8 *scoreBase asm("r12") = scoreValue;
                    register u8 *slotValue asm("r3") = gUnknown_03005278;
                    slotValue += first;
                    register u8 *firstSlot asm("r9") = slotValue;
                    register u8 *orderLoad = gUnknown_03005278;
                    asm volatile("" : "+r"(orderLoad));
                    register u8 *orderBase asm("r10") = orderLoad;
                    do {
                        register u8 *order asm("r6") = gUnknown_03005278;
                        asm volatile("" : : "r"(order));
                        register u8 *candidateAddress asm("r0") = (u8 *)(second + (u32)order);
                        register u32 candidate = *candidateAddress;
                        register u32 present = *(u8 *)(candidate + (u32)active);
                        register u32 nextSecond asm("r3") = second + 1;
                        if (present != 255) {
                            register u8 *currentOrder asm("r1") = gUnknown_03005278;
                            register u8 *currentAddress asm("r0") =
                                (u8 *)(first + (u32)currentOrder);
                            u32 current = *currentAddress;
                            if (*(u8 *)(current + (u32)active) != 255) {
                                register u8 *scores asm("r5") = scoreBase;
                                register u8 *left = (u8 *)(current + (u32)scores);
                                register u8 *right asm("r1") = (u8 *)(candidate + (u32)scores);
                                if (*left >= *right)
                                    goto nextSoloCandidate;
                            }
                            {
                                register u32 selected asm("r1") = candidate;
                                register u32 move asm("r6") = second;
                                asm volatile("" : "+r"(second));
                                nextSecond = second + 1;
                                if (second > first) {
                                    register u32 previous asm("r0") = second - 1;
                                    u8 *out = (u8 *)(previous + (u32)orderBase);
                                    do {
                                        out[1] = out[0];
                                        out--;
                                        move--;
                                    } while (move > first);
                                }
                                register u8 *writeSlot asm("r6") = firstSlot;
                                *writeSlot = selected;
                            }
                        }
                    nextSoloCandidate:
                        second = nextSecond;
                    } while (second < 4);
                }
                first = nextFirst;
            } while (first < 4);
            register u8 *firstMapping asm("r1") = gUnknown_03005278;
            register u32 leftIndex = firstMapping[0];
            register u8 *scores asm("r4") = scene;
            scores += 39;
            register u8 *left asm("r0") = (u8 *)(leftIndex + (u32)scores);
            register u8 *right = (u8 *)(firstMapping[1] + (u32)scores);
            if (*left == *right) {
                register u8 *rankSlot asm("r2") = gUnknown_030052a4;
                rankSlot[1] = rankSlot[0];
            }
            register u8 *middleMapping asm("r3") = gUnknown_03005278;
            left = (u8 *)(middleMapping[1] + (u32)scores);
            right = (u8 *)(middleMapping[2] + (u32)scores);
            register u32 leftValue = *left;
            register u32 rightValue asm("r5") = *right;
            asm volatile("" : : "r"(rightValue));
            if (leftValue == rightValue) {
                register u8 *rankSlot asm("r6") = gUnknown_030052a4;
                rankSlot[2] = rankSlot[1];
            }
            register u8 *lastMapping asm("r2") = gUnknown_03005278;
            left = (u8 *)(lastMapping[3] + (u32)scores);
            if (*right == *left) {
                register u8 *rankSlot asm("r3") = gUnknown_030052a4;
                rankSlot[3] = rankSlot[2];
            }
        }
    }
    register u32 *decisionMode asm("r4") = &gUnknown_03005264;
    register u32 decision asm("r0") = *decisionMode;
    if (decision == 2) {
        if (scene[117] != 0) {
            gUnknown_03002030 = FUN_0802cc78;
            return;
        }
        register u8 *firstPlayer asm("r5") = gUnknown_03005278;
        if (*firstPlayer != 0) {
            gUnknown_03002030 = FUN_080336dc;
            return;
        }
    } else {
        if (decision != 1)
            goto initializeGraphics;
        if (scene[117] != 0) {
            gUnknown_03002030 = FUN_08029250;
            return;
        }
    }
    {
        register u32 *adjustMode asm("r6") = &gUnknown_03005264;
        if (*adjustMode == 1 && gUnknown_03002600[7] != 0) {
            register u8 *adjustScene = scene;
            register u32 teamMode asm("r4") = adjustScene[8];
            if (teamMode != 0) {
                register u8 *winnerAddress asm("r1") = &gUnknown_030052a0;
                if (*winnerAddress != 2) {
                    u32 i = 0;
                    register u8 *countAddress asm("r2") = &gUnknown_0300527c;
                    register u32 count asm("r2") = *countAddress;
                    if (i < count) {
                        register u8 *teamValue asm("r3") = scene + 32;
                        asm volatile("" : : "r"(teamValue));
                        register u8 *teams = teamValue;
                        asm volatile("" : "+r"(teams));
                        register u8 *firstValues asm("r5") = scene + 12;
                        register u8 *secondValue asm("r4") = scene + 16;
                        asm volatile("" : : "r"(secondValue));
                        register u8 *secondValues asm("r9") = secondValue;
                        register u32 zero = 0;
                        register u32 maximum = 255;
                        do {
                            register u8 *mapping asm("r6") = gUnknown_03005278;
                            register u8 *mappedAddress asm("r0") = (u8 *)(i + (u32)mapping);
                            register u32 player = *mappedAddress;
                            register u8 *teamBase asm("r1") = teams;
                            asm volatile("" : : "r"(teamBase));
                            register u8 *teamAddress asm("r0") = (u8 *)(player + (u32)teamBase);
                            register u32 team = *teamAddress;
                            register u8 *winner asm("r6") = &gUnknown_030052a0;
                            register u32 winnerValue asm("r6") = *winner;
                            if (team == winnerValue) {
                                {
                                    register u8 *address = (u8 *)(player + (u32)firstValues);
                                    register u32 value = *address;
                                    if (value <= 4)
                                        *address = zero;
                                    else
                                        *address = value - 5;
                                }
                                register u8 *base asm("r0") = secondValues;
                                {
                                    register u8 *address asm("r1") = (u8 *)(player + (u32)base);
                                    register u32 value = *address;
                                    if (value <= 4)
                                        *address = zero;
                                    else
                                        *address = value - 5;
                                }
                            } else {
                                {
                                    register u8 *address = (u8 *)(player + (u32)firstValues);
                                    register u32 value = *address;
                                    if (value > 250)
                                        value |= maximum;
                                    else
                                        value += 5;
                                    *address = value;
                                }
                                register u8 *base asm("r6") = secondValues;
                                asm volatile("" : : "r"(base));
                                {
                                    register u8 *address asm("r1") = (u8 *)(player + (u32)base);
                                    register u32 value = *address;
                                    if (value > 250)
                                        value |= maximum;
                                    else
                                        value += 5;
                                    *address = value;
                                }
                            }
                            i++;
                            register u8 *limitAddress = &gUnknown_0300527c;
                            asm volatile("" : "+r"(limitAddress));
                            register u32 limit = *limitAddress;
                            if (i >= limit)
                                break;
                        } while (true);
                    }
                }
            } else {
                register u8 *mapping asm("r1") = gUnknown_03005278;
                register u32 player = mapping[0];
                register u8 *base = scene + 12;
                register u8 *address = (u8 *)(player + (u32)base);
                register u32 value = *address;
                if (value <= 4)
                    *address = teamMode;
                else
                    *address = value - 5;
                base = scene + 16;
                address = (u8 *)(player + (u32)base);
                value = *address;
                if (value <= 4)
                    value = 0;
                else
                    value -= 5;
                *address = value;
                u32 i = 1;
                register u8 *countAddress asm("r2") = &gUnknown_0300527c;
                register u32 count asm("r2") = *countAddress;
                if (i < count) {
                    register u8 *firstValues asm("r5") = gUnknown_0300162c;
                    register u32 maximum asm("r4") = 255;
                    register u8 *secondValues asm("r3") = firstValues + 4;
                    do {
                        asm volatile("" : : : "r8", "r9", "r10", "r12");
                        register u8 *mapping asm("r6") = gUnknown_03005278;
                        asm volatile("" : : "r"(mapping));
                        register u8 *mappedAddress asm("r0") = (u8 *)(i + (u32)mapping);
                        register u32 player = *mappedAddress;
                        register u8 *address = (u8 *)(player + (u32)firstValues);
                        register u32 value = *address;
                        if (value > 250)
                            value |= maximum;
                        else
                            value += 5;
                        *address = value;
                        address = (u8 *)(player + (u32)secondValues);
                        value = *address;
                        if (value > 250)
                            value |= maximum;
                        else
                            value += 5;
                        *address = value;
                        i++;
                        register u8 *limitAddress = &gUnknown_0300527c;
                        asm volatile("" : "+r"(limitAddress));
                        register u32 limit = *limitAddress;
                        if (i >= limit)
                            break;
                    } while (true);
                }
            }
        }
    }
initializeGraphics:
    FUN_0801fbfc(gUnknown_0811c244, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();
    fills[0] = 0;
    CpuFastSet(&fills[0], (void *)0x05000000, 0x01000100);
    fills[1] = 0;
    CpuFastSet(&fills[1], (void *)0x06000000, 0x01000008);
    if (gUnknown_03005264 == 0 || gUnknown_03005264 == 2)
        LZ77UnCompVram(gUnknown_081323d4, (void *)0x06000020);
    else
        LZ77UnCompVram(gUnknown_08132544, (void *)0x06000020);
    LZ77UnCompVram(gUnknown_0811c3a4, (void *)0x06010000);
    switch (gUnknown_03002110[119]) {
    case 0:
        LZ77UnCompVram(gUnknown_0811d818, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbbe8;
        break;
    case 2:
        LZ77UnCompVram(gUnknown_0811d9bc, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbbfc;
        break;
    case 3:
        LZ77UnCompVram(gUnknown_0811d9bc, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbc04;
        break;
    case 4:
        LZ77UnCompVram(gUnknown_0811d9bc, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbc0c;
        break;
    case 5:
        LZ77UnCompVram(gUnknown_0811d9bc, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbc14;
        break;
    default:
        LZ77UnCompVram(gUnknown_0811d9bc, (void *)0x06015020);
        gUnknown_03005280 = gUnknown_08edbbf4;
        break;
    }
    if (gUnknown_03005264 == 2) {
        memcpy(gUnknown_03005200 + 0, gUnknown_08edd518[gUnknown_03001620[20]], 16);
        memcpy(gUnknown_03005200 + 16, gUnknown_08edd518[gUnknown_03001620[21]], 16);
        memcpy(gUnknown_03005200 + 32, gUnknown_08edd518[gUnknown_03001620[22]], 16);
        memcpy(gUnknown_03005200 + 48, gUnknown_08edd518[gUnknown_03001620[23]], 16);
    }
    FUN_0802b6e8(0, gUnknown_03005278[0] + 1);
    FUN_0802b6e8(1, gUnknown_03005278[1] + 1);
    FUN_0802b6e8(2, gUnknown_03005278[2] + 1);
    FUN_0802b6e8(3, gUnknown_03005278[3] + 1);
    FUN_0802b81c(0, 0);
    FUN_0802b81c(1, 0);
    FUN_0802b81c(2, 0);
    FUN_0802b81c(3, 0);
    CpuSet(gUnknown_03001d0c + gUnknown_03005278[0] * 252, (void *)0x5000300, 16);
    CpuSet(gUnknown_03001d0c + gUnknown_03005278[1] * 252, (void *)0x5000320, 16);
    CpuSet(gUnknown_03001d0c + gUnknown_03005278[2] * 252, (void *)0x5000340, 16);
    CpuSet(gUnknown_03001d0c + gUnknown_03005278[3] * 252, (void *)0x5000360, 16);
    fills[2] = 0;
    CpuFastSet(&fills[2], (void *)0x0600f800, 0x01000200);
    fills[3] = 0;
    CpuFastSet(&fills[3], (void *)0x0600e800, 0x01000200);
    fills[4] = 0;
    CpuFastSet(&fills[4], (void *)0x0600e000, 0x01000200);
    register u16 *destination = (u16 *)0x0600d000;
    register u32 row asm("r7") = 0;
    u16 one = 1;
    do {
        u32 col = 0;
        row++;
        register u32 nextRow asm("r8") = row;
        do {
            FUN_08021000(destination, gUnknown_081327d4, 8, 8, one);
            destination += 8;
            col++;
        } while (col < 4);
        register u32 rowStride asm("r1") = 448;
        destination = (u16 *)((u32)destination + rowStride);
        row = nextRow;
    } while (row < 4);
    if (gUnknown_03005264 == 0 || gUnknown_03005264 == 2)
        FUN_0801f7d0(FUN_08030d3c, 4, gUnknown_03003e20, 0);
    else
        FUN_0801f7d0(FUN_08030d20, 4, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0802c37c, 12, gUnknown_03003e20, 0);
    FUN_080158e4();
    FUN_0801fba0(0, 0x1840);
    gUnknown_03002030 = FUN_0802c1d4;
    gUnknown_03001b10[1] = 0;
    gUnknown_03001b10[2] = 0;
    gUnknown_03001b10[3] = 0;
    FUN_08018444();
    gUnknown_03005270[3] = 256;
    gUnknown_03005270[2] = 256;
    gUnknown_03005270[1] = 256;
    gUnknown_03005270[0] = 256;
    FUN_0801f618(3);
    if (gUnknown_03005254 != 0)
        FUN_0801f9e8(0x9876);
    gUnknown_03005258 = 0;
}
}

#include "types.h"
extern "C" {
extern u32 gUnknown_03005254, gUnknown_03005258, gUnknown_03005264;
extern u8 gUnknown_0300525c;
extern void (*gUnknown_03002030)(void);
u32 FUN_0802067c(u16 *, u16);
u32 FUN_0801fab0(u16);
void FUN_0803d1a0(void), FUN_0803c378(void), FUN_08029250(void);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void);
void FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void);
void FUN_0801f89c(void), FUN_0801fda0(void);
void FUN_0802c1d4(void) {
    if (gUnknown_03005254 != 0) {
        u32 *counter = &gUnknown_03005258;
        if (*counter > 59) {
            if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
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
        if (gUnknown_0300525c == (u8)FUN_0801fab0(0x9876))
            *counter = 0;
        else
            ++*counter;
    }
    FUN_0801f89c();
    FUN_0801fda0();
}
void FUN_0802c25c(void) {
    if (gUnknown_03005264 == 2)
        gUnknown_03002030 = FUN_0803c378;
    else
        gUnknown_03002030 = FUN_08029250;
}
}

extern "C" {
extern u8 gUnknown_0300525c, gUnknown_03005260, gUnknown_0300527c, gUnknown_03005278[];
extern s16 gUnknown_030016f0[][8];
extern Node gUnknown_03003e20[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0801f8c0(Node *), FUN_0802c800(Node *);
void FUN_0802c28c(Node *node) {
    u8 *state = (u8 *)node->allocation;
    for (u32 peer = 0; peer < gUnknown_0300525c; peer++) {
        if (peer == gUnknown_03005260)
            continue;
        if (gUnknown_030016f0[peer][1] == 0x6789) {
            for (u32 player = 0; player < gUnknown_0300527c; player++) {
                if (gUnknown_03005278[player] == peer) {
                    register u8 *base asm("r0") = state + 4;
                    u8 *slot = base + peer;
                    if (*slot == 0) {
                        Node *child = FUN_0801f7d0(FUN_0802c800, 16, gUnknown_03003e20, 0);
                        child->position->player = player;
                        *slot = child->index;
                    }
                }
            }
        } else {
            for (u32 player = 0; player < gUnknown_0300527c; player++) {
                if (gUnknown_03005278[player] == peer) {
                    register u8 *base asm("r0") = state + 4;
                    u8 *slot = base + peer;
                    if (*slot != 0) {
                        FUN_0801f8c0(&gUnknown_03003e20[*slot]);
                        *slot = 0;
                    }
                }
            }
        }
    }
}
}

extern "C" {
extern u8 gUnknown_0300527c, gUnknown_03005278[], gUnknown_03001620[];
extern Node gUnknown_03003e20[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802c88c(Node *), FUN_0802c944(Node *), FUN_0802c9dc(Node *), FUN_0802cb64(Node *),
    FUN_0802c56c(Node *);
void FUN_0802c37c(Node *node) {
    u32 *state = (u32 *)node->allocation;
    Node *child;
    switch (gUnknown_0300527c) {
    case 4:
        child = FUN_0801f7d0(FUN_0802c88c, 16, gUnknown_03003e20, 0);
        child->position->player = 3;
        child = FUN_0801f7d0(FUN_0802c944, 16, gUnknown_03003e20, 0);
        child->position->player = 3;
        child = FUN_0801f7d0(FUN_0802c9dc, 16, gUnknown_03003e20, 0);
        child->position->player = 3;
    case 3:
        child = FUN_0801f7d0(FUN_0802c88c, 16, gUnknown_03003e20, 0);
        child->position->player = 2;
        child = FUN_0801f7d0(FUN_0802c944, 16, gUnknown_03003e20, 0);
        child->position->player = 2;
        child = FUN_0801f7d0(FUN_0802c9dc, 16, gUnknown_03003e20, 0);
        child->position->player = 2;
    case 2:
        child = FUN_0801f7d0(FUN_0802c88c, 16, gUnknown_03003e20, 0);
        child->position->player = 1;
        child = FUN_0801f7d0(FUN_0802c944, 16, gUnknown_03003e20, 0);
        child->position->player = 1;
        child = FUN_0801f7d0(FUN_0802c9dc, 16, gUnknown_03003e20, 0);
        child->position->player = 1;
    case 1:
        child = FUN_0801f7d0(FUN_0802c88c, 16, gUnknown_03003e20, 0);
        child->position->player = 0;
        child = FUN_0801f7d0(FUN_0802c944, 16, gUnknown_03003e20, 0);
        child->position->player = 0;
        child = FUN_0801f7d0(FUN_0802c9dc, 16, gUnknown_03003e20, 0);
        child->position->player = 0;
    }
    switch (gUnknown_0300527c) {
    case 4: {
        child = FUN_0801f7d0(FUN_0802cb64, 16, gUnknown_03003e20, 0);
        child->position->player = 3;
        Position *position = child->position;
        u8 *scene = gUnknown_03001620;
        u8 *players = gUnknown_03005278;
        scene += 20;
        position->state = scene[players[3]];
    }
    case 3: {
        child = FUN_0801f7d0(FUN_0802cb64, 16, gUnknown_03003e20, 0);
        child->position->player = 2;
        Position *position = child->position;
        u8 *scene = gUnknown_03001620;
        u8 *players = gUnknown_03005278;
        scene += 20;
        position->state = scene[players[2]];
    }
    case 2: {
        child = FUN_0801f7d0(FUN_0802cb64, 16, gUnknown_03003e20, 0);
        child->position->player = 1;
        Position *position = child->position;
        u8 *scene = gUnknown_03001620;
        u8 *players = gUnknown_03005278;
        scene += 20;
        position->state = scene[players[1]];
    }
    case 1: {
        child = FUN_0801f7d0(FUN_0802cb64, 16, gUnknown_03003e20, 0);
        child->position->player = 0;
        Position *position = child->position;
        u8 *scene = gUnknown_03001620;
        u8 *players = gUnknown_03005278;
        scene += 20;
        position->state = scene[players[0]];
    }
    }
    *state = 0;
    node->callback = FUN_0802c56c;
}
}

extern "C" {
extern u32 gUnknown_03005264;
extern u16 gUnknown_03005270[];
extern const u16 gUnknown_081326f4[], gUnknown_08132734[], gUnknown_08132714[], gUnknown_0811c2a4[];
u32 FUN_08020500(u16 *, const u16 *, u16);
void FUN_0802c654(Node *), FUN_0802c28c(Node *);
void FUN_0802c56c(Node *node) {
    u32 *state = (u32 *)node->allocation;
    register u32 firstPending;
    if (gUnknown_03005264 == 0)
        firstPending = (u8)FUN_08020500((u16 *)0x05000000, gUnknown_081326f4, 16) == 0;
    else if (gUnknown_03005264 == 2)
        firstPending = (u8)FUN_08020500((u16 *)0x05000000, gUnknown_08132734, 16) == 0;
    else
        firstPending = (u8)FUN_08020500((u16 *)0x05000000, gUnknown_08132714, 16) == 0;
    u32 pending = firstPending;
    asm volatile("" : "+r"(pending));
    register u32 secondPending;
    if ((u8)FUN_08020500((u16 *)0x05000200, gUnknown_0811c2a4, 128) == 0)
        secondPending = (pending | 1) << 24;
    else
        secondPending = pending << 24;
    secondPending >>= 24;
    asm volatile("" : : "r"(secondPending));
    pending = secondPending;
    if (*state > 35)
        gUnknown_03005270[0] = (gUnknown_03005270[0] * 3) >> 2;
    if (*state > 30)
        gUnknown_03005270[1] = (gUnknown_03005270[1] * 3) >> 2;
    if (*state > 25)
        gUnknown_03005270[2] = (gUnknown_03005270[2] * 3) >> 2;
    if (*state > 20)
        gUnknown_03005270[3] = (gUnknown_03005270[3] * 3) >> 2;
    if (gUnknown_03005270[0] != 0)
        pending = (u8)(pending | 1);
    ++*state;
    if (pending == 0) {
        *state = 0;
        node->callback = FUN_0802c654;
    }
    FUN_0802c28c(node);
}
}

extern "C" {
struct ControlState {
    u32 selection;
    u8 children[4], unused8, marker;
};
extern u16 gUnknown_030048e0[];
extern u32 gUnknown_03005254;
extern u8 gUnknown_0300527c, gUnknown_03005278[], gUnknown_03005260;
extern Node gUnknown_03003e20[];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802c734(Node *), FUN_0802c800(Node *), FUN_0802cb30(Node *), FUN_0802c28c(Node *);
void FUN_0801f618(u16), FUN_0802b81c(u32, u32);
void FUN_0802c654(Node *incoming) {
    register Node *node = incoming;
    ControlState *state = (ControlState *)node->allocation;
    register u32 keys = gUnknown_030048e0[2];
    register u32 one asm("r2") = 1;
    register u32 test asm("r0") = one;
    test &= keys;
    if (test != 0) {
        register void (*callback)(Node *) = FUN_0802c734;
        node->callback = callback;
        FUN_0801f618(402);
        Node *child = FUN_0801f7d0(FUN_0802c800, 16, gUnknown_03003e20, 0);
        u32 player = 0;
        for (; player < gUnknown_0300527c; player++) {
            if (gUnknown_03005278[player] == gUnknown_03005260) {
                child->position->player = player;
                state->children[gUnknown_03005260] = child->index;
                break;
            }
        }
        if (gUnknown_03005254 != 0) {
            child = FUN_0801f7d0(FUN_0802cb30, 16, gUnknown_03003e20, 0);
            state->marker = child->index;
        }
    } else {
        test = 48;
        test &= keys;
        if (test != 0) {
            state->selection ^= one;
            FUN_0802b81c(0, state->selection);
            FUN_0802b81c(1, state->selection);
            FUN_0802b81c(2, state->selection);
            FUN_0802b81c(3, state->selection);
        }
    }
    FUN_0802c28c(node);
}
}

extern "C" {
extern u32 gUnknown_03005254;
extern u8 gUnknown_0300525c;
extern u16 gUnknown_03001b10[];
extern s16 gUnknown_030016f0[][8];
extern Node gUnknown_03003e20[];
extern void (*gUnknown_03002030)(void);
void FUN_0801f8c0(Node *), FUN_0802c28c(Node *), FUN_0802c7d8(Node *);
void FUN_0801f618(u16), FUN_0801f718(u16, u16), FUN_0802c25c(void);
u32 FUN_0802067c(u16 *, u16);
void FUN_0802c734(Node *node) {
    u8 *state = (u8 *)node->allocation;
    if (gUnknown_03005254 != 0) {
        gUnknown_03001b10[1] = 0x6789;
        u32 matched = 0;
        u32 peer = 0;
        for (; peer <= 3; peer++) {
            if (gUnknown_030016f0[peer][1] == 0x6789)
                matched++;
        }
        if (matched == gUnknown_0300525c) {
            if (state[9] != 0) {
                FUN_0801f8c0(&gUnknown_03003e20[state[9]]);
                state[9] = 0;
            }
            node->callback = FUN_0802c7d8;
            FUN_0801f618(404);
            FUN_0801f718(3, 120);
        }
    } else {
        node->callback = FUN_0802c7d8;
        FUN_0801f618(404);
        FUN_0801f718(3, 120);
    }
    FUN_0802c28c(node);
}
void FUN_0802c7d8(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_0802c25c;
}
}

extern "C" {
extern const u8 gUnknown_0811dbb0[], gUnknown_0811dc58[];
extern const u16 gUnknown_08edbc1c[][2], gUnknown_08edbc2c[][2];
extern u16 gUnknown_03005270[];
extern u8 gUnknown_03001620[], gUnknown_03005278[];
void FUN_0801fed8(u8, u32);
void FUN_0802c85c(Node *), FUN_0802c914(Node *);
void FUN_0802c800(Node *node) {
    node->position->parts = gUnknown_0811dbb0;
    node->position->tile = 0;
    node->position->x =
        gUnknown_08edbc1c[node->position->player][0] + gUnknown_03005270[node->position->player];
    node->position->y = gUnknown_08edbc1c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0802c85c;
}
void FUN_0802c85c(Node *node) {
    node->position->x =
        gUnknown_08edbc1c[node->position->player][0] + gUnknown_03005270[node->position->player];
    FUN_0801fed8(node->index, 0);
}
void FUN_0802c88c(Node *node) {
    {
        Position *position = node->position;
        position->parts = gUnknown_0811dc58;
        u8 *scene = gUnknown_03001620;
        register u32 tile asm("r0") = scene[8];
        if (tile != 0) {
            u8 *settings = scene + 32;
            if (settings[gUnknown_03005278[position->player]] != 0)
                tile = 0;
            else
                tile = 192;
        }
        position->tile = tile;
    }
    register Position *current = node->position;
    register const u16 *coordinates = &gUnknown_08edbc2c[0][0];
    register u32 value asm("r0") = current->player;
    register const u16 *coordinate = (const u16 *)(value * 4 + (u32)coordinates);
    register u16 *offset = gUnknown_03005270;
    value = value * 2 + (u32)offset;
    value = *(u16 *)value;
    value += *coordinate;
    register u32 zero asm("r1") = 0;
    current->x = value;
    register Position *row = node->position;
    value = row->player * 4;
    coordinates++;
    row->y = *(const u16 *)(value + (u32)coordinates);
    node->position->attr0 = zero;
    node->position->attr1 = zero;
    node->position->attr2 = zero;
    node->callback = FUN_0802c914;
}
void FUN_0802c914(Node *node) {
    node->position->x =
        gUnknown_08edbc2c[node->position->player][0] + gUnknown_03005270[node->position->player];
    FUN_0801fed8(node->index, 0);
}
}

extern "C" {
extern const u8 gUnknown_0811dc08[];
extern const u16 gUnknown_08edbc3c[][2];
extern u16 gUnknown_03005270[];
void FUN_0801fed8(u8, u32);
void FUN_0802c9ac(Node *);
void FUN_0802c944(Node *node) {
    node->position->parts = gUnknown_0811dc08;
    node->position->tile = node->position->player * 40 + 864;
    node->position->x =
        gUnknown_08edbc3c[node->position->player][0] + gUnknown_03005270[node->position->player];
    node->position->y = gUnknown_08edbc3c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0802c9ac;
}
void FUN_0802c9ac(Node *node) {
    node->position->x =
        gUnknown_08edbc3c[node->position->player][0] + gUnknown_03005270[node->position->player];
    FUN_0801fed8(node->index, 0);
}
}

extern "C" {
extern const u8 gUnknown_0811dbd8[], gUnknown_0811dbe0[];
extern const void *const gUnknown_08edbc5c[];
extern const u16 gUnknown_08edbc4c[][2];
extern u16 gUnknown_03005270[];
extern u8 gUnknown_03001620[], gUnknown_03005278[], gUnknown_030052a0, gUnknown_030052a4[];
void FUN_0801fed8(u8, u32);
void FUN_0802caac(Node *);
void FUN_0802c9dc(Node *node) {
    u8 *scene = gUnknown_03001620;
    if (scene[8] != 0) {
        Position *position = node->position;
        position->parts = gUnknown_0811dbd8;
        u32 selected = gUnknown_030052a0;
        if (selected == 2) {
            position->parts = gUnknown_0811dbe0;
            position->tile = 576;
        } else {
            u8 *settings = scene + 32;
            if (settings[gUnknown_03005278[position->player]] == selected)
                position->tile = 512;
            else
                position->tile = 544;
        }
    } else {
        u8 *selections = gUnknown_030052a4;
        Position *position = node->position;
        u32 selected = selections[position->player];
        position->parts = gUnknown_08edbc5c[selected];
        position->tile = selected * 32 + 384;
    }
    node->position->x =
        gUnknown_08edbc4c[node->position->player][0] + gUnknown_03005270[node->position->player];
    node->position->y = gUnknown_08edbc4c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0802caac;
}
void FUN_0802caac(Node *node) {
    node->position->x =
        gUnknown_08edbc4c[node->position->player][0] + gUnknown_03005270[node->position->player];
    FUN_0801fed8(node->index, 0);
}
}

extern "C" {
extern const s16 gUnknown_0804df7c[];
extern const u8 gUnknown_0811dba8[];
u32 FUN_0801fd18(s16, u32);
void FUN_0801fed8(u8, u32);
void FUN_0802cadc(Node *node) {
    const s16 *table = gUnknown_0804df7c;
    s32 scale = table[node->position->state * 32] >> 8;
    node->position->attr0 = 1;
    node->position->attr1 &= 193;
    node->position->attr1 |= FUN_0801fd18(scale + 256, 0) << 1;
    FUN_0801fed8(node->index, 0);
    node->position->state += 4;
}
void FUN_0802cb30(Node *node) {
    node->position->parts = gUnknown_0811dba8;
    node->position->tile = 0;
    node->position->x = 214;
    node->position->y = 145;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0802cadc;
}
}

extern "C" {
extern const u8 gUnknown_0811dbe8[];
extern const u16 gUnknown_08edbc6c[][2];
extern u16 gUnknown_03005270[];
extern u8 gUnknown_03005278[];
void FUN_0801fed8(u8, u32);
void FUN_08015924(u8, u16, u8, u16, u8);
s16 FUN_08015f40(u8), FUN_08015f58(u8);
void FUN_0802cbd0(Node *);
void FUN_0802cb64(Node *node) {
    node->position->parts = gUnknown_0811dbe8;
    node->position->tile = node->position->player * 36 + 720;
    node->position->x =
        gUnknown_08edbc6c[node->position->player][0] + gUnknown_03005270[node->position->player];
    node->position->y = gUnknown_08edbc6c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = node->position->player * 16 - 128;
    node->callback = FUN_0802cbd0;
}
void FUN_0802cbd0(Node *node) {
    if ((++node->position->unused & 1) != 0)
        FUN_08015924(node->position->state, 0, 2, node->position->player * 36 + 720,
                     gUnknown_03005278[node->position->player]);
    node->position->x = FUN_08015f40(node->position->player) +
                        gUnknown_08edbc6c[node->position->player][0] +
                        gUnknown_03005270[node->position->player];
    node->position->y =
        FUN_08015f58(node->position->player) + gUnknown_08edbc6c[node->position->player][1];
    node->position->x =
        gUnknown_08edbc6c[node->position->player][0] + gUnknown_03005270[node->position->player];
    FUN_0801fed8(node->index, 0);
}
}

extern "C" {
u16 gUnknown_03005270[4];
u8 gUnknown_03005278[4] __attribute__((section(".bss.mapping"))) = {0};
u8 gUnknown_0300527c __attribute__((section(".bss.count"))) = 0;
const u16 *const *gUnknown_03005280 __attribute__((section(".bss.text"))) = 0;
u16 gUnknown_03005290[4] __attribute__((section(".bss.digits"))) = {0};
u8 gUnknown_030052a0 __attribute__((section(".bss.winner"))) = 0;
u8 gUnknown_030052a4[4] __attribute__((section(".bss.ranks"))) = {0};
extern const u16 gUnknown_0811dc70[], gUnknown_0811dc7c[], gUnknown_0811dc88[];
extern const u16 gUnknown_0811dca0[], gUnknown_0811dcb0[], gUnknown_0811dcc0[], gUnknown_0811dcd0[];
extern const u16 gUnknown_0811dce0[], gUnknown_0811dcf8[], gUnknown_0811dd04[], gUnknown_0811dd18[];
extern const u16 gUnknown_0811dd24[], gUnknown_0811dd34[];
extern const u8 gUnknown_0811dbc0[], gUnknown_0811dbc8[], gUnknown_0811dbd0[];
const u16 *const gUnknown_08edbbe8[3] = {gUnknown_0811dc70, gUnknown_0811dc7c, gUnknown_0811dc88};
const u16 *const gUnknown_08edbbf4[2] = {gUnknown_0811dca0, gUnknown_0811dcb0};
const u16 *const gUnknown_08edbbfc[2] = {gUnknown_0811dcc0, gUnknown_0811dcd0};
const u16 *const gUnknown_08edbc04[2] = {gUnknown_0811dce0, gUnknown_0811dcf8};
const u16 *const gUnknown_08edbc0c[2] = {gUnknown_0811dd04, gUnknown_0811dd18};
const u16 *const gUnknown_08edbc14[2] = {gUnknown_0811dd24, gUnknown_0811dd34};
const u16 gUnknown_08edbc1c[4][2] = {{162, 4}, {142, 44}, {122, 84}, {102, 124}};
const u16 gUnknown_08edbc2c[4][2] = {{68, 0}, {48, 40}, {28, 80}, {8, 120}};
const u16 gUnknown_08edbc3c[4][2] = {{112, 4}, {92, 44}, {72, 84}, {52, 124}};
const u16 gUnknown_08edbc4c[4][2] = {{180, 2}, {160, 42}, {140, 82}, {120, 122}};
const void *const gUnknown_08edbc5c[4] = {gUnknown_0811dbc0, gUnknown_0811dbc8, gUnknown_0811dbd0,
                                          gUnknown_0811dbc0};
const u16 gUnknown_08edbc6c[4][2] = {{64, (u16)-4}, {44, 36}, {24, 76}, {4, 116}};
}
