// Last updated: 01/08/2026, 22:48:06
class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0){
            return false;
        }
        int num = x;
        long long revX = 0;
        while(num > 0){
            revX = revX*10 + num%10;
            num = num / 10;
        }
        if(x == revX){
            return true;
        }else{
            return false;
        }
    }
};