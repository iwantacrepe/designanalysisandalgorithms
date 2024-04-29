#include <iostream>

const int MAX_SIZE = 100; // Maximum number of elements which can be handled

void printSubset(int x[], int n) {
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 1) {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}

void SumOfSubsets(int S, int k, int r, int w[], int x[], int M, int n) {
    x[k] = 1; // Include the k-th element
    if (S + w[k] == M) {
        printSubset(x, n); // Found a subset
    } else if (S + w[k] + w[k + 1] <= M) { // Try to include the next element
        SumOfSubsets(S + w[k], k + 1, r - w[k], w, x, M, n);
    }

    // Exclude the k-th element and find the right child
    if ((S + r - w[k] >= M) && (S + w[k + 1] <= M)) {
        x[k] = 0; // Exclude the k-th element
        SumOfSubsets(S, k + 1, r - w[k], w, x, M, n);
    }
}

int main() {
    int M = 10; // The target sum
    int w[] = {0, 1, 2, 3, 4, 5}; // Weight array, w[0] is dummy to make the indexing start from 1
    int n = sizeof(w)/sizeof(w[0]) - 1; // Number of elements in w
    int x[MAX_SIZE] = {0}; // Solution array
    int totalSum = 0; // Total sum of all elements

    for (int i = 1; i <= n; ++i) {
        totalSum += w[i];
    }

    // It is assumed that the first element is less than M and the total sum of all elements is greater or equal to M
    if (w[1] <= M && totalSum >= M) {
        SumOfSubsets(0, 1, totalSum, w, x, M, n);
    } else {
        std::cout << "No solution exists" << std::endl;
    }

    return 0;
}
