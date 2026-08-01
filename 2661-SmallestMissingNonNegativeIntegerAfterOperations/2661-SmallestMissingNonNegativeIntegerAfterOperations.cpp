// Last updated: 01/08/2026, 22:44:42
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int , int> numbersCount; //value : count
        for(int i = 0 ; i < nums.size() ; i ++){
            int smallest = abs(nums[i])%value;
            if(nums[i] < 0 && smallest != 0) smallest = value - smallest;
            numbersCount[smallest]++;
        }
        int ans = 0;
        while(true){
            if(numbersCount[ans]){
                numbersCount[ans]--;
                if(numbersCount[ans]){
                    numbersCount[ans + value] = numbersCount[ans];
                }
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};