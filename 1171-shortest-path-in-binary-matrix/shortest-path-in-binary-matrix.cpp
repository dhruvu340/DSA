class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        vector<pair<int,int>>dir={{0,1},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{-1,0},{0,-1}};
        if(grid[0][0]!=0)return -1;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        dist[0][0]=0;
        while(!q.empty()){
         
                int distance=q.top()[0];
                int i=q.top()[1];
                int j=q.top()[2];
                q.pop();
                if(i==n-1&&j==m-1)return distance+1;
                if(distance>dist[i][j])continue;
                for(auto &d:dir){
                    int x=i+d.first;
                    int y=j+d.second;
                    if(x>=0&&y>=0&&y<m&&x<n&&grid[x][y]==0&&(distance+1<dist[x][y])){
                        dist[x][y]=distance+1;
                        q.push({dist[x][y],x,y});
                    }
                }
            
        }


        return -1;
    }
};