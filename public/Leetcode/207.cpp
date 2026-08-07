class Solution {
public:
    bool topologicalSort(vector<int> adj[], vector<int>& inDegree, int n){
        queue<int> q;
        
        int count = 0;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int& v: adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        if(count == n) return true; // iska mtlb agar main n tak pahaunch gya toh maine sare course complete kr liye 
    return false; // agar nhi pahuncha last tak toh nhi kiye honge
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //using BFS
        int V = numCourses;
        vector<int> adj[V];
        vector<int> inDegree(V, 0);

        for(auto& e : prerequisites){
            int u = e[0];
            int v = e[1];
        //u --------> v
            adj[v].push_back(u);
          //  toh inDegree u ka badhega
            inDegree[u]++;
        }
        //vector of array bnn gya

        //if cycle is present then true else false

        return topologicalSort(adj, inDegree, V);
    }
};  