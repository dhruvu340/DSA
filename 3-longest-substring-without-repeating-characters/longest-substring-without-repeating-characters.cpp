class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        unordered_set<int>se;
        while(r<s.size()){
            while(se.count(s[r])){
                se.erase(s[l++]);
            }
            se.insert(s[r]);
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};