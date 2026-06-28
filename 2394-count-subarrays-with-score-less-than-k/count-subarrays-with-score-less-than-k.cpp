class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int n=nums.size();
        long long ans = 0;
        for(int i=0,j=0;j<n;j++){
            sum += 1LL*nums[j];
            while(i<=j && sum*1LL*(j-i+1) >= k){
                sum -= 1LL*nums[i];
                i++;
            }
            
                ans += 1LL*(j-i+1);
            
        }
        return ans;
    }
};