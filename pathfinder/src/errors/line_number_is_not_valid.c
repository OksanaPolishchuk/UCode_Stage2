#include "pathfinder.h"

void line_number_is_not_valid(char *file) {
    int fd = open(file, O_RDONLY);
    char *lineptr = NULL;
    int num = mx_read_line(&lineptr, 1, '\n', fd);
    int count = 1;

    for (int i = 0; lineptr[i] != '\0'; i++) {
        if(!mx_isdigit(lineptr[i])) {
            mx_printerr("error: line 1 is not valid");
            close(fd);
            exit(1);
        }
    }
    while (mx_read_line(&lineptr, 1, '\n', fd)) {
        char *line = NULL;
        mx_read_line(&line, 1, '-', fd);
        count++;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!mx_isalpha(line[i])) {
                mx_printerr("error: line [line_number] is not valid");
            }
        }
    }
    close(fd);
}




