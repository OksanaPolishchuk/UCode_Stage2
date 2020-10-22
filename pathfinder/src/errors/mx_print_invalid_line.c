#include "pathfinder.h"

void mx_print_invalid_line(int line, t_finder *path) {
    char *print = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(print);
    mx_printerr(" is not valid\n");
    mx_clean_memory(path);
    exit(1); 
}

