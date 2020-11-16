#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len){
    const unsigned char *big2 = big;
    const unsigned char *lit2 = little;

    for (size_t i = 0; i < big_len; i++) {
        if (mx_memcmp(big2, lit2, little_len) == 0)
            return (void *)big2;
        big2++;
    }
    return 0;
}
