// Last updated: 01/08/2026, 22:48:14
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> numberPosition;
        vector<int> answer;
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            if(numberPosition.find(diff) != numberPosition.end()){
                answer = {numberPosition[diff] , i};
                return answer;
            }else{
                numberPosition.insert({nums[i] , i});
            }
        }
        return answer;
    }
};