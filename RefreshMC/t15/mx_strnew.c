#include <stdlib.h>

char *mx_strnew(const int size) {
    char *new = NULL;

    if (size < 0)
        return NULL;
    new = (char *)malloc(sizeof(char) * (size + 1));
    for (int i = 0; i <= size; i++)
        new[i] = '\0';
    return new;    
}
