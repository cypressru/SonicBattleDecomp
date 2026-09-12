// C++ reconstruction fallback; evidence and ownership: docs/selection-tu-cpp.md.
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
struct UnknownLookupRecord29250 {
    u8 unused0[4], value, unused5[3];
};
extern u8 gUnknown_03001620[], gUnknown_03002110[], gUnknown_030013b0[], gUnknown_0300524c[],
    gUnknown_03005268[];
extern u8 gUnknown_03005260, gUnknown_0300525c, gUnknown_03005200[][16], gUnknown_03002170[];
extern u32 gUnknown_03005254, gUnknown_03005258;
extern u8 gUnknown_03005250;
extern u16 gUnknown_03001b10[];
extern Node gUnknown_03003e20[];
extern const Position gUnknown_08edbabc[];
extern const void *const gUnknown_08edbadc[];
extern const u8 gUnknown_0810b32c[], gUnknown_08edbaac[], gUnknown_0810dbcc[], gUnknown_08132544[];
extern const u8 gUnknown_08116444[], gUnknown_0810df04[], gUnknown_08116568[], gUnknown_08117368[],
    gUnknown_08117b68[], gUnknown_08118368[];
extern const u16 gUnknown_0810db14[], gUnknown_081327d4[];
extern void (*gUnknown_03002030)(void);
u32 FUN_08020144(void);
void FUN_0801fbfc(const u16 *, u8);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void),
    FUN_080210d8(void), FUN_0802110c(void);
void CpuFastSet(const void *, void *, u32), LZ77UnCompVram(const void *, void *);
void *memcpy(void *, const void *, unsigned long);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
void FUN_0802036c(u32, u32, u32), FUN_08020408(u32, u32), FUN_080290e8(u32, u32, u32);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_08030d20(Node *), FUN_0802a0ec(Node *), FUN_0802b2d4(Node *), FUN_0802b3c8(Node *),
    FUN_0801f9d8(Node *), FUN_0802b638(Node *);
