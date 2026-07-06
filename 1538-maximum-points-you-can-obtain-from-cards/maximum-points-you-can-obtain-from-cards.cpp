class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        int i;
        for( i = 0;i<k;i++){
            sum += cardPoints[i];
        }
        i--;
        int ans = sum;
        for(int j = n-1;j>=n-k;j--){
            sum += cardPoints[j] - cardPoints[i--];
            ans = max(ans,sum);
        }

        return ans;
    }
};