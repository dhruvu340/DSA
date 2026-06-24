class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-1;i++){
            ans=max(ans,abs(nums[i] - nums[i+1]));
        }
        return ans;
    }
};