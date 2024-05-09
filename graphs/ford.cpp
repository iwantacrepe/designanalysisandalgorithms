#include <iostream>
#include <cstdio>
#include <climits>

#define V 6  // Number of vertices in the graph

/* Returns true if there is a path from source 's' to sink 't' in residual graph.
   Also fills parent[] to store the path */
int bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue, enqueue source vertex and mark source vertex as visited
    int queue[V], front = 0, back = 0;
    queue[back++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front != back) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue[back++] = v;
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    // Create a residual graph and fill the residual graph with given capacities in the original graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates residual capacity of edge from i to j (if there is an edge).
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];  // This array is filled by BFS and to store path
    int max_flow = 0;  // There is no flow initially

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent)) {
        // Find the minimum residual capacity of the edges along the path filled by BFS.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = std::min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    std::cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
