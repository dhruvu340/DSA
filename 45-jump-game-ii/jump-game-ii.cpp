class Solution {
public:
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),10001);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j = 1 ; j<=min(nums[i]+i,n-1);j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }


        return dp[n-1];
    }
};