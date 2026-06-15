class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ct = 0;
        for(auto i:nums)ct^=i;
        return ct;
    }
};