// Last updated: 01/08/2026, 22:46:26
class Solution {
public:
    bool isPalindrome(const string& s , int left , int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }

        return true;
    }

    void backtracking(int index , string& s , vector<string>& currAns , vector<vector<string>>& answer){
        if(index == s.size()){
            answer.push_back(currAns);
            return;
        }

        for(int i = index ; i < s.size() ; i++){
            if(isPalindrome(s , index , i)){
                currAns.push_back(s.substr(index , i - index + 1));
                backtracking(i + 1 , s , currAns , answer);
                currAns.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> currAns;
        backtracking(0 , s , currAns , answer);
        return answer;
    }
};