class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=-1;
        int maj2=-1;
        int ct1=0;
        int ct2=0;
        int n=nums.size();
        for(auto i:nums){
            if(maj1==i){
                ct1++;
            }else if(maj2==i){
                ct2++;
            }else if(ct1==0){
                maj1=i;
                ct1=1;
            }else if(ct2==0){
                maj2=i;
                ct2=1;
            }else{
                ct1--;
                ct2--;
            }
        }

        vector<int>ans;
        int r1=count(begin(nums),end(nums),maj1);
        int r2=count(begin(nums),end(nums),maj2);
        if(r1>n/3){
            ans.push_back(maj1);
        }

        if(r2>n/3 && maj2!=maj1){
           ans.push_back(maj2);
        }


        sort(begin(ans),end(ans));
        return ans;
    }
};