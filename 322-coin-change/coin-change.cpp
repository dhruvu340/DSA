class Solution {
public: 
    
    int coinChange(vector<int>& coins, int amount) {

       vector<int>dp(amount+1);
       dp[0]=0;
       for(int i=1;i<=amount;i++){
        dp[i]=INT_MAX;
        for(auto j:coins){
            if(i-j>=0){
                dp[i]=min(dp[i]+0LL,dp[i-j]+1LL);
            }
        }
       }


       return dp[amount] ==INT_MAX ? -1 : dp[amount];
    }
};