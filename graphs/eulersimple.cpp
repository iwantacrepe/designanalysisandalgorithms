#include <iostream>

const int MAX_V = 100;  // Maximum number of vertices
int adj[MAX_V][MAX_V];  // Adjacency list represented as a 2D array
int degree[MAX_V];      // Degree of each vertex

// Function to add an edge to graph
void addEdge(int v, int w) {
    adj[v][degree[v]++] = w;
    adj[w][degree[w]++] = v;  // Since the graph is undirected
}

// Utility function for DFS to check connectivity
void DFSUtil(int v, bool visited[], int V) {
    visited[v] = true;
    for (int i = 0; i < degree[v]; ++i) {
        int adjV = adj[v][i];
        if (!visited[adjV]) {
            DFSUtil(adjV, visited, V);
        }
    }
}

// Function to check if all non-zero degree vertices are connected
bool isConnected(int V) {
    bool visited[MAX_V] = {false};
    int i;

    // Find a vertex with non-zero degree
    for (i = 0; i < V; i++) {
        if (degree[i] > 0)
            break;
    }

    // If no edges are present, return true
    if (i == V)
        return true;

    DFSUtil(i, visited, V);

    for (i = 0; i < V; i++) {
        if (!visited[i] && degree[i] > 0)
            return false;
    }

    return true;
}

// Function to check if the graph is Eulerian
int isEulerian(int V) {
    if (!isConnected(V))
        return 0;

    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (degree[i] & 1)
            odd++;
    }

    if (odd > 2)
        return 0;
    else if (odd == 2)
        return 1;
    else
        return 2;
}

// Function to test different configurations
void test(int V) {
    int res = isEulerian(V);
    if (res == 0)
        std::cout << "graph is not Eulerian\n";
    else if (res == 1)
        std::cout << "graph has a Euler path\n";
    else
        std::cout << "graph has a Euler cycle\n";
}

int main() {
    // Example configurations for different types of Eulerian paths/cycles
    int V = 5;
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    test(V);

    // Resetting for a new graph test
    std::fill_n(degree, V, 0);  // Reset degrees
    test(V);  // Expect non-Eulerian since we reset the graph and didn't add edges again

    return 0;
}
