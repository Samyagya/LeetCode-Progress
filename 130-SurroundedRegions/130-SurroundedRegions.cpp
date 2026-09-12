// Last updated: 13/09/2026, 03:11:23
class Solution {
public:
    void bfs(vector<vector<char>>& board, pair<int,int> current){
        vector<pair<int,int>> visited;
        // board[i][j] = 'T';
        queue<pair<int,int>> q;
        q.push(current);
        vector<vector<int>> dirs = {{-1,0} , {1,0} , {0,1} , {0,-1}};
        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();
            if(board[top.first][top.second] == 'O'){
                board[top.first][top.second] = 'T';
                for(int i = 0 ; i < 4 ; i++){
                    int r = top.first + dirs[i][0];
                    int c = top.second + dirs[i][1];
                    if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()){
                        continue;
                    }
                    if(board[r][c] == 'O'){
                        q.push({r,c});
                    }
                }
            }else{
                continue;
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // vector<pair<int,int>> allOs;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1){
                    if(board[i][j] == 'O'){
                        pair<int,int> current = {i,j};
                        bfs(board , current);
                    }
                }
            }
        }

        for(int i = 0 ; i < board.size() ; i ++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }else{
                    continue;
                }
            }
        }
    }
};