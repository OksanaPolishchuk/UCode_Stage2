#include "uls.h"

static int max_len_of_user(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort);

void mx_username_align_left(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {

    int temp = 0;
    char *temp_str = NULL;
    int max_len_of_uname = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        max_len_of_uname = max_len_of_user(lattrib, flags, sort);
        lattrib[i]->user_str = mx_strnew(max_len_of_uname);
        temp = max_len_of_uname - mx_strlen(lattrib[i]->user);
        temp_str = mx_strnew(mx_strlen(lattrib[i]->user));
        mx_strcpy(temp_str, lattrib[i]->user);
        mx_strcpy(lattrib[i]->user_str, temp_str);
        if (temp != 0) {
            for (int j = 0; j < temp; j++)
                mx_strcat(lattrib[i]->user_str, " ");
        }
        if (temp_str)
            mx_strdel(&temp_str);
    }
}

static int max_len_of_user(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    int res = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        if (mx_strlen(lattrib[i]->user) > res)
            res = mx_strlen(lattrib[i]->user);
    }
    return res;
}
