#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *clone = NULL;

	if (!head || !*head)
		return;
	if ((*head)->next == NULL) {
		(*head)->data = NULL;
		free(*head);
		*head = NULL;
	}
	else {
		clone = *head;
		while (clone && clone->next->next != NULL) {
			clone = clone->next;
		}
		clone->next->data = NULL;
		free(clone->next);
		clone->next = NULL;
	}
}
