void mx_sort_arr_int(int *arr, int size) {
    int temp;
    
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
