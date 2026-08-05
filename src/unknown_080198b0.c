#include "types.h"
#include <string.h>

struct UnknownListNode;
struct UnknownState482d0;
struct UnknownState420dc;
struct UnknownCameraState4230c;

extern void FUN_08012b98(u32 value);
extern void FUN_08016078(u32 value);
extern void FUN_0801bcac(void);
extern void FUN_0801b394(void);
extern void FUN_0801c770(void);
extern void FUN_08020840(u16 value);
extern u32 FUN_080205d0(void);
extern u32 FUN_0801cfc8(u8 value);
extern u8 FUN_0801d068(u8 value);
extern u8 FUN_0801d188(u8 value);
extern void FUN_0801d870(u8 value);
extern void FUN_0801fed8(u8 value, u32 other);
extern void FUN_08018664(void);
extern void FUN_080185d8(void);
extern void FUN_08018654(void);
extern void *FUN_08021180(void *value);
extern void FUN_08049108(u16 value);
extern void FUN_080490b4(u16 value);
extern void FUN_080491d4(const void *value, u16 other);
extern void FUN_080491e4(const void *value, u16 other);
extern void FUN_08049234(const void *value);
extern void FUN_0804962c(void);
extern void FUN_080496ac(void);
extern void FUN_08049030(void);
extern void FUN_08049724(void);
extern void FUN_08049170(void);
extern void *gUnknown_03005478;
extern u8 gUnknown_030001c8;
extern u8 gUnknown_030001b0[4];
extern u8 gUnknown_030001b8;
extern u8 (*gUnknown_030001b4)[2];
extern u8 (*gUnknown_030001c0)[2];
extern u8 *gUnknown_030001bc;
extern u8 *gUnknown_030001c4;
struct UnknownPoolNode404ec;
extern struct UnknownPoolNode404ec *volatile gUnknown_0300547c;
extern u8 gUnknown_030001ac;
extern u8 gUnknown_030001ad;
extern u8 *gUnknown_030001a8;
extern u8 gUnknown_03005480;
extern const s16 gUnknown_081231d6[];
extern void FUN_08048fb8(void);
extern void FUN_08049544(const void *value);
extern void FUN_080411fc(void);
extern u32 gUnknown_03005430;
extern void FUN_08047bd8(struct UnknownState482d0 *state);
extern void FUN_08047b40(struct UnknownState482d0 *state);
extern void FUN_080311b4(struct UnknownListNode *node);
extern u8 gUnknown_0300537c;
extern const u8 gUnknown_081734d8[];
extern const u8 gUnknown_08173500[];
extern const u8 gUnknown_08173520[];
extern const void *gUnknown_0817adc8[];
extern void FUN_08041c14(void);
extern void FUN_08041e2c(void);
extern void FUN_08041f84(struct UnknownState420dc *state);
extern void FUN_0804230c(struct UnknownCameraState4230c *state);
extern void FUN_08041860(u8 value);
extern void FUN_08041920(void);
extern void FUN_080419d4(void);
extern void FUN_0804280c(struct UnknownState420dc *state);
extern void FUN_08043e5c(void);
extern void FUN_08043f2c(void);
extern u8 gUnknown_030052e0;
extern void FUN_0802ea64(u8 value);
extern void FUN_080375d8(u8 value);
extern void FUN_0803b69c(u8 value);
extern void FUN_0803a9dc(u8 value);
extern void FUN_08038360(u8 value);
extern void FUN_080309e0(struct UnknownListNode *node);
extern void FUN_0803878c(struct UnknownListNode *node);
extern void FUN_0803bb54(struct UnknownListNode *node);
extern void FUN_0803bc10(struct UnknownListNode *node);
extern void FUN_080304e4(struct UnknownListNode *node);
extern void FUN_08038448(struct UnknownListNode *node);
extern void FUN_0803b82c(struct UnknownListNode *node);
extern void FUN_08032f34(struct UnknownListNode *node);
extern void FUN_08035408(struct UnknownListNode *node);
extern void FUN_08035798(struct UnknownListNode *node);
extern void FUN_08035b08(struct UnknownListNode *node);
extern void FUN_08035b58(struct UnknownListNode *node);
extern u8 gUnknown_03005300;
extern u16 gUnknown_03005378;
extern void FUN_08041808(void *state);
extern void FUN_0802fcb4(u8 value);
extern u8 gUnknown_030052f8;
extern void FUN_08030a08(struct UnknownListNode *node);
extern void FUN_08033090(struct UnknownListNode *node);
extern void FUN_08033228(struct UnknownListNode *node);
extern void FUN_08033bc4(struct UnknownListNode *node);
extern void FUN_08033cdc(struct UnknownListNode *node);
extern const u8 gUnknown_081a7f60[];
extern const u8 gUnknown_0814d910[];
extern const u32 gUnknown_08edc8a8[];
extern void FUN_08046aa4(void);
extern void FUN_08031164(void);
extern void FUN_080284b4(void);
extern void FUN_08000210(void);
extern void FUN_0802c25c(void);
extern void FUN_0802d76c(struct UnknownListNode *node);
extern void FUN_0802da00(struct UnknownListNode *node);
extern void FUN_0804a0a0(const void *value, u16 other);
extern void FUN_0804a0c4(const void *value, u16 first, u16 second);
extern void FUN_0804a1a0(const void *value, u16 first, s8 second);
extern void FUN_0804a594(void *destination, const void *source, u32 size);
extern void FUN_0804af6c(struct UnknownListNode *node, const void *data);
extern u16 FUN_0804afa4(u32 value, u32 divisor);
extern struct UnknownListNode *FUN_0801f7d0(void (*callback)(struct UnknownListNode *), u32 size,
                                            struct UnknownListNode *nodes, u8 flag);

typedef void (*UnknownCallback)(void);

struct UnknownEntity {
    UnknownCallback callback;
    const void *data;
    u16 field8;
    u16 field10;
    u8 field12;
    u8 field13;
    u8 field14;
    u8 field15;
    u8 field16;
    u8 filler17[7];
};

struct UnknownEntityData {
    u8 filler0[16];
    u8 field16;
    u8 filler17[3];
    u16 field20;
    u8 filler22[28];
    u8 field50;
    u8 filler51[3];
    s16 field54[4];
    s16 field62[4];
    u8 filler70[110];
    u32 field180;
    u8 filler184[7];
    u8 field191;
    u8 filler192[60];
};

struct UnknownSoundIndex {
    u8 filler0[4];
    u16 index;
    u8 filler6[2];
};

struct UnknownSoundEntry {
    const void *value;
    u8 filler4[8];
};

struct UnknownQueuedSoundCommand {
    u16 songId;
    u16 parameter;
};

struct UnknownPosition {
    const void *field0;
    s16 x;
    s16 y;
    u16 tile;
    u8 field10;
    u8 field11;
    u8 field12;
    u8 field13;
    u8 field14;
    u8 field15;
};

struct UnknownListNode {
    const void *data;
    u8 field4;
    u8 previous;
    u8 field6;
    u8 next;
    struct UnknownPosition *position;
    void *allocation;
};

struct UnknownQueuedValue {
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;
};

struct UnknownPoolNode404ec {
    u8 field0;
    u8 next;
    u8 padding2;
    u8 field3;
    const void *data;
    u8 padding8[19];
    u8 field27;
    u8 padding28[16];
};

struct UnknownPoolCommand4051c {
    u8 node;
    u8 replacement;
    u8 value;
};

struct UnknownFadeState41808 {
    u8 padding0[26];
    u8 step;
    u8 progress;
};

struct UnknownState41f24 {
    u8 padding0[4];
    const void *callback;
    u8 padding8[8];
    const void *graphics;
    u16 field20;
    u8 field22;
    u8 padding23;
    u8 field24;
    u8 padding25[2];
    u8 selector;
};

struct UnknownState420dc {
    u8 padding0[2];
    u8 field2;
    u8 field3;
    const void *callback;
    union {
        u32 fixed;
        struct {
            u16 low;
            u16 high;
        } half;
    } field8;
    u8 padding12[2];
    u16 field14;
    const void *graphics;
    u8 padding20[2];
    u8 field22;
    u8 padding23;
    u8 field24;
    u8 poolIndex;
    u8 field26;
    u8 fade;
    u8 padding28[2];
    u16 baseX;
    u8 padding32[2];
    u16 baseY;
    u8 cachedPoolField;
};

struct UnknownCameraState4230c {
    u8 padding0[2];
    u8 field2;
    u8 field3;
    const void *callback;
    u8 padding8[2];
    s16 relativeX;
    u8 padding12[2];
    s16 relativeY;
    const void *graphics;
    u16 animation;
    u8 padding22[4];
    u8 animationFrame;
    u8 animationIndex;
    union {
        s32 fixed;
        struct {
            u16 low;
            s16 high;
        } half;
    } x;
    union {
        s32 fixed;
        struct {
            u16 low;
            s16 high;
        } half;
    } y;
};

struct UnknownRecord41f24 {
    u8 padding0[4];
    u16 field4;
    u16 field6;
    u16 field8;
    u16 field10;
    u8 padding12[20];
};

struct UnknownState080201f8 {
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;
    u16 fifth;
    u8 sixth;
    u8 seventh;
    u8 eighth;
};

struct UnknownCommandRecord {
    u32 first;
    u32 second;
    u32 third;
    u16 fourth;
    u16 type;
};

struct UnknownBufferState {
    u32 field0;
    const u8 *source;
    u8 *destination;
    u32 end;
    u16 width;
    u16 rowSize;
    u16 stride;
    u16 blockSize;
    u32 fill;
};

struct UnknownHeapBlock {
    struct UnknownHeapBlock *next;
    s32 size;
};

struct UnknownState08021484 {
    u8 filler0[29];
    u8 firstFlags;
    u8 secondFlags;
};

struct UnknownState03002110 {
    u8 filler0[119];
    u8 field119;
    u8 filler120;
    u8 field121;
    u8 filler122[166];
    u8 validity[0x200];
    u8 selector;
    u8 filler321;
    u8 records[358];
    u8 field1160;
    u8 field1161;
    u8 field1162;
    u8 field1163;
    u32 field1164;
    u8 filler1168[8];
    u16 field1176;
    u16 field1178;
    u8 rowMasks[64];
};

struct UnknownState03004dbc {
    u8 filler0[2];
    u8 field2;
    u8 field3;
    u8 filler4[8];
    u16 field12;
    u16 field14;
    u16 field16;
    u16 field18;
    u32 bits[16];
};

struct UnknownAllocation248f0 {
    u8 filler0[6];
    u8 field6;
    u8 filler7[7];
    u8 field14;
};

struct UnknownAllocation29d74 {
    u8 filler0[2];
    u16 index;
    u8 childIndices[2];
    u8 filler6[6];
    u8 lowFlags[4];
    u8 highFlags[4];
    u8 firstSelection;
    u8 secondSelection;
};

struct UnknownAllocation2a298Child {
    const void *graphics;
    u8 filler4[4];
    u16 field8;
    u8 filler10[10];
    u16 x;
    u16 y;
    u8 filler24[4];
};

struct UnknownAllocation25a98 {
    u8 filler0[16];
    struct UnknownListNode *child16;
    u8 filler20[20];
    struct UnknownListNode *child40;
    u8 filler44[4];
    struct UnknownListNode *child;
    u8 childIds[7];
};

struct UnknownAllocation27db8 {
    u8 filler0[16];
    u16 field16;
    u16 field18;
    u16 field20;
    u16 field22;
};

struct UnknownAllocation28770 {
    u32 field0;
    u8 field4;
    u8 field5;
};

struct UnknownState482d0 {
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
    u8 filler23[3];
    u8 field26;
    u8 field27;
    u8 filler28[2];
    u16 field30;
    u8 filler32[2];
    u16 field34;
    u8 field36;
    u8 field37;
    u8 field38;
    u8 field39;
    u16 field40;
    u8 filler42[4];
    u8 field46;
};

struct UnknownPair4825c {
    u16 first;
    u16 second;
};

struct UnknownTriple47c30 {
    u16 first;
    u16 second;
    u16 third;
};

struct UnknownTransferRecord4033c {
    const void *source;
    void *destination;
    u32 size;
};

struct UnknownTransferList4033c {
    struct UnknownTransferRecord4033c records[1];
};

struct UnknownTransferRecord403c0 {
    const void *source;
    void *destination;
    u8 width;
    u8 height;
    u16 flags;
};

struct UnknownTransferList403c0 {
    struct UnknownTransferRecord403c0 records[1];
};

struct UnknownGlobalRenderState {
    const void *callback;
    u32 field4;
    u16 field8;
    u16 field10;
    u16 field12;
    u8 filler14[2];
    u16 field16;
    u16 field18;
    u16 field20;
    u16 field22;
    u16 field24;
    u16 field26;
    u8 filler28;
    u8 field29;
    u8 filler30;
    u8 field31;
    u8 field32;
    u8 field33;
    u8 field34;
    u8 field35;
    u8 field36;
    u8 filler37[3];
    u32 field40;
    u8 field44;
    u8 filler45;
    u8 field46;
};

struct UnknownBounds4230c {
    u8 filler0[12];
    s16 width;
    s16 height;
};

extern struct UnknownGlobalRenderState gUnknown_03005440;
extern s16 gUnknown_03005490;
extern s16 gUnknown_03005494;
extern u32 gUnknown_03005488;
extern u32 gUnknown_03002610;
extern void *gUnknown_03007c54;
extern struct UnknownState420dc *gUnknown_030001d4;
extern s32 gUnknown_0300023c;
extern s32 gUnknown_03000240;
extern u16 gUnknown_030001e0;
extern u16 gUnknown_030001f0;
extern u16 gUnknown_03000200;
extern u16 gUnknown_03000210;
extern const u8 gUnknown_08173510[];
extern const u8 gUnknown_08173540[];
extern const struct UnknownBounds4230c gUnknown_081a4c2a[];
extern void FUN_08045d30(void);
extern u8 FUN_08043cf8(s16 x, s16 y);
extern u16 Sqrt(u32 value);
extern struct UnknownState420dc *gUnknown_030001d0;
extern const struct UnknownRecord41f24 *gUnknown_08eeb660[];
extern const struct UnknownRecord41f24 *gUnknown_08eeb678[];
extern const void *const *gUnknown_08edda00[];
extern struct UnknownState420dc *FUN_0803ff98(const void *callback, void *parent, u32 flag);
extern void FUN_080481c8(struct UnknownState482d0 *state);
extern void FUN_0804825c(struct UnknownState482d0 *state);
extern void FUN_08047acc(struct UnknownState482d0 *state);
extern void FUN_08047c30(struct UnknownState482d0 *state);
extern void FUN_0804033c(const void *source, void *destination, u32 size);
extern void FUN_0804051c(void *state);
extern void FUN_0803fe98(u16 first, u16 second, u16 third);
extern void FUN_080403c0(const void *source, void *destination, u32 width, u32 height, u32 flags);
extern const u8 gUnknown_081a81d0[];
extern void FUN_0804542c(struct UnknownState482d0 *state);
extern u8 gUnknown_03005380;
extern void FUN_08036560(void);
extern void FUN_080412dc(void);
extern void FUN_080405a8(u8 first, u8 second);
extern s16 FUN_08040698(u8 value);
extern s16 FUN_08040684_wide(u32 value) asm("FUN_08040684");
extern s16 FUN_08040698_wide(u32 value) asm("FUN_08040698");
extern s32 FUN_0804a59c(s32 value, s32 divisor);
extern const u8 gUnknown_081a7f88[];
extern void FUN_0804a5c4(void *destination, const void *source, u32 width, u32 height);
extern struct UnknownTriple47c30 gUnknown_030002d0;
extern const u8 gUnknown_030044d6[];
extern struct UnknownTransferList4033c *gUnknown_030001a0;
extern struct UnknownTransferList403c0 *gUnknown_030001a4;
extern volatile struct UnknownTransferRecord4033c gUnknown_030000d4;
extern const u8 gUnknown_081a7f18[];
extern struct UnknownPair4825c gUnknown_03000288;
extern void FUN_080405f4(u8 first, u8 second);

struct UnknownAllocation3128c {
    u8 filler0[2];
    u16 field2;
    u16 field4;
};

struct UnknownState43e28 {
    u8 filler0[4];
    const void *callback;
    u8 filler8[8];
    const void *graphics;
    u8 filler20[2];
    u8 field22;
    u8 filler23;
    u8 field24;
};

struct UnknownRecordValue28c80 {
    s16 value;
    u8 filler2[14];
};

struct UnknownLookupRecord29250 {
    u8 filler0[4];
    u8 value;
    u8 filler5[3];
};

struct UnknownRecords28c80 {
    u8 filler0[2];
    s16 field2;
    u8 filler4[14];
    struct UnknownRecordValue28c80 records[1];
};

struct UnknownCoordinatePairs28f98 {
    s16 firstX;
    s16 firstY;
    s16 secondX;
    s16 secondY;
};

struct UnknownCallbackState03005330 {
    UnknownCallback callback;
    s16 field4;
    s16 field6;
    u16 field8;
    u8 field10;
    u8 field11;
};

struct UnknownUnsignedHalfword {
    u32 value : 16;
};

struct UnknownFourByteMessage {
    u8 type;
    u8 index;
    u16 value;
};

struct Unknown16ByteRecord {
    u8 field0;
    u8 filler1[15];
};

