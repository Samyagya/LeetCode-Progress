// Last updated: 09/09/2026, 11:11:12
class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string sCopy = "";
            for(int i  = 0 ; i < s.size() - 1 ; i++){
                int digit1 = s[i] - '0';
                int digit2 = s[i+1] - '0';
                int sum = digit1 + digit2;
                sum = sum % 10;
                sCopy.push_back(sum + '0');
            }
            s = sCopy;
        }
        if(s[0] == s[1]) return true;
        return false;
    }
};