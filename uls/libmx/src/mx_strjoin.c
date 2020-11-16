#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {;
	if (s1 == NULL && s2 != NULL) {
		char *c_s2 = mx_strdup(s2);
			return c_s2;
	}
	if (s1 != NULL && s2 == NULL) {
		char *c_s1 = mx_strdup(s1);
			return c_s1;
	}
	if (s1 != NULL && s2 != NULL) {
		char *c_s1 = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		c_s1 = mx_strcpy(c_s1, s1);
		c_s1 = mx_strcat(c_s1, s2);
		return c_s1;
	}
	return NULL;
}
