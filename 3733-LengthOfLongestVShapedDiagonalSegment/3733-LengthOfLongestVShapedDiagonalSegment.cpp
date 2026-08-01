// Last updated: 01/08/2026, 22:44:31
class Solution {
public:
    vector<pair<int , int>> directions = {{-1 , 1} , {1,1} , {1 , -1} , {-1 , -1}};

    int dfs(int i , int j , int expected , int d , bool turned , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0||j>=m)return 0;
        if (grid[i][j] != expected) return 0;

        int nextExpected = (expected == 2? 0 : 2);

        int len = 1 + dfs(i + directions[d].first , j + directions[d].second , nextExpected , d , turned , grid);

        if(!turned){
            int newD = (d + 1)% 4;
            len = max(len , 1 + dfs(i + directions[newD].first , j + directions[newD].second , nextExpected , newD , true , grid));
        }


        return len;

    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxLen = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ;j < m ; j++){
                if(grid[i][j] == 1){
                    for(int d = 0 ; d < 4 ; d++){
                        maxLen = max(maxLen , dfs(i , j , 1 , d , false , grid));
                    }
                }
            }
        }

        return maxLen;
    }
};