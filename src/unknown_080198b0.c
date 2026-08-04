#include "types.h"

extern void FUN_08012b98(u32 value);
extern void FUN_08016078(u32 value);
extern void FUN_0801bcac(void);
extern void FUN_0801b394(void);
extern void FUN_0801c770(void);
extern void FUN_08020840(u32 value);
extern void FUN_080205d0(void);
extern u32 FUN_0801cfc8(u8 value);
extern void FUN_0801d870(u8 value);

typedef void (*UnknownCallback)(void);

struct UnknownEntity {
    UnknownCallback callback;
    const void *data;
    u8 filler8[5];
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
    u8 filler22[230];
};

extern void (*gUnknown_03002030)(void);
extern u8 gUnknown_03001620;
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

extern void FUN_0801d618(void);
extern void FUN_0801dfdc(void);
extern void FUN_0801e044(void);
extern void FUN_0801e174(void);
extern u8 FUN_0801ee4c(u8 value);
extern u32 FUN_08020160(u16 value);
extern void FUN_0801eea8(void);

void FUN_0801eb94(u8 value);
void FUN_0801ebf4(u8 value);
void FUN_0801ed50(u8 value);
void FUN_0801edc0(u8 value);
void FUN_0801ee30(u8 value);

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
                entity->callback = FUN_0801eea8;
                return 1;
            }
        }
    }

    return 0;
}
