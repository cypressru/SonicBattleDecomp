#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03003140;
/* 156-byte participant records. Offsets 93..146 hold two 27-byte palette
   selections; the byte at 150 chooses between them. */
struct UnknownRecord030013b0 {
    u8 first[93];
    u8 palettes[2][27];
    u8 padding147[3];
    u8 slot;
    u8 padding151[5];
};
extern struct UnknownRecord030013b0 gUnknown_030013b0[];
extern u32 gUnknown_03001380;
extern u8 gUnknown_03002684;
extern u8 gUnknown_030028c0[];
extern u16 gUnknown_030030f8[];
extern u16 gUnknown_03003108[];
extern u16 gUnknown_03003110[];
extern u8 gUnknown_03003120[];
extern u16 gUnknown_03003100[];
extern s16 gUnknown_03003118[];
extern volatile u16 gUnknown_03003178[];

#define REG_BG0CNT (*(volatile u16 *)0x04000008)
#define REG_BG1CNT (*(volatile u16 *)0x0400000a)
#define REG_BG2CNT (*(volatile u16 *)0x0400000c)
#define REG_BG3CNT (*(volatile u16 *)0x0400000e)
#define REG_SIOCNT (*(volatile u32 *)0x04000128)
#define REG_IME (*(volatile u16 *)0x04000208)
extern u8 gUnknown_030016d0;
struct UnknownState03001620 {
    u8 padding0[20];
    u8 activeSlots[113];
};
extern struct UnknownState03001620 gUnknown_03001620;
extern u8 gUnknown_030016a4;
extern u8 gUnknown_0300163c[];
extern u8 gUnknown_030017c0;
extern u8 gUnknown_030017c8;
extern u8 gUnknown_030017cc;
extern s16 gUnknown_030016c8;
extern u8 gUnknown_030016c4;
extern s16 gUnknown_03001b04;
extern s16 gUnknown_03001b08;
extern u16 gUnknown_03001b28;
extern u8 gUnknown_03001390;
extern u8 gUnknown_03001370;
extern s16 gUnknown_03001374;
extern s16 gUnknown_03001b24;
extern s16 gUnknown_03002100;
extern s16 gUnknown_030016bc;
extern s16 gUnknown_030016c0;
extern s16 gUnknown_03001b2c;
extern s16 gUnknown_03001384;
extern s16 FUN_08018390(void);
extern void FUN_0801816c(s16 *outputX, s16 *outputY, s16 inputX, s16 inputY);
extern void FUN_08018204(s16 *outputX, s16 *outputY, s16 factorX, s16 factorY);
extern void FUN_08017f00(u32 first, u32 second, u32 third, u32 fourth);
extern void FUN_080069ac(void);
extern void FUN_0800c1c8(u16 active, u8 mode, s16 x, s16 y, s16 height, u32 sixth, u32 seventh,
                         u32 eighth, u8 field172, u8 index, u8 field149);
extern u16 gUnknown_03003380[][16];
extern u16 gUnknown_03003170;
extern u16 gUnknown_030033cc;

union UnknownQueueEntry08017f00 {
    u32 words[4];
    struct {
        u16 x;
        u16 y;
        u16 height;
        u16 yMinus6;
        u16 tile;
        u8 padding10;
        u8 zero11;
        u8 index;
        u8 type;
        u8 padding14;
        u8 direction;
    } fields;
};

union UnknownQueueEntry08017f34 {
    struct {
        u32 first;
        u32 second;
    } words;
    u16 halves[4];
};

struct UnknownQueueEntry08018004 {
    u16 first;
    u16 second;
    u16 zero;
    u16 constant;
    u16 fourth;
    u8 third;
    u8 sixth;
    u8 fifth;
    u8 seventh;
    u8 eighth;
    u8 ninth;
};

/* The 0x030033E0 queue is written field-wise by FUN_08015F6C and read back a
   word at a time by FUN_08017690, so both views of the record are needed. */
union UnknownQueueRecord030033e0 {
    u32 words[4];
    struct {
        u16 first;
        u16 second;
        s16 zero;
        /* FUN_080175D4 sorts on this field with `ldrsh`, so it is signed. */
        s16 constant;
        u16 fourth;
        u8 third;
        u8 sixth;
        u8 fifth;
        u8 seventh;
        u8 eighth;
        u8 ninth;
    } fields;
};

struct UnknownRecord030017d0 {
    u8 slots[4];
    u8 first;
    u8 second;
    u8 third;
    u8 padding7;
    u16 fourth[4];
    u8 fifth;
    u8 sixth;
    u16 seventh[3];
    u8 eighth;
    u8 padding25;
    u16 ninth;
    s16 tenth[3];
    u16 eleventh[4];
    u16 twelfth[4];
    u8 thirteenth;
    u8 fourteenth;
    u8 fifteenth;
    u8 sixteenth;
    u8 padding54[2];
    u16 seventeenth;
    u16 eighteenth[3];
    u8 nineteenth;
    u8 twentieth;
    u8 twentyfirst;
    u8 padding67;
};

struct UnknownState030030d0 {
    u8 first;
    u8 second;
    u8 padding2[2];
    u16 counter;
    u8 padding6[30];
    u8 flag;
};

struct UnknownEntry03002cd0 {
    u16 first;
    u16 second;
    u16 unused;
    u16 third;
    u16 fourth;
    u8 padding10[2];
    u8 fifth;
    u8 sixth;
    u8 padding14[2];
};

struct UnknownState080180d4 {
    u16 first;
    u16 unused;
    u16 second;
    u16 third;
};

struct UnknownState080180f0 {
    u16 first[10];
    u16 flags[10];
    u16 third[10];
    u8 position;
    u8 padding61[3];
};

struct UnknownRecord03001c40 {
    s16 x;
    s16 y;
    u16 height;
    u8 padding6[6];
    u16 screenX;
    u16 screenY;
    u8 directionMode;
    u8 previousDirection;
    u8 requestedDirection;
    u8 padding19;
    u16 first;
    u8 padding22;
    u8 stateType;
    u8 padding24[4];
    u8 status;
    u8 substatus;
    u8 padding30[6];
    u8 renderMode;
    u8 padding37[15];
    s16 anchorHeight;
    u8 padding54[56];
    u8 midpointMode;
    u8 padding111;
    u8 maximumMode;
    u8 padding113[3];
    u32 field74;
    u8 padding120[5];
    u8 partner;
    u8 padding126[21];
    u8 field147;
    u8 padding148;
    u8 field149;
    u8 second;
    u8 padding151[8];
    u8 style;
    s16 offsetX;
    s16 offsetY;
    u8 padding164[2];
    u16 displacement;
    u16 heightOffset;
    u16 active;
    u8 field172;
    u8 padding173;
    s16 field174;
    s16 field176;
    u8 padding178[2];
    u32 fieldB4;
    u8 padding184[12];
    u8 third;
    u8 padding197[2];
    u8 networkState;
    u16 value;
    u8 padding202[34];
    u8 field236;
    u8 padding237[15];
};

extern union UnknownQueueEntry08017f34 gUnknown_03003190[];
extern union UnknownQueueRecord030033e0 gUnknown_030033e0[];
extern struct UnknownEntry03002cd0 gUnknown_03002cd0[];
extern struct UnknownState030030d0 gUnknown_030030d0;
extern volatile struct UnknownState080180d4 gUnknown_030048e0;
extern struct UnknownState080180f0 gUnknown_03001b30[];
extern struct UnknownRecord03001c40 gUnknown_03001c40[];
extern struct UnknownRecord030017d0 gUnknown_030017d0[];
extern const s16 gUnknown_0804df7c[];
extern const u8 gUnknown_0806b2d4[][10];
extern const u16 gUnknown_0806b2fc[][8];
extern const u16 gUnknown_0847aa18[];
extern const u16 gUnknown_08055800[];
extern const u16 gUnknown_0805587e[];
extern const u16 gUnknown_08055994[];
extern const u16 gUnknown_080559d8[];
extern const u16 gUnknown_080576e8[];

/* The link send slot and the four receive slots. Each receive slot is a
   16-byte record whose first halfword carries the handshake marker. */
struct UnknownState03001b10 {
    s16 first;
    s16 second;
    s16 padding4[5];
    s16 check;
};
extern struct UnknownState03001b10 gUnknown_03001b10;
extern s16 gUnknown_030016f0[][8];
extern u32 gUnknown_030013a4;
extern u32 gUnknown_03001730;
extern u8 gUnknown_030017c4;
extern u32 FUN_08018730(s16 *slots);
extern void FUN_08018c20(void);
extern void FUN_08017964(u8 group);
extern u8 gUnknown_03002cb0;

