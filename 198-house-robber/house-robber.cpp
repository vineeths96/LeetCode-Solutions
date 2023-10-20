class Solution {
    std::vector<int> dpVector;

    int robRecursive(const std::vector<int> &nums, int currentIndex) {
        if (currentIndex >= nums.size())
            return 0;

        if (dpVector[currentIndex] != -1)
            return dpVector[currentIndex];

        int robCurrent = nums[currentIndex] + robRecursive(nums, currentIndex + 2);
        int skipCurrent = robRecursive(nums, currentIndex + 1);

        return dpVector[currentIndex] = std::max(robCurrent, skipCurrent);        
    }
public:
    int rob(vector<int>& nums) {
        dpVector = std::vector<int>(nums.size(), -1);
        return robRecursive(nums, 0);
    }
};