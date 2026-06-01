class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int l=0;
        int r=m-1;
        while(l<n&&r<m&&l>=0&&r>=0){
           if(nums[l][r]==target)return true;
           else if(nums[l][r]>target)r--;
           else l++;
        }
        return false;   
    }
};