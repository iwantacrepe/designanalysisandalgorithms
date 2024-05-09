#include <iostream>

int main() {
    int denominations[] = {100, 50, 20, 10, 5, 2, 1};  
    int n = sizeof(denominations) / sizeof(denominations[0]);
    int amount;
    std::cin >> amount; 
    
    int coins[7] = {0};  
    
    for(int i = 0; i < n; i++) {
        while(amount >= denominations[i]) {
            amount -= denominations[i];
            coins[i]++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(coins[i] > 0) {
            std::cout << denominations[i] << " x " << coins[i] << "\n";
        }
    }
    
    return 0;
}