void FUN_0801fba0(u16, u16), FUN_0801f618(u16), FUN_08029ba0(void);
void FUN_08029250(void) {
    u32 fills[3];
    u32 *volatile fillAddresses[2];
    s32 entryOffset;
    u32 i;
    u32 j;
    Node *node;

    {
        register u8 *scene asm("r4") = gUnknown_03001620;
        register u32 zero asm("r0") = 0;
        register u32 one asm("r2");
        register u8 *state asm("r1");
        register u32 stateOffset asm("r3");

        scene[1] = zero;
        one = 1;
        scene[2] = one;
        state = (u8 *)&gUnknown_03002110;
        stateOffset = 0x473;
        asm volatile("" : "+r"(stateOffset));
        {
            register u8 *checkAddress asm("r0") = state + stateOffset;

            asm volatile("" : "+r"(checkAddress));
            if (*checkAddress != 0) {
                register u32 selectorOffset asm("r5") = 0x472;
                register u32 selector asm("r0");
                register u8 *selectorAddress asm("r0");

                asm volatile("" : "+r"(selectorOffset));
                selectorAddress = state + selectorOffset;
                asm volatile("" : "+r"(selectorAddress));
                {
                    register u32 tableOffset asm("r6") = 0x474;

                    asm volatile("" : "+r"(tableOffset));
                    state += tableOffset;
                }
                selector = *selectorAddress;
                state += selector;
                scene[3] = *state - 1;
            } else {
                register u8 *address asm("r0") = state;
                register u32 flags asm("r1");
                register u32 test asm("r0");

                address += 0x79;
                flags = *address;
                test = one;
                test &= flags;
                if (test != 0) {
                    scene[3] = ((FUN_08020144() & 0xFFF) * 11) >> 12;
                } else {
                    scene[3] = ((FUN_08020144() & 0xFFF) * 5) >> 11;
                }
            }
        }
    }

    FUN_0801fbfc(gUnknown_0810db14, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();

    fills[0] = 0;
    CpuFastSet(&fills[0], (void *)0x05000000, 0x01000100);

    {
        u32 mode;
        register u8 *config asm("r12");

        {
            register u32 *modeAddress asm("r6") = &gUnknown_03005254;

            mode = *modeAddress;
        }

        if (mode != 0) {
            u32 recordIndex = gUnknown_03005260;
            u8 *record = gUnknown_030013b0;
            u8 *recordAddress;
            register u8 *destinationBase asm("r7");
            register u8 *state asm("r3");
            register u8 *selectedEntries asm("r9");
            u8 metadata;
            u8 group;

            {
                register u32 recordOffset asm("r4");

                recordOffset = recordIndex * 156;
                recordAddress = &record[recordOffset];
                state = (u8 *)&gUnknown_03002110;
                metadata = state[800];
                recordAddress[150] = metadata;
                group = 0;
                entryOffset = 802;
                selectedEntries = &state[entryOffset];
                {
                    register u8 *selectedConfig asm("r0") = gUnknown_0300524c;

                    asm volatile("" : "+r"(selectedConfig));
                    config = selectedConfig;
                }
                {
                    register u32 *firstFill asm("r1");

                    u32 base = (u32)fills - sizeof(u32);
                    asm volatile("" : "+r"(base));
                    firstFill = (u32 *)(base + 2 * sizeof(u32));
                    fillAddresses[0] = firstFill;
                }
                {
                    register u32 *secondFill asm("r3");

                    u32 base = (u32)fills - sizeof(u32);
                    asm volatile("" : "+r"(base));
                    secondFill = (u32 *)(base + 3 * sizeof(u32));
                    fillAddresses[1] = secondFill;
                }
                record += 69;
                destinationBase = &record[recordOffset];
            }
            {
                register const struct UnknownLookupRecord29250 *lookupTable asm("r4") =
                    (const struct UnknownLookupRecord29250 *)gUnknown_0810b32c;

                for (; group <= 2; group++) {
                    u8 column;
                    register u32 scaledGroup asm("r1") = group;
                    register u32 destinationOffset asm("r0");
                    register u8 *destination asm("r3");
                    register const u16 *entries asm("r6");
                    register u8 *entryBase asm("r0");

                    scaledGroup <<= 3;
                    scaledGroup -= group;
                    destinationOffset = scaledGroup << 2;
                    destinationOffset -= group;
                    destination = &destinationBase[destinationOffset];
                    scaledGroup <<= 3;
                    entryBase = selectedEntries;
                    entries = (const u16 *)(scaledGroup + (u32)entryBase);

                    for (column = 0; column <= 26; column++) {
                        u16 value;

                        destination[column] = lookupTable[entries[column]].value;
                    }
                }
            }
        } else {
            register u8 *record asm("r3") = gUnknown_030013b0;
            register u8 *initialState asm("r2") = (u8 *)&gUnknown_03002110;
            register u8 *state asm("r8");
            register u8 *entryBytes asm("r9");

            {
                u8 initialMetadata;

                {
                    register u32 metadataOffset asm("r1") = 200;
                    register u8 *metadataAddress asm("r0");

                    asm volatile("" : "+r"(metadataOffset));
                    metadataOffset <<= 2;
                    asm volatile("" : "+r"(metadataOffset));
                    metadataAddress = initialState + metadataOffset;
                    asm volatile("" : "+r"(metadataAddress));
                    initialMetadata = *metadataAddress;
                }
                {
                    register u8 *recordAddress asm("r1");
                    register u32 metadataValue asm("r0") = initialMetadata;

                    asm volatile("" : "+r"(metadataValue));
                    recordAddress = record;
                    asm volatile("" : "+r"(recordAddress));
                    recordAddress += 150;
                    *recordAddress = metadataValue;
                }
            }
            {
                register u32 firstGroup asm("r4") = 0;

                state = initialState;
                asm volatile("" : "+r"(state));
                {
                    register u32 unselectedEntryOffset asm("r2") = 802;

                    asm volatile("" : "+r"(unselectedEntryOffset));
                    entryBytes = &state[unselectedEntryOffset];
                    asm volatile("" : "+r"(entryBytes));
                }
                {
                    register u8 *unselectedConfig asm("r5") = gUnknown_0300524c;

                    asm volatile("" : "+r"(unselectedConfig));
                    config = unselectedConfig;
                }
                {
                    register u32 *firstFill asm("r6");

                    u32 base = (u32)fills - sizeof(u32);
                    asm volatile("" : "+r"(base));
                    firstFill = (u32 *)(base + 2 * sizeof(u32));
                    fillAddresses[0] = firstFill;
                }
                {
                    register u32 *secondFill asm("r0");

                    u32 base = (u32)fills - sizeof(u32);
                    asm volatile("" : "+r"(base));
                    secondFill = (u32 *)(base + 3 * sizeof(u32));
                    fillAddresses[1] = secondFill;
                }

                do {
                    register u8 *firstDestinationBase asm("r10");
                    register u32 firstBaseAddress asm("r1") = 69;

                    asm volatile("" : "+r"(firstBaseAddress));
                    firstBaseAddress += (u32)record;
                    asm volatile("" : "+r"(firstBaseAddress));
                    firstDestinationBase = (u8 *)firstBaseAddress;
                    {
                        register const struct UnknownLookupRecord29250 *firstLookupTable asm("r7") =
                            (const struct UnknownLookupRecord29250 *)gUnknown_0810b32c;

                        do {
                            u8 column;
                            register u32 scaledGroup asm("r1") = firstGroup;
                            register u32 scratch asm("r0");
                            register u8 *destination asm("r6");
                            register u8 *destinationAddress asm("r2");
                            register const u16 *entries asm("r5");

                            scaledGroup <<= 3;
                            scaledGroup -= firstGroup;
                            scratch = scaledGroup << 2;
                            scratch -= firstGroup;
                            destinationAddress = firstDestinationBase;
                            asm volatile("" : "+r"(destinationAddress));
                            destination = (u8 *)(scratch + (u32)destinationAddress);
                            scaledGroup <<= 3;
                            scratch = (u32)entryBytes;
                            asm volatile("" : "+r"(scratch));
                            entries = (const u16 *)(scaledGroup + scratch);
                            column = 0;
                            firstGroup += 1;

                            for (; column <= 26; column++) {
                                u16 value;

                                destination[column] = firstLookupTable[entries[column]].value;
                            }
                            scratch = firstGroup << 24;
                            firstGroup = scratch >> 24;
                        } while (firstGroup <= 2);
                    }
                } while (0);
            }
            do {
                {
                    register u8 metadata asm("r0") = state[800];
                    register u32 secondRecordOffset asm("r2") = 153;
                    register u8 *secondRecordAddress asm("r1");

                    asm volatile("" : "+r"(metadata));
                    secondRecordOffset <<= 1;
                    secondRecordAddress = record + secondRecordOffset;
                    asm volatile("" : "+r"(secondRecordAddress));
                    *secondRecordAddress = metadata;
                }
                {
                    register u32 secondGroup asm("r4") = 0;
                    register u8 *secondDestinationBase asm("r10");
                    register u32 secondBaseAddress asm("r5") = 225;

                    asm volatile("" : "+r"(secondGroup));
                    asm volatile("" : "+r"(secondBaseAddress));
                    secondBaseAddress += (u32)record;
                    asm volatile("" : "+r"(secondBaseAddress));
                    secondDestinationBase = (u8 *)secondBaseAddress;
                    {
                        register const struct UnknownLookupRecord29250 *secondLookupTable asm(
                            "r7") = (const struct UnknownLookupRecord29250 *)gUnknown_0810b32c;

                        do {
                            u8 column;
                            register u32 scaledGroup asm("r1") = secondGroup;
                            register u32 scratch asm("r0");
                            register u8 *destination asm("r6");
                            register u8 *destinationAddress asm("r2");
                            register const u16 *entries asm("r5");

                            scaledGroup <<= 3;
                            scaledGroup -= secondGroup;
                            scratch = scaledGroup << 2;
                            scratch -= secondGroup;
                            destinationAddress = secondDestinationBase;
                            asm volatile("" : "+r"(destinationAddress));
                            destination = (u8 *)(scratch + (u32)destinationAddress);
                            scaledGroup <<= 3;
                            scratch = (u32)entryBytes;
                            asm volatile("" : "+r"(scratch));
                            entries = (const u16 *)(scaledGroup + scratch);
                            column = 0;
                            secondGroup += 1;

                            for (; column <= 26; column++) {
                                u16 value;

                                destination[column] = secondLookupTable[entries[column]].value;
                            }
                            scratch = secondGroup << 24;
                            secondGroup = scratch >> 24;
                        } while (secondGroup <= 2);
                    }
                }
            } while (0);
            do {
                {
                    register u8 metadata asm("r0") = state[800];
                    register u32 thirdRecordOffset asm("r2") = 231;
                    register u8 *thirdRecordAddress asm("r1");

                    asm volatile("" : "+r"(metadata));
                    thirdRecordOffset <<= 1;
                    thirdRecordAddress = record + thirdRecordOffset;
                    asm volatile("" : "+r"(thirdRecordAddress));
                    *thirdRecordAddress = metadata;
                }
                {
                    register u32 thirdGroup asm("r4") = 0;
                    register u8 *thirdDestinationBase asm("r10");
                    register u32 thirdBaseAddress asm("r5") = 381;

                    asm volatile("" : "+r"(thirdGroup));
                    asm volatile("" : "+r"(thirdBaseAddress));
                    thirdBaseAddress += (u32)record;
                    asm volatile("" : "+r"(thirdBaseAddress));
                    thirdDestinationBase = (u8 *)thirdBaseAddress;
                    {
                        register const struct UnknownLookupRecord29250 *thirdLookupTable asm("r7") =
                            (const struct UnknownLookupRecord29250 *)gUnknown_0810b32c;

                        do {
                            u8 column;
                            register u32 scaledGroup asm("r1") = thirdGroup;
                            register u32 scratch asm("r0");
                            register u8 *destination asm("r6");
                            register u8 *destinationAddress asm("r2");
                            register const u16 *entries asm("r5");

                            scaledGroup <<= 3;
                            scaledGroup -= thirdGroup;
                            scratch = scaledGroup << 2;
                            scratch -= thirdGroup;
                            destinationAddress = thirdDestinationBase;
                            asm volatile("" : "+r"(destinationAddress));
                            destination = (u8 *)(scratch + (u32)destinationAddress);
                            scaledGroup <<= 3;
                            scratch = (u32)entryBytes;
                            asm volatile("" : "+r"(scratch));
                            entries = (const u16 *)(scaledGroup + scratch);
                            column = 0;
                            thirdGroup += 1;

                            for (; column <= 26; column++) {
                                u16 value;

                                destination[column] = thirdLookupTable[entries[column]].value;
                            }
                            scratch = thirdGroup << 24;
                            thirdGroup = scratch >> 24;
                        } while (thirdGroup <= 2);
                    }
                }
            } while (0);
            do {
                {
                    register u32 metadataScratch asm("r0") = 200;
                    register u8 metadata asm("r1");

                    metadataScratch <<= 2;
                    metadataScratch += (u32)state;
                    metadata = *(u8 *)metadataScratch;
                    asm volatile("" : "+r"(metadata));
                    {
                        register u32 fourthRecordOffset asm("r2") = 618;
                        register u8 *fourthRecordAddress asm("r0");

                        fourthRecordAddress = record + fourthRecordOffset;
                        asm volatile("" : "+r"(fourthRecordAddress));
                        *fourthRecordAddress = metadata;
                    }
                }
                {
                    register u32 fourthGroup asm("r4") = 0;
                    register u8 *fourthDestinationBase asm("r7");
                    register u32 fourthBaseAddress asm("r5") = 537;

                    asm volatile("" : "+r"(fourthGroup));
                    asm volatile("" : "+r"(fourthBaseAddress));
                    fourthDestinationBase = record + fourthBaseAddress;
                    asm volatile("" : "+r"(fourthDestinationBase));
                    {
                        register const struct UnknownLookupRecord29250 *fourthLookupTable asm(
                            "r3") = (const struct UnknownLookupRecord29250 *)gUnknown_0810b32c;

                        do {
                            u8 column;
                            register u32 scaledGroup asm("r1") = fourthGroup;
                            register u32 scratch asm("r0");
                            register u8 *destination asm("r6");
                            register const u16 *entries asm("r5");

                            scaledGroup <<= 3;
                            scaledGroup -= fourthGroup;
                            scratch = scaledGroup << 2;
                            scratch -= fourthGroup;
                            destination = (u8 *)(scratch + (u32)fourthDestinationBase);
                            scaledGroup <<= 3;
                            scratch = (u32)entryBytes;
                            asm volatile("" : "+r"(scratch));
                            entries = (const u16 *)(scaledGroup + scratch);
                            column = 0;
                            fourthGroup += 1;

                            for (; column <= 26; column++) {
                                u16 value;

                                destination[column] = fourthLookupTable[entries[column]].value;
                            }
                            scratch = fourthGroup << 24;
                            fourthGroup = scratch >> 24;
                        } while (fourthGroup <= 2);
                    }
                }
            } while (0);
        }

        {
            register u8 *configAddress asm("r3") = config;

            asm volatile("" : "+r"(configAddress));
            if (configAddress[0] == 10) {
                gUnknown_03005268[0] |= 1;
            }
            if (configAddress[1] == 10) {
                gUnknown_03005268[1] |= 1;
            }
            if (configAddress[2] == 10) {
                gUnknown_03005268[2] |= 1;
            }
        }
        {
            register u8 *configAddress asm("r1") = config;

            asm volatile("" : "+r"(configAddress));
            if (configAddress[3] == 10) {
                gUnknown_03005268[3] |= 1;
            }
        }
    }

    {
        u32 mode;

        {
            register u32 *modeAddress asm("r2") = &gUnknown_03005254;

            asm volatile("" : "+r"(modeAddress));
            mode = *modeAddress;
        }
        if (mode != 0) {
            register u8 *scene asm("r0") = gUnknown_03001620;

            scene += 36;
            {
                register u32 four asm("r1") = 4;

                *scene = four;
            }
            for (i = gUnknown_0300525c; i <= 3; i++) {
                memcpy(gUnknown_03005200[i], gUnknown_08edbaac, 16);
            }
        } else {
            register u8 *scene asm("r1") = gUnknown_03001620;

            scene += 36;
            {
                register u32 four asm("r0") = 4;

                *scene = four;
            }
            gUnknown_03005250 = 1;
            memcpy(gUnknown_03005200[0], gUnknown_03002170, 12);
            memcpy(gUnknown_03005200[1], gUnknown_08edbaac, 16);
            memcpy(gUnknown_03005200[2], gUnknown_08edbaac, 16);
            memcpy(gUnknown_03005200[3], gUnknown_08edbaac, 16);
        }
    }

    LZ77UnCompVram(gUnknown_0810dbcc, (void *)0x06000000);
    LZ77UnCompVram(gUnknown_08132544, (void *)0x0600C000);
    {
        register u32 count asm("r5");

        fills[1] = 0;
        {
            register void *destination asm("r1") = (void *)0x0600F800;
            register const void *source asm("r0");

            asm volatile("" : "+r"(destination));
            count = 0x01000200;
            asm volatile("" : "+r"(count));
            source = fillAddresses[0];
            asm volatile("" : "+r"(source));
            CpuFastSet(source, destination, count);
        }
        fills[2] = 0;
        {
            register void *destination asm("r1") = (void *)0x0600F000;
            register const void *source asm("r0");

            asm volatile("" : "+r"(destination));
            source = fillAddresses[1];
            asm volatile("" : "+r"(source));
            CpuFastSet(source, destination, count);
        }
    }
    LZ77UnCompVram(gUnknown_08116444, (void *)0x0600E800);

    {
        u16 *destination = (u16 *)0x0600E000;

        for (i = 0; i <= 3; i++) {
            for (j = 0; j <= 3; j++) {
                FUN_08021000(destination, gUnknown_081327d4, 8, 8, 0xF200);
                destination += 8;
            }
            destination += 0xE0;
        }
    }

    LZ77UnCompVram(gUnknown_0810df04, (void *)0x06010000);
    {
        register u32 selected asm("r1") = gUnknown_03005250;
        register u32 selectedCopy asm("r0") = selected;

        asm volatile("" : "+r"(selected), "+r"(selectedCopy));
        if (selected <= 4) {
            register u32 source asm("r1");

            selected += 2;
            selected <<= 9;
            selected += (u32)gUnknown_08116568;
            asm volatile("" : "+r"(selected));
            FUN_0802036c(0x06016000, selected, 512);
            source = (u32)gUnknown_08117368;
            asm volatile("" : "+r"(source));
            FUN_0802036c(0x06016200, source, 2048);
        } else if (selected <= 9) {
            register u32 source asm("r1");

            selected -= 4;
            selected <<= 9;
            selected += (u32)gUnknown_08116568;
            asm volatile("" : "+r"(selected));
            FUN_0802036c(0x06016000, selected, 512);
            source = (u32)gUnknown_08117b68;
            asm volatile("" : "+r"(source));
            FUN_0802036c(0x06016200, source, 2048);
        } else if (selectedCopy <= 14) {
            register u32 source asm("r1") = selectedCopy;

            source -= 10;
            source <<= 9;
            source += (u32)gUnknown_08116568;
            asm volatile("" : "+r"(source));
            FUN_0802036c(0x06016000, source, 512);
            source = (u32)gUnknown_08118368;
            asm volatile("" : "+r"(source));
            FUN_0802036c(0x06016200, source, 2048);
        }
    }

#define LOAD_PLAYER_GRAPHICS(index, destination)                                                   \
    do {                                                                                           \
        register u32 value asm("r0") = gUnknown_0300524c[index];                                   \
        asm volatile("" : "+r"(value));                                                            \
        if (value > 9) {                                                                           \
            value = 10;                                                                            \
        } else if (value > 8) {                                                                    \
            value = 9;                                                                             \
        }                                                                                          \
        {                                                                                          \
            register u32 source asm("r1") = (u32)gUnknown_08edbadc[value];                         \
            asm volatile("" : "+r"(source));                                                       \
            FUN_08020408((destination), source);                                                   \
        }                                                                                          \
    } while (0)

    LOAD_PLAYER_GRAPHICS(0, 0x06013800);
    LOAD_PLAYER_GRAPHICS(1, 0x06014200);
    LOAD_PLAYER_GRAPHICS(2, 0x06014C00);
    LOAD_PLAYER_GRAPHICS(3, 0x06015600);
#undef LOAD_PLAYER_GRAPHICS

    {
        register u8 *variants asm("r5") = gUnknown_03005268;

        asm volatile("" : "+r"(variants));
        FUN_080290e8(0, variants[0], 0);
        FUN_080290e8(1, variants[1], 1);
        FUN_080290e8(2, variants[2], 2);
        FUN_080290e8(3, variants[3], 3);
    }

    FUN_0801f7d0(FUN_08030d20, 12, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0802a0ec, 28, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0802b2d4, 16, gUnknown_03003e20, 0);
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->player = 0;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->player = 1;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->player = 2;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->player = 3;
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edbabc[0];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edbabc[1];
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->player = 0;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->player = 1;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->player = 2;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->player = 3;

    FUN_0801fba0(0, 8000);
    gUnknown_03002030 = FUN_08029ba0;
    if (gUnknown_03005254 != 0) {
        register u16 *command asm("r5");
        register u8 *playerAddress asm("r3");
        register u32 mask asm("r1");
        register u32 packed asm("r2");
        register u32 player asm("r0");
        register u8 *selectionAddress asm("r0");
        register u32 selection asm("r4");
        register u8 *variants asm("r6");
        register u8 *scene asm("r0");

        command = gUnknown_03001b10;
        asm volatile("" : "+r"(command));
        {
            register u32 commandValue asm("r0") = 0x3456;

            asm volatile("" : "+r"(commandValue));
            command[1] = commandValue;
        }
        playerAddress = &gUnknown_03005260;
        asm volatile("" : "+r"(playerAddress));
        player = *playerAddress;
        mask = 15;
        asm volatile("" : "+r"(mask));
        packed = mask;
        packed &= player;
        packed <<= 12;
        selectionAddress = gUnknown_0300524c;
        playerAddress = (u8 *)(u32)*playerAddress;
        selectionAddress = (u8 *)((u32)playerAddress + (u32)selectionAddress);
        selection = *selectionAddress;
        player = mask;
        player &= selection;
        player <<= 8;
        packed |= player;
        variants = gUnknown_03005268;
        playerAddress += (u32)variants;
        playerAddress = (u8 *)(u32)*playerAddress;
        player = mask;
        player &= (u32)playerAddress;
        player <<= 4;
        packed |= player;
        scene = gUnknown_03001620;
        player = scene[3];
        mask &= player;
        mask |= packed;
        command[2] = mask;
        command[3] = 0;
        command[4] = 0;
        command[5] = 0;
        command[6] = 0;
        command[7] = 0;
    }
    FUN_0801f618(2);
    gUnknown_03005258 = 0;
}
}

