#include "pathfinder.h"

//mx_wrong_args_or_file
void mx_check_arg_and_file(int argc, char *argv[], t_finder *path) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    path->fd = open(argv[1], O_RDONLY);
    path->file_str = NULL;
    if (path->fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        mx_clean_memory(path);
        exit(1);
    }
}

