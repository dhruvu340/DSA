class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        

        int ans = 0;

        for(int c = 0 ; c<m;c++){
            for(int j = c;j<m;j++){
                unordered_map<int,int>m;
                m[0] = 1;
                int sum = 0;
                for(int i = 0;i<n;i++){
                    sum += matrix[i][j] - ((c>0) ? matrix[i][c-1] : 0);
                    if(m.find(sum - target) != m.end()){
                        ans += m[sum-target]; 
                    }
                    m[sum]++;
                }
            }
        }
        return ans;
    }
};