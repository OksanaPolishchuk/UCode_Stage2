#include "pathfinder.h"

void check_arg2_is_exist(char *file){
    int fd = open(file, O_RDONLY);

    if (fd < 0){
        mx_printerr("error: file [filename] does not exist\n");
        close(fd);
        exit(1);
    }

    close(fd);
}
