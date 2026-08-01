// Last updated: 01/08/2026, 22:45:13
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int , double> positionToSpeed; // position -> speed
        stack<pair<int ,double>> fleets; // pairs=> position -> speed
        for(int i = 0; i < n ; i ++){
            positionToSpeed[position[i]] = speed[i];
        }
        sort(position.rbegin() , position.rend());
        for(int i = 0 ; i < n ; i++){
            if(fleets.empty()){
                pair<int , int> p1 = {position[i] , positionToSpeed[position[i]]};
                fleets.push(p1);
                continue;
            }
            double currTime = (double)(target - position[i])/positionToSpeed[position[i]];
            double lastTime = (double)(target - fleets.top().first)/fleets.top().second;
            if(currTime > lastTime){
                pair<int , int> p1 = {position[i] , positionToSpeed[position[i]]};
                fleets.push(p1);
            }
        }

        return fleets.size();





    }
};