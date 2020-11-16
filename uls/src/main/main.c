#include "uls.h"

static void count_objects(t_flags *flags);

int main(int argc, char **argv) {
    t_flags *flags = (t_flags*)malloc(sizeof(t_flags));
    t_sorted_odj *sort = (t_sorted_odj *)malloc(sizeof(t_sorted_odj));
    t_lattrib **lattrib = NULL;
    flags->argc = argc;
    flags->argv = argv;

    count_objects(flags);
// if just ./uls
    if (flags->argc == 1 || ((mx_strcmp(flags->argv[1], "-h") == 0) &&
        !flags->argv[2]) || ((mx_strcmp(flags->argv[1], "--") == 0) &&
        !flags->argv[2])) {
        mx_print_root_files(flags);
    }
// check illegal flags
    mx_error_illegal_option(flags);
// if ./uls + flags(-i -l -la ...)
    mx_check_flags(flags, sort);
    mx_check_and_rewrite_obj(flags);
    mx_check_and_connect_flags(flags, sort);

    if (flags->argc > 1 && flags->count_flags == 0)
        mx_print_two_and_more_obj(flags);
//     mx_printstr("\n\n");
//     system("leaks -q uls");
    if (flags->error_checher == 1)
        exit(1);
    else
        exit(0);
}

static void count_objects(t_flags *flags) {
    DIR *d;
    struct dirent *dir;
    flags->num_dir_file = 0;

    d = opendir(".");
    while ((dir = readdir(d)) != NULL)
        if (dir->d_name[0] != '.')
            flags->num_dir_file++;
    closedir(d);
}
