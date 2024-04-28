#include <iostream>

const int V = 6;  // Number of vertices in the graph
const int MAX_EDGES = 5;  // Maximum number of edges from any vertex

void dfs(int v, bool visited[], int stack[], int &stackIndex, int graph[V][MAX_EDGES], int numEdges[V]) {
    visited[v] = true;  // Mark the current node as visited

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < numEdges[v]; i++) {
        int adj = graph[v][i];
        if (!visited[adj]) {
            dfs(adj, visited, stack, stackIndex, graph, numEdges);
        }
    }

    // Push current vertex to stack which stores the result
    stack[stackIndex++] = v;
}

void topologicalSort(int graph[V][MAX_EDGES], int numEdges[V]) {
    bool visited[V] = {false};  // Mark all the vertices as not visited
    int stack[V];  // To store the topological order
    int stackIndex = 0;  // Index for stack array

    // Call the recursive helper function to store Topological Sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, stack, stackIndex, graph, numEdges);
        }
    }

    // Print contents of the stack
    while (stackIndex) {
        std::cout << stack[--stackIndex] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int graph[V][MAX_EDGES] = {{}, {}, {}, {}, {}, {}};
    int numEdges[V] = {0};

    // Example edges (as an adjacency list but using a 2D array)
    graph[5][numEdges[5]++] = 2;
    graph[5][numEdges[5]++] = 0;
    graph[4][numEdges[4]++] = 0;
    graph[4][numEdges[4]++] = 1;
    graph[2][numEdges[2]++] = 3;
    graph[3][numEdges[3]++] = 1;

    // Call topological sort
    topologicalSort(graph, numEdges);

    return 0;
}