extern u8 gUnknown_0300138c;
extern u16 gUnknown_03001378;
extern volatile u16 gUnknown_03007ff8;
extern unsigned long long gUnknown_03002610;
extern void MultiSioSyncVSync(void);
extern void FUN_0801f60c(void);
extern void FUN_0801694c(void);
extern void FUN_0801ffa4(u32 first);
extern void FUN_0801fbd8(void);

extern u16 gUnknown_030016b8;
extern u16 gUnknown_030020fc;
extern u16 gUnknown_03001b20;
extern s16 gUnknown_03002b70;
extern s16 gUnknown_03002b74;
extern s16 gUnknown_03002b80;
extern u8 gUnknown_03002b84;
extern s16 gUnknown_03002b90[];
extern s16 gUnknown_03002bd0;
extern u16 gUnknown_03001d0c[][126];
extern void CpuFastSet(const void *source, void *destination, u32 mode);
extern void CpuSet(const void *source, void *destination, u32 mode);
extern s32 DivArm(s32 denominator, s32 numerator);
extern s32 __divsi3(s32 numerator, s32 denominator);
extern void FUN_0800baac(u8 index);
extern u8 FUN_0800b098(u16 animation);
extern void FUN_08020440(u32 first, u16 second, u16 third);
extern void FUN_08016b30(u32 first, u32 second, u32 third, u32 fourth);
extern void FUN_08017690(void);
extern void FUN_08017eec(void);
extern void FUN_08017fb0(void);
extern void FUN_08018004(s16 first, s16 second, u8 third, u16 fourth, u8 fifth, u8 sixth,
                         u8 seventh, u8 eighth, u8 ninth);
extern void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth);
extern void FUN_0801f618(u32 index);
extern void FUN_0801ff30(void);

/* One byte of participant `index`'s selected palette record. */
#define PALETTE(part) (gUnknown_030013b0[index].palettes[gUnknown_030013b0[index].slot][part])

void FUN_080007fc(u8 index) {
    struct UnknownRecord03001c40 *table = gUnknown_03001c40;
    u32 wideIndex = index << 6;
    u32 offset = (wideIndex - index) << 2;
    u8 *record = (u8 *)table + offset;
    u8 *activeRecord;
    u8 *mode = &gUnknown_0300138c;
    u8 byteZero = 0;
    u32 wordZero = 0;

    *(u16 *)(record + 20) = 6;
    *(u16 *)(record + 32) = wordZero;
    *(u16 *)(record + 34) = wordZero;
    record[36] = byteZero;
    record[37] = 4;
    record[16] = byteZero;
    record[17] = byteZero;
    record[18] = byteZero;
    *(u16 *)(record + 38) = wordZero;
    *(u16 *)(record + 40) = wordZero;
    *(u16 *)(record + 42) = wordZero;
    *(u16 *)(record + 44) = wordZero;
    *(u16 *)(record + 46) = wordZero;
    *(u16 *)(record + 48) = wordZero;
    *(u16 *)(record + 4) = 80;
    *(u16 *)(record + 10) = 80;
    record[50] = byteZero;
    *(u16 *)(record + 52) = wordZero;
    *(u32 *)(record + 180) = wordZero;
    record[184] = 2;
    record[143] = byteZero;
    record[142] = byteZero;
    record[145] = byteZero;
    record[146] = byteZero;
    record[159] = byteZero;
    *(u16 *)(record + 160) = wordZero;
    *(u16 *)(record + 162) = wordZero;
    *(u16 *)(record + 164) = 0x0fff;
    *(u16 *)(record + 96) = wordZero;
    *(u16 *)(record + 98) = wordZero;
    *(u16 *)(record + 100) = wordZero;
    record[102] = byteZero;
    *(u16 *)(record + 104) = wordZero;
    record[107] = byteZero;
    record[106] = byteZero;
    record[108] = byteZero;
    record[112] = byteZero;
    record[109] = byteZero;
    record[110] = byteZero;
    record[113] = byteZero;
    record[124] = 0xff;
    *(s8 *)(record + 125) = -1;
    record[126] = byteZero;
    record[185] = byteZero;
    record[186] = byteZero;
    record[187] = byteZero;
    record[191] = gUnknown_03001b28;
    record[192] = byteZero;
    *(u16 *)(record + 194) = wordZero;
    *(u16 *)(record + 24) = wordZero;
    *(u16 *)(record + 26) = wordZero;
    record[28] = byteZero;
    record[29] = byteZero;
    record[30] = byteZero;
    record[23] = record[196];
    record[199] = byteZero;
    record[156] = byteZero;
    record[157] = byteZero;
    record[158] = byteZero;

    {
        u8 i;

        for (i = 0; i <= 9; i++) {
            ((u8 *)table)[offset + 128 + i] = 0;
        }
    }

    activeRecord = (u8 *)&table[index];
    *(u16 *)(activeRecord + 54) = 0;
    *(u16 *)(activeRecord + 62) = 0;
    *(u32 *)(activeRecord + 72) = 0;
    *(u16 *)(activeRecord + 56) = 0;
    *(u16 *)(activeRecord + 64) = 0;
    *(u32 *)(activeRecord + 76) = 0;
    *(u16 *)(activeRecord + 58) = 0;
    *(u16 *)(activeRecord + 66) = 0;
    *(u32 *)(activeRecord + 80) = 0;
    *(u16 *)(activeRecord + 60) = 0;
    *(u16 *)(activeRecord + 68) = 0;
    *(u32 *)(activeRecord + 84) = 0;
    activeRecord[138] = 0;
    activeRecord[127] = 15;
    activeRecord[188] = 0;
    activeRecord[190] = 0;
    *(u16 *)(activeRecord + 166) = 0;
    *(u16 *)(activeRecord + 168) = 0;
    *(u16 *)(activeRecord + 170) = 0;
    activeRecord[172] = 0;
    *(u32 *)(activeRecord + 116) = 0;
    *(u32 *)(activeRecord + 120) = 0;
    *(u16 *)(activeRecord + 174) = 0;
    *(u16 *)(activeRecord + 176) = 0;
    activeRecord[198] = 0;
    *(u16 *)(activeRecord + 240) = 0;
    *(u16 *)(activeRecord + 242) = 0;
    activeRecord[149] = 0;
    activeRecord[244] = 0;
    *(u32 *)(activeRecord + 180) &= 0xffbfffff;

    {
        volatile u8 *state = (volatile u8 *)&gUnknown_03001620;

        if (*mode == 0 || index == gUnknown_03001380 ||
            (index == gUnknown_03001380 + 2 && (state += 28, state[index] != 0))) {
            ((u8 *)&table[index])[199] = 12;
        }
    }
}

void FUN_08000a2c(void) {
    u8 *records;
    const u16 *values;
    u8 i;

    FUN_08017964(0);
    FUN_08017964(1);
    FUN_08017964(2);
    FUN_08017964(3);
    gUnknown_03001b28 = 100;
    for (i = 0; i <= 3; i++) {
        FUN_080007fc(i);
    }

    records = (u8 *)gUnknown_03001c40;
    records[147] = 0;
    records[399] = 0;
    records[651] = 0;
    records[903] = 0;
    records[149] = 0;
    records[401] = 0;
    records[653] = 0;
    records[905] = 0;
    records[150] = 0;
    records[402] = 0;
    records[654] = 0;
    records[906] = 0;
    records[144] = 0;
    records[396] = 0;
    records[648] = 0;
    records[900] = 0;

    values = gUnknown_0806b2fc[gUnknown_03002cb0];
    *(u16 *)(records + 0) = values[0];
    *(u16 *)(records + 6) = values[0];
    *(u16 *)(records + 2) = values[1];
    *(u16 *)(records + 252) = values[2];
    *(u16 *)(records + 254) = values[3];
    *(u16 *)(records + 504) = values[4];
    *(u16 *)(records + 506) = values[5];
    *(u16 *)(records + 756) = values[6];
    *(u16 *)(records + 758) = values[7];
    *(u16 *)(records + 8) = values[1];
    *(u16 *)(records + 258) = values[2];
    *(u16 *)(records + 260) = values[3];
    *(u16 *)(records + 510) = values[4];
    *(u16 *)(records + 512) = values[5];
    *(u16 *)(records + 762) = values[6];
    *(u16 *)(records + 764) = values[7];

    *(u16 *)(records + 152) = 0;
    *(u16 *)(records + 404) = 0;
    *(u16 *)(records + 656) = 0;
    *(u16 *)(records + 908) = 0;
    records[154] = 0;
    records[406] = 0;
    records[658] = 0;
    records[910] = 0;
    records[155] = 0;
    records[407] = 0;
    records[659] = 0;
    records[911] = 0;
    records[141] = 0;
    records[393] = 0;
    records[645] = 0;
    records[897] = 0;
    records[236] = 0;
    records[488] = 0;
    records[740] = 0;
    records[992] = 0;
    *(u16 *)(records + 238) = 0;
    *(u16 *)(records + 490) = 0;
    *(u16 *)(records + 742) = 0;
    *(u16 *)(records + 994) = 0;

    records[36] = 6;
    records[288] = 4;
    records[540] = 6;
    records[792] = 4;
    records[37] = 6;
    records[289] = 4;
    records[541] = 6;
    records[793] = 4;
    records[16] = 1;
    records[268] = 0;
    records[520] = 1;
    records[772] = 0;
    records[18] = 1;
    records[270] = 0;
    records[522] = 1;
    records[774] = 0;
}

