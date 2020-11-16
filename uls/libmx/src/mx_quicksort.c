#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	int i = left;
	int j = right;
	int pivot = (left + right) / 2;
	int num_swap = 0;

	if (arr == NULL)
		return -1;

	while (i <= j) {
		while (mx_strlen(arr[i]) < mx_strlen(arr[pivot]))
			i++;
		while (mx_strlen(arr[j]) > mx_strlen(arr[pivot]))
			j--;
		if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j])) {
			char *temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			num_swap++;
		}
		i++;
		j--;
		if (left < j)
			num_swap += mx_quicksort(arr, left, j);
		if (i < right)
			num_swap += mx_quicksort(arr, i, right);
	}
	return num_swap;
}
