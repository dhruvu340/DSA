class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base case: last row
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                dp[n-1][i][j] = grid[n-1][i];
                if(i != j) dp[n-1][i][j] += grid[n-1][j];
            }
        }

        // Fill DP from bottom to top
        for(int i = n-2; i >= 0; i--) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = 0; c2 < m; c2++) {

                    int best = 0;

                    for(int dc1 = -1; dc1 <= 1; dc1++) {
                        for(int dc2 = -1; dc2 <= 1; dc2++) {

                            int nc1 = c1 + dc1;
                            int nc2 = c2 + dc2;

                            if(nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m) {
                                best = max(best, dp[i+1][nc1][nc2]); // ✅ FIXED
                            }
                        }
                    }

                    dp[i][c1][c2] = best + grid[i][c1];
                    if(c1 != c2) dp[i][c1][c2] += grid[i][c2];
                }
            }
        }

        return dp[0][0][m-1]; // robots start at (0,0) and (0,m-1)
    }
};