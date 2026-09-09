// Last updated: 09/09/2026, 11:11:44
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0 ; i < stones.size() ; i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int largest = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(largest != second){
                int left = largest - second;
                pq.push(left);
            }
        }


        if(pq.size() != 0){
            return pq.top();
        }

        return 0;
    }
};