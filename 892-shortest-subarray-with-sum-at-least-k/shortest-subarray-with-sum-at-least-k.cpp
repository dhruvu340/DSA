class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n+1,0);
        pre[1]=nums[0];
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1]*1LL + nums[i-1];
        }
        int l = 0;
        deque<int>q;
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){
            while(!q.empty() && pre[i] - pre[q.front()] >=k){
                ans= min(ans,i - q.front());
                q.pop_front();
            }

            while(!q.empty()&&pre[q.back()] >pre[i] )q.pop_back();
            q.push_back(i);
        }
        return ans == INT_MAX?-1:ans;
    }
};