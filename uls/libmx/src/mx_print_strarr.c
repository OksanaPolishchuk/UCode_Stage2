#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int a = 0;

	if (arr == NULL || delim == NULL)
		return;

	if (mx_strlen(delim) >= 0) {
		while(arr[a] != NULL) {
			write(1, arr[a], mx_strlen(arr[a]));
			if (arr[a + 1] != NULL)
				write(1, delim, mx_strlen(delim));
				a++;
		}
	}
	write(1, delim, 1);
	// write(1, "\n", 1);
}
