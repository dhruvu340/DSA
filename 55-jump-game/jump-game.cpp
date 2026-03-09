class Solution {
public:
    int dp[100001];
    bool solve(vector<int>&nums,int idx){
        if(idx>=nums.size()-1){
            return true;
        }

        if(dp[idx]!=-1)return dp[idx];

        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,idx+i))return dp[idx] = true;
        }



        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};