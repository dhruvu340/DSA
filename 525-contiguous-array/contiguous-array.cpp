class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &i:nums){
            if(!i){
                i=-1;
            }
        }

        map<int,int>m;
        m[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.find(sum)!=m.end()){
                ans=max(ans,i-m[sum]);
            }else
            {m[sum]=i;}
        }
    return ans;
    }
};