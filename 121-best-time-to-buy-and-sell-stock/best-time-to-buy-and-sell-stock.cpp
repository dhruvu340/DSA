class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(auto i:prices){
            ans  = max(ans,i-mini);
            mini = min(mini,i);
        }

        return ans;
    }
};