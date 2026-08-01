// Last updated: 01/08/2026, 22:47:04
class Solution {
public:
    bool answer = false;
    void backtracking(vector<vector<char>>& board , string& s , string& word , pair<int , int> last){
        if(answer){
            return;
        }
        if(s.empty()){
            for(int row = 0 ; row < board.size() ; row++){
                for(int col = 0 ; col < board[row].size() ; col++){
                    if(board[row][col] == word[0]){
                        s.push_back(board[row][col]);
                        char letter = board[row][col];
                        board[row][col] = '#';
                        backtracking(board , s , word , {row , col});
                        board[row][col] = letter;
                        s.pop_back();
                    }
                }
            }
        }
        else if(s.size() == word.size()){
            answer = true;
            return;
        }else{
            int lastRow = last.first;
            int lastCol = last.second;
            if(lastRow + 1 < board.size() && board[lastRow + 1][lastCol] == word[s.size()]){
                s.push_back(board[lastRow+1][lastCol]);
                char letter = board[lastRow+1][lastCol];
                board[lastRow+1][lastCol] = '#';
                backtracking(board , s , word , {lastRow + 1 , lastCol});
                board[lastRow+1][lastCol] = letter;
                s.pop_back();
            }
            if(lastRow - 1 >= 0 && board[lastRow - 1][lastCol] == word[s.size()]){
                s.push_back(board[lastRow-1][lastCol]);
                char letter = board[lastRow-1][lastCol];
                board[lastRow-1][lastCol] = '#';
                backtracking(board , s , word , {lastRow - 1 , lastCol});
                board[lastRow-1][lastCol] = letter;
                s.pop_back();                
            }
            if(lastCol + 1 < board[lastRow].size() && board[lastRow][lastCol + 1] == word[s.size()]){
                s.push_back(board[lastRow][lastCol+1]);
                char letter = board[lastRow][lastCol+1];
                board[lastRow][lastCol+1] = '#';
                backtracking(board , s , word , {lastRow , lastCol + 1});
                board[lastRow][lastCol+1] = letter;
                s.pop_back();
            }
            if(lastCol - 1 >= 0 && board[lastRow][lastCol - 1] == word[s.size()]){
                s.push_back(board[lastRow][lastCol-1]);
                char letter = board[lastRow][lastCol-1];
                board[lastRow][lastCol-1] = '#';
                backtracking(board , s , word , {lastRow , lastCol-1});
                board[lastRow][lastCol-1] = letter;
                s.pop_back();
            }
        }
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        string s = "";

        backtracking(board , s , word , {-1 , -1});
        return answer;
    }
};