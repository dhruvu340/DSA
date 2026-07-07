class Solution {
public:
    void traverse(int node,vector<bool>&vis,vector<vector<int>>&graph){
        vis[node] = true;
        for(auto i:graph[node]){
            if(!vis[i])traverse(i,vis,graph);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        traverse(0,vis,rooms);
        for(auto i:vis){
            if(!i)return false;
        }
        return true;
    }
};