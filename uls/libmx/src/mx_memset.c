#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *value = (unsigned char *)b;

    while (len > 0) {
        *value++ = c;
        len--;
    }
    return b;
}
