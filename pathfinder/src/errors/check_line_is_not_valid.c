
#include "pathfinder.h"

void check_line_is_not_valid(char *file) {
    int fd = open(file, O_RDONLY);
    char *lineptr = NULL;

    int num = mx_read_line(&lineptr, 1, '\n', fd);
    for (int i = 0; lineptr[i] != '\0'; i++) {
        if(!mx_isdigit(lineptr[i])) {
            mx_printerr("error: line 1 is not valid");
            close(fd);
            exit(1);
        }
    }
    close(fd);
}
