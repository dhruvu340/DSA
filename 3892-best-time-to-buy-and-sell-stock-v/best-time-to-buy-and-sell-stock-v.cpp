class Solution {
public:
    long long dp[1001][1001][3];
    long long solve(vector<int>&prices,int k,int i,int state){
        if(i==prices.size() ||  k==0){
            return state !=2  ? 0 : INT_MIN;
        }
        if(dp[i][k][state] !=-1)return dp[i][k][state];
        if(state == 0){
            long long buy = -prices[i] + solve(prices,k,i+1,1);
            long long notbuy = solve(prices,k,i+1,0);
            long long shortSell = prices[i] + solve(prices,k,i+1,2);
            return dp[i][k][state] = max({buy,notbuy,shortSell});
        }else if(state == 1){
            long long  sell = prices[i] + solve(prices,k-1,i+1,0);
            long long  notsell = solve(prices,k,i+1,1);
            return dp[i][k][state] = max({sell,notsell});
        }else{
            long long  shortsell = -prices[i] + solve(prices,k-1,i+1,0);
            long long  notshort = solve(prices,k,i+1,2);
            return dp[i][k][state] = max(shortsell,notshort);
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,k,0,0);
    }
};