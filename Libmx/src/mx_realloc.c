#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t len = malloc_size(ptr);
    unsigned char *new_pointer = NULL;

    if ((int)size >= 0) {
        if (size != 0 && len > size)
            return ptr;
        new_pointer = malloc(size);
        if (size != 0 && ptr != NULL)
            new_pointer = mx_memcpy(new_pointer, ptr, size);
        free(ptr);
    }
    return new_pointer;
}
