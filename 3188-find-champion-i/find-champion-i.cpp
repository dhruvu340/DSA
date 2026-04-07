class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            int ct=0;
            for(int j=0;j<grid[0].size();j++){
                if(i!=j&&grid[i][j]==1){
                   ct++;
                }
            }
            if(ct==grid[0].size()-1){
                return i;
            }
        }
        

        return -1;
    }
};