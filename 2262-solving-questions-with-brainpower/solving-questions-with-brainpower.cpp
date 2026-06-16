class Solution {
public:
    long long dp[100001];
    long long solve(vector<vector<int>>& v,int i){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long pick = v[i][0]*1LL + 1LL*solve(v,i+v[i][1]+1);
        long long notpick = 1LL*solve(v,i+1);
        return  dp[i] = max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }
};