#include "libmx.h"

static void mx_swap(char **arr, int i, int j, int *swap) {
    char *tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    (*swap)++;
}

int mx_quicksort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = (left + right) / 2;
    int swap = 0;

    if (!arr)
        return -1;
    if (i < j) {
        for ( ; mx_strlen(arr[i]) < mx_strlen(arr[pivot]); i++);
        for ( ; mx_strlen(arr[j]) > mx_strlen(arr[pivot]); j--);
        if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j]))
            mx_swap(arr, i, j, &swap);
        --j > left ? swap += mx_quicksort(arr, left, j) : j;
        ++i < right ? swap += mx_quicksort(arr, i, right) : i;
    }

    return swap;
}
