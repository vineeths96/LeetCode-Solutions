class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = std::numeric_limits<int>::min();
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);            
        }

        return maxSum;
    }
};