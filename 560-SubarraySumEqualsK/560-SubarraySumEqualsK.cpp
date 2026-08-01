// Last updated: 01/08/2026, 22:45:31
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> prefixSumCount;
        prefixSumCount[0] = 1;
        int currSum = 0;
        int count = 0;

        for(int num : nums){
            currSum = currSum + num;
            if(prefixSumCount.find(currSum - k) != prefixSumCount.end()){
                count = count + prefixSumCount[currSum - k];
            }
            prefixSumCount[currSum]++;
        }

        return count;
    }
};