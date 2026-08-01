// Last updated: 01/08/2026, 22:45:37
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char , int> charCounter;
        int maxSize = 0;
        int maxf = 0;
        while(r<s.size()){
            charCounter[s[r]]++;
            maxf = max(maxf , charCounter[s[r]]);
            int len = r - l + 1;
            int diff = len - maxf;
            if(diff > k){
                charCounter[s[l]]--;
                l++;                
            }else{
                maxSize = max(len , maxSize);
            }
            r++;
        }

        return maxSize;
    }
};