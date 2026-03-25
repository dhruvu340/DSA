class Solution {
public: 
    int maxProfit(vector<int>& v) {
        int l=0;
        int r=1;
        int ans=0;
        while(r<v.size()){
            if(v[l]<v[r]){
                ans=max(ans,v[r]-v[l]);
            }else{
                l=r;
            }
            r++;
        }
        return ans;
    }
};