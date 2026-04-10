class Solution {
public:
    vector<vector<int>>dp=vector<vector<int>>(201,vector<int>(20001,-1));
    bool solve(vector<int>&nums,int sum,int curr,int i,int n){
        if(i==n){
            return dp[i][curr] = curr*2 == sum;
        }
        if(dp[i][curr]!=-1) return dp[i][curr];

        bool take = solve(nums,sum,curr+nums[i],i+1,n);
        bool nottake=solve(nums,sum,curr,i+1,n);

        return dp[i][curr] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total&1)return false;
        return solve(nums,total,0,0,nums.size());   
    }
};