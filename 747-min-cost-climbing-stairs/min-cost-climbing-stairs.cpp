class Solution {
public:
    int dp[1001];
    int rec(vector<int>& cost,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        return dp[i]=cost[i]+ min(rec(cost,i+1,n),((i+2<=n) ? rec(cost,i+2,n) :INT_MAX));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(rec(cost,0,n),rec(cost,1,n));

        
    }
};