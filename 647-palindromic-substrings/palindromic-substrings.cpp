class Solution {
public:
    int countSubstrings(string s) {
    
        int n=s.size();
        int ct=0;
        for(int i=0;i<n;i++){
            
            int l=i;
            int r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                ct++;
                l--;
                r++;
            }
            
             l=i-1;
             r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                ct++;
                l--;
                r++;
            }
            
        }

        return ct;
  
    }
};