//BFS
class Solution {
  public:
  
    bool BFS(vector<int> adj[], vector<bool>& visited, int u){
        queue<pair<int, int>> q;
        visited[u] =  true;
        q.push({u, -1});
        
        while(!q.empty()){
            pair<int, int> P = q.front();
            q.pop();
            
            int source = P.first;
            int parent = P.second;
            for(int& v : adj[source]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v, source});
                    
                }
                else if(v != parent) return true;
            }
        }
    return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && BFS(adj, visited, i)){
                return true;
            }
        }
    return false;
    }
};

//DFS
