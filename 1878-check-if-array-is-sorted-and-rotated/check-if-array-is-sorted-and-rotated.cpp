class Solution {
public:
    bool check(vector<int>& nums) {
        int ct  = 0;
        int i;
        int n=nums.size();
       nums.insert(nums.end(),nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(is_sorted(nums.begin() + i,nums.begin()+i + n ))return true;

       }
       return false;
    }
};