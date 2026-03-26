class Solution {
public:
    int countSubstrings(string s) {
    
       int n=s.size();
        int maxl=1;
        int stidx=0;
        int ct=0;
          vector<vector<bool>>t(n,vector<bool>(n));
          for(int i=0;i<n;i++){
            t[i][i]=true;
            ct++;
          }
        for(int l=2;l<=s.size();l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j]&&l==2){
                    t[i][j]=true;
                    maxl=2;
                    stidx=i;
                }else if(s[i]==s[j]&&t[i+1][j-1]){
                    t[i][j]=true;
                    maxl=j-i+1;
                    stidx=i;
                }else{
                    t[i][j]=false;
                }


                if(t[i][j])ct++;
            }
        }

        return ct;
    }
};