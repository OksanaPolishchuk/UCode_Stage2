#include "pathfinder.h"

static int index_of_island(char *island, t_finder *path);
static void memory_for_matrices(t_finder *path, t_matrix *matrix);

void mx_matrix_init(t_finder *path, t_matrix *matrix) {
    int i;
    int j;
    char *buf = mx_strchr(path->file_str, ',');

    memory_for_matrices(path, matrix);
    for (i = 0; i < path->n_islands; i++) {
        for (j = 0; j < path->n_islands; j++) {
            matrix->map[i][j] = (i != j ? INT_MAX : 0);
        }
    }
    for (int ai = 0 ; (buf = mx_strchr(buf, ',')); ai +=2) {
        i = index_of_island(path->islands[ai], path);
        j = index_of_island(path->islands[ai + 1], path);
        matrix->map[i][j] = mx_atoi(++buf);
        matrix->map[j][i] = matrix->map[i][j];
    }
}

static void memory_for_matrices(t_finder *path, t_matrix *matrix) {
    matrix->map = (long **)malloc(sizeof(long *) * path->n_islands);
    matrix->first = (long **)malloc(sizeof(long *) * path->n_islands);
    for (int i = 0; i < path->n_islands; i++) {
        matrix->map[i] = (long *)malloc(sizeof(long) * path->n_islands);
        matrix->first[i] = (long *)malloc(sizeof(long) * path->n_islands);
    }
}

static int index_of_island(char *island, t_finder *path) {
    for (int i = 0; path->unique[i]; i++)
        if (!mx_strcmp(island, path->unique[i]))
            return i;
    return 0;
}
