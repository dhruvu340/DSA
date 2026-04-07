class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int winner=0;
        for(int i=0;i<grid.size();i++){
            if(winner==i)continue;
            if(grid[i][winner]==1){
                winner=i;
            }
        }   
        

        return winner;
    }
};