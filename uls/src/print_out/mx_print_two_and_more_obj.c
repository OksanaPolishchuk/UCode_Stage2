#include "uls.h"

void mx_print_two_and_more_obj(t_flags *flags) {
    t_sorted_odj *sort = (t_sorted_odj *) malloc(sizeof(t_sorted_odj));
    sort->len_of_dirs_array = sort->len_of_files_array = 0;
    mx_file_dir_sort(sort, flags);
    if (sort->len_of_dirs_array == 1 && sort->len_of_files_array == 0) {
        if (!opendir(sort->dirs[0]));
        else if (flags->error_checher == 1 && sort->len_of_dirs_array == 1 &&
            sort->len_of_files_array == 0) {
            mx_printstr(sort->dirs[0]);
            mx_printstr(":\n");
        }
    }
    if (sort->len_of_files_array != 0) {
        mx_alphabet_sort(sort->files, sort->len_of_files_array);
    }
    if (sort->len_of_dirs_array != 0) {
        mx_alphabet_sort(sort->dirs, sort->len_of_dirs_array);
    }
    if (sort->len_of_files_array != 0) {
        if (isatty(1))
            mx_output_by_size_of_wind(sort->files, sort->len_of_files_array);
        else
            mx_output_in_one_column(sort->files, sort->len_of_files_array);
    }
    for (int j = 0; j < sort->len_of_dirs_array; ++j) {
        if (flags->count_obj != 1) {
            if (j != 0 || sort->len_of_files_array != 0)
                mx_printchar('\n');
            mx_printstr(sort->dirs[j]);
            mx_printstr(":\n");
        }
        mx_print_one_obj(sort->dirs[j]);
    }
    if (sort) {
        if (sort->files)
            mx_del_strarr(&sort->files);
        if (sort->dirs)
            mx_del_strarr(&sort->dirs);
        free(sort);
    }
}
