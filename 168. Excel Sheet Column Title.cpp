class Solution {
public:
    string convertToTitle(int n) {
        string res;
        char ch;
        
        while(n) {
            n --;
            ch = 'A' + (n % 26);
            res = ch + res;
            n /= 26;
        }
        return res;
    }
};
