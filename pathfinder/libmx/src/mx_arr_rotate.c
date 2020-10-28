void mx_arr_rotate(int *arr, int size, int shift) {
    int tmp;
    int n_shift = shift % size;

    if (n_shift < 0)
        n_shift = n_shift + size;
    for (int i = 0; i < n_shift; i++) {
        tmp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = tmp;
    }
}
