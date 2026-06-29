class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] ==  color)return image;
        int n = image.size();
        int m= image[0].size();
        queue<vector<int>>q;
       
        q.push({sr,sc,image[sr][sc]});
        vector<vector<int>>vis(n,vector<int>(m,0));
        image[sr][sc]=color;
        vector<vector<int>>v = {{0,1},{1,0},{0,-1},{-1,0}};
        vis[sr][sc] =1;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                int x = q.front()[0];
                int y = q.front()[1];
                int col = q.front()[2];
                q.pop();
                for(auto i:v){
                    int nx = x+i[0];
                    int ny = y+i[1];
                    if(nx<n&&ny<m&&nx>=0&&ny>=0&&image[nx][ny] == col && vis[nx][ny] !=1){
                        q.push({nx,ny,image[nx][ny]});
                        image[nx][ny] = color;
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        return image;
    }
};