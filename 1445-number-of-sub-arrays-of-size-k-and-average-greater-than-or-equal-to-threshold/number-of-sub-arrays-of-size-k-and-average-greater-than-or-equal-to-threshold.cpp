class Solution {
public:
    int numOfSubarrays(vector<int>& v, int k, int threshold) {
        int n = v.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            sum += v[i];
            if(i>=k)sum-=v[i-k];
            if(i>=k-1 && sum/k >= threshold)ans++;
        }
        return ans;
    }
};