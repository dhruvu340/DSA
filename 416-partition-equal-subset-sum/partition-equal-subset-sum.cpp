class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        vector<vector<bool>>dp(sum+1,vector<bool>(n+1,false));
        for(int i=0;i<=n;i++){
            dp[0][i]=true;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                if(j-nums[i-1]>=0){
                    dp[j][i]=dp[j-nums[i-1]][i-1]||dp[j][i-1];
                }else{
                    dp[j][i]=dp[j][i-1];
                }
            }
        }



        return dp[sum/2][n];

    }
};