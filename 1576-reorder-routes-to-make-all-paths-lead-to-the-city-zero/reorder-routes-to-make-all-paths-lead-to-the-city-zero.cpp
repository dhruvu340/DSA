class Solution {
public:
    int dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int n = q.front();
                q.pop();
                for(auto i:adj[n]){
                    if(vis[i.first]==false){
                        vis[i.first]=true;
                        ans += i.second;
                        q.push(i.first);
                    }
                }
            }
        }
        return ans;
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