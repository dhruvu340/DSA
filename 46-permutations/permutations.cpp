class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(auto num : nums){
            if(find(temp.begin(),temp.end(),num)==temp.end()){
                temp.push_back(num);
                solve(nums,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        solve(nums,temp);
        return ans;
    }
};