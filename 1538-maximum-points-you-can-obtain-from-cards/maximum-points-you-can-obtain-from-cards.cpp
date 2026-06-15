class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int initialSum = 0;
        int i;
        for(i=0;i<k;i++){
            initialSum += cardPoints[i];
        }
        i--;

        int ans = initialSum;
        for(int j = n-1;j>=n-k;j--){
            initialSum += cardPoints[j];
            initialSum -= cardPoints[i];
            i--;
            cout<<"I runned"<<endl;
            ans=max(ans,initialSum);
        }


        return ans;


    }
};