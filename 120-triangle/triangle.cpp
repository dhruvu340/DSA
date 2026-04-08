class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>front(n,0);
        for(int i=0;i<n;i++){
            front[i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=0;j<=i;j++){
                int dl=front[j]+triangle[i][j];
                int dr=front[j+1]+triangle[i][j];
                curr[j]=min(dl,dr);
            }
            front=curr;
        }


        return front[0];
    }
};