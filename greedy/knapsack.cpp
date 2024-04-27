#include <iostream>
using namespace std;

int main() {
    int kw = 25;             // Total knapsack weight capacity
    int n = 5;               // Number of items
    int p[] = {1, 2, 3, 4, 5};  // Array of item profits
    int w[] = {5, 6, 7, 3, 5};  // Array of item weights
    float r[n];                // Array to store ratio of profit to weight

    // Calculate the profit to weight ratio for each item
    for (int i = 0; i < n; i++) {
        r[i] = (float)p[i] / w[i];
    }

    // Bubble sort to order items by decreasing profit/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (r[j] < r[j + 1]) {
                // Swap ratio
                float temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;

                // Swap profit
                int tempInt = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempInt;

                // Swap weight
                tempInt = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempInt;
            }
        }
    }

    // Calculate maximum profit within knapsack constraints
    int P = 0;  // Initialize total profit
    for (int i = 0; i < n; i++) {
        if (kw > 0 && w[i] <= kw) {
            P += p[i];
            kw -= w[i];
        } else {
            P += (p[i] * kw) / w[i];
            break;  // Knapsack is full
        }
    }

    // Output the total profit
    cout << P << endl;

    return 0;
}