/* Rebuilds participant `index`'s palette entries 3..13 from the colour table
   at 0x0847AA18, leaving the rest of the stored palette alone. Entries 3-6,
   7-10 and 11-13 each take their colour set from a different byte of the
   participant's selected 27-byte palette record. */
void FUN_080016c4(u8 index) {
    u16 buffer[16];

    CpuSet(gUnknown_03001d0c[index], buffer, 16);
    buffer[3] = gUnknown_0847aa18[PALETTE(0) * 16 + 3];
    buffer[4] = gUnknown_0847aa18[PALETTE(0) * 16 + 4];
    buffer[5] = gUnknown_0847aa18[PALETTE(0) * 16 + 5];
    buffer[6] = gUnknown_0847aa18[PALETTE(0) * 16 + 6];
    buffer[7] = gUnknown_0847aa18[PALETTE(1) * 16 + 7];
    buffer[8] = gUnknown_0847aa18[PALETTE(1) * 16 + 8];
    buffer[9] = gUnknown_0847aa18[PALETTE(1) * 16 + 9];
    buffer[10] = gUnknown_0847aa18[PALETTE(1) * 16 + 10];
    buffer[11] = gUnknown_0847aa18[PALETTE(2) * 16 + 11];
    buffer[12] = gUnknown_0847aa18[PALETTE(2) * 16 + 12];
    buffer[13] = gUnknown_0847aa18[PALETTE(2) * 16 + 13];
    CpuSet(buffer, gUnknown_03001d0c[index], 16);
}

/* Uploads participant `index`'s 16-colour palette. Normally the stored palette
   is DMAed straight to 0x05000200; when the caller asks for the highlight and
   the effect is enabled, each entry is brightened first - blue and green
   doubled, red tripled, every channel clamped to 31. */
void FUN_08000cf4(u8 index, u8 first, u8 second) {
    volatile u32 *dma;
    volatile u32 *other;
    u16 buffer[16];
    u32 colour;
    u32 red;
    u32 green;
    u32 blue;
    u8 i;

    gUnknown_03001c40[index].third = first;
    if (second != 0 && (gUnknown_030016b8 & 4) && gUnknown_03001c40[index].first != 254 &&
        gUnknown_03001c40[index].first != 255) {
        for (i = 1; i <= 15; i++) {
            colour = gUnknown_03001d0c[index][i];
            blue = ((colour << 16) >> 26) & 31;
            green = ((colour << 16) >> 21) & 31;
            red = colour & 31;
            blue = blue * 2;
            green = green * 2;
            red = red + red * 2;
            if (blue > 31) {
                blue = 31;
            }
            if (green > 31) {
                green = 31;
            }
            if (red > 31) {
                red = 31;
            }
            buffer[i] = (blue << 10) | (green << 5) | red;
        }
        gUnknown_03001c40[index].second = 1;
        dma = (volatile u32 *)0x040000d4;
        dma[0] = (u32)buffer;
        dma[1] = 0x05000200 + index * 32;
        dma[2] = 0x80000010;
        dma[2];
    } else {
        other = (volatile u32 *)0x040000d4;
        other[0] = (u32)gUnknown_03001d0c[index];
        other[1] = 0x05000200 + index * 32;
        other[2] = 0x80000010;
        other[2];
    }
}

/* The buttons currently held by participant `index`, taken from the newest
   slot of that participant's input ring. */
#define HELD_BUTTONS (gUnknown_03001b30[index].first[gUnknown_03001b30[index].position])

/* Selects one of the ten columns of the 0x0806B2D4 move table for the
   participant's fighting style, according to the buttons held. */
u8 FUN_080034f0(u8 index) {
    u8 result;

    if ((HELD_BUTTONS & 0x20) && (HELD_BUTTONS & 0x80)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][1];
    } else if ((HELD_BUTTONS & 0x10) && (HELD_BUTTONS & 0x80)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][3];
    } else if ((HELD_BUTTONS & 0x20) && (HELD_BUTTONS & 0x40)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][7];
    } else if ((HELD_BUTTONS & 0x10) && (HELD_BUTTONS & 0x40)) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][9];
    } else if (HELD_BUTTONS & 0x80) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][2];
    } else if (HELD_BUTTONS & 0x20) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][4];
    } else if (HELD_BUTTONS & 0x10) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][6];
    } else if (HELD_BUTTONS & 0x40) {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][8];
    } else {
        result = gUnknown_0806b2d4[gUnknown_03001c40[index].style][0];
    }
    return result;
}

void FUN_080066d8(void) {
    u8 i;
    u32 base;
    u32 flagsBase;
    u32 flagsAddress;
    u32 fieldAddress;
    u32 offset;
    u32 *field74;
    u32 flagValue;
    u32 mask;

    i = 0;
    base = (u32)gUnknown_03001c40;
    flagsBase = base + 0xB4;
    do {
        offset = (i * 63) << 2;
        fieldAddress = base + 0x74;
        field74 = (u32 *)(offset + fieldAddress);

        if ((*field74 & 0x1F00) == 0x900) {
            flagsAddress = offset + flagsBase;
            flagValue = *(u32 *)flagsAddress;
            mask = 0x1000000;
            if ((flagValue & mask) == 0) {
                goto setFlag;
            }
        }
        *field74 = 0;
        offset += flagsBase;
        *(u32 *)offset &= ~0x1000000;
        goto next;

    setFlag:
        *(u32 *)flagsAddress = flagValue | mask;
    next:
        i++;
    } while (i <= 3);
}

void FUN_0800673c(u8 index) {
    struct UnknownRecord03001c40 *initialRecords;
    struct UnknownRecord03001c40 *records;
    struct UnknownRecord03001c40 *record;
    u32 initialScaledIndex;
    u32 scaledIndex;
    u8 midpointMode;
    s16 angle;

    if (index > 3) {
        return;
    }

    initialRecords = gUnknown_03001c40;
    initialScaledIndex = index << 6;
    record =
        (struct UnknownRecord03001c40 *)((u32)initialRecords + ((initialScaledIndex - index) << 2));
    midpointMode = record->midpointMode;
    records = initialRecords;
    scaledIndex = initialScaledIndex;
    if (midpointMode != 0) {
        switch (record->partner) {
        case 0:
            gUnknown_03001374 = (record->x + gUnknown_03001c40[0].x) >> 1;
            gUnknown_03001b24 = (record->y + gUnknown_03001c40[0].y) >> 1;
            break;
        case 1:
            gUnknown_03001374 = (record->x + gUnknown_03001c40[1].x) >> 1;
            gUnknown_03001b24 = (record->y + gUnknown_03001c40[1].y) >> 1;
            break;
        case 2:
            gUnknown_03001374 = (record->x + gUnknown_03001c40[2].x) >> 1;
            gUnknown_03001b24 = (record->y + gUnknown_03001c40[2].y) >> 1;
            break;
        case 3:
            gUnknown_03001374 = (record->x + gUnknown_03001c40[3].x) >> 1;
            gUnknown_03001b24 = (record->y + gUnknown_03001c40[3].y) >> 1;
            break;
        default:
            break;
        }
        gUnknown_03002100 =
            ((struct UnknownRecord03001c40 *)((u32)records + ((scaledIndex - index) << 2)))->height
            << 1;
    } else if (record->maximumMode != 0) {
        switch (record->partner) {
        case 0:
            if ((s16)record->height > (s16)gUnknown_03001c40[0].height) {
                gUnknown_03002100 = record->height << 1;
            } else {
                gUnknown_03002100 = gUnknown_03001c40[0].height << 1;
            }
            break;
        case 1:
            if ((s16)record->height > (s16)gUnknown_03001c40[1].height) {
                gUnknown_03002100 = record->height << 1;
            } else {
                gUnknown_03002100 = gUnknown_03001c40[1].height << 1;
            }
            break;
        case 2:
            if ((s16)record->height > (s16)gUnknown_03001c40[2].height) {
                gUnknown_03002100 = record->height << 1;
            } else {
                gUnknown_03002100 = gUnknown_03001c40[2].height << 1;
            }
            break;
        case 3:
            if ((s16)record->height > (s16)gUnknown_03001c40[3].height) {
                gUnknown_03002100 = record->height << 1;
            } else {
                gUnknown_03002100 = gUnknown_03001c40[3].height << 1;
            }
            break;
        default:
            break;
        }
        gUnknown_03001374 =
            ((struct UnknownRecord03001c40 *)((u32)records + ((scaledIndex - index) << 2)))->x;
        gUnknown_03001b24 =
            ((struct UnknownRecord03001c40 *)((u32)records + ((scaledIndex - index) << 2)))->y;
    } else {
        gUnknown_03001374 = record->x;
        gUnknown_03001b24 = record->y;
        gUnknown_03002100 = record->height << 1;
    }
    angle = FUN_08018390();
    if ((u16)(angle - 0x400) > 0x1800) {
        gUnknown_03001370 = 0;
    } else if ((u16)(angle - 0x401) <= 0x7FE) {
        gUnknown_03001370 = 2;
    } else if ((u16)(angle - 0xC01) <= 0x7FE) {
        gUnknown_03001370 = 1;
    } else if ((u16)(angle - 0x1401) <= 0x7FE) {
        gUnknown_03001370 = 3;
    }
}

