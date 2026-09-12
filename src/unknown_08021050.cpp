#include "types.h"
// C++ reconstruction fallback; original language and names are unknown.
// Complete TU and private-state evidence: docs/memory-tu-cpp.md.
extern "C" {
struct UnknownHeapBlock {
    UnknownHeapBlock *next;
    s32 size;
};
static u16 gUnknown_03004b30[256];
static UnknownHeapBlock *gUnknown_03004d30;
extern UnknownHeapBlock gUnknown_030033e0;
static u32 gUnknown_03004d34, gUnknown_03004d38;
void CpuSet(const void *, void *, u32);

u16 FUN_08021050(u16 size) {
    u16 count = size;
    u16 *table = gUnknown_03004b30;
    count = (count + 3) >> 2;
    u16 start = 0;
    u16 end;
    s32 limit;
    goto test;
search:
    end = start;
    if (end < limit) {
        s32 scanLimit = limit;
        u16 occupied;
        do {
            end++;
            if (end >= scanLimit)
                goto endscan;
            occupied = table[end];
        } while (occupied == 0);
        start = end + occupied;
    }
endscan:
    if (end == start + count) {
        goto found;
    }
next:
    start++;
test:
    if (start <= 255) {
        if (table[start] != 0) {
            start += table[start];
            goto next;
        }
        limit = start + count;
        if (limit <= 255) {
            goto search;
        }
        start = 256;
    }
done:
    u16 result;
    if (start != 256) {
        result = start * 4;
        goto result;
    }
    goto failed;
found:
    table[start] = count;
    goto done;
failed:
    result = 0xffff;
result:
    start = result;
    return start;
}

void FUN_080210d8(void) {
    u32 zero = 0;
    CpuSet(&zero, gUnknown_03004b30, 0x05000080);
}
void FUN_080210f8(u16 value) { gUnknown_03004b30[value >> 2] = 0; }
void FUN_0802110c(void) {
    gUnknown_03004d30 = &gUnknown_030033e0;
    gUnknown_030033e0.next = 0;
    gUnknown_030033e0.size = 0xff8;
}
void *FUN_08021128(s32 requested) {
    UnknownHeapBlock *block = gUnknown_03004d30;
    requested = (requested + 7) & ~7;
    for (;;) {
        s32 available = block->size;
        if (available >= requested) {
            if ((u32)available < requested + 24U) {
                block->size = -available;
            } else {
                UnknownHeapBlock *tail = (UnknownHeapBlock *)((u8 *)block + requested + 8);
                tail->next = block->next;
                block->next = tail;
                tail->size = available - requested - 8;
                block->size = -requested;
            }
            return block + 1;
        }
        if (block->next == 0) {
            return 0;
        }
        block = block->next;
    }
}
void FUN_08021180(void *allocation) {
    UnknownHeapBlock *block = gUnknown_03004d30;
    UnknownHeapBlock *previous = 0;
    UnknownHeapBlock *wanted = (UnknownHeapBlock *)allocation - 1;
    for (;;) {
        if (block == wanted) {
            block->size = -block->size;
            if (previous != 0 && previous->size > 0) {
                previous->size += 8 + block->size;
                previous->next = block->next;
                block = previous;
            }
            UnknownHeapBlock *next = block->next;
            if (next != 0 && next->size > 0) {
                block->size += 8 + next->size;
                block->next = next->next;
            }
            return;
        }
        if (block->next == 0) {
            return;
        }
        previous = block;
        block = block->next;
    }
}
void FUN_080211d8(u8 value) {
    gUnknown_03004d38 = value;
    gUnknown_03004d34 = 0;
}
u8 FUN_080211f0(void) {
    u32 bit = 1;
    u8 index = 0;
    u32 *limitAddress = &gUnknown_03004d38;
    u32 limit = *limitAddress;
    u32 *limitPointer = limitAddress;
    u32 *bits;
    if (index < limit) {
        u32 *bitsAddress = &gUnknown_03004d34;
        u32 flags = *bitsAddress & bit;
        bits = bitsAddress;
        while (flags != 0) {
            bit <<= 1;
            index++;
            if (index >= *limitAddress) {
                goto failed;
            }
            flags = *bitsAddress & bit;
        }
        if (index < *limitPointer) {
            goto allocate;
        }
    }
failed:
    index = *(u8 *)limitPointer;
    goto done;
allocate:
    *bits |= bit;
done:
    return index;
}
void FUN_08021244(u8 index) {
    u32 bit = 1 << index;
    if (gUnknown_03004d34 & bit) {
        gUnknown_03004d34 &= ~bit;
    }
}
}
