class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }

        vector<int>dp(1e4+1);
        dp[0]=0;
        dp[1]=m[1]*1;
        for(int i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1],((i-2>=0)?m[i]*i + dp[i-2]:0));
        }


        return dp[1e4];


    


        
    }
};