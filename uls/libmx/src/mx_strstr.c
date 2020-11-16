#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!haystack || !needle)
        return NULL;
    while (*haystack != '\0') {
        if (mx_strncmp(haystack, needle, mx_strlen(needle)) == 0)
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}
