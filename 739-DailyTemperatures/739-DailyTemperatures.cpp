// Last updated: 01/08/2026, 22:45:20
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> indexTemps;
        vector<int> answer(n , 0);
        for(int i = 0 ; i < n ; i++){
            while(!indexTemps.empty() && temperatures[i] > temperatures[indexTemps.top()]){
                int prevIndex = indexTemps.top();
                indexTemps.pop();
                answer[prevIndex] = i - prevIndex;
            }
            indexTemps.push(i);
        }

        return answer;
    }
};