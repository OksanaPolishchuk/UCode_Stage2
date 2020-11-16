#include "libmx.h"

void mx_printint(int n) {
	long num = n;
	if (num < 0) {
		mx_printchar('-');
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		mx_printchar(num + 48);
	else if (num > 9) {
		mx_printint(num / 10);
		mx_printchar(num % 10 + 48);
	}
}
