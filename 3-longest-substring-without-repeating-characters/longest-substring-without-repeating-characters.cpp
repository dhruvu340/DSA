class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        vector<int>v(128,-1);
        while(r<s.size()){
            if(v[s[r]]>=l){
                l=v[s[r]]+1;
            }
            v[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};