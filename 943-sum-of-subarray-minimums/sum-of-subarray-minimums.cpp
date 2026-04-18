class Solution {
public:
const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long>left(n,0),right(n,0);
        stack<pair<long long,long long>>s;
        for(int i=0;i<n;i++){
            long long ct= 1;
            while(!s.empty()&&s.top().first > arr[i]){
                ct+=s.top().second;
                s.pop();
            }
            left[i] = ct;
            s.push({arr[i],ct});
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            long long ct= 1;
            while(!s.empty()&&s.top().first >= arr[i]){
                ct+=s.top().second;
                s.pop();
            }
            right[i] = ct;
            s.push({arr[i],ct});
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            ans =( ans +  ((arr[i]%MOD * (left[i]%MOD))%MOD * right[i]%MOD)%MOD)%MOD;
        }
        return ans;
    }
};