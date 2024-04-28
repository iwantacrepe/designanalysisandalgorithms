#include <iostream>

const int MAX_V = 100; // Maximum number of vertices
int adj[MAX_V][MAX_V]; // Adjacency matrix
int degree[MAX_V]; // Degree of each vertex
bool visited[MAX_V][MAX_V]; // To check if an edge has been used

// Function to add an edge
void addEdge(int u, int v) {
    adj[u][degree[u]++] = v;
    adj[v][degree[v]++] = u;
}

void hierholzer(int V) {
    int curr_path[MAX_V], path_index = 0;
    int path[MAX_V], path_len = 0;

    curr_path[path_index++] = 0; // Start from vertex 0

    while (path_index) {
        int curr_v = curr_path[path_index - 1];
        if (degree[curr_v]) {
            // Find the next vertex using an edge that hasn't been used
            for (int i = 0; i < degree[curr_v]; i++) {
                int next_v = adj[curr_v][i];
                if (!visited[curr_v][next_v]) {
                    visited[curr_v][next_v] = visited[next_v][curr_v] = true; // Mark edge as used
                    curr_path[path_index++] = next_v;
                    break;
                }
            }
        } else {
            // No more adjacent vertices, add to path
            path[path_len++] = curr_v;
            --path_index; // Pop from stack
        }
    }

    for (int i = path_len - 1; i >= 0; i--) // Print path in reverse
        std::cout << path[i] << " -> ";
    std::cout << "DONE" << std::endl;
}

int main() {
    int V = 3; // Number of vertices
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);

    hierholzer(V);
    return 0;
}
