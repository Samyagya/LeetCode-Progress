// Last updated: 01/08/2026, 22:44:53
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> startEndPositions;
        int s = -1;
        int e = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                if( s == -1){
                    s = i;
                }
            }else{
                if(s == -1) continue;
                e = i - 1;
                pair<int , int> startEnd = {s , e};
                startEndPositions.push_back(startEnd);
                s = -1;
            }
        }
        if(s != -1){
            pair<int  , int> lastOne = {s , nums.size() - 1};
            startEndPositions.push_back(lastOne);
        }
        int maxSize = 0;
        int diff = -1;
        for(int i = 0; i < startEndPositions.size() ; i++){
            pair<int , int> startEnd = startEndPositions[i];
            int len = startEnd.second - startEnd.first + 1;
            maxSize = max(maxSize , len);
            if(i == 0)continue;
            pair<int , int>prevStartEnd = startEndPositions[i-1];
            diff = startEnd.first - prevStartEnd.second;
            if(diff != 2) continue;
            int len2 = prevStartEnd.second - prevStartEnd.first + 1;
            maxSize = max(maxSize , len + len2); 
        }
        if(maxSize == nums.size()) return maxSize - 1;
        return maxSize;
    }
};