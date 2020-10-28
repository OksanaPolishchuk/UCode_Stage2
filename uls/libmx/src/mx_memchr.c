#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *pointer = (unsigned char *)s;

    for (size_t i = 0; i < n; i++)
        if (*pointer++ == c)
            return --pointer;
    return NULL;
}
