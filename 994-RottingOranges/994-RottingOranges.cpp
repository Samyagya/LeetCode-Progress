// Last updated: 09/09/2026, 11:11:49
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<vector<int>> dirs = {{-1,0} , {1,0} , {0,-1} , {0,1}};

        bool converted = false;
        while(fresh > 0){
            for(int i = 0 ; i < grid.size() ; i ++){
                for(int j = 0 ; j < grid[0].size() ; j++){
                    if(grid[i][j] == 2){
                        for(int d = 0 ; d < 4 ; d++){
                            int r = i + dirs[d][0];
                            int c = j + dirs[d][1];

                            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
                                continue;
                            }else if(grid[r][c] == 1){
                                grid[r][c] = 3;
                                fresh--;
                                converted = true;
                            }
                        }
                    }
                }
            }

            if(converted == false){
                return -1;
            }

            for(int i = 0 ; i < grid.size() ; i++){
                for(int j = 0 ; j < grid[0].size() ; j++){
                    if(grid[i][j] == 3){
                        grid[i][j] = 2;
                    }
                }
            }

            time++;
            converted = false;
        }

        return time;

    }
};