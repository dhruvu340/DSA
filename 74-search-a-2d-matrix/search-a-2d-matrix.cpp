class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        //declare root of the bst.
        int i=0;
        int j=m-1;
        while(i<n&&j>=0&&nums[i][j]!=target){
            if(nums[i][j]>target){
                //move left
                j--;
            }else{
                //move down
                i++;
            }
        }

        if(i>=n||j<0){
            return false;
        }else{
            return true;
        }

        
    }
};