#include <iostream>

const int MAX_V = 100; // Maximum vertices
int adj[MAX_V][MAX_V]; // 2D adjacency list
int degree[MAX_V]; // Degree of each vertex
bool visited[MAX_V]; // Visited vertices for DFS

void addEdge(int u, int v) {
    adj[u][degree[u]++] = v;
    adj[v][degree[v]++] = u;
}

void removeEdge(int u, int v) {
    for (int i = 0; i < degree[u]; i++)
        if (adj[u][i] == v) {
            for (int j = i; j < degree[u] - 1; j++)
                adj[u][j] = adj[u][j + 1];
            degree[u]--;
            break;
        }
    for (int i = 0; i < degree[v]; i++)
        if (adj[v][i] == u) {
            for (int j = i; j < degree[v] - 1; j++)
                adj[v][j] = adj[v][j + 1];
            degree[v]--;
            break;
        }
}

int dfsCount(int v, int V) {
    visited[v] = true;
    int count = 1; // Current vertex is also counted
    for (int i = 0; i < degree[v]; i++) {
        int adjV = adj[v][i];
        if (!visited[adjV])
            count += dfsCount(adjV, V);
    }
    return count;
}

bool isValidNextEdge(int u, int v, int V) {
    int count1 = dfsCount(u, V); // Count reachable vertices from u

    removeEdge(u, v); // Remove edge u-v
    std::fill(visited, visited + V, false);
    int count2 = dfsCount(u, V); // Count reachable vertices from u after removing edge

    addEdge(u, v); // Add edge u-v back

    return (count1 == count2); // Edge is valid if removing doesn't increase number of connected components
}

void fleury(int u, int V) {
    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (isValidNextEdge(u, v, V)) {
            std::cout << u << "-" << v << " ";
            removeEdge(u, v);
            fleury(v, V);
            break; // Exit the loop after one valid edge is used
        }
    }
}

int main() {
    int V = 3;
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);

    std::cout << "Fleury's starting at vertex 0: ";
    fleury(0, V);
    std::cout << std::endl;
    return 0;
}
