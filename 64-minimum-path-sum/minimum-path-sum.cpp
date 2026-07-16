class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0)continue;

                dp[i][j] = grid[i][j];
                int toAdd = INT_MAX;
                if(i-1>=0)toAdd = min(toAdd,dp[i-1][j]);
                if(j-1>=0)toAdd = min(toAdd,dp[i][j-1]);
                dp[i][j] += toAdd;
            }
        }

        return dp[n-1][m-1];
    }
};