class Solution {
public:
     int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int bfs(vector<vector<int>>& grid,int i,int j ,int m,int n){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=-1;
        int ct=1;

        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int _i=p.first+dx[j];
                    int _j=p.second+dy[j];

                    if(_i>=m||_i<0||_j>=n||_j<0||grid[_i][_j]!=1){
                        continue;
                    }else{
                        q.push({_i,_j});
                        grid[_i][_j]=-1;
                        ct++;
                    }
                }

            }
        }

        return ct;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   ct=max(ct, bfs(grid,i,j,m,n));
                    
                }
            }
        }

        return ct;
    }
};