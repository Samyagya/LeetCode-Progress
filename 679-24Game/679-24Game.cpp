// Last updated: 01/08/2026, 22:45:23
class Solution {
public:
    bool solving(vector<double> nums){

        if(nums.size() == 1){
            return fabs(nums[0] - 24) < 1e-6;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j =0 ; j < nums.size() ; j++){
                if(i == j) continue;

                vector<double> next;
                for(int k = 0 ; k < nums.size() ; k++){
                    if(k != i && k != j){
                        next.push_back(nums[k]);
                    }
                }
                
                double a = nums[i];
                double b = nums[j];
                vector<double> computed = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6) computed.push_back(a / b);
                if (fabs(a) > 1e-6) computed.push_back(b / a);

                for(double x : computed){
                    next.push_back(x);
                    if(solving(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin() , cards.end());
        return solving(nums);
    }
};