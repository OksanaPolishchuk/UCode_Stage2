#include "libmx.h"

static int mx_s_strlen(const char *s) {
    int i = 0;

    if (s)
        while (s[i] != '\0')
            i++;
    return i;
}

char *mx_strndup(const char *s1, size_t n) {
	char *result = NULL;
	size_t size = (unsigned int) mx_s_strlen(s1);

	if (size < n)
		result = mx_strdup(s1);
	else {
		result = mx_strnew(n);
		result = mx_strncpy(result, s1, n);
	}
	return result;
}
