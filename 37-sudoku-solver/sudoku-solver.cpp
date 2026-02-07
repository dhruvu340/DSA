class Solution {
public:
    bool checker(vector<vector<char>>& board ,int row,int col,int c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c||board[i][col]==c)return false;
        }
        int rs=row-row%3;
        int cs=col-col%3;
        for(int i=rs;i<rs+3;i++){
            for(int j=cs;j<cs+3;j++){
                if(board[i][j]==c)return false;
            }
        }


        return true;
    }
    bool solve(vector<vector<char>>& board,int row,int col){
        if(row==9)return true;
        if(col==9)return solve(board,row+1,0);
        if(board[row][col]!='.')return solve(board,row,col+1);
        for(char c='1';c<='9';c++){
            if(checker(board,row,col,c)==false)continue;
            board[row][col]=c;
            bool ans=solve(board,row,col+1);
            if(ans)return true;
            board[row][col]='.';
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};