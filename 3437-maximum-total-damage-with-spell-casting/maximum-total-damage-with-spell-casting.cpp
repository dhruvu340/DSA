class Solution {
public:
    long long dp[100001];
    long long solve(vector<int>&v,int i,map<int,int>&m){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int tkid=upper_bound(v.begin(),v.end(),v[i]+2)-v.begin();
        return dp[i]=max(solve(v,i+1,m)*1LL,v[i]*1LL*m[v[i]]+solve(v,tkid,m));
    }
    long long maximumTotalDamage(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
       sort(v.begin(),v.end());
        map<int,int>m;
        for(auto i:v)m[i]++;
        return solve(v,0,m);
    }
};