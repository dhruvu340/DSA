class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        vector<int>ans(temperatures.size(),0);
        for(int i = 0 ;i<temperatures.size() ; i++){
            while(!s.empty()&&s.top().second < temperatures[i]){
                ans[s.top().first] = i-s.top().first;
                s.pop();
            }
            s.push({i,temperatures[i]});
        }
        return ans; 
    }
};