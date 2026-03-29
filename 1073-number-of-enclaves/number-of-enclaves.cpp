class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && (i==0||i==n-1||j==0||j==m-1)){
                    q.push({i,j});
                    board[i][j]=0;
                   
                }
            }
        }
        vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                for(auto i:dir){
                    int rn=r+i.first;
                    int cn=c+i.second;
                    if(rn<n&&rn>=0&&cn<m&&cn>=0&&board[rn][cn]==1){
                        board[rn][cn]=0;
                        q.push({rn,cn});
                    }
                }

            }
        }

    int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ct+=board[i][j];
            }
        }
        return ct;
    }
};