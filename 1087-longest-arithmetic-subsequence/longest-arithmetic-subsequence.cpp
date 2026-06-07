class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&nums,int i,int diff,int n){
        if(i<0)return 0;
        if(dp[i][diff+500]!=-1)return dp[i][diff+500];
        int ans = 0;
        for(int idx=i-1;idx>=0;idx--){
            if(nums[i]-nums[idx]==diff){
                ans = max(ans,1+solve(nums,idx,diff,n));
            }
        }
        return dp[i][diff+500]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+solve(nums,i,nums[j]-nums[i],n));
            }
        }
        return ans;
    }
};