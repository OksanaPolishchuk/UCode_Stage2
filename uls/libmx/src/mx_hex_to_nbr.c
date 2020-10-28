unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;
    unsigned long base = 1;

    if (!hex)
        return 0;
    for (int i = 0; hex[i + 1]; i++)
        base *= 16;
    for (int i = 0; hex[i]; i++) {
        if (hex[i] >= '0' && hex[i] <= '9')
            nbr += (hex[i] - 48) * base;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            nbr += (hex[i] - 55) * base;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            nbr += (hex[i] - 87) * base;
        base /= 16;
    }
    return nbr;
}
