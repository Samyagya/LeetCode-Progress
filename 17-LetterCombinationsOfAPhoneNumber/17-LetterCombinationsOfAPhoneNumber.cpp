// Last updated: 01/08/2026, 22:47:57
class Solution {
public:
    void backtracking(vector<string>& answer , string& currString , int index , string& digits , vector<string>& letter){
        if(index == digits.size()){
            answer.push_back(currString);
            return;
        }
        string word = letter[digits[index] - '0'];
        for(auto i : word){
            currString.push_back(i);
            backtracking(answer , currString , index + 1 , digits , letter);
            currString.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> letter = {"none","none" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        vector<string> answer;
        string currString = "";
        backtracking(answer , currString , 0 , digits , letter);
        return answer;
    }
};