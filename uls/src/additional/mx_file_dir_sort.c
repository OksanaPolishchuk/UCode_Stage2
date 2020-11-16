#include "uls.h"

void mx_file_dir_sort(t_sorted_odj *sort, t_flags *flags) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    sort->len_of_dirs_array = 0;
    sort->len_of_files_array = 0;
    DIR *dir;
    
    sort->files = (char **)malloc(sizeof(char *) * flags->count_obj + 1);
    sort->dirs = (char **)malloc(sizeof(char *) * flags->count_obj + 1);
    for (int i = 0; i < flags->count_obj; i++) {
        if ((dir = opendir(flags->all_obj[i]))) {
            sort->dirs[a] = mx_strdup(flags->all_obj[i]);
            a++;
            closedir(dir);
        }
        else if (errno == 13) {
            sort->dirs[a] = mx_strdup(flags->all_obj[i]);
            a++;
        }
        else {
            sort->files[b] = mx_strdup(flags->all_obj[i]);
            b++;
        }
    }
    for (int j = a; j < flags->count_obj + 1; ++j) {
        sort->dirs[a] = NULL;
    }
    for (int j = b; j < flags->count_obj + 1; ++j) {
        sort->files[b] = NULL;
    }
    while (sort->dirs[c] != NULL) {
        sort->len_of_dirs_array++;
        c++;
    }
    while (sort->files[d] != NULL) {
        sort->len_of_files_array++;
        d++;
    }
    if (sort->len_of_files_array == 0) {
       mx_del_strarr(&sort->files);
    }

}
