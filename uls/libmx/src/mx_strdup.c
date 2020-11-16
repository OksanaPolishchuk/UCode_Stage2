#include "libmx.h"

char *mx_strdup(const char *str) {
	int n = 0;
	char *str2 = NULL;

	if (!str)
		return NULL;
	n = mx_strlen(str);
	str2 = mx_strnew(n);
	mx_strcpy(str2, str);
	return str2;
}
