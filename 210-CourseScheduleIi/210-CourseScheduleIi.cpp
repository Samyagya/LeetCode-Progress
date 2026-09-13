// Last updated: 13/09/2026, 20:15:22
class Solution {
public:
    void eraser(map<int, unordered_set<int>>& preMap , int course){
        for(auto& pair : preMap){
            pair.second.erase(course);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int , unordered_set<int>> preMap;

        for(int i = 0; i < numCourses; i++){
            preMap[i] = unordered_set<int>();
        }

        for(int i = 0 ; i < prerequisites.size() ; i++){
            vector<int> current = prerequisites[i];
            int course = current[0];
            int prereq = current[1];
            preMap[course].insert(prereq);
        }

        vector<int> answer;
        bool possible = true;
        bool anyChange = false;
        while(!preMap.empty()){
            anyChange = false;
            for(auto it = preMap.begin(); it != preMap.end(); it++){
                int currentCourse = it->first;
                unordered_set<int>& currentPrereqs = it->second;

                if(currentPrereqs.empty()){
                    answer.push_back(currentCourse);
                    preMap.erase(currentCourse);
                    eraser(preMap , currentCourse);
                    anyChange = true;
                    break;
                }
            }
            if(!anyChange){
                possible = false;
                break;
            }
        }

        if(!possible){
            vector<int> noAns;
            return noAns;
        }

        return answer;
        
    }
};