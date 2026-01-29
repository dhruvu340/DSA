class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=-1;
        int ct=-1;
        for(auto i:nums){
            if(maj==-1&&ct==-1){
                maj=i;
                ct=1;
            }else if(i==maj){
                ct++;
            }else{
                ct--;
                if(ct==-1){
                    maj=i;
                    ct=1;
                }
            }
        }

        return maj;
    }
};