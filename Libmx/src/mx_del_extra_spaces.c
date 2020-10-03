#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *cleared = NULL;
    char *tmp = NULL;
    int j = 0;

    if (NULL == str)
        return NULL;
    tmp = mx_strnew(mx_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) == 0) {
            tmp[j] = str[i];
            j++;
        }
        if (mx_isspace(str[i]) == 0 && mx_isspace(str[i + 1]) == 1) {
            tmp[j] = ' ';
            j++;
        }
    }
    cleared = mx_strtrim(tmp);
    mx_strdel(&tmp);
    return cleared;
}
