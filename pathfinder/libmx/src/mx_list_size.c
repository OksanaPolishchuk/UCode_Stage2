#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *tmp = NULL;
    int i = 0;

    if (list == NULL)
        return i;
    else
        tmp = list;
        while (tmp != NULL) {
            i++;
            tmp = tmp->next;
        }
    return i;
}
