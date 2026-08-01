// Last updated: 01/08/2026, 22:47:05
class Solution {
public:
    void backtracking(vector<int>& nums , vector<vector<int>>& answer , int i , vector<int>& currVector){
        if(i == nums.size()){
            answer.push_back(currVector);
            return;
        }
        int currNum = nums[i];
        currVector.push_back(currNum);
        backtracking(nums , answer , i+1 , currVector);
        currVector.pop_back();
        backtracking(nums , answer , i+1 , currVector);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currVector;
        backtracking(nums , answer , 0 , currVector);
        return answer;
    }
};