class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
       map<int,int>m;
       for(int i=0;i<n;i++){
        int s=target-nums[i];
        if(m.find(s)!=m.end())return {m[s],i};
        m[nums[i]]=i;
       }

       return {-1,-1};
    }

};