// Last updated: 09/09/2026, 11:11:07
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ways = 0;
        if(n==m && m == 1){
            return 0;
        }
        for(long long i = 1 ; i <=n ; i++){
            if(i%2==1){
                ways = ways + m/2;
            }else{
                long long toAdd = ceil((double)m/2);
                ways = ways + toAdd;
            }
        }


        return ways;
    }
};