void FUN_08006e64(void) {
    u8 index;

    index = 0;
    do {
        if (gUnknown_03001c40[index].active != 0 && gUnknown_03001620.activeSlots[index] != 0xFF) {
            s16 xOffset = 0;
            s16 yOffset = 0;

            switch (gUnknown_03001c40[index].renderMode) {
            case 0:
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
                if (gUnknown_03001c40[index].directionMode == 0) {
                    if (gUnknown_03001c40[index].style == 0) {
                        xOffset = gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 1) {
                        xOffset = -gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 2) {
                        yOffset = gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 3) {
                        yOffset = -gUnknown_03001c40[index].displacement;
                    }
                } else {
                    if (gUnknown_03001c40[index].style == 0) {
                        xOffset = -gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 1) {
                        xOffset = gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 2) {
                        yOffset = -gUnknown_03001c40[index].displacement;
                    } else if (gUnknown_03001c40[index].style == 3) {
                        yOffset = gUnknown_03001c40[index].displacement;
                    }
                }
                break;
            case 4:
                xOffset = gUnknown_03001c40[index].displacement;
                break;
            case 6:
                xOffset = -gUnknown_03001c40[index].displacement;
                break;
            case 8:
                yOffset = gUnknown_03001c40[index].displacement;
                break;
            case 2:
                yOffset = -gUnknown_03001c40[index].displacement;
                break;
            default:
                break;
            }
            FUN_0800c1c8(gUnknown_03001c40[index].active, gUnknown_03001c40[index].renderMode,
                         gUnknown_03001c40[index].x + xOffset, gUnknown_03001c40[index].y + yOffset,
                         gUnknown_03001c40[index].height + gUnknown_03001c40[index].heightOffset, 0,
                         0, 0, gUnknown_03001c40[index].field172, index,
                         gUnknown_03001c40[index].field149);
            gUnknown_03001c40[index].field172 = 0;
            gUnknown_03001c40[index].active = 0;
        }
        index++;
    } while (index <= 3);
}

#define PACK_HALVES(low, high) ((u16)(low) | ((u32)(u16)(high) << 16))

void FUN_08006ff4(u8 count) {
    union UnknownQueueEntry08017f00 entry;
    u32 originalX;
    u32 originalY;
    s16 x;
    s16 y;
    u8 index;

#define SUBMIT_QUEUE(px, py, ptile, ptype)                                                         \
    do {                                                                                           \
        entry.fields.x = (px);                                                                     \
        entry.fields.y = (py);                                                                     \
        entry.fields.tile = (ptile);                                                               \
        entry.fields.type = (ptype);                                                               \
        FUN_08017f00(entry.words[0], entry.words[1], entry.words[2], entry.words[3]);              \
    } while (0)
#define record (&gUnknown_03001c40[index])
    entry.fields.zero11 = 0;
    index = 0;
    while (index < count) {
        u16 identifier = record->first;

        if (identifier != 254 && (identifier != 255 || index == gUnknown_03001380) &&
            (record->stateType != 2 || identifier != 0x116 || index == gUnknown_03001380) &&
            (record->stateType != 3 || identifier != 0x115 || index == gUnknown_03001380) &&
            gUnknown_03001620.activeSlots[index] != 0xFF) {
            FUN_0801816c(&x, &y, record->x, record->y);
            FUN_08018204(&x, &y, x, y);
            entry.fields.yMinus6 = y - 6;
            originalX = (u16)(x - 16);
            originalY = (u16)(y - 4);

            switch (record->directionMode) {
            case 0:
                x = x - (record->offsetX + 24);
                y = (record->offsetY - 40) + y;
                break;
            case 1:
                x = x + (record->offsetX - 24);
                y = (record->offsetY - 40) + y;
                break;
            }

            record->screenX = x;
            record->screenY = y - record->height;
            if ((u16)(x + 64) <= 304 && (s16)record->screenY <= gUnknown_030017c0 &&
                (s16)record->screenY >= gUnknown_030016d0 - 64) {
                u16 tile = (u16)index * 36;

                entry.fields.index = index;
                entry.fields.direction = record->directionMode;
                entry.fields.height = record->height;

                switch (record->directionMode) {
                case 0:
                    SUBMIT_QUEUE(x, y, tile, 11);
                    SUBMIT_QUEUE(x, y + 32, tile + 16, 12);
                    SUBMIT_QUEUE(x + 32, y, tile + 24, 13);
                    SUBMIT_QUEUE(x + 32, y + 32, tile + 32, 14);
                    break;
                case 1:
                    SUBMIT_QUEUE(x, y, tile + 24, 13);
                    SUBMIT_QUEUE(x, y + 32, tile + 32, 14);
                    SUBMIT_QUEUE(x + 16, y, tile, 11);
                    SUBMIT_QUEUE(x + 16, y + 32, tile + 16, 12);
                    break;
                }
            }

            if ((u16)(x + 64) <= 304 && (s16)y <= gUnknown_030017c0 &&
                (s16)y >= gUnknown_030016d0 - 64 && record->first != 255) {
                s16 indicator;

                if ((s16)record->height < record->anchorHeight + 20) {
                    indicator = 0;
                } else if ((s16)record->height < record->anchorHeight + 40) {
                    indicator = 1;
                } else if ((s16)record->height < record->anchorHeight + 60) {
                    indicator = 2;
                } else {
                    indicator = 3;
                }
                entry.fields.x = originalX;
                entry.fields.y = originalY;
                entry.fields.height = record->anchorHeight;
                entry.fields.index = 4;
                entry.fields.tile = indicator * 8 + 0x90;
                entry.fields.type = 0x14;
                FUN_08017f00(entry.words[0], entry.words[1], entry.words[2], entry.words[3]);
            }
        }

        record->previousDirection = record->directionMode;
        record->directionMode = record->requestedDirection;
        if (record->first != 0x37 || gUnknown_0300138c == 0 || index == gUnknown_03001380 ||
            (index == gUnknown_03001380 + 2 && gUnknown_0300163c[index] != 0)) {
            switch (gUnknown_03001370) {
            case 0:
                if (record->renderMode == 4 || record->renderMode == 7 || record->renderMode == 1) {
                    record->requestedDirection = 0;
                } else if (record->renderMode == 6 || record->renderMode == 9 ||
                           record->renderMode == 3) {
                    record->requestedDirection = 1;
                }
                break;
            case 1:
                if (record->renderMode == 4 || record->renderMode == 7 || record->renderMode == 1) {
                    record->requestedDirection = 1;
                } else if (record->renderMode == 6 || record->renderMode == 9 ||
                           record->renderMode == 3) {
                    record->requestedDirection = 0;
                }
                break;
            case 2:
                if ((u8)(record->renderMode - 1) < 3) {
                    record->requestedDirection = 0;
                } else if ((u8)(record->renderMode - 7) < 3) {
                    record->requestedDirection = 1;
                }
                break;
            case 3:
                if ((u8)(record->renderMode - 1) < 3) {
                    record->requestedDirection = 1;
                } else if ((u8)(record->renderMode - 7) < 3) {
                    record->requestedDirection = 0;
                }
                break;
            }
        }
        index++;
    }
    FUN_080069ac();
#undef record
#undef SUBMIT_QUEUE
}

#undef PACK_HALVES

void FUN_08007e24(void) {
    volatile u32 *dma;

    dma = (volatile u32 *)0x040000d4;
    dma[0] = 0x0847ab98;
    dma[1] = 0x05000280;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = 0x0847abb8;
    dma[1] = 0x06011200;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847acb8;
    dma[1] = 0x06011300;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847adb8;
    dma[1] = 0x06011400;
    dma[2] = 0x80000080;
    dma[2];
    dma[0] = 0x0847aeb8;
    dma[1] = 0x06011500;
    dma[2] = 0x80000080;
    dma[2];
}

void FUN_08007e9c(u8 index) {
    u8 i;

    for (i = 0; i <= 68; i++) {
        gUnknown_030013b0[index].first[i] = 9;
    }
}

