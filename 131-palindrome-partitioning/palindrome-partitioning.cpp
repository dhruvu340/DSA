class Solution {
public:
    bool pal(string s,int st,int end){
        while(st<end){
            if(s[st]!=s[end])return false;

            end--;
            st++;
        }

        return true;
    }
    vector<vector<string>>ans;
    void solve(string s,int idx,vector<string>t){
        if(idx==s.size()){
            ans.push_back(t);
            return;
        }
        for(int i=idx;i<s.size();i++){
           if(pal(s,idx,i)){ t.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,t);
            t.pop_back();}
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,0,temp);
        return ans;
    }
};