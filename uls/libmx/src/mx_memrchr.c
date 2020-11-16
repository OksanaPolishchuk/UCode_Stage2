#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;

    for (; *str != '\0'; str++);
    for (size_t i = n; i > 0; i--) {
        if (*str != (unsigned char)c)
            str--;
        else
            return (void *)str;
    }
    return 0;
}
