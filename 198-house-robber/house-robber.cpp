class Solution {
public:
    int dp[500];
    int solve(vector<int>&nums,int i){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take=0;

        
            take=nums[i]+solve(nums,i+2);
       

        int nottake=solve(nums,i+1);

        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};