extern void (*gUnknown_03002030)(void);
extern struct UnknownCallbackState03005330 gUnknown_03005330;
extern u8 gUnknown_03001620;
extern u8 gUnknown_03001210[];
extern u8 gUnknown_030013a0;
extern u8 gUnknown_03001b00[8];
extern struct UnknownEntity gUnknown_03003db0[];
extern struct UnknownEntityData gUnknown_03001c40[];
extern u8 gUnknown_03003e10;
extern u16 gUnknown_08071264[];
extern const u8 gUnknown_08ed89d0[];
extern const u8 gUnknown_08ed89e4[];
extern const u8 gUnknown_08ed89ec[];
extern const u8 gUnknown_08ed89f8[];
extern const u8 gUnknown_08ed8a0c[];
extern const u8 gUnknown_08ed8a8c[];
extern const u8 gUnknown_08ed8a9c[];
extern const u8 gUnknown_08ed8aac[];
extern const u8 gUnknown_08ed8ae4[];
extern const s16 gUnknown_08edc4a4[];
extern const u16 gUnknown_08edc544[];
extern const struct UnknownSoundIndex gUnknown_08bf7244[];
extern const struct UnknownSoundEntry gUnknown_08bf71fc[];
extern u8 gUnknown_03000008[100];
extern u8 gUnknown_0300006c;
extern struct UnknownListNode gUnknown_03003e20[100];
extern u8 gUnknown_030000c0;
extern u16 gUnknown_03000070[20][2];
extern const void *gUnknown_03003150[];
extern u8 gUnknown_03004470;
extern struct UnknownQueuedSoundCommand gUnknown_03004480[];
extern u32 gUnknown_0300019c;
extern s8 gUnknown_030048d4;
extern u8 gUnknown_030048d0;
extern struct UnknownQueuedValue gUnknown_030044d0[];
extern u8 gUnknown_0300019a;
extern u8 gUnknown_030044c0;
extern u8 gUnknown_030000c8[4];
extern struct UnknownState080201f8 gUnknown_030048e0;
extern u32 gUnknown_030048f0;
extern struct UnknownCommandRecord gUnknown_03004900[];
extern u16 gUnknown_03004b00;
extern u8 gUnknown_03004b04;
extern u16 gUnknown_03004b08;
extern struct UnknownBufferState gUnknown_03004b10;
extern const u8 gUnknown_0807173c[];
extern const u8 gUnknown_08071b7c[];
extern const u32 gUnknown_0807a37c[];
extern const u32 gUnknown_0807a77c[];
extern u16 gUnknown_03004b30[];
extern struct UnknownHeapBlock *gUnknown_03004d30;
extern struct UnknownHeapBlock gUnknown_030033e0;
extern u32 gUnknown_03004d34;
extern u32 gUnknown_03004d38;
extern void CpuSet(const void *source, void *destination, u32 mode);
extern struct UnknownState08021484 gUnknown_03004d40;
extern u32 gUnknown_020000e0;
extern const void *gUnknown_03004d94;
extern u32 gUnknown_03004d8c;
extern void SoftResetExram(u32 flags);
extern void LZ77UnCompWram(const void *source, void *destination);
extern void LZ77UnCompVram(const void *source, void *destination);
extern void CpuFastSet(const void *source, void *destination, u32 mode);
extern u32 FUN_08018c8c(void *state);
extern u32 FUN_0801950c(void *state);
extern void ReadFlash(u16 sector, u32 offset, void *destination, u32 size);
extern u32 VerifyFlashSector(u16 sector, u8 *source);
extern u16 SetFlashTimerIntr(u8 timer, void (**handler)(void));
extern void (*gUnknown_0300315c)(void);
extern void (*gUnknown_03006788)(void);
extern u32 (*gUnknown_0300677c)(u16 sector, u8 *source);
extern const u8 gUnknown_0807b780[];
extern const u32 gUnknown_0807b880[];
extern struct UnknownState03004dbc *gUnknown_03004dbc;
extern struct UnknownState03002110 gUnknown_03002110;
extern const u32 gUnknown_0807163c[];
extern const u8 gUnknown_08edb498[];
extern const u8 gUnknown_08edb820[];
extern const u8 gUnknown_08edb4f0[];
extern const u8 gUnknown_08edb678[];
extern const u16 gUnknown_08edb834[];
extern const void *gUnknown_08edb750;
extern const u16 gUnknown_08edb91c[];
extern const void *gUnknown_08edb760[];
extern u8 gUnknown_08edb5c8[];
extern const void *gUnknown_08edb7f0[];
extern const u16 gUnknown_08edb854[];
extern const void *gUnknown_08edb740[];
extern const u8 gUnknown_08edb84c[];
extern const u8 gUnknown_08edb570[];
extern const u8 gUnknown_08edb488[];
extern const u8 gUnknown_08edb4f8[];
extern const u8 gUnknown_08edb5a0[];
extern const u8 gUnknown_08edb548[];
extern const u8 gUnknown_08edb558[];
extern const u8 gUnknown_08edb468[];
extern const u8 gUnknown_08edb5b8[];
extern const u8 gUnknown_08edb5c0[];
extern const u16 gUnknown_08edb86c[];
extern u16 *gUnknown_03004db0;
extern const u16 data_gap_003[];
extern u32 gUnknown_03004dc0;
extern u32 gUnknown_03004dc8;
extern u16 gUnknown_03004dd8;
extern u16 gUnknown_03004dd4;
extern u16 gUnknown_03004ddc;
extern u16 gUnknown_03004de0;
extern u32 gUnknown_03004da8;
extern u32 gUnknown_03004dc4;
extern u8 *gUnknown_03004db8;
extern u16 gUnknown_03004df0[];
extern const void *gUnknown_03005240;
extern const void *gUnknown_08ed9740[];
extern u16 gUnknown_03004dd0;
extern const u8 gUnknown_0807c620[];
extern const u8 gUnknown_0807c060[];
extern const void *const *gUnknown_08edb450[];
extern u16 gUnknown_03001b10[];
extern void FUN_08034f28(void);
extern void FUN_08020b74(u32 first, u32 second, const void *data, u32 fourth, u32 fifth);
extern u32 FUN_08020ad0(const void *data);
extern const void *gUnknown_08edb9ac[];
extern const void *gUnknown_08edb9cc[];
extern const void *gUnknown_08edb9ec[];
extern const void *gUnknown_08edba0c[];
extern const void *gUnknown_08edba2c[];
extern const void *gUnknown_08edba4c[];
extern u8 gUnknown_0600dfc0[];
extern const u8 gUnknown_0600da80[];
extern void FUN_080264d0(struct UnknownListNode *node);
extern void FUN_080266ac(struct UnknownListNode *node);
extern void FUN_080279c4(struct UnknownListNode *node);
extern void FUN_08026844(struct UnknownListNode *node);
extern void FUN_08018c3c(void);
extern u32 FUN_0801f9e8(u16 value);
extern void FUN_0801f618(u16 value);
extern void m4aSongNumStart(u16 number);
extern u8 gUnknown_03005248;
extern u8 gUnknown_0300525c;
extern u8 gUnknown_030017c4;
extern u32 gUnknown_03001380;
extern u32 gUnknown_03005254;
extern u8 gUnknown_030051f4;
extern u16 gUnknown_03005244;
extern struct UnknownFourByteMessage gUnknown_03001b1c;
extern u8 gUnknown_030051f0;
extern struct Unknown16ByteRecord gUnknown_030016fc[];
extern void FUN_08027b84(struct UnknownListNode *node);
extern void FUN_08027d18(struct UnknownListNode *node);
extern void FUN_080274ac(struct UnknownListNode *node);
extern void FUN_080217d0(u32 value);
extern void FUN_080282a8(struct UnknownListNode *node);
extern void FUN_080282e0(struct UnknownListNode *node);
extern void FUN_08028318(struct UnknownListNode *node);
extern void FUN_08028350(struct UnknownListNode *node);
extern void FUN_08028388(struct UnknownListNode *node);
extern void FUN_080283c0(struct UnknownListNode *node);
extern void FUN_08028814(struct UnknownListNode *node);
extern void FUN_080288b4(struct UnknownListNode *node);
extern void FUN_08028bec(void);
extern void FUN_08028c80(struct UnknownListNode *node);
extern void FUN_08028ed8(struct UnknownListNode *node);
extern void FUN_080291a8(void);
extern void FUN_08029014(struct UnknownListNode *node);
extern void FUN_080290b4(struct UnknownListNode *node);
extern void FUN_08028158(struct UnknownListNode *node);
extern void FUN_08028190(struct UnknownListNode *node);
extern void FUN_0802a480(struct UnknownListNode *node);
extern void FUN_0802a804(struct UnknownListNode *node);
extern void FUN_0802fdf8(void);
extern void FUN_080340b8(void);
extern const u8 gUnknown_0811c0d0[];
extern const u16 gUnknown_08edbb34[][4];
extern const u8 gUnknown_0811c0d8[];
extern const u16 gUnknown_08edbb9c[][2];
extern const u8 gUnknown_0811c0e0[];
extern const u16 gUnknown_08edbbac[][2];
extern void FUN_0802b688(struct UnknownListNode *node);
extern void FUN_0802b248(struct UnknownListNode *node);
extern void FUN_0802b388(struct UnknownListNode *node);
extern const u8 gUnknown_0811c120[];
extern const u8 gUnknown_0811c188[];
extern const u16 gUnknown_08edbb7c[][2];
extern const u8 gUnknown_0811c138[];
extern const u16 gUnknown_08edbb8c[][2];
extern u32 gUnknown_03005264;
extern u8 gUnknown_03002600[];
extern u8 gUnknown_03005268[];
extern u8 gUnknown_0300524c[];
extern void FUN_08029250(void);
extern u8 gUnknown_030013b0[];
extern u8 gUnknown_03005250;
extern u8 gUnknown_03002170[];
extern const u16 gUnknown_0810db14[];
extern const u8 gUnknown_0810db54[];
extern const u8 gUnknown_0810b32c[];
extern const u8 gUnknown_0810dbcc[];
extern const u8 gUnknown_08132544[];
extern const u8 gUnknown_08116444[];
extern const u16 gUnknown_081327d4[];
extern const u8 gUnknown_0810df04[];
extern const u8 gUnknown_08116568[];
extern const u8 gUnknown_08117368[];
extern const u8 gUnknown_08117b68[];
extern const u8 gUnknown_08118368[];
extern const void *gUnknown_08edbadc[];
extern const u8 gUnknown_08edbaac[];
extern const struct UnknownPosition gUnknown_08edbabc[];
extern void FUN_08030d20(struct UnknownListNode *node);
extern void FUN_0802a0ec(struct UnknownListNode *node);
extern void FUN_0802b2d4(struct UnknownListNode *node);
extern void FUN_0802b3c8(struct UnknownListNode *node);
extern void FUN_0802b638(struct UnknownListNode *node);
extern void FUN_08029ba0(void);
extern void FUN_0801c82c(void);
extern void FUN_0800ec18(void);
extern void FUN_0800f38c(void);
extern void FUN_08031db4(void *destination, const void *source, u32 size);
extern void FUN_0803281c(void);
extern void FUN_0803d1a0(void);
extern void FUN_080315bc(void);
extern void FUN_08039e20(void);
extern void FUN_08021268(u32 value);
extern const u8 gUnknown_08edb97c[];
extern const u8 gUnknown_08edb984[];
extern const u8 gUnknown_08edb94c[];
extern const u8 gUnknown_08edb974[];
extern const struct UnknownCoordinatePairs28f98 gUnknown_08edb98c[];
extern const u8 gUnknown_0804df7c[];
extern u16 gUnknown_03005200[][8];
extern void FUN_08028d30(struct UnknownListNode *node);
extern void FUN_08020978(s32 x, u32 y, u16 tile, u32 attributes);
extern void FUN_08028f1c(struct UnknownListNode *node);
extern void FUN_0802f328(void *state);
extern u32 FUN_0801fab0(u16 value);
extern void FUN_080214c0(u32 value);
extern u8 gUnknown_03005260;
extern u32 gUnknown_03005258;
extern struct UnknownRecords28c80 gUnknown_030016f0;
extern u16 gUnknown_05000080[];
extern u16 gUnknown_050001c0[];
extern u16 gUnknown_050001e0[];
extern u16 gUnknown_05000200[];
extern const u16 gUnknown_0810c5f4[];
extern const u16 gUnknown_0815e67c[];
extern const u16 gUnknown_081326f4[];
extern const u16 gUnknown_0810c634[];
extern u32 FUN_0801fd18(s16 value, u32 other);
extern void FUN_0801f89c(void);
extern void FUN_0801fda0(void);
extern void FUN_08021b0c(void);
extern void FUN_08021e70(u16 value);

extern void FUN_0801d618(void);
extern void FUN_0801dfdc(void);
extern void FUN_0801e044(void);
extern void FUN_0801e174(void);
extern void FUN_0801e4f4(u8 value);
extern u8 FUN_0801ee4c(u8 value);
extern u32 FUN_08020160(u32 value);
extern u32 FUN_08020144(void);
extern void FUN_0801eea8(u8 value);
extern u16 ArcTan2(s16 x, s16 y);
extern u16 gUnknown_08071250[];

void FUN_0801eb94(u8 value);
void FUN_0801ebf4(u8 value);
void FUN_0801ed50(u8 value);
void FUN_0801edc0(u8 value);
void FUN_0801ee30(u8 value);
void FUN_080244ac(struct UnknownListNode *node);
void FUN_0802440c(struct UnknownListNode *node);
void FUN_080243a4(struct UnknownListNode *node);
void FUN_080245a0(struct UnknownListNode *node);
void FUN_08024794(struct UnknownListNode *node);
void FUN_08024a34(struct UnknownListNode *node);
void FUN_08024aac(struct UnknownListNode *node);
void FUN_08024b1c(struct UnknownListNode *node);
void FUN_08024c20(struct UnknownListNode *node);
void FUN_08024c30(struct UnknownListNode *node);
void FUN_08024d0c(struct UnknownListNode *node);
void FUN_08025734(struct UnknownListNode *node);
void FUN_080257b8(struct UnknownListNode *node);
void FUN_08025838(struct UnknownListNode *node);
void FUN_080258ac(struct UnknownListNode *node);
void FUN_08025994(struct UnknownListNode *node);
void FUN_08025a08(struct UnknownListNode *node);
void FUN_08025628(struct UnknownListNode *node);
void FUN_08025c4c(struct UnknownListNode *node);
void FUN_08025b78(struct UnknownListNode *node);
void FUN_08025c14(struct UnknownListNode *node);
void FUN_08025d50(struct UnknownListNode *node);
extern u32 FUN_080211f0(void);
extern void FUN_08025064(u8 value);
void FUN_08025120(struct UnknownListNode *node);
void FUN_080252d0(struct UnknownListNode *node);
void FUN_08025f5c(struct UnknownListNode *node);
void FUN_08025fd4(struct UnknownListNode *node);
extern void FUN_08018444(void);

void FUN_0801c8f0(void) {
    FUN_08012b98(60);
    gUnknown_03002030 = FUN_0801bcac;
    gUnknown_03002030();
}

void FUN_0801c910(void) {
    FUN_08012b98(30);
    gUnknown_03002030 = FUN_0801b394;
    gUnknown_03002030();
}

void FUN_0801c930(void) {
    FUN_08016078(6);
    gUnknown_03001620 = 0;
    gUnknown_03002030 = FUN_0801c770;
    FUN_08020840(24);
    FUN_080205d0();
    gUnknown_030013a0 = 1;
}

void FUN_0801ce70(void) {
    gUnknown_03001b00[0] = 0;
    gUnknown_03001b00[1] = 0;
    gUnknown_03001b00[2] = 0;
    gUnknown_03001b00[3] = 0;
    gUnknown_03001b00[4] = 0;
    gUnknown_03001b00[5] = 0;
    gUnknown_03001b00[6] = 0;
    gUnknown_03001b00[7] = 0;
}

void FUN_0801eacc(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801dfdc;
    }
}

void FUN_0801eaf8(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801e044;
    }
}

void FUN_0801eb24(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        gUnknown_03003db0[value].callback = FUN_0801d618;
    }
}

