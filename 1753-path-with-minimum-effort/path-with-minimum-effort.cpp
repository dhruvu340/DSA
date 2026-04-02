class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        queue<vector<int>>q;
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        q.push({0,0});
        dist[0][0]=0;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int efforts=dist[i][j];
            q.pop();
            


            for(auto d:dir){
                int x=i+d.first;
                int y=j+d.second;
                if(x<0||x>=n||y<0||y>=m||heights[x][y]==-1)continue;

                int minefforts=max(efforts,abs(heights[i][j]-heights[x][y]));

                if(minefforts<dist[x][y]){
                    
                    dist[x][y]=minefforts;
                    q.push({x,y});
                }
                
            }
        }

        return dist[n-1][m-1];
    }
};


