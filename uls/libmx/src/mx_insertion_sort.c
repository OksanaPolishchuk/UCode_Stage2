int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    char *tmp;
    int count = 0;
    int k;

    for (int i = 1; i < size; i++) {
        k = i;
        while (k > 0 && (mx_strlen(arr[k-1]) > mx_strlen(arr[k]))) {
            tmp = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = tmp;
            count++;
            k--;
        }
    }
    return count;
}
