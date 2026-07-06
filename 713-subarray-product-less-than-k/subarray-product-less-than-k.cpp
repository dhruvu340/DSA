class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        long long p = 1;
        int n = nums.size();
        for(int l=0,r=0;r<n;r++){
            p*=nums[r]*1LL;
            while(l<=r && p>=k){
                p/=nums[l++];
            }
            ans += r-l+1;
        }
        return ans;
    }
};