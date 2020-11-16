#include "libmx.h"

void mx_push_front(t_list **list, void *data) {

t_list *one_new_node = (t_list*)malloc(sizeof(t_list));

	one_new_node->data = data;
	one_new_node->next = (*list);
	(*list) = one_new_node;
}
