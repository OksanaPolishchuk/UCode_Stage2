#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *front_list = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        front_list = (*head)->next;
        free(*head);
        *head = front_list;
    }
}
