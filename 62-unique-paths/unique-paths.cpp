class Solution {
public:
    int dp[101][101];
    int solve(int mc,int nc,int m,int n){
        if(mc>=m)return 0;
        if(nc>=n)return 0;
        if(mc==m-1&&nc==n-1)return 1;
        if(dp[mc][nc]!=-1)return dp[mc][nc];
        return dp[mc][nc]=solve(mc+1,nc,m,n)+solve(mc,nc+1,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};