// Last updated: 01/08/2026, 22:46:01
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> checker;
        for(int i = 0 ; i < nums.size() ; i++){
            if(checker[nums[i]]){
                return true;
            }else{
                checker[nums[i]]++;
            }
        }
        return false;
    }
};