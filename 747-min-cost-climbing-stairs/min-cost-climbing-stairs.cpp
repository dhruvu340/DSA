class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(1001,-1);
        auto solve= [&](auto&& self, int i ) {
            if(i>=cost.size())return 0;
            if(dp[i]!=-1)return dp[i];

            return dp[i] = cost[i] + min (self(self,i+1),self(self , i+2));
        };  

        return min(solve(solve , 0) , solve(solve , 1));

    }
};