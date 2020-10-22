#include "pathfinder.h"

void mx_floyd_algorithm(t_finder *path, t_matrix *matrix) {
    long sum;
    int i;

    for (i = 0; i < path->n_islands; i++) { // duplicate 1st table
        for (int j = i; j < path->n_islands; j++) {
            matrix->first[i][j] = matrix->map[i][j];
            matrix->first[j][i] = matrix->map[j][i];
        }
    }
    for (int k = 0; k < path->n_islands; k++) {
        for (i = 0; i < path->n_islands; i++) {
            for (int j = i + 1; j < path->n_islands; j++) {
                sum = matrix->map[k][j] + matrix->map[i][k];
                if (matrix->map[i][j] > sum) {
                    matrix->map[i][j] = sum;
                    matrix->map[j][i] = sum;
                }
            }
        }
    }
}

