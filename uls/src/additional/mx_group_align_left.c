#include "uls.h"

static int max_len_of_groupid(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort);

void mx_group_align_left(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {

    int temp = 0;
    char *temp_str = NULL;
    int max_len_of_group = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        max_len_of_group = max_len_of_groupid(lattrib, flags, sort);
        lattrib[i]->group_str = mx_strnew(max_len_of_group);
        temp = max_len_of_group - mx_strlen(lattrib[i]->group);
        temp_str = mx_strnew(mx_strlen(lattrib[i]->group));
        mx_strcpy(temp_str, lattrib[i]->group);
        mx_strcpy(lattrib[i]->group_str, temp_str);
        if (temp != 0) {
            for (int j = 0; j < temp; j++)
                mx_strcat(lattrib[i]->group_str, " ");
        }
        if (temp_str)
            mx_strdel(&temp_str);
    }
}

static int max_len_of_groupid(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int res = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        if (mx_strlen(lattrib[i]->group) > res)
            res = mx_strlen(lattrib[i]->group);
    }
    return res;
}
