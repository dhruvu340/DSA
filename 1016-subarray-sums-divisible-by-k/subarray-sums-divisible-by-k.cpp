class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>check;
       check[0] = 1;
       int sum = 0;
       int ans = 0;
       for(auto i:nums){
        sum += i;
        int toCheck = sum % k;
        if(toCheck < 0)toCheck += k;
        if(check.find(toCheck) != check.end()){
            ans += check[toCheck];
        }
        check[toCheck]++ ;
       }
       return ans;
    }
};