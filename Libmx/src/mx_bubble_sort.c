#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *tmp;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                count++;
            }
        }
    }
    return count;
}
