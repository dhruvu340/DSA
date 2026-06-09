class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& v,int i,int j,int m,int n){
        if(i==m-1&&j==n-1&&v[i][j]!=1)return 1;
        if(i>=m||j>=n||i<0||j<0||v[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right = solve(v,i,j+1,m,n);
        int down = solve(v,i+1,j,m,n);
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        if(v[0][0]==1)return 0;
        int m=v.size();
        int n=v[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(v,0,0,m,n);
    }
};