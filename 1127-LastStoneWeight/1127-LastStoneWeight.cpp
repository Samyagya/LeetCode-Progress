// Last updated: 01/08/2026, 22:45:06
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin() , stones.end());
        while(q.size() > 1){
            int max = q.top();
            q.pop();
            int sec = q.top();
            q.pop();
            if(max != sec){
                q.push(max - sec);
            }
        }

        if(q.empty()){
            return 0;
        }

        return q.top();

    }
};