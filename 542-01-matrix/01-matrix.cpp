class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));
        
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){q.push({i,j,0});mat[i][j]=0;}
            }
        }

        
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front()[0];
                int c=q.front()[1];
                int steps=q.front()[2];
                q.pop();
                ans[r][c]=steps;

                for(auto i:dir){
                    int rn=r+i.first;
                    int cn=c+i.second;
                    if(rn<0||rn>=n||cn>=m||cn<0||mat[rn][cn]==0){
                        continue;
                    }else{
                        mat[rn][cn]=0;
                        q.push({rn,cn,steps+1});
                    }
                }
            }
        }


        return ans;

    }
};