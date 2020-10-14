#include "pathfinder.h"

void check_arg2_is_empty(char *file) {
    int fd = open(file, O_RDONLY);
    char *lineptr = NULL;

    int num = mx_read_line(&lineptr, 1, '\n', fd);
    if (num == -1) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        close(fd);
        exit(1);
    }
    close(fd);
}

