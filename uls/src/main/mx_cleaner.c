#include "uls.h"

void mx_cleaner(t_sorted_odj *sort, t_lattrib **lattrib) {
    for (int i = 0; i < sort->len_of_files_array; i++) {
        free(lattrib[i]->rights);
        free(lattrib[i]->lk_str);
        free(lattrib[i]->user);
        free(lattrib[i]->group);
        free(lattrib[i]->size_str);
        free(lattrib[i]->time);
        free(lattrib[i]->name);
        free(lattrib[i]->user_str);
        free(lattrib[i]->group_str);
        free(lattrib[i]);
    }
    free(lattrib);
}
