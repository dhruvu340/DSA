class Solution {
public:
    vector<vector<int>>dp=vector<vector<int>>(1001,vector<int>(1001,-1));
    bool solve(string &s,int i, int j){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
           return dp[i][j]=solve(s,i+1,j-1);
        }else{
            return dp[i][j] = false;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string s1="";

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(j-i+1>s1.size()){
                       s1 = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return s1;
    }
};