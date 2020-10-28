#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *dst = mx_strnew(mx_strlen(s1));

    mx_strcpy(dst, s1);
    return dst;
}
