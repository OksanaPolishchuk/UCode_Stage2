#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *pointer;

    if (s) { 
        pointer = (unsigned char *)s + mx_strlen(s);
        for (size_t i = 0; i < n; i++)
            if (*pointer-- == c)
                return ++pointer;
    }
    return NULL;
}
