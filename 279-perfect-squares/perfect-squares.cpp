class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n==0)return 0;
        if(dp[n])return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            
            if(n-(i*i)>=0){ans=min(ans,1+solve(n-(i*i)));}
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        
        
        return solve(n);
    }
};