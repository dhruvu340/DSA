class Solution {
public:
    void bfs(int node ,vector<vector<int>>&adj,vector<bool>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int nextElement = q.front();
                q.pop();
                for(auto i:adj[nextElement]){
                    if(!vis[i]){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
        bfs(0,rooms,vis);
        for(auto i:vis){
            if(!i)return false;
        }
        return true;
    }
};