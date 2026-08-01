// Last updated: 01/08/2026, 22:47:14
class Solution {
public:
    void backtracking(int n , vector<vector<string>>& answer , int index , vector<string>& currAns , vector<int>& cols, vector<int>& diag1 , vector<int>& diag2){
        if(index == n){
            answer.push_back(currAns);
            return;
        }

        for(int i = 0 ; i < n ; i ++){
            if(cols[i] || diag1[i+index] || diag2[i-index+n-1]) continue;
            cols[i] = diag1[i+index] = diag2[i - index+n-1] = 1;
            string row(n , '.');
            row[i] = 'Q';
            currAns.push_back(row);
            backtracking(n , answer , index + 1 , currAns , cols , diag1 , diag2);
            cols[i] = diag1[i+index] = diag2[i - index+n-1] = 0;;
            currAns.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> currAns;
        vector<int> cols(n , 0);
        vector<int> diag1(2*n - 1 , 0);
        vector<int> diag2(2*n - 1 , 0);
        backtracking(n , answer , 0 , currAns , cols , diag1 , diag2);
        return answer;
    }
};