class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        vector<int>v(128,0);
        while(r<s.size()){
            while(v[s[r]]!=0){
                v[s[l++]]--;
            }
            v[s[r]]++;
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};