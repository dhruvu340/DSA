class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int ct = 0;
        int  i =0;
        int j =n-1;
        int il = 0;
        int jr = n-1;
        vector<int>ans(n);
        while(i<n&&j>=0){
            if(nums[i] < pivot) {
                ans[il++] = nums[i];
            }
            if(nums[j] > pivot){
                ans[jr--] = nums[j];
            }

            i++;
            j--;
        }
        
        while(il<=jr){
            ans[il++] = pivot;
        }

        return ans;
    }
};