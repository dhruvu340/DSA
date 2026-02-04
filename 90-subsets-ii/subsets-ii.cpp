class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int>nums,int i,vector<int>temp){
        if(i>=nums.size()){
            ans.insert(temp);
            return ;
        }

        temp.push_back(nums[i]);
        solve(nums,i+1,temp);
        temp.pop_back();
        solve(nums,i+1,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>temp;
        solve(nums,0,temp);
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};