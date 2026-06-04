class Solution {
public:
    int dfs(int i,unordered_map<int,vector<pair<int,int>>>&gr,vector<int>&vis){
        vis[i] = true;
        int ct = 0;
        for(auto v : gr[i]){
            if(!vis[v.first]){
                ct+=dfs(v.first,gr,vis) + (v.second == 0 );
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