#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int isinword = 0;
    int word_count = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == delimiter) {
            isinword = 0;
        }
        else if (isinword == 0) {
            ++word_count;
            isinword = 1;
        }
    }
    return word_count;
}
