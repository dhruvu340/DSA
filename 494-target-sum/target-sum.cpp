class Solution {
public:
    vector<vector<int>>dp=vector<vector<int>>(21,vector<int>(200001,-1));
    int solve(vector<int>&nums,int target,int sum,int i){
        if(i==nums.size()){
            if(sum==target){
               
                return dp[i][1000+sum] = 1;
                
                }
            else return dp[i][1000+sum] = 0;
        }

        if(dp[i][1000+sum]!=-1)return dp[i][1000+sum];

        int add = sum + nums[i];
        int minus = sum - nums[i];

        int f=solve(nums,target,add,i+1);
        int e=solve(nums,target,minus,i+1);


        return dp[i][1000+sum] = f+e;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};