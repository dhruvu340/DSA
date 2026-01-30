class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
       
        map<int,int>m;
        for(int i=0;i<n;i++){
            int a=target-nums[i];
            if(m.find(a)!=m.end()){
                return {m[a],i};
            }
            m[nums[i]]=i;
        }

        return {-1,-1};
    }

};