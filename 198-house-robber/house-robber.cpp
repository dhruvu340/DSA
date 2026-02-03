class Solution {
public:
    int dp[500][2];
    int solve(vector<int>&nums,int flag,int i){
        if(i==nums.size())return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        int take=0;

        if(flag==0){
            take=nums[i]+solve(nums,1,i+1);
        }

        int nottake=solve(nums,0,i+1);

        return dp[i][flag]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};