#include "pathfinder.h"

int main (int argc, char *argv[]) {
    t_finder *path = (t_finder *)malloc(sizeof(t_finder));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));

    mx_check_all_errors(argc, argv, path);
    mx_matrix_init(path, matrix);
    mx_floyd_algorithm(path, matrix);
    mx_results(path, matrix);
    mx_del_strarr(&path->unique);
    mx_del_strarr(&path->islands);
    mx_matrix_memory(path, matrix);
    mx_clean_memory(path);
    return 0;
}

