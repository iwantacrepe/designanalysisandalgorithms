#include <iostream>
#include <climits>

int maxSubArray(int arr[], int n) {
    int max_so_far = arr[0], max_ending_here = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = std::max(arr[i], max_ending_here + arr[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Maximum contiguous sum (iterative) is " << maxSubArray(arr, n) << std::endl;
    return 0;
}
