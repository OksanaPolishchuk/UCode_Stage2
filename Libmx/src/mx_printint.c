#include "libmx.h"

void mx_printint(int n) {
    if (n == INT_MIN) {
    	write(1, "-2147483648", 11);
    	return;
    }
    if (n< 0) {
    	mx_printchar('-');
    	n *= -1;
    }
    if (n > 9)
    	mx_printint(n /10);
    mx_printchar(n % 10 + 48);
}
