// Last updated: 04/09/2026, 02:15:24
class Solution {
public:
    void dfs(vector<vector<char>>& grid , set<pair<int,int>>& visited , pair<int,int> current , stack<pair<int , int>>& toVisit){
        int i = current.first;
        int j = current.second;
        grid[i][j] = '0';
        visited.insert(current);
        if(i+1 < grid.size() && grid[i+1][j] == '1'){
            toVisit.push({i + 1 , j});
        }
        if(i > 0 && grid[i-1][j] == '1'){
            toVisit.push({i-1 , j});
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == '1'){
            toVisit.push({i , j + 1});
        }
        if(j > 0 && grid[i][j-1] == '1'){
            toVisit.push({i , j-1});
        }
        if(!toVisit.empty()){
            pair<int,int> next = toVisit.top();
            toVisit.pop();
            dfs(grid , visited , next , toVisit);
        }

        return;

    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        set<pair<int , int>> visited;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                pair<int,int> current = {i,j};
                if(visited.find(current) == visited.end()){
                    if(grid[i][j] == '1'){
                        stack<pair<int,int>> toVisit;
                        count++;
                        dfs(grid , visited , current , toVisit);
                    }else{
                        continue;
                    }
                }else{
                    continue;
                }
            }
        }

        return count;
    }
};