#include <iostream>
#include <queue>

using namespace std;

const int V = 6;  // Number of vertices
const int MAX_EDGES = 5;  // Max edges per vertex

// Function to perform topological sort using Kahn's algorithm
void kahnTopologicalSort(int graph[V][MAX_EDGES], int numEdges[V]) {
    int in_degree[V] = {0};
    queue<int> q;

    // Compute in-degree (number of incoming edges) for each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < numEdges[i]; j++) {
            int v = graph[i][j];
            in_degree[v]++;
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;  // Count of vertices in topological order
    int topoSort[V];  // To store topological order

    // One by one dequeue vertices from queue and enqueue adjacents if in-degree of adjacent becomes 0
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoSort[cnt++] = u;

        // Iterate through all the neighbouring nodes of dequeued node u
        for (int i = 0; i < numEdges[u]; i++) {
            int v = graph[u][i];
            // If in-degree becomes zero, add it to queue
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check if there was a cycle in the graph
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    // Print topological order
    for (int i = 0; i < cnt; i++) {
        cout << topoSort[i] << " ";
    }
    cout << endl;
}

int main() {
    // Graph in adjacency matrix form, but it's actually an adjacency list in a 2D array form
    int graph[V][MAX_EDGES] = {{}, {}, {}, {}, {}, {}};
    int numEdges[V] = {0};

    // Adding edges: To make it more dynamic, we should ideally have an add_edge function.
    graph[5][numEdges[5]++] = 2;
    graph[5][numEdges[5]++] = 0;
    graph[4][numEdges[4]++] = 0;
    graph[4][numEdges[4]++] = 1;
    graph[2][numEdges[2]++] = 3;
    graph[3][numEdges[3]++] = 1;

    // Perform the topological sort
    kahnTopologicalSort(graph, numEdges);

    return 0;
}
