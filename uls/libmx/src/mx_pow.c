#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
	double result = 1;
	
	if (pow == 0)
		return 1;
	while (pow > 0) {
		result *= n;
		--pow;
	}
	return result;
}
