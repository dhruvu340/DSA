class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sumTotal = accumulate(nums.begin(),nums.end(),0);
        if(sumTotal&1)return false;
        sort(nums.begin(),nums.end());
        int amount=sumTotal/2;
        vector<vector<int>>dp(amount+1,vector<int>(n,false));
        for(int i=0;i<n;i++){
            dp[0][i]=true;
        }
        for(int i=1;i<=amount;i++){
            for(int j = n-1;j>=0;j--){
                dp[i][j] =false;
                if(i-nums[j]>=0&&j+1<n)dp[i][j] = dp[i-nums[j]][j+1];
                if(j+1<n)dp[i][j]|=dp[i][j+1];
            }
        }
        return dp[amount][0];
    }
};