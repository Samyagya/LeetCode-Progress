// Last updated: 01/08/2026, 22:46:11
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 ;
        int j = numbers.size() - 1;
        vector<int> answer;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                answer.push_back(i+1);
                answer.push_back(j+1);
                break;
            }
            else if(sum > target){
                j--;
            }else{
                i++;
            }            
        }
        return answer;
    }
};