extern "C" {
extern const u16 gUnknown_0810db14[];
extern const u8 gUnknown_0810db54[];
extern u8 gUnknown_03001620[], gUnknown_0300524c[], gUnknown_03005268[], gUnknown_0300525c;
extern u8 gUnknown_030013b0[], gUnknown_03002600[], gUnknown_03002110[];
extern u32 gUnknown_03005254;
extern void (*gUnknown_03002030)(void);
void FUN_0801fbfc(const u16 *, u8);
void FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void), FUN_0801f780(void);
void FUN_080210d8(void), FUN_0802110c(void);
void *memcpy(void *, const void *, unsigned long);
void FUN_080184c8(void), FUN_08018c3c(void), FUN_0801c82c(void);
void FUN_080299c0(void) {
    u8 *scene;
    u8 *state;

    FUN_0801fbfc(gUnknown_0810db14, 16);
    FUN_0801fb60();
    FUN_0801fb94();
    FUN_0801ff30();
    FUN_0801f780();
    FUN_080210d8();
    FUN_0802110c();

    {
        register u8 *selectionDestination asm("r2") = gUnknown_03001620;
        register u8 *selectionCount asm("r1") = selectionDestination;

        selectionCount += 36;
        {
            register u32 countZero asm("r0") = 0;

            *selectionCount = countZero;
        }
        {
            u32 loopIndex = 0;

            selectionDestination += 20;
            {
                register u32 zero asm("r5") = 0;

                do {
                    register u32 selection asm("r0") = gUnknown_0300524c[loopIndex];
                    register u32 selectionTest asm("r3") = selection;

                    if (selectionTest > 9) {
                        selection = 0xFF;
                        *selectionDestination = 0xFF;
                    } else {
                        if (selectionTest > 8) {
                            selection = 9;
                        }
                        *selectionDestination = selection;
                        *selectionCount += 1;
                    }

                    if (loopIndex >= gUnknown_0300525c && *selectionDestination != 0xFF) {
                        selectionDestination[8] = 1;
                    } else {
                        selectionDestination[8] = zero;
                    }
                    selectionDestination++;
                    loopIndex++;
                } while (loopIndex <= 3);
            }
        }
    }

    scene = gUnknown_03001620;
    scene[125] = 0;
    if (gUnknown_03005254 != 0) {
        scene[0] = 1;
        if (gUnknown_0300525c == 2) {
            u8 *copyBase = gUnknown_030013b0 + 312;

            memcpy(copyBase, copyBase - 312, 156);
            memcpy(copyBase + 156, copyBase - 156, 156);
        } else if (gUnknown_0300525c == 3) {
            u8 *copyBase = gUnknown_030013b0 + 468;

            memcpy(copyBase, copyBase - 468, 156);
        }
    } else {
        scene[0] = 0;
    }

    asm volatile("" : : : "r4");
    {
        register u8 *output asm("r3") = gUnknown_03001620;
        register const u8 *table asm("r2") = gUnknown_0810db54;
        register const u8 *indices asm("r1") = gUnknown_03002600;

        {
            register u32 index asm("r0") = indices[0];

            index += (u32)table;
            output[4] = *(u8 *)index;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[1];

            entry += 8;
            entry += index;
            output[5] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[2];

            entry += 16;
            entry += index;
            output[6] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[3];

            entry += 24;
            entry += index;
            output[7] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[4];

            entry += 32;
            entry += index;
            output[8] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[5];

            entry += 40;
            entry += index;
            output[9] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r4") = indices[6];

            entry += 48;
            entry += index;
            output[10] = *entry;
        }
        {
            register const u8 *entry asm("r0") = table;
            register u32 index asm("r1") = indices[8];

            entry += 64;
            entry += index;
            output[11] = *entry;
        }

        {
            register u32 active asm("r2") = 0;
            register const u8 *variants asm("r1") = gUnknown_03005268;

            if (variants[0] == 0) {
                active = 1;
            }
            output[32] = active;

            active = 0;
            if (variants[1] == 0) {
                active = 1;
            }
            output[33] = active;

            active = 0;
            if (variants[2] == 0) {
                active = 1;
            }
            output[34] = active;

            active = 0;
            if (variants[3] == 0) {
                active = 1;
            }
            output[35] = active;
            asm volatile("" : "+r"(output));
        }
    }

    state = (u8 *)&gUnknown_03002110;
    {
        register u32 counterOffset asm("r0") = 1138;
        register u8 *counter asm("r2") = state + counterOffset;
        register u32 value asm("r0") = *counter + 1;
        *counter = value;
        {
            register u32 limitOffset asm("r3") = 1139;
            register u8 *limit asm("r1") = state;

            limit += limitOffset;
            if ((u8)value >= *limit) {
                *counter = 0;
            }
        }
    }

    FUN_080184c8();
    FUN_08018c3c();
    gUnknown_03002030 = FUN_0801c82c;
}
}

extern "C" {
struct UnknownAllocation29d74 {
    u8 unused0[2];
    u16 index;
    u8 childIndices[2], unused6[6];
    u8 lowFlags[4], highFlags[4], firstSelection, secondSelection;
};
extern u32 gUnknown_03005254, gUnknown_03005258;
extern u8 gUnknown_0300525c, gUnknown_0300524c[], gUnknown_03005268[];
extern u8 gUnknown_030013b0[], gUnknown_03002110[], gUnknown_03001620[];
extern u16 gUnknown_03001b10[];
extern const u8 gUnknown_08116568[], gUnknown_08117368[], gUnknown_08117b68[], gUnknown_08118368[];
extern const u8 gUnknown_0810b32c[];
extern const void *const gUnknown_08edbadc[];
extern void (*gUnknown_03002030)(void);
u32 FUN_0802067c(u16 *, u16), FUN_0801fab0(u16);
void FUN_0803d1a0(void), FUN_0801fb60(void), FUN_0801fb94(void), FUN_0801ff30(void);
void FUN_0801f780(void), FUN_080210d8(void), FUN_0802110c(void), FUN_0801f89c(void),
    FUN_0801fda0(void);
void FUN_0802036c(u32, u32, u32), FUN_08020408(u32, u32);
void FUN_08029ba0(void) {
    u32 *counter;

    if (gUnknown_03005254 != 0) {
        counter = &gUnknown_03005258;
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

        if (gUnknown_0300525c == (u8)FUN_0801fab0(0x1379)) {
            *counter = 0;
        } else {
            (*counter)++;
        }
    }

    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08029c28(void) {}

void FUN_08029c2c(u32 index) {
    if (index <= 4) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((index + 2) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08117368, 2048);
    } else if (index <= 9) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((index - 4) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08117b68, 2048);
    } else if (index <= 14) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((index - 10) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08118368, 2048);
    }
}

