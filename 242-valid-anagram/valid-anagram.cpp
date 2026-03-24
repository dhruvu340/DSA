class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vs(26,0);
        vector<int>vt(26,0);
        for(auto i:s)vs[i-'a']++;
        for(auto i:t)vt[i-'a']++;
        for(int i=0;i<26;i++)if(vs[i]!=vt[i])return false;
        return true;

        
    }
};