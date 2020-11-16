#include "uls.h"

int mx_max_len_of_inode(char *obj, t_flags *flags) {
    int res = 0;
    DIR *d;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        while ((directory = readdir(d)) != NULL) {
            if (flags->switch_flags[0] == 1 || flags->switch_flags[6] == 1) {
                if (flags->switch_flags[0] == 1) { // '-a' case
                    if (mx_intlen(directory->d_ino) > res) {
                        res = mx_intlen(directory->d_ino);
                    }
                }
                else if (flags->switch_flags[6] == 1 &&
                        (mx_strcmp(".", directory->d_name) != 0 &&
                        mx_strcmp("..", directory->d_name) != 0)) { // case '-A'
                    if (mx_intlen(directory->d_ino) > res) {
                        res = mx_intlen(directory->d_ino);
                    }
                }
            }
            else {
                if (directory->d_name[0] != '.') { // case without '-a' and '-A'
                    if (mx_intlen(directory->d_ino) > res)
                        res = mx_intlen(directory->d_ino);
                }
            }
        }
    }
    closedir(d);
    return res;
}