void FUN_0800baac(u8 index) {
    struct UnknownRecord030017d0 *record;
    struct UnknownRecord030017d0 *table;

    table = gUnknown_030017d0;
    record = table + index;
    if (record->slots[0] != 255) {
        gUnknown_030028c0[record->slots[0]] = 0;
    }
    if (record->slots[1] != 255) {
        gUnknown_030028c0[record->slots[1]] = 0;
    }
    if (record->slots[2] != 255) {
        gUnknown_030028c0[record->slots[2]] = 0;
    }
    if (record->slots[3] != 255) {
        gUnknown_030028c0[record->slots[3]] = 0;
    }
    record->fifteenth = 255;
    record->slots[0] = -1;
    record->slots[1] = -1;
    record->slots[2] = -1;
    record->slots[3] = -1;
    record->first = 0;
    record->nineteenth = 0;
    record->second = 0;
    record->third = 0;
    record->fourth[0] = 0;
    record->fourth[1] = 0;
    record->fourth[2] = 0;
    record->fourth[3] = 0;
    record->eighteenth[0] = 0;
    record->eighteenth[1] = 0;
    record->eighteenth[2] = 0;
    record->fifth = 0;
    record->sixth = 0;
    record->seventh[0] = 0;
    record->seventh[1] = 0;
    record->seventh[2] = 0;
    record->eighth = 0;
    record->ninth = 0xffff;
    record->tenth[0] = -1;
    record->tenth[1] = -1;
    record->tenth[2] = -1;
    record->eleventh[0] = 0;
    record->twelfth[0] = 0;
    record->eleventh[1] = 0;
    record->twelfth[1] = 0;
    record->eleventh[2] = 0;
    record->twelfth[2] = 0;
    record->eleventh[3] = 0;
    record->twelfth[3] = 0;
    record->seventeenth = 0;
    record->sixteenth = 8;
    record->fourteenth = 0;
    record->thirteenth = 1;
    record->twentieth = 0;
    record->twentyfirst = 0;
}

void FUN_0800fd8c(void) {
    u8 i;

    for (i = 0; i <= 11; i++) {
        FUN_0800baac(i);
    }
    for (i = 0; i <= 26; i++) {
        gUnknown_030028c0[i] = 0;
    }
    gUnknown_03002684 = 0;
}

void FUN_08012b60(void) {
    u8 i;

    gUnknown_030030d0.flag = 0;
    for (i = 0; i <= 63; i++) {
        gUnknown_03002cd0[i].first = 0;
        gUnknown_03002cd0[i].second = 0;
        gUnknown_03002cd0[i].third = 0;
        gUnknown_03002cd0[i].fourth = 0;
        gUnknown_03002cd0[i].fifth = 0;
        gUnknown_03002cd0[i].sixth = 0;
    }
}

u8 FUN_080125dc(u16 *horizontal, u16 *vertical, u16 *boundaryX, u16 *boundaryY, s16 x, s16 y) {
    s16 distancesX[2];
    s16 distancesY[2];
    u8 result;
    u8 i;

    result = 0;
    *horizontal = result;
    *vertical = result;
    *boundaryX = result;
    *boundaryY = result;

    for (i = result; i < gUnknown_03002b84; i += 4) {
        u8 horizontalSide;
        u8 verticalSide;
        s32 horizontalDistance;
        s32 verticalDistance;
        s32 firstDistance;
        s32 secondDistance;

        if (gUnknown_03002b90[i] < x && x < gUnknown_03002b90[i + 1] &&
            gUnknown_03002b90[i + 2] < y && y < gUnknown_03002b90[i + 3]) {
            distancesX[0] = x - gUnknown_03002b90[i];
            distancesX[1] = x - gUnknown_03002b90[i + 1];
            distancesY[0] = y - gUnknown_03002b90[i + 2];
            distancesY[1] = y - gUnknown_03002b90[i + 3];

            firstDistance = distancesX[0];
            if (firstDistance < 0) {
                firstDistance = -firstDistance;
            }
            secondDistance = distancesX[1];
            if (secondDistance < 0) {
                secondDistance = -secondDistance;
            }
            horizontalSide = 1;
            if (firstDistance < secondDistance) {
                horizontalSide = 0;
            }
            firstDistance = distancesY[0];
            if (firstDistance < 0) {
                firstDistance = -firstDistance;
            }
            secondDistance = distancesY[1];
            if (secondDistance < 0) {
                secondDistance = -secondDistance;
            }
            verticalSide = 3;
            if (firstDistance < secondDistance) {
                verticalSide = 2;
            }

            result |= 1 << horizontalSide;
            result |= 1 << verticalSide;
            horizontalDistance = distancesX[horizontalSide];
            if (horizontalDistance < 0) {
                horizontalDistance = -horizontalDistance;
            }
            verticalDistance = distancesY[verticalSide - 2];
            if (verticalDistance < 0) {
                verticalDistance = -verticalDistance;
            }
            if (horizontalDistance < verticalDistance) {
                *horizontal = distancesX[horizontalSide];
            } else {
                *vertical = distancesY[verticalSide - 2];
            }
        }
    }

    if (x > gUnknown_03002b74) {
        *boundaryX = x - gUnknown_03002b74;
        result |= 0x10;
    } else if (x < gUnknown_03002bd0) {
        *boundaryX = x - gUnknown_03002bd0;
        result |= 0x20;
    }
    if (y > gUnknown_03002b80) {
        *boundaryY = y - gUnknown_03002b80;
        result |= 0x40;
    } else if (y < gUnknown_03002b70) {
        *boundaryY = y - gUnknown_03002b70;
        result |= 0x80;
    }
    return result;
}

#define BUTTON_STATE                                                                               \
    gUnknown_03001b30[gUnknown_03001380].flags[gUnknown_03001b30[gUnknown_03001380].position]

u8 FUN_080153e0(void) {
    if (gUnknown_030030d0.counter <= 0x1fff) {
        gUnknown_030030d0.counter += 0x200;
    } else {
        gUnknown_030030d0.counter -= 0x2000;
    }
    if ((BUTTON_STATE & 0x40) || (BUTTON_STATE & 0x80)) {
        gUnknown_030030d0.second ^= 1;
        FUN_0801f618(600);
    }
    if (BUTTON_STATE & 1) {
        FUN_0801f618(601);
        return gUnknown_030030d0.second;
    }
    if (BUTTON_STATE & 8) {
        FUN_0801f618(601);
        return 0;
    }
    return 255;
}

void FUN_080163c0(u8 layer) {
    u8 index;
    volatile u16 value;

    index = layer;
    gUnknown_03003178[index] = 0;
    value = 0;
    gUnknown_03003178[index] |= value;
    switch (index) {
    case 0:
        REG_BG0CNT = gUnknown_03003178[0];
        break;
    case 1:
        REG_BG1CNT = gUnknown_03003178[1];
        break;
    case 2:
        REG_BG2CNT = gUnknown_03003178[2];
        break;
    case 3:
        REG_BG3CNT = gUnknown_03003178[3];
        break;
    }
}

void FUN_08016438(u16 originX, u16 originY, s16 firstDenominator, u16 secondDenominator, u8 scaleX,
                  u8 scaleY, u16 angle, u8 matrixIndex) {
    u16 pa;
    u16 pb;
    u16 pc;
    u16 pd;
    s32 x;
    s32 y;

    pa = scaleX * DivArm(firstDenominator, gUnknown_0804df7c[angle + 0x800] << 3);
    pb = scaleY * DivArm(firstDenominator, gUnknown_0804df7c[angle] << 3);
    pc = scaleX * -DivArm((s16)secondDenominator, gUnknown_0804df7c[angle] << 3);
    pd = DivArm((s16)secondDenominator, gUnknown_0804df7c[angle + 0x800] << 3) * scaleY;
    x = 0x8000 - (s16)pa * (s16)originX - (s16)pb * (s16)originY;
    y = 0x8000 - (s16)pc * (s16)originX - (s16)pd * (s16)originY;

    switch (matrixIndex) {
    case 2:
        gUnknown_03003380[gUnknown_03003140 ^ 1][0] = pa;
        gUnknown_03003380[gUnknown_03003140 ^ 1][1] = pb;
        gUnknown_03003380[gUnknown_03003140 ^ 1][2] = pc;
        gUnknown_03003380[gUnknown_03003140 ^ 1][3] = pd;
        gUnknown_03003380[gUnknown_03003140 ^ 1][4] = x;
        gUnknown_03003380[gUnknown_03003140 ^ 1][5] = (x & 0x0fff0000) >> 16;
        gUnknown_03003380[gUnknown_03003140 ^ 1][6] = y;
        gUnknown_03003380[gUnknown_03003140 ^ 1][7] = (y & 0x0fff0000) >> 16;
        break;
    case 3:
        gUnknown_03003380[gUnknown_03003140 ^ 1][8] = pa;
        gUnknown_03003380[gUnknown_03003140 ^ 1][9] = pb;
        gUnknown_03003380[gUnknown_03003140 ^ 1][10] = pc;
        gUnknown_03003380[gUnknown_03003140 ^ 1][11] = pd;
        gUnknown_03003380[gUnknown_03003140 ^ 1][12] = x;
        gUnknown_03003380[gUnknown_03003140 ^ 1][13] = (x & 0x0fff0000) >> 16;
        gUnknown_03003380[gUnknown_03003140 ^ 1][14] = y;
        gUnknown_03003380[gUnknown_03003140 ^ 1][15] = (y & 0x0fff0000) >> 16;
        break;
    }
}

