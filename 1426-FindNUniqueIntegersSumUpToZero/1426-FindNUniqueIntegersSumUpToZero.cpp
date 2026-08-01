// Last updated: 01/08/2026, 22:44:59
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