// Last updated: 01/08/2026, 22:47:12
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int min = 0;
        int max = m - 1;
        int mid;
        while(min <= max){
            mid = (min + max) / 2;
            if(target > matrix[mid][n - 1]){
                min = mid + 1;
            }else if(target < matrix[mid][0]){
                max = mid - 1;
            }else{
                break;
            }
        }

        int l = 0;
        int r = n - 1;
        int x;
        while(l <= r){
            x = (l + r) / 2;
            if(target > matrix[mid][x]){
                l = x + 1;
            }else if(target < matrix[mid][x]){
                r = x - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};