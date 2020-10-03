#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char byte;
    int counter = 0;
    int bit_and = 0;
    int bit_or = 0;

    c <= 127 ? write(1, &c, 1) : c;
    if (c > 127) {
        c >= 2048 ? c >= 65536 ? (counter = 3, bit_and = 7, bit_or = 240)
                                : (counter = 2, bit_and = 15, bit_or = 224)
                                : (counter = 1, bit_and = 31, bit_or = 192);
        for ( int i = counter; i >= 0; i--) {
            if (i == counter)
                byte = (c >> (6 * i) & bit_and) | bit_or;
            else
                byte = (c >> (6 * i ) & 63) | 128;
            write(1, &byte, 1);
        }
    }
}
