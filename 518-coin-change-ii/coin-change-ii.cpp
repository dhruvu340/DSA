class Solution {
public:
    int dp[5001][301];
    int solve(int amount ,vector<int>&coins,int i){
        if(amount==0)return 1;
        if(dp[amount][i]!=-1)return dp[amount][i];
        int ans =0;
        for(int idx=i;idx<coins.size();idx++){
            if(coins[idx]<=amount){
                ans += solve(amount - coins[idx] , coins,idx);
            }
        }
        return dp[amount][i] = ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(amount,coins,0);
    }
};