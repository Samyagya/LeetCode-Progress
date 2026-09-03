// Last updated: 04/09/2026, 02:15:05
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        int totalTasks = tasks.size();
        vector<int> freqMap (26 , 0);
        for(int i = 0 ; i < tasks.size() ; i ++){
            freqMap[tasks[i] - 'A']++;
        }
        
        queue<int> timeout;

        priority_queue<int> pq;
        for(int i = 0; i < freqMap.size() ; i++){
            if(freqMap[i] != 0){
                pq.push(freqMap[i]);
            }
        }

        while(totalTasks > 0){
            intervals++;
            if(pq.size() == 0){
                timeout.push(0);              
            }else{
                int largest = pq.top();
                pq.pop();
                largest--;
                timeout.push(largest);
                totalTasks--;
            }

            if(timeout.size() > n){
                int allowed = timeout.front();
                timeout.pop();
                if(allowed != 0){
                    pq.push(allowed);
                }
            }
            
        }


        return intervals;
    }
};