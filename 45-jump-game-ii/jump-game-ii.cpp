class Solution {
public:
    const int N=10001;
    vector<int>dp=vector<int>(N,-1);
    int jump(vector<int>& nums,int idx=0) {
        if(idx>=nums.size()-1)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int minjumps=10001;
        for(int i=1;i<=nums[idx];i++){
            minjumps=min(minjumps,1+jump(nums,idx+i));
        }

        return dp[idx] = minjumps;
    }
};