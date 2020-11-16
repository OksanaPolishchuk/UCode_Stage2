#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	unsigned long num = 0;
	unsigned long digit = 1;
	int len = mx_strlen(hex);

	for (int i = len - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9')
			num += (hex[i] - 48) * digit;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			num += (hex[i] - 87) * digit;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			num += (hex[i] - 55) * digit;
		digit *= 16;
	}
	return num;
}
