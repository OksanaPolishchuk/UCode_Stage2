#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    char *new = NULL;

    if (str && sub && replace) {
        new = mx_strnew(mx_strlen(str) + (mx_strlen(replace) - mx_strlen(sub)) 
                        * mx_count_substr(str, sub));
        for (int i = 0; *str != '\0'; ) {
            if (!mx_strncmp(str, sub, mx_strlen(sub))) {
                mx_strcat(new, replace);
                i += mx_strlen(replace);
                str += mx_strlen(sub);
            }
            else
                new[i++] = *str++;
        }
    }
    return new;
}
