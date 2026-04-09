class Solution {
public:
    
   
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m)));
       for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            dp[n-1][i][j]=grid[n-1][i];
            if(i!=j){
                dp[n-1][i][j]+=grid[n-1][j];
            }
        }
       }

       for(int i=n-2;i>=0;i--){
        for(int c1=0;c1 <= min(m-1,i);c1++){
            for(int c2=max(m-i-1,0);c2<m;c2++){
                dp[i][c1][c2]=0;
                for(int prevc1=max(0,c1-1);prevc1<=min(m-1,c1+1);prevc1++){
                    for(int prevc2=max(0,c2-1);prevc2<=min(m-1,c2+1);prevc2++){
                        dp[i][c1][c2]=max(dp[i][c1][c2],dp[i+1][prevc1][prevc2]);
                    }
                }

                dp[i][c1][c2]+=grid[i][c1];
                if(c1!=c2){
                    dp[i][c1][c2]+=grid[i][c2];
                }
            }
        }
       }



       int maxans=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            maxans=max(maxans,dp[0][i][j]);
        }
       }


       return maxans;
    }
};