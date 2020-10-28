#include "libmx.h"

void mx_str_reverse(char *s) {
    int j = s ? mx_strlen(s) - 1 : 0;
    
    if (s)
        for (int i = 0; i < j; )
            mx_swap_char(&s[i++],&s[j--]);
}
