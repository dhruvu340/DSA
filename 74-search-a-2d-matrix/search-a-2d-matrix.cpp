class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int l=0;
        int r=m*n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int row=(mid/m);
            int col=mid%m;
            if(nums[row][col]==target)return true;
            else if(nums[row][col]>target)r=mid-1;
            else l=mid+1;
        }

        return false;

        
    }
};