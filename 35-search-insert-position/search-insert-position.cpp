class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx=lower_bound(begin(nums),end(nums),target)-nums.begin();
        return idx;
    }
};