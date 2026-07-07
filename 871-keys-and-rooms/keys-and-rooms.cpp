class Solution {
public:
    void traverse(int node,vector<bool>&vis,vector<vector<int>>&graph){
        vis[node] = true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int front = q.front();
                q.pop();
                for(auto i:graph[front]){
                    if(!vis[i]){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
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