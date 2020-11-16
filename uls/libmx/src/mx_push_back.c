#include "libmx.h"

void mx_push_back(t_list **list, void *data){
	t_list *new_tmp;
	t_list *current = *list;
	new_tmp = mx_create_node(data);
	if (current == NULL) {
		*list = new_tmp;
	}
	else {
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = new_tmp;
	}
}
