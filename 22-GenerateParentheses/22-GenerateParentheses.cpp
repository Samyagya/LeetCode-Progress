// Last updated: 01/08/2026, 22:47:46
class Solution {
public:
    void backtracking(string& s , int n , int openN , int closedN  , vector<string>& answer){
        if(openN == closedN && openN == n){
            answer.push_back(s);
        }
        if(openN < n){
            s = s + "(";
            backtracking(s , n , openN+1 , closedN , answer);
            s.pop_back();
        }
        if(closedN < openN){
            s = s + ")";
            backtracking(s , n , openN , closedN + 1 , answer);
            s.pop_back();
        }


    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string s;
        backtracking(s , n , 0 , 0 , answer);
        return answer;
    }
};