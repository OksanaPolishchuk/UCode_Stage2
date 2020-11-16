#include "libmx.h"

int mx_sqrt(int x) {

	if (x == 1)
		return 1;
	if (x < 0)
		return 0;
	for (int i = 0; i < 46341; i++) {
		if (i * i == x)
			return i;
	}
	return 0;
}
