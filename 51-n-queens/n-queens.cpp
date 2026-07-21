class Solution {
public:
    vector<vector<string>>ans;
    bool safe(int i,int j,vector<string>temp){
        //col
        for(int r = i ; r>=0 ;r--){
            if(temp[r][j]=='Q')return false;
        }

        for(int r=i,c=j;r>=0&&c>=0;r--,c--){
            if(temp[r][c]=='Q')return false;
        }

        for(int r=i,c=j;r>=0&&c<temp.size();r--,c++){
            if(temp[r][c]=='Q')return false;
        }
        return true;
    }
    void solve(vector<string> &temp,int row,int n){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(safe(row,i,temp)){
                temp[row][i] = 'Q';
                solve(temp,row+1,n);
                temp[row][i] = '.';
            }
        }


        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        
       vector<string>temp(n,string(n,'.'));
        solve(temp,0,n);
        return ans;
    }
};