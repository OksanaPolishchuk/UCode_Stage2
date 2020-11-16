#include "uls.h"

int mx_max_len_of_size(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int res = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        if (mx_intlen(lattrib[i]->size) > res)
            res = mx_intlen(lattrib[i]->size);
    }
    return res;
}
