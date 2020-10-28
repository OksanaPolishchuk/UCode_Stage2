#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0;

    if (NULL == str)
        return -1;
    for (int i = 0 ; str[i] != '\0'; i++) {
        if (str[i] == delimiter && str[i + 1] != '\0')
            i++;
        if (str[i] != delimiter) {
            count++;
            while((str[i]) != delimiter && str[i + 1] != '\0' )
                i++;
        }
    }
    return count;
}
