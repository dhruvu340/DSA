class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int> &nums,int i,vector<int>&t,int target){
        
        if(target==0){
            ans.insert(t);
            return ;
        }
        for(int idx=i;idx<nums.size();idx++){
            if(idx>i&&nums[idx]==nums[idx-1])continue;
            if(nums[idx]>target)break;
            t.push_back(nums[idx]);
            solve(nums,idx+1,t,target-nums[idx]);
            t.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(begin(candidates),end(candidates));
        solve(candidates,0,temp,target);
       vector <vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};