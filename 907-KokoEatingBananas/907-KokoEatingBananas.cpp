// Last updated: 01/08/2026, 22:45:10
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = piles[0];
        for(int i = 0 ; i < n ; i ++){
            r = max(piles[i] , r);
        }
        int ans = r;
        while(l <=r){
            long long totaltime= 0;
            int k = (l + r)/2;
            for(int i = 0 ; i < n ; i++){
                totaltime += ceil(static_cast<double>(piles[i]) / k);
            }
            if(totaltime <= h){
                ans = k;
                r = k - 1;
            }else{
                l = k + 1;
            }
        }

        return ans;
    }
};