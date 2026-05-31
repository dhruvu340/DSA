class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n=nums.size();
        int sum = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum >= target && l<=i){
                ans = min(ans,i-l+1);
                sum -= nums[l++];
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};