void FUN_08029cc8(u32 index, u32 selection) {
    u32 playerIndex = index;

    if (selection > 9) {
        selection = 10;
    } else if (selection > 8) {
        selection = 9;
    }

    FUN_08020408(0x06013800 + ((playerIndex * 5) << 9), (u32)gUnknown_08edbadc[selection]);
}

void FUN_08029cfc(u32 playerIndex) {
    register u32 normalizedIndex asm("r0") = (u8)playerIndex;
    register u8 *players asm("r2") = gUnknown_030013b0;
    register u32 multiplier asm("r1") = 156;
    register u32 playerOffset asm("r4") = normalizedIndex;

    asm volatile("" : "+r"(normalizedIndex));
    playerOffset *= multiplier;
    {
        register u8 *player asm("r1") = (u8 *)(playerOffset + (u32)players);
        register u8 *state asm("r3") = (u8 *)&gUnknown_03002110;
        register u32 stateOffset asm("r5") = 800;
        register u8 *stateValue asm("r0") = state + stateOffset;
        register u32 value asm("r0") = *stateValue;

        asm volatile("" : "+r"(value));
        player[150] = value;

        {
            u32 row = 0;
            register u16 *sourceBase asm("r12") = (u16 *)(state + 0x322);
            u8 *destinationBase;

            players += 69;
            destinationBase = (u8 *)(playerOffset + (u32)players);
            {
                register const u8(*records)[8] asm("r6") = (const u8(*)[8])gUnknown_0810b32c;

                do {
                    register u32 rowTimesSeven asm("r1") = (row << 3) - row;
                    register u32 destinationOffset asm("r0") = (rowTimesSeven << 2) - row;
                    register u8 *destination asm("r4") = destinationBase + destinationOffset;
                    register u16 *sources asm("r3");

                    rowTimesSeven <<= 3;
                    sources = (u16 *)(rowTimesSeven + (u32)sourceBase);
                    {
                        u32 column = 0;

                        row++;
                        do {
                            destination[column] = records[sources[column]][4];
                            {
                                register u32 nextColumn asm("r0") = column + 1;

                                column = (u8)nextColumn;
                            }
                        } while (column <= 26);
                    }
                    {
                        register u32 shiftedRow asm("r0") = row << 24;

                        row = shiftedRow >> 24;
                    }
                } while (row <= 2);
            }
        }
    }
}

void FUN_08029d74(Node *node) {
    register struct UnknownAllocation29d74 *data asm("r12") =
        (UnknownAllocation29d74 *)node->allocation;

    if (gUnknown_03005254 == 0) {
        return;
    }
    {
        register u16 *displayState asm("r5") = gUnknown_03001b10;
        register u32 mask asm("r6");

        {
            register struct UnknownAllocation29d74 *dataAddress asm("r1") = data;
            register u32 index asm("r0") = dataAddress->index;
            register u32 lowMask asm("r1");
            register u32 value asm("r2");
            register u32 tableIndex asm("r3");

            mask = 15;
            lowMask = 15;
            value = lowMask;
            value &= index;
            value <<= 12;
            {
                register const u8 *firstTable asm("r0") = gUnknown_0300524c;
                register struct UnknownAllocation29d74 *indexAddress asm("r4") = data;

                tableIndex = indexAddress->index;
                firstTable = (const u8 *)(tableIndex + (u32)firstTable);
                {
                    register u32 tableValue asm("r4") = *firstTable;

                    index = lowMask;
                    index &= tableValue;
                }
                index <<= 8;
                value |= index;
            }
            {
                register const u8 *secondTable asm("r0") = gUnknown_03005268;
                register u32 tableAddress asm("r3") = tableIndex + (u32)secondTable;

                tableIndex = *(const u8 *)tableAddress;
                index = lowMask;
                index &= tableIndex;
                index <<= 4;
                value |= index;
            }
            {
                register u8 *scene asm("r0") = gUnknown_03001620;

                index = scene[3];
            }
            lowMask &= index;
            lowMask |= value;
            displayState[2] = lowMask;
        }

        {
            register struct UnknownAllocation29d74 *firstAddress asm("r1") = data;
            register u32 first asm("r0") = firstAddress->firstSelection;
            register struct UnknownAllocation29d74 *secondAddress asm("r2");
            register u32 flags asm("r1");

            first++;
            first &= mask;
            flags = first << 12;
            secondAddress = data;
            first = secondAddress->secondSelection;
            first++;
            first &= mask;
            first <<= 4;
            flags |= first;
            displayState[3] = flags;

            if (secondAddress->firstSelection != 0xFF) {
                register u8 selection asm("r3");
                register u8 *flagAddress asm("r0") = (u8 *)data + 16;

                selection = secondAddress->firstSelection;
                flagAddress += selection;
                if (*flagAddress != 0) {
                    register u32 highBit asm("r4") = 128;
                    register u32 bit asm("r0");

                    asm volatile("" : "+r"(highBit));
                    highBit <<= 1;
                    asm volatile("" : "+r"(highBit));
                    bit = highBit;
                    asm volatile("" : "+r"(bit));
                    displayState[3] = flags | bit;
                }
                {
                    register u8 *flagAddress asm("r0") = (u8 *)data + 12;
                    register struct UnknownAllocation29d74 *selectionAddress asm("r1") = data;
                    register u32 selection asm("r1") = selectionAddress->firstSelection;

                    flagAddress += selection;
                    if (*flagAddress != 0) {
                        displayState[3] |= 0xF00;
                    }
                }
            }
        }

        {
            register struct UnknownAllocation29d74 *selectionAddress asm("r3") = data;

            if (selectionAddress->secondSelection != 0xFF) {
                register u8 selection asm("r4");
                register u8 *flagAddress asm("r0") = (u8 *)data + 16;

                selection = selectionAddress->secondSelection;
                flagAddress += selection;
                if (*flagAddress != 0) {
                    register u32 current asm("r1") = displayState[3];
                    register u32 bit asm("r0") = 1;

                    bit |= current;
                    displayState[3] = bit;
                }
                {
                    register u8 *flagAddress asm("r0") = (u8 *)data + 12;
                    register struct UnknownAllocation29d74 *secondAddress asm("r1") = data;
                    register u32 selection asm("r1") = secondAddress->secondSelection;

                    flagAddress += selection;
                    if (*flagAddress != 0) {
                        register u32 current asm("r1") = displayState[3];
                        register u32 bits asm("r0") = 15;

                        bits |= current;
                        displayState[3] = bits;
                    }
                }
            }
        }
    }
}
}

