// Last updated: 01/08/2026, 22:46:38
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int profit = 0;
        while(r <= prices.size() - 1){
            int p = prices[r] - prices[l];
            profit = max(p , profit);
            if(p < 0){
                l++;
            }else{
                r++;
            }
        }

        return profit;
    }
};