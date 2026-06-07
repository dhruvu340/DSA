class Solution {
public:
    unordered_map<int,int>m;
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,set<int>>m;
        m[1] = {1};
        for(int i = 1;i<n;i++){
            for(auto diff:m[stones[i]]){
                m[stones[i] + diff].insert(diff);
                m[stones[i] + diff+1].insert(diff+1);
                m[stones[i] + diff-1].insert(diff-1);
            }
        }


        return m[stones[n-1]].size() ? true : false;

    }
};