#include "uls.h"

void mx_struct_sort(t_lattrib **lattrib, t_flags *flags) {
    t_lattrib *temp = NULL;
    for (int k = 0; k < flags->count_obj; k++)
        for (int h = 0; h < (flags->count_obj - k - 1); h++)
            if (mx_strcmp(lattrib[h]->name, lattrib[h + 1]->name) > 0) {
                temp = lattrib[h + 1];
                lattrib[h + 1] = lattrib[h];
                lattrib[h] = temp;
            }
}
