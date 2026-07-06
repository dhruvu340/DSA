class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>dpfront(k+1);
        vector<int>dpback(k+1);
        dpfront[0] = dpback[0] = 0;
        for(int i = 0;i<k;i++){
            dpfront[i + 1] = dpfront[i] + cardPoints[i];
            dpback[i + 1] = dpback[i] + cardPoints[n-i-1];
        }

        int ans = dpfront[k];
        for(int i = 1 ; i <= k ;i++){
            ans = max(ans,dpfront[k-i] + dpback[i]);
        }
        return ans;
    }
};