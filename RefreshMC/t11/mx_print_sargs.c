#include <stdlib.h>

void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
    char *temp = NULL;
    
    if (argc > 0) { 
        for (int i = 1; i < argc; i++) {
            for (int j = i + 1; j < argc; j++) {
                if (mx_strcmp(argv[i], argv[j]) > 0) {
                    temp = argv[i];
                    argv[i] = argv[j];
                    argv[j] = temp;
                }
            }
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    return 0;
    }
}
