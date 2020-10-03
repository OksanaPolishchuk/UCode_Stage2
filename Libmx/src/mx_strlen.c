int mx_strlen(const char *s) {
    int a = 0;
    
    while (s[a] != '\0')
        a++;
    return a;
}
