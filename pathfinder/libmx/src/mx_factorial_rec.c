int mx_factorial_rec(int n) {
    if (n < 0 || n > 12) 
        return 0;
    return (n == 0) ? 1 : (n * mx_factorial_rec(n - 1));
}
