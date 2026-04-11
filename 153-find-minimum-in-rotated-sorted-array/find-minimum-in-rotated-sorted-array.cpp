class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            rotate(nums.begin(),nums.begin()+1,nums.end());
            if(is_sorted(nums.begin(),nums.end()))return nums[0];
        }
        return -1;
    }
};