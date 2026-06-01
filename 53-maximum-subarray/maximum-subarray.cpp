class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ct = 0;
        int ans = INT_MIN;
        for(auto i:nums){
           ct += i;
           ans = max(ans,ct);
           if(ct<0){
            ct=0;
           }
        }
        ans = max(ans,ct);
        int minel = *max_element(nums.begin(),nums.end());

        if(ans == 0){
            if(count(nums.begin(),nums.end(),0)==0)return minel;
        }
        return (ans==INT_MIN) ? minel : ans;
        
    }
};