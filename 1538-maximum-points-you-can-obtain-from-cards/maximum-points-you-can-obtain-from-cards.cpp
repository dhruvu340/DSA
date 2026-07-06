class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0LL);
        int ans = INT_MAX;
        int sum = 0;
        int windowSize = n-k;
        for(int i = 0;i<n;i++){
            sum += cardPoints[i];
            if(i>=windowSize){
                sum -= cardPoints[i-windowSize];
            }
            if(i>=windowSize-1){
                ans=min(ans,sum);
            }
        }

        return totalSum - ans;
    }
};