class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum = 0 ;
        int ans = 0;
        for(int l = 0 , r = 0 ;r<n;r++){
            sum += nums[r]*1LL;
            while(l <= r && (r-l+1)*1LL*nums[r] - sum > k){
                sum -= nums[l++];
            }
            if((r-l+1)*1LL*nums[r] - sum <= k ){
                ans = max(ans,r-l+1);
            }
        }

        return ans;
    }
};