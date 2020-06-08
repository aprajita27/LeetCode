class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int sum = INT_MIN, positive_checker = 0, dynamic_sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                positive_checker = 1;
                break;
            }
            else if(nums[i] > sum)
                sum = nums[i];
        }
        if(positive_checker == 0)
            return sum;
        for(int i = 0; i < nums.size(); i++){
            dynamic_sum += nums[i];
            
            if(dynamic_sum < 0)
                dynamic_sum = 0;
            
            if(dynamic_sum > sum)
                sum = dynamic_sum;
        }
        return sum;
    }
};
