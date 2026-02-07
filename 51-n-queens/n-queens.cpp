class Solution {
public:
    vector<vector<string>>ans;
    bool safe(vector<string>s,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(s[row][i]=='Q')return false;
        }
        for(int i=0;i<n;i++){
            if(s[i][col]=='Q')return false;
        }

        for(int r=row,c=col;r>=0&&c>=0;r--,c--){
            if(s[r][c]=='Q')return false;
        }
        for(int r=row,c=col;r>=0&&c>=0;r--,c++){
            if(s[r][c]=='Q')return false;
        }


        return true;


    }
    void solve(vector<string>s,int row,int n){
        if(row==n){
            ans.push_back(s);
            return ;
        }

        for(int i=0;i<n;i++){
            if(safe(s,row,i,n)){
                s[row][i]='Q';
                solve(s,row+1,n);
                s[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>s(n,string(n,'.'));
        solve(s,0,n);

        return ans;
    }
};