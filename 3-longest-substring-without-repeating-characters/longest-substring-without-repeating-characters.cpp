class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>check(256,false);
        int l = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            while(l<=i && check[s[i]] == true){
                check[s[l]] = false;
                l++;
            }
            check[s[i]] = true;
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};