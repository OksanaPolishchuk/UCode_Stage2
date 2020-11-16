#include "uls.h"

void mx_clean_struct_result(t_result *result_of_work_i) {
    for (int j = 0; j < result_of_work_i->length; j++) {
        if (result_of_work_i->result[j])
            mx_strdel(&result_of_work_i->result[j]);
        if (result_of_work_i->result)
            free(result_of_work_i->result);
        if (result_of_work_i)
            free(result_of_work_i);
    }
}
