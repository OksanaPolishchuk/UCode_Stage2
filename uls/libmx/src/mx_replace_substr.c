#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    char *arrrep = NULL;
    int sub_len;
    int replace_len;
    int i = 0;

    if (!str || !sub || !replace)
        return NULL;
    sub_len = mx_strlen(sub);
    replace_len = mx_strlen(replace);
    i = mx_get_substr_index(str, sub);
    arrrep = mx_strnew(mx_strlen(str) + (sub_len - replace_len) *
    			mx_count_substr(str, sub));
    i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&arrrep[i], replace);
            i += sub_len;
            str += replace_len;
        }
        else
            arrrep[i++] = *str++;
    }
    return arrrep;
}
