#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *buff = lst;
    void *tmp;

    for (int i = mx_list_size(lst) - 1; i > 0; i--) {
        buff = lst;
        for (int j = 0; j < i; j++) {
            if (cmp(buff->data, buff->next->data)) {
                    tmp = buff->next->data;
                    buff->next->data = buff->data;
                    buff->data = tmp;
            }
            buff = buff->next;
        }
    }
    return lst;
}
