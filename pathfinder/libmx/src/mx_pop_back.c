#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *tmp = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        tmp = *head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
    }
}
