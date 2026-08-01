// Last updated: 01/08/2026, 22:46:35
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i <= j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(i > j){
                break;
            }else{
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};