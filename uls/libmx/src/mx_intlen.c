#include "libmx.h"

int mx_intlen(int n) {
    int len_number = 1;
    
    while(n /= 10)
        len_number++;
    return len_number;
}
