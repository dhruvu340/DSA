class Solution {
public:
    int  dfs (int i,unordered_map<int,vector<pair<int,int>>>&graph,vector<int>&vis){
        int ct = 0;
        vis[i] = true;
        for(auto j : graph[i]){
            if(!vis[j.first]){
                ct +=  dfs(j.first,graph,vis) + (j.second==1?0:1 );
            }
        }
        return ct;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto i:connections){
            graph[i[0]].push_back({i[1],0});
            graph[i[1]].push_back({i[0],1});
        }
        vector<int>vis(n,false);
        return dfs(0,graph,vis);
        
    }
};