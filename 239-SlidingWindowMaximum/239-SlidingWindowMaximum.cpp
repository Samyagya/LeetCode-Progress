// Last updated: 01/08/2026, 22:45:50
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonicStack;
        vector<int> maxes;
        int currMax = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            while(!monotonicStack.empty() && nums[monotonicStack.back()] < nums[i]){
                monotonicStack.pop_back();
            }
            monotonicStack.push_back(i);
            
            if(monotonicStack.front() <= i - k){
                monotonicStack.pop_front();
            }

            if(i >= k - 1){
                maxes.push_back(nums[monotonicStack.front()]);
                
            }
        }

        return maxes;         
    }
};