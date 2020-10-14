#include "pathfinder.h"

void check_all_errors(char *file) {
    check_arg2_is_file(file);
    check_arg2_is_exist(file);
    check_arg2_is_empty(file);
    check_line_is_not_valid(file);
    line_number_is_not_valid(file);

}

