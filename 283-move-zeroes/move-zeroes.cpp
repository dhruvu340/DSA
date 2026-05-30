class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = -1;
        for(auto i:nums){
            if(i!=0){
                l++;
                nums[l]=i;
            }
        }
        for(int i=l+1;i<nums.size();i++){
            nums[i]=0;
        }
        
    }
};