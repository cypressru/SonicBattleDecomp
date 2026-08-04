/* Correlated to newlib's openly licensed libc/string/memcpy.c. */
#include <stddef.h>

#define UNALIGNED(X, Y) (((long)(X) & (sizeof(long) - 1)) | ((long)(Y) & (sizeof(long) - 1)))
#define BIGBLOCKSIZE (sizeof(long) << 2)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)

void *memcpy(void *dst0, const void *src0, size_t len0) {
    char *dst = dst0;
    const char *src = src0;
    long *aligned_dst;
    const long *aligned_src;
    int len = len0;

    if (!TOO_SMALL(len) && !UNALIGNED(src, dst)) {
        aligned_dst = (long *)dst;
        aligned_src = (long *)src;
        while (len >= BIGBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }
        while (len >= LITTLEBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            len -= LITTLEBLOCKSIZE;
        }
        dst = (char *)aligned_dst;
        src = (char *)aligned_src;
    }

    while (len--)
        *dst++ = *src++;
    return dst0;
}
