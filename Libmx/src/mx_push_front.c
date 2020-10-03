#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);

    if (*list == NULL) {
        *list = front;
        return;
    }
    front->next = *list;
    *list = front;
}
