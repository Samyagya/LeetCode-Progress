// Last updated: 09/09/2026, 11:11:24
class Solution {
public:
    long long subArrayCounter(int numOfZeros){
        if(numOfZeros == 0){
            return 0;
        }
        long long counter = 0;
        long long sum = numOfZeros + 1;
        while(numOfZeros > 0){
            counter = counter + (sum - numOfZeros);
            numOfZeros--;
        }

        return counter;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        long long counter = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] == 0){
                counter++;
            }else{
                total = total + subArrayCounter(counter);
                counter = 0;
            }
        }
        total = total + subArrayCounter(counter);

        return total;
    }
};