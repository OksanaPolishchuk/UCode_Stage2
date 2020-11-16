#include "libmx.h"

char *mx_strchr(const char *s, int c) {
	while (*s) {
		if (*s == c)
			return (char *)s;
		else
			s++;
	}
	return 0;
}
