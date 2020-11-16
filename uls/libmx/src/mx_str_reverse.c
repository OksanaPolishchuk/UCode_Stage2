#include "libmx.h"

void mx_str_reverse(char *s) {
	int length = 0;
	int half = 0;

	if (!s)
		return;
	length = mx_strlen(s) - 1;
	half = length / 2;
	for (int i = 0; i <= half; length--) {
		mx_swap_char(&s[length], &s[i]);
		i++;
	}
}
