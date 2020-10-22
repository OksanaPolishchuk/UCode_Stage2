#include "pathfinder.h"

void mx_clean_memory(t_finder *path) {
    if (path->file_str)
        mx_strdel(&path->file_str);
    free(path);
}

