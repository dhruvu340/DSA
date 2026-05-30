class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
           while(nums[i]>0&&nums[i]-1<nums.size()&&nums[i]!=nums[nums[i]-1]){ swap(nums[nums[i]-1],nums[i]);}
        }
        int ct = 1;
        
        
        for(auto i:nums){
            if(i==ct){
                ct++;
            }
        }
        return ct;
    }
};