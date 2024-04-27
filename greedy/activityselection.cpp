#include <iostream>

int main() {
    int start[] = {1, 0, 1, 4, 2, 5, 3, 4};
    int finish[] = {3, 4, 2, 6, 9, 8, 5, 5};
    int activity[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int seq[8] = {0}; // Initialize the sequence array with zeros
    int n = sizeof(start) / sizeof(start[0]);
    int i, j;

    // Bubble sort activities based on their finish times
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                // Swap finish times
                int t = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = t;

                // Swap start times
                t = start[j];
                start[j] = start[j + 1];
                start[j + 1] = t;

                // Swap activity numbers
                t = activity[j];
                activity[j] = activity[j + 1];
                activity[j + 1] = t;
            }
        }
    }

    // Activity selection algorithm
    int k = 0;
    int f = finish[0];
    seq[k] = activity[0];
    k++;
    for (j = 1; j < n; j++) {
        if (start[j] >= f) {
            seq[k] = activity[j];
            k++;
            f = finish[j];
        }
    }

    // Output the selected activities
    for (i = 0; i < k; i++) {
        std::cout << seq[i] << "\t";
    }
    std::cout << std::endl; // Add newline at the end for better formatting

    return 0;
}
