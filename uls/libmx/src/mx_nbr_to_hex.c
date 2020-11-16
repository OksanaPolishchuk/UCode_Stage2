#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
        int rem;
        int i = 0, j = 0;
        unsigned long n_nbr = nbr;

        while (n_nbr > 0) {
                n_nbr /= 10;
                i++;
        }
        char *hex = mx_strnew(i);
        while (nbr != 0) {
                rem = nbr % 16;
                if (rem < 10)
                        hex[j++] = 48 + rem;
                if (rem > 10)
                        hex[j++] = 87 + rem;
                nbr /= 16;
        }
	j--;

        mx_str_reverse(hex);
        return hex;
}
