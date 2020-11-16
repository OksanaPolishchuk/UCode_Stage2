#include "uls.h"

int mx_the_biggest_name(char **array, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        int temp = mx_strlen(array[i]);
        if (temp > res)
            res = temp;
    }
    return res;
}
