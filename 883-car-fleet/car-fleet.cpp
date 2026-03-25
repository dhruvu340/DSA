class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        float prev=(long double)(target - v[0].first )/v[0].second;
        int ct=1;
        for(int i=1;i<n;i++){
            float time  = (float)(target - v[i].first )/v[i].second;
            if(time>prev){
                prev=time;
                ct++;

            }
        }
        return ct;;
    }
};