class Solution {
public:
    int dp[10001][201];
    bool solve(vector<int>&nums,int ns,int i,int &sum){
        if(ns==(sum/2))return true;
        if(i>=nums.size()||ns>(sum/2))return false;
        if(dp[ns][i]!=-1)return dp[ns][i];

        return dp[ns][i] = solve(nums,ns+nums[i],i+1,sum) || solve(nums,ns,i+1,sum);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        return solve(nums,0,0,sum);
    }
};