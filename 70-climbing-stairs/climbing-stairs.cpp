class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        //if n is less than or equal to 1 then there is only one possibility
        vector<int>dp(n+1);

        //base case is when if n < = 1 return 1;
        dp[0]=1;
        dp[1]=1;

        // transition function will look alike this dp[i] = dp[i-1] + dp[i-2];
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};