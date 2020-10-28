#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    const char *p = haystack;

    if (mx_strlen(needle) == 0)
        return (char *) p;
    for ( ; (p = mx_strchr(p, *needle)) != 0; p++) {
        if (mx_strncmp(p, needle, mx_strlen(needle)) == 0)
            return (char *) p;
    }
    return 0;
}
