#include <iostream>

const int MAX_V = 20;

bool hamCycleUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V);
bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos);
void printSolution(int path[], int V);

bool hamCycle(bool graph[MAX_V][MAX_V], int V) {
    int path[MAX_V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1, V)) {
        std::cout << "\nSolution does not exist";
        return false;
    }
    printSolution(path, V);
    return true;
}

bool hamCycleUtil(bool graph[MAX_V][MAX_V], int path[], int pos, int V) {
    if (pos == V) {
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
            path[pos] = -1;
        }
    }
    return false;
}

bool isSafe(int v, bool graph[MAX_V][MAX_V], int path[], int pos) {
    if (!graph[path[pos-1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

void printSolution(int path[], int V) {
    std::cout << "Solution Exists: Following is one Hamiltonian Cycle" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << path[i] << " ";
    std::cout << path[0] << std::endl;
}

int main() {
    bool graph[MAX_V][MAX_V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int V = 5;

    hamCycle(graph, V);

    return 0;
}
