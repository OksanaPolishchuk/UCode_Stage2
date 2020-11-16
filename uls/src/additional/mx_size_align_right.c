#include "uls.h"

void mx_size_align_right(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int temp = 0;
    char *temp_str = NULL;
    int max_len_of_size = 0;
    max_len_of_size = mx_max_len_of_size(lattrib, flags, sort);
    for (int i = 0; i < sort->len_of_files_array; i++) {
        lattrib[i]->size_str = mx_strnew(max_len_of_size);
        temp = max_len_of_size - mx_intlen(lattrib[i]->size);
        if (temp != 0) {
            for (int j = 0; j < temp; j++) {
                if (j == 0)
                    lattrib[i]->size_str = mx_strcpy(lattrib[i]->size_str, " ");
                else
                    lattrib[i]->size_str = mx_strcat(lattrib[i]->size_str, " ");
            }
            temp_str = mx_itoa(lattrib[i]->size);
            lattrib[i]->size_str = mx_strcat(lattrib[i]->size_str, temp_str);
        }
        else {
            temp_str = mx_itoa(lattrib[i]->size);
            lattrib[i]->size_str = mx_strcpy(lattrib[i]->size_str, temp_str);
        }
        if (temp_str)
            mx_strdel(&temp_str);
    }
}
