class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>temp,int i){
        if(i==temp.size()){
            ans.push_back(temp);
            return ;
        }

        for(int idx = i;idx<temp.size();idx++){
            swap(temp[i],temp[idx]);
            solve(temp,i+1);
            swap(temp[i],temp[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp(nums.begin(),nums.end());
        solve(temp,0);
        return ans;
    }
};