u8 FUN_08015384(void) {
    u16 previous;

    previous = gUnknown_030030d0.counter;
    gUnknown_030030d0.counter = previous + 1;
    if (previous >= 60 && previous <= 0xed6) {
        if (gUnknown_030048e0.second & 8) {
            gUnknown_030030d0.counter = 0xed8;
        }
    }
    if (gUnknown_030030d0.counter > 0xf00) {
        return 2;
    }
    if (gUnknown_030030d0.counter > 0xed8) {
        return 1;
    }
    return 0;
}

u8 FUN_08015858(void) {
    const u8 *source;

    gUnknown_030030d0.counter++;
    if (gUnknown_030030d0.counter == 27) {
        FUN_0801f618(46);
    } else if (gUnknown_030030d0.counter == 88) {
        source = (const u8 *)0x0831ed34;
        CpuFastSet(source, (void *)0x06016800, 0x200);
        source += 0x800;
        CpuFastSet(source, (void *)0x06017000, 0x200);
    }
    if (gUnknown_030030d0.counter > 103) {
        return 1;
    }
    return 0;
}

u8 FUN_0801584c(void) { return gUnknown_030030d0.first; }

void FUN_080158e4(void) {
    gUnknown_03003108[0] = 0;
    gUnknown_03003108[1] = 0;
    gUnknown_03003108[2] = 0;
    gUnknown_03003108[3] = 0;
    gUnknown_03003110[0] = 0;
    gUnknown_03003110[1] = 0;
    gUnknown_03003110[2] = 0;
    gUnknown_03003110[3] = 0;
    gUnknown_030030f8[0] = 0;
    gUnknown_030030f8[1] = 0;
    gUnknown_030030f8[2] = 0;
    gUnknown_030030f8[3] = 0;
    gUnknown_03003120[0] = 0;
    gUnknown_03003120[1] = 0;
    gUnknown_03003120[2] = 0;
    gUnknown_03003120[3] = 0;
}

/* Advances one slot's packed animation command stream. Commands use their
   upper halfword as an opcode and their lower halfword as the frame/value. */
u8 FUN_08015924(u8 character, u16 animation, u8 direction, u16 sound, u8 slot) {
    const u32 *commands;
    u32 command;
    u32 opcode;
    u32 resource;
    const u8 *commandTable;
    u16 commandIndex;
    u8 animationIndex;
    u32 remapped;
    u8 *activeSlot;

#define ACTIVE_SLOT (activeSlot = (u8 *)&gUnknown_03001620, activeSlot += 24, activeSlot[slot])

    resource = 0;
    if (character != 9) {
        goto not_remapped;
    }
    remapped = 1;
    commandTable = (const u8 *)gUnknown_030013b0;
    character = gUnknown_030013b0[slot].first[FUN_0800b098(animation)];
    goto animation_ready;

invalid_stream:
    gUnknown_03003110[slot] = 0;
    gUnknown_03003108[slot] = 1 - direction;
    return 0xff;

not_remapped:
    remapped = 0;
    commandTable = (const u8 *)0x0868eda8;

animation_ready:

    animationIndex = FUN_0800b098(animation);
    commands = *(const u32 *const *)(character * 0x118 + animationIndex * 4 + (u32)commandTable);

    if (gUnknown_030030f8[slot] != animation || gUnknown_03003120[slot] != character ||
        (s16)gUnknown_03003108[slot] == 0) {
        gUnknown_030030f8[slot] = animation;
        gUnknown_03003120[slot] = character;
        gUnknown_03003108[slot] = 0;
        gUnknown_03003110[slot] = 0;
        gUnknown_03003100[slot] = 0;
        gUnknown_03003118[slot] = 0;
    }

    if ((s16)gUnknown_03003108[slot] < 0) {
        goto advance_frame;
    }

    {
        u16 *scanIndex = &gUnknown_03003110[slot];
        u32 sentinel;
        u32 mask;
        u32 header;

        header = commands[*scanIndex];
        mask = 0xffff0000;
        header &= mask;
        sentinel = 0xfff00000;
        if (header != sentinel) {
            u16 *cursor = scanIndex;
            u32 loopSentinel = sentinel;

            do {
                (*cursor)++;
                if (*cursor > 0xfe) {
                    return 0xff;
                }
            } while ((commands[*cursor] & mask) != loopSentinel);
        }
    }

    commandIndex = gUnknown_03003110[slot];
    if ((u16)commands[commandIndex] != (s16)gUnknown_03003108[slot]) {
        goto advance_frame;
    }

    gUnknown_03003110[slot] = commandIndex + 1;
    while ((commands[gUnknown_03003110[slot]] & 0xffff0000) != 0xfff00000) {
        command = commands[gUnknown_03003110[slot]];
        opcode = command & 0xffff0000;
        if (opcode == 0x11000000) {
            goto opcode_110;
        }
        if (opcode <= 0x11000000) {
            if (opcode == 0x00f00000) {
                goto loop_command;
            }
            if (opcode == 0x10000000) {
                goto sprite_command;
            }
            goto command_done;
        }
        if (opcode == 0x12000000) {
            goto opcode_120;
        }
        if (opcode == 0xfffe0000) {
            goto loop_command;
        }
        goto command_done;

    opcode_110:
        gUnknown_03003100[slot] = command;
        goto command_done;

    opcode_120:
        gUnknown_03003118[slot] = command;
        goto command_done;

    sprite_command:
        switch (character) {
        case 0:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x08787d18 : 0x0847afd8;
            break;
        case 1:
        case 10:
        case 11:
        case 21:
            resource = 0x08787d18;
            break;
        case 2:
        case 22:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x08835158 : 0x08528418;
            break;
        case 3:
        case 23:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x087d7b38 : 0x084cadf8;
            break;
        case 4:
        case 24:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x0889a578 : 0x0858d838;
            break;
        case 5:
        case 25:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x08900b98 : 0x085f3e58;
            break;
        case 6:
        case 26:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x089431b8 : 0x08636478;
            break;
        case 7:
        case 27:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x08a037f8 : 0x086f6ab8;
            break;
        case 8:
        case 28:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x0898e7d8 : 0x08681a98;
            break;
        case 9:
            resource = ACTIVE_SLOT || remapped == 1 ? 0x08a40418 : 0x087336d8;
            break;
        default:
            break;
        }

        if (character == 1) {
            if (animation == 19) {
                gUnknown_03003100[slot] = gUnknown_08055800[(s16)command - 172] - 8;
                gUnknown_03003118[slot] = gUnknown_0805587e[(s16)command - 172];
            } else if (animation == 20) {
                gUnknown_03003100[slot] = gUnknown_08055994[(s16)command - 236] - 8;
                gUnknown_03003118[slot] = gUnknown_080559d8[(s16)command - 236];
            }
        } else if (character == 2 && animation == 21) {
            gUnknown_03003100[slot] = gUnknown_080576e8[(s16)command - 184];
        }
        FUN_08020440(resource, sound, command);
        goto command_done;

    loop_command:
        if ((s16)gUnknown_03003108[slot] == 0) {
            goto invalid_stream;
        }
        gUnknown_03003110[slot] = 0;
        gUnknown_03003108[slot] = 1 - direction;
        return 0;

    command_done:
        gUnknown_03003110[slot]++;
        if (gUnknown_03003110[slot] > 0xfe) {
            return 0xff;
        }
    }

advance_frame:
    gUnknown_03003108[slot]++;
#undef ACTIVE_SLOT
    return 1;
}

/* Bubble-sorts the live part of the 0x030033E0 queue into descending order of
   the halfword at offset 6, so FUN_08017690 submits records back to front. */
void FUN_080175d4(void) {
    union UnknownQueueRecord030033e0 temp;
    u8 i;
    u8 j;
    u8 pass;

    pass = 1;
    for (i = gUnknown_030017c8 + 1; i < gUnknown_030017cc; i++) {
        for (j = gUnknown_030017c8; j < gUnknown_030017cc - pass; j++) {
            if (gUnknown_030033e0[j].fields.constant < gUnknown_030033e0[j + 1].fields.constant) {
                temp = gUnknown_030033e0[j];
                gUnknown_030033e0[j] = gUnknown_030033e0[j + 1];
                gUnknown_030033e0[j + 1] = temp;
            }
        }
        pass++;
    }
}

