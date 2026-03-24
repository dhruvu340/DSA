class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==1)return {0};
        

        vector<int>v(nums.size());
        v[0]=1;
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]*nums[i-1];
        }

        int ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            v[i]*=ans;
            ans*=nums[i];
        }


        return v;
        
    }
};