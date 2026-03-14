class Solution {
public:
    int maxProfit(vector<int>& v) {
        int minsell=INT_MAX;
        int ans=0;
        for(auto i:v){
            minsell=min(minsell,i);
            ans=max(ans,i-minsell);
        }



        return ans;


        
    }
};