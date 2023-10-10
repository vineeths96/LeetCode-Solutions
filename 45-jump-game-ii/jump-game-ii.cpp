class Solution {
    std::vector<int> dpVector;

    int jumpRecursive(const std::vector<int> &nums, int currentIndex) {
        if (currentIndex == nums.size() - 1)
            return 0;

        if (dpVector[currentIndex] != -1)
            return dpVector[currentIndex];

        int maxSteps = nums[currentIndex];
        int minSteps = std::numeric_limits<int>::max();

        if (maxSteps == 0) return minSteps;

        for (int i = 1; i <= maxSteps; i++) {
            if (currentIndex + i >= nums.size()) break;

            int steps = jumpRecursive(nums, currentIndex + i);
            if (steps != std::numeric_limits<int>::max()) steps++;

            minSteps = std::min(minSteps, steps);
        }

        return dpVector[currentIndex] = minSteps;
    }

public:
    int jump(vector<int>& nums) {
        dpVector = std::vector<int>(nums.size() + 1, -1);
        return jumpRecursive(nums, 0);    
    }
};