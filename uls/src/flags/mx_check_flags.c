#include "uls.h"

char **store_all_obj_array(t_flags *flags, int k);

// searching for flags
void mx_check_flags(t_flags *flags, t_sorted_odj *sort) {
    flags->count_obj = 0;
    flags->count_flags = 0;
    flags->switch_flags = (int *)malloc(sizeof(int) * 9);
    flags->all_obj = (char **)malloc(sizeof(char *) * 1000);

    for (int i = 0; i < 9; i++)
        flags->switch_flags[i] = 0;
    flags->all_flags = mx_strsplit(FLAGS, ' ');
    for (int k = 1; flags->argv[k] != NULL; k++) {
        if (flags->argv[k][0] == '-' && flags->argv[k][1]) {
            for (int h = 1; flags->argv[k][h]; h++) {
                for (int j = 0; flags->all_flags[j]; j++)
                    if (flags->argv[k][h] == flags->all_flags[j][0]) {
                        flags->switch_flags[j] = 1;
                        flags->count_flags += 1;
                    }
            }
        }
// move all obj after flags to new 2d array
        if (flags->argv[k][0] != '-' || (flags->argv[k][0] == '-' &&
            !flags->argv[k][1])) {
            flags->all_obj = store_all_obj_array(flags, k);
            break;
        }
// move all obj after '--' to new 2d array
        if (flags->argv[k][0] == '-' && flags->argv[k][1] == '-' &&
            !flags->argv[k][2]) {
            k += 1;
            flags->all_obj = store_all_obj_array(flags, k);
            mx_file_dir_sort(sort, flags);
            break;
        }
    }
}

char **store_all_obj_array(t_flags *flags, int k) {
    for (int i = 0; flags->argv[k]; i++, k++) {
        flags->all_obj[i] = mx_strdup(flags->argv[k]);
        flags->count_obj++;
    }
    return flags->all_obj;
}
