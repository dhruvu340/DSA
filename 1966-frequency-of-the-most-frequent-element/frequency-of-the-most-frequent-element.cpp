class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        long long sum  = 0;
        int n = nums.size();
        for(int l = 0,r=0;r<n;r++){
            sum += 1LL*nums[r];
            while(l<=r&&(r-l+1)*1LL*nums[r] - sum >k){
                sum -= 1LL*nums[l++];
            }
            ans =  max(ans,r-l+1);
        }
        return ans;
    }
};