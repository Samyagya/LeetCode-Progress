// Last updated: 01/08/2026, 22:45:36
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> store(n + m);
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                int num = mat[i][j];
                int sum = i + j;
                if(sum % 2 == 1){
                    store[sum].push_back(num);
                }else{
                    store[sum].insert(store[sum].begin() , num);
                }
            }
        }

        vector<int> answer;
        for(int i = 0 ; i < store.size() ; i++){
            for(int j = 0 ; j < store[i].size() ; j++){
                answer.push_back(store[i][j]);
            }
        }

        return answer;
    }
};