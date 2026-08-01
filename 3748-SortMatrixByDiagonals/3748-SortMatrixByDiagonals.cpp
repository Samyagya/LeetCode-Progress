// Last updated: 01/08/2026, 22:44:30
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> answer(n , vector<int>(n));
        unordered_map<int , deque<int>> store;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int num = i - j;
                store[num].push_back(grid[i][j]);
            }
        }

        for(auto& i : store){
            if(i.first < 0){
                sort(i.second.begin() , i.second.end());
            }else{
                sort(i.second.rbegin() , i.second.rend());
            }
        }

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                int num = i - j;
                answer[i][j] = store[num].front();
                store[num].pop_front();
            }
        }

        return answer;
    }
};