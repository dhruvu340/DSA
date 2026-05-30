class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int l = 0;
        int r = 1;
        for(auto i:nums){
            if(i>=0){
                ans[l]=i;
                l+=2;
            }else{
                ans[r]=i;
                r+=2;
            }
        }
        return ans;
    }
};