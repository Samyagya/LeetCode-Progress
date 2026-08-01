// Last updated: 01/08/2026, 22:47:59
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;
        set<vector<int>> UniqueAnswers;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() && nums[i] <=0 ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            int target = nums[i] * -1;
            while( j < k){
                if(nums[j] + nums[k] == target){
                    vector<int> res = {nums[i] , nums[j] , nums[k]};
                    if(UniqueAnswers.find(res) != UniqueAnswers.end()){
                        //do nothing
                    }else{
                        UniqueAnswers.insert(res);
                        answers.push_back(res);
                    }
                    k--;
                    j++;
                }else if(nums[j] + nums[k] > target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return answers;
    }
};