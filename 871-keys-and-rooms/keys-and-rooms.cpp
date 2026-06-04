class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<rooms.size();i++){
            for(auto j:rooms[i]){
                graph[i].push_back(j);
            }
        }
        int n=rooms.size();
        vector<int>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                q.pop();
                for(auto i : graph[top]){
                    if(!vis[i]){vis[i] = true;
                    q.push(i);}
                }
            }
        }

        for(auto i:vis){
            if(!i)return false;
        }
        return true;
    }
};