double mx_pow(double n, unsigned int pow) {
    unsigned int i = 0;
    double result = 1;

    if (pow == 0)
        return 1;
    while (i < pow) {
        result *= n;
        i++;
    }
    return result;
}
