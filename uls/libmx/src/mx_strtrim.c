#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *str2 = NULL;
    int j = 0;
    int i = 0;
    int length = mx_strlen(str);

    if (!str)
        return NULL;
    while (mx_isspace(str[i]))
        i++;
    while (mx_isspace(str[length - 1]))
        length--;
    str2 = mx_strnew(length - i);
    while (i < length) {
        str2[j] = str[i];
        i++;
        j++;
    }
    return str2;
}
