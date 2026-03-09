class Solution {
public:
    int dp[56];
    int solve(int n){
        
        if(n<=2)return n;
        if(dp[n]!=-1)return dp[n]; 
        int one=0;
        int two=0;
       if(n-1>=0){  one=solve(n-1);}
       if(n-2>=0){  two=solve(n-2);}
       return dp[n]=one+two;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};