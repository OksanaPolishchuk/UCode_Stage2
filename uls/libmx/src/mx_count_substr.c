#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int i;
    const char *buf = str;

    if (NULL == str || NULL == sub)
        return -1;
    if (mx_strlen(sub) == 0 || mx_strlen(str) == 0)
        return 0;
    for (i = 0; (buf = mx_strstr(buf, sub)) != 0; i++)
        buf++;
    return i;
}
