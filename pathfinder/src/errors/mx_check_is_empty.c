#include "pathfinder.h"

void mx_check_is_empty(char *argv[], t_finder *path) {
    char *buf = mx_strnew(1);
    int chars = read(path->fd, buf, 1);

    if (chars == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        mx_clean_memory(path);
        exit(1);
    }
    mx_strdel(&buf);
    close(path->fd);
    path->file_str = mx_file_to_str(argv[1]);
}

