class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>check;
       check[0] = 1;
       int sum = 0;
       int ans = 0;
       for(auto i:nums){
        sum += i;
        int toCheck = sum - k;
        if(check.find(toCheck) != check.end()){
            ans += check[toCheck];
        }
        check[sum]++ ;
       }
       return ans;
    }
};