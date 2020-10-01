int mx_factorial_iter(int n) {
    int result = 1;

    if (n < 0 || n > 12)
        return 0;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}
