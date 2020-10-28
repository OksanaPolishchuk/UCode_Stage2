#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, 
                 int c, size_t n) {
    size_t i;

    for(i = 0; i < n; ) {
        ((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
        if (((const unsigned char *)src)[i++] == (unsigned char)c)
            break;
    }
    return i == n ? NULL : &(((unsigned char *)dst)[i]);
}
