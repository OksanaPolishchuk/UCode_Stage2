#include "pathfinder.h"

void mx_check_all_errors(int argc, char *argv[], t_finder *path) {
    mx_check_arg_and_file(argc, argv, path);
    mx_check_is_empty(argv, path);
    mx_check_invalid_line(path);
    mx_invalid_num_of_islands(path);
    mx_invalid_bridges(path);
}

