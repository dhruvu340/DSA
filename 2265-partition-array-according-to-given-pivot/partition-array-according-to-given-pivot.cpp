class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int ct = 0;
        for(auto i:nums){
            if(i>=pivot)ct++;
        }
        int idxOfPivot = n - ct;
        int smallerIndex = 0;
        vector<int>ans(n);
        for(auto i:nums){
            if(i<pivot){
                ans[smallerIndex++] = i;
            }
        }

        for(auto i:nums){
            if(i==pivot){
                ans[smallerIndex++] = i;
            }
        }

        for(auto i:nums){
            if(i>pivot){
                ans[smallerIndex++] = i;
            }
        }

        

        return ans;
    }
};