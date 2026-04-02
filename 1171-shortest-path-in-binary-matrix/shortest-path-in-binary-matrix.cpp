class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<pair<int,int>>dir={{0,1},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{-1,0},{0,-1}};
        if(grid[0][0]!=0)return -1;
        queue<vector<int>>q;
        q.push({0,0,1});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front()[0];
                int j=q.front()[1];
                int distance=q.front()[2];
                q.pop();
                if(i==n-1&&j==m-1)return distance;
                for(auto d:dir){
                    int x=i+d.first;
                    int y=j+d.second;
                    
                    if(x<0||x>=n||y>=m||y<0||grid[x][y]!=0){
                        continue;
                    }else{
                        q.push({x,y,distance+1});
                        grid[x][y]=-1;
                    }
                }
            }
        }


        return -1;
    }
};