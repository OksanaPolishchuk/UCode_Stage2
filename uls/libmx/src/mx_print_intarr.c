#include "libmx.h"

void mx_print_intarr(int **arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            mx_printint(arr[i][j]);
            write(1, "\t", 1);
        }
	write(1, "\n", 1);
    }
}
