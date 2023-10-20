class Solution {
    std::vector<int> dpVector;

    int jumpRecursive(const std::vector<int> &nums, int currentIndex) {
        if (currentIndex == nums.size() - 1)
            return 0;

        if (dpVector[currentIndex] != -1)
            return dpVector[currentIndex];

        int maxSteps = nums[currentIndex];
        int minStepsToEnd = std::numeric_limits<int>::max();
        for (int step = 1; step <= maxSteps; step++) {
            if (currentIndex + step >= nums.size()) break;

            int nextResult = jumpRecursive(nums, currentIndex + step);
            if (nextResult != std::numeric_limits<int>::max()) 
                minStepsToEnd = std::min(minStepsToEnd, 1 + nextResult);
        }

        return dpVector[currentIndex] = minStepsToEnd;
    } 

public:
    int jump(vector<int>& nums) {
        dpVector = std::vector<int>(nums.size(), -1);
        return jumpRecursive(nums, 0);
    }
};