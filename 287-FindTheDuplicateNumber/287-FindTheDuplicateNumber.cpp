// Last updated: 01/08/2026, 22:45:43
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }

        return 0;
    }
};