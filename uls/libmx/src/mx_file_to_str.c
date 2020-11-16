#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int any_file;
    int file_length = 0;
    int i = 0;
    char buffer[1];
    char *target_str;

    if (file == NULL)
    	return NULL;
    any_file = open(file, O_RDONLY);
    if (any_file < 0)
        return NULL;
    while(read(any_file, buffer, 1))
    	file_length++;
    	if (close(any_file) < 0)
    		return NULL;
    	target_str = mx_strnew(file_length);
    	if (target_str == NULL)
    		return NULL;
    	any_file = open(file, O_RDONLY);
    	if (any_file < 0)
    		return NULL;
    while(read(any_file, buffer, 1)) {
        target_str[i] = buffer[0];
        i++;
    }
    target_str[i] = '\0';
    if (close(any_file) < 0) return NULL;
    	return target_str;
}
