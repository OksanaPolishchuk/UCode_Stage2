#include "uls.h"

int mx_get_dir_len(char *obj, t_flags *flags) {
    DIR *d;
    int len_of_array = 0;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        while ((directory = readdir(d)) != NULL) {
            if (flags->switch_flags[0] == 1 || flags->switch_flags[6] == 1){
                if (flags->switch_flags[0] == 1) { // 'a' case
                    len_of_array++;
                }
                else if (flags->switch_flags[6] == 1 &&
                        (mx_strcmp(".", directory->d_name) != 0 &&
                        mx_strcmp("..", directory->d_name) != 0)) {
                    len_of_array++;
                }
            }
            else {
                if (directory->d_name[0] != '.') {
                    len_of_array++;
                }
            }
        }
        closedir(d);
    }
    return len_of_array;
}
