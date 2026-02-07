class Solution {
public:
    int n;
    set<string>st;
    int dp[305];
    bool solve(int idx,string &s){
        if(idx==n)return dp[idx]=true;
        if(dp[idx]!=-1)return dp[idx];

        for(int i=1;i<=n;i++){
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end()&&solve(idx+i,s)){
                return dp[idx]= 1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict){
            st.insert(i);
        }
       return solve(0,s);
    }
};