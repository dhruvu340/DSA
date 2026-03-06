class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&nums,int m,int n){
        if(i>=m||j>=n)return INT_MAX;
        if(i==m-1&&j==n-1)return nums[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
       long long down=solve(i,j+1,nums,m,n);
        long long right=solve(i+1,j,nums,m,n);
        return dp[i][j]=nums[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& nums) {
        memset(dp,-1,sizeof(dp));

       return solve(0,0,nums,nums.size(),nums[0].size());
        
    }
};