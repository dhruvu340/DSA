class Solution {
public:
    vector<vector<vector<int>>>dp = vector<vector<vector<int>>>(71,vector<vector<int>>(71,vector<int>(71,-1)));
    int solve(vector<vector<int>>&grid,int row , int c1,int c2,int n,int m){
        if(row>=n)return 0 ; 
        if(dp[row][c1][c2]!=-1)return dp[row][c1][c2];
        int ans = grid[row][c1];
        if(c1!=c2){
            ans+=grid[row][c2];
        }
        int cherry=0;
        for(int i = -1 ; i<=1;i++ ){
            for(int j=-1;j<=1;j++){
                int nc1=c1+i;
                int nc2=c2+j;
                if(nc1>=0&&nc1<m&&nc2>=0&&nc2<m){
                    cherry = max(cherry,solve(grid,row+1,nc1,nc2,n,m));
                }
            }
        }


        return dp[row][c1][c2] =  ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid,0,0,m-1,n,m);
    }
};