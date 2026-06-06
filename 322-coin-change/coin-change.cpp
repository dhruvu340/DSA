class Solution {
public:
    int dp[10001];
    long long solve(vector<int>&coins,int amount){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        int ans = INT_MAX;
        for(int idx=0;idx<coins.size();idx++){
            if(coins[idx] <= amount){
                ans = min(ans*1LL,1+solve(coins,amount-coins[idx]));
               
            }
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int ans = solve(coins,amount);
        return  (ans==INT_MAX)?-1:ans;
    }
};