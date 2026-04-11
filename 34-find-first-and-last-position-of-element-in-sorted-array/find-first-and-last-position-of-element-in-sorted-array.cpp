class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=upper_bound(nums.begin(),nums.end(),target-1) - nums.begin();
        int second=upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;
        if(first<nums.size()&&second<nums.size()&&nums[first]==target&&nums[second]==target){
            return {first,second};
        }

        return {-1,-1};
    }
};