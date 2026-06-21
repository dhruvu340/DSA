class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m));
        prefix[0][0] = matrix[0][0];
        for(int i=1;i<n;i++){
            prefix[i][0] = prefix[i-1][0] + matrix[i][0];
        }
        for(int i=1;i<m;i++){
            prefix[0][i] = prefix[0][i-1] + matrix[0][i];
        }

        for(int i = 1;i<n;i++){
            for(int j=1;j<m;j++){
                prefix[i][j] = matrix[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int rs = 1;i+rs<=n;rs++){
                for(int j = 0;j<m;j++){
                    for(int cs=1;j+cs<=m;cs++){
                        int r1 = i;
                        int c1 = j;

                        int r2 = i + rs - 1;
                        int c2 = j + cs - 1;

                        int sum = prefix[r2][c2];
                        if(r1-1>=0){
                            sum -= prefix[r1-1][c2];
                        }
                        if(c1-1>=0){
                            sum -= prefix[r2][c1-1];
                        }

                        if(r1-1>=0 && c1-1>=0){
                            sum += prefix[r1-1][c1-1];
                        }

                        if(sum == target)ans++;
                    }
                }
            }
        }

        return ans;
    }
};