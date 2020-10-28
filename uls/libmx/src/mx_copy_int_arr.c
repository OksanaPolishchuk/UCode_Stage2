#include "libmx.h"

int *mx_copy_int_arr(const int *src, int size) {
    int *new_arr = NULL;

    if (NULL == src || size <= 0)
        return NULL;
    new_arr = (int *)malloc(sizeof(int) * (size));
    for (int i = 0; i < size; i++)
        new_arr[i] = src[i];
    return new_arr;
}
