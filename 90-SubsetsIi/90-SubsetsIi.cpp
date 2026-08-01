// Last updated: 01/08/2026, 22:46:57
class Solution {
public:
    void backtracking(vector<int>& nums , set<vector<int>>& answerSet , vector<int>& currVec , int index){
        if(index == nums.size()){
            answerSet.insert(currVec);
            return;
        }
        backtracking(nums , answerSet , currVec , index + 1);
        currVec.push_back(nums[index]);
        backtracking(nums , answerSet , currVec , index + 1);
        currVec.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> answerSet;
        vector<int> currVec;
        backtracking(nums , answerSet , currVec , 0);
        vector<vector<int>> answer(answerSet.begin() , answerSet.end());
        return answer;
    }
};