class Solution {
public:
    int dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
        vis[node] = 1;
        int ct = 0;
        for(auto i:adj[node]){
            int curr = i.first;
            int dupli = i.second;
            if(!vis[curr]){
               ct += dupli + dfs(curr,adj,vis);
            }
        }
        return ct;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<int>vis(n,0);
        int ct = dfs(0,adj,vis);
        return ct;
    }
};