// Last updated: 13/09/2026, 16:19:05
class Solution {
public:
    bool dfs(map<int,vector<int>>& preMap , int course , unordered_set<int>& checkTracker){
        if(checkTracker.count(course)){
            return false;
        }
        checkTracker.insert(course);
        if(preMap[course].empty()){
            checkTracker.erase(course);
            return true;
        }
        // vector<int> preReqs = preMap[course];
        bool canDo = false;
        while(preMap[course].size() != 0){
            canDo = false;
            canDo = dfs(preMap , preMap[course][0] , checkTracker);
            if(canDo == true){
                preMap[course].erase(preMap[course].begin());
            }else{
                break;
            }
        }
        checkTracker.erase(course);

        return canDo;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int , vector<int>> preMap;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            vector<int> current = prerequisites[i];
            int course = current[0];
            int prereq = current[1];
            preMap[course].push_back(prereq);
        }
        unordered_set<int> checkTracker;
        bool answer = true;
        for(int i = 0 ; i < numCourses ; i++){
            bool check = dfs(preMap , i , checkTracker);
            if(check == false){
                answer = false;
                break;
            }
        }

        return answer;
    }
};