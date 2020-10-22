#include "pathfinder.h"

static void print_shortest_path(t_finder *path, t_matrix *matrix);
static bool check_shortest_path(t_finder *path, t_matrix *matrix, int k);
static void print_path_and_route(t_finder *path, t_matrix *matrix);
static void print_distance(t_finder *path, t_matrix *matrix);

void mx_results(t_finder *path, t_matrix *matrix) {
    for (int i = 0; i < path->n_islands; i++) {
        for (int j = i + 1; j < path->n_islands; j++) {
            matrix->pattern = (int *)malloc(sizeof(int) * (path->n_islands));
            matrix->len = 1;
            matrix->pattern[0] = j;
            matrix->pattern[matrix->len] = i;
            print_shortest_path(path, matrix);
            free(matrix->pattern);
        }
    }
}

static void print_shortest_path(t_finder *path, t_matrix *matrix) {
    for (int k = 0; k < path->n_islands; k++) {
        if (k != matrix->pattern[matrix->len]
            && check_shortest_path(path, matrix, k)) {
            matrix->pattern[++matrix->len] = k;
            print_shortest_path(path, matrix);
            matrix->len--;
        }
    }
    if (matrix->pattern[matrix->len] != matrix->pattern[0])
        return;
    print_path_and_route(path, matrix);
    print_distance(path, matrix);
}

static bool check_shortest_path(t_finder *path, t_matrix *matrix, int k) {
    int i = matrix->pattern[matrix->len];
    int j = matrix->pattern[0];

    if (matrix->first[i][k] == matrix->map[i][j] - matrix->map[k][j])
        return true;
    return false;
}

static void print_path_and_route(t_finder *path, t_matrix *matrix) {
    mx_print_limit();
    mx_printstr("Path: ");
    mx_printstr(path->unique[matrix->pattern[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->unique[matrix->pattern[matrix->len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix->len + 1; ) {
        mx_printstr(path->unique[matrix->pattern[i]]);
        ++i < matrix->len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static void print_distance(t_finder *path, t_matrix *matrix) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < matrix->len; i++){
        mx_printint(matrix->first[matrix->pattern[i]][matrix->pattern[i + 1]]);
        sum += matrix->first[matrix->pattern[i]][matrix->pattern[i + 1]];
        if (i < matrix->len - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_print_limit();
}
