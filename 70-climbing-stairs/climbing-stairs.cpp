class Solution {
public:
    int dp[46];
    int solve(int idx){
        if(idx<0)return 0;
        if(idx==0)return 1;
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx] = solve(idx-1) + solve(idx-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
       return solve(n);

    }
};