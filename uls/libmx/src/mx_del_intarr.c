#include "libmx.h"

void mx_del_intarr(int **arr, int len) {
    if (arr) {
        for (int i = 0; i < len; i++)
            free(arr[i]);
        free(arr);
    }
}
