#include "uls.h"

void mx_print_root_files(t_flags *flags) {
    DIR *d;
    struct dirent *dir;

    d = opendir(".");
    int i = 0;
    flags->all_obj = (char **)malloc(sizeof(char *) * flags->num_dir_file + 1);
    while ((dir = readdir(d)) != NULL)
        if (dir->d_name[0] != '.') {
            flags->all_obj[i] = mx_strdup(dir->d_name);
            i++;
        }
    mx_alphabet_sort(flags->all_obj, flags->num_dir_file);
    if (isatty(1)) {
        mx_output_by_size_of_wind(flags->all_obj, flags->num_dir_file);
    }
    else {
        mx_output_in_one_column(flags->all_obj, flags->num_dir_file);
    }
    closedir(d);
    exit(0);
}
