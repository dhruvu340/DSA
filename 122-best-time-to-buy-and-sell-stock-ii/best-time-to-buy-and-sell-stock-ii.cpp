class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>&prices,int i,int buyOrSell){
        if(i==prices.size())return 0;
        if(dp[i][buyOrSell]!=-1)return dp[i][buyOrSell];
        int ans ; 
        if(buyOrSell==0){
            int buy = -prices[i] + solve(prices,i+1,1);
            int skip = solve(prices,i+1,buyOrSell);
            ans = max(buy,skip);
        }else{
            int sell = prices[i] + solve(prices,i+1,0);
            int skip = solve(prices,i+1,buyOrSell);
            ans = max(sell,skip);
        }
        return dp[i][buyOrSell] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0);
    }
};