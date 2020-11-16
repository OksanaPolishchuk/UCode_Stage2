#include "uls.h"

void mx_check_and_connect_flags(t_flags *flags, t_sorted_odj *sort) {
    t_lattrib **lattrib = NULL;
    t_result *result_of_work_i = NULL;
// all flags: -a0 -l1 -i2 -h3 -p4 -15 -A6 -r7 -s8

// flag -i
    if (flags->switch_flags[1] == 0 && flags->switch_flags[2] == 1 &&
        flags->switch_flags[3] == 0 && flags->switch_flags[4] == 0 &&
        flags->switch_flags[8] == 0)
        mx_flag_i(flags);
// flag -l
    if (flags->switch_flags[1] == 1 && flags->switch_flags[4] == 0 &&
        flags->switch_flags[5] == 0 && flags->switch_flags[7] == 0 &&
        flags->switch_flags[8] == 0 && flags->switch_flags[0] == 0 &&
        flags->switch_flags[6] == 0)
        mx_flag_l(flags, sort);
// flags -p
    if (flags->switch_flags[1] == 0 && flags->switch_flags[2] == 0 &&
        flags->switch_flags[3] == 0 && flags->switch_flags[4] == 1 && flags->switch_flags[8] == 0)
        mx_flag_p(flags);
}
