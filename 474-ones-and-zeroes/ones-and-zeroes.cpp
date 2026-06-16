class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>&v,int i,int m,int n){
        if(i>=v.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int notpick = solve(v,i+1,m,n);
        int c0 = count(v[i].begin(),v[i].end(),'0');
        int c1 = v[i].size() - c0;
        int pick = (c0<=m&&c1<=n) ? 1+solve(v,i+1,m-c0,n-c1) : 0;
        return dp[i][m][n] = max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);
    }
};