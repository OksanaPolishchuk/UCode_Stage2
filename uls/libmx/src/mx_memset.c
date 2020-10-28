#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    for (size_t i = 0; i < len; ((unsigned char *)b)[i++] = c);
    return b;
}
