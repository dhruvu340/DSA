class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ans = 0;
        int n = v.size();
        int j;
        for( j=0;j<k;j++){
            ans += v[j];
        }
        j--;
        int res = ans;
        for(int i=n-1;i>=n-k;i--){
            ans += v[i];
            ans-= v[j--];
            res = max(res,ans);
        }
        return res;
    }
};