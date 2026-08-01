// Last updated: 01/08/2026, 22:47:16
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> sortedToWords;
        for(int i = 0 ; i < strs.size() ; i++){
            string word = strs[i];
            string sortedWord = word;
            sort(sortedWord.begin() , sortedWord.end());
            sortedToWords[sortedWord].push_back(word);
        }
        vector<vector<string>> answer;
        for(auto& pair: sortedToWords){
            answer.push_back(pair.second);
        }
        return answer;
    }
};