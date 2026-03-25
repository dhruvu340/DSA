class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=1;
        int n=s.size();
        vector<int>freq(26,0);
            int maxfreq=0;
            int l=0,r=0;
        while(r<n){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);

            while(l<r && r-l+1-maxfreq>k){
                freq[s[l]-'A']--;
                for(int i=0;i<26;i++){
                    maxfreq=max(maxfreq,freq[i]);
                }
                l++;
            }
            
            if(r-l+1-maxfreq<=k){
                ans = max(ans,r-l+1);
            }
            r++;
        }
         

        return ans;
    }
};