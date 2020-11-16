#include "uls.h"

static int max_len_of_links(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort);

void mx_links_align_right(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int temp = 0;
    char *temp_str = NULL;
    int max_len_of_lk = 0;

    max_len_of_lk = max_len_of_links(lattrib, flags, sort);
    for (int i = 0; i < sort->len_of_files_array; i++) {
        lattrib[i]->lk_str = mx_strnew(max_len_of_lk);
        temp = max_len_of_lk - mx_intlen(lattrib[i]->links);
        if (temp != 0) {
            for (int j = 0; j < temp; j++) {
                if (j == 0)
                    lattrib[i]->lk_str = mx_strcpy(lattrib[i]->lk_str, " ");
                else
                    lattrib[i]->lk_str = mx_strcat(lattrib[i]->lk_str, " ");
            }
            temp_str = mx_itoa(lattrib[i]->links);
            lattrib[i]->lk_str = mx_strcat(lattrib[i]->lk_str, temp_str);
        }
        else {
            temp_str = mx_itoa(lattrib[i]->links);
            lattrib[i]->lk_str = mx_strcpy(lattrib[i]->lk_str, temp_str);
        }
        if (temp_str)
            mx_strdel(&temp_str);
    }
}
static int max_len_of_links(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int res = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        if (mx_intlen(lattrib[i]->links) > res)
            res = mx_intlen(lattrib[i]->links);
    }
    return res;
}
