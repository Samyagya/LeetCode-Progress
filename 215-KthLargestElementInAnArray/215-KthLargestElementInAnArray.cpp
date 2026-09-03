// Last updated: 04/09/2026, 02:15:21
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> sortedNums;
        for(int i = 0 ; i < nums.size() ; i ++){
            sortedNums.push(nums[i]);
        }

        for(int i = 0 ; i < k-1 ; i ++){
            sortedNums.pop();
        }

        return sortedNums.top();
    }
};