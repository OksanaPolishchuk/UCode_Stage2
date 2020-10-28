int mx_s_strlen(const char *s) {
    int i = 0;

    if (s)
        while (s[i] != '\0')
            i++;
    return i;
}
