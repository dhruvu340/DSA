class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0;
        int ans=0;
        for(auto i:nums){
            if(i==1)ct++;
            else{ans=max(ans,ct);ct=0;}

        }
        ans=max(ans,ct);

        return ans;
    }
};