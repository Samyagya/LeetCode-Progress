// Last updated: 09/09/2026, 11:11:51
class Solution {
public:
    int distance(int x1 , int y1){
        int xsquare = x1*x1;
        int ysquare = y1*y1;
        return xsquare + ysquare;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int,vector<int>,greater<int>> dists;
        unordered_map<int , vector<vector<int>>> distancePoints;
        vector<vector<int>> answers;
        for(int i = 0 ; i < points.size() ; i++){
            vector<int> thisPoint = points[i];
            int x = thisPoint[0];
            int y = thisPoint[1];


            int d = distance(x , y);
            dists.push(d);
            distancePoints[d].push_back(thisPoint);
        }

        for(int i = 0 ; i < k ; i++){
            int d = dists.top();
            dists.pop();
            answers.push_back(distancePoints[d].back());

            distancePoints[d].pop_back();
        }

        return answers;
    }
};