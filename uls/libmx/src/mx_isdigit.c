#include "libmx.h"

bool mx_isdigit(int c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
