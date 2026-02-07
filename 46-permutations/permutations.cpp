class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int> &temp,vector<bool>&used){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int idx=0;idx<nums.size();idx++){
            if(used[idx])continue;
            used[idx]=true;
            temp.push_back(nums[idx]);
            solve(nums,temp,used);
            temp.pop_back();
            used[idx]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int>temp;
    vector<bool>used(nums.size(),false);
    solve(nums,temp,used);
    return ans; 

        
    }
};