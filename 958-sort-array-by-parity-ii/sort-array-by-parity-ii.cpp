class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j = 1;
        
        int n = nums.size();
        for(int i = 0;i<n;i+=2){
            if(nums[i]&1){
                while(nums[j]%2==1){
                    j+=2;
                }
                swap(nums[j],nums[i]);
            }
        }

        return nums;
    }
};