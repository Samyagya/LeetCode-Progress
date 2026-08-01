// Last updated: 01/08/2026, 22:48:03
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 ;
        int j = height.size() - 1;
        int maxWater = 0;
        while(i < j){
            int water = (j - i) * min(height[i] , height[j]);
            maxWater = max(water , maxWater);
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }

        return maxWater;
    }
};