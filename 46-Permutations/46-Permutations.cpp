// Last updated: 01/08/2026, 22:47:19
class Solution {
public:
    void backtracking(vector<int>& nums , vector<vector<int>>& answer , vector<int>& currVec , int choice , vector<bool>& usedVec){
        if(choice == nums.size()){
            answer.push_back(currVec);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(!usedVec[i]){
                currVec.push_back(nums[i]);
                usedVec[i] = true;
                backtracking(nums , answer , currVec , choice + 1 , usedVec);
                usedVec[i] = false;
                currVec.pop_back();
            }else{
                continue;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currVec;
        vector<bool> usedVec(nums.size() , false);
        backtracking(nums , answer, currVec , 0 , usedVec);
        return answer;
    }
};