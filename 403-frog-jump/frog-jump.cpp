class Solution {
public:
    unordered_map<int,int>m;
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(stones.size(),vector<int>(n,false));
        for(int i=0;i<n;i++)dp[n-1][i] = true;
        for(int i=0;i<n;i++)m[stones[i] ]=i;
        if(stones[1]!=1)return false;
        for(int i = n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=false;
                for(int diff = j-1;diff<=j+1;diff++){
                 if(diff>0&&diff<n&&m.find(stones[i] + diff)!=m.end()){
                    dp[i][j]|= dp[m[stones[i] + diff]][diff];
                    }

                }
            }
        }

        return dp[1][1];

    }
};