// Last updated: 01/08/2026, 22:44:47
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> nums(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0 ; i < mat.size() ; i++){
            for(int  j = 0; j < mat[0].size() ; j++){
                if(mat[i][j] == 0){
                    nums[i][j] = 0;
                    continue;
                }
                int rowCounter = 0;
                int jc = j;
                while(jc < mat[0].size() && mat[i][jc] != 0){
                    rowCounter++;
                    jc++;
                }
                nums[i][j] = rowCounter;
            }
        }

        int counter = 0;
        for(int i = 0; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(nums[i][j] == 0) continue;
                int thisCellCounter = 0;
                for(int h = 1 ; i + h - 1 < mat.size() ; h++){
                    int currMin = nums[i][j];
                    for(int k = 0 ; k < h ; k++){
                        currMin = min(currMin , nums[i + k][j]);
                    }
                    thisCellCounter += currMin;
                }
                counter += thisCellCounter;
            }
        }

        return counter;
    }
};