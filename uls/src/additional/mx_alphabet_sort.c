#include "uls.h"

void mx_alphabet_sort(char **array, int len) {
    char *temp_str = NULL;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (mx_strcmp(array[i], array[j]) > 0) {
                temp_str = array[i];
                array[i] = array[j];
                array[j] = temp_str;
            }
        }
    }
}
