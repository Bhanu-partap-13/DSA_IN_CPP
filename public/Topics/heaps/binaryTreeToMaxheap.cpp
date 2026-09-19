class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion, int u){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v : adj[u]){
            if(inRecursion[v]) return true;
            else if(!visited[v] && dfs(adj, visited, inRecursion, v)){
                    return true;
                }
        }
    inRecursion[u] = false;
    return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        //terminal node h jio kisi ko connect nhi krti
        //safe node h jo terminal node ki indegree h, ya terminal nodes khud
        int V = adj.size();

        vector<bool> inRecursion(V, false);
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i])
             dfs(adj, visited, inRecursion, i);
        }
        
        vector<int> res;

        for(int i=0; i<V; i++){
            if(inRecursion[i] == false){
                res.push_back(i);
            }
        }
    return res;
    }
};