#include <iostream>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int n) {
    int curr_size;
    int left_start;
    
    for (curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size) {
        for (left_start = 0; left_start < n-1; left_start += 2*curr_size) {
            int mid = std::min(left_start + curr_size - 1, n-1);
            int right_end = std::min(left_start + 2*curr_size - 1, n-1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, arr_size);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    return 0;
}
