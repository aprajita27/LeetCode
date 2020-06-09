class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int j = 1, k = 2, res = 1;
        
        for(int i = 3; i <= n; i++){
            res = j + k;
            j = k;
            k = res;
        }
        return res;
    }
};
