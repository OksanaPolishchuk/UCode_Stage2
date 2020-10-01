unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int i;

    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result = result * 16 + (hex[i] - 48);
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result = result * 16 +(hex[i] - 55);
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result = result * 16 + (hex[i] - 87);
        }
        else {
            return 0;
        }
    }
    return result;
}
