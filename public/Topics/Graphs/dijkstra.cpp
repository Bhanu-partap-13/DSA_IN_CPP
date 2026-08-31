#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //priority_queue<int, vector<int>>; // agar ye likhte toh this is max_heap
        //priority_queue<int, vector<int>, greater<int>>; //This is the min heap but we are storing and traversing in the pair, so we have to use pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<vector<pair<int, int>>> adj(V);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        //agar nhi likhte toh bhi kuch nhi hota
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dist > result[node])continue;
            
            for(auto& v : adj[node]){
                int neigh = v.first;
                int wt = v.second;
                
                if(dist + wt < result[neigh]){
                  result[neigh] = dist + wt;
                  pq.push({dist+wt, neigh}); 
                }
            }
        }
    return result;
    }
};