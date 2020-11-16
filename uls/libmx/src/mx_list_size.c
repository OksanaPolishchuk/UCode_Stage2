#include "libmx.h"

int mx_list_size(t_list *list) {
	t_list *calc = list;
	int count = 0;

	while (calc != NULL) {
		count++;
		calc = calc->next;
	}
	return count;
}
