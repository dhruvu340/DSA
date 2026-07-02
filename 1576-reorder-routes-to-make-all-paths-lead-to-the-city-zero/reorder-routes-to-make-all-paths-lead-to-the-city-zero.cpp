class Solution {
public:
    int dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node] = true;
        int ct = 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currElement = q.front();
                q.pop();
                for(auto i:adj[currElement]){
                    int el = i.first;
                    int dup = i.second;

                    if(!vis[el]){
                        vis[el] = true;
                        ct += dup;
                        q.push(el);
                    }
                }
            }
        }
        return ct;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        vector<int>vis(n,0);
        int ct = dfs(0,adj,vis);
        return connections.size()-ct;
    }
};