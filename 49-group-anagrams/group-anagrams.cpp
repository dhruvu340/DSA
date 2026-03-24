class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>m;
       for(auto i:strs){
        string temp=i;
        sort(temp.begin(),temp.end());
        m[temp].push_back(i);
       }

       vector<vector<string>>ans;
       for(auto i:m){
        vector<string>t;
        for(auto j:i.second){
            t.push_back(j);
        }
        ans.push_back(t);
       }

        return ans;
    }
};