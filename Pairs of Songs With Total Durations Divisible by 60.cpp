// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
//TC: O(n) SC: O(1) n: size of input
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> t(60, 0);
        
        for(int i = 0; i < time.size(); i++){
            int remainder = time[i] % 60;
            if(remainder == 0) 
                count += t[remainder];
            else 
                count += t[60 - remainder];
            t[remainder]++;
        }
        return count;
    }
};
