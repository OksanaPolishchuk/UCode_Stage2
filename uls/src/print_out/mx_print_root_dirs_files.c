#include "uls.h"

void mx_print_root_dirs_files(t_flags *flags) {
    if (flags->argc == 2)
        mx_print_one_obj(flags->argv[1]);
    if (flags->argc > 2)
        mx_print_two_and_more_obj(flags);
}
