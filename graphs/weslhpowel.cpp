#include <iostream>
#include <algorithm>

using namespace std;

// Assume a maximum number of vertices
const int MAX_V = 100;

// Function to find the chromatic number of a graph using the Welsh-Powell algorithm
int welshPowell(int graph[MAX_V][MAX_V], int V) {
    int result[MAX_V];
    bool available[MAX_V];

    // Initialize all vertices as unassigned
    for (int i = 0; i < V; i++)
        result[i] = -1;

    // Assign the first color to the first vertex
    result[0] = 0;

    // Initialize all colors as available
    for (int i = 0; i < V; i++)
        available[i] = false;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Process all adjacent vertices and flag their colors as unavailable
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && result[i] != -1)
                available[result[i]] = true;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (!available[cr])
                break;
        }

        result[u] = cr; // Assign the found color

        // Reset the values back to false for the next iteration
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && result[i] != -1)
                available[result[i]] = false;
        }
    }

    // Print the result
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;

    // Return the number of colors used
    return *max_element(result, result + V) + 1;
}

int main() {
    // Example: Graph in adjacency matrix form
    int graph[MAX_V][MAX_V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    int V = 5; // Number of vertices

    int numColors = welshPowell(graph, V);
    cout << "Number of colors used: " << numColors << endl;

    return 0;
}
