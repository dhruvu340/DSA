class Solution {
public:
    string minWindow(string s, string t) {
        int  l = 0 ;
        int n =s.size();
        map<char,int>mpp;
        for(auto i:t)mpp[i]++;
        int sti = -1;
        int len = INT_MAX;
        int ct = t.size();
        for(int i = 0;i<n;i++){
            if(mpp[s[i]]>0){
                ct--;
            }
            mpp[s[i]]--;
            while(ct==0){
                if(len>i-l+1){
                    sti = l;
                    len = min(len , i-l+1 );
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    ct++;
                }
                l++;
            }
        }

        if(sti==-1)return "";
        string ans = s.substr(sti,len);
        return ans;

    }
};