extern "C" {
extern u32 gUnknown_03005254;
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern s16 gUnknown_030016f0[][8];
extern u8 gUnknown_03001620[];
extern u8 gUnknown_0300524c[], gUnknown_03005268[];
extern Node gUnknown_03003e20[];
void FUN_080290e8(u32, u32, u32);
void FUN_08029cc8(u32, u32);
void FUN_0802b444(Node *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0801f8c0(Node *);

struct PacketState {
    u8 unused0[8], sprites[4], slots[4], flags[4];
};
void FUN_08029e60(Node *node) {
    PacketState *state = (PacketState *)node->allocation;
    if (gUnknown_03005254 == 0)
        return;
    for (u32 peer = 0; peer < gUnknown_0300525c; peer++) {
        if (peer == gUnknown_03005260)
            continue;
        if (gUnknown_030016f0[peer][0] != 0x1379)
            continue;
        s32 command = gUnknown_030016f0[peer][1];
        if (command != 0x3456 && command != 0x4567 && command != 0x4568 && command != 0x4569)
            continue;
        u32 player = ((u32)gUnknown_030016f0[peer][2] & 0xf000) >> 12;
        u32 selection = (gUnknown_030016f0[peer][2] & 0xf00) >> 8;
        u32 variant = (gUnknown_030016f0[peer][2] & 0xf0) >> 4;
        u32 setting = gUnknown_030016f0[peer][2] & 15;
        if (peer == 0)
            gUnknown_03001620[3] = setting;
        if (gUnknown_0300524c[player] != selection) {
            if (gUnknown_0300524c[player] == 10 || selection == 10) {
                if (selection == 10)
                    FUN_080290e8(player, 4, player);
                else
                    FUN_080290e8(player, gUnknown_03005268[player], player);
            }
            gUnknown_0300524c[player] = selection;
            FUN_08029cc8(player, gUnknown_0300524c[player]);
            register u32 selected asm("r4") = gUnknown_0300524c[player];
            if (selected > 8)
                gUnknown_03003e20[state->sprites[player]].position->attr2 = 148;
            else
                gUnknown_03003e20[state->sprites[player]].position->attr2 = (selected << 4) | 4;
            asm("" : : "r"(selected));
        }
        if (gUnknown_03005268[player] != variant)
            gUnknown_03005268[player] = variant;
        u32 first = gUnknown_030016f0[peer][3] & 0xf000;
        if (first != 0) {
            player = (u8)((first >> 12) - 1);
            state->flags[player] = (gUnknown_030016f0[peer][3] & 0xf00) >> 8;
            if ((gUnknown_030016f0[peer][3] & 0xf00) == 0xf00) {
                if (state->slots[player] == 0) {
                    Node *child = FUN_0801f7d0(FUN_0802b444, 16, gUnknown_03003e20, 0);
                    state->slots[player] = child->index;
                    child->position->player = player;
                }
            } else if (state->slots[player] != 0) {
                FUN_0801f8c0(&gUnknown_03003e20[state->slots[player]]);
                state->slots[player] = 0;
            }
        }
        u16 second = gUnknown_030016f0[peer][3] & 0xf0;
        if (second != 0) {
            player = (u8)((second >> 4) - 1);
            state->flags[player] = gUnknown_030016f0[peer][3] & 15;
            if ((gUnknown_030016f0[peer][3] & 15) == 15) {
                if (state->slots[player] == 0) {
                    Node *child = FUN_0801f7d0(FUN_0802b444, 16, gUnknown_03003e20, 0);
                    state->slots[player] = child->index;
                    child->position->player = player;
                }
            } else if (state->slots[player] != 0) {
                FUN_0801f8c0(&gUnknown_03003e20[state->slots[player]]);
                state->slots[player] = 0;
            }
        }
    }
}
}

extern "C" {
extern Node gUnknown_03003e20[];
extern u32 gUnknown_03005254;
extern u8 gUnknown_03005260, gUnknown_0300525c;
void FUN_0802b31c(Node *);
void FUN_0802b490(Node *);
void FUN_0802af30(Node *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802a0ec(Node *node) {
    u8 *state = (u8 *)node->allocation;
    Node *child;
    child = FUN_0801f7d0(FUN_0802b31c, 16, gUnknown_03003e20, 0);
    u32 firstIndex = child->index;
    u32 zero = 0;
    asm("" : : "r"(zero));
    state[8] = firstIndex;
    child->position->player = 0;
    child->position->state = 0;
    child = FUN_0801f7d0(FUN_0802b31c, 16, gUnknown_03003e20, 0);
    state[9] = child->index;
    child->position->player = 1;
    child->position->state = 0;
    child = FUN_0801f7d0(FUN_0802b31c, 16, gUnknown_03003e20, 0);
    state[10] = child->index;
    child->position->player = 2;
    child->position->state = 0;
    child = FUN_0801f7d0(FUN_0802b31c, 16, gUnknown_03003e20, 0);
    state[11] = child->index;
    child->position->player = 3;
    child->position->state = 0;
    child = FUN_0801f7d0(FUN_0802b490, 4, gUnknown_03003e20, 0);
    state[26] = child->index;
    if (gUnknown_03005254 != 0) {
        state[12] = 0;
        state[13] = 0;
        state[14] = 0;
        state[15] = 0;
        state[20] = gUnknown_03005260;
        state[21] = 255;
        register s32 sentinel asm("r0") = -1;
        asm("" : : "r"(sentinel));
        state[22] = sentinel;
        state[23] = sentinel;
        state[24] = sentinel;
        state[25] = 0;
        if (gUnknown_03005260 == 0) {
            if (gUnknown_0300525c == 3)
                state[21] = 3;
            else if (gUnknown_0300525c == 2)
                state[21] = 2;
        } else if (gUnknown_0300525c == 2)
            state[21] = 3;
    } else {
        state[20] = 0;
        state[21] = 1;
        state[22] = 2;
        state[23] = 3;
        state[24] = 255;
        state[25] = 0;
    }
    ((u16 *)state)[1] = state[20];
    node->callback = FUN_0802af30;
}

extern u8 gUnknown_03005268[], gUnknown_0300524c[], gUnknown_03002600[];
u8 FUN_0802a220(u8 player) {
    u8 variant = gUnknown_03005268[player] & 0xFE;
    u8 other;

    if (gUnknown_03005260 == player) {
        return 0;
    }
    if (gUnknown_0300524c[1] == 10 && gUnknown_0300524c[2] == 10 && gUnknown_0300524c[3] == 10) {
        return 0;
    }
    if (gUnknown_03002600[4] == 0) {
        return 1;
    }

    for (other = 0; other <= 3; other++) {
        if (other != player && gUnknown_03005268[other] == variant) {
            break;
        }
    }

    if (other != 4) {
        return 1;
    }
    return 0;
}

struct SelectionState {
    u8 unused0[2];
    u16 index;
    u8 childIndices[2];
    u8 unused6[6];
    u8 lowFlags[4], highFlags[4], firstSelection, secondSelection;
};
struct SelectionChild {
    const void *graphics;
    u8 unused4[4];
    u16 field8;
    u8 unused10[10];
    u16 x, y;
    u8 unused24[4];
};
extern Node gUnknown_03003e20[];
extern u8 gUnknown_0300524c[], gUnknown_03005268[], gUnknown_03002110[];
extern const u8 gUnknown_0811c0d0[];
extern const s16 gUnknown_08edbb34[][4];
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_08028158(Node *), FUN_08028190(Node *), FUN_0802a480(Node *);
u8 FUN_0802a220(u8);
void FUN_0802a298(Node *node) {
    SelectionState *data = (SelectionState *)node->allocation;
    Node *child;
    SelectionChild *childData;

    child = FUN_0801f7d0(FUN_08028158, 28, gUnknown_03003e20, 0);
    data->childIndices[0] = child->index;
    childData = (SelectionChild *)child->allocation;
    childData->graphics = gUnknown_0811c0d0;
    childData->field8 = 32;
    childData->x = gUnknown_08edbb34[data->index][0];
    childData->y = gUnknown_08edbb34[data->index][1];

    child = FUN_0801f7d0(FUN_08028190, 28, gUnknown_03003e20, 0);
    data->childIndices[1] = child->index;
    childData = (SelectionChild *)child->allocation;
    childData->graphics = gUnknown_0811c0d0;
    childData->field8 = 48;
    childData->x = gUnknown_08edbb34[data->index][2];
    childData->y = gUnknown_08edbb34[data->index][3];

    data->highFlags[3] = 0;
    data->highFlags[2] = 0;
    data->highFlags[1] = 0;
    data->highFlags[0] = 0;
    node->callback = FUN_0802a480;
}

void FUN_0802a34c(Node *node) {
    SelectionState *data = (SelectionState *)node->allocation;
    u8 *states = gUnknown_0300524c;
    u16 player = data->index;

    if (states[player] == 10) {
        if (FUN_0802a220((u8)player) != 0) {
            gUnknown_03005268[data->index] |= 1;
        } else {
            gUnknown_03005268[data->index] &= 0xFE;
            gUnknown_0300524c[data->index] = 9;
        }
    } else {
        gUnknown_03005268[player] &= 0xFE;
    }

    if (gUnknown_0300524c[data->index] == 8 && (gUnknown_03002110[121] & 2) == 0) {
        gUnknown_0300524c[data->index]--;
    }
    if (gUnknown_0300524c[data->index] == 7 && (gUnknown_03002110[121] & 4) == 0) {
        gUnknown_0300524c[data->index]--;
    }
}

void FUN_0802a3f4(Node *node) {
    SelectionState *data = (SelectionState *)node->allocation;
    u8 *states = gUnknown_0300524c;

    if (states[data->index] == 10) {
        u8 valid = FUN_0802a220((u8)data->index);

        if (valid != 0) {
            gUnknown_03005268[data->index] |= 1;
        } else {
            gUnknown_03005268[data->index] &= 0xFE;
            states[data->index] = valid;
        }
    } else if (states[data->index] > 10) {
        gUnknown_03005268[data->index] &= 0xFE;
        states[data->index] = 0;
    } else {
        gUnknown_03005268[data->index] &= 0xFE;
    }
}

extern Node gUnknown_03003e20[];
extern const s16 gUnknown_08edbb34[][4];
extern u8 gUnknown_03005260, gUnknown_0300524c[], gUnknown_03002110[];
extern u32 gUnknown_03005254;
extern s16 gUnknown_030016f0[][8];
extern u16 gUnknown_030048e0[];
void FUN_080280b8(Node *, s16, s16);
void FUN_0801f8c0(Node *);
void FUN_0801f618(u16);
void FUN_0801f718(u16, u16);
void FUN_0802b08c(Node *), FUN_0802b134(Node *), FUN_0802b1dc(Node *);
void FUN_0802a70c(Node *), FUN_0802afb0(Node *), FUN_0802afc4(Node *);
void FUN_08027db8(Node *), FUN_08027e38(Node *);
void FUN_0802a34c(Node *), FUN_0802a3f4(Node *);
void FUN_08029d74(Node *), FUN_08029e60(Node *);
struct InputState {
    u16 timer, index;
    u8 children[2], unused6[6], childSlots[4], flags[4], selections[5], cursor;
};
void FUN_0802a480(Node *node) {
    InputState *state = (InputState *)node->allocation;
    FUN_080280b8(&gUnknown_03003e20[state->children[0]], gUnknown_08edbb34[state->index][0],
                 gUnknown_08edbb34[state->index][1]);
    FUN_080280b8(&gUnknown_03003e20[state->children[1]], gUnknown_08edbb34[state->index][2],
                 gUnknown_08edbb34[state->index][3]);
    if (gUnknown_03005260 != 0) {
        if (gUnknown_030016f0[0][1] == 0x4567)
            node->callback = FUN_0802b08c;
        if (gUnknown_030016f0[0][1] == 0x4568)
            node->callback = FUN_0802b134;
    }
    register u32 keys asm("r1") = gUnknown_030048e0[2];
    if (keys & 256) {
        if (gUnknown_03005260 == 0) {
            node->callback = FUN_0802b08c;
            FUN_0801f618(402);
        }
    } else if (keys & 512) {
        if (gUnknown_03005260 == 0) {
            node->callback = FUN_0802b134;
            FUN_0801f618(402);
        }
    } else if (keys & 2) {
        if (state->cursor != 0) {
            state->cursor--;
            state->index = state->selections[state->cursor];
            FUN_0801f8c0(&gUnknown_03003e20[state->childSlots[state->index]]);
            state->childSlots[state->index] = 0;
            state->flags[state->index] = 0;
            FUN_0801f618(403);
        } else if (gUnknown_03005254 == 0) {
            FUN_0801f718(2, 120);
            FUN_0801f618(405);
            node->callback = FUN_0802b1dc;
        }
    } else if (keys & 1) {
        u8 *flag = state->flags;
        asm("" : "+r"(flag));
        register u32 index asm("r6") = state->index;
        flag += index;
        register u32 accepted asm("r1") = 1;
        *flag = accepted;
        node->callback = FUN_0802a70c;
    } else if ((u16)(keys & 32)) {
        if (gUnknown_0300524c[state->index] != 0)
            gUnknown_0300524c[state->index]--;
        else
            gUnknown_0300524c[state->index] = 10;
        FUN_0802a34c(node);
        gUnknown_03003e20[state->children[0]].callback = FUN_08027db8;
        gUnknown_03003e20[state->children[0]].position->state = 0;
        state->timer = 0;
        node->callback = FUN_0802afb0;
        FUN_0801f618(401);
    } else if (keys & 16) {
        if (++gUnknown_0300524c[state->index] > 10)
            gUnknown_0300524c[state->index] = 0;
        if (gUnknown_0300524c[state->index] == 7 && (gUnknown_03002110[121] & 4) == 0)
            gUnknown_0300524c[state->index]++;
        if (gUnknown_0300524c[state->index] == 8 && (gUnknown_03002110[121] & 2) == 0)
            gUnknown_0300524c[state->index]++;
        FUN_0802a3f4(node);
        gUnknown_03003e20[state->children[1]].callback = FUN_08027e38;
        gUnknown_03003e20[state->children[1]].position->state = 0;
        state->timer = 0;
        node->callback = FUN_0802afc4;
        FUN_0801f618(401);
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}

extern Node gUnknown_03003e20[];
extern u8 gUnknown_03002600[], gUnknown_0300524c[];
void FUN_0802a9a4(Node *), FUN_0802b444(Node *), FUN_0802a480(Node *), FUN_0802afd8(Node *);
void FUN_08029d74(Node *), FUN_08029e60(Node *);
void FUN_0801f618(u16), FUN_0801f8c0(Node *);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
struct AcceptState {
    u16 timer, index;
    u8 children[2], unused6[6], childSlots[4], flags[4], selections[5], cursor;
};
void FUN_0802a70c(Node *node) {
    AcceptState *state = (AcceptState *)node->allocation;
    if (++state->flags[state->index] > 4) {
        if (gUnknown_03002600[4] != 0 && gUnknown_0300524c[state->index] != 10) {
            node->callback = FUN_0802a9a4;
            gUnknown_03003e20[state->children[0]].position->tile = 0;
            gUnknown_03003e20[state->children[1]].position->tile = 16;
            FUN_0801f618(402);
        } else {
            Node *child = FUN_0801f7d0(FUN_0802b444, 16, gUnknown_03003e20, 0);
            state->childSlots[state->index] = child->index;
            child->position->player = state->index;
            state->cursor++;
            register u8 *nextBase asm("r0") = state->selections;
            asm("" : "+r"(nextBase));
            register u32 cursor asm("r2") = state->cursor;
            register u8 *nextAddress asm("r1") = nextBase + cursor;
            u8 next = *nextAddress;
            if (next != 255) {
                state->index = next;
                state->flags[state->index] = 0;
                node->callback = FUN_0802a480;
                FUN_0801f618(402);
            } else {
                FUN_0801f8c0(&gUnknown_03003e20[state->children[0]]);
                FUN_0801f8c0(&gUnknown_03003e20[state->children[1]]);
                node->callback = FUN_0802afd8;
                FUN_0801f618(404);
            }
        }
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}

extern Node gUnknown_03003e20[];
extern u8 gUnknown_0300524c[], gUnknown_03005268[];
void FUN_0801fba0(u16, u16);
void FUN_08029cc8(u32, u32), FUN_080290e8(u32, u32, u32);
void FUN_08029d74(Node *), FUN_08029e60(Node *);
void FUN_0802a8f8(Node *), FUN_0802a480(Node *);
struct TransitionState {
    u16 timer, index;
    u8 unused4[4], sprites[4], childSlots[4], flags[4];
};
void FUN_0802a804(Node *node) {
    TransitionState *state = (TransitionState *)node->allocation;
    gUnknown_03003e20[state->sprites[state->index]].position->attr0 |= 16;
    u32 mosaic = state->timer & 0xf00;
    FUN_0801fba0(76, (mosaic << 4) | mosaic);
    register u32 step asm("r0") = 256;
    asm("" : : "r"(step));
    register u32 timer asm("r1") = step;
    asm("" : "+r"(timer));
    register u32 previous asm("r2") = state->timer;
    timer += previous;
    state->timer = timer;
    gUnknown_03003e20[state->sprites[state->index]].position->state = (u16)timer >> 9;
    if (state->timer > 0xeff) {
        u8 *table = gUnknown_0300524c;
        u32 selection = table[state->index];
        u8 *retained = table;
        if (selection > 8)
            gUnknown_03003e20[state->sprites[state->index]].position->attr2 = 148;
        else
            gUnknown_03003e20[state->sprites[state->index]].position->attr2 = (selection << 4) | 4;
        u32 graphicsIndex = state->index;
        register u8 *graphicsTable asm("r3") = retained;
        asm("" : : "r"(graphicsTable));
        register u32 graphicsAddress asm("r1") = graphicsIndex + (u32)graphicsTable;
        FUN_08029cc8(graphicsIndex, *(u8 *)graphicsAddress);
        u32 variantIndex = state->index;
        register u8 *variantTable asm("r1") = retained;
        register u32 variantAddress asm("r0") = variantIndex + (u32)variantTable;
        if (*(u8 *)variantAddress == 10)
            FUN_080290e8(variantIndex, 4, variantIndex);
        else
            FUN_080290e8(variantIndex, gUnknown_03005268[variantIndex], variantIndex);
        node->callback = FUN_0802a8f8;
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}
void FUN_0802a8f8(Node *node) {
    TransitionState *state = (TransitionState *)node->allocation;
    gUnknown_03003e20[state->sprites[state->index]].position->attr0 |= 16;
    u32 mosaic = state->timer & 0xf00;
    FUN_0801fba0(76, (mosaic << 4) | mosaic);
    register u32 step asm("r0") = (u32)-256;
    asm("" : : "r"(step));
    register u32 timer asm("r1") = step;
    asm("" : "+r"(timer));
    timer += state->timer;
    state->timer = timer;
    gUnknown_03003e20[state->sprites[state->index]].position->state = (u16)timer >> 9;
    if (state->timer <= 256) {
        gUnknown_03003e20[state->sprites[state->index]].position->attr0 &= 239;
        gUnknown_03003e20[state->sprites[state->index]].position->state = 0;
        state->flags[state->index] = 0;
        node->callback = FUN_0802a480;
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}

extern Node gUnknown_03003e20[];
extern const s16 gUnknown_08edbb54[][4];
extern u8 gUnknown_03005260, gUnknown_03005268[];
extern s16 gUnknown_030016f0[][8];
extern u16 gUnknown_030048e0[];
void FUN_080280b8(Node *, s16, s16);
void FUN_0801f8c0(Node *), FUN_0801f618(u16);
Node *FUN_0801f7d0(void (*)(Node *), u32, Node *, u8);
void FUN_0802b08c(Node *), FUN_0802b134(Node *), FUN_0802b444(Node *);
void FUN_0802a480(Node *), FUN_0802afd8(Node *), FUN_0802ac48(Node *), FUN_0802ad4c(Node *);
void FUN_08029d74(Node *), FUN_08029e60(Node *);
struct VariantState {
    u16 timer, index;
    u8 children[2], unused6[6], childSlots[4], flags[4], selections[5], cursor, syncChild, phase;
};
static inline u8 variantShared(u8 player, u8 variant) {
    u8 other;
    for (other = 0; other <= 3; other++) {
        if (other != player && gUnknown_03005268[other] == variant)
            break;
    }
    if (other == 4)
        return 0;
    return 1;
}
void FUN_0802a9a4(Node *node) {
    VariantState *state = (VariantState *)node->allocation;
    FUN_080280b8(&gUnknown_03003e20[state->children[0]], gUnknown_08edbb54[state->index][0],
                 gUnknown_08edbb54[state->index][1]);
    FUN_080280b8(&gUnknown_03003e20[state->children[1]], gUnknown_08edbb54[state->index][2],
                 gUnknown_08edbb54[state->index][3]);
    if (gUnknown_03005260 != 0) {
        if (gUnknown_030016f0[0][1] == 0x4567)
            node->callback = FUN_0802b08c;
        if (gUnknown_030016f0[0][1] == 0x4568)
            node->callback = FUN_0802b134;
    }
    register u32 keys asm("r1") = gUnknown_030048e0[2];
    if (keys & 256) {
        if (gUnknown_03005260 == 0) {
            node->callback = FUN_0802b08c;
            FUN_0801f618(402);
        }
    } else if (keys & 512) {
        if (gUnknown_03005260 == 0) {
            node->callback = FUN_0802b134;
            FUN_0801f618(402);
        }
    } else if (keys & 1) {
        Node *child = FUN_0801f7d0(FUN_0802b444, 16, gUnknown_03003e20, 0);
        state->childSlots[state->index] = child->index;
        child->position->player = state->index;
        state->cursor++;
        register u8 *nextBase asm("r0") = state->selections;
        asm("" : "+r"(nextBase));
        register u32 cursor asm("r3") = state->cursor;
        register u8 *nextAddress asm("r1") = nextBase + cursor;
        u8 next = *nextAddress;
        if (next != 255) {
            state->index = next;
            register u8 *nextFlags asm("r0") = state->flags;
            asm("" : "+r"(nextFlags));
            register u32 nextIndex asm("r2") = state->index;
            nextFlags[nextIndex] = 0;
            node->callback = FUN_0802a480;
            gUnknown_03003e20[state->children[0]].position->tile = 32;
            gUnknown_03003e20[state->children[1]].position->tile = 48;
            FUN_0801f618(402);
        } else {
            FUN_0801f8c0(&gUnknown_03003e20[state->children[0]]);
            FUN_0801f8c0(&gUnknown_03003e20[state->children[1]]);
            node->callback = FUN_0802afd8;
            FUN_0801f618(404);
        }
    } else if (keys & 2) {
        register u8 *cancelledFlags asm("r0") = state->flags;
        asm("" : "+r"(cancelledFlags));
        register u32 cancelledIndex asm("r3") = state->index;
        cancelledFlags[cancelledIndex] = 0;
        node->callback = FUN_0802a480;
        gUnknown_03003e20[state->children[0]].position->tile = 32;
        gUnknown_03003e20[state->children[1]].position->tile = 48;
        FUN_0801f618(403);
    } else if (keys & 64) {
        if (variantShared(state->index, gUnknown_03005268[state->index])) {
            gUnknown_03005268[state->index] ^= 2;
            node->callback = FUN_0802ac48;
            state->phase = 0;
        } else
            FUN_0801f618(419);
    } else if (keys & 128) {
        if (variantShared(state->index, gUnknown_03005268[state->index])) {
            gUnknown_03005268[state->index] ^= 2;
            node->callback = FUN_0802ad4c;
            state->phase = 0;
        } else
            FUN_0801f618(419);
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}
}

extern "C" {
void FUN_08027eb8(Node *), FUN_08027f38(Node *);
void FUN_0802ac48(Node *node) {
    VariantState *state = (VariantState *)node->allocation;
    FUN_080280b8(&gUnknown_03003e20[state->children[0]], gUnknown_08edbb54[state->index][0],
                 gUnknown_08edbb54[state->index][1]);
    FUN_080280b8(&gUnknown_03003e20[state->children[1]], gUnknown_08edbb54[state->index][2],
                 gUnknown_08edbb54[state->index][3]);
    if (variantShared(state->index, gUnknown_03005268[state->index] ^ 2)) {
        if (++state->phase > 9) {
            gUnknown_03003e20[state->children[0]].callback = FUN_08027eb8;
            gUnknown_03003e20[state->children[0]].position->state = 0;
            state->timer = 0;
            FUN_0801f618(401);
            node->callback = FUN_0802a9a4;
        }
    } else {
        gUnknown_03005268[state->index] ^= 2;
        FUN_0801f618(419);
        node->callback = FUN_0802a9a4;
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}
void FUN_0802ad4c(Node *node) {
    VariantState *state = (VariantState *)node->allocation;
    FUN_080280b8(&gUnknown_03003e20[state->children[0]], gUnknown_08edbb54[state->index][0],
                 gUnknown_08edbb54[state->index][1]);
    FUN_080280b8(&gUnknown_03003e20[state->children[1]], gUnknown_08edbb54[state->index][2],
                 gUnknown_08edbb54[state->index][3]);
    if (variantShared(state->index, gUnknown_03005268[state->index] ^ 2)) {
        if (++state->phase > 9) {
            gUnknown_03003e20[state->children[1]].callback = FUN_08027f38;
            gUnknown_03003e20[state->children[1]].position->state = 0;
            state->timer = 0;
            FUN_0801f618(401);
            node->callback = FUN_0802a9a4;
        }
    } else {
        gUnknown_03005268[state->index] ^= 2;
        FUN_0801f618(419);
        node->callback = FUN_0802a9a4;
    }
    FUN_08029d74(node);
    FUN_08029e60(node);
}
}

extern "C" {
extern u32 gUnknown_03005254;
extern u16 gUnknown_03001b10[];
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern s16 gUnknown_030016f0[][8], gUnknown_030016f2[][8];
void FUN_08029d74(Node *), FUN_08029e60(Node *);
void FUN_0802b064(Node *), FUN_0802b08c(Node *), FUN_0802b134(Node *);
void FUN_0801f718(u16, u16), FUN_0801f618(u16);
void FUN_0802ae50(Node *node) {
    u32 ready = 1;
    if (gUnknown_03005254 != 0) {
        gUnknown_03001b10[1] = 0x4569;
        FUN_08029d74(node);
        FUN_08029e60(node);
        for (u8 peer = 0; peer < gUnknown_0300525c; peer++) {
            if (peer != gUnknown_03005260 && gUnknown_030016f2[peer][0] != 0x4569)
                ready = 0;
        }
        if (ready) {
            node->callback = FUN_0802b064;
            FUN_0801f718(2, 120);
            FUN_0801f618(407);
        }
        if (gUnknown_03005260 != 0) {
            if (gUnknown_030016f0[0][1] == 0x4567)
                node->callback = FUN_0802b08c;
            if (gUnknown_030016f0[0][1] == 0x4568)
                node->callback = FUN_0802b134;
        }
    } else {
        node->callback = FUN_0802b064;
        FUN_0801f718(2, 120);
        FUN_0801f618(407);
    }
}
}

extern "C" {
extern void (*gUnknown_03002030)(void);
extern u8 gUnknown_03005268[];
u32 FUN_0802067c(u16 *, u16);
void FUN_080299c0(void), FUN_0802fdf8(void), FUN_080340b8(void), FUN_08039e20(void);
}
extern "C" {
extern const u16 gUnknown_08132714[], gUnknown_0810dbac[], gUnknown_0810dd04[];
u8 FUN_08020500(u16 *, const u16 *, u16);
void FUN_0802a298(Node *);
void FUN_0802af30(Node *node) {
    register u32 firstPending asm("r1") =
        FUN_08020500((u16 *)0x050001e0, gUnknown_08132714, 16) == 0;
    asm volatile("" : : "r"(firstPending));
    u32 pending = firstPending;
    asm volatile("" : "+r"(pending));
    register u32 secondPending asm("r0");
    if (FUN_08020500((u16 *)0x05000080, gUnknown_0810dbac, 32) == 0) {
        secondPending = 1;
        asm volatile("" : : "r"(secondPending));
    } else {
        secondPending = (u8)pending;
    }
    pending = secondPending;
    asm volatile("" : "+r"(pending));
    register u32 finalPending asm("r0") =
        FUN_08020500((u16 *)0x05000200, gUnknown_0810dd04, 256) == 0 ? pending | 1 : (u8)pending;
    asm volatile("" : : "r"(finalPending));
    if (finalPending == 0)
        node->callback = FUN_0802a298;
}
}

extern "C" {
void FUN_0802a34c(Node *);
void FUN_0802a3f4(Node *);
void FUN_0802a804(Node *);
void FUN_0802afb0(Node *node) {
    FUN_0802a34c(node);
    FUN_0802a804(node);
}
void FUN_0802afc4(Node *node) {
    FUN_0802a3f4(node);
    FUN_0802a804(node);
}
}
extern "C" {
extern u32 gUnknown_03005254;
extern u8 gUnknown_03005260;
extern s16 gUnknown_030016f0[][8];
extern Node gUnknown_03003e20[101];
void FUN_0802ae50(Node *);
void FUN_08029d74(Node *);
void FUN_08029e60(Node *);
void FUN_0802b08c(Node *);
void FUN_0802b134(Node *);

void FUN_0802afd8(Node *node) {
    const u8 *state = (const u8 *)node->allocation;
    if (gUnknown_03005254 != 0) {
        if (*(u8 *)gUnknown_03003e20[state[26]].allocation > 16)
            node->callback = FUN_0802ae50;
        FUN_08029d74(node);
        FUN_08029e60(node);
        if (gUnknown_03005260 != 0) {
            if (gUnknown_030016f0[0][1] == 0x4567)
                node->callback = FUN_0802b08c;
            if (gUnknown_030016f0[0][1] == 0x4568)
                node->callback = FUN_0802b134;
        }
    } else {
        node->callback = FUN_0802ae50;
    }
}
}

extern "C" {
void FUN_0802b064(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_080299c0;
}
}
extern "C" {
extern u16 gUnknown_03001b10[];
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern s16 gUnknown_030016f2[][8];
void FUN_08029d74(Node *);
void FUN_08029e60(Node *);
void FUN_0802b10c(Node *);
void FUN_0801f618(u16);
void FUN_0801f718(u16, u16);
void FUN_0802b08c(Node *node) {
    u32 ready = 1;
    register u16 *commandAddress asm("r0") = gUnknown_03001b10;
    asm volatile("" : "+r"(commandAddress));
    register s32 command asm("r6") = 0x4567;
    commandAddress[1] = command;
    FUN_08029d74(node);
    FUN_08029e60(node);
    u8 index = 0;
    for (; index < gUnknown_0300525c; index++) {
        if (index != gUnknown_03005260 && gUnknown_030016f2[index][0] != command)
            ready = 0;
    }
    if (ready != 0) {
        node->callback = FUN_0802b10c;
        FUN_0801f618(0x197);
        FUN_0801f718(2, 120);
    }
}
}

extern "C" {
void FUN_0802b10c(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_0802fdf8;
}
}
extern "C" {
extern u16 gUnknown_03001b10[];
extern u8 gUnknown_0300525c, gUnknown_03005260;
extern s16 gUnknown_030016f2[][8];
void FUN_08029d74(Node *);
void FUN_08029e60(Node *);
void FUN_0802b1b4(Node *);
void FUN_0801f618(u16);
void FUN_0801f718(u16, u16);
void FUN_0802b134(Node *node) {
    u32 ready = 1;
    register u16 *commandAddress asm("r0") = gUnknown_03001b10;
    asm volatile("" : "+r"(commandAddress));
    register s32 command asm("r6") = 0x4568;
    commandAddress[1] = command;
    FUN_08029d74(node);
    FUN_08029e60(node);
    u8 index = 0;
    for (; index < gUnknown_0300525c; index++) {
        if (index != gUnknown_03005260 && gUnknown_030016f2[index][0] != command)
            ready = 0;
    }
    if (ready != 0) {
        node->callback = FUN_0802b1b4;
        FUN_0801f618(0x197);
        FUN_0801f718(2, 120);
    }
}
}

extern "C" {
void FUN_0802b1b4(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_080340b8;
}
}

extern "C" {
void FUN_0802b1dc(Node *) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0)
        gUnknown_03002030 = FUN_08039e20;
}
}

extern "C" {
u32 FUN_0802b204(u8 player, u8 variant) {
    u8 other;
    for (other = 0; other <= 3; other++) {
        if (other != player && gUnknown_03005268[other] == variant)
            break;
    }
    if (other == 4)
        return 0;
    return 1;
}
}
extern "C" {
extern u8 gUnknown_03002600[];
extern u8 gUnknown_03005250;
extern const u8 gUnknown_0811c224[];
extern const s16 gUnknown_08edbb74[];
void FUN_08029c2c(u32);
void FUN_0801fed8(u8, u32);

void FUN_0802b248(Node *node) {
    register u32 selection asm("r1") = 0;
    u8 *settings = gUnknown_03002600;
    switch (settings[0]) {
    case 0:
        selection = gUnknown_0811c224[settings[1] * 2];
        break;
    case 2: {
        register const u8 *table asm("r1") = gUnknown_0811c224;
        asm volatile("" : "+r"(table));
        u32 offset = settings[2] * 2;
        table += 10;
        selection = *(const u8 *)(offset + (u32)table);
        break;
    }
    case 1: {
        register const u8 *table asm("r1") = gUnknown_0811c224;
        asm volatile("" : "+r"(table));
        u32 offset = settings[3] * 2;
        table += 20;
        selection = *(const u8 *)(offset + (u32)table);
        break;
    }
    }
    if (gUnknown_03005250 != selection) {
        gUnknown_03005250 = selection;
        FUN_08029c2c(selection);
    }
    node->position->x = gUnknown_08edbb74[gUnknown_03002600[0]];
    FUN_0801fed8(node->index, 0);
}
}
extern "C" {
extern const u8 gUnknown_0811c120[], gUnknown_0811c188[], gUnknown_0811c138[], gUnknown_0811c0d8[];
extern const u16 gUnknown_08edbb7c[][2], gUnknown_08edbb8c[][2], gUnknown_08edbb9c[][2];
extern u8 gUnknown_0300524c[];
void FUN_0801fed8(u8, u32);
void FUN_0802b248(Node *);
void FUN_0802b2d4(Node *);
void FUN_0802b31c(Node *);
void FUN_0802b388(Node *);
void FUN_0802b3c8(Node *);
void FUN_0802b424(Node *);
void FUN_0802b434(Node *);
void FUN_0802b444(Node *);
void FUN_0802b2d4(Node *node) {
    node->position->parts = gUnknown_0811c120;
    node->position->tile = 768;
    node->position->x = 76;
    node->position->y = 0;
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->position->player = 0xFF;
    node->position->state = 0xFF;
    node->callback = FUN_0802b248;
}

void FUN_0802b31c(Node *node) {
    node->position->parts = gUnknown_0811c188;
    node->position->tile = node->position->player * 80 + 448;
    node->position->x = gUnknown_08edbb7c[node->position->player][0];
    node->position->y = gUnknown_08edbb7c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = (gUnknown_0300524c[node->position->player] << 4) | 4;
    node->callback = FUN_0802b388;
}

void FUN_0802b388(Node *node) {
    node->position->x =
        gUnknown_08edbb7c[node->position->player][0] - ((node->position->state + 1) >> 1);
    node->position->y =
        gUnknown_08edbb7c[node->position->player][1] - ((node->position->state + 1) >> 1);
    FUN_0801fed8(node->index, 0);
}

void FUN_0802b3c8(Node *node) {
    node->position->parts = gUnknown_0811c138;
    node->position->tile = node->position->player * 20 + 848;
    node->position->x = gUnknown_08edbb8c[node->position->player][0];
    node->position->y = gUnknown_08edbb8c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 8;
    node->callback = FUN_0802b424;
}

void FUN_0802b424(Node *node) { FUN_0801fed8(node->index, 0); }

void FUN_0802b434(Node *node) { FUN_0801fed8(node->index, 0); }

void FUN_0802b444(Node *node) {
    node->position->parts = gUnknown_0811c0d8;
    node->position->tile = 0;
    node->position->x = gUnknown_08edbb9c[node->position->player][0];
    node->position->y = gUnknown_08edbb9c[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 0;
    node->callback = FUN_0802b434;
}
}

extern "C" {
extern u32 gUnknown_03005254;
extern u8 gUnknown_03005260, gUnknown_0300525c;
extern s16 gUnknown_030016f0[][8];
extern u8 gUnknown_030016fc[];
extern u8 gUnknown_030016f8[][16];
extern u8 gUnknown_03001b18[];
extern u8 gUnknown_030013f5[];
extern const u32 gUnknown_0807163c[];
void FUN_0802f488(u8 *);
void FUN_0802f328(u8 *);

void FUN_0802b490(Node *node) {
    u8 *state = (u8 *)node->allocation;
    if (gUnknown_03005254 == 0)
        return;
    u8 *playerAddress = &gUnknown_03005260;
    u32 playerIndex = *playerAddress;
    register u8 *localPlayer asm("r8") = playerAddress;
    if (playerIndex != 0 && gUnknown_030016f0[0][0] == 0x1379 && gUnknown_030016f0[0][1] == 0x3456)
        state[0] = ((u8 *)gUnknown_030016f0)[8];
    u8 *outgoing;
    u32 peer;
    register u32 phase = state[0];
    register u32 phaseTest asm("r2") = phase;
    if (phaseTest == 1) {
        outgoing = gUnknown_03001b18;
        outgoing[0] = phase;
        if (gUnknown_03005260 != 0)
            FUN_0802f488(gUnknown_030016fc);
        FUN_0802f328(outgoing + 4);
    } else if ((u8)(phase - 2) <= 14) {
        outgoing = gUnknown_03001b18;
        register u32 recordIndex = *localPlayer;
        register u32 recordOffset = 156;
        recordOffset *= recordIndex;
        register u8 *records = gUnknown_030013f5;
        register u8 *record asm("r4") = (u8 *)(recordOffset + (u32)records);
        asm volatile("" : "+r"(state) : "r"(recordOffset));
        record += (state[0] - 2) * 6;
        outgoing[0] = state[0];
        outgoing[1] = 0;
        outgoing[2] = record[0];
        outgoing[3] = record[1];
        outgoing[4] = record[2];
        outgoing[5] = record[3];
        outgoing[6] = record[4];
        outgoing[7] = record[5];
        peer = 0;
        register u8 *countLoad = &gUnknown_0300525c;
        asm volatile("" : : "r"(countLoad));
        register u8 *peerRecords asm("r9") = records;
        if (peer < gUnknown_0300525c) {
            register const u32 *masks asm("r4") = gUnknown_0807163c;
            do {
                if (peer != *localPlayer) {
                    u8 *incoming = gUnknown_030016f8[peer];
                    if (state[0] == 0 || incoming[0] != state[0])
                        goto nextPeer;
                    register u32 destinationOffset = 156;
                    destinationOffset *= peer;
                    register u32 destinationBase asm("r1") = (u32)peerRecords;

                    register u8 *destination asm("r2") =
                        (u8 *)(destinationOffset + destinationBase);
                    asm volatile("" : : "r"(destinationOffset));
                    destination += (state[0] - 2) * 6;
                    destination[0] = incoming[2];
                    destination[1] = incoming[3];
                    destination[2] = incoming[4];
                    destination[3] = incoming[5];
                    destination[4] = incoming[6];
                    destination[5] = incoming[7];
                }
                outgoing[1] = masks[peer];
            nextPeer:
                peer = (u8)(peer + 1);
            } while (peer < gUnknown_0300525c);
        }
    } else if (phaseTest > 16) {
        outgoing = gUnknown_03001b18;
        outgoing[0] = phase;
    }
    if (gUnknown_03005260 == 0) {
        u8 matched = 1;
        register u8 *outputAddress asm("r4") = gUnknown_03001b18;
        asm volatile("" : : "r"(outputAddress));
        u8 *outgoing = outputAddress;
        peer = 1;
        for (; peer < gUnknown_0300525c; peer = (u8)(peer + 1)) {
            register u32 receivedOffset = peer << 4;
            register u8 *receivedAddress asm("r2") =
                (u8 *)(receivedOffset + (u32)gUnknown_030016f8);
            asm volatile("" : "+r"(receivedAddress) : "r"(receivedOffset));
            register u32 received asm("r2") = receivedAddress[0];

            if (outgoing[0] == received)
                matched++;
        }
        if (gUnknown_0300525c == matched && state[0] <= 16)
            state[0]++;
    }
}
}

extern "C" {
extern const u8 gUnknown_0811c0e0[];
extern const u16 gUnknown_08edbbac[][2];
extern u8 gUnknown_03002600[], gUnknown_0300524c[], gUnknown_03005268[];
void FUN_0801fed8(u8, u32);
void FUN_0802b688(Node *);
void FUN_0802b638(Node *node) {
    node->position->parts = gUnknown_0811c0e0;
    node->position->tile = 64;
    node->position->x = gUnknown_08edbbac[node->position->player][0];
    node->position->y = gUnknown_08edbbac[node->position->player][1];
    node->position->attr0 = 0;
    node->position->attr1 = 0;
    node->position->attr2 = 184;
    node->callback = FUN_0802b688;
}
void FUN_0802b688(Node *incoming) {
    register Node *node asm("r2") = incoming;
    {
        u8 *states = gUnknown_0300524c;
        Position *position = node->position;

        if (states[position->player] > 9) {
            position->tile = 256;
            node->position->attr2 = 168;
        } else {
            if (gUnknown_03002600[4] != 0 && (gUnknown_03005268[position->player] & 2) != 0) {
                position->tile = 160;
            } else {
                node->position->tile = 64;
            }
            node->position->attr2 = 184;
        }
        FUN_0801fed8(node->index, 0);
    }
}
}

extern "C" {
u8 gUnknown_03005250;
extern const u8 gUnknown_0811c0c8[];
extern const u8 gUnknown_08118b68[], gUnknown_08119124[], gUnknown_081196c0[];
extern const u8 gUnknown_08119c94[], gUnknown_0811a21c[], gUnknown_0811a76c[];
extern const u8 gUnknown_0811ac7c[], gUnknown_0811b1c4[], gUnknown_0811b630[];
extern const u8 gUnknown_0811bb00[], gUnknown_0811bf90[];

const Position gUnknown_08edbabc[2] = {{gUnknown_0811c0c8, 32, 16, 384, 0, 0, 0, 0, 0, 0},
                                       {gUnknown_0811c0c8, 208, 16, 416, 0, 0, 0, 0, 0, 0}};
const void *const gUnknown_08edbadc[11] = {gUnknown_08118b68, gUnknown_08119124, gUnknown_081196c0,
                                           gUnknown_08119c94, gUnknown_0811a21c, gUnknown_0811a76c,
                                           gUnknown_0811ac7c, gUnknown_0811b1c4, gUnknown_0811b630,
                                           gUnknown_0811bb00, gUnknown_0811bf90};

#define SELECTION_COORDINATES __attribute__((section(".rodata.selection_positions")))
const s16 gUnknown_08edbb34[4][4] SELECTION_COORDINATES = {
    {64, 80, 112, 80}, {184, 80, 232, 80}, {64, 144, 112, 144}, {184, 144, 232, 144}};
const s16 gUnknown_08edbb54[4][4] SELECTION_COORDINATES = {
    {40, 56, 40, 88}, {160, 56, 160, 88}, {40, 120, 40, 152}, {160, 120, 160, 152}};
const s16 gUnknown_08edbb74[4] SELECTION_COORDINATES = {56, 48, 48, 0};
const u16 gUnknown_08edbb7c[4][2] SELECTION_COORDINATES = {
    {48, 24}, {168, 24}, {48, 88}, {168, 88}};
const u16 gUnknown_08edbb8c[4][2] SELECTION_COORDINATES = {
    {6, 36}, {126, 36}, {6, 100}, {126, 100}};
const u16 gUnknown_08edbb9c[4][2] SELECTION_COORDINATES = {
    {12, 56}, {132, 56}, {12, 120}, {132, 120}};
const u16 gUnknown_08edbbac[4][2] SELECTION_COORDINATES = {
    {0, 48}, {120, 48}, {0, 112}, {120, 112}};
#undef SELECTION_COORDINATES
}
