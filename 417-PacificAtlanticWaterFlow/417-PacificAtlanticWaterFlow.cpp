// Last updated: 10/09/2026, 18:41:02
class Solution {
public:
    void checker(vector<vector<int>>& heights , vector<vector<int>>& bothOceans , vector<int> current , vector<vector<int>> visited){
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dirs = {{-1 , 0} , {1,0} , {0,1} , {0,-1}};
        bool pacific = false;
        bool atlantic = false;
        queue<vector<int>> q;
        q.push(current);
        visited.push_back(current);

        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();
            if(find(bothOceans.begin() , bothOceans.end() , top) != bothOceans.end()){
                bothOceans.push_back(current);
                break;
            }
            for(int i = 0 ; i < 4 ; i++){
                int r = top[0] + dirs[i][0];
                int c = top[1] + dirs[i][1];
                if(r >= m || c >= n){
                    atlantic = true;
                }
                if(r < 0 || c < 0){
                    pacific = true;
                }
                if(r >= 0 && r < m && c >= 0 && c < n){
                    if(heights[r][c] <=heights[top[0]][top[1]]){
                        vector<int> newBlock = {r , c};
                        if(find(visited.begin() , visited.end() , newBlock) == visited.end()){
                            q.push({r,c});
                            visited.push_back(newBlock);
                        }

                    }
                }
            }

            if(atlantic && pacific){
                bothOceans.push_back(current);
                break;
            }
        } 
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> bothOceans;
        for(int i = 0 ; i < heights.size() ; i++){
            for(int j = 0 ; j < heights[0].size() ; j++){
                vector<int> current = {i , j};
                vector<vector<int>> visited;
                checker(heights , bothOceans , current , visited);
            }
        }

        return bothOceans;
    }
};