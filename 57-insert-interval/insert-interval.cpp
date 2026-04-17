class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        
        int i=0;
        int n=intervals.size();
        int st = newInterval[0];
        int end = newInterval[1];
        while(i<n&&intervals[i][1]<st){
            res.push_back(intervals[i]);
            i++;
        }
        vector<int>merge={st,end};
        while(i<n&&intervals[i][0]<=end){
            merge[0] = min(intervals[i][0],merge[0]);
            merge[1] = max(intervals[i][1],merge[1]);
            i++;
        }

        res.push_back(merge);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};