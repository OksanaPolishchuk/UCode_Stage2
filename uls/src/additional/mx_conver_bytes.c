#include "uls.h"

static char *convert(int size, char *type, int n);
static char *convert_float(int size, char *type, int n);

char *mx_convert_bytes(int size) {
    char *result = NULL;
    if (size < 0 || size > 2147483647) {
        return NULL;
    }
    if (size == 0) {
        result = mx_strnew(2);
        result = mx_strcpy(result, "0B");
        return result;
    }

    else if (size > 0 && size <= 1024) {
        result = convert(size, "B", 1);
    }
    else if (size > 1024 && size <= 1048576) {
        if (size < 10240)
            result = convert_float(size, "K", 1024);
        else
            result = convert(size, "K", 1024);
    }
    else if (size > 1048576 && size <= 1073741824) {
        result = convert(size, "M", 1048576);
    }
    else {
        result = convert(size, "G", 1073741824);
    }
    return result;
}

static char *convert(int size, char *type, int n) {
    char *result;
    char *temp;
    size /= n;
    result = mx_strnew(mx_intlen(size) + 1);
    temp = mx_itoa(size);
    result = mx_strcpy(result, temp);
    result = mx_strcat(result, type);
    mx_strdel(&temp);
    return result;
}

static char *convert_float(int size, char *type, int n) {
    char *result = NULL;
    char *temp;
    float f_size;
    f_size = (float)size / (float)n;
    size /= n;
    result = mx_strnew(mx_intlen(size) + 3);
    ftoa(f_size, result, 1);
    result = mx_strcat(result, type);
    return result;
}
