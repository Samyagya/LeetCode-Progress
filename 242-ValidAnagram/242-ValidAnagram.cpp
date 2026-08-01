// Last updated: 01/08/2026, 22:45:47
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<string , int> counter;
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        if(s == t){
            return true;
        }else{
            return false;
        }
    }
};