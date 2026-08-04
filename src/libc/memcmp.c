/* Correlated to newlib's openly licensed libc/string/memcmp.c. */
#include <string.h>

#define UNALIGNED(X, Y) (((long)(X) & (sizeof(long) - 1)) | ((long)(Y) & (sizeof(long) - 1)))
#define LBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < LBLOCKSIZE)

int memcmp(const void *m1, const void *m2, size_t n) {
    unsigned char *s1 = (unsigned char *)m1;
    unsigned char *s2 = (unsigned char *)m2;
    unsigned long *a1;
    unsigned long *a2;

    if (!TOO_SMALL(n) && !UNALIGNED(s1, s2)) {
        a1 = (unsigned long *)s1;
        a2 = (unsigned long *)s2;
        while (n >= LBLOCKSIZE) {
            if (*a1 != *a2)
                break;
            a1++;
            a2++;
            n -= LBLOCKSIZE;
        }
        s1 = (char *)a1;
        s2 = (char *)a2;
    }

    while (n--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}
