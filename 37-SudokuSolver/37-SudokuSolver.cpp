// Last updated: 01/08/2026, 22:47:29
class Solution {
public:
    bool solve(vector<vector<char>>& board , vector<unordered_set<char>>& rows , vector<unordered_set<char>>& cols ,vector<unordered_set<char>>& boxes, int i , int j){

        if(i == 9) return true;
        int nextI = i;
        int nextJ = j + 1;
        if(j==8){
            nextI++;
            nextJ = 0;
        }

        int boxIndex = (i/3) * 3 + (j/3);
        if(board[i][j] == '.'){
            for(char c = '1' ; c <= '9' ; c++){
                if(!rows[i].count(c) && !cols[j].count(c) && !boxes[boxIndex].count(c)){
                    board[i][j] = c;
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxes[boxIndex].insert(c);

                    if(solve(board , rows , cols , boxes , nextI , nextJ)) return true;

                    board[i][j] = '.';
                    rows[i].erase(c);
                    cols[j].erase(c);
                    boxes[boxIndex].erase(c);
                }
            }

        }else{
            return solve(board , rows , cols ,boxes, nextI , nextJ);
        }

        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9) , cols(9) , boxes(9);
        for(int i = 0; i < 9 ; i ++){
            for(int j = 0; j < 9 ; j ++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    rows[i].insert(c);
                    cols[j].insert(c);
                    int box = (i/3)*3 + (j/3);
                    boxes[box].insert(c);
                }
            }
        }

        solve(board , rows , cols ,boxes, 0 , 0);
    }
};