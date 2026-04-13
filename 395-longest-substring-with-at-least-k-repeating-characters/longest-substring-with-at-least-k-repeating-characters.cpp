class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0||n<k)return 0;
        if(k<=1)return n;
        unordered_map<char,int>m;
        for(auto i:s)m[i]++;
        int l=0;
        while(l<n&&m[s[l]]>=k)l++;
        if(l==n)return l;
        int s1=longestSubstring(s.substr(0,l),k);
        while(l<n&&m[s[l]]<k)l++;
        int s2=longestSubstring(s.substr(l,n-l+1),k);
        return max(s1,s2);
    }
};