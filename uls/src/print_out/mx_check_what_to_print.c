#include "uls.h"

// ./uls -l print output
void mx_check_what_to_print(t_flags *flags, t_lattrib **lattrib, t_sorted_odj *sort) {
    if (flags->switch_flags[1] == 1 && flags->switch_flags[2] == 0 &&
            flags->switch_flags[3] == 0)
        mx_print_l_flag(lattrib, flags, sort);
    else if (flags->switch_flags[2] == 1 && flags->switch_flags[1] == 1 &&
            flags->switch_flags[3] == 0)
        mx_print_li_flag(lattrib, flags, sort);
    if (flags->switch_flags[2] == 0 && flags->switch_flags[1] == 1 &&
            flags->switch_flags[3] == 1) {
        mx_flag_h(lattrib, flags, sort);
        mx_print_lh_flag(lattrib, flags, sort);
    }
    if (flags->switch_flags[2] == 1 && flags->switch_flags[1] == 1 &&
            flags->switch_flags[3] == 1) {
        mx_flag_h(lattrib, flags, sort);
        mx_print_lhi_flag(lattrib, flags, sort);
    }

    mx_cleaner(sort, lattrib);
}
