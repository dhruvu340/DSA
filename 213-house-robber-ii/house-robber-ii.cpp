class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
          if(n<2)return nums[n-1];
    vector<int>dp(n);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<n-1;i++){
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);

        if(i==n-1){
            dp[i]=max(dp[i],dp[0]);
        }

    }

    int ans1=dp[n-2];



    dp.clear();

    dp[0]=0;
    dp[1]=nums[1];
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],(i-2>=0)?nums[i]+dp[i-2]:0);
    }



    return max(ans1,dp[n-1]);

    
    }
};