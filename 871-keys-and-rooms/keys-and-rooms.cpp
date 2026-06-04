class Solution {
public:
    void dfs (vector<int>&vis,unordered_map<int,vector<int>>&gr,int i){
        vis[i] = true;
        for(auto a:gr[i]){
            if(!vis[a]){
                dfs(vis,gr,a);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<rooms.size();i++){
            for(auto j:rooms[i]){
                graph[i].push_back(j);
            }
        }
        int n=rooms.size();
        vector<int>vis(n,false);
        dfs(vis,graph,0);
        for(auto i:vis){
            if(!i)return false;
        }
        return true;
    }
};