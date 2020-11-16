#include "uls.h"

void mx_array_reverse(char **arr, int len) {
    char *temp;
    int j = len - 1;
    for (int i = 0; i < j; i++) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}
