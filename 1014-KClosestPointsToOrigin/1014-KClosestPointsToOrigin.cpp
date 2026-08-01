// Last updated: 01/08/2026, 22:45:09
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int , vector<vector<int>>> distanceToPointMap;
        vector<vector<int>> answer;

        for(int i = 0 ; i < points.size() ; i ++){
            vector<int> p = points[i];
            int distance = (p[0]*p[0]) + (p[1] *p[1]);
            distanceToPointMap[distance].push_back(p);
        }

        for(auto i = distanceToPointMap.begin() ; i != distanceToPointMap.end() ; i++ ){
            vector<vector<int>>& ThisDistance = i->second;
            for(int j = 0 ; j < ThisDistance.size() ; j++){
                if(answer.size() < k){
                    answer.push_back(ThisDistance[j]);
                }else{
                    break;
                }
            }
            if(answer.size() == k){
                break;
            }

        }

        return answer;

        return answer;
    }
};