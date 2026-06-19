class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int>prefix(n+1,0);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({people[i],i});
        }
        sort(v.begin(),v.end());

        for(int i = 0;i<m;i++){
            int l = flowers[i][0];
            int r = flowers[i][1];
            pair<int,int> p={l,INT_MIN};
            int idx = lower_bound(v.begin(),v.end(),p)-v.begin();
            prefix[idx]++;
            p={r+1,INT_MIN};
             idx = lower_bound(v.begin(),v.end(),p)-v.begin();
            prefix[idx]--;
        }


        for(int i=1;i<n;i++)prefix[i] += prefix[i-1];

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[v[i].second] = prefix[i];
        }
        return ans;
    }
};