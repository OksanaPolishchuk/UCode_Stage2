#include "libmx.h"

bool mx_isspace(char c) {
    if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13) {
        return true;
    }
    else {
        return false;
    }
}

//int main() {
//    printf("%d\n",mx_isspace('\n'));
//}

