// Last updated: 01/08/2026, 22:47:25
class Solution {
public:
    void backtracking(vector<int>& candidates, vector<vector<int>>& answer , vector<int>& currAns , int currSum , int index , int target){
        for(int i = index ; i < candidates.size() ; i++){

            if(i > index && candidates[i] == candidates[i-1]) continue;

            int currVal = candidates[i];
            currSum = currSum + currVal;
            if(currSum == target){
                currAns.push_back(currVal);
                answer.push_back(currAns);
                currAns.pop_back();
                currSum = currSum - currVal;
                break;
            }else if(currSum > target){
                currSum = currSum - currVal;
                break;
            }else{
                currAns.push_back(currVal);
                backtracking(candidates , answer , currAns , currSum , i + 1 , target);
                currAns.pop_back();
                currSum = currSum - currVal;
            }
             
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> currAns;
        sort(candidates.begin() , candidates.end());
        backtracking(candidates , answer , currAns , 0 , 0 , target);
        return answer;
    }
};