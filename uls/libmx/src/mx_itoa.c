#include "libmx.h"

char *mx_itoa(int number) {
    int length = 0;
    char *result = NULL;

    if (number == -2147483648) {
        result = (char *) malloc(sizeof(char) * 12);
        mx_strcpy(result, "-2147483648");
        return result;
    }
    //assigning 0 value and the end of string
    if (number == 0) {
        result = (char *) malloc(sizeof(char) * 2);
        mx_strcpy(result, "0");
        return result;
    }
    length = mx_nbr_length(number);
    result = (char *) malloc(sizeof(char) * length + 2);
    if (number < 0) {
        result[0] = '-';
        number *= -1;
        length++;
    }
    result[length] = '\0';
    while (number) {
        result[--length] = (char)((number % 10) + 48);
        number /= 10;
    }
    return result;
}
