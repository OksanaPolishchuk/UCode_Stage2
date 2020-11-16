#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;

    for (size_t i = 0; i < n; i++) {
        if (*str != (unsigned char)c)
            str++;
        else
            return (void *)str;
    }
    return 0;
}
