#include <iostream>

// Assuming a fixed maximum size for simplicity
const int MAX_V = 20;

bool hamCycleUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V);
bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos);
void printSolution(int path[], int V);

// Function to check for a Hamiltonian cycle
bool hamCycle(bool graph[MAX_V][MAX_V], int V) {
    int path[MAX_V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;  // Start from vertex 0

    if (!hamCycleUtil(graph, path, 1, V)) {
        std::cout << "\nSolution does not exist";
        return false;
    }
    printSolution(path, V);
    return true;
}

// Utility function to solve the Hamiltonian cycle problem
bool hamCycleUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V) {
    if (pos == V) {
        // Check if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos-1]][path[0]]) {
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, V))
                return true;
            path[pos] = -1;  // Backtrack
        }
    }
    return false;
}

// Function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex and is not already in the path
    if (!graph[path[pos-1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Function to print the solution
void printSolution(int path[], int V) {
    std::cout << "Solution Exists: Following is one Hamiltonian Cycle" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << path[i] << " ";
    std::cout << path[0] << std::endl;  // Print the first vertex again to show the complete cycle
}

int main() {
    // Example graph represented using adjacency matrix
    bool graph[MAX_V][MAX_V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int V = 5; // Number of vertices

    hamCycle(graph, V);

    return 0;
}
