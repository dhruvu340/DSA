class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string s1="";
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
            string s2 = s.substr(l+1,r-l-1);
            if(s1.size()<s2.size()){
                s1=s2;
            }
             l=i-1;
             r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
            string s3 = s.substr(l+1,r-l-1);
            if(s1.size()<s3.size()){
                s1=s3;
            }
        }

        return s1;
    }
};