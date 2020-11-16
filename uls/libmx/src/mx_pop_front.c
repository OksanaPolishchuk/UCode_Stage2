#include "libmx.h"

void mx_pop_front(t_list **head) {
	t_list *clone = NULL;

	if (!head || !*head)
		return;
	if ((*head)->next == NULL) {
		(*head)->data = NULL;
		free(*head);
		*head = NULL;
	}
	else {
		clone = (*head)->next;
		(*head)->data = NULL;
		free(*head);
		*head = clone;
	}
}
