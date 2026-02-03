class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0;
        int r=0;
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<g.size()&&r<s.size()){
            while(r<s.size()&&s[r]<g[l]){
                r++;
            }

            if(r<s.size()&&l<g.size()&&s[r]>=g[l]){
                ans++;
                r++;
                l++;
            }else{
                break;
            }
        }


        return ans;

    }
};