void FUN_0801eb50(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801eb94;
    {
        const void *data = gUnknown_08ed89d0;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801eb94(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ebb0(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ebf4;
    {
        const void *data = gUnknown_08ed89e4;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801ebf4(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ec10(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed89ec;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ec64(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed89f8;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ecb8(u8 value) {
    if (FUN_0801ee4c(value) == 0) {
        gUnknown_03003db0[value].field13 = 0;
        gUnknown_03003db0[value].callback = FUN_0801e174;
        {
            const void *data = gUnknown_08ed8a0c;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ed0c(u8 value) {
    gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ed50;
    {
        const void *data = gUnknown_08ed8a8c;
        gUnknown_03003db0[value].data = data;
    }
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

void FUN_0801ed50(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801ed6c(u8 value) {
    if (gUnknown_03003db0[value].field15 == value) {
        FUN_0801d870(value);
    } else {
        gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801edc0;
        {
            const void *data = gUnknown_08ed8a9c;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801edc0(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

void FUN_0801eddc(u8 value) {
    if (gUnknown_03003db0[value].field15 == value) {
        FUN_0801d870(value);
    } else {
        gUnknown_03003db0[value].callback = (UnknownCallback)FUN_0801ee30;
        {
            const void *data = gUnknown_08ed8aac;
            gUnknown_03003db0[value].data = data;
        }
        gUnknown_03003db0[value].field14 = 0;
        gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
    }
}

void FUN_0801ee30(u8 value) {
    if (FUN_0801cfc8(value) == 0) {
        FUN_0801d870(value);
    }
}

u8 FUN_0801ee4c(u8 value) {
    if (FUN_08020160(gUnknown_08071264[gUnknown_03003e10]) != 0) {
        struct UnknownEntity *entities = gUnknown_03003db0;
        struct UnknownEntity *entity = &entities[value];
        u8 linked = entity->field15;

        {
            struct UnknownEntityData *data = gUnknown_03001c40;

            if (data[linked].field20 == 53) {
                entity->callback = (UnknownCallback)FUN_0801eea8;
                return 1;
            }
        }
    }

    return 0;
}

void FUN_0801eea8(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];
    u8 linked = entity->field15;

    {
        struct UnknownEntityData *data = gUnknown_03001c40;

        if (data[linked].field20 != 53) {
            entity->callback = FUN_0801d618;
        }
    }
}

void FUN_0801eee0(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->field8 = (entity->field8 & 0xFF0F) | 0x200;
    entity->field12 = 0;
    entity->callback = (UnknownCallback)FUN_0801e4f4;
}

void FUN_0801ef14(u8 value, const void *data) {
    gUnknown_03003db0[value].data = data;
    gUnknown_03003db0[value].field14 = 0;
    gUnknown_03003db0[value].field16 = gUnknown_03001c40[value].field16;
}

u16 FUN_0801ef4c(void) {
    u32 random = FUN_08020144();
    u16 *table = gUnknown_08071250;
    u16 *base = &table[gUnknown_03003e10];

    return *base + ((random & 0xFFF) * *base >> 12);
}

u8 FUN_0801ef7c(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    if (entity->field15 == value) {
        return 1;
    }

    {
        struct UnknownEntityData *data = gUnknown_03001c40;
        u8 linked = entity->field15;

        if (gUnknown_03001c40[value].field54[linked] < 0) {
            if (data[value].field16 == 0) {
                return 0;
            }
        } else if (data[value].field16 != 0) {
            return 0;
        }
    }

    return 1;
}

u8 FUN_0801efd4(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];
    u8 linked = entity->field15;
    struct UnknownEntityData *data = gUnknown_03001c40;
    u32 offset = linked * 2 + value * sizeof(*data);
    u8 *firstBase = (u8 *)data + 54;
    s16 *first = (s16 *)(firstBase + offset);

    {
        u8 *secondBase = (u8 *)data + 62;
        s16 *second = (s16 *)(secondBase + offset);

        {
            const u8 *lookup = gUnknown_08ed8ae4;
            u16 angle = ArcTan2(*first, *second);

            return lookup[angle >> 12];
        }
    }
}

void FUN_0801f024(u8 value) { gUnknown_03003e10 = value; }

void FUN_0801f030(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->callback = FUN_0801d618;
    entity->field15 = FUN_0801d068(value);
}

void FUN_0801f058(u8 value) {
    struct UnknownEntity *entities = gUnknown_03003db0;
    struct UnknownEntity *entity = &entities[value];

    entity->callback = FUN_0801d618;
    entity->field15 = FUN_0801d188(value);
}

u32 FUN_0801f308(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;

    return FUN_08020160(word >> 16);
}

u32 FUN_0801f31c(u8 value, u8 other, const u32 **stream) {
    *stream += 1;

    if ((gUnknown_03001c40[value].field50 & 0xF) != 0) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f3a4(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return 1;
}

u32 FUN_0801f3b0(u8 value, u8 other, const u32 **stream) {
    u32 operand = (*stream)[1];
    *stream += 2;

    return (gUnknown_03001c40[other].field180 & operand) == 1;
}

u32 FUN_0801f3e4(u8 value, u8 other, const u32 **stream) {
    u32 operand = (*stream)[1];
    *stream += 2;

    return (gUnknown_03001c40[value].field180 & operand) == 1;
}

u32 FUN_0801f418(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;

    {
        u16 operand = word >> 16;
        return gUnknown_03001c40[value].field20 == operand;
    }
}

u32 FUN_0801f448(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return gUnknown_03003db0[value].field10 == 0;
}

u32 FUN_0801f474(u8 value, u8 other, const u32 **stream) {
    u32 word = *(*stream)++;
    u16 operand = word >> 16;
    u8 operation = (word & 0xFF00) >> 8;
    u32 result = 0;

    switch (operation) {
    case 0:
        if (gUnknown_03001c40[value].field191 == operand) {
            result = 1;
        }
        break;
    case 1:
        if (gUnknown_03001c40[value].field191 < operand) {
            result = 1;
        }
        break;
    case 2:
        if (gUnknown_03001c40[value].field191 > operand) {
            result = 1;
        }
        break;
    }

    return result;
}

u32 FUN_0801f4f4(u8 value, u8 other, const u32 **stream) {
    *stream += 1;
    return (u16)(gUnknown_03001c40[other].field20 - 252) <= 3;
}

void FUN_0801f628(u16 value) { FUN_08049108(value); }

void FUN_0801f644(u16 value) {
    FUN_08049234(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value);
}

void FUN_0801f66c(u16 value, u16 first, s8 second) {
    FUN_0804a1a0(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, first, second);
}

void FUN_0801f6a0(u16 value, u16 first, u16 second) {
    FUN_0804a0c4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, first, second);
}

void FUN_0801f6d4(u16 value, u16 other) {
    FUN_0804a0a0(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other);
}

void FUN_0801f700(void) { FUN_0804962c(); }

void FUN_0801f70c(void) { FUN_080496ac(); }

void FUN_0801f718(u16 value, u16 other) {
    FUN_080491d4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other >> 4);
}

void FUN_0801f744(u16 value, u16 other) {
    FUN_080491e4(gUnknown_08bf71fc[gUnknown_08bf7244[value].index].value, other);
}

void FUN_0801f770(u16 value) { FUN_080490b4(value); }

void FUN_0801f89c(void) {
    u8 index = 0;

    do {
        struct UnknownListNode *node = &gUnknown_03003e20[index];

        FUN_0804af6c(node, node->data);
        index = node->next;
    } while (index != 0);
}

void FUN_0801f8c0(struct UnknownListNode *node) {
    gUnknown_03003e20[node->previous].next = node->next;
    gUnknown_03003e20[node->next].previous = node->previous;

    gUnknown_03000008[gUnknown_0300006c++] = node->field6;
    if (gUnknown_0300006c > 99) {
        gUnknown_0300006c = 0;
    }

    if (node->allocation != 0) {
        FUN_08021180(node->allocation);
    }
}

s16 FUN_0801f914(s16 first, s16 second) { return first + (second - first) / 2; }

u32 FUN_0801f92c(struct UnknownListNode *node, s16 x, s16 y) {
    node->position->x = x + (node->position->x - x) / 2;
    node->position->y = y + (node->position->y - y) / 2;

    if (node->position->x == x && node->position->y == y) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f978(struct UnknownListNode *node, s16 x) {
    node->position->x = x + (node->position->x - x) / 2;
    if (node->position->x == x) {
        return 1;
    }
    return 0;
}

u32 FUN_0801f9a8(struct UnknownListNode *node, s16 y) {
    node->position->y = y + (node->position->y - y) / 2;
    if (node->position->y == y) {
        return 1;
    }
    return 0;
}

void FUN_0801f9d8(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_0801fb60(void) {
    gUnknown_03003150[1] = (const void *)((u32)FUN_080185d8 + 1);
    gUnknown_03003150[2] = (const void *)((u32)FUN_08018654 + 1);
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000004 = 0x128;
    *(volatile u16 *)0x04000208 = 1;
}

void FUN_0801fb94(void) { gUnknown_030000c0 = 0; }

void FUN_0801fba0(u16 offset, u16 value) {
    if (gUnknown_030000c0 <= 19) {
        gUnknown_03000070[gUnknown_030000c0][0] = offset;
        gUnknown_03000070[gUnknown_030000c0++][1] = value;
    }
}

void FUN_0801fbfc(const u16 *entries, u8 count);

void FUN_0801fbd8(void) {
    if (gUnknown_030000c0 != 0) {
        FUN_0801fbfc(&gUnknown_03000070[0][0], gUnknown_030000c0);
        gUnknown_030000c0 = 0;
    }
}

void FUN_0801fbfc(const u16 *entries, u8 count) {
    count--;
    while (count != 0xFF) {
        u16 offset = *entries++;

        *(volatile u16 *)(0x04000000 + offset) = *entries++;
        count--;
    }
}

void FUN_0801fc30(u8 value, const void *data) {
    if (data == 0) {
        data = (const void *)FUN_08018664;
    }
    gUnknown_03003150[value] = data;
}

void FUN_0801fc54(void) { gUnknown_03004470 = 0; }

void FUN_0801fc60(void) {
    u8 *countAddress = &gUnknown_03004470;
    u8 queued = *countAddress;
    u8 *count = countAddress;

    if (queued != 0) {
        u8 index = 0;

        if (index < queued) {
            register u32 specialSong asm("r8") = 0x333;

            do {
                u16 songId = gUnknown_03004480[index].songId;
                u16 parameter = gUnknown_03004480[index].parameter;

                FUN_0801f618(songId);
                FUN_0801f644(songId);
                FUN_0801f66c(songId, 0xFFFF, (s8)parameter);
                if (songId == specialSong) {
                    FUN_0801f6a0(songId, 0xFFFF, 0x80);
                }
                index++;
            } while (index < gUnknown_03004470);
        }
    }
    *count = 0;
}

void FUN_0801ffa4(u8 force) {
    if (gUnknown_030048d0 != 0 || force != 0) {
        FUN_0804a594(gUnknown_030044d0, (const void *)0x07000000, 0x100);
    }
    gUnknown_030048d0 = 0;
}

void FUN_08020028(void) { gUnknown_030048d4 = 0; }

u32 FUN_08020034(u16 first, u16 second, u16 third) {
    struct UnknownQueuedValue *entry;

    if (gUnknown_030048d4 < 0) {
        return 0;
    }
    entry = &gUnknown_030044d0[(u8)gUnknown_030048d4];
    entry->first = first;
    entry->second = second;
    entry->third = third;
    gUnknown_030048d4++;
    return 1;
}

void FUN_08020074(void) {
    if (gUnknown_030048d4 >= 0) {
        u8 index = gUnknown_030048d4;
        register u32 offset asm("r1") = index << 3;
        register struct UnknownQueuedValue *base asm("r0") = gUnknown_030044d0;
        struct UnknownQueuedValue *entry;

        asm volatile("" : "+r"(offset), "+r"(base));
        entry = (struct UnknownQueuedValue *)(offset + (u32)base);

        if ((s8)index >= 0) {
            register u32 rawValue asm("r0") = 0x200;
            register u16 value asm("r3") = rawValue;

            asm volatile("" : "+r"(value));
            do {
                entry->first = value;
                entry++;
                index++;
            } while ((s8)index >= 0);
        }
    }
    gUnknown_030048d0 = 1;
}

void FUN_080200bc(u16 index, u16 first, u16 second, u16 third) {
    struct UnknownQueuedValue *entry = &gUnknown_030044d0[index];

    entry->first = first;
    entry->second = second;
    entry->third = third;
}

void FUN_080200d8(u16 index, u16 first, u16 second, u16 third, u16 fourth) {
    struct UnknownQueuedValue *entries = &gUnknown_030044d0[index * 4];

    entries[0].fourth = first;
    entries[1].fourth = second;
    entries[2].fourth = third;
    entries[3].fourth = fourth;
}

void FUN_080200f8(void) {
    s16 i;

    for (i = 0; i <= 3; i++) {
        gUnknown_030000c8[i] = 0;
    }
    gUnknown_0300019a = 1;
    gUnknown_030044c0 = 0;
}

void FUN_08020134(u32 value) { gUnknown_0300019c = value | 1; }

void FUN_0802021c(u8 first, u8 second);

void FUN_080201f8(void) {
    gUnknown_030048e0.fifth = 0;
    gUnknown_030048e0.third = 0;
    gUnknown_030048e0.first = 0;
    gUnknown_030048e0.second = 0xFFFF;
    FUN_0802021c(0, 0);
}

void FUN_0802021c(u8 first, u8 second) {
    if (first == 0 || second == 0) {
        first = 15;
        second = 7;
    }
    gUnknown_030048e0.seventh = first;
    gUnknown_030048e0.sixth = first;
    gUnknown_030048e0.eighth = second;
}

void FUN_08020360(void) { gUnknown_030048f0 = 0; }

void FUN_0802036c(u32 first, u32 second, u32 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 0;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_080203a4(u32 first, u32 second, u16 third, u16 fourth, u16 fifth) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third | (fourth << 16);
        gUnknown_03004900[index].fourth = fifth;
        gUnknown_03004900[index].type = 1;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_08020408(u32 first, u32 second) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = 0;
        gUnknown_03004900[index].type = 2;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_08020440(u32 first, u16 second, u16 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 3;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_0802047c(u32 first, u8 second, u16 third) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 4;
        gUnknown_030048f0 = index + 1;
    }
}

void FUN_080204b8(u32 first, u16 second, u8 third, u16 fourth) {
    u32 index = gUnknown_030048f0;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].fourth = third;
        gUnknown_03004900[index].third = fourth;
        gUnknown_03004900[index].type = 5;
        gUnknown_030048f0 = index + 1;
    }
}

u8 FUN_08020500(u16 *destination, const u16 *source, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*destination & 0x7FFF) != (*source & 0x7FFF)) {
            if ((*destination & 0x1F) > (*source & 0x1F)) {
                (*destination)--;
            }
            if ((*destination & 0x1F) < (*source & 0x1F)) {
                (*destination)++;
            }
            if ((*destination & 0x3E0) > (*source & 0x3E0)) {
                *destination -= 0x20;
            }
            if ((*destination & 0x3E0) < (*source & 0x3E0)) {
                *destination += 0x20;
            }
            if ((*destination & 0x7C00) > (*source & 0x7C00)) {
                *destination -= 0x400;
            }
            if ((*destination & 0x7C00) < (*source & 0x7C00)) {
                *destination += 0x400;
            }
            result = 0;
        }
        destination++;
        source++;
        i++;
    }
    return result;
}

u32 FUN_080205d0(void) {
    switch (gUnknown_03004b04) {
    case 0:
        return 1;
    case 1:
        if (gUnknown_03004b00 & 0x8000) {
            return 1;
        }
        gUnknown_03004b00 += gUnknown_03004b08;
        if (gUnknown_03004b00 > 0x8000) {
            gUnknown_03004b00 = 0x8000;
            FUN_0801fba0(0x54, 0x10);
        } else {
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    case 2:
        if (gUnknown_03004b00 == 0) {
            return 1;
        }
        if (gUnknown_03004b00 < gUnknown_03004b08) {
            gUnknown_03004b00 = 0;
            FUN_0801fba0(0x54, 0);
        } else {
            gUnknown_03004b00 -= gUnknown_03004b08;
            FUN_0801fba0(0x54, (gUnknown_03004b00 & 0xF800) >> 11);
        }
        break;
    }
    return 0;
}

u32 FUN_0802067c(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if (*colors & 0x7FFF) {
            if (*colors & 0x1F) {
                (*colors)--;
            }
            if (*colors & 0x3E0) {
                *colors -= 0x20;
            }
            if (*colors & 0x7C00) {
                *colors -= 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

u32 FUN_080206ec(u16 *colors, u16 count) {
    u32 result = 1;
    u16 i = 0;

    while (i < count) {
        if ((*colors & 0x7FFF) != 0x7FFF) {
            if ((*colors & 0x1F) <= 0x1E) {
                (*colors)++;
            }
            if ((*colors & 0x3E0) <= 0x3DF) {
                *colors += 0x20;
            }
            if ((*colors & 0x7C00) <= 0x7BFF) {
                *colors += 0x400;
            }
            result = 0;
        }
        colors++;
        i++;
    }
    return result;
}

void FUN_08020774(u16 *destination, const u16 *source, u16 count, u16 factor) {
    u16 i = 0;

    while (i < count) {
        u16 result;

        result = (((0x1FU & *source) * factor) >> 4) & 0x1F;
        result |= (((0x3E0U & *source) * factor) >> 4) & 0x3E0;
        result |= (((0x7C00U & *source) * factor) >> 4) & 0x7C00;
        *destination = result;
        destination++;
        source++;
        i++;
    }
}

void FUN_080207ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020840(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xFF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020898(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 1;
    gUnknown_03004b00 = 0;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_080208ec(u16 value) {
    u16 *result;

    FUN_0801fba0(0x50, 0xBF);
    FUN_0801fba0(0x54, 0x10);
    gUnknown_03004b04 = 2;
    gUnknown_03004b00 = 0x8000;
    if (value == 0) {
        value = 1;
    }
    result = &gUnknown_03004b08;
    *result = FUN_0804afa4(0x7FFF, value);
    if (*result == 0) {
        *result = 1;
    }
}

void FUN_08020944(void) {
    FUN_0801fba0(0x50, 0);
    FUN_0801fba0(0x54, 0);
    gUnknown_03004b04 = 0;
    gUnknown_03004b00 = 0;
    gUnknown_03004b08 = 0;
}

u8 FUN_08020d20(u32 *destination, u32 x, u32 y, u16 tile, u32 value) {
    u16 normalizedTile = tile;
    u32 offset = x >> 3;
    u32 shift = 7;
    u32 *output;
    const u8 *source;
    u8 i;
    u32 reverseShift;

    shift &= x;
    offset <<= 5;
    offset += y;
    offset <<= 2;
    output = (u32 *)((u8 *)destination + offset);
    source = &gUnknown_08071b7c[(normalizedTile & 0x7FFF) << 5];
    i = 0;
    reverseShift = 8 - shift;

    do {
        u8 first;
        u8 second;
        u8 upper;
        u8 middle;
        u8 lower;

        first = source[0];
        upper = first << shift;
        middle = first >> reverseShift;
        second = source[1];
        middle |= second << shift;
        lower = second >> reverseShift;

        if (upper != 0) {
            output[0] = (output[0] & gUnknown_0807a37c[upper]) | (gUnknown_0807a77c[upper] * value);
        }
        if (middle != 0) {
            output[32] =
                (output[32] & gUnknown_0807a37c[middle]) | (gUnknown_0807a77c[middle] * value);
        }
        if (lower != 0) {
            output[64] =
                (output[64] & gUnknown_0807a37c[lower]) | (gUnknown_0807a77c[lower] * value);
        }
        source += 2;
        output++;
        i++;
    } while (i <= 15);

    return gUnknown_0807173c[normalizedTile & 0x7FFF];
}

u32 FUN_08020e28(const u16 *stream) {
    register u32 maximum asm("r5") = 0;
    register u32 width asm("r4") = 0;
    register const u16 *streamPosition asm("r2") = stream;
    register u32 token asm("r3") = *streamPosition;

    if (token != 0xFFFE) {
        u32 newline = 0xFFFD;
        u32 skip = newline - 1;
        const u8 *widths = gUnknown_0807173c;
        u32 extraFirst = 0xFFFB;
        u32 extraSecond = 0xFFFA;
        u32 end = 0xFFFE;

        do {
            if (token == newline) {
                if (maximum < width) {
                    maximum = width;
                }
                width = 0;
            } else if (token != skip) {
                if (token == extraFirst || token == extraSecond || token == 0xFFF9) {
                    streamPosition++;
                } else {
                    register u32 noWidth asm("r0") = 0xFFF8;

                    asm("" : "+r"(noWidth));
                    if (token != noWidth && token != noWidth - 1) {
                        width += widths[token & 0x7FFF];
                    }
                }
            }
            streamPosition++;
            token = *streamPosition;
        } while (token != end);
    }
    return width;
}

void FUN_08020ecc(u32 first, const u8 *source, u8 *destination, u32 width, u32 height, u8 fill) {
    u32 pattern;
    u32 value;

    gUnknown_03004b10.field0 = first;
    gUnknown_03004b10.source = source;
    gUnknown_03004b10.destination = destination;
    gUnknown_03004b10.end = (u32)destination + width * height * 32;
    gUnknown_03004b10.width = width;
    gUnknown_03004b10.rowSize = height * 8;
    gUnknown_03004b10.stride = height * 8;
    gUnknown_03004b10.blockSize = height * 16;
    value = fill & 0xF;
    pattern = value | (value << 4) | (value << 8) | (value << 12);
    pattern |= pattern << 16;
    gUnknown_03004b10.fill = pattern;
}

void FUN_08020f18(void) {
    struct UnknownBufferState *state = &gUnknown_03004b10;
    u32 *destination = (u32 *)state->destination;
    u32 count = state->rowSize * state->width - 2;
    u32 offset;
    u32 i;

    for (i = 0; i < count; i++) {
        *destination = destination[2];
        destination++;
    }

    offset = state->stride * 4 - 8;
    destination = (u32 *)(state->destination + offset);
    for (i = 0; i < state->width; i++) {
        destination[0] = destination[1] = state->fill;
        destination += state->stride;
    }
}

void FUN_08020f78(u32 *data) {
    u32 *start = data;
    u32 i;

    for (i = 0; i <= 0x3FD; i++) {
        *data = data[2];
        data++;
    }

    data = start + 30;
    for (i = 0; i <= 31; i++) {
        data[1] = 0;
        data[0] = 0;
        data += 32;
    }
}

u8 FUN_08020f64(u16 value) {
    struct UnknownBufferState *state = &gUnknown_03004b10;

    value &= 0x7FFF;
    return state->source[value];
}

u16 FUN_08020fac(u16 value) {
    const u8 *source = gUnknown_0807173c;

    value &= 0x7FFF;
    return source[value];
}

void FUN_08020fbc(u16 *destination, const u16 *source, u16 width, u16 rows) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination++ = *source++;
        }
        destination += 32 - width;
    }
}

void FUN_08021000(u16 *destination, const u16 *source, u16 width, u16 rows, u16 offset) {
    u16 row;

    for (row = 0; row < rows; row++) {
        u16 column;

        for (column = 0; column < width; column++) {
            *destination = offset + *source;
            destination++;
            source++;
        }
        destination += 32 - width;
    }
}

void FUN_080210d8(void) {
    u32 zero = 0;

    CpuSet(&zero, gUnknown_03004b30, 0x05000080);
}

void FUN_080210f8(u16 value) { gUnknown_03004b30[value >> 2] = 0; }

void FUN_0802110c(void) {
    gUnknown_03004d30 = &gUnknown_030033e0;
    gUnknown_030033e0.next = 0;
    gUnknown_030033e0.size = 0xFF8;
}

void FUN_080211d8(u8 value) {
    gUnknown_03004d38 = value;
    gUnknown_03004d34 = 0;
}

void FUN_08021244(u8 index) {
    u32 bit = 1 << index;

    if (gUnknown_03004d34 & bit) {
        gUnknown_03004d34 &= ~bit;
    }
}

u8 FUN_08021484(void) {
    u8 result = 1;
    u8 index;

    for (index = 1; index <= 3; index++) {
        if (((gUnknown_03004d40.firstFlags >> index) & 1) &&
            ((gUnknown_03004d40.secondFlags >> index) & 1)) {
            result++;
        }
    }
    return result;
}

void FUN_08021518(void) {
    gUnknown_020000e0 = 0x12345678;
    SoftResetExram(0x40);
}

u32 FUN_08021534(void) {
    if (FUN_08018c8c(&gUnknown_03004d40) != 0) {
        return 0xFF;
    }
    if (FUN_0801950c(&gUnknown_03004d40) != 0) {
        return 1;
    }
    return 0;
}

u32 FUN_0802158c(void) {
    LZ77UnCompWram(gUnknown_03004d94, (void *)0x02000100);
    return 0;
}

u32 FUN_08021564(void) {
    const void *source = gUnknown_03004d94;
    u32 size = gUnknown_03004d8c;

    CpuSet(source, (void *)(0x0203B000 - size), (size << 10) >> 11);
    return 0;
}

u32 FUN_080218ac(u8 sector, u8 *data) {
    ReadFlash(sector, 0, data, 0x1000);
    if (VerifyFlashSector(sector, data) == 0) {
        return 0;
    }
    return 1;
}

u32 FUN_0802188c(void) {
    SetFlashTimerIntr(2, &gUnknown_0300315c);
    gUnknown_03006788();
    return 0;
}

u32 FUN_080218dc(u8 sector, u8 *data) {
    SetFlashTimerIntr(2, &gUnknown_0300315c);
    if ((u16)gUnknown_0300677c(sector, data) != 0) {
        return 1;
    }
    if (VerifyFlashSector(sector, data) != 0) {
        return 1;
    }
    return 0;
}

void FUN_08021a10(u8 *data, u32 count) {
    u32 end = count - 1;
    u8 previous = data[0];
    u32 i;

    for (i = 0; i < end; i++) {
        u8 next = data[1];
        data[1] = next - gUnknown_0807b780[previous];
        previous = next;
        data++;
    }
}

u32 FUN_08021a40(const u8 *data, u32 size) {
    u32 value = -1;
    u32 i;

    for (i = 0; i < size; i++) {
        u32 index = (data[0] ^ value) & 0xFF;
        value = ((value >> 8) & 0xFFFFFF) ^ gUnknown_0807b880[index];
        data++;
    }
    value = ~value;
    return value;
}

void FUN_08021a84(void) {
    u32 i;
    u32 offset;
    u8 *validity;
    u16 **list;

    memset(gUnknown_03004dbc->bits, 0, sizeof(gUnknown_03004dbc->bits));
    gUnknown_03004db0 = (u16 *)(gUnknown_03002110.records + gUnknown_03002110.selector * 56);
    i = 0;
    validity = gUnknown_03002110.validity;
    list = &gUnknown_03004db0;
    offset = 0;
    do {
        u16 value = *(u16 *)((u32)offset + (u32)gUnknown_03004db0);

        if (*(u8 *)((u32)value + (u32)validity) != 0xFF &&
            *(u8 *)((u32)value + (u32)validity) != 0) {
            FUN_08021e70(value);
        } else {
            u16 *entry = (u16 *)((u32)offset + (u32)*list);
            *entry = *(const u16 *)((const u8 *)data_gap_003 + offset);
            FUN_08021e70(*entry);
        }
        offset += 2;
        i++;
    } while (i <= 0x1A);
}

u32 FUN_08021e48(u16 value) {
    if (gUnknown_03002110.validity[value] != 0xFF) {
        return 1;
    }
    return 0;
}

void FUN_08021e70(u16 value) {
    gUnknown_03004dbc->bits[value >> 5] |= gUnknown_0807163c[value & 0x1F];
}

u32 FUN_08021ec8(u16 value) {
    if ((gUnknown_03004dbc->bits[value >> 5] & gUnknown_0807163c[value & 0x1F]) != 0) {
        return 1;
    }
    return 0;
}

void FUN_08021f04(void) {
    gUnknown_03004dc0++;
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08021f20(void) {
    FUN_08021b0c();
    gUnknown_03004dc8 = 1;
}

void FUN_0802436c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb4f0;
    node->position->tile = 0;
    node->position->x = 461;
    node->position->y = 14;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080243a4;
}

void FUN_080243a4(struct UnknownListNode *node) {
    if (gUnknown_03004dbc->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        node->position->x = gUnknown_03004dbc->field12 + 205;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080243d4(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb820;
    node->position->tile = 0;
    node->position->x = 487;
    node->position->y = 34;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_0802440c;
}

void FUN_0802440c(struct UnknownListNode *node) {
    struct UnknownState03004dbc *state = gUnknown_03004dbc;

    if (state->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        u16 *count = &gUnknown_03004dd8;

        if (*count <= 12) {
            return;
        }
        {
            struct UnknownPosition *position = node->position;
            u32 numerator = 115 * gUnknown_03004ddc;
            u32 denominator = ((*count + 3) & -4) - 12;

            position->y = FUN_0804afa4(numerator, denominator) + 34;
        }
        node->position->x = state->field12 + 231;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0802446c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = 256;
    node->position->y = node->position->field13 * 24 + 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244ac;
}

void FUN_080244ac(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_080244bc(struct UnknownListNode *node) {
    FUN_0801f92c(node, 4, 4);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080244d8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = -128;
    node->position->y = 4;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244ac;
}

void FUN_0802450c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = -128;
    node->position->y = 4;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080244bc;
}

void FUN_08024540(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, 256) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08024570(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, -128) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080245a0(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + 120;
    FUN_0801f9a8(node, node->position->field13 * 24 + 36);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080245dc(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_080245ec(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + 0x68;
    FUN_0801fed8(node->field6, 0);
}

void FUN_0802460c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb498;
    node->position->x = 256;
    node->position->y = node->position->field13 * 24 + 36;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080245a0;
}

void FUN_0802464c(struct UnknownListNode *node) {
    if ((u8)FUN_0801f92c(node, 120, node->position->field13 * 24 + 36) != 0 &&
        (s16)gUnknown_03004dbc->field12 == 0) {
        node->data = FUN_080245a0;
    }
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024698(struct UnknownListNode *node) {
    if ((u8)FUN_0801f978(node, 256) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080246c8(struct UnknownListNode *node) {
    FUN_08021244(node->position->field14);
    FUN_0801f8c0(node);
}

void FUN_08024708(struct UnknownListNode *node) {
    node->position->tile = 0;
    node->position->x = 360;
    node->position->y = 8;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_080245ec;
}

void FUN_08024738(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb678;
    node->position->tile = node->position->field13 << 4;
    node->position->x = 256 + gUnknown_08edb834[node->position->field13 * 2];
    node->position->y = gUnknown_08edb834[node->position->field13 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_08024794;
}

void FUN_08024794(struct UnknownListNode *node) {
    node->position->x = gUnknown_03004dbc->field12 + gUnknown_08edb834[node->position->field13 * 2];
    FUN_0801fed8(node->field6, 0);
}

void FUN_080247c4(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004dbc->field16 - gUnknown_03004dbc->field14;
    u32 remainder = difference % 6;
    u32 quotient = difference / 6;

    node->position->field0 = gUnknown_08edb750;
    node->position->tile = 336;
    node->position->x = remainder * 32 + 24;
    node->position->y = quotient * 40 + 32;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024a34;
}

void FUN_0802482c(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004de0 - gUnknown_03004ddc;
    u32 column = difference & 3;
    u32 row = difference >> 2;

    node->position->field0 = gUnknown_08edb750;
    node->position->tile = 336;
    node->position->x = gUnknown_08edb91c[column];
    node->position->y = gUnknown_08edb91c[row + 4];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024aac;
}

void FUN_08024894(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb760[0];
    node->position->tile = 336;
    node->position->x = gUnknown_08edb834[gUnknown_03004dbc->field2 * 2];
    node->position->y = gUnknown_08edb834[gUnknown_03004dbc->field2 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024b1c;
}

void FUN_080248f0(struct UnknownListNode *node) {
    struct UnknownAllocation248f0 *allocation = node->allocation;

    CpuSet(allocation, gUnknown_08edb5c8, 0x04000004);
    allocation->field6 = 0;
    allocation->field14 = 126;
    node->position->field0 = allocation;
    node->position->tile = 0;
    node->position->x = 160;
    node->position->y = 29;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024c20;
}

void FUN_08024940(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb7f0[0];
    node->position->tile = 336;
    node->position->x = gUnknown_08edb854[node->position->field13 * 2];
    node->position->y = gUnknown_08edb854[node->position->field13 * 2 + 1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024c30;
}

void FUN_08024994(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801f9a8(node, node->position->field13 * 24 + 16);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080249e4(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801f9a8(node, node->position->field13 * 24 + 36);
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024a34(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004dbc->field16 - gUnknown_03004dbc->field14;
    u32 remainder = difference % 6;
    u32 quotient = difference / 6;
    s16 x = remainder * 32 + 24;

    FUN_0801f92c(node, x, (s16)(quotient * 40 + 32));
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024aac(struct UnknownListNode *node) {
    u32 difference = gUnknown_03004de0 - gUnknown_03004ddc;
    u32 column = difference & 3;
    u32 row = difference >> 2;

    FUN_0801f92c(node, (s16)gUnknown_08edb91c[column], (s16)gUnknown_08edb91c[row + 4]);
    node->position->field0 = gUnknown_08edb740[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024b1c(struct UnknownListNode *node) {
    FUN_0801f92c(node, (s16)gUnknown_08edb834[gUnknown_03004dbc->field2 * 2],
                 (s16)gUnknown_08edb834[gUnknown_03004dbc->field2 * 2 + 1]);
    node->position->field0 = gUnknown_08edb760[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024b90(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[0];
    node->position->tile = 336;
    node->position->x = 120;
    node->position->y = node->position->field13 * 24 + 16;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08024994;
}

void FUN_08024bd8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb740[0];
    node->position->tile = 336;
    node->position->x = 120;
    node->position->y = node->position->field13 * 24 + 36;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080249e4;
}

void FUN_08024c20(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_08024c30(struct UnknownListNode *node) {
    FUN_0801f92c(node, (s16)gUnknown_08edb854[node->position->field13 * 2],
                 (s16)gUnknown_08edb854[node->position->field13 * 2 + 1]);
    node->position->field0 = gUnknown_08edb7f0[gUnknown_08edb84c[(gUnknown_03004dc0 & 28) >> 2]];
    FUN_0801fed8(node->field6, 0);
}

void FUN_08024c90(struct UnknownListNode *node) {
    u8 value = node->position->field13;
    u8 column = value % 6;
    u8 row = value / 6;

    node->position->field0 = gUnknown_08edb570;
    node->position->tile = 0;
    node->position->x = 256 + gUnknown_08edb86c[column];
    node->position->y = gUnknown_08edb86c[row + 6];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_08024d0c;
}

static inline u8 FUN_080256fc_validity(struct UnknownState03002110 *state, u16 index) {
    return state->validity[index];
}

void FUN_080256fc(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb488;
    node->position->tile = 656;
    node->position->x = 272;
    node->position->y = 45;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025734;
}

void FUN_08025734(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 16;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025770(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb4f8;
    node->position->tile = 0;
    node->position->x = node->position->field13 * 6 + 316;
    node->position->y = 37;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080257b8;
}

void FUN_080257b8(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        struct UnknownPosition *position = node->position;
        struct UnknownState03004dbc *state = gUnknown_03004dbc;
        u32 x = position->field13 * 6 + 60;

        position->x = x + state->field12;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025800(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb5a0;
    node->position->tile = 0;
    node->position->x = 272;
    node->position->y = 38;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025838;
}

void FUN_08025838(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 16;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025874(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb548;
    node->position->tile = 0;
    node->position->x = 300;
    node->position->y = 106;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080258ac;
}

void FUN_080258ac(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 44;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080258e8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb548;
    node->position->tile = 0;
    node->position->x = 300;
    node->position->y = 112;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_080258ac;
}

void FUN_08025920(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 44;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0802595c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb558;
    node->position->tile = 0;
    node->position->x = 328;
    node->position->y = 141;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025994;
}

void FUN_08025994(struct UnknownListNode *node) {
    if (FUN_080256fc_validity(&gUnknown_03002110, gUnknown_03004dd4) != 0xff) {
        node->position->x = gUnknown_03004dbc->field12 + 72;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080259d0(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb558;
    node->position->tile = 40;
    node->position->x = 312;
    node->position->y = 141;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = FUN_08025a08;
}

void FUN_08025a08(struct UnknownListNode *node) {
    u16 index = gUnknown_03004dd4;
    struct UnknownState03004dbc *state = gUnknown_03004dbc;

    if (state->field3 != 0) {
        FUN_0801f8c0(node);
    } else if (FUN_080256fc_validity(&gUnknown_03002110, index) != 0xff) {
        node->position->x = state->field12 + 56;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025a58(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb468;
    node->position->tile = 425;
    node->position->x = 284;
    node->position->y = 51;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->position->field14 = 0xff;
    node->data = FUN_08025628;
}

void FUN_08025a98(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    u32 i;

    node->position->field0 = gUnknown_08edb5c0;
    node->position->tile = 0;
    node->position->x = 362;
    node->position->y = 4;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;

    i = 0;
    do {
        struct UnknownListNode *child = FUN_0801f7d0(FUN_08025c14, 16, gUnknown_03003e20, 0);

        child->position->field13 = i;
        child->position->tile = 0;
        allocation->childIds[i] = child->field6;
        i++;
    } while (i <= 6);

    gUnknown_03003e20[allocation->childIds[3]].position->tile = 10;
    gUnknown_03003e20[allocation->childIds[4]].position->tile = gUnknown_03004da8 / 100;
    gUnknown_03003e20[allocation->childIds[5]].position->tile = (gUnknown_03004da8 % 100) / 10;
    gUnknown_03003e20[allocation->childIds[6]].position->tile = gUnknown_03004da8 % 10;
    node->data = FUN_08025b78;
}

void FUN_08025b78(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    struct UnknownState03004dbc *state = gUnknown_03004dbc;
    u32 value;

    if (state->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        node->position->x = state->field12 + 106;
        value = gUnknown_03004dc4 * 5;
        gUnknown_03003e20[allocation->childIds[0]].position->tile = value / 100;
        gUnknown_03003e20[allocation->childIds[1]].position->tile = (value % 100) / 10;
        gUnknown_03003e20[allocation->childIds[2]].position->tile = value % 10;
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025c14(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_08edb5b8;
    node->position->x = node->position->field13 * 8 + 367;
    node->position->y = 9;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 12;
    node->data = FUN_08025c4c;
}

void FUN_08025c4c(struct UnknownListNode *node) {
    struct UnknownPosition *position = node->position;
    struct UnknownState03004dbc *state = gUnknown_03004dbc;
    u32 x = position->field13 * 8 + 111;

    position->x = x + state->field12;
    if (state->field3 != 0) {
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08025c84(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    u8 index = FUN_080211f0();
    u16 savedFirst;
    u16 savedSecond;
    u32 offset;

    gUnknown_03004dbc->field12 = 256;
    savedFirst = gUnknown_03004de0;
    savedSecond = gUnknown_03004ddc;
    offset = index * 9;
    FUN_0802036c(0x06015300 + offset * 128, (u32)gUnknown_03004db8 + 3456, 1152);
    allocation->child = FUN_0801f7d0(FUN_0802450c, 16, gUnknown_03003e20, 0);
    allocation->child->position->tile = offset * 4 + 664;
    allocation->child->position->field13 = 3;
    allocation->child->position->field14 = index;
    gUnknown_03004dbc->filler0[0] = 3;
    FUN_08025d50(node);
    gUnknown_03004de0 = savedFirst;
    gUnknown_03004ddc = savedSecond;
    gUnknown_03004dd4 = gUnknown_03004df0[gUnknown_03004de0];
}

void FUN_08025d50(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    u32 zero;
    u16 *destination;
    u16 value;
    u32 i;

    gUnknown_03005240 = gUnknown_08ed9740[gUnknown_03002110.field119];
    FUN_08025064(0xff);
    gUnknown_03004de0 = gUnknown_03004ddc = 0;
    gUnknown_03004dd0 = 3;
    LZ77UnCompVram(gUnknown_0807c620, (void *)0x0600f000);
    LZ77UnCompVram(gUnknown_0807c060, (void *)0x0600e000);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, (u8 *)0x0600b000, 16, 14, 0);
    zero = 0;
    CpuFastSet(&zero, (void *)0x0600b000, 0x01000700);

    value = 4480;
    destination = (u16 *)0x0600f11a;
    i = 0;
    do {
        destination[0] = value++;
        destination[32] = value++;
        destination[64] = value++;
        destination[96] = value++;
        destination[128] = value++;
        destination[160] = value++;
        destination[192] = value++;
        destination[224] = value++;
        destination[256] = value++;
        destination[288] = value++;
        destination[320] = value++;
        destination[352] = value++;
        destination[384] = value++;
        destination[416] = value++;
        destination++;
        i++;
    } while (i <= 14);

    gUnknown_03004dbc->field18 = 0;
    gUnknown_03004dbc->field3 = 0;
    i = 0;
    do {
        struct UnknownListNode *child = FUN_0801f7d0(FUN_08025120, 16, gUnknown_03003e20, 0);

        child->position->field13 = i;
        i++;
    } while (i <= 11);

    allocation->child16 = FUN_0801f7d0(FUN_080252d0, 60, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_080243d4, 16, gUnknown_03003e20, 0);
    FUN_0801f7d0(FUN_0802436c, 16, gUnknown_03003e20, 0);
    gUnknown_03004dd4 = gUnknown_03004df0[gUnknown_03004de0];
    node->data = FUN_08025f5c;
}

void FUN_08025f5c(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    s16 value;

    gUnknown_03004dbc->field12 = (s16)gUnknown_03004dbc->field12 / 2;
    FUN_0801fba0(16, -gUnknown_03004dbc->field12 & 0x1ff);
    FUN_0801fba0(20, -gUnknown_03004dbc->field12 & 0x1ff);
    value = gUnknown_03004dbc->field12;
    if (value == 0) {
        allocation->child40 = FUN_0801f7d0(FUN_0802482c, 16, gUnknown_03003e20, 0);
        node->data = FUN_08025fd4;
        gUnknown_03001b10[7] = 0;
        gUnknown_03001b10[6] = 0;
        FUN_08018444();
    }
}

void FUN_08026634(struct UnknownListNode *node) {
    struct UnknownAllocation25a98 *allocation = node->allocation;
    u32 zero;

    if (node->position->field15 != 0) {
        node->position->field15--;
    } else {
        gUnknown_03001b10[7] = 0;
        gUnknown_03001b10[6] = 0;
        gUnknown_03001b10[5] = 0;
        gUnknown_03001b10[4] = 0;
        gUnknown_03001b10[3] = 0;
        gUnknown_03001b10[2] = 0;
        gUnknown_03001b10[1] = 0;
        gUnknown_03001b10[0] = 0;
        FUN_08018444();
        zero = 0;
        CpuFastSet(&zero, (void *)0x0600b000, 0x01000700);
        gUnknown_03004dbc->field18 = 0;
        allocation->child40 = FUN_0801f7d0(FUN_0802482c, 16, gUnknown_03003e20, 0);
        node->data = FUN_08025fd4;
    }
}

void FUN_08026d6c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 0x200) != 0) {
        u32 value;

        gUnknown_03001b10[0] = 0;
        gUnknown_03001b10[1] = 0;
        FUN_08021f20();
        FUN_08034f28();
        gUnknown_03005330.callback = FUN_08021f20;
        value = ((struct UnknownUnsignedHalfword *)&gUnknown_03004dd4)->value;
        gUnknown_03005330.field8 = value;
        value &= 0xffff;
        gUnknown_03005330.field6 = value;
        value &= 0xffff;
        gUnknown_03005330.field4 = value;
        gUnknown_03005330.field10 = 1;
        gUnknown_03005330.field11 = 1;
        gUnknown_03002030 = FUN_08034f28;
    }
}

void FUN_080278f8(struct UnknownListNode *node) {
    void (*callback)(struct UnknownListNode *) = FUN_08025fd4;

    node->data = callback;
    gUnknown_03001b10[7] = 0;
    gUnknown_03001b10[6] = 0;
    FUN_08018444();
    callback(node);
}

void FUN_0802786c(struct UnknownListNode *node) {
    const void *const *row;
    const void *data;

    row = gUnknown_08edb450[gUnknown_03002110.field119];
    data = row[gUnknown_03004dd4];

    FUN_08020b74(0, 0, data, 15, 1);
    node->data = FUN_080264d0;
}

void FUN_080278b4(struct UnknownListNode *node) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)0x0600b000, 0x01000700);
    FUN_08020b74(0, 0, *(const void **)gUnknown_03005240, 15, 1);
    node->data = FUN_080266ac;
}

void FUN_08027920(struct UnknownListNode *node) {
    u16 *values = gUnknown_03001b10;
    u32 zero;
    u32 value = 0;

    values[0] = value;
    values[1] = value;
    FUN_080184c8();
    FUN_08018c3c();
    zero = value;
    CpuFastSet(&zero, (void *)0x0600b000, 0x01000700);
    FUN_08020b74(0, 0, ((const void *const *)gUnknown_03005240)[11], 15, 1);
    node->position->field15 = 120;
    node->data = FUN_08026634;
}

void FUN_0802797c(struct UnknownListNode *node) {
    const void *const *row;
    const void *data;

    row = gUnknown_08edb450[gUnknown_03002110.field119];
    data = row[gUnknown_03004dd4];
    FUN_08020b74(0, 0, data, 15, 1);
    node->data = FUN_080279c4;
}

void FUN_080279c4(struct UnknownListNode *node) {
    u32 value = FUN_0801f9e8(0x3579);

    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            gUnknown_03004dd4 = gUnknown_03005244;
            node->data = FUN_08027920;
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }

    if ((gUnknown_030048e0.third & 0x100) != 0) {
        node->data = FUN_08026844;
        FUN_0801f618(420);
    }
}

void FUN_08027a4c(struct UnknownListNode *node) {
    u32 value;
    register struct Unknown16ByteRecord *record asm("r1");
    register u8 index asm("r0");

    gUnknown_03001b1c.type = 13;
    gUnknown_03001b1c.index = gUnknown_030051f0;
    gUnknown_03001b1c.value = gUnknown_03004dd4;
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            node->data = (const void *)((u32)FUN_08027920 + 1);
            FUN_0801f618(419);
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }

    index = gUnknown_030051f0;
    record = &gUnknown_030016fc[index];
    if (record->field0 == 10) {
        node->data = FUN_08027b84;
    }
}

void FUN_08027ae8(struct UnknownListNode *node) {
    u32 value;
    register struct Unknown16ByteRecord *record asm("r1");
    register u8 index asm("r0");

    gUnknown_03001b1c.type = 12;
    gUnknown_03001b1c.index = gUnknown_030051f0;
    gUnknown_03001b1c.value = gUnknown_03004dd4;
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            node->data = (const void *)((u32)FUN_08027920 + 1);
            FUN_0801f618(419);
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }

    index = gUnknown_030051f0;
    record = &gUnknown_030016fc[index];
    if (record->field0 == 10) {
        node->data = FUN_08027b84;
    }
}

void FUN_08027b84(struct UnknownListNode *node) {
    u32 value;
    register struct UnknownFourByteMessage *message asm("r1") = &gUnknown_03001b1c;

    {
        register u32 byteZero asm("r0") = 0;

        message->type = byteZero;
        message->index = byteZero;
    }
    asm volatile("" : : : "r0");
    {
        register u16 halfwordZero asm("r0") = 0;

        message->value = halfwordZero;
    }
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            node->data = (const void *)((u32)FUN_08027920 + 1);
            FUN_0801f618(419);
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }
    node->data = FUN_080266ac;
}

void FUN_08027bfc(struct UnknownListNode *node) {
    u32 value;

    {
        register struct UnknownFourByteMessage *message asm("r1") = &gUnknown_03001b1c;
        register u32 byteZero asm("r0") = 0;

        message->type = byteZero;
        message->index = byteZero;
        asm volatile("" : : : "r0");
        {
            register u16 halfwordZero asm("r0") = 0;

            message->value = halfwordZero;
        }
    }
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            node->data = (const void *)((u32)FUN_08027920 + 1);
            FUN_0801f618(419);
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }

    {
        register struct Unknown16ByteRecord *record asm("r1");
        register u8 index asm("r0");

        index = gUnknown_030051f0;
        record = &gUnknown_030016fc[index];
        if (record->field0 <= 6) {
            node->data = FUN_08027b84;
        }
    }
}

void FUN_08027c8c(struct UnknownListNode *node) {
    u32 value;

    gUnknown_03001b1c.type = 14;
    gUnknown_03001b1c.index = gUnknown_030051f0;
    gUnknown_03001b1c.value = gUnknown_03004dd4;
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (gUnknown_0300525c != (u8)value) {
        gUnknown_030051f4++;
        if (gUnknown_030051f4 > 29) {
            node->data = (const void *)((u32)FUN_08027d18 + 1);
            return;
        }
    } else {
        gUnknown_030051f4 = 0;
    }

    {
        register struct Unknown16ByteRecord *record asm("r1");
        register u8 index asm("r0");

        index = gUnknown_030051f0;
        record = &gUnknown_030016fc[index];
        if (record->field0 <= 6) {
            node->data = (const void *)((u32)FUN_08027d18 + 1);
        }
    }
}

void FUN_08027d18(struct UnknownListNode *node) {
    u32 value;
    register struct UnknownFourByteMessage *message asm("r1") = &gUnknown_03001b1c;

    {
        register u32 byteZero asm("r0") = 0;

        message->type = byteZero;
        message->index = byteZero;
    }
    asm volatile("" : : : "r0");
    {
        register u16 halfwordZero asm("r0") = 0;

        message->value = halfwordZero;
    }
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    FUN_0801f718(31, 60);
    node->data = FUN_08026d6c;
}

void FUN_08027d54(struct UnknownListNode *node) {
    u32 value;

    gUnknown_03001b1c.type = 9;
    gUnknown_03001b1c.index = gUnknown_030051f0;
    gUnknown_03001b1c.value = gUnknown_03004df0[gUnknown_03004de0];
    value = FUN_0801f9e8(0x3579);
    gUnknown_03005248 = value;
    if (node->position->field15 != 0) {
        node->position->field15--;
    } else {
        FUN_080217d0(0);
        node->data = FUN_080274ac;
    }
}

void FUN_08027db8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_080282a8 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value + 32;
        position->x = allocation->field20 - offset;
    }
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027e38(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_080282e0 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value - 32;
        position->x = allocation->field20 + offset;
    }
    node->position->y = allocation->field22 - 32;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027eb8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_08028318 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    node->position->x = allocation->field20 - 32;
    {
        struct UnknownPosition *position = node->position;

        offset = value + 32;
        position->y = allocation->field22 - offset;
    }
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027f38(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_08028350 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    node->position->x = allocation->field20 - 32;
    {
        struct UnknownPosition *position = node->position;

        offset = value - 32;
        position->y = allocation->field22 + offset;
    }
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08027fb8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_08028388 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value + 64;
        position->x = allocation->field20 - offset;
    }
    node->position->y = allocation->field22 - 64;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

void FUN_08028038(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    s16 value;
    s32 offset;

    if (node->position->field14 > 15) {
        node->data = (const void *)((u32)FUN_080283c0 + 1);
        value = 0;
    } else if (node->position->field14 > 3) {
        value = 4 - FUN_0804afa4(node->position->field14 - 4, 3);
    } else {
        value = node->position->field14;
    }
    {
        struct UnknownPosition *position = node->position;

        offset = value - 64;
        position->x = allocation->field20 + offset;
    }
    node->position->y = allocation->field22 - 64;
    node->position->field10 = 3;
    node->position->field11 = FUN_0801fd18(value * 16 + 256, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14++;
}

u32 FUN_080280b8(struct UnknownListNode *node, s32 x, s32 y) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    register s32 newX asm("r3") = (s16)allocation->field20;
    register s32 targetX asm("r1") = (s16)x;
    register s32 newY asm("r0");
    register s32 targetY asm("r5");

    newX = targetX + (newX - targetX) / 2;
    allocation->field20 = newX;
    newY = (s16)allocation->field22;
    targetY = (s16)y;
    newY = targetY + (newY - targetY) / 2;
    allocation->field22 = newY;
    if ((s16)newX == targetX && (s16)newY == targetY) {
        return 1;
    }
    return 0;
}

u32 FUN_08028100(struct UnknownListNode *node, s32 x) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    register s32 newX asm("r0") = (s16)allocation->field20;
    register s32 targetX asm("r1") = (s16)x;

    newX = targetX + (newX - targetX) / 2;
    allocation->field20 = newX;
    if ((s16)newX == targetX) {
        return 1;
    }
    return 0;
}

u32 FUN_0802812c(struct UnknownListNode *node, s32 y) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    register s32 newY asm("r0") = (s16)allocation->field22;
    register s32 targetY asm("r1") = (s16)y;

    newY = targetY + (newY - targetY) / 2;
    allocation->field22 = newY;
    if ((s16)newY == targetY) {
        return 1;
    }
    return 0;
}

void FUN_08028158(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_080282a8 + 1);
}

void FUN_08028190(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_080282e0 + 1);
}

void FUN_080281c8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_08028318 + 1);
}

void FUN_08028200(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_08028350 + 1);
}

void FUN_08028238(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_08028388 + 1);
}

void FUN_08028270(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    register u32 byteZero asm("r4") = 0;
    register u16 halfwordZero asm("r5") = 0;

    asm volatile("" : : "r"(byteZero), "r"(halfwordZero));
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = byteZero;
    node->position->field11 = byteZero;
    allocation->field16 = 256;
    allocation->field18 = halfwordZero;
    node->data = (const void *)((u32)FUN_080283c0 + 1);
}

void FUN_080282a8(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080282e0(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028318(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028350(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 16;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 16;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_08028388(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080283c0(struct UnknownListNode *node) {
    struct UnknownAllocation27db8 *allocation = node->allocation;
    struct UnknownPosition *position = node->position;
    s32 x = allocation->field20 - 32;
    register u32 zero asm("r3") = 0;

    asm volatile("" : : "r"(zero));
    position->x = x;
    node->position->y = allocation->field22 - 32;
    node->position->field10 = zero;
    node->position->field11 = zero;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080283f8(u32 index) {
    register u32 selectedIndex asm("r5") = index;
    void *destination = gUnknown_0600dfc0;
    register const u8 *source asm("r6") = gUnknown_0600da80;
    register const void *const *table asm("r1");
    const void *data;
    u32 i;
    register u32 entry asm("r0");

    for (i = 0; i <= 20; i++) {
        FUN_0804a594(destination, source, 16);
        source += 64;
    }
    if (selectedIndex == 0) {
        return;
    }
    switch (gUnknown_03002110.field119) {
    case 0:
        table = gUnknown_08edb9ac;
        break;
    case 2:
        table = gUnknown_08edb9ec;
        break;
    case 3:
        table = gUnknown_08edba0c;
        break;
    case 4:
        table = gUnknown_08edba2c;
        break;
    case 5:
        table = gUnknown_08edba4c;
        break;
    default:
        table = gUnknown_08edb9cc;
        break;
    }
    entry = selectedIndex - 1;
    asm volatile("" : "+r"(entry));
    data = table[entry];
    {
        register u32 width asm("r1") = FUN_08020ad0(data);
        register u32 halfWidth asm("r0");
        register u32 x asm("r1");

        asm volatile("" : : "r"(width));
        halfWidth = width / 2;
        asm volatile("" : : "r"(halfWidth));
        x = 88 - halfWidth;
        asm volatile("" : : "r"(x));
        FUN_08020b74(x, 0, data, 5, 6);
    }
}

void FUN_08028760(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08028770(struct UnknownListNode *node) {
    struct UnknownAllocation28770 *allocation = node->allocation;
    struct UnknownListNode *created;

    allocation->field0 = 1;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->field13 = 0;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->field13 = 1;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->field13 = 2;
    created = FUN_0801f7d0(FUN_08029014, 16, gUnknown_03003e20, 0);
    created->position->field13 = 3;
    created = FUN_0801f7d0(FUN_080290b4, 16, gUnknown_03003e20, 0);
    allocation->field5 = created->field6;
    if (gUnknown_03005264 == 4) {
        FUN_080283f8(0);
    } else {
        FUN_080283f8(1);
    }
    node->data = (const void *)((u32)FUN_08028814 + 1);
}

void FUN_08028814(struct UnknownListNode *node) {
    u8 pending = FUN_08020500(gUnknown_05000080, gUnknown_0810c5f4, 32) == 0;
    u8 result;

    result = FUN_08020500(gUnknown_050001c0, gUnknown_0815e67c, 16);
    pending |= result == 0;
    result = FUN_08020500(gUnknown_050001e0, gUnknown_081326f4, 16);
    pending |= result == 0;
    result = FUN_08020500(gUnknown_05000200, gUnknown_0810c634, 64);
    pending |= result == 0;
    if (pending == 0) {
        node->data = (const void *)((u32)FUN_080288b4 + 1);
    }
}

void FUN_080288b4(struct UnknownListNode *node) {
    register struct UnknownListNode *current asm("r2") = node;
    register struct UnknownAllocation28770 *allocation asm("r8") = current->allocation;
    u8 count;
    u16 keys;
    u32 ready;
    register u32 one asm("r9");
    register u32 oneAgain asm("r10");
    register u32 secondOne asm("r2");
    register u32 keyMask asm("r5");
    register u32 zero asm("r4");
    register u8 *countAddress asm("r6");
    register u8 *selectionAddress asm("r2");
    register u8 *validationAddress asm("r3");
    register u32 selectionValue asm("r0");
    register u32 secondMask asm("r0");
    register struct UnknownAllocation28770 *selectionRead asm("r4");
    register struct UnknownAllocation28770 *selectionWrite asm("r5");
    register u16 *resetWords asm("r0");
    register u32 *resetFlagAddress asm("r0");
    register u8 *resetCountAddress asm("r0");
    register struct UnknownListNode *nodesAddress asm("r1");
    register s32 recordType asm("r1");
    u8 limitedSelection;

    gUnknown_03001b10[1] = 0x1234;
    if (gUnknown_03005264 == 4) {
        gUnknown_0300525c = FUN_08021484();
    } else {
        count = FUN_0801f9e8(0x1357);
        if (gUnknown_030016f0.field2 != 0x2345) {
            gUnknown_0300525c = count;
        }
    }

    selectionValue = (u32)&gUnknown_0300525c;
    limitedSelection = *(u8 *)selectionValue;
    validationAddress = (u8 *)selectionValue;
    if (limitedSelection == 0xff || limitedSelection == 0) {
        gUnknown_030017c4 = 0;
        *validationAddress = 1;
    }
    selectionAddress = validationAddress;
    limitedSelection = *selectionAddress;
    selectionValue = limitedSelection;
    selectionRead = allocation;
    if (selectionValue != *(u8 *)selectionRead) {
        if (selectionValue > 4) {
            limitedSelection = 4;
        }
        *selectionAddress = limitedSelection;
        selectionValue = *selectionAddress;
        selectionWrite = allocation;
        selectionWrite->field0 = selectionValue;
        if (gUnknown_03005264 == 4) {
            if (*selectionAddress <= 1) {
                FUN_080283f8(0);
            } else {
                FUN_080283f8(*selectionAddress + 4);
            }
        } else {
            FUN_080283f8(*validationAddress);
        }
    }

    keys = gUnknown_030048e0.third;
    one = 1;
    secondOne = 1;
    asm volatile("" : "+r"(secondOne));
    oneAgain = secondOne;
    keyMask = oneAgain;
    asm volatile("" : "+r"(keyMask));
    keyMask &= keys;
    if (keyMask != 0) {
        if (gUnknown_03005264 == 4) {
            if (gUnknown_0300525c <= 1) {
                goto update_child;
            }
            current->data = (const void *)((u32)FUN_08028bec + 1);
            FUN_0801f618(404);
            FUN_0801f718(2, 60);
            goto update_child;
        }

        FUN_080291a8();
        keyMask = gUnknown_030017c4;
        if (keyMask != 0) {
            keyMask = gUnknown_03001380;
            if (keyMask != 0) {
                goto update_child;
            }
            countAddress = &gUnknown_0300525c;
            if (*countAddress == 1) {
                resetWords = gUnknown_03001b10;
                zero = 0;
                resetWords[0] = keyMask;
                resetWords[1] = keyMask;
                FUN_080184c8();
                FUN_08018c3c();
                gUnknown_03005260 = zero;
                validationAddress = (u8 *)one;
                *countAddress = (u32)validationAddress;
            } else {
                gUnknown_03005260 = keyMask;
                resetFlagAddress = &gUnknown_03005254;
                zero = oneAgain;
                asm volatile("" : "+r"(zero));
                *resetFlagAddress = zero;
                gUnknown_03005258 = keyMask;
                current->data = (const void *)((u32)FUN_08028c80 + 1);
                FUN_0801f618(402);
                goto update_child;
            }
        } else {
            if (gUnknown_03005264 == 4) {
                goto update_child;
            }
            resetWords = gUnknown_03001b10;
            zero = 0;
            resetWords[0] = keyMask;
            resetWords[1] = keyMask;
            FUN_080184c8();
            FUN_08018c3c();
            gUnknown_03005260 = zero;
            gUnknown_0300525c = one;
        }
        gUnknown_03005254 = keyMask;
        current->data = (const void *)((u32)FUN_08028bec + 1);
        FUN_0801f618(404);
    } else {
        secondMask = 2;
        asm volatile("" : "+r"(secondMask));
        secondMask &= keys;
        if (secondMask == 0) {
            goto update_child;
        }
        resetWords = gUnknown_03001b10;
        zero = 0;
        resetWords[0] = keyMask;
        resetWords[1] = keyMask;
        FUN_080184c8();
        FUN_08018c3c();
        gUnknown_03005260 = zero;
        resetCountAddress = &gUnknown_0300525c;
        secondOne = one;
        *resetCountAddress = secondOne;
        gUnknown_03005254 = keyMask;
        current->data = (const void *)((u32)FUN_08028ed8 + 1);
        FUN_0801f618(405);
        FUN_0801f718(2, 120);
        goto done;
    }

update_child:
    if (gUnknown_03005264 == 4) {
        if (gUnknown_0300525c <= 1) {
            nodesAddress = gUnknown_03003e20;
            validationAddress = (u8 *)allocation;
            selectionValue = ((struct UnknownAllocation28770 *)validationAddress)->field5 * 16;
            asm volatile("" : "+r"(selectionValue));
            nodesAddress = (struct UnknownListNode *)((u8 *)nodesAddress + 8);
            asm volatile("" : "+r"(nodesAddress));
            selectionValue += (u32)nodesAddress;
            asm volatile("" : "+r"(selectionValue));
            (*(struct UnknownPosition **)selectionValue)->field0 = gUnknown_08edb974;
        } else {
            nodesAddress = gUnknown_03003e20;
            selectionRead = allocation;
            selectionValue = selectionRead->field5 * 16;
            asm volatile("" : "+r"(selectionValue));
            nodesAddress = (struct UnknownListNode *)((u8 *)nodesAddress + 8);
            asm volatile("" : "+r"(nodesAddress));
            selectionValue += (u32)nodesAddress;
            asm volatile("" : "+r"(selectionValue));
            (*(struct UnknownPosition **)selectionValue)->field0 = gUnknown_08edb94c;
        }
    } else if (gUnknown_030017c4 != 0 && gUnknown_03001380 != 0) {
        nodesAddress = gUnknown_03003e20;
        selectionWrite = allocation;
        selectionValue = selectionWrite->field5 * 16;
        asm volatile("" : "+r"(selectionValue));
        nodesAddress = (struct UnknownListNode *)((u8 *)nodesAddress + 8);
        asm volatile("" : "+r"(nodesAddress));
        selectionValue += (u32)nodesAddress;
        asm volatile("" : "+r"(selectionValue));
        (*(struct UnknownPosition **)selectionValue)->field0 = gUnknown_08edb974;
    } else {
        nodesAddress = gUnknown_03003e20;
        validationAddress = (u8 *)allocation;
        selectionValue = ((struct UnknownAllocation28770 *)validationAddress)->field5 * 16;
        asm volatile("" : "+r"(selectionValue));
        nodesAddress = (struct UnknownListNode *)((u8 *)nodesAddress + 8);
        asm volatile("" : "+r"(nodesAddress));
        selectionValue += (u32)nodesAddress;
        asm volatile("" : "+r"(selectionValue));
        (*(struct UnknownPosition **)selectionValue)->field0 = gUnknown_08edb94c;
    }

    ready = gUnknown_03001380;
    if (ready != 0) {
        validationAddress = (u8 *)&gUnknown_030016f0;
        zero = 2;
        asm volatile("" : "+r"(zero));
        asm volatile("ldrsh %0, [%1, %2]" : "=r"(recordType) : "r"(validationAddress), "r"(zero));
        if (recordType == 0x2345) {
            gUnknown_03005260 = ready;
            gUnknown_03005254 = 1;
            FUN_0802f428(validationAddress + 4);
            gUnknown_03005258 = 0;
            current->data = (const void *)((u32)FUN_08028c80 + 1);
            FUN_0801f618(402);
        }
    }
    if (gUnknown_03005264 == 4) {
        FUN_08021534();
    }
done:
}

void FUN_08028bec(void) {
    register u8 value asm("r1");
    register u8 *values asm("r0");

    if (gUnknown_03005264 == 4) {
        FUN_08021534();
    }
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        if (gUnknown_03005264 == 4) {
            gUnknown_03002030 = FUN_0803281c;
        } else {
            gUnknown_03002030 = FUN_08029250;
            value = gUnknown_03002600[4];
            if (value != 0) {
                values = gUnknown_03005268;
                values[0] = 0;
                value = 2;
                values[1] = value;
                values[2] = 0;
            } else {
                values = gUnknown_03005268;
                values[0] = value;
                values[1] = value;
                values[2] = value;
            }
            values[3] = value;
            gUnknown_0300524c[0] = 0;
            gUnknown_0300524c[1] = 1;
            gUnknown_0300524c[2] = 2;
            gUnknown_0300524c[3] = 3;
        }
    }
}

void FUN_08028c80(struct UnknownListNode *node) {
    register struct UnknownListNode *owner asm("r5") = node;
    register s32 command asm("r6");
    register u16 *commandState asm("r0");
    u32 complete;
    register u32 count asm("r1");
    register u32 i asm("r2");
    register u32 loopCount asm("r3");
    register u8 *records asm("r0");
    register s32 expected asm("r12");
    s16 *recordValue;

    commandState = gUnknown_03001b10;
    asm volatile("" : "+r"(commandState));
    command = 0x2345;
    asm volatile("" : : "r"(command));
    commandState[1] = command;
    FUN_0802f328(&commandState[2]);
    FUN_0801fab0(0x1357);
    if (gUnknown_03005260 == 0) {
        complete = 1;
        i = 1;
        count = gUnknown_0300525c;
        if (complete < count) {
            records = (u8 *)&gUnknown_030016f0;
            asm volatile("" : "+r"(records));
            expected = command;
            asm volatile("" : : "r"(expected));
            loopCount = count;
            recordValue = (s16 *)(records + 18);
            do {
                if (*recordValue != expected) {
                    complete = 0;
                }
                recordValue = (s16 *)((u8 *)recordValue + 16);
                i++;
            } while (i < loopCount);
        }
        if (complete != 0) {
            gUnknown_03005258 = 0;
            owner->data = (const void *)((u32)FUN_08028d30 + 1);
        }
    } else if (gUnknown_030016f0.field2 == 0x2346) {
        gUnknown_03005258 = 0;
        owner->data = (const void *)((u32)FUN_08028d30 + 1);
    }
    gUnknown_03005258++;
    if (gUnknown_03005258 > 299) {
        owner->data = (const void *)((u32)FUN_08028f1c + 1);
    }
}

void FUN_08028d30(struct UnknownListNode *node) {
    struct UnknownListNode *volatile owner[1];
    register u16 *command asm("r1");
    register u32 zero asm("r0");
    register u32 commandCode asm("r4");
    register const u8 *state asm("r2");
    register u32 failed asm("r6");
    register u32 i asm("r5");
    register const void *next asm("r0");

    owner[0] = node;
    asm volatile("" : : : "memory");
    command = gUnknown_03001b10;
    zero = 0;
    commandCode = 0x2346;
    command[1] = commandCode;
    command[2] = zero;
    state = (const u8 *)&gUnknown_03002110;
    command[3] = *(const u16 *)(state + 96);
    command[4] = *(const u16 *)(state + 98);
    command[5] = *(const u16 *)(state + 100);
    command[6] = *(const u16 *)(state + 102);
    command[7] = *(const u16 *)(state + 104);
    asm volatile("" : : "r"(state));
    FUN_0801fab0(0x1357);

    failed = 0;
    i = 0;
    if (failed < gUnknown_0300525c) {
        register u32 expected asm("r10") = commandCode;
        register u16 *destinationBase asm("r12") = gUnknown_03005200[0];
        register u8 *localIndex asm("r9") = &gUnknown_03005260;
        register const u8 *records asm("r3") = (const u8 *)&gUnknown_030016f0;
        register const u8 *count asm("r8") = &gUnknown_0300525c;
        register u16 *destination asm("r4") = destinationBase;
        u32 sentinel = 0xFFFE;

        asm volatile("" : : "r"(count));
        asm volatile("" : : "r"(destination));
        asm volatile("" : : "r"(sentinel));

        do {
            if (i != *localIndex) {
                register u32 offset asm("r2") = i * 16;
                register const u8 *address asm("r0") = records + 2;
                register u32 addressZero asm("r1") = 0;

                address = (const u8 *)(offset + (u32)address);
                if (*(const s16 *)((u32)address + addressZero) == expected) {
                    register const u8 *sourceAddress asm("r0") = records + 6;
                    register u8 *destinationAddress asm("r1");

                    sourceAddress = (const u8 *)(offset + (u32)sourceAddress);
                    destination[0] = *(const u16 *)sourceAddress;
                    destinationAddress = (u8 *)destinationBase + 2;
                    destinationAddress = (u8 *)(offset + (u32)destinationAddress);
                    sourceAddress = records + 8;
                    sourceAddress = (const u8 *)(offset + (u32)sourceAddress);
                    *(u16 *)destinationAddress = *(const u16 *)sourceAddress;
                    destinationAddress = (u8 *)destinationBase + 4;
                    destinationAddress = (u8 *)(offset + (u32)destinationAddress);
                    sourceAddress = records + 10;
                    sourceAddress = (const u8 *)(offset + (u32)sourceAddress);
                    *(u16 *)destinationAddress = *(const u16 *)sourceAddress;
                    destinationAddress = (u8 *)destinationBase + 6;
                    destinationAddress = (u8 *)(offset + (u32)destinationAddress);
                    sourceAddress = records + 12;
                    sourceAddress = (const u8 *)(offset + (u32)sourceAddress);
                    *(u16 *)destinationAddress = *(const u16 *)sourceAddress;
                    destinationAddress = (u8 *)destinationBase + 8;
                    destinationAddress = (u8 *)(offset + (u32)destinationAddress);
                    sourceAddress = records + 14;
                    sourceAddress = (const u8 *)(offset + (u32)sourceAddress);
                    *(u16 *)destinationAddress = *(const u16 *)sourceAddress;
                    destination[5] = sentinel;
                } else {
                    failed = 1;
                }
            }
            destination += 8;
            i++;
        } while (i < *count);
    }

    if (failed != 0) {
        gUnknown_03005258++;
        if (gUnknown_03005258 > 299) {
            next = (const void *)((u32)FUN_08028f1c + 1);
        } else {
            return;
        }
    } else {
        register u16 *destinationBase asm("r2") = gUnknown_03005200[0];
        register u8 *localIndex asm("r3") = &gUnknown_03005260;
        register const u8 *source asm("r4");

        *(u16 *)((u8 *)destinationBase + *localIndex * 16) =
            *(const u16 *)((source = (const u8 *)&gUnknown_03002110) + 96);
        {
            register u32 offset asm("r0") = *localIndex * 16;
            register u8 *destinationOffset asm("r1");
            register u8 *destinationAddress asm("r0");

            destinationOffset = (u8 *)destinationBase + 2;
            destinationAddress = (u8 *)(offset + (u32)destinationOffset);
            asm volatile("" : : "r"(destinationAddress));
            *(u16 *)destinationAddress = *(const u16 *)(source + 98);
        }
        {
            register u32 offset asm("r0") = *localIndex * 16;
            register u8 *destinationOffset asm("r1");
            register u8 *destinationAddress asm("r0");

            destinationOffset = (u8 *)destinationBase + 4;
            destinationAddress = (u8 *)(offset + (u32)destinationOffset);
            asm volatile("" : : "r"(destinationAddress));
            *(u16 *)destinationAddress = *(const u16 *)(source + 100);
        }
        {
            register u32 offset asm("r0") = *localIndex * 16;
            register u8 *destinationOffset asm("r1");
            register u8 *destinationAddress asm("r0");

            destinationOffset = (u8 *)destinationBase + 6;
            destinationAddress = (u8 *)(offset + (u32)destinationOffset);
            asm volatile("" : : "r"(destinationAddress));
            *(u16 *)destinationAddress = *(const u16 *)(source + 102);
        }
        {
            register u32 offset asm("r0") = *localIndex * 16;
            register u8 *destinationOffset asm("r1");
            register u8 *destinationAddress asm("r0");

            destinationOffset = (u8 *)destinationBase + 8;
            destinationAddress = (u8 *)(offset + (u32)destinationOffset);
            asm volatile("" : : "r"(destinationAddress));
            *(u16 *)destinationAddress = *(const u16 *)(source + 104);
        }
        {
            register u32 offset asm("r0") = *localIndex * 16;
            register u8 *destinationAddress asm("r0");
            register u32 sentinel asm("r1");

            destinationBase = (u16 *)((u8 *)destinationBase + 10);
            destinationAddress = (u8 *)(offset + (u32)destinationBase);
            sentinel = 0xFFFE;
            *(u16 *)destinationAddress = sentinel;
        }
        asm volatile("" : : "r"(source));
        next = (const void *)((u32)FUN_08028bec + 1);
    }
    owner[0]->data = next;
}

void FUN_08028f1c(struct UnknownListNode *node) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_0803d1a0;
        FUN_0801fb60();
        FUN_0801fb94();
        FUN_0801ff30();
        FUN_0801f780();
        FUN_080210d8();
        FUN_0802110c();
    }
}

void FUN_08028f5c(void) {
    FUN_08021484();
    if ((gUnknown_030048e0.third & 1) != 0) {
        FUN_080214c0(0);
    }
    FUN_08021534();
}

void FUN_08028ed8(struct UnknownListNode *node) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        if (gUnknown_03005264 == 4) {
            gUnknown_03002030 = FUN_080315bc;
        } else {
            gUnknown_03002030 = FUN_08039e20;
        }
    }
}

void FUN_08028f80(struct UnknownListNode *node) {
    FUN_08021268(0);
    node->data = (const void *)((u32)FUN_08028f5c + 1);
}

void FUN_08028f98(struct UnknownListNode *node) {
    register struct UnknownListNode *owner asm("r4") = node;
    register struct UnknownPosition *position asm("r2") = owner->position;
    register s32 index asm("r3");

    position->field0 = gUnknown_08edb97c;
    if (gUnknown_0300525c >= (index = position->field13) + 1) {
        register const u8 *table asm("r2") = (const u8 *)gUnknown_08edb98c;
        register u32 offset asm("r3") = index * 8;
        register u32 zero asm("r5");
        register const s16 *xAddress asm("r0") = (const s16 *)(table + 4);
        register const s16 *yAddress asm("r3");
        register u32 zero0 asm("r0");
        register s32 x asm("r1");
        register s32 y asm("r2");

        xAddress = (const s16 *)(offset + (u32)xAddress);
        zero = 0;
        x = xAddress[zero];
        asm volatile("" : : "r"(x));
        table += 6;
        offset += (u32)table;
        yAddress = (const s16 *)offset;
        asm volatile("" : : "r"(yAddress));
        zero0 = 0;
        y = *(const s16 *)((u32)yAddress + zero0);

        if ((u8)FUN_0801f92c(owner, x, y) != 0) {
            owner->position->field0 = gUnknown_08edb984;
        }
    } else {
        register const u8 *table asm("r0") = (const u8 *)gUnknown_08edb98c;
        register u32 offset asm("r2") = index * 8;
        register u32 zero3 asm("r3");
        register u32 zero5 asm("r5");
        register const s16 *xAddress asm("r1") = (const s16 *)(offset + (u32)table);
        register const s16 *yAddress asm("r2");
        register s32 x asm("r1");
        register s32 y asm("r2");

        zero3 = 0;
        x = xAddress[zero3];
        asm volatile("" : : "r"(x));
        table += 2;
        yAddress = (const s16 *)(offset + (u32)table);
        asm volatile("" : : "r"(yAddress));
        zero5 = 0;
        y = yAddress[zero5];

        FUN_0801f92c(owner, x, y);
    }
    FUN_0801fed8(owner->field6, 0);
}

void FUN_08029014(struct UnknownListNode *node) {
    register struct UnknownPosition *position asm("r2") = node->position;
    register u32 zero asm("r4");
    register u32 halfwordZero asm("r1");

    position->field0 = gUnknown_08edb97c;
    zero = 0;
    halfwordZero = 0;
    position->tile = halfwordZero;
    {
        register struct UnknownPosition *selected asm("r3") = node->position;
        register const u8 *table asm("r2") = (const u8 *)gUnknown_08edb98c;
        register u32 offset asm("r1") = selected->field13 * 8;

        selected->x = *(const u16 *)(offset + (u32)table);
        selected = node->position;
        offset = selected->field13 * 8;
        table += 2;
        selected->y = *(const u16 *)(offset + (u32)table);
    }
    node->position->field10 = zero;
    node->position->field11 = zero;
    node->position->field12 = zero;
    node->data = (const void *)((u32)FUN_08028f98 + 1);
}

void FUN_08029060(struct UnknownListNode *node) {
    register const u8 *table asm("r1") = gUnknown_0804df7c;
    struct UnknownPosition *position;
    s32 value;

    value = (s8)(*(const u16 *)(table + node->position->field14 * 64) >> 8);
    node->position->field10 = 1;
    position = node->position;
    position->field11 &= 0xC1;
    value += 256;
    node->position->field11 |= FUN_0801fd18(value, 0) * 2;
    FUN_0801fed8(node->field6, 0);
    node->position->field14 += 4;
}

void FUN_080290b4(struct UnknownListNode *node) {
    register struct UnknownPosition *position asm("r2") = node->position;
    register u32 zero asm("r3");
    register u32 halfwordZero asm("r1");

    position->field0 = gUnknown_08edb94c;
    zero = 0;
    halfwordZero = 0;
    position->tile = halfwordZero;
    node->position->x = 214;
    node->position->y = 145;
    node->position->field10 = zero;
    node->position->field11 = zero;
    node->position->field12 = zero;
    node->data = (const void *)((u32)FUN_08029060 + 1);
}

void FUN_080290e8(u32 index, u32 variant, u32 unused) {
    u8 *destination = (u8 *)0x06016A00 + index * 640;
    u32 fill = 0;

    FUN_0804a594(&fill, destination, 0x010000A0);
    FUN_08020ecc((u32)gUnknown_08071b7c, gUnknown_0807173c, destination, 10, 2, 0);
    if (variant <= 3) {
        u16 *entries = gUnknown_03005200[index];
        register s32 y asm("r6") = 30;
        register u32 stop asm("r1");
        u32 i = 0;

        if (entries[0] != (stop = 0xFFFE)) {
            register u32 scanStop asm("r3") = stop;
            const u16 *entry = entries;

            do {
                y -= 6;
                entry++;
                i++;
                if (i > 4) {
                    break;
                }
            } while (entry[0] != scanStop);
        }
        asm volatile("" : : : "memory");
        if (entries[0] != (stop = 0xFFFE)) {
            register u32 sentinel asm("r7") = stop;

            do {
                register s32 width asm("r0") = (s16)FUN_08020fac(entries[0]);
                register s32 x asm("r4");

                asm volatile("" : "+r"(width));
                x = 12 - width;
                x += (u32)x >> 31;
                x = (s32)((u32)x << 15) >> 16;
                x += y;
                FUN_08020978(x + 1, 1, entries[0], 1);
                FUN_08020978(x, 0, entries[0], 15);
                y += 12;
                entries++;
            } while (entries[0] != sentinel);
        }
    }
}

void FUN_080291a8(void) {
    register u8 *destination asm("r1") = gUnknown_03002600;
    register const u8 *source asm("r2") = (const u8 *)&gUnknown_03002110;

    destination[0] = source[108];
    destination[1] = source[109];
    destination[2] = source[110];
    destination[3] = source[111];
    destination[4] = source[112];
    destination[5] = source[113];
    destination[6] = source[114];
    destination[7] = source[115];
    destination[8] = source[116];
    asm volatile("" : : "r"(source));
}

void FUN_08029200(void) {
    register u8 *destination asm("r3") = (u8 *)&gUnknown_03002110;
    register const u8 *source asm("r1") = gUnknown_03002600;
    register u8 value2 asm("r2");
    register u8 value0 asm("r0");
    register u8 *address0 asm("r0");
    register u8 *cursor asm("r2");

    value2 = source[0];
    address0 = destination + 108;
    *address0 = value2;
    value0 = source[1];
    cursor = destination + 109;
    *cursor = value0;
    value0 = source[2];
    cursor++;
    *cursor = value0;
    value0 = source[3];
    cursor++;
    asm volatile("" : : "r"(cursor));
    *cursor = value0;
    value2 = source[4];
    address0 = destination + 112;
    *address0 = value2;
    value0 = source[5];
    cursor = destination + 113;
    *cursor = value0;
    value0 = source[6];
    cursor++;
    *cursor = value0;
    value0 = source[7];
    cursor++;
    asm volatile("" : : "r"(cursor));
    *cursor = value0;
    {
        register u8 value1 asm("r1") = source[8];

        address0 = destination + 116;
        *address0 = value1;
        asm volatile("" : : "r"(destination));
    }
}

void FUN_08029250(void) {
    u32 fills[3];
    u32 *volatile fillAddresses[2];
    s32 entryOffset;
    u32 i;
    u32 j;
    struct UnknownListNode *node;

    {
        register u8 *scene asm("r4") = &gUnknown_03001620;
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

                    asm volatile("mov %0, sp" : "=r"(firstFill));
                    firstFill += 2;
                    fillAddresses[0] = firstFill;
                }
                {
                    register u32 *secondFill asm("r3");

                    asm volatile("mov %0, sp" : "=r"(secondFill));
                    secondFill += 3;
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

                    asm volatile("mov %0, sp" : "=r"(firstFill));
                    firstFill += 2;
                    fillAddresses[0] = firstFill;
                }
                {
                    register u32 *secondFill asm("r0");

                    asm volatile("mov %0, sp" : "=r"(secondFill));
                    secondFill += 3;
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
            register u8 *scene asm("r0") = &gUnknown_03001620;

            scene += 36;
            {
                register u32 four asm("r1") = 4;

                *scene = four;
            }
            for (i = gUnknown_0300525c; i <= 3; i++) {
                memcpy(gUnknown_03005200[i], gUnknown_08edbaac, 16);
            }
        } else {
            register u8 *scene asm("r1") = &gUnknown_03001620;

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
    node->position->field13 = 0;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->field13 = 1;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->field13 = 2;
    node = FUN_0801f7d0(FUN_0802b3c8, 16, gUnknown_03003e20, 0);
    node->position->field13 = 3;
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edbabc[0];
    node = FUN_0801f7d0(FUN_0801f9d8, 16, gUnknown_03003e20, 0);
    *node->position = gUnknown_08edbabc[1];
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->field13 = 0;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->field13 = 1;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->field13 = 2;
    node = FUN_0801f7d0(FUN_0802b638, 16, gUnknown_03003e20, 0);
    node->position->field13 = 3;

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
        scene = &gUnknown_03001620;
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
        register u8 *selectionDestination asm("r2") = &gUnknown_03001620;
        register u8 *selectionCount asm("r1") = selectionDestination;

        selectionCount += 36;
        {
            register u32 countZero asm("r0") = 0;

            *selectionCount = countZero;
        }
        {
            register u32 loopIndex asm("r4") = 0;

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

    scene = &gUnknown_03001620;
    scene[125] = 0;
    if (gUnknown_03005254 != 0) {
        scene[0] = 1;
        if (gUnknown_0300525c == 2) {
            u8 *copyBase = gUnknown_030013b0 + 312;

            FUN_08031db4(copyBase, copyBase - 312, 156);
            FUN_08031db4(copyBase + 156, copyBase - 156, 156);
        } else if (gUnknown_0300525c == 3) {
            u8 *copyBase = gUnknown_030013b0 + 468;

            FUN_08031db4(copyBase, copyBase - 468, 156);
        }
    } else {
        scene[0] = 0;
    }

    asm volatile("" : : : "r4");
    {
        register u8 *output asm("r3") = &gUnknown_03001620;
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

    FUN_0800ec18();
    FUN_0800f38c();
    gUnknown_03002030 = FUN_0801c82c;
}

void FUN_08029ba0(void) {
    register u32 *counter asm("r5");

    if (gUnknown_03005254 != 0) {
        counter = &gUnknown_03005258;
        if (*counter > 59) {
            if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
                gUnknown_03002030 = (void (*)(void))((u32)FUN_0803d1a0 + 1);
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

void FUN_08029c2c(u32 index) {
    register u32 selected asm("r1") = index;

    if (selected <= 4) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((selected + 2) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08117368, 2048);
    } else if (selected <= 9) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((selected - 4) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08117b68, 2048);
    } else if (selected <= 14) {
        FUN_0802036c(0x06016000, (u32)gUnknown_08116568 + ((selected - 10) << 9), 512);
        FUN_0802036c(0x06016200, (u32)gUnknown_08118368, 2048);
    }
}

void FUN_08029cc8(u32 index, u32 selection) {
    register u32 playerIndex asm("r2") = index;

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
            register u32 row asm("r5") = 0;
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
                        register u32 column asm("r2") = 0;

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

void FUN_08029d74(struct UnknownListNode *node) {
    register struct UnknownAllocation29d74 *data asm("r12") = node->allocation;

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
                register u8 *scene asm("r0") = &gUnknown_03001620;

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

void FUN_0802a298(struct UnknownListNode *node) {
    struct UnknownAllocation29d74 *data = node->allocation;
    struct UnknownListNode *child;
    struct UnknownAllocation2a298Child *childData;

    child = FUN_0801f7d0(FUN_08028158, 28, gUnknown_03003e20, 0);
    data->childIndices[0] = child->field6;
    childData = child->allocation;
    childData->graphics = gUnknown_0811c0d0;
    childData->field8 = 32;
    childData->x = gUnknown_08edbb34[data->index][0];
    childData->y = gUnknown_08edbb34[data->index][1];

    child = FUN_0801f7d0(FUN_08028190, 28, gUnknown_03003e20, 0);
    data->childIndices[1] = child->field6;
    childData = child->allocation;
    childData->graphics = gUnknown_0811c0d0;
    childData->field8 = 48;
    childData->x = gUnknown_08edbb34[data->index][2];
    childData->y = gUnknown_08edbb34[data->index][3];

    data->highFlags[3] = 0;
    data->highFlags[2] = 0;
    data->highFlags[1] = 0;
    data->highFlags[0] = 0;
    node->data = (const void *)((u32)FUN_0802a480 + 1);
}

void FUN_0802a34c(struct UnknownListNode *node) {
    struct UnknownAllocation29d74 *data = node->allocation;
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

    if (gUnknown_0300524c[data->index] == 8 && (gUnknown_03002110.field121 & 2) == 0) {
        gUnknown_0300524c[data->index]--;
    }
    if (gUnknown_0300524c[data->index] == 7 && (gUnknown_03002110.field121 & 4) == 0) {
        gUnknown_0300524c[data->index]--;
    }
}

void FUN_0802a3f4(struct UnknownListNode *node) {
    struct UnknownAllocation29d74 *data = node->allocation;
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

void FUN_0802afb0(struct UnknownListNode *node) {
    FUN_0802a34c(node);
    FUN_0802a804(node);
}

void FUN_0802afc4(struct UnknownListNode *node) {
    FUN_0802a3f4(node);
    FUN_0802a804(node);
}

void FUN_0802b064(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_080299c0;
    }
}

void FUN_0802b10c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_0802fdf8;
    }
}

void FUN_0802b1b4(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_080340b8;
    }
}

void FUN_0802b1dc(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_0802b424(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_0802b434(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_0802b444(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_0811c0d8;
    node->position->tile = 0;
    node->position->x = gUnknown_08edbb9c[node->position->field13][0];
    node->position->y = gUnknown_08edbb9c[node->position->field13][1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 0;
    node->data = (const void *)((u32)FUN_0802b434 + 1);
}

void FUN_0802b638(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_0811c0e0;
    node->position->tile = 64;
    node->position->x = gUnknown_08edbbac[node->position->field13][0];
    node->position->y = gUnknown_08edbbac[node->position->field13][1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 184;
    node->data = (const void *)((u32)FUN_0802b688 + 1);
}

void FUN_0802b688(struct UnknownListNode *node) {
    register struct UnknownListNode *current asm("r2") = node;

    asm volatile("" : "+r"(current));
    {
        u8 *states = gUnknown_0300524c;
        struct UnknownPosition *position = current->position;

        if (states[position->field13] > 9) {
            position->tile = 256;
            current->position->field12 = 168;
        } else {
            if (gUnknown_03002600[4] != 0 && (gUnknown_03005268[position->field13] & 2) != 0) {
                position->tile = 160;
            } else {
                current->position->tile = 64;
            }
            current->position->field12 = 184;
        }
        FUN_0801fed8(current->field6, 0);
    }
}

void FUN_0802b2d4(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_0811c120;
    node->position->tile = 768;
    node->position->x = 76;
    node->position->y = 0;
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 0;
    node->position->field13 = 0xFF;
    node->position->field14 = 0xFF;
    node->data = (const void *)((u32)FUN_0802b248 + 1);
}

void FUN_0802b31c(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_0811c188;
    node->position->tile = node->position->field13 * 80 + 448;
    node->position->x = gUnknown_08edbb7c[node->position->field13][0];
    node->position->y = gUnknown_08edbb7c[node->position->field13][1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = (gUnknown_0300524c[node->position->field13] << 4) | 4;
    node->data = (const void *)((u32)FUN_0802b388 + 1);
}

void FUN_0802b388(struct UnknownListNode *node) {
    node->position->x =
        gUnknown_08edbb7c[node->position->field13][0] - ((node->position->field14 + 1) >> 1);
    node->position->y =
        gUnknown_08edbb7c[node->position->field13][1] - ((node->position->field14 + 1) >> 1);
    FUN_0801fed8(node->field6, 0);
}

void FUN_0802b3c8(struct UnknownListNode *node) {
    node->position->field0 = gUnknown_0811c138;
    node->position->tile = node->position->field13 * 20 + 848;
    node->position->x = gUnknown_08edbb8c[node->position->field13][0];
    node->position->y = gUnknown_08edbb8c[node->position->field13][1];
    node->position->field10 = 0;
    node->position->field11 = 0;
    node->position->field12 = 8;
    node->data = (const void *)((u32)FUN_0802b424 + 1);
}

void FUN_08025060(void) {}

void FUN_08043e5c(void) {}

void FUN_0801f600(void) { FUN_08049030(); }

void FUN_0801f60c(void) { FUN_08049724(); }

void FUN_0801f618(u16 value) { m4aSongNumStart(value); }

void FUN_0801f638(void) { FUN_08049170(); }

void FUN_08040460(void) { gUnknown_03005478 = (void *)0x03001800; }

void FUN_080405e8(void) { gUnknown_030001c8 = 0; }

void FUN_08040578(void) {
    s16 index = 0;

    do {
        gUnknown_030001b0[index] = 0;
        index++;
    } while (index <= 3);
    gUnknown_030001b8 = 1;
}

void FUN_080405a8(u8 first, u8 second) {
    gUnknown_030001b4[gUnknown_030001b8][0] = gUnknown_030001b0[second];
    gUnknown_030001b4[gUnknown_030001b8][1] = first;
    gUnknown_030001b0[second] = gUnknown_030001b8++;
}

void FUN_080405f4(u8 first, u8 second) {
    gUnknown_030001c0[gUnknown_030001c8][0] = second;
    gUnknown_030001c0[gUnknown_030001c8++][1] = first;
}

void FUN_080404ec(void) {
    register struct UnknownPoolNode404ec **address asm("r1") =
        (struct UnknownPoolNode404ec **)&gUnknown_0300547c;
    register u32 index asm("r4") = (*address)[0].next;

    if (index != 0) {
        register struct UnknownPoolNode404ec **globalAddress asm("r5") = address;
        register u32 stride asm("r6") = sizeof(struct UnknownPoolNode404ec);

        asm volatile("" : "+r"(globalAddress), "+r"(stride));
        do {
            register struct UnknownPoolNode404ec *node asm("r0") = *globalAddress;

            asm volatile("" : "+r"(node));
            index *= stride;
            node = (struct UnknownPoolNode404ec *)(index + (u32)node);
            FUN_0804af6c((struct UnknownListNode *)node, node->data);
            node = *globalAddress;
            index += (u32)node;
            index = ((struct UnknownPoolNode404ec *)index)->next;
        } while (index != 0);
    }
}

void FUN_0804051c(void *value) {
    struct UnknownPoolCommand4051c *command = value;

    gUnknown_0300547c[command->node].next = command->replacement;
    gUnknown_0300547c[command->replacement].field0 = command->node;
    gUnknown_030001a8[gUnknown_030001ac++] = command->value;
    if (gUnknown_030001ac > 126) {
        gUnknown_030001ac = 0;
    }
    gUnknown_03005480--;
}

void FUN_08040470(void) {
    s16 index;
    u32 zero;
    volatile u32 *dma;
    u8 *recycleIndex;
    u8 *secondaryIndex;
    u8 *activeCount;
    register struct UnknownPoolNode404ec **poolAddress asm("r12");
    register struct UnknownPoolNode404ec **poolCopy asm("r2");

    gUnknown_030001a8 = (u8 *)0x02002580;
    gUnknown_0300547c = (struct UnknownPoolNode404ec *)0x02002600;
    index = 0;
    poolAddress = (struct UnknownPoolNode404ec **)&gUnknown_0300547c;
    asm volatile("" : "+r"(poolAddress));
    recycleIndex = &gUnknown_030001ac;
    secondaryIndex = &gUnknown_030001ad;
    activeCount = &gUnknown_03005480;
    do {
        gUnknown_030001a8[index] = index + 1;
        index++;
    } while (index <= 126);
    *activeCount = 0;
    *secondaryIndex = 0;
    *recycleIndex = 0;
    zero = 0;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&zero;
    poolCopy = poolAddress;
    asm volatile("" : "+r"(poolCopy));
    dma[1] = (u32)*poolCopy;
    dma[2] = 0x8500000b;
    dma[2];
}

void FUN_08040624(void) {
    u32 fill;
    volatile u32 *dma;

    gUnknown_030001b4 = (u8(*)[2])0x02002200;
    gUnknown_030001bc = (u8 *)0x02002300;
    gUnknown_030001c0 = (u8(*)[2])0x02002400;
    gUnknown_030001c4 = (u8 *)0x02002500;
    fill = 160;
    dma = (volatile u32 *)0x040000d4;
    dma[0] = (u32)&fill;
    dma[1] = 0x030044d0;
    dma[2] = 0x85000100;
    dma[2];
}

s32 FUN_080406d4(s32 value, s8 *destination, s32 width) {
    register s32 current asm("r3") = value;
    register s32 adjustedWidth asm("r2");
    register s8 *cursor asm("r4") = destination;
    register u8 remaining asm("r5");

    asm volatile("" : "+r"(cursor));
    adjustedWidth = (s8)width;
    asm volatile("" : "+r"(adjustedWidth));
    cursor += adjustedWidth;
    adjustedWidth--;
    adjustedWidth <<= 24;
    asm volatile("" : "+r"(adjustedWidth));
    remaining = (u32)adjustedWidth >> 24;
    adjustedWidth >>= 24;
    if (adjustedWidth == -1) {
        goto digits_done;
    }
    goto check_current;

digit_loop: {
    register s32 quotient asm("r0") = FUN_0804a59c(current, 10);
    register s32 remainder asm("r1");
    register u32 shifted asm("r0");
    register u32 decrement asm("r1");

    asm volatile("" : "=r"(remainder));
    current = quotient;
    *--cursor = remainder;
    shifted = remaining << 24;
    decrement = 0xFFu << 24;
    asm volatile("" : "+r"(shifted), "+r"(decrement));
    shifted += decrement;
    remaining = shifted >> 24;
    if ((s8)remaining == -1) {
        goto digits_done;
    }
}

check_current:
    if (current > 9) {
        goto digit_loop;
    }
    *--cursor = current;

digits_done: {
    register u32 originalShift asm("r2") = remaining << 24;
    register s32 signedRemaining asm("r0");

    asm volatile("" : "+r"(originalShift));
    signedRemaining = (s32)originalShift >> 24;
    if (signedRemaining > 0) {
        register s32 minusOne asm("r1");

        originalShift >>= 24;
        signedRemaining--;
        signedRemaining <<= 24;
        remaining = (u32)signedRemaining >> 24;
        signedRemaining >>= 24;
        minusOne = -1;
        asm volatile("" : "+r"(minusOne), "+r"(signedRemaining));
        if (signedRemaining != minusOne) {
            register s32 padding asm("r3") = minusOne;

            asm volatile("" : "+r"(padding));
            do {
                register u32 shifted asm("r0");
                register u32 decrement asm("r5");

                *--cursor = padding;
                shifted = remaining << 24;
                decrement = 0xFFu << 24;
                asm volatile("" : "+r"(shifted), "+r"(decrement));
                shifted += decrement;
                remaining = shifted >> 24;
                signedRemaining = (s32)shifted >> 24;
            } while (signedRemaining != minusOne);
        }
        signedRemaining = (s8)originalShift;
    }
    return signedRemaining;
}
}

void FUN_0802cfd0(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08031154(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_0803186c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08032adc(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08033a1c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08035258(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08036888(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_080380e4(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08039c5c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_08037100(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

void FUN_08039fd0(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_0803b53c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_0803c844(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_0803cf9c(void) {
    FUN_0801f89c();
    FUN_0801fda0();
}

void FUN_0803cb54(struct UnknownListNode *node) { FUN_0801fed8(node->field6, 0); }

s16 FUN_08040684(u8 index) { return gUnknown_081231d6[index]; }

s16 FUN_08040698(u8 index) {
    register u32 adjusted asm("r0") = index;
    register const s16 *table asm("r2");
    register u32 mask asm("r1");

    asm volatile("" : "+r"(adjusted));
    table = gUnknown_081231d6;
    adjusted += 64;
    mask = 0xFF;
    asm volatile("" : "+r"(table), "+r"(adjusted), "+r"(mask));
    return table[adjusted & mask];
}

void FUN_0801f5ec(void) {
    FUN_08048fb8();
    FUN_08049544((const void *)0x0093e800);
}

u32 FUN_08020144(void) { return gUnknown_0300019c = gUnknown_0300019c * 0x0014fa05 + 0x0000c0af; }

u32 FUN_08020160(u32 threshold) {
    u32 random = gUnknown_0300019c * 0x0014fa05 + 0x0000c0af;
    u32 percent;
    register u32 result asm("r2");

    gUnknown_0300019c = random;
    percent = ((random & 0xFFFF) * 100) >> 16;
    result = 0;
    if (percent <= threshold) {
        result = 1;
    }
    return result;
}

void FUN_080402a0(void) {
    FUN_08016078(1);
    FUN_080411fc();
}

u32 FUN_080406b4(void) {
    gUnknown_03005430 = gUnknown_03005430 * 0x41c64e6d + 0x3039;
    return (gUnknown_03005430 << 1) >> 17;
}

void FUN_080303cc(void) {
    register volatile u16 *registers asm("r1") = (volatile u16 *)0x0400000a;
    register u32 value asm("r2") = 0x1c09;
    register u32 copy asm("r0");

    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
    registers++;
    value = 0x1b01;
    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
}

void FUN_080381e4(void) {
    register volatile u16 *registers asm("r1") = (volatile u16 *)0x0400000a;
    register u32 value asm("r2") = 0x1e09;
    register u32 copy asm("r0");

    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
    registers++;
    value = 0x1d01;
    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
}

void FUN_0803b588(void) {
    register volatile u16 *registers asm("r1") = (volatile u16 *)0x0400000a;
    register u32 value asm("r2") = 0x1e09;
    register u32 copy asm("r0");

    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
    registers++;
    value = 0x1d01;
    asm volatile("" : "+r"(value));
    copy = value;
    asm volatile("" : "+r"(copy));
    *registers = copy;
}

void FUN_080482d0(struct UnknownState482d0 *state) {
    state->field12.half.high = 96;
    state->field38 = 5;
    state->callback = (const void *)((u32)FUN_08047bd8 + 1);
}

void FUN_080482e8(struct UnknownState482d0 *state) {
    state->field12.half.high = 96;
    state->field38 = 7;
    state->callback = (const void *)((u32)FUN_08047bd8 + 1);
}

void FUN_0803128c(struct UnknownListNode *node) {
    struct UnknownAllocation3128c *allocation = node->allocation;

    allocation->field4 = 30;
    allocation->field2 = 0;
    node->data = (const void *)((u32)FUN_080311b4 + 1);
}

void FUN_080368c0(u8 index) { gUnknown_0300537c &= ~gUnknown_0807163c[index]; }

void FUN_08043e28(struct UnknownState43e28 *state) {
    state->graphics = gUnknown_081734d8;
    state->field22 = 4;
    state->field24 = 44;
    state->callback = (const void *)((u32)FUN_08041c14 + 1);
}

u8 FUN_08043e44(s16 x, s16 y) {
    register s32 row asm("r1") = y >> 3;
    register s32 column asm("r0") = x >> 3;
    register const u8 *map asm("r2") = (const u8 *)0x02020c00;

    row <<= 6;
    row += (u32)map;
    asm volatile("" : "+r"(row));
    row += column;
    return *(const u8 *)row;
}

void FUN_080309c0(struct UnknownListNode *node) {
    FUN_0802ea64(gUnknown_030052e0);
    node->data = (const void *)((u32)FUN_080309e0 + 1);
}

void FUN_0803876c(struct UnknownListNode *node) {
    FUN_080375d8(gUnknown_030052e0);
    node->data = (const void *)((u32)FUN_0803878c + 1);
}

void FUN_0803bb34(struct UnknownListNode *node) {
    FUN_0803b69c(gUnknown_030052e0);
    node->data = (const void *)((u32)FUN_0803bb54 + 1);
}

void FUN_0803bbf0(struct UnknownListNode *node) {
    FUN_0803b69c(gUnknown_030052e0);
    node->data = (const void *)((u32)FUN_0803bc10 + 1);
}

void FUN_080482b4(struct UnknownState482d0 *state) {
    state->field12.half.high = 96;
    state->field30 = state->field10;
    state->field39 = 64;
    state->callback = (const void *)((u32)FUN_08047b40 + 1);
}

void FUN_0802dc78(struct UnknownListNode *node) {
    FUN_0801f978(node, 32);
    FUN_0801fed8(node->field6, 0);
}

void FUN_0802dcc8(struct UnknownListNode *node) {
    FUN_0801f978(node, 28);
    FUN_0801fed8(node->field6, 0);
}

void FUN_08034f10(struct UnknownListNode *node) {
    FUN_0801f978(node, 48);
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035b58(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 - 4;
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035ba4(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035bf0(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->field6, 0);
}

void FUN_08036244(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->field6, 0);
}

void FUN_080312f8(struct UnknownListNode *node) {
    u32 *counter = node->allocation;

    FUN_0801fba0(28, *(u8 *)counter);
    *counter -= 12;
}

void FUN_08032778(struct UnknownListNode *node) {
    u32 *counter = node->allocation;

    FUN_0801fba0(30, *(u8 *)counter);
    *counter -= 1;
}

void FUN_08032790(struct UnknownListNode *node) {
    FUN_0801f92c(node, 104, gUnknown_08edc4a4[node->position->field13]);
    FUN_0801fed8(node->field6, 0);
}

void FUN_080327bc(struct UnknownListNode *node) {
    if ((u8)FUN_0801f9a8(node, -16) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080327ec(struct UnknownListNode *node) {
    if ((u8)FUN_0801f9a8(node, 160) != 0) {
        FUN_08021244(node->position->field14);
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08033060(struct UnknownListNode *node) {
    u32 *angle = node->allocation;

    *angle += 16;
    if (*angle > 95) {
        *angle -= 96;
    }
    FUN_0801fba0(8, gUnknown_08edc544[*angle >> 4]);
}

void FUN_0803315c(struct UnknownListNode *node) {
    struct UnknownPosition *position = node->position;

    position->field14++;
    if (position->field14 > 29) {
        node->position->field14 = 0;
        node->data = (const void *)((u32)FUN_08033090 + 1);
    }
}

void FUN_080333dc(struct UnknownListNode *node) {
    FUN_0801fed8(node->field6, 0);
    gUnknown_03003e20[node->position->field13].position->x = node->position->x;
}

void FUN_08033404(struct UnknownListNode *node) {
    struct UnknownPosition *position = node->position;

    position->field14++;
    if (position->field14 > 59) {
        node->position->field14 = 0;
        node->data = (const void *)((u32)FUN_08033228 + 1);
    }
}

void FUN_080335dc(struct UnknownListNode *node) {
    if (((u8)++node->position->field14 & 4) != 0) {
        node->position->tile = 128;
    } else {
        node->position->tile = 148;
    }
    node->position->x -= 8;
    if (node->position->x < -16) {
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0803362c(struct UnknownListNode *node) {
    if (((u8)++node->position->field14 & 4) != 0) {
        node->position->tile = 168;
    } else {
        node->position->tile = 174;
    }
    node->position->x -= 6;
    if (node->position->x < -16) {
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0803367c(struct UnknownListNode *node) {
    node->position->x -= 6;
    if (node->position->x < -16) {
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080336ac(struct UnknownListNode *node) {
    node->position->x -= 6;
    if (node->position->x < -16) {
        FUN_0801f8c0(node);
    } else {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_080344d8(u8 index) {
    FUN_0802036c(0x05000300, (u32)gUnknown_0814d910 + index * 128, 128);
    FUN_08020408(0x06014000, gUnknown_08edc8a8[index]);
}

void FUN_08034ebc(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03001210[0x472] = 0;
        gUnknown_03002030 = FUN_0802fdf8;
    }
}

void FUN_08035760(struct UnknownListNode *node) {
    s16 *state = node->allocation;
    register s32 value asm("r1") = 256;

    asm volatile("" : "+r"(value));
    state[0] = value;
    state[1] = 30;
    gUnknown_03005378 = value + 84;
    FUN_0801fba0(20, (u16)-value);
    node->data = (const void *)((u32)FUN_08035798 + 1);
}

void FUN_080358b4(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 256) != 0) {
        gUnknown_03002030 = gUnknown_03005330.callback;
    }
}

void FUN_080358dc(struct UnknownListNode *node) {
    s16 *counter = (s16 *)node->allocation + 1;

    if (*counter > 0) {
        (*counter)--;
    } else {
        *counter = 0;
        node->data = (const void *)((u32)FUN_08035408 + 1);
    }
}

void FUN_08035ad8(struct UnknownListNode *node) {
    node->position->y -= 8;
    if (node->position->y <= 40) {
        node->position->y = 40;
        node->data = (const void *)((u32)FUN_08035b08 + 1);
    }
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035b08(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 68;
    node->position->x = gUnknown_03005378 + 68;
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035b28(struct UnknownListNode *node) {
    node->position->y += 8;
    if (node->position->y > 39) {
        node->position->y = 40;
        node->data = (const void *)((u32)FUN_08035b58 + 1);
    }
    FUN_0801fed8(node->field6, 0);
}

void FUN_08035c0c(struct UnknownListNode *node) {
    u32 *counter = node->allocation;

    FUN_0801fba0(28, *(u8 *)counter);
    *counter -= 4;
}

void FUN_08036288(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 4;
    FUN_0801fed8(node->field6, 0);
}

void FUN_080362a4(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 32;
    FUN_0801fed8(node->field6, 0);
}

void FUN_080362c0(struct UnknownListNode *node) {
    node->position->x = gUnknown_03005378 + 32;
    FUN_0801fed8(node->field6, 0);
}

void FUN_08039da0(struct UnknownListNode *node) {
    if (gUnknown_030052e0 != 0) {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08039dbc(struct UnknownListNode *node) {
    if (gUnknown_030052e0 <= 9) {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0803cb1c(struct UnknownListNode *node) {
    if (gUnknown_030052e0 != 0) {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_0803cb38(struct UnknownListNode *node) {
    if (gUnknown_030052e0 <= 10) {
        FUN_0801fed8(node->field6, 0);
    }
}

void FUN_08039c3c(void) {
    u32 zero = 0;

    FUN_0804a594(&zero, (const void *)0x06008000, 0x01000b68);
}

void FUN_08043ee4(struct UnknownState482d0 *state) {
    FUN_0801fba0(82, 4096);
    state->callback = (const void *)((u32)FUN_08041808 + 1);
}

void FUN_08034ef4(struct UnknownListNode *node) {
    FUN_0801f978(node, -48);
    FUN_0801fed8(node->field6, 0);
}

void FUN_08030d20(struct UnknownListNode *node) {
    u32 *counter = node->allocation;
    u32 value = --*counter;

    FUN_0801fba0(30, (value & 0x1FE) >> 1);
}

void FUN_08030d3c(struct UnknownListNode *node) {
    u32 *counter = node->allocation;
    u32 value = --*counter;

    FUN_0801fba0(28, (value & 0x1FE) >> 1);
}

void FUN_080309e0(struct UnknownListNode *node) {
    FUN_0802fcb4(gUnknown_030052e0);
    gUnknown_030052f8 = 1;
    node->data = (const void *)((u32)FUN_08030a08 + 1);
}

void FUN_08048284(struct UnknownState482d0 *state) {
    state->field10 = 226;
    state->field12.half.high = 153;
    state->graphics = gUnknown_081a7f60;
    state->callback = (const void *)((u32)FUN_08046aa4 + 1);
    FUN_0804af6c((struct UnknownListNode *)state, state->callback);
}

void FUN_080312a0(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08031164;
    }
}

void FUN_0803256c(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_080325f0(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_080284b4;
    }
}

void FUN_08033038(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_0803d1a0;
    }
}

void FUN_08033bf8(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08000210;
    }
}

void FUN_08033bb4(struct UnknownListNode *node) {
    *(u32 *)node->allocation = 180;
    node->data = (const void *)((u32)FUN_08033bc4 + 1);
}

void FUN_08033cc8(struct UnknownListNode *node) {
    *(u32 *)node->allocation = 300;
    node->data = (const void *)((u32)FUN_08033cdc + 1);
}

void FUN_08033bc4(struct UnknownListNode *node) {
    s32 *counter = node->allocation;

    if (--*counter <= 0 || (gUnknown_030048e0.third & 1) != 0) {
        node->data = (const void *)((u32)FUN_08033bf8 + 1);
        FUN_0801f718(5, 120);
    }
}

void FUN_08033cdc(struct UnknownListNode *node) {
    s32 *counter = node->allocation;

    if (--*counter <= 0 || (gUnknown_030048e0.third & 1) != 0) {
        node->data = (const void *)((u32)FUN_08033bf8 + 1);
        FUN_0801f718(5, 120);
    }
}

void FUN_0802c7d8(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_0802c25c;
    }
}

void FUN_0802d734(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_08039d00(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_0803d100(void) {
    if ((u8)FUN_0802067c((u16 *)0x05000000, 512) != 0) {
        gUnknown_03002030 = FUN_08039e20;
    }
}

void FUN_0802d95c(struct UnknownListNode *node) {
    FUN_0801fed8(node->field6, 0);
    if (node->position->field14 == 0) {
        node->data = (const void *)((u32)FUN_0802d76c + 1);
    }
}

void FUN_0802db10(struct UnknownListNode *node) {
    FUN_0801fed8(node->field6, 0);
    if (node->position->field14 == 0) {
        node->data = (const void *)((u32)FUN_0802da00 + 1);
    }
}

void FUN_0803bb08(struct UnknownListNode *node) {
    FUN_0803a9dc(gUnknown_030052e0);
    gUnknown_030052f8++;
    node->data = (const void *)((u32)FUN_0803bb34 + 1);
}

void FUN_0803bbc4(struct UnknownListNode *node) {
    FUN_0803a9dc(gUnknown_030052e0);
    gUnknown_030052f8++;
    node->data = (const void *)((u32)FUN_0803bbf0 + 1);
}

void FUN_08030a08(struct UnknownListNode *node) {
    if (gUnknown_030052f8 <= 7) {
        gUnknown_030052f8 += 2;
    } else {
        gUnknown_030052f8 = 8;
        node->data = (const void *)((u32)FUN_080304e4 + 1);
    }
}

void FUN_080387b4(struct UnknownListNode *node) {
    if (gUnknown_030052f8 <= 3) {
        gUnknown_030052f8++;
    } else {
        gUnknown_030052f8 = 4;
        node->data = (const void *)((u32)FUN_08038448 + 1);
    }
}

void FUN_0803bb54(struct UnknownListNode *node) {
    if (gUnknown_030052f8 <= 3) {
        gUnknown_030052f8++;
    } else {
        gUnknown_030052f8 = 4;
        node->data = (const void *)((u32)FUN_0803b82c + 1);
    }
}

void FUN_0803bc10(struct UnknownListNode *node) {
    if (gUnknown_030052f8 <= 3) {
        gUnknown_030052f8++;
    } else {
        gUnknown_030052f8 = 4;
        node->data = (const void *)((u32)FUN_0803b82c + 1);
    }
}

void FUN_0803878c(struct UnknownListNode *node) {
    FUN_08038360(gUnknown_030052e0);
    gUnknown_030052f8 = 1;
    node->data = (const void *)((u32)FUN_080387b4 + 1);
}

void FUN_08032f10(struct UnknownListNode *node) {
    FUN_080214c0(gUnknown_03005300);
    node->data = (const void *)((u32)FUN_08032f34 + 1);
    FUN_0804af6c(node, node->data);
}

void FUN_08047fc0(struct UnknownState482d0 *state) {
    FUN_0801f744(gUnknown_03005440.field12, 2);
    state->field26 = 36;
    state->callback = (const void *)((u32)FUN_080481c8 + 1);
}

void FUN_08047fe4(struct UnknownState482d0 *state) {
    state->field30 = state->field10;
    state->field34 = state->field12.half.high;
    state->graphics = gUnknown_081a7f18 + ((state->field3 & 4) << 3);
    state->callback = (const void *)((u32)FUN_0804825c + 1);
    FUN_0804af6c((struct UnknownListNode *)state, state->callback);
}

void FUN_0804825c(struct UnknownState482d0 *state) {
    register u16 first asm("r1") = gUnknown_03000288.first;
    register u16 firstOffset asm("r3") = state->field30;
    register u16 second asm("r1");
    register u16 secondOffset asm("r2");

    asm volatile("" : "+r"(first), "+r"(firstOffset));
    first += firstOffset;
    state->field10 = first;
    second = gUnknown_03000288.second;
    secondOffset = state->field34;
    asm volatile("" : "+r"(second), "+r"(secondOffset));
    second += secondOffset;
    state->field12.half.high = second;
    FUN_080405f4(state->field2, state->field39);
}

void FUN_080482a8(struct UnknownState482d0 *state) {
    state->callback = (const void *)((u32)FUN_08047acc + 1);
}

void FUN_08048300(struct UnknownState482d0 *state) {
    FUN_0804033c((const void *)0x02028000, (void *)0x06013200, 0x800);
    state->field12.half.high = -32;
    state->field20 = 0;
    state->field39 = 16;
    state->callback = (const void *)((u32)FUN_08047c30 + 1);
}

void FUN_080481c8(struct UnknownState482d0 *state) {
    if (--state->field26 == 0) {
        gUnknown_03005440.field12 = state->field20;
        FUN_0801f618(gUnknown_03005440.field12);
        gUnknown_03005440.field8 &= ~4;
        FUN_0804051c(state);
    }
}

void FUN_08048148(struct UnknownState482d0 *state) {
    state->field27++;
    FUN_0803fe98(16, 176, (u8)state->field27 >> 1);
    if (state->field27 > 31) {
        gUnknown_03005440.field8 &= ~4;
        FUN_0804051c(state);
    }
}

void FUN_08048184(struct UnknownState482d0 *state) {
    state->field27++;
    FUN_0803fe98(16, 176, (u16)(16 - ((u8)state->field27 >> 1)));
    if (state->field27 > 31) {
        gUnknown_03005440.field8 &= ~4;
        FUN_0804051c(state);
    }
}

void FUN_08047f7c(struct UnknownState482d0 *state) {
    state->field27++;
    FUN_0803fe98(0, 512, (u16)(16 - state->field27));
    if (state->field27 > 15) {
        gUnknown_03005440.field8 &= ~1;
        FUN_0804051c(state);
    }
}

void FUN_08047f20(struct UnknownState482d0 *state) {
    u8 variant = gUnknown_03005440.field36 + 1;

    if (variant > 3) {
        variant = 1;
    }
    FUN_080403c0(gUnknown_081a81d0 + variant * 360, (void *)0x06019b80, 30, 6, 0);
    gUnknown_03005440.field46 = variant;
    state->field12.half.high = 48;
    state->callback = (const void *)((u32)FUN_0804542c + 1);
}

void FUN_08047ec4(struct UnknownState482d0 *state) {
    FUN_0801f744(gUnknown_03005440.field12, 1);
    gUnknown_03005380 = 1;
    gUnknown_03005440.callback = (const void *)((u32)FUN_08036560 + 1);
    gUnknown_03005440.field32 = 0;
    gUnknown_03005440.field33 = 0;
    gUnknown_03005440.field34 = 1;
    gUnknown_03005440.field35 = 1;
    gUnknown_03005440.field8 |= 1;
    gUnknown_03002030 = FUN_080412dc;
    FUN_0804051c(state);
}

void FUN_08047bd8(struct UnknownState482d0 *state) {
    register u32 mask asm("r2");
    u32 value;
    u8 *limit;

    state->field26++;
    mask = 0xFF;
    asm volatile("" : "+r"(mask));
    if ((u8)state->field26 > 2) {
        state->field26 = 0;
        value = state->field27 + 1;
        state->field27 = value;
        limit = &state->field38;
        asm volatile("" : "+r"(limit));
        if ((value & mask) >= *limit) {
            gUnknown_03005440.field8 &= ~4;
            FUN_0804051c(state);
            return;
        }
    }
    state->field20 = state->field27 << 4;
    FUN_080405a8(state->field2, 1);
}

void FUN_08047b40(struct UnknownState482d0 *state) {
    register u32 zero asm("r2");
    register u32 mask asm("r1");
    u32 value = state->field26 + 1;

    zero = 0;
    asm volatile("" : "+r"(zero));
    state->field26 = value;
    mask = 0xFF;
    asm volatile("" : "+r"(mask));
    if ((u8)value > 6) {
        state->field26 = zero;
        value = state->field27 + 1;
        state->field27 = value;
        value &= mask;
        if (value > 5) {
            state->field27 = zero;
        }
    }

    state->field20 = gUnknown_081a7f88[state->field27];
    state->field10 = state->field30 + FUN_0804a59c(FUN_08040698(state->field39), 1536);
    state->field39 += 3;
    state->field12.fixed += 0xFFFF6000;
    if ((s16)state->field12.half.high <= -16) {
        gUnknown_03005440.field8 &= ~4;
        FUN_0804051c(state);
    } else {
        FUN_080405a8(state->field2, 1);
    }
}

void FUN_08047c30(struct UnknownState482d0 *state) {
    register u32 zero asm("r2");
    register u32 mask asm("r1");

    switch (state->field37) {
    case 0:
        state->field12.fixed += 0x8000;
        if ((s16)state->field12.half.high > 79) {
            state->field37++;
        }
        break;
    case 1:
        state->field40++;
        if ((u16)state->field40 > 59) {
            state->field37++;
        }
        break;
    case 2: {
        register u32 fade asm("r1");

        state->field22 = 1;
        fade = FUN_0804a59c(4096, state->field39);
        asm volatile("" : "+r"(fade));
        gUnknown_030002d0.second = fade;
        gUnknown_030002d0.first = fade;
        gUnknown_030002d0.third = 0;
        FUN_0804a5c4(&gUnknown_030002d0, gUnknown_030044d6, 1, 8);
        state->field39--;
        if ((u8)state->field39 == 0) {
            gUnknown_03005440.field8 &= ~4;
            FUN_0804051c(state);
            return;
        }
        break;
    }
    }

    {
        u32 frame = state->field26 + 1;

        zero = 0;
        asm volatile("" : "+r"(zero));
        state->field26 = frame;
        mask = 0xFF;
        asm volatile("" : "+r"(mask));
        if ((u8)frame > 4) {
            state->field26 = zero;
            frame = state->field27 + 1;
            state->field27 = frame;
            frame &= mask;
            if (frame > 5) {
                state->field27 = zero;
            }
            FUN_0804033c((void *)(0x02028000 + state->field27 * 0x800), (void *)0x06013200, 0x800);
        }
    }
    FUN_080405a8(state->field2, 1);
}

void FUN_08040328(void) {
    gUnknown_030001a0 = (struct UnknownTransferList4033c *)0x02001600;
    gUnknown_030001a0->records[0].size = 1;
}

void FUN_0804033c(const void *source, void *destination, u32 size) {
    register struct UnknownTransferList4033c *list asm("r5") = gUnknown_030001a0;
    register u32 index asm("r4") = list->records[0].size;
    register u32 recordAddress asm("r3");
    struct UnknownTransferRecord4033c *record;

    recordAddress = index * 12;
    recordAddress += (u32)list;
    asm volatile("" : "+r"(recordAddress));
    record = (struct UnknownTransferRecord4033c *)recordAddress;
    record->source = source;
    record->destination = destination;
    record->size = size;
    list->records[0].size = index + 1;
}

void FUN_08040360(void) {
    register u32 index asm("r4") = 1;
    register struct UnknownTransferList4033c **queue asm("r6");
    register struct UnknownTransferList4033c **globalAddress asm("r0") = &gUnknown_030001a0;
    register struct UnknownTransferList4033c *list asm("r3") = *globalAddress;
    register u32 count asm("r1") = list->records[0].size;

    queue = globalAddress;
    asm volatile("" : "+r"(queue), "+r"(list), "+r"(count));
    if (index < count) {
        register volatile struct UnknownTransferRecord4033c *destination asm("r2") =
            &gUnknown_030000d4;
        register struct UnknownTransferRecord4033c *record asm("r1") = &list->records[1];
        register u32 flags asm("r5") = 0x84000000;

        asm volatile("" : "+r"(destination), "+r"(record), "+r"(flags));
        do {
            destination->source = record->source;
            destination->destination = record->destination;
            destination->size = (record->size >> 2) | flags;
            destination->size;
            record++;
            index++;
        } while (index < list->records[0].size);
    }
    (*queue)->records[0].size = 1;
}

void FUN_080403ac(void) {
    gUnknown_030001a4 = (struct UnknownTransferList403c0 *)0x02001700;
    gUnknown_030001a4->records[0].flags = 1;
}

void FUN_080403c0(const void *source, void *destination, u32 width, u32 height, u32 flags) {
    register u32 storedFlags asm("r9") = flags;
    register struct UnknownTransferList403c0 **queue asm("r8") = &gUnknown_030001a4;
    register struct UnknownTransferList403c0 *recordBase asm("r5") = *queue;
    register u32 index asm("r6") = recordBase->records[0].flags;
    register u32 offset asm("r4") = index * 12;
    register struct UnknownTransferList403c0 **queueCopy asm("r1");
    register struct UnknownTransferList403c0 *current asm("r0");
    struct UnknownTransferRecord403c0 *record;

    asm volatile("" : "+r"(storedFlags), "+r"(queue), "+r"(recordBase), "+r"(index), "+r"(offset));
    recordBase = (struct UnknownTransferList403c0 *)(offset + (u32)recordBase);
    record = (struct UnknownTransferRecord403c0 *)recordBase;
    record->source = source;
    record->destination = destination;
    record->width = width;
    queueCopy = queue;
    asm volatile("" : "+r"(queueCopy));
    current = *queueCopy;
    current = (struct UnknownTransferList403c0 *)(offset + (u32)current);
    current->records[0].height = height;
    current = *queueCopy;
    offset += (u32)current;
    ((struct UnknownTransferRecord403c0 *)offset)->flags = storedFlags;
    current->records[0].flags = index + 1;
}

void FUN_08040408(const u16 *source, u16 *destination, s32 width, s32 height, s32 offset) {
    register const u16 *sourceCursor asm("r4") = source;
    register u16 *destinationCursor asm("r1") = destination;
    register s32 rawWidth asm("r2") = width;
    register u32 encodedRows asm("r3");
    register u32 rawOffset asm("r0");
    register s32 columns asm("r5");
    register u16 tileOffset asm("r6");
    register u32 rowStride asm("r2");

    asm volatile("" : "+r"(sourceCursor));
    rawOffset = offset;
    asm volatile("" : "+r"(rawOffset));
    rawWidth <<= 24;
    asm volatile("" : "+r"(rawWidth));
    columns = (u32)rawWidth >> 24;
    encodedRows = height << 24;
    asm volatile("" : "+r"(columns), "+r"(encodedRows));
    rawOffset <<= 16;
    tileOffset = rawOffset >> 16;
    asm volatile("" : "+r"(tileOffset));
    rawOffset = 32 - columns;
    rawOffset <<= 24;
    rowStride = rawOffset >> 24;

    {
        register u32 decrement asm("r0") = 0xFFu << 24;

        asm volatile("" : "+r"(decrement));
        encodedRows += decrement;
    }
    rawOffset = encodedRows >> 24;
    if (rawOffset != 0xFF) {
        register u32 strideBytes = rowStride << 1;

        asm volatile("" : "+r"(strideBytes));
        do {
            s16 column = 0;

            encodedRows = rawOffset - 1;
            while (column < columns) {
                *destinationCursor++ = tileOffset + *sourceCursor++;
                column++;
            }
            destinationCursor = (u16 *)((u8 *)destinationCursor + strideBytes);
            rawOffset = (encodedRows << 24) >> 24;
        } while (rawOffset != 0xFF);
    }
}

void FUN_08041808(void *value) {
    register struct UnknownFadeState41808 *state asm("r4") = value;
    register u32 progress asm("r0") = state->step;
    register u32 oldProgress asm("r1") = state->progress;

    asm volatile("" : "+r"(state), "+r"(progress), "+r"(oldProgress));
    progress += oldProgress;
    state->progress = progress;
    asm volatile("" : "+r"(progress));
    progress = (u8)progress;
    if (progress > 15) {
        state->progress = 16;
    }
    {
        register u32 blend asm("r1") = state->progress;
        register u32 inverse asm("r0") = 16 - blend;

        asm volatile("" : "+r"(blend), "+r"(inverse));
        blend |= inverse << 8;
        FUN_0801fba0(0x52, (u16)blend);
    }
    if ((gUnknown_03005440.field8 & 2) == 0 && state->progress > 15) {
        gUnknown_03005440.field8 &= 0xFEFF;
        FUN_0804051c(state);
    }
}

void FUN_08041f24(struct UnknownState41f24 *state) {
    state->graphics = gUnknown_081734d8;
    state->field20 =
        (gUnknown_08eeb678[gUnknown_03005440.field31][state->selector].field10 + 1) * 8;
    state->field22 = 4;
    if (gUnknown_08eeb678[gUnknown_03005440.field31][state->selector].field10 == 4) {
        state->field24 = 0xcc;
    } else {
        state->field24 = 0x2c;
    }
    state->callback = (const void *)((u32)FUN_08041e2c + 1);
}

void FUN_08042044(struct UnknownState420dc *state) {
    register const void *const *table asm("r2") = gUnknown_0817adc8;
    register u32 index asm("r0");
    const void *source;
    struct UnknownState420dc *child;

    asm volatile("" : "+r"(table));
    index = gUnknown_03005440.field31 * 3 + gUnknown_03005440.field29;
    index <<= 2;
    asm volatile("" : "+r"(table), "+r"(index));
    table++;
    index += (u32)table;
    source = *(const void *const *)index;
    LZ77UnCompWram(source, (void *)0x02028000);
    FUN_0804033c((void *)0x02028000, (void *)0x06013200, 0x1000);
    FUN_0801fba0(0x52, 16);
    child = FUN_0803ff98((const void *)((u32)FUN_08041f84 + 1), state, 0);
    child->field3 = 1;
    state->field8.half.high = child->field8.half.high = 120;
    state->field14 = child->field14 = 80;
    state->graphics = child->graphics = gUnknown_08173500;
    state->field22 = child->field22 = 4;
    state->field24 = child->field24 = 48;
    state->field26 = child->field26 = 90;
    state->fade = child->fade = 16;
    state->callback = (const void *)((u32)FUN_08041f84 + 1);
    FUN_0801f770(gUnknown_03005440.field10);
}

void FUN_080420dc(struct UnknownState420dc *state) {
    if ((gUnknown_03005440.field8 & 0x200) != 0) {
        state->callback = (const void *)((u32)FUN_08043f2c + 1);
        FUN_0804af6c((struct UnknownListNode *)state, state->callback);
        return;
    }

    if (gUnknown_0300547c[state->poolIndex].field3 != 0) {
        state->fade++;
        if (state->fade > 16) {
            state->fade = 16;
        }
    } else {
        if (state->fade == 0) {
            state->callback = (const void *)((u32)FUN_08043e5c + 1);
            return;
        }
        state->fade--;
    }

    FUN_0801fba0(0x52, state->fade | ((16 - state->fade) << 8));
    state->field8.half.high = state->baseX - gUnknown_03005494;
    state->field14 = state->baseY - gUnknown_03005490;
    FUN_080405a8(state->field2, 2);
}

void FUN_08042180(struct UnknownState420dc *state) {
    register u32 tableIndex asm("r6") = gUnknown_03005440.field31;
    register u32 tableIndexCopy = tableIndex;
    register u32 poolField asm("r4") = gUnknown_0300547c[state->poolIndex].field27;
    register const struct UnknownRecord41f24 *const *recordTable asm("r0");
    register u32 tableOffset asm("r2");
    register u32 recordOffset asm("r1");
    register const void *records asm("r0");
    register const void *const *resourceTable asm("r1");
    register u32 resourceOffset asm("r0");
    const void *source;

    if (state->cachedPoolField != poolField) {
        state->cachedPoolField = poolField;
        state->fade = 0;
    }
    FUN_0801fba0(0x52, state->fade | ((16 - state->fade) << 8));
    state->graphics = gUnknown_08173520;
    if (state->field3 != 0) {
        recordTable = gUnknown_08eeb678;
        tableOffset = tableIndex << 2;
        goto foundTable;
    } else {
        recordTable = gUnknown_08eeb660;
        tableOffset = tableIndexCopy << 2;
    }
foundTable:
    asm volatile("" : "+r"(recordTable), "+r"(tableOffset));
    tableOffset += (u32)recordTable;
    asm volatile("" : "+r"(tableOffset));
    records = *(const void *const *)tableOffset;
    asm volatile("" : "+r"(records));
    recordOffset = poolField << 5;
    state->baseX = *(const u16 *)(recordOffset + (u32)records + 4);
    state->baseY = *(const u16 *)(recordOffset + (u32) * (const void *const *)tableOffset + 6);
    poolField = *(const u16 *)(recordOffset + (u32) * (const void *const *)tableOffset + 8);
    state->field22 = 4;
    state->field24 = 8;
    resourceTable = (const void *const *)gUnknown_08edda00;
    resourceOffset = gUnknown_03005440.field29 << 2;
    asm volatile("" : "+r"(resourceTable), "+r"(resourceOffset));
    resourceOffset += (u32)resourceTable;
    resourceTable = *(const void *const **)resourceOffset;
    resourceOffset = poolField << 2;
    asm volatile("" : "+r"(resourceTable), "+r"(resourceOffset));
    resourceOffset += (u32)resourceTable;
    source = *(const void *const *)resourceOffset;
    LZ77UnCompWram(source, (void *)0x02010600);
    FUN_0804033c((void *)0x02010600, (void *)0x06013200, 0x400);
    state->callback = (const void *)((u32)FUN_080420dc + 1);
}

void FUN_0804224c(u8 value) {
    register u8 *state asm("r3") = (u8 *)&gUnknown_03002110;
    register u32 offset asm("r2") = 0x488;

    state[offset] = value;
    {
        register struct UnknownGlobalRenderState *global asm("r4") = &gUnknown_03005440;
        register u32 field asm("r1") = global->filler30;

        offset++;
        state[offset] = field;
        field = global->field31;
        offset++;
        state[offset] = field;
        field = global->field44;
        offset++;
        state[offset] = field;
        asm volatile("" : "+r"(offset));
        {
            register u32 *destination asm("r5") = (u32 *)(state + 0x48c);
            register const u32 *firstAddress asm("r0") = &gUnknown_03002610;
            register const u32 *secondAddress asm("r2") = &gUnknown_03005488;
            register u32 difference asm("r1");
            register u32 second asm("r0");

            asm volatile("" : "+r"(firstAddress), "+r"(secondAddress));
            difference = *firstAddress;
            second = *secondAddress;
            asm volatile("" : "+r"(difference), "+r"(second));
            difference -= second;
            {
                register u32 total asm("r0") = global->field40 + difference;

                *destination = total;
            }
        }
        field = global->field24;
        offset = 0x498;
        *(u16 *)(state + offset) = field;
        field = global->field26;
        offset += 2;
        *(u16 *)(state + offset) = field;
    }

    {
        const s16 *source = (const s16 *)0x02000200;
        s16 row = 0;
        u32 one = 1;
        register u32 destinationOffset asm("r0") = 0x49c;
        u8 *destination;

        asm volatile("" : "+r"(destinationOffset));
        destination = state + destinationOffset;

        do {
            u16 mask = 0;
            s16 column = 0;

            do {
                if (*source++ != 0) {
                    register s32 shift asm("r1") = column;
                    register u32 bits asm("r0") = one;

                    asm volatile("" : "+r"(shift), "+r"(bits));
                    bits <<= shift;
                    bits |= mask;
                    mask = bits;
                }
                column++;
            } while (column <= 7);
            *(u8 *)((u32)row + (u32)destination) = mask;
            row++;
        } while (row <= 63);
    }
    FUN_080217d0(0);
}

void FUN_0804230c(struct UnknownCameraState4230c *state) {
    u16 keys;
    s32 cardinalStep;
    s32 diagonalStep;

    if ((gUnknown_03005440.field8 & 2) != 0) {
        keys = 0;
    } else {
        keys = gUnknown_030048e0.first;
    }
    if ((gUnknown_03005440.field8 & 1) != 0) {
        goto updateAnimation;
    }

    gUnknown_03000200 = gUnknown_030001e0;
    gUnknown_03000210 = gUnknown_030001f0;
    cardinalStep = 0x20000;
    diagonalStep = 0x16a0a;
    if ((gUnknown_030048e0.first & 2) != 0) {
        cardinalStep = FUN_0804a59c(0x60000, 2);
        diagonalStep = FUN_0804a59c(0x43e1e, 2);
    }

    switch (keys & 0xf0) {
    case 0x40:
        state->y.fixed -= cardinalStep;
        break;
    case 0x80:
        state->y.fixed += cardinalStep;
        break;
    case 0x20:
        state->x.fixed -= cardinalStep;
        break;
    case 0x10:
        state->x.fixed += cardinalStep;
        break;
    case 0x60:
        state->y.fixed -= diagonalStep;
        state->x.fixed -= diagonalStep;
        break;
    case 0x50:
        state->y.fixed -= diagonalStep;
        state->x.fixed += diagonalStep;
        break;
    case 0xa0:
        state->y.fixed += diagonalStep;
        state->x.fixed -= diagonalStep;
        break;
    case 0x90:
        state->y.fixed += diagonalStep;
        state->x.fixed += diagonalStep;
        break;
    }

    if (state->x.half.high < 8) {
        state->x.half.high = 8;
    }
    if (state->x.half.high > gUnknown_081a4c2a[gUnknown_03005440.field31].width - 8) {
        state->x.half.high = gUnknown_081a4c2a[gUnknown_03005440.field31].width - 8;
    }
    {
        s16 yCoordinate = state->y.half.high;

        if (yCoordinate < 8) {
            state->y.half.high = 8;
        }
    }
    if (state->y.half.high > gUnknown_081a4c2a[gUnknown_03005440.field31].height - 8) {
        state->y.half.high = gUnknown_081a4c2a[gUnknown_03005440.field31].height - 8;
    }
    if (FUN_08043cf8(state->x.half.high, state->y.half.high) == 0) {
        gUnknown_030001e0 = state->x.half.high;
        gUnknown_030001f0 = state->y.half.high;
    }

    {
        register u16 yPosition asm("r9");
        register s16 *cameraYPointer asm("r12");

        {
            register s16 *cameraX asm("r4") = &gUnknown_03005494;
            register u16 x asm("r3") = state->x.half.high;
            u16 oldCameraX = *cameraX;
            u16 deltaXValue = (x - oldCameraX) & 0xffff;
            register u16 deltaX = deltaXValue;
            register s16 *cameraY asm("r2") = &gUnknown_03005490;
            register u16 y asm("r1") = state->y.half.high;
            register s16 oldCameraY asm("r6") = *cameraY;
            register s32 shiftedDeltaY asm("r0") = ((u32)y - (u16)oldCameraY) << 16;
            u16 deltaYValue = (u32)shiftedDeltaY >> 16;
            register u16 deltaY = deltaYValue;
            register s32 signedDeltaY asm("r5") = shiftedDeltaY >> 16;

            yPosition = y;
            cameraYPointer = cameraY;

            if (signedDeltaY <= 76) {
                register s16 updatedCameraY asm("r0") = oldCameraY;

                updatedCameraY -= 77;
                updatedCameraY = signedDeltaY + updatedCameraY;

                *cameraY = updatedCameraY;
                if (updatedCameraY < 0) {
                    *cameraY = 0;
                }
            }
            {
                register u16 rawSecondDeltaY asm("r1") = deltaY;
                register s32 shiftedSecondDeltaY asm("r0") = rawSecondDeltaY << 16;
                register s32 secondDeltaY asm("r5") = shiftedSecondDeltaY >> 16;

                if (secondDeltaY > 131) {
                    register s16 *secondCameraY asm("r2") = cameraYPointer;
                    register s16 updatedCameraY asm("r0") = *secondCameraY;

                    updatedCameraY -= 131;
                    updatedCameraY = secondDeltaY + updatedCameraY;
                    *secondCameraY = updatedCameraY;
                    if (*secondCameraY >
                        gUnknown_081a4c2a[gUnknown_03005440.field31].height - 160) {
                        *cameraYPointer = gUnknown_081a4c2a[gUnknown_03005440.field31].height - 160;
                    }
                }
            }
            {
                register u16 rawDeltaX asm("r2") = deltaX;
                register s32 shiftedDeltaX asm("r0") = rawDeltaX << 16;
                register s32 firstDeltaX asm("r2") = shiftedDeltaX >> 16;
                register s32 retainedShiftedX asm("r1") = shiftedDeltaX;

                if (firstDeltaX <= 79) {
                    register s16 updatedCameraX asm("r0") = *cameraX;

                    updatedCameraX -= 80;
                    updatedCameraX = firstDeltaX + updatedCameraX;
                    *cameraX = updatedCameraX;
                    if (updatedCameraX < 0) {
                        *cameraX = 0;
                    }
                }
                {
                    register s32 secondDeltaX asm("r1") = retainedShiftedX >> 16;

                    if (secondDeltaX > 160) {
                        register s16 updatedCameraX asm("r0") = *cameraX;

                        updatedCameraX -= 160;
                        updatedCameraX = secondDeltaX + updatedCameraX;
                        *cameraX = updatedCameraX;
                        if (*cameraX > gUnknown_081a4c2a[gUnknown_03005440.field31].width - 240) {
                            *cameraX = gUnknown_081a4c2a[gUnknown_03005440.field31].width - 240;
                        }
                    }
                }
            }

            {
                register volatile s16 *relativeCameraX asm("r1") = &gUnknown_03005494;

                state->relativeX = x - *relativeCameraX;
            }
        }
        {
            register s16 *relativeCameraY asm("r2") = cameraYPointer;
            register u16 relativeCameraYValue asm("r0") = *relativeCameraY;
            register u16 relativeYPosition asm("r4") = yPosition;
            register u16 relativeY asm("r2") = relativeYPosition - relativeCameraYValue;

            asm volatile("" : "+r"(relativeYPosition));
            state->relativeY = relativeY;
        }
        {
            register u32 heldDirection asm("r5") = keys & 0xf0;

            asm volatile("" : "+r"(heldDirection));
            if (heldDirection == 0) {
                s16 targetX = 120 - state->relativeX;
                s16 targetY = 104 - state->relativeY;

                if (targetX != 0 || targetY != 0) {
                    register u32 angle asm("r9") = ArcTan2(targetX, targetY) >> 8;
                    u16 distance = Sqrt((targetX * targetX + targetY * targetY) << 4) >> 2;

                    if (((s16)gUnknown_03005494 <= 0 && state->relativeX <= 120) ||
                        ((s16)gUnknown_03005494 >=
                             gUnknown_081a4c2a[gUnknown_03005440.field31].width - 240 &&
                         state->relativeX > 119)) {
                        if (targetY == 0) {
                            goto updateRegisters;
                        }
                        if (targetY < 0) {
                            distance = -targetY;
                            angle = 0xc0;
                        } else {
                            distance = targetY;
                            angle = 0x40;
                        }
                    } else if (((s16)gUnknown_03005490 <= 0 && state->relativeY <= 104) ||
                               ((s16)gUnknown_03005490 >=
                                    gUnknown_081a4c2a[gUnknown_03005440.field31].height - 160 &&
                                state->relativeY > 103)) {
                        if (targetX == 0) {
                            goto updateRegisters;
                        }
                        if (targetX < 0) {
                            distance = -targetX;
                            angle = 0x80;
                        } else {
                            distance = targetX;
                            angle = 0;
                        }
                    }
                    if (distance > 15) {
                        distance = 15;
                    }
                    distance = (distance >> 1) + 1;
                    gUnknown_0300023c -= FUN_08040698_wide(angle) * distance;
                    gUnknown_03000240 -= FUN_08040684_wide(angle) * distance;
                    if ((s32)gUnknown_0300023c < 0) {
                        gUnknown_0300023c = 0;
                    } else {
                        const struct UnknownBounds4230c *boundsTable = gUnknown_081a4c2a;
                        const struct UnknownBounds4230c *bounds =
                            &boundsTable[gUnknown_03005440.field31];
                        s32 maximum = (bounds->width - 240) << 16;

                        if ((s32)gUnknown_0300023c > maximum) {
                            gUnknown_0300023c = maximum;
                        }
                    }
                    if ((s32)gUnknown_03000240 < 0) {
                        gUnknown_03000240 = 0;
                    } else {
                        const struct UnknownBounds4230c *boundsTable = gUnknown_081a4c2a;
                        const struct UnknownBounds4230c *bounds =
                            &boundsTable[gUnknown_03005440.field31];
                        s32 maximum = (bounds->height - 160) << 16;

                        if ((s32)gUnknown_03000240 > maximum) {
                            gUnknown_03000240 = maximum;
                        }
                    }
                    gUnknown_03005494 = gUnknown_0300023c >> 16;
                    gUnknown_03005490 = gUnknown_03000240 >> 16;
                    state->relativeX = state->x.half.high - gUnknown_03005494;
                    state->relativeY = state->y.half.high - gUnknown_03005490;
                }
            } else {
                {
                    register s16 *fixedCameraX asm("r5");

                    gUnknown_0300023c = *(fixedCameraX = &gUnknown_03005494) << 16;
                }
                {
                    register s16 *fixedCameraY asm("r3");

                    gUnknown_03000240 = *(fixedCameraY = cameraYPointer) << 16;
                }
            }
        }
    }

updateRegisters:
    if ((gUnknown_03005440.field8 & 0x10) == 0) {
        s16 index = 0;

        do {
            FUN_0801fba0((index * 4 + 20) & 0xffff, gUnknown_03005494);
            FUN_0801fba0((index * 4 + 22) & 0xffff, gUnknown_03005490);
            index++;
        } while (index <= 2);
    }
    gUnknown_03005440.field16 = gUnknown_03005494;
    gUnknown_03005440.field18 = gUnknown_03005490;

updateAnimation: {
    u8 animationIndex;
    u16 animationReset = gUnknown_03005440.field8 & 2;

    if (animationReset != 0) {
        return;
    }
    state->animationFrame++;
    {
        register u32 animationIndexMask asm("r2") = 0xff;

        if (state->animationFrame > 4) {
            state->animationFrame = animationReset;
            animationIndex = state->animationIndex;

            state->animationIndex = animationIndex + 1;
            if (((u32)(animationIndex + 1) & animationIndexMask) > 5) {
                state->animationIndex = animationReset;
            }
            state->animation = gUnknown_08173540[state->animationIndex];
        }
    }
    FUN_080405a8(state->field2, 2);
}
}

void FUN_0804280c(struct UnknownState420dc *state) {
    register u16 *first asm("r0");
    register u16 *second asm("r1");

    gUnknown_030001d4 = FUN_0803ff98((const void *)((u32)FUN_08045d30 + 14), gUnknown_03007c54, 0);
    gUnknown_0300023c = (s16)gUnknown_03005494 << 16;
    gUnknown_03000240 = (s16)gUnknown_03005490 << 16;
    state->baseX = gUnknown_03005440.field20;
    state->baseY = gUnknown_03005440.field22;
    state->graphics = gUnknown_08173510;
    state->field24 = 40;
    if (FUN_08043cf8(state->baseX, state->baseY) == 0) {
        register u16 *address asm("r2") = &gUnknown_030001e0;

        *address = state->baseX;
        second = &gUnknown_030001f0;
        *second = state->baseY;
        first = address;
    } else {
        first = &gUnknown_030001e0;
        second = &gUnknown_030001f0;
        *second = 0;
        *first = 0;
    }
    {
        register u16 *secondCopy asm("r2") = second;

        asm volatile("" : "+r"(secondCopy));
        gUnknown_03000200 = *first;
        gUnknown_03000210 = *secondCopy;
    }
    state->callback = (const void *)((u32)FUN_0804230c + 1);
}

void FUN_08041f84(struct UnknownState420dc *state) {
    if ((gUnknown_030048e0.third & 1) != 0) {
        state->field26 = 0;
    }
    if (state->field26 != 0) {
        state->field26--;
    } else {
        if ((gUnknown_03005440.field4 & 1) != 0) {
            state->fade--;
        }
        if (state->fade > 16) {
            if (state->field3 == 0) {
                gUnknown_03005440.field8 &= 0xbfff;
                gUnknown_030001d0 = FUN_0803ff98((const void *)((u32)FUN_0804280c + 1), state, 1);
                FUN_08041860(2);
                FUN_08041920();
                FUN_080419d4();
            }
            FUN_0804051c(state);
            return;
        }
        if (state->field3 != 0) {
            register u32 position asm("r0") = state->field8.fixed;
            register u32 delta asm("r1") = (u32)-0x1c000;

            asm volatile("" : "+r"(position), "+r"(delta));
            position += delta;
            state->field8.fixed = position;
            asm volatile("" : "+r"(position));
        } else {
            state->field8.fixed += 0x1c000;
            FUN_0801fba0(0x52, state->fade | ((16 - state->fade) << 8));
        }
    }
    FUN_080405a8(state->field2, 0);
}
