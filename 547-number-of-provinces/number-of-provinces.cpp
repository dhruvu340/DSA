class Solution {
public:
    void bfs(unordered_map<int,vector<int>>graph,vector<bool>&vis,int i){
        queue<int>q;
        q.push(i);
        vis[i] = true;
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

        
    }
    int findCircleNum(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i][j]==1){graph[i].push_back(j);
                graph[i].push_back(j);}
            }
        }
        int n=rooms.size();
        vector<bool>vis(n,false);

        int ct =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(graph,vis,i);
                ct++;
            }
        }



        return ct;
    }
};