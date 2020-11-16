#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
				int c, size_t n) {
    unsigned char *pdst = (unsigned char *)dst;
    unsigned char *psrc = (unsigned char *)src;
	size_t i = 0;

// 	for (i = 0; i < n; i++) {
// 		*pdst++ = *psrc++;
// 		if (*pdst == (char)c)
// 			return pdst + 1;
// 	}
// 	return dst;
// }

	for (i = 0; i < n; i++) {
		pdst[i] = psrc[i];
		if (pdst[i] == (char)c)
			return pdst + 1;
	}
	return dst;
}
