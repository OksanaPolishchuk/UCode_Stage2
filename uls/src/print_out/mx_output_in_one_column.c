#include "uls.h"

/*
 * flag -1
 */
void mx_output_in_one_column(char **array, int len_of_array) {
    for (int i = 0; i < len_of_array; i++) {
        mx_printstr(array[i]);
        mx_printchar('\n');
    }
}
