// Last updated: 01/08/2026, 22:47:28
class Solution {
public:
    void backtracking(vector<int>& candidates , vector<vector<int>>& answer , int target , vector<int>& currAns , int currSum , int index){
        for(int i = index; i < candidates.size() ; i++){
            currSum = currSum + candidates[i];
            if(currSum > target){
                currSum = currSum - candidates[i];
                continue;
            }else if(currSum == target){
                currAns.push_back(candidates[i]);
                answer.push_back(currAns);
                // break;
            }else{
                currAns.push_back(candidates[i]);
                backtracking(candidates, answer , target , currAns , currSum , i);
            }
            currAns.pop_back();
            currSum = currSum - candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> currAns;
        backtracking(candidates , answer , target , currAns , 0 , 0);
        return answer;
    }
};