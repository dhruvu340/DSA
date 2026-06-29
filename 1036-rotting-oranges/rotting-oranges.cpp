class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ctOfones = 0;
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }else if(grid[i][j]==1)ctOfones++;
            }
        }

        
        int ans = 0;
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int topElx = q.front()[0];
                int topEly = q.front()[1];
                int c = q.front()[2];
                q.pop();
                for(auto i:dir){
                    int newx = topElx + i.first;
                    int newy = topEly + i.second;

                    if(newx >=0 && newy>=0 && newx<n && newy<m&&grid[newx][newy] == 1){
                        grid[newx][newy] = 2;
                        ans=max(ans,c+1);
                        ctOfones--;
                        q.push({newx,newy,c+1});
                    }
                }
            }
           
        }

        if(ctOfones)return -1;

        return ans;
        
    }
};