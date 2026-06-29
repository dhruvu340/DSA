class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       int n=nums.size();
       long long sum = 0;
       int ans = INT_MAX;
       deque<pair<long long,int>>q;
       q.push_back({0,-1});
       for(int i = 0;i<n;i++){
            sum += nums[i];
            while(!q.empty() && q.back().first >= sum)q.pop_back();
            q.push_back({sum,i});
            while(!q.empty() && sum - q.front().first >= k){
                ans=min(ans,i-q.front().second);
                q.pop_front();
            }
       }

       return (ans == INT_MAX ) ? -1 : ans; 
    }
};