#include "pathfinder.h"

void mx_invalid_bridges(t_finder *path) {
    char *buf = mx_strchr(path->file_str, ',');

    for (unsigned len = 0; buf; buf = mx_strchr(buf, ',')) {
        len += mx_atoi(++buf);
        if (len > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            mx_del_strarr(&path->unique);
            mx_del_strarr(&path->islands);
            mx_clean_memory(path);
            exit(1);

        }
    }
}

