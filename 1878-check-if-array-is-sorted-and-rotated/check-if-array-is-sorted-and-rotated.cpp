class Solution {
public:
    bool check(vector<int>& nums) {
        int ct  = 0;
        int i;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])ct++;
        }
        if(nums[n-1]>nums[0])ct++;
        return ct <= 1;
    }
};