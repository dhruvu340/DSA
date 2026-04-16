class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(auto i:nums1){
            int j;
            for(j=0;j<nums2.size();j++){
                if(nums2[j]==i)break;
            }
            bool flag = 0;
            while(j<nums2.size()){
                if(nums2[j]>i){
                    ans.push_back(nums2[j]);
                    flag=1;
                    break;
                }

                j++;
            }

            if(!flag){
                ans.push_back(-1);
            }
        }


        return ans;
    }
};