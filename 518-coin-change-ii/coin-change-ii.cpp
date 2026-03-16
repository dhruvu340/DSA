class Solution {
public: 
    int dp[5001][301];
    int solve(int amount,vector<int>&coins,int i){
         if(amount==0)return 1;
        if(amount<0||(i>=coins.size())){
            return 0;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];


        return dp[amount][i]=solve(amount-coins[i],coins,i)+solve(amount,coins,i+1);

        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
       return  solve(amount,coins,0);
       
    }
};