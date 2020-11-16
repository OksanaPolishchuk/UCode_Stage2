#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    unsigned char byte[4];
    int size = 0;

    if (c < 0x80) { // < 128
        byte[0] = ((c >> 0) & 0x7F) | 0x00;
        byte[1] = '\0';
        byte[2] = '\0';
        byte[3] = '\0';
        size = 1;
    }
    else if (c < 0x800) { // < 2047
        byte[0] = ((c >> 6) & 0x1F) | 0xC0;
        byte[1] = ((c >> 0) & 0x3F) | 0x80;
        byte[2] = '\0';
        byte[3] = '\0';
        size = 2;
    }
    else if (c < 0x10000) { // < 65535
        byte[0] = ((c >> 12) & 0x0F) | 0xE0;
        byte[1] = ((c >> 6) & 0x3F) | 0x80;
        byte[2] = ((c >> 0) & 0x3F) | 0x80;
        byte[3] = '\0';
        size = 3;
    }
    else if (c < 0x110000) { // < 1114111
        byte[0] = ((c >> 18) & 0x07) | 0xF0;
        byte[1] = ((c >> 12) & 0x3F) | 0x80;
        byte[2] = ((c >> 6) & 0x3F) | 0x80;
        byte[3] = ((c >> 0) & 0x3F) | 0x80;
        size = 4;
    }
    write(1, byte, size);
}
