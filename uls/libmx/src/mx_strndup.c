#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *s2 = NULL;
    int len = 0;
    size_t buf = 0;

    if (!s1)
        return NULL;
    len = mx_strlen(s1);
    if ((size_t)len < n)
        buf = (size_t)len;
    else
        buf = n;
    s2 = mx_strnew(buf);
    for (size_t c = 0; c < buf; c++)
        s2[c] = s1[c];
    return s2;
}
