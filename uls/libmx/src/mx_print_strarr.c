#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr && delim) {
        for(int i = 0; arr[i] != NULL; mx_printstr(arr[i++]))
            if (i != 0)
                mx_printstr(delim);
        mx_printchar('\n');
    }
}
