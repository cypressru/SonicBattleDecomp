#include "types.h"

extern u8 gUnknown_03001740[];

extern u8 gUnknown_03001388;
extern u8 gUnknown_030016d0;
extern u8 gUnknown_030017c0;
extern u8 gUnknown_030017c8;
extern u8 gUnknown_030017cc;
extern u16 gUnknown_03003170;
extern u16 gUnknown_030033cc;

struct UnknownQueueEntry08017f00 {
    u32 words[4];
};

struct UnknownQueueEntry08017f34 {
    void *first;
    void *second;
};

extern struct UnknownQueueEntry08017f34 gUnknown_03003190[];
extern struct UnknownQueueEntry08017f00 gUnknown_030033e0[];
extern void CpuFastSet(const void *source, void *destination, u32 mode);

void FUN_08017ed0(void) {
    gUnknown_030017cc = 0;
    gUnknown_030017c8 = 0;
    gUnknown_03001388 = 0;
}

void FUN_08017eec(void) {
    gUnknown_030033cc = 0;
    gUnknown_03003170 = 0;
}

void FUN_08017f00(u32 first, u32 second, u32 third, u32 fourth) {
    struct UnknownQueueEntry08017f00 entry;

    entry.words[0] = first;
    entry.words[1] = second;
    entry.words[2] = third;
    entry.words[3] = fourth;
    CpuFastSet(&entry, &gUnknown_030033e0[gUnknown_030017cc], 4);
    gUnknown_030017cc++;
}

void FUN_08017f34(void *first, void *second) {
    struct UnknownQueueEntry08017f34 *entries = gUnknown_03003190;
    u8 *count = &gUnknown_03001388;
    struct UnknownQueueEntry08017f34 *entry = &entries[*count];

    entry->first = first;
    entry->second = second;
    (*count)++;
}

void FUN_08017f58(u8 first, u8 second) {
    gUnknown_030016d0 = first;
    gUnknown_030017c0 = second;
}

void FUN_08017f6c(void) { gUnknown_030017c8 = gUnknown_030017cc; }

void FUN_08018410(void) {
    volatile u32 *dma = (volatile u32 *)0x040000d4;

    dma[0] = 0x0847afb8;
    dma[1] = (u32)gUnknown_03001740;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = 0x084cadd8;
    dma[1] = (u32)(gUnknown_03001740 + 0x40);
    dma[2] = 0x80000010;
    dma[2];
}
