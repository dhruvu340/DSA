class Solution {
public:
    
    
    bool canJump(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi>=i){maxi=max(maxi,nums[i]+i);}else{
                return false;
            }
        }

        return true;
    }
};