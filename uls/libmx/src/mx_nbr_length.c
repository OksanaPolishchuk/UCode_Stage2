#include "libmx.h"

int mx_nbr_length(int num) {
    int len = 1;

    while (num /= 10)
        len++;
    return len;
}
