class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        vector<long long>dp(n);
        sort(power.begin(),power.end());
        map<int,int>mpp;
        for(auto i:power)mpp[i]++;
        dp[n-1] = power[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            int gridx = upper_bound(power.begin()+i,power.end(),power[i]+2) - power.begin();
           
                dp[i] = max(dp[i],power[i]*1LL*mpp[power[i]]+ ((gridx<n)?1LL*dp[gridx]:0));
            
        }
        return dp[0];
    }
};