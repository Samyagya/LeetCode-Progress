// Last updated: 01/08/2026, 22:46:12
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return nums[0];
    }
};