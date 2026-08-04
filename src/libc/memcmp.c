#include "types.h"

int memcmp(const void *left, const void *right, u32 count)
{
    const u8 *left8 = left;
    const u8 *right8 = right;

    if (count > 3 && (((u32)left8 | (u32)right8) & 3) == 0) {
        while (count > 3) {
            if (*(const u32 *)left8 != *(const u32 *)right8)
                break;
            left8 += 4;
            right8 += 4;
            count -= 4;
        }
    }

    while (count-- != 0) {
        int difference = *left8 - *right8;
        if (difference != 0)
            return difference;
        left8++;
        right8++;
    }
    return 0;
}
