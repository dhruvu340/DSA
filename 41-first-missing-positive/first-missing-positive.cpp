class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ct = 1;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            if(i==ct){
                ct++;
            }
        }
        return ct;
    }
};