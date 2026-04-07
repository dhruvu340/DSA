class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int>s;
        for(auto i:edges){
            s.insert(i[1]);
        }
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }


        if(ans.size()>1)return -1;

        return ans[0];
    }
};