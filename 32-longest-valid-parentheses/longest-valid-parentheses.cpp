class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
       int open = 0;
       int close = 0;
       for(auto i:s){
        if(i=='(')open++;
        else close++;


        if(open==close){
            ans=max(ans,open+close);
        }else if(close>open){
            open=0;
            close=0;
        }
       }
       open=0;
       close=0;

       reverse(s.begin(),s.end());
       for(auto i:s){
        if(i=='(')open++;
        else close++;


        if(open==close){
            ans=max(ans,open+close);
        }else if(close<open){
            open=0;
            close=0;
        }
       }

        return ans;
    }
};