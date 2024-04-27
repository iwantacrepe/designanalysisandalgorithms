#include <iostream>

int main() {
    int job[] = {1, 2, 3, 4, 5, 6};
    int seq[] = {0, 0, 0, 0, 0, 0};
    int profit[] = {15, 10, 12, 20, 8, 5};
    int deadline[] = {5, 3, 3, 2, 4, 2};
    int n = sizeof(seq) / sizeof(seq[0]);
    int i, j, t, sum = 0;

    // Bubble sort by profit in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (profit[j] < profit[j + 1]) {
                t = profit[j + 1];
                profit[j + 1] = profit[j];
                profit[j] = t;

                t = deadline[j + 1];
                deadline[j + 1] = deadline[j];
                deadline[j] = t;

                t = job[j + 1];
                job[j + 1] = job[j];
                job[j] = t;
            }
        }
    }

    // Schedule jobs to maximize profit
    for (i = 0; i < n; i++) {
        j = deadline[i] - 1; // Adjust index for 0-based array
        while (j >= 0 && seq[j] != 0) {
            j--;
        }
        if (j >= 0) {
            seq[j] = job[i];
        }
    }

    // Calculate the total profit for the scheduled jobs
    for (i = 0; i < n; i++) {
        if (seq[i] != 0) {
            for (j = 0; j < n; j++) {
                if (job[j] == seq[i]) {
                    sum += profit[j];
                    std::cout << seq[i] << "\t";
                    break;
                }
            }
        }
    }

    std::cout << "\nTotal profit is " << sum << std::endl;
    return 0;
}
