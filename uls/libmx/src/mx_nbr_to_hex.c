#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex = NULL;
    int len = 0;
    unsigned long tmp; 

    if (nbr == 0) {
        hex = mx_strnew(1);
        hex[0] = '0';
        return hex;
    }
    for (tmp = nbr ; tmp != 0; len++)
        tmp /= 16;
    hex = mx_strnew(len);
    while (nbr) {
        tmp = nbr % 16;
        tmp < 10 ? (hex[--len] = 48 + tmp) : (hex[--len] = 87 + tmp);
        nbr /= 16;
    }
    return hex;
}
