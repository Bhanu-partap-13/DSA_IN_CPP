#include<bits/stdc++.h>
using namespace std;

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
            
        }
    }
}