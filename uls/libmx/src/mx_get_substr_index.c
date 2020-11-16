#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[0]) {
            int k = 1;
            for (int j = i + 1; str[j] != '\0' || sub[k] != '\0'; j++, k++) {
                if (str[j] == sub[k] && sub[k + 1] == '\0')
                    return i;
                if (str[j] != sub[k])
                    break;
            }
        }
    }
    return -1;
}
