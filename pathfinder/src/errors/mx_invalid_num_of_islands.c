#include "pathfinder.h"

static void unique_islands(t_finder *path);
static void double_islands(t_finder *path);
static void duplicate_bridges(t_finder *path);

static void print_invalid_number(t_finder *path) {
    mx_printerr("error: invalid number of islands\n");
    mx_clean_memory(path);
    exit(1);
}

void mx_invalid_num_of_islands(t_finder *path) {
    char *buf = mx_strdup(path->file_str);

    path->n_islands = mx_atoi(buf);
    if (path->n_islands < 2)
        print_invalid_number(path);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == ',' || buf[i] == '\n' || mx_isdigit(buf[i]))
            buf[i] = '-';
    path->phrase = mx_count_words(buf, '-');
    path->unique = (char **)malloc(sizeof(char *) * path->phrase);
    path->islands = mx_strsplit(buf, '-');
    mx_strdel(&buf);
    unique_islands(path);
    double_islands(path);
    duplicate_bridges(path);
}

static void unique_islands(t_finder *path) {
    int num = 1;

    if (path->islands[0] == NULL)
        print_invalid_number(path);
    path->unique[0] = mx_strdup(path->islands[0]);
    for (int i = 1; i < path->phrase; i++) {
        for (int j = 0; j < num; ) {
            if (!mx_strcmp(path->unique[j], path->islands[i]))
                break;
            if (++j == num)
                path->unique[num++] = mx_strdup(path->islands[i]);
        }
    }
    if (path->n_islands != num) {
        mx_del_strarr(&path->unique);
        print_invalid_number(path);
    }
}

static void double_islands(t_finder *path) {
    int line = 2;

    for (int i = 1; i < path->phrase; i +=2) {
        if (!mx_strcmp(path->islands[i], path->islands[i - 1])) {
            mx_del_strarr(&path->islands);
            mx_del_strarr(&path->unique);
            mx_print_invalid_line(line, path);
        }
        line++;
    }
}

static void duplicate_bridges(t_finder *path) {
    for (int i = 0; i < path->phrase; i +=2) {
        for (int j = i + 2; j < path->phrase; j+=2) {
            if (!mx_strcmp(path->islands[i], path->islands[j])
                || !mx_strcmp(path->islands[i], path->islands[j + 1])) {
                if (!mx_strcmp(path->islands[i + 1], path->islands[j + 1])
                    || !mx_strcmp(path->islands[i + 1], path->islands[j])) {
                    mx_printerr("error: duplicate bridges\n");
                    mx_del_strarr(&path->islands);
                    exit(1);
                }
            }
        }
    }
}

