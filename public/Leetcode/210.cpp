class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, vector<int>& inDegree, int u){
        queue<int> q;
        vector<int> res;
        int n = inDegree.size();

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int& v: adj[u]){
                inDegree[v]--;   
                if(inDegree[v]==0){
                    res.push_back(v);
                    q.push(v);
                }
            }
        }
        if(res.size() == n){
            return res;
        }
    return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        
        for(auto &e : prerequisites){
            int u = e[0];
            int v = e[1];

            adj[v].push_back(u);
            inDegree[u]++;
        }

    return topologicalSort(adj, inDegree, numCourses);
    }
};