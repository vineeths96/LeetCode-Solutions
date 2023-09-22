class Solution {
    std::vector<std::vector<int>> dpVector;

    int findTargetSumWaysRecursive(const std::vector<int> &nums, int target, int totalSum, int currentSum, int currentIndex) {
        if (currentIndex == nums.size()) {
            if (target == currentSum) return 1;
            else return 0;
        }
        
        if (dpVector[currentIndex][currentSum + totalSum] != -1) 
            return dpVector[currentIndex][currentSum + totalSum];

        int result = 0;
        result += findTargetSumWaysRecursive(nums, target, totalSum, currentSum - nums[currentIndex], currentIndex + 1);
        result += findTargetSumWaysRecursive(nums, target, totalSum, currentSum + nums[currentIndex], currentIndex + 1);
        
        return dpVector[currentIndex][currentSum + totalSum] = result;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);        
        dpVector = std::vector<std::vector<int>>(nums.size() + 1, std::vector<int>(2 * totalSum + 1, -1)); 
        return findTargetSumWaysRecursive(nums, target, totalSum, 0, 0);
    }
};