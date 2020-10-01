int mx_sqrt(int x) {
    int y = 1;

    while (y <= x / 2) {
        if (y * y == x) {
            return y;
        }
        y++;
    }
    return 0;
}
