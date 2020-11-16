#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *pdst = (unsigned char *)dst;
    unsigned char *psrc = (unsigned char *)src;

    for (size_t i = 0; i < n; i++)
        *pdst++ = *psrc++;
    return dst;
}
