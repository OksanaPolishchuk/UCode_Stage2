#include "uls.h"

void mx_alphabet_sort3(char **array, int len) {
    char *temp_str = NULL;
    bool change1 = false;
    bool change2 = false;
    bool swap = false;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (array[i][mx_strlen(array[i]) - 1] == '/') {
                array[i][mx_strlen(array[i]) - 1] = '\0';
                change1 = true;
            }
            if (array[j][mx_strlen(array[j]) - 1] == '/') {
                array[j][mx_strlen(array[j]) - 1] = '\0';
                change2 = true;
            }
            if (mx_strcmp(array[i], array[j]) > 0) {
                temp_str = array[i];
                array[i] = array[j];
                array[j] = temp_str;
                swap = true;
            }
            if (!swap) {
                if (change1)
                    array[i][mx_strlen(array[i])] = '/';
                if (change2)
                    array[j][mx_strlen(array[j])] = '/';
            } else {
                if (change1)
                    array[j][mx_strlen(array[j])] = '/';
                if (change2)
                    array[i][mx_strlen(array[i])] = '/';
            }
            swap = change1 = change2 = false;
        }
    }
}
