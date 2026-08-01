// Last updated: 01/08/2026, 22:46:29
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numCounter(nums.begin() , nums.end());
        if(nums.empty())return 0;
        int k = 1;
        for(int nums: numCounter){
            int t = 1;
            int num = nums;
            if(numCounter.find(num-1) != numCounter.end()){
                //do nothing
            }else{
                 while(numCounter.find(num + 1) != numCounter.end()){
                    t++;
                    num++;
                 }   
            }
            k = max(k , t);
        }

        return k;


    }
};