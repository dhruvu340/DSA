class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sumAverage = 0;
        int ans = 0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sumAverage  += arr[i];
            if(i>=k){
                sumAverage -= arr[i-k];
            }
            if(i>=k-1){
                int average=sumAverage/k;
                ans += (average>=threshold);
            }
        }

        return ans;
    }
};