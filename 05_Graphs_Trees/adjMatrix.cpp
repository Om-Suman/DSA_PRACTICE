#include <iostream>
using namespace std;

void addEdge(int adjMatrix[][5], int u, int v, int V) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAdjMatrix(int adjMatrix[][5], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int V = 5; // Number of vertices
    int adjMatrix[5][5];
    
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add edges to the graph
    addEdge(adjMatrix, 0, 3, V);
    addEdge(adjMatrix, 0, 4, V);
    addEdge(adjMatrix, 1, 4, V);
    addEdge(adjMatrix, 1, 2, V);
    addEdge(adjMatrix, 2, 3, V);

    cout << "Adjacency Matrix:" << endl;
    printAdjMatrix(adjMatrix, V);
    
    return 0;
}
