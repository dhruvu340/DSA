class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}}; 
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        grid[i][j] = 0;
        for(auto d:dir){
            int x = i + d[0];
            int y = j + d[1];
            if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y] == 1){
                dfs(grid,x,y,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i==0||j==0||i==n-1||j==m-1)&&grid[i][j] == 1){
                    dfs(grid,i,j,n,m);
                }
            }
        }

        int ct = 0 ;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                ct+=grid[i][j];
            }
        }
        return ct;
    }
};