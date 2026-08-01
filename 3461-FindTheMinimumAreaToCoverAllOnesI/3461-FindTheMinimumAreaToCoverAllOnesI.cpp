// Last updated: 01/08/2026, 22:44:32
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minH = 0;
        int minW = 0;
        vector<int> numsRow(grid.size() , 0);
        vector<int> numsCols(grid[0].size() , 0);
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    numsRow[i] = 1;
                    numsCols[j] = 1;
                }
            }
        }

        int widthL = 0;
        int widthR = numsRow.size() - 1;
        int heightL = 0;
        int heightR = numsCols.size() - 1;
        while(numsRow[widthL] == 0){
            widthL++;
        }
        while(numsRow[widthR] == 0){
            widthR--;
        }
        while(numsCols[heightR] == 0){
            heightR--;
        }
        while(numsCols[heightL] == 0){
            heightL++;
        }

        int width = widthR - widthL + 1;
        int height = heightR - heightL + 1;
        return width*height;
    }
};