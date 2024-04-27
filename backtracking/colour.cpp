#include <iostream>

const int V = 5;  // Number of vertices

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the m coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)  // Base case: If all vertices are assigned a color then return true
        return true;

    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is possible
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;  // If assigning color c doesn't lead to a solution then remove it
        }
    }

    return false;  // If no color can be assigned to this vertex then return false
}

// Function to print the solution
void printSolution(int color[]) {
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
        std::cout << "Node " << nodes[i] << " --->  Color " << color[i] << std::endl;
}

// Main function to solve the m Coloring problem using backtracking
void graphColoring(int graph[V][V], int m) {
    int color[V];  // Color array to store colors assigned to vertices
    for (int i = 0; i < V; i++) color[i] = 0;  // Initialize all vertices as unassigned

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, color, 0)) {
        std::cout << "Solution does not exist";
        return;
    }

    // Print the solution
    printSolution(color);
}

int main() {
    // Adjacency matrix for given graph
    int graph[V][V] = {
        {0, 1, 1, 0, 1},  // A -> B, C, E
        {1, 0, 1, 0, 1},  // B -> A, C, E
        {1, 1, 0, 1, 0},  // C -> A, B, D
        {0, 0, 1, 0, 1},  // D -> C, E
        {1, 1, 0, 1, 0}   // E -> A, B, D
    };

    int m = 3;  // Number of colors
    graphColoring(graph, m);
    return 0;
}
