#include "libmx.h"

bool mx_isalpha(int c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                return true;
        else
                return false;
}
