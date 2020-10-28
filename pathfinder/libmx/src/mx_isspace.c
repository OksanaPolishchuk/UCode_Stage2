#include "libmx.h"

bool mx_isspace(char c) {
    return (( c > 8 && c < 14 ) || ( c == 32 )) ? 1 : 0;
}
