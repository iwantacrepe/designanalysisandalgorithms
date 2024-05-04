#include <iostream>

const int V = 5;  

bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) 
        return true;

    for (int c = 1; c <= m; c++) {
     
        if (isSafe(v, graph, color, c)) {
            color[v] = c; 

         
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;  
        }
    }

    return false; 
}


void printSolution(int color[]) {
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
        std::cout << "Node " << nodes[i] << " --->  Color " << color[i] << std::endl;
}

void graphColoring(int graph[V][V], int m) {
    int color[V];  
    for (int i = 0; i < V; i++) color[i] = 0;  

    
    if (!graphColoringUtil(graph, m, color, 0)) {
        std::cout << "Solution does not exist";
        return;
    }

    
    printSolution(color);
}

int main() {
   
    int graph[V][V] = {
        {0, 1, 1, 0, 1},  
        {1, 0, 1, 0, 1},  
        {1, 1, 0, 1, 0},  
        {0, 0, 1, 0, 1}, 
        {1, 1, 0, 1, 0}  
    };

    int m = 5;  
    graphColoring(graph, m);
    return 0;
}
