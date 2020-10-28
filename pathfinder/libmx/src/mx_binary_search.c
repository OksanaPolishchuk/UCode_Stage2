#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int mid;

    if (!*arr)
        return -1;
    else {
        while (left <= right) {
            (*count)++;
            mid = (left + right) / 2;
            if (mx_strcmp(arr[mid], s) == 0)
                return mid;
            else if (mx_strcmp(arr[mid], s) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        *count = 0;
        return -1;
    }
}
