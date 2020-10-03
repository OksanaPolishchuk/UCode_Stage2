#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, 
				size_t little_len) {
    			unsigned char *p_big = (unsigned char *)big;
    			unsigned char *p_little = (unsigned char *)little;

    if (!(big_len < little_len) && (big_len && little_len) > 0)
        for ( ; *p_big; p_big++)
            if (!mx_memcmp(p_big, p_little, little_len - 1))
                return p_big;
    return NULL;
}
