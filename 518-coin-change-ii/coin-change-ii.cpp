class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        if(coins[0]<=amount)dp[coins[0]][0]=1;

        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = ((j-1>=0) ? dp[i][j-1] : 0);
                if(i-coins[j]>=0)dp[i][j]+=1LL*dp[i-coins[j]][j];
            }
        }
        return dp[amount][n-1];
    }
};