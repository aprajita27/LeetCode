//https://leetcode.com/problems/partition-labels/
//TC: O(n) SC: O(1) n: length of the input string
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> charIdx(26, 0);
        for (int i = 0; i < S.size(); ++i){
            charIdx[S[i]-'a'] = i;
        }
        
        vector<int> res;
        
        int maxIdx = -1, lastIdx = 0;
        for (int i = 0; i < S.size(); ++i){
            maxIdx = max(maxIdx, charIdx[S[i]-'a']);
            
            if(i == maxIdx) {
                res.push_back(maxIdx - lastIdx + 1);
                lastIdx = i + 1;
            }
            
        }
        return res;
    }
};
