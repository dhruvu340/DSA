class Solution {
public: 
    int maxProfit(vector<int>& v) {
        int ans=0;
        int maxi=INT_MAX;
        for(auto i:v){
            maxi=min(maxi,i);
            ans=max(ans,i-maxi);

        }

        return ans;
    }
};