class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int low = 0, high = x, mid = 0;
        
        while(low < high){
            mid = (low + high) / 2;
            
            if((x / mid) >= mid)
                low = mid + 1;
            else
                high = mid;
        }
        return high - 1;
    }
};
