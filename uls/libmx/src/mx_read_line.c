#include "libmx.h"

static void *mx_realloc2(void *ptr, size_t size) {
    char *new = mx_strnew(size);
    char *p = (char *)ptr;

    if (new == NULL)
        return NULL;
    if (ptr == NULL)
        return new;
    for (unsigned int i = 0; i < size; i++)
        new[i] = p[i];
    free(ptr);
    return new;
}

static void mx_free(char **lineptr, char *buf, int *count, int chars) {
    chars == 0 && (*count) == 0 ? (*count)-- : (*count);
    mx_strdel(&buf);
    if (*lineptr == NULL && (*count) < 1) {
        *lineptr = malloc(1);
        *lineptr[0] = '\0';
    }
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    char *buf = mx_strnew(1);
    int count = 0;
    int chars;

    fd < 0 ? (count = -2) : count;
    for ( ; (chars = read(fd, buf, (buf_size / buf_size))) > 0; ) {
        if (*buf == delim)
            break;
        *lineptr = mx_realloc2(*lineptr,
                            mx_s_strlen(*lineptr) + mx_s_strlen(buf));
        *lineptr = mx_strcat(*lineptr, buf);
        count++;
    }
    mx_free(&(*lineptr), buf, &count, chars);
    return count;
}


