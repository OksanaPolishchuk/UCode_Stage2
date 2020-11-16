#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int mid;
	int start = 0;
	int end = size - 1;

	if (!arr || !s)
		return -1;
	(*count) = 0;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (mx_strcmp(arr[mid], s) < 0) {
			start = mid + 1;
			(*count)++;
		}
		else if (mx_strcmp(arr[mid], s) > 0) {
			end = mid - 1;
			(*count)++;
		}
		else {
			(*count)++;
			return mid;
		}
	}
	(*count) = 0;
	return -1;
}
