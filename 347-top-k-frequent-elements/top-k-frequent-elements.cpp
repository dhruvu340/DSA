class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(auto i:nums)m[i]++;
       vector<vector<int>>bucket(nums.size()+1);
       for(auto i:m){
        bucket[i.second].push_back(i.first);
       }


        vector<int>ans;
        
        for(int i=n;i>=0;i--){
            int j=0;
            int ns=bucket[i].size();
            while(k>0&&j<ns){
                ans.push_back(bucket[i][j++]);
                k--;
            }
        }


        return ans;

    }
};