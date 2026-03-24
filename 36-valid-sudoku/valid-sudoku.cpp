class Solution {
public:
    bool solve(vector<vector<char>>& board,int target , int n,int m,int row,int col){
        for(int i=0;i<m;i++){
            if(i==col)continue;

            if(board[row][i]==target)return false;
        }

        for(int i=0;i<n;i++){
            if(i==row)continue;

            if(board[i][col]==target)return false;
        }


        int startRow = (row / 3) * 3;
int startCol = (col / 3) * 3;

for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
        if (i == row && j == col) continue;

        if (board[i][j] == target) return false;
    }
}


return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'&& solve(board,board[i][j],n,m,i,j)==false){
                    return false;
                }
            }
        }

        return true;
    }
};
