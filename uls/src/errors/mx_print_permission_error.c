#include "uls.h"

void mx_print_permission_error(char *fd) {
    mx_printerr("uls: ");
    mx_printerr(fd);
    mx_printerr(": Permission denied\n");
}

