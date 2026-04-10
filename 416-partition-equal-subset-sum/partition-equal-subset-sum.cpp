class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total&1)return false;
       int targetSum=total/2;
       vector<vector<int>>dp=vector<vector<int>>(nums.size(),vector<int>(targetSum+1,false));  
       for(int i=0;i<nums.size();i++){
        dp[i][0]=true;
       }

       if(nums[0]<=targetSum){
        dp[0][nums[0]]=true;
       }
    int n=nums.size();
       for(int i=1;i<n;i++){
        for(int s=0;s<=targetSum;s++){
            bool skip = dp[i-1][s];
            bool take=false;
            if(s-nums[i]>=0&&i-1>=0){
                take=dp[i-1][s-nums[i]];
            }
            dp[i][s]=take||skip;
        }
       }


       return dp[nums.size()-1][targetSum];
    }
};