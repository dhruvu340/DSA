class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char,int>m;
        map<string,int>mp;
        int ct = 0;
        for(int l = 0 , r = 0 ; r<s.size();r++){
            m[s[r]]++;
            
            if(r-l+1 > minSize){
                m[s[l]]--;
                if(m[s[l]]== 0 ){
                    m.erase(s[l]);
                }
                l++;
            }

            if(r-l+1==minSize && m.size()<=maxLetters){
                string t = s.substr(l,r-l+1);
                mp[t]++;
            }

        }

        int ans = 0;
        for(auto i:mp){
            ans = max(ans,i.second);
        }

        return ans;
    }
};