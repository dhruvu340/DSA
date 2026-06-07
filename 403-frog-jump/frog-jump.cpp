class Solution {
public:
unordered_map<int,int>m;
int dp[2001][2001];
    bool solve(vector<int>&nums,int n,int curr_idx,int diff){
        if(curr_idx==n-1)return true;
        if(dp[curr_idx][diff]!=-1)return dp[curr_idx][diff];
        int ans =false;
        for(int k = diff-1;k<=diff+1;k++){
            if(k>0&&m.find(nums[curr_idx] + k)!=m.end()){
                ans |= solve(nums,n,m[nums[curr_idx] + k],k);
            }
        }
        return dp[curr_idx][diff] = ans;
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n=stones.size();
        for(int i=0;i<n;i++){
            m[stones[i]]=i;
        }
        if(stones[1]!=1)return false;
        return solve(stones,n,1,1);
    }
};