#include <iostream>
#include <algorithm> // For std::next_permutation

// Function to print the permutation which represents a Hamiltonian path
void print_permutation(int p[], int n) {
    std::cout << "Hamiltonian path: ";
    for (int i = 0; i <= n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

// Function to check all permutations for Hamiltonian path
bool check_all_permutations(bool adj[][10], int n) {
    int p[10]; // Array to store the current permutation of vertices

    // Initialize p[] such that p[i] = i for i from 0 to n
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    // Check each permutation
    do {
        bool valid = true;

        // Check if current permutation is a valid path
        for (int i = 0; i < n; i++) {
            if (!adj[p[i]][p[i+1]]) {
                valid = false;
                break;
            }
        }

        // If valid, print and return true
        if (valid) {
            print_permutation(p, n);
            return true;
        }
    } while (std::next_permutation(p, p + n + 1)); // Generate the next permutation

    return false; // Return false if no valid Hamiltonian path found
}

int main() {
    // Example of an adjacency matrix for a graph with 4 vertices
    bool adj[10][10] = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };
    int n = 3; // Index of the last vertex (0-based index)

    // Function call
    if (!check_all_permutations(adj, n)) {
        std::cout << "No Hamiltonian path exists." << std::endl;
    }

    return 0;
}
