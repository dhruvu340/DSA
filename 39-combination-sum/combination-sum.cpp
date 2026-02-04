class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int> &nums,int i,vector<int>&t,int target){
        if(i==nums.size()||target<0)return;
        if(target==0){
            ans.insert(t);
        }
        t.push_back(nums[i]);
        solve(nums,i+1,t,target-nums[i]);
        solve(nums,i,t,target-nums[i]);
        t.pop_back();
        solve(nums,i+1,t,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums,0,temp,target);
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};