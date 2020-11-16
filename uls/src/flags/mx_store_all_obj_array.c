#include "uls.h"

char **mx_store_all_obj_array(t_flags *flags) {
    int k = 0;
    flags->num_dir_file = 0;
    flags->all_obj = (char **)malloc(sizeof(char *) * 1000);

    for (int i = 1; flags->argv[i]; i++, k++) {
        flags->all_obj[k] = mx_strdup(flags->argv[i]);
        flags->num_dir_file++;
    }
    return flags->all_obj;
}
