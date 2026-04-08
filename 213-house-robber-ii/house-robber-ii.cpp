class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        int n=nums.size();
        if(n==1)return nums[0];
        dp[0] = nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }

        int ans=dp[n-2];

        dp = vector<int>(n);
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
             dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }

        return max(ans,dp[n-1]);
    }
};