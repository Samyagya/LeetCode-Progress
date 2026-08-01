// Last updated: 01/08/2026, 22:44:41
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        double maxDiagonal = 0;
        for(int i = 0 ; i < dimensions.size() ; i++){
            double l = dimensions[i][0];
            double b = dimensions[i][1];
            double dia = sqrt(l*l + b*b);
            if(dia > maxDiagonal){
                int area = l*b;
                maxArea = area;
                maxDiagonal = dia;
            }else if(dia == maxDiagonal){
                int area = l * b;
                maxArea = max(area , maxArea);
            }
        }

        return maxArea;
    }
};