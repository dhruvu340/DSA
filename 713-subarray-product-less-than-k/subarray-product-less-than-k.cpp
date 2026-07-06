class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0;
        double logK = log(k);
        int n = nums.size();
        vector<double>logsPrefixSum(nums.size(),0);
        logsPrefixSum[0] = log(nums[0]);
        for(int i = 1;i<nums.size();i++){
            logsPrefixSum[i] = logsPrefixSum[i-1] + (double)log(nums[i]);
        }
        int ans = 0;
        for(int i = 0 ;i<n;i++){
            int curr = i-1;
            double prev = (curr>=0)?logsPrefixSum[curr]:0;
            double toFind = prev + logK - 1e-9;
            int lastIdx = upper_bound(logsPrefixSum.begin()+i,logsPrefixSum.end(),toFind)-logsPrefixSum.begin();
            ans += lastIdx - i;
        }
        return ans;
    }
};