#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<set>
using namespace std ; 
void  preparedAdjList ( unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(  unordered_map<int,set<int>> &adjList,     unordered_map<int,bool> &visited,    vector<int>&ans,int node){
   queue<int>q;
   q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
     unordered_map<int,bool> visited;
    
    preparedAdjList(adjList,edges);
    // traverse all components
    for(int i =0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i); 
        }
    }
   return ans; 
}

int main() {
    int vertex = 5;

    vector<pair<int, int>> edges = {
        {0, 1}, 
        {0, 2}, 
        {1, 3}, 
        {1, 4}
    };

    vector<int> result = BFS(vertex, edges);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}