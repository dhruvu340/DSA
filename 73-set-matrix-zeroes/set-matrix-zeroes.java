class Solution {
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
       int[] row=new int[n];
       int[] col=new int[m];
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
       }


       for(int i=0;i<n;i++){
        if(row[i]==1){
            for(int k=0;k<m;k++){
                matrix[i][k]=0;
            }
        }
       }
       for(int i=0;i<m;i++){
        if(col[i]==1){
            for(int k=0;k<n;k++){
                matrix[k][i]=0;
            }
        }
       }
    }
}