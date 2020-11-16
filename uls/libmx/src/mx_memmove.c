#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *pdst = dst;
    const unsigned char *psrc = src;
    char *temp = NULL;

    temp = mx_strnew(len);
    mx_memcpy(temp, psrc, len);
    for (size_t i = 0; i < len; i++)
        pdst[i] = temp[i];
    free(temp);
    return (void *)pdst;
}
