// Last updated: 01/08/2026, 22:48:07
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int l = 0;
        int r = 0;
        int maxSize = 0;
        unordered_map<char , int> hash;
        while(r < s.size()){
            if(!hash[s[r]]){
                maxSize = max(maxSize , r - l + 1);
            }else{
                while(hash[s[r]] != 0){
                    hash[s[l]] = 0;
                    l++;
                    maxSize = max(maxSize , r - l + 1);
                }
            }
            hash[s[r]] = 1;
            r++;
        }
        return maxSize;
    }
};