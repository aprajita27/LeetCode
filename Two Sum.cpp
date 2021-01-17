//https://leetcode.com/problems/two-sum/
//TC: O(n) SC: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); ++i)    {
            int to_find = target - nums[i];
            if(mp.find(to_find) != mp.end() && mp[to_find] != i){
                res.push_back(i);
                res.push_back(mp[to_find]);
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
