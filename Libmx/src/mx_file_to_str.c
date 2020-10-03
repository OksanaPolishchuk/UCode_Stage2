#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int open_file = open(file, O_RDONLY);
    int len = 0;
    char buf;
    char *str;

    if (open_file > 0) {
        while ((read(open_file, &buf, 1)))
            len++;
        close(open_file);
        if (len > 0) {
            open_file = open(file, O_RDONLY);
            str = mx_strnew(len);
            for (int i = 0; read(open_file, &buf, 1); i++)
                str[i] = buf;
            close(open_file);
            return str;
        }
    }
    return NULL;
}
