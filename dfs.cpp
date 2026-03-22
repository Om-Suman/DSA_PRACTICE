#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

// Function to perform DFS on a graph from a given node
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    // Recursive call for all connected nodes
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

// Function to perform DFS for all components of a graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Prepare adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // Call DFS for all unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    // Number of vertices and edges
    int V = 7, E = 5;

    // Edges of the graph
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {4, 5},
        {5, 6}
    };

    // Perform DFS
    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Output the connected components
    cout << "Connected Components in the Graph:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : result[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
