class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int ans=0;
        int sum=0;
        for(auto i:nums){
            sum+=i;
         
                ans+=m[sum-k];
            
            m[sum]++;
        }

        return ans;
    }
};