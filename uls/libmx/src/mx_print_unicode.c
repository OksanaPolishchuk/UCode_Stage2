#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    int dc[5] = {0};
    int index = 0;

    c < 128 ? write(1, &c, 1) : c;
    if (c >= 128 && c <= 1112064) {
        c >= 2048 ? c >= 65536 ? (index = 3, dc[0] = 240)
                               : (index = 2, dc[0] = 224)
                               : (index = 1, dc[0] = 192);
        for (int i = 1; i < index + 1; dc[i++] = 128);
        for (int i = 0; c != 0; c /= 2) {
            i == 6 ? (i = 0, --index) : i;
            dc[index] += c % 2 * mx_pow(2, (i++));
        }
        for (int i = 0; dc[i] != 0; i++)
            write(1, &dc[i], 1);
    }
}
