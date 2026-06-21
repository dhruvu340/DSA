class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int ct = 0 ;
        for(auto i:nums){
            if(i==maj)ct++;
            else{
                ct--;
                if(ct<0){
                    ct = 1;
                    maj = i;
                }
            }
        }

        return maj;
    }
};