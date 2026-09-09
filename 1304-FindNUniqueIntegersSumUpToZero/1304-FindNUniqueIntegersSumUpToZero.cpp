// Last updated: 09/09/2026, 11:11:39
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer;
        int half = n/2;
        for(int i = 1 ; i <= half ; i++){
            answer.push_back(i);
            answer.push_back(-i);
        }
        if(answer.size() == n){
            return answer;
        }else{
            answer.push_back(0);
            return answer;
        }
    }
};