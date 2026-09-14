#include "types.h"
// C++ fallback with synthetic linkage; original source language is unknown.
// Full TU and storage evidence: docs/transfer-command-tu-cpp.md.
extern "C" {
struct UnknownCommandRecord {
    u32 first, second, third;
    u16 fourth, type;
};
// Preserve the observed gap before the records; its original role is unknown.
static struct {
    u32 count;
    u8 unclassified[12];
} gUnknown_030048f0;
static UnknownCommandRecord gUnknown_03004900[32];
void CpuFastSet(const void *, void *, u32);
void LZ77UnCompVram(const void *, void *);
void FUN_08021000(u16 *, const u16 *, u16, u16, u16);
void FUN_08020244(void) {
    u32 i = 0;
    while (i < gUnknown_030048f0.count) {
        switch (gUnknown_03004900[i].type) {
        case 0:
            CpuFastSet((const void *)gUnknown_03004900[i].second,
                       (void *)gUnknown_03004900[i].first,
                       (gUnknown_03004900[i].third & 0x7fffff) >> 2);
            break;
        case 1:
            FUN_08021000((u16 *)gUnknown_03004900[i].first,
                         (const u16 *)gUnknown_03004900[i].second, (u16)gUnknown_03004900[i].third,
                         gUnknown_03004900[i].third >> 16, gUnknown_03004900[i].fourth);
            break;
        case 2:
            LZ77UnCompVram((const void *)gUnknown_03004900[i].second,
                           (void *)gUnknown_03004900[i].first);
            break;
        case 3:
            CpuFastSet(
                (const void *)(gUnknown_03004900[i].first + (u16)gUnknown_03004900[i].third * 1152),
                (void *)(0x06010000 + gUnknown_03004900[i].fourth * 32), 0x120);
            break;
        case 4:
            CpuFastSet(
                (const void *)(gUnknown_03004900[i].first + (u16)gUnknown_03004900[i].third * 1152),
                (void *)(0x06010000 + (u8)gUnknown_03004900[i].fourth * 1152), 0x120);
            break;
        case 5:
            CpuFastSet(
                (const void *)(gUnknown_03004900[i].first + (u16)gUnknown_03004900[i].third * 32),
                (void *)(0x06011600 + (u8)gUnknown_03004900[i].fourth * 512),
                (gUnknown_03004900[i].second << 16) >> 19);
            break;
        }
        i++;
    }
    gUnknown_030048f0.count = 0;
}
void FUN_08020360(void) { gUnknown_030048f0.count = 0; }

void FUN_0802036c(u32 first, u32 second, u32 third) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 0;
        gUnknown_030048f0.count = index + 1;
    }
}

void FUN_080203a4(u32 first, u32 second, u16 third, u16 fourth, u16 fifth) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = third | (fourth << 16);
        gUnknown_03004900[index].fourth = fifth;
        gUnknown_03004900[index].type = 1;
        gUnknown_030048f0.count = index + 1;
    }
}

void FUN_08020408(u32 first, u32 second) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].third = 0;
        gUnknown_03004900[index].type = 2;
        gUnknown_030048f0.count = index + 1;
    }
}

void FUN_08020440(u32 first, u16 second, u16 third) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 3;
        gUnknown_030048f0.count = index + 1;
    }
}

void FUN_0802047c(u32 first, u8 second, u16 third) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].fourth = second;
        gUnknown_03004900[index].third = third;
        gUnknown_03004900[index].type = 4;
        gUnknown_030048f0.count = index + 1;
    }
}

void FUN_080204b8(u32 first, u16 second, u8 third, u16 fourth) {
    u32 index = gUnknown_030048f0.count;

    if (index <= 31) {
        gUnknown_03004900[index].first = first;
        gUnknown_03004900[index].second = second;
        gUnknown_03004900[index].fourth = third;
        gUnknown_03004900[index].third = fourth;
        gUnknown_03004900[index].type = 5;
        gUnknown_030048f0.count = index + 1;
    }
}
}
