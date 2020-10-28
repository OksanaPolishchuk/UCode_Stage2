#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#define INT_MAX 2147483647

typedef struct s_finder {
    int fd;
    int phrase;
    int n_islands;
    char *file_str;
    char **unique;
    char **islands;
}               t_finder;

typedef struct s_matrix {
    int len;
    int *pattern;
    long **first;
    long **map;
}         t_matrix;

/* validation */

void mx_check_all_errors(int argc, char *argv[], t_finder *path);
void mx_check_is_empty(char *argv[], t_finder *path);
void mx_check_arg_and_file(int argc, char *argv[], t_finder *path);
void mx_check_invalid_line(t_finder *path); /
void mx_invalid_num_of_islands(t_finder *path);
void mx_print_invalid_line(int line,t_finder *path);
void mx_invalid_bridges(t_finder *path);

// algorithm

void mx_matrix_init(t_finder *path, t_matrix *matrix);
void mx_floyd_algorithm(t_finder *path, t_matrix *matrix);

// result and cleaning

void mx_print_limit();
void mx_results(t_finder *path, t_matrix *matrix);
void mx_clean_memory(t_finder *path);
void mx_matrix_memory(t_finder *path, t_matrix *matrix);

#endif
