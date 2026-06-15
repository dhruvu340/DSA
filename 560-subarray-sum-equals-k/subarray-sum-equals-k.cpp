class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int sum = 0;
        int ans = 0;
        m[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            int toFind = sum - k;
            if(m.find(toFind) != m.end()){
                ans += m[toFind] ; 
            }

            m[sum]++ ;
        }

        return ans;
    }
};