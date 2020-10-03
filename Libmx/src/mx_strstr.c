#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    int len2 = mx_strlen(s2);
    int ptr = 0;
    
    while (*s1 != 0) {
        ptr = *s1;
        if (mx_strncmp(s1, s2, len2) == 0)
            return mx_strchr(s1, ptr);
        s1++;
    }
    return 0;
}

