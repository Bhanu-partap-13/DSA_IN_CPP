#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& res){
   if(visited[node]) return;
    visited[node] = true;
    res.push_back(node);

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(graph, neighbor, visited, res);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Graph representation (adjacency list):" << endl;

    unordered_map<int, vector<int>> adj;

    for(int u = 0; u < n; u++){
        for(int v= graph[u].begin(); v != graph[u].end(); v++){
            adj[u].push_back(*v);
        }
    }
    vector<int> res;
    vector<bool> visited(n, false);

    dfs(graph, 0, visited, res);
    
    cout << "DFS Traversal starting from node 0:" << endl;
    for(int node : res){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}