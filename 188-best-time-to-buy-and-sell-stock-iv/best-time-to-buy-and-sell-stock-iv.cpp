class Solution {
public:
    int maxProfit(int t, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(t+1,-1)));
        for(int i=0;i<=1;i++){
            for(int j=0;j<=t;j++){
                dp[n][i][j]=0;
            }
        }
       
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=t;k++){
                    if(k!=0){
                    if(j == 0){
                    dp[i][j][k] = max(-prices[i]+dp[i+1][1][k],dp[i+1][j][k]);
                }else{
                    dp[i][j][k] = max(prices[i]+dp[i+1][0][k-1],dp[i+1][j][k]);
                }
                    }
                    else{
                    dp[i][j][k] = 0;
                }
                }
            }
        }
        return dp[0][0][t];
    }
};