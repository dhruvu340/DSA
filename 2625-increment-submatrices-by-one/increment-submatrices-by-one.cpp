class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>prefix(n,vector<int>(n,0));
        for(auto i:queries){
            int r1 = i[0];
            int c1 = i[1];
            int r2 = i[2];
            int c2 = i[3];
            prefix[r1][c1]++;

            if(r2 + 1 < n){
                prefix[r2+1][c1]--;
            }

            if(c2 + 1 < n){
                prefix[r1][c2 + 1]--;
            }

            if(r2+1 < n && c2+1<n){
                prefix[r2+1][c2+1]++;
            }
        }

        for(int i = 1 ; i<n;i++){
            prefix[i][0] += prefix[i-1][0];
            prefix[0][i] +=prefix[0][i-1];
        }

        for(int i = 1;i<n;i++){
            for(int j=1;j<n;j++){
                prefix[i][j] += (prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]);
            }
        }
        return prefix;
        
    }
};