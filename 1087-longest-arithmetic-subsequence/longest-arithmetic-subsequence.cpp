class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        int ans =1;
        vector<vector<int>>dp(n,vector<int>(1001,1));
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff=nums[i]-nums[j];
                dp[i][diff+500] = max(dp[i][diff+500],dp[j][500+diff] + 1);
                ans=max(ans,dp[i][diff+500]);
            }
        }
        return ans;
    }
};