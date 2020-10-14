#include "pathfinder.h"

void check_arg2_is_file(char *file){
    int fd = open(file, O_RDONLY | O_DIRECTORY);

    if (fd > 0){
        mx_printerr("usage: ./pathfinder [filename]\n");
        close(fd);
        exit(1);
    }

    close(fd);
}
