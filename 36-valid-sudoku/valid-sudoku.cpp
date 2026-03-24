class Solution {
public:
   
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>row(9),col(9);

        unordered_map<string,unordered_set<int>>box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                string t= to_string(i/3) + "#" + to_string(j/3);

                if(row[i].count(board[i][j])||col[j].count(board[i][j])||box[t].count(board[i][j])){
                    return false;
                }

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[t].insert(board[i][j]);
            }
        }


        return true;
        
    }
};
