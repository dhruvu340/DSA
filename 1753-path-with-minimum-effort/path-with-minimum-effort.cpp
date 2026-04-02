class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        q.push({0,0,0});
        dist[0][0]=0;
        while(!q.empty()){
            int i=q.top()[1];
            int j=q.top()[2];
            int efforts=q.top()[0];
            q.pop();
            if(i==n-1&&j==m-1)return efforts;


            for(auto d:dir){
                int x=i+d.first;
                int y=j+d.second;
                if(x<0||x>=n||y<0||y>=m||heights[x][y]==-1)continue;

                int minefforts=max(efforts,abs(heights[i][j]-heights[x][y]));

                if(minefforts<dist[x][y]){
                    
                    dist[x][y]=minefforts;
                    q.push({minefforts,x,y});
                }
                
            }
        }

        return 0;
    }
};


