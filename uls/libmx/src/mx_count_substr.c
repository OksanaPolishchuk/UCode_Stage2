#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count_substr = 0;
    int sub_len = 0;
    if (str == NULL || sub == NULL)
        return -1;
    if (mx_strlen(sub) <= 0)
        return 0;
    sub_len = mx_strlen(sub);
    for (int i = 0; str[i]; i++) {
    	// if (str[i] == str[0]) {
    	// 	if (mx_strncmp(str + i, sub, sub_len) == 0) {
        if (mx_strstr(str + i, sub) == str + i) {
            count_substr++;
            //to start after first matching
            i += sub_len - 1;
        }
    }
    return count_substr;
}