void FUN_08017690(void) {
    u8 i;
    union UnknownQueueRecord030033e0 *record;

    for (i = 0; i < gUnknown_030017cc; i++) {
        if (i >= gUnknown_030017c8) {
            if (gUnknown_030033e0[i].fields.zero > 29) {
                gUnknown_030033e0[i].fields.third = 2;
            } else {
                gUnknown_030033e0[i].fields.third = 3;
            }
        }
        record = &gUnknown_030033e0[i];
        FUN_08016b30(record->words[0], record->words[1], record->words[2], record->words[3]);
    }
}

/* Eases 0x03001B08 towards a target angle on a 0x2000-unit circle, taking the
   short way round and renormalising both the argument and the result. */
void FUN_080176e4(s16 target) {
    while (target > 0x2000) {
        target -= 0x2000;
    }
    while (target < 0) {
        target += 0x2000;
    }
    if (gUnknown_03001b08 - target > 0x1000) {
        gUnknown_03001b08 -= 0x2000;
    } else if (gUnknown_03001b08 - target < -0x1000) {
        gUnknown_03001b08 += 0x2000;
    }
    gUnknown_03001b08 -= (gUnknown_03001b08 - target) >> 3;
    while (gUnknown_03001b08 > 0x1fff) {
        gUnknown_03001b08 -= 0x2000;
    }
    while (gUnknown_03001b08 < 0) {
        gUnknown_03001b08 += 0x2000;
    }
}

void FUN_08017964(u8 group) {
    u8 i;

    gUnknown_03001b30[group].position = 0;
    for (i = 0; i <= 9; i++) {
        gUnknown_03001b30[group].first[i] = 0;
        gUnknown_03001b30[group].flags[i] = 0;
        gUnknown_03001b30[group].third[i] = 0;
    }
    gUnknown_03001c40[0].value = 0;
    gUnknown_03001c40[1].value = 0;
    gUnknown_03001c40[2].value = 0;
    gUnknown_03001c40[3].value = 0;
}

u8 FUN_080158c0(void) {
    gUnknown_030030d0.counter++;
    if (gUnknown_030030d0.counter > 119) {
        return 1;
    }
    return 0;
}

void FUN_08015e30(s16 x, s16 y, u8 fourth, u8 fifth, u8 index) {
    u32 xOffset = gUnknown_03003100[index];
    s32 signedX = x;

    FUN_08018004(signedX - xOffset, y + gUnknown_03003118[index], 0, fourth, fifth, 0, 113, 0, 0);
    xOffset = gUnknown_03003100[index];
    FUN_08018004(signedX - xOffset, (s16)(gUnknown_03003118[index] + 32) + y, 0, fourth + 16, fifth,
                 0, 111, 0, 0);
    xOffset = gUnknown_03003100[index];
    FUN_08018004(signedX - (xOffset - 32), y + gUnknown_03003118[index], 0, fourth + 24, fifth, 0,
                 112, 0, 0);
    xOffset = gUnknown_03003100[index];
    FUN_08018004(signedX - (xOffset - 32), (s16)(gUnknown_03003118[index] + 32) + y, 0, fourth + 32,
                 fifth, 0, 110, 0, 0);
}

s16 FUN_08015f40(u8 index) { return -gUnknown_03003100[index]; }

s16 FUN_08015f58(u8 index) { return gUnknown_03003118[index]; }

void FUN_08015f6c(void) {
    u8 i;

    for (i = 0; (s8)i >= 0; i++) {
        gUnknown_030033e0[i].fields.first = 0;
        gUnknown_030033e0[i].fields.second = 0;
        gUnknown_030033e0[i].fields.zero = 0;
        gUnknown_030033e0[i].fields.constant = 0;
        gUnknown_030033e0[i].fields.fourth = 0;
        gUnknown_030033e0[i].fields.third = 0;
        gUnknown_030033e0[i].fields.sixth = 0;
        gUnknown_030033e0[i].fields.fifth = 0;
        gUnknown_030033e0[i].fields.seventh = 0;
        gUnknown_030033e0[i].fields.eighth = 0;
        gUnknown_030033e0[i].fields.ninth = 0;
    }
}

/* The v-blank handler: services the link, bumps the frame counter, raises the
   v-blank bit in the BIOS interrupt-check word, and on the frame after a mode
   change reinitialises OAM and the affine matrices. */
void FUN_08015fa4(void) {
    volatile u16 *entry;
    s32 i;

    if (gUnknown_0300138c != 0) {
        MultiSioSyncVSync();
    }
    FUN_0801f60c();
    gUnknown_03001378++;
    REG_IME = 0;
    gUnknown_03007ff8 |= 1;
    REG_IME = 1;
    if (gUnknown_030013a0 != 0) {
        entry = (volatile u16 *)0x07000000;
        for (i = 0; i < 32; i++) {
            *entry++ = 0x200;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0x100;
            *entry++ = 0x200;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0x200;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0x200;
            *entry++ = 0;
            *entry++ = 0;
            *entry++ = 0x100;
        }
        FUN_0801694c();
        FUN_0801ffa4(1);
        FUN_0801fbd8();
    }
    gUnknown_030013a0 = 0;
    gUnknown_03002610++;
}

void FUN_08016684(void) {
    s16 pb;
    s16 pa;
    s16 pc;
    s16 pd;
    s32 first;
    s32 second;
    s32 x;
    s32 y;
    const s16 *table;

    table = gUnknown_0804df7c;
    pa = DivArm(gUnknown_03001b04, table[gUnknown_03001b08 + 0x800] << 3);
    pb = DivArm(gUnknown_03001b04, (table[gUnknown_03001b08] * gUnknown_030016c8) >> 5);
    pc = -DivArm(gUnknown_03001b04, table[gUnknown_03001b08] << 3);
    pd = DivArm(gUnknown_03001b04, (table[gUnknown_03001b08 + 0x800] * gUnknown_030016c8) >> 5);

    first = (table[gUnknown_03001b08 + 0x800] * gUnknown_03001b2c -
             table[gUnknown_03001b08] * gUnknown_030016c0) >>
            13;
    second = (-table[gUnknown_03001b08] * gUnknown_03001b2c -
              table[gUnknown_03001b08 + 0x800] * gUnknown_030016c0) >>
             13;
    x = (first * (gUnknown_03001b04 << 7)) >> 20;
    y = DivArm(gUnknown_030016c8, second * (gUnknown_03001b04 << 7)) >> 12;

    gUnknown_03003380[gUnknown_03003140 ^ 1][0] = pa;
    gUnknown_03003380[gUnknown_03003140 ^ 1][1] = pb;
    gUnknown_03003380[gUnknown_03003140 ^ 1][2] = pc;
    gUnknown_03003380[gUnknown_03003140 ^ 1][3] = pd;
    first = 0x10000 - pb * (y - gUnknown_03001384 + 82) - pa * (x + 120);
    second = 0x10000 - pd * (y - gUnknown_03001384 + 82) - pc * (x + 120);
    gUnknown_03003380[gUnknown_03003140 ^ 1][4] = first;
    gUnknown_03003380[gUnknown_03003140 ^ 1][5] = (first & 0x0fff0000) >> 16;
    gUnknown_03003380[gUnknown_03003140 ^ 1][6] = second;
    gUnknown_03003380[gUnknown_03003140 ^ 1][7] = (second & 0x0fff0000) >> 16;

    gUnknown_03003380[gUnknown_03003140 ^ 1][8] = pa;
    gUnknown_03003380[gUnknown_03003140 ^ 1][9] = pb;
    gUnknown_03003380[gUnknown_03003140 ^ 1][10] = pc;
    gUnknown_03003380[gUnknown_03003140 ^ 1][11] = pd;
    first = 0x10000 - pb * (y + 80) - pa * (x + 120);
    second = 0x10000 - pd * (y + 80) - pc * (x + 120);
    gUnknown_03003380[gUnknown_03003140 ^ 1][12] = first;
    gUnknown_03003380[gUnknown_03003140 ^ 1][13] = (first & 0x0fff0000) >> 16;
    gUnknown_03003380[gUnknown_03003140 ^ 1][14] = second;
    gUnknown_03003380[gUnknown_03003140 ^ 1][15] = (second & 0x0fff0000) >> 16;
}

