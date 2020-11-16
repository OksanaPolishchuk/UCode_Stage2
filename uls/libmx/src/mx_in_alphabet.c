#include "libmx.h"

bool mx_in_alphabet(char a) {
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
        return true;
    return false;
}

