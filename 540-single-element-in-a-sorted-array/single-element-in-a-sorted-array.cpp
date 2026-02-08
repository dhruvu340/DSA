class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x_or=0;
        for(auto i:nums)x_or^=i;
        return x_or;
    }
};