void FUN_0801694c(void) {
    ((volatile u16 *)0x04000020)[0] = gUnknown_03003380[gUnknown_03003140][0];
    ((volatile u16 *)0x04000020)[1] = gUnknown_03003380[gUnknown_03003140][1];
    ((volatile u16 *)0x04000020)[2] = gUnknown_03003380[gUnknown_03003140][2];
    ((volatile u16 *)0x04000020)[3] = gUnknown_03003380[gUnknown_03003140][3];
    ((volatile u16 *)0x04000020)[4] = gUnknown_03003380[gUnknown_03003140][4];
    ((volatile u16 *)0x04000020)[5] = gUnknown_03003380[gUnknown_03003140][5];
    ((volatile u16 *)0x04000020)[6] = gUnknown_03003380[gUnknown_03003140][6];
    ((volatile u16 *)0x04000020)[7] = gUnknown_03003380[gUnknown_03003140][7];
    ((volatile u16 *)0x04000020)[8] = gUnknown_03003380[gUnknown_03003140][8];
    ((volatile u16 *)0x04000020)[9] = gUnknown_03003380[gUnknown_03003140][9];
    ((volatile u16 *)0x04000020)[10] = gUnknown_03003380[gUnknown_03003140][10];
    ((volatile u16 *)0x04000020)[11] = gUnknown_03003380[gUnknown_03003140][11];
    ((volatile u16 *)0x04000020)[12] = gUnknown_03003380[gUnknown_03003140][12];
    ((volatile u16 *)0x04000020)[13] = gUnknown_03003380[gUnknown_03003140][13];
    ((volatile u16 *)0x04000020)[14] = gUnknown_03003380[gUnknown_03003140][14];
    ((volatile u16 *)0x04000020)[15] = gUnknown_03003380[gUnknown_03003140][15];
}

void FUN_08016a44(const u16 *palette) {
    u16 output[256];
    u16 colour;
    s16 red;
    s16 green;
    s16 blue;
    u32 greenComponent;
    u32 blueComponent;
    s16 i;

    for (i = 0; i <= 255; i++) {
        colour = palette[i];
        greenComponent = ((u32)colour << 16) >> 21;
        blueComponent = ((u32)colour << 16) >> 26;
        red = (colour & 31) + gUnknown_030016b8;
        green = (greenComponent & 31) + gUnknown_030020fc;
        blue = (blueComponent & 31) + gUnknown_03001b20;
        if (red > 31) {
            red = 31;
        }
        if (green > 31) {
            green = 31;
        }
        if (blue > 31) {
            blue = 31;
        }
        if (red < 0) {
            red = 0;
        }
        if (green < 0) {
            green = 0;
        }
        if (blue < 0) {
            blue = 0;
        }
        output[i] = (red & 31) | ((green & 31) << 5) | ((blue & 31) << 10);
    }
    CpuFastSet(output, (void *)0x05000000, 128);
}

void FUN_080177b8(u8 participant) {
    u8 i;
    volatile u32 participantSlot;
    u32 initialParticipant;
    u16 value;
    struct UnknownState080180f0 *ring;
    u32 previous;
    u32 changed;
    u16 pressed;
    struct UnknownState080180f0 *rings;
    u16 released;

    participantSlot = participant;
    value = gUnknown_030048e0.first;
    pressed = gUnknown_030048e0.second;
    released = gUnknown_030048e0.third;
    rings = gUnknown_03001b30;
    initialParticipant = participantSlot;
    previous = initialParticipant;
    gUnknown_03001b30[previous].position++;
    if (gUnknown_03001b30[previous].position > 9) {
        gUnknown_03001b30[previous].position = 0;
    }
    gUnknown_03001b30[initialParticipant].flags[rings[initialParticipant].position] = pressed;
    gUnknown_03001b30[previous].third[gUnknown_03001b30[initialParticipant].position] = released;
    gUnknown_03001b30[initialParticipant].first[gUnknown_03001b30[previous].position] = value;

    for (i = 0; i <= 3; i++) {
        if (i != participantSlot) {
            value = gUnknown_03001c40[i].value;
            previous = gUnknown_03001b30[i].first[gUnknown_03001b30[i].position];
            changed = previous;
            changed = value ^ changed;
            pressed = changed & value;
            ring = &gUnknown_03001b30[i];
            released = previous & changed;
            gUnknown_03001b30[i].position++;
            if (gUnknown_03001b30[i].position > 9) {
                gUnknown_03001b30[i].position = 0;
            }
            gUnknown_03001b30[i].flags[ring->position] = pressed;
            gUnknown_03001b30[i].third[gUnknown_03001b30[i].position] = released;
            gUnknown_03001b30[i].first[ring->position] = value;
        } else {
            gUnknown_03001c40[i].value = gUnknown_030048e0.first;
        }
    }
}

/* Advances every participant's input ring by one slot, deriving the pressed
   and released masks from the newly latched button word. */
void FUN_080178d0(void) {
    u32 value;
    u32 previous;
    u32 changed;
    u16 pressed;
    u16 released;
    u8 i;

    for (i = 0; i <= 3; i++) {
        value = gUnknown_03001c40[i].value;
        previous = gUnknown_03001b30[i].first[gUnknown_03001b30[i].position];
        changed = value ^ previous;
        pressed = value & changed;
        released = previous & changed;
        gUnknown_03001b30[i].position++;
        if (gUnknown_03001b30[i].position > 9) {
            gUnknown_03001b30[i].position = 0;
        }
        gUnknown_03001b30[i].flags[gUnknown_03001b30[i].position] = pressed;
        gUnknown_03001b30[i].third[gUnknown_03001b30[i].position] = released;
        gUnknown_03001b30[i].first[gUnknown_03001b30[i].position] = value;
    }
}

/* Runs one link handshake round: stamps the local send slot with the 0x1234
   marker, clears every receive slot, exchanges them, and counts how many
   participants echoed the marker back. */
u8 FUN_080179d0(void) {
    u8 count;
    u8 i;

    gUnknown_03001b10.first = 0x1234;
    for (i = 0; i < 4; i++) {
        gUnknown_030016f0[i][0] = 0;
    }
    gUnknown_030013a4 = gUnknown_03001730;
    gUnknown_03001730 = FUN_08018730(gUnknown_030016f0[0]);
    FUN_08018c20();
    if (gUnknown_03001730 & 0x100) {
        gUnknown_03001380 = (REG_SIOCNT << 26) >> 30;
        gUnknown_030017c4 = 1;
    }
    count = 0;
    for (i = 0; i < 4; i++) {
        if (gUnknown_030016f0[i][0] == gUnknown_03001b10.first) {
            count++;
        }
    }
    if (gUnknown_03001380 == 255) {
        return 255;
    }
    return count;
}

struct UnknownParticipantState17a80 {
    u8 padding0[20];
    u8 participants[4];
};

u32 FUN_08017a80(struct UnknownParticipantState17a80 *state, u8 participantCount) {
    u32 matches;
    u8 i;

    gUnknown_03001b10.first = state->participants[gUnknown_03001380];
    gUnknown_03001b10.check = 0x3210;
    for (i = 0; i < 4; i++) {
        gUnknown_030016f0[i][0] = 0;
        gUnknown_030016f0[i][1] = 0;
        gUnknown_030016f0[i][2] = 0;
        gUnknown_030016f0[i][3] = 0;
        gUnknown_030016f0[i][4] = 0;
        gUnknown_030016f0[i][7] = 0;
    }
    gUnknown_030013a4 = gUnknown_03001730;
    gUnknown_03001730 = FUN_08018730(gUnknown_030016f0[0]);
    FUN_08018c20();
    matches = 1;
    for (i = 0; i < participantCount; i++) {
        if (matches && gUnknown_030016f0[i][7] != gUnknown_03001b10.check) {
            matches = 0;
        }
    }
    if (matches) {
        state->participants[0] = gUnknown_030016f0[0][0];
        state->participants[1] = gUnknown_030016f0[1][0];
        state->participants[2] = gUnknown_030016f0[2][0];
        state->participants[3] = gUnknown_030016f0[3][0];
    }
    return matches;
}

u32 FUN_08017b74(void *unused, u8 marker, u8 participantCount) {
    volatile u32 valid;
    int one;
    u8 *acceptedCount;
    u8 i;

    (void)unused;
    gUnknown_03001b10.first = marker;
    gUnknown_03001b10.second = 0x8844;
    gUnknown_03001620.activeSlots[112] = 0;
    for (i = 0; i < participantCount; i++) {
        gUnknown_030016f0[i][0] = 0;
    }
    gUnknown_030013a4 = gUnknown_03001730;
    one = 1;
    gUnknown_03001730 = FUN_08018730(gUnknown_030016f0[0]);
    FUN_08018c20();
    valid = 1;
    for (i = 0; i < participantCount; i++) {
        if (gUnknown_03001730 & (one << i)) {
            acceptedCount = &gUnknown_030016a4;
            if (gUnknown_030016f0[i][1] == gUnknown_03001b10.second || i == gUnknown_03001380) {
                (*acceptedCount)++;
            }
        }
        valid = ((u8 *)gUnknown_030016f0[i])[0] & valid;
    }
    return valid;
}
