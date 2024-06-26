#include <iostream>

int main() {
    int job[] = {1, 2, 3, 4, 5, 6};
    int seq[] = {0, 0, 0, 0, 0};
    int profit[] = {15, 10, 12, 20, 8, 5};
    int deadline[] = {5, 3, 3, 2, 4, 2};
    int n = sizeof(seq) / sizeof(seq[0]);
    int i, j, t, sum = 0;

  
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

   
    for (i = 0; i < n; i++) {
        j = deadline[i] - 1; 
        while (j >= 0 && seq[j] != 0) {
            j--;
        }
        if (j >= 0) {
            seq[j] = job[i];
            sum += profit[i];  
            std::cout << job[i] << "\t";  
        }
    }

    std::cout << "\nTotal profit is " << sum << std::endl;
    return 0;
}
