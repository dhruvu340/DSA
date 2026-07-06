class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>m;
       int ct = 0;
       int n = s.size();
       int ans = 0;
       for(int l = 0 , r = 0 ;r<n;r++){
            m[s[r]]++;
            while(l<=r && m.size() < r-l+1){
                m[s[l]]--;
                if(m[s[l]] == 0)m.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
       }
       return ans;
    }
};