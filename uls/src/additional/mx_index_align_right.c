#include "uls.h"

static int max_len_of_index(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort);

void mx_index_align_right(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int temp = 0;
    char *temp_str = NULL;
    int max_len_of_id = 0;

    max_len_of_id = max_len_of_index(lattrib, flags, sort);
    for (int i = 0; i < sort->len_of_files_array; i++) {
        lattrib[i]->id_str = mx_strnew(max_len_of_id);
        temp = max_len_of_id - mx_intlen(lattrib[i]->id);
        if (temp != 0) {
            for (int j = 0; j < temp; j++) {
                if (j == 0)
                    lattrib[i]->id_str = mx_strcpy(lattrib[i]->id_str, " ");
                else
                    lattrib[i]->id_str = mx_strcat(lattrib[i]->id_str, " ");
            }
            temp_str = mx_itoa(lattrib[i]->id);
            lattrib[i]->id_str = mx_strcat(lattrib[i]->id_str, temp_str);
        }
        else {
            temp_str = mx_itoa(lattrib[i]->id);
            lattrib[i]->id_str = mx_strcpy(lattrib[i]->id_str, temp_str);
        }
        if (temp_str)
            mx_strdel(&temp_str);
    }
}

static int max_len_of_index(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int res = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        if (mx_intlen(lattrib[i]->id) > res)
            res = mx_intlen(lattrib[i]->id);
    }
    return res;
}
