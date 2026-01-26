class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        bool flag =false;
        while((i<matrix.size())&&j>=0){
            if(matrix[i][j]==target){flag=true;break;}
            else if(matrix[i][j]>target){
                j--;
            }else{
                i++;
            }
        }


        return flag;
    }
};