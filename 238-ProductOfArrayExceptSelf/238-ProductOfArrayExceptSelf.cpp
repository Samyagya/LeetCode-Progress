// Last updated: 01/08/2026, 22:45:55
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> A1(n) , A2(n);
        int prodFront = 1;
        int prodBack = 1;
        for(int i = 0 , j = n -1; i < n , j>= 0; i++ , j--){
            prodFront = prodFront * nums[i];
            A1[i] = prodFront;
            prodBack = prodBack * nums[j];
            A2[j] = prodBack;
        }
        answer[0] = A2[1];
        answer[n-1] = A1[n-2];
        for(int i = 1 ; i < n - 1 ; i++){
            answer[i] = A1[i-1] * A2[i+1];
        }

        return answer;
        
    }
};