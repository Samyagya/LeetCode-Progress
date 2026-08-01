// Last updated: 01/08/2026, 22:45:40
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int , int> numberCount;
        for(int i = 0 ; i < nums.size() ; i++){
            int number = nums[i];
            numberCount[number]++;
        }
        unordered_map<int , vector<int>>countNumber;
        for(auto i: numberCount){
            int num = i.first;
            int freq = i.second;
            countNumber[freq].push_back(num);
        }

        vector<int>frequencies;
        for(auto i : countNumber){
            frequencies.push_back(i.first);
        }

        sort(frequencies.rbegin() , frequencies.rend());
        int freqTracker = 0;
        while(k > 0){
            vector<int>toAdd = countNumber[frequencies[freqTracker]];
            freqTracker++;
            for(int j = 0 ; j <toAdd.size() ; j++){
                answer.push_back(toAdd[j]);
                k--;
                if(k==0){
                    break;
                }
            }
        }

        return answer;
    }
};