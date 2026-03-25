class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        stack<float>st;
        for(int i=0;i<n;i++){
            float time = ((long double)target-v[i].first)/v[i].second;
            if(st.empty()||time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};