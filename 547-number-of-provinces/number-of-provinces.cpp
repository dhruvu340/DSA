class Solution {
public:
    void dfs(unordered_map<int,vector<int>>graph,vector<bool>&vis,int i){
        
        vis[i] = true;
        for(auto j:graph[i]){
            if(vis[j]==false){
                dfs(graph,vis,j);
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
                dfs(graph,vis,i);
                ct++;
            }
        }



        return ct;
    }
};