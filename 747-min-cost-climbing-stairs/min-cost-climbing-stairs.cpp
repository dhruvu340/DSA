class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),0);
        int n=cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<cost.size();i++){
            dp[i]=1LL*(cost[i] + min(dp[i-1],dp[i-2]));

        }


        return min(dp[n-2],dp[n-1]);
        

    }
};