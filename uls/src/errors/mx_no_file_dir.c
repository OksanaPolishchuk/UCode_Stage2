#include "uls.h"

void mx_no_file_dir(char *fd) {
    mx_printerr("uls: ");
    mx_printerr(fd);
    mx_printerr(": No such file or directory\n");
}
