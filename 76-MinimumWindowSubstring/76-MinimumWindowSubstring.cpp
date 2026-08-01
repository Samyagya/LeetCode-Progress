// Last updated: 01/08/2026, 22:47:08
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char , int> sMap;
        unordered_map<char , int> tMap;
        for(char c : t) tMap[c]++;

        int l = 0;
        int required = tMap.size();
        int matches = 0;
        int r = 0;
        int minLen = INT_MAX;
        int bestStart = 0;

        for(r = 0 ; r < s.size() ; r ++){
            sMap[s[r]]++;

            if(tMap.count(s[r]) && sMap[s[r]] == tMap[s[r]]) matches++;

            while(matches == required){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    bestStart = l;
                }
                sMap[s[l]]--;
                if(tMap.count(s[l]) && sMap[s[l]] < tMap[s[l]]) matches--;
                l++;
            }
        }

       
        return minLen == INT_MAX ? "" : s.substr(bestStart , minLen);
    }
};