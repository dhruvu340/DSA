class Solution {
public:
    int dp[2502][2502];
    int solve(vector<int>&nums,int prev,int i){
        if(i==nums.size()){
            return 0;
        }
        if(prev!=-1&&dp[prev+1][i]!=-1)return dp[prev+1][i];
        int nottake = solve(nums,prev,i+1);
        int take = 0;
        if(prev==-1||nums[prev]<nums[i]){
            take = 1 + solve(nums,i,i+1);
        }
        return dp[prev+1][i] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,-1,0);
    }
};