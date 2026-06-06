class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        

        for(int i=1;i<=amount;i++){
            for(int j=n-1;j>=0;j--){
                dp[i][j] = 0;
                for(int k = j;k<n;k++){
                if(coins[k]<=i){
                   dp[i][j] += 1LL*dp[i-coins[k]][k];
                }

                }
            }
        }
        return dp[amount][0];
    }
};