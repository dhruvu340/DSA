class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int l = 0;
        int r = 1;
        vector<int>ans(nums.size());
        for(auto i:nums){
            if(i&1){
                ans[r++]=i;
                r++;
            }else{
                ans[l++]=i;
                l++;
            }
        }
        return ans;
    }
};