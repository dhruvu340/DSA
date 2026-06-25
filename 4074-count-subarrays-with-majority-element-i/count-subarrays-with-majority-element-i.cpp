class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n =nums.size();
        int ans=0;
        vector<int>pre(2*n+1,0);
        pre[n] = 1;
        int ct = n;
        int sum = 0;
        for(auto i:nums){
            if(i==target){
                sum += pre[ct];
                ct++;
                ++pre[ct];
            }else{
                ct--;
                sum -= pre[ct];
                ++pre[ct];
            }
            ans+=sum;
        }

        return ans;
    }
};