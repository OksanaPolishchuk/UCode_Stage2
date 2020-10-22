#include "pathfinder.h"

static void del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path->n_islands; i++)
            free(arr[i]);
        free(arr);

    }
}

void mx_matrix_memory(t_finder *path, t_matrix *matrix) {
    del_int_arr((int **)matrix->first, path);
    del_int_arr((int **)matrix->map, path);
    free(matrix);
}

