#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int num_swap = 0;

    if (!arr)
        return -1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *n = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = n;
                num_swap++;
            }
        }
    }
    return num_swap;
}
