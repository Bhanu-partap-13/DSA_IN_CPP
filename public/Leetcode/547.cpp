class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        queue<int> q;
        visited[u] = true;
        q.push(u);

        while(!q.empty()){
            int u = q.front();
            q.pop();

        for(int& v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //now we will be doing bfs
        int V = isConnected.size();

        unordered_map<int, vector<int>> adj;
        
        for(int i = 0 ; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++)
        {
            if(!visited[i]){
                bfs(adj, i, visited);
                count++;
            }
        }
    return count;
    }
};