// Last updated: 01/08/2026, 22:45:27
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int> s1Map;
        for(char c : s1){
            s1Map[c]++;
        }
        int l = 0;
        int r = s1.size() - 1;
        while(r  < s2.size()){
            unordered_map<char , int> s2Map;
            for(int i = l ; i <= r ; i++){
                s2Map[s2[i]]++;
            }
            if(s1Map == s2Map){
                return true;
            }
            l++;
            r++;
        }

        return false;
    }
};