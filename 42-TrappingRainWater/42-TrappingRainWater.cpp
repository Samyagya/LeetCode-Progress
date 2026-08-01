// Last updated: 01/08/2026, 22:47:23
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL = height[0];
        int maxR = height[n-1];
        int L = 0; int R = n - 1;
        int totalWater = 0;
        while(L < R){
            int moved;
            if(maxL <= maxR){
                L++;
                moved = L;
            }else{
                R--;
                moved = R;
            }
            int water = min(maxL , maxR) - height[moved];
            maxL = max(maxL , height[L]);
            maxR = max(maxR , height[R]);
            totalWater += max(water , 0);
        }

        return totalWater;
    }
};