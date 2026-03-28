class Solution {
public:
    void dfs(int node ,map<int,vector<int>>&adj, vector<bool>&vis){
        if(vis[node]==true)return ;

        vis[node]=true;
        for(auto i:adj[node]){
           if(!vis[i]){ dfs(i,adj,vis);}
        }

    }
    int findCircleNum(vector<vector<int>>& a) {
        map<int,vector<int>>adj;
        int V=a.size();
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(V,false);
        int ct=0;
        for(int i=0;i<V;i++){
            if(vis[i]!=true){
                dfs(i,adj,vis);
                ct++;
            }
        }

        return ct;
    }
};