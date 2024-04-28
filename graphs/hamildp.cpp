#include <iostream>
#include <cstring> // For memset

const int N = 5; // Define the number of vertices

// Function to check whether there exists a Hamiltonian Path or not
bool Hamiltonian_path(int adj[N][N], int N) {
    int dp[N][1 << N]; // dp array

    // Initialize the dp table
    memset(dp, 0, sizeof(dp));

    // Set all dp[i][(1 << i)] to true
    for (int i = 0; i < N; i++) {
        dp[i][(1 << i)] = 1;
    }

    // Iterate over each subset of nodes
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            // If the jth node is included in the current subset
            if (i & (1 << j)) {
                // Find K, neighbour of j also present in the current subset
                for (int k = 0; k < N; k++) {
                    if ((i & (1 << k)) && adj[k][j] && j != k && dp[k][i ^ (1 << j)]) {
                        // Update dp[j][i] to true
                        dp[j][i] = 1;
                        break;
                    }
                }
            }
        }
    }

    // Check the vertices for a Hamiltonian Path
    for (int i = 0; i < N; i++) {
        if (dp[i][(1 << N) - 1]) {
            return true;
        }
    }

    return false;
}

// Driver Code
int main() {
    // Input adjacency matrix
    int adj[N][N] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0} // Additional row for the complete adjacency matrix
    };

    // Function call
    if (Hamiltonian_path(adj, N))
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
