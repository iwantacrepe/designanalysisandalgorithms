#include <iostream>
#include <stack>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h) {
    std::stack<int> stack;
    stack.push(l);
    stack.push(h);

    while (!stack.empty()) {
        h = stack.top();
        stack.pop();
        l = stack.top();
        stack.pop();

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stack.push(l);
            stack.push(p - 1);
        }
        if (p + 1 < h) {
            stack.push(p + 1);
            stack.push(h);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
