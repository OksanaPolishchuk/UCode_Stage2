#include "libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int len = mx_strlen(s1);
    int i;
 
    for (i = 0; s2 && s2[i] != '\0'; i++)
        s1[len + i] = s2[i];
    s1[len + i] = '\0';
 
    return s1;
}
