#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    for (t_list *i = lst; i->next != NULL; i = i->next) {
        for (t_list *j = lst; j->next != NULL; j = j->next) {
            if (cmp(j->data, j->next->data)) {
                void *temp = j->next->data;
                j->next->data = j->data;
                j->data = temp;
            }
        }
    }
    return lst;
}
