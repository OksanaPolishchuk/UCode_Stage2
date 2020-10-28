#include "libmx.h"

static void mx_str_in_array(char const *s, char c, char **new_arr) {
    int len_of_word = 0;
    int j = 0;
    int k = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c && len_of_word == 0)
            k = i;
        if (s[i] != c && s[i] != 0)
            len_of_word++;
        if (len_of_word > 0 && (s[i + 1] == c || s[i + 1] == 0)) {
            new_arr[j] = mx_strnew(len_of_word);
            new_arr[j] = mx_strncpy(new_arr[j], &(s[k]), len_of_word);
            len_of_word = 0;
            j++;
        }
    }
    new_arr[j] = NULL;
}

char **mx_strsplit(char const *s, char c) {
    char **new_arr = NULL;

    if (!s)
        return NULL;    
    new_arr = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    mx_str_in_array(s, c, new_arr);
    return